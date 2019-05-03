/***************************************************************************
 * STM32 VGA demo
 * Copyright (C) 2012 Artekit Italy
 * http://www.artekit.eu
 * Written by Ruben H. Meleca
 
### main.c

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
#include "stm32f10x_usart.h"
#include "sys.h"
#include "video.h"
#include "gdi.h"
#include "hc6502_display.h"


extern void demoInit(void);
void RCC_Configuration(void);
void GPIO_Configuration(void);
void USART2_Config(void);

extern u8 fb[VID_VSIZE][VID_HSIZE+2];

int main(void)
{
	//char buf[64];
	//unsigned char ch = 0x20;
	//int i, x;
 	RCC_Configuration();
	GPIO_Configuration();
	//USART2_Config();
	//vidInit();
	hc6502_display_init();
	sysInitSystemTimer();
	
	//gdiDrawTextEx(0, 0, "01234567890123456789012345678901234567890123456789012345678901234567890123456789", GDI_ROP_COPY);
	gdiDrawTextEx(130, 80, "HC6502 by", GDI_ROP_COPY);
	gdiDrawTextEx(150, 90, "muselab-tech.com", GDI_ROP_COPY);
	sysDelayMs(8000);
	vidClearScreen();
	
	//gdiRectangle(0,0,(VID_PIXELS_X - 1),VID_VSIZE - 1,0);
	//vidClearScreen();
	//gdiBitBlt(NULL,0, 0, 240,56, (pu8) logo,GDI_ROP_COPY);
	/*
	gdiDrawTextEx(0, 0, "01234567890123456789012345678901234567890123456789012345678901234567890123456789", GDI_ROP_COPY);
	x = 50;
	while(ch < 0x80){
		for(i = 0; i < 63 && ch < 0x80; ++i)
			buf[i] = ch++;
		buf[i] = '\0';
		gdiDrawTextEx(0, x, buf, GDI_ROP_COPY);
		x += 10;
	}
	*/
	GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_SET);
	sysDelayMs(1000);
	GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_RESET);
	sysDelayMs(1000);
	
	while(1){
		/*
		if(!zq_empty(&queue)){
			uint8_t mask = 0x80;
			ch = zq_dequeue(&queue);
			for(i = 0; i < 8; i++){
				buf[i] = ch & mask ? '1' : '0';
				mask >>= 1;
			}
			buf[i] = '\0';
			gdiDrawTextEx(0, 20, buf, GDI_ROP_COPY);
		}
		*/
		hc6502_display_routine();
		//hc6502_display_debug();
		//GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET);
		//sysDelayMs(50);
		//GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_RESET);
		sysDelayMs(27);
	}
	
	//demoInit();
	
	return 0;
}


void RCC_Configuration(void)
{
	/* TIM1, GPIOA, GPIOB and AFIO clocks enable */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_SPI1 | RCC_APB2Periph_TIM1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
}

void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5 | GPIO_Pin_9 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_RESET);
}

void USART2_Config(void)
{
	GPIO_InitTypeDef gpioInitStruct;
	USART_InitTypeDef usartInitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	//PA2	TXD
	gpioInitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpioInitStruct.GPIO_Pin = GPIO_Pin_2;
	gpioInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpioInitStruct);
	
	//PA3	RXD
	gpioInitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpioInitStruct.GPIO_Pin = GPIO_Pin_3;
	gpioInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpioInitStruct);
	
	usartInitStruct.USART_BaudRate = 9600;
	usartInitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usartInitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	usartInitStruct.USART_Parity = USART_Parity_No;
	usartInitStruct.USART_StopBits = USART_StopBits_1;
	usartInitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2, &usartInitStruct);
	
	USART_Cmd(USART2, ENABLE);
}
