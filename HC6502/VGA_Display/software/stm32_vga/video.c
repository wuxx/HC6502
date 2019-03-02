/***************************************************************************
 * STM32 VGA demo
 * Copyright (C) 2012 Artekit Italy
 * http://www.artekit.eu
 * Written by Ruben H. Meleca
 
### video.c
 
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

***************************************************************************/

#include "stm32f10x.h"
#include "video.h"

#define VTOTAL	52							/* Total bytes to send through SPI */
__align(4) u8 fb[VID_VSIZE][VID_HSIZE+2];	/* Frame buffer */
static volatile u16 vline = 0;				/* The current line being drawn */
static volatile u32 vflag = 0;				/* When 1, the SPI DMA request can draw on the screen */
static volatile u32 vdraw = 0;				/* Used to increment vline every 3 drawn lines */ 

void TIMER_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef nvic;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	u32 TimerPeriod = 0;
	u16 Channel1Pulse = 0, Channel2Pulse = 0, Channel3Pulse = 0;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/*
		SVGA 800x600 @ 56 Hz
		Vertical refresh	35.15625 kHz
		Pixel freq.			36.0 MHz
		
		1 system tick @ 72Mhz = 0,0138 us
	*/
	
	/*
		Horizontal timing
		-----------------
		
		Timer 1 period = 35156 Hz
		
		Timer 1 channel 1 generates a pulse for HSYNC each 28.4 us.
		28.4 us	= Visible area + Front porch + Sync pulse + Back porch.
		HSYNC is 2 us long, so the math to do is:
		2us / 0,0138us = 144 system ticks.
		
		Timer 1 channel 2 generates a pulse equal to HSYNC + back porch.
		This interrupt will fire the DMA request to draw on the screen if vflag == 1.
		Since firing the DMA takes more or less 800ns, we'll add some extra time.
		The math for HSYNC + back porch is:
		(2us + 3,55us - dma) / 0,0138us = +-350 system ticks
	
		Horizontal timing info
		----------------------

						Dots	us
		--------------------------------------------		
		Visible area	800		22.222222222222
		Front porch		24		0.66666666666667
		Sync pulse		72		2
		Back porch		128		3.5555555555556
		Whole line		1024	28.444444444444
	
	*/

	TimerPeriod = 2048;
	Channel1Pulse = 144;		/* HSYNC */
	Channel2Pulse = 352; 		/* HSYNC + BACK PORCH */
	
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = TimerPeriod;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitStructure.TIM_Pulse = Channel1Pulse;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Set;

	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Inactive;
	TIM_OCInitStructure.TIM_Pulse = Channel2Pulse;
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);

	/* TIM1 counter enable and output enable */
	TIM_CtrlPWMOutputs(TIM1, ENABLE);

	/* Select TIM1 as Master */
	TIM_SelectMasterSlaveMode(TIM1, TIM_MasterSlaveMode_Enable);
	TIM_SelectOutputTrigger(TIM1, TIM_TRGOSource_Update);
	
	/*
		Vertical timing
		---------------
		
		Polarity of vertical sync pulse is positive.

						Lines
		------------------------------
		Visible area	600
		Front porch		1
		Sync pulse		2
		Back porch		22
		Whole frame		625
		
	*/

	/* VSYNC (TIM2_CH2) and VSYNC_BACKPORCH (TIM2_CH3) */
	/* Channel 2 and 3 Configuration in PWM mode */
	TIM_SelectSlaveMode(TIM2, TIM_SlaveMode_Gated);
	TIM_SelectInputTrigger(TIM2, TIM_TS_ITR0);
	
	TimerPeriod = 625;		/* Vertical lines */
	Channel2Pulse = 2;		/* Sync pulse */
	Channel3Pulse = 24;		/* Sync pulse + Back porch */
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = TimerPeriod;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitStructure.TIM_Pulse = Channel2Pulse;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Set;
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Inactive;
	TIM_OCInitStructure.TIM_Pulse = Channel3Pulse;
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);

	/*	TIM2 counter enable and output enable */
	TIM_CtrlPWMOutputs(TIM2, ENABLE);

	/* Interrupt TIM2 */
	nvic.NVIC_IRQChannel = TIM2_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 1;
    nvic.NVIC_IRQChannelSubPriority = 0;
    nvic.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&nvic);
	TIM_ITConfig(TIM2, TIM_IT_CC3, ENABLE);

	/* Interrupt TIM1 */
	nvic.NVIC_IRQChannel = TIM1_CC_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 1;
    nvic.NVIC_IRQChannelSubPriority = 0;
    nvic.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&nvic);
	TIM_ITConfig(TIM1, TIM_IT_CC2, ENABLE);
	
	TIM_Cmd(TIM2, ENABLE);
	TIM_Cmd(TIM1, ENABLE);
}

void SPI_Configuration(void)
{
	NVIC_InitTypeDef nvic;
	SPI_InitTypeDef SPI_InitStructure;
	DMA_InitTypeDef	DMA_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	SPI_Cmd(SPI1, DISABLE);
	DMA_DeInit(DMA1_Channel3);

	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&SPI1->DR;
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32) &fb[0][0];
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
	DMA_InitStructure.DMA_BufferSize = VTOTAL;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Low;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel3, &DMA_InitStructure);

	SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI1, &SPI_InitStructure);
	
	SPI_CalculateCRC(SPI1, DISABLE);
	SPI_Cmd(SPI1, ENABLE);
	
	SPI1->CR2 |= SPI_I2S_DMAReq_Tx;
	
	nvic.NVIC_IRQChannel = DMA1_Channel3_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 0;
	nvic.NVIC_IRQChannelSubPriority = 0;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic);
	
	DMA1_Channel3->CCR &= ~1;
	DMA1_Channel3->CNDTR = VTOTAL;
	DMA1_Channel3->CMAR = (u32) &fb[0][0];
	
	DMA_ITConfig(DMA1_Channel3, DMA_IT_TC, ENABLE);
}

//*****************************************************************************
//	This irq is generated at the end of the horizontal back porch.
//	Test if inside a valid vertical start frame (vflag variable), 
//	and start the DMA to output a single frame buffer line through the SPI device.
//*****************************************************************************
__irq void TIM1_CC_IRQHandler(void)
{
	if (vflag)
	{
		DMA1_Channel3->CCR = 0x93;
	}
	TIM1->SR = 0xFFFB; //~TIM_IT_CC2;
}

//*****************************************************************************
//	This irq is generated at the end of the vertical back porch.
//	Sets the 'vflag' variable to 1 (valid vertical frame).
//*****************************************************************************
__irq void TIM2_IRQHandler(void)
{
	vflag = 1;
	TIM2->SR = 0xFFF7; //~TIM_IT_CC3;
}

//*****************************************************************************
//	This interrupt is generated at the end of every line.
//	It will increment the line number and set the corresponding line pointer
//	in the DMA register.
//*****************************************************************************
__irq void DMA1_Channel3_IRQHandler(void)
{	
	DMA1->IFCR = DMA1_IT_TC3;
	DMA1_Channel3->CCR = 0x92;
	DMA1_Channel3->CNDTR = VTOTAL;
	
	vdraw++;
	
	if (vdraw == 3)
	{
		vdraw = 0;

		vline++;
		
		if (vline == VID_VSIZE)
		{
			vdraw = vline = vflag = 0;
			DMA1_Channel3->CMAR = (u32) &fb[0][0];
		} else {
			DMA1_Channel3->CMAR += VTOTAL;
		}
	}
}

void vidClearScreen(void)
{
	u16 x, y;

	for (y = 0; y < VID_VSIZE; y++)
	{
		for (x = 0; x < VTOTAL; x++)
		{
			fb[y][x] = 0;
		}
	}
}

void vidInit(void)
{
	SPI_Configuration();
	TIMER_Configuration();
	vidClearScreen();
}
