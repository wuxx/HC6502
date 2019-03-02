;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 28 2016) (Linux)
; This file was generated Wed Jan  2 15:12:28 2019
;--------------------------------------------------------
	.module stm8s_uart1
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _assert_failed
	.globl _CLK_GetClockFreq
	.globl _UART1_DeInit
	.globl _UART1_Init
	.globl _UART1_Cmd
	.globl _UART1_ITConfig
	.globl _UART1_HalfDuplexCmd
	.globl _UART1_IrDAConfig
	.globl _UART1_IrDACmd
	.globl _UART1_LINBreakDetectionConfig
	.globl _UART1_LINCmd
	.globl _UART1_SmartCardCmd
	.globl _UART1_SmartCardNACKCmd
	.globl _UART1_WakeUpConfig
	.globl _UART1_ReceiverWakeUpCmd
	.globl _UART1_ReceiveData8
	.globl _UART1_ReceiveData9
	.globl _UART1_SendData8
	.globl _UART1_SendData9
	.globl _UART1_SendBreak
	.globl _UART1_SetAddress
	.globl _UART1_SetGuardTime
	.globl _UART1_SetPrescaler
	.globl _UART1_GetFlagStatus
	.globl _UART1_ClearFlag
	.globl _UART1_GetITStatus
	.globl _UART1_ClearITPendingBit
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	../src/stm8s_uart1.c: 53: void UART1_DeInit(void)
;	-----------------------------------------
;	 function UART1_DeInit
;	-----------------------------------------
_UART1_DeInit:
;	../src/stm8s_uart1.c: 57: (void)UART1->SR;
	ldw	x, #0x5230
	ld	a, (x)
;	../src/stm8s_uart1.c: 58: (void)UART1->DR;
	ldw	x, #0x5231
	ld	a, (x)
;	../src/stm8s_uart1.c: 60: UART1->BRR2 = UART1_BRR2_RESET_VALUE;  /* Set UART1_BRR2 to reset value 0x00 */
	mov	0x5233+0, #0x00
;	../src/stm8s_uart1.c: 61: UART1->BRR1 = UART1_BRR1_RESET_VALUE;  /* Set UART1_BRR1 to reset value 0x00 */
	mov	0x5232+0, #0x00
;	../src/stm8s_uart1.c: 63: UART1->CR1 = UART1_CR1_RESET_VALUE;  /* Set UART1_CR1 to reset value 0x00 */
	mov	0x5234+0, #0x00
;	../src/stm8s_uart1.c: 64: UART1->CR2 = UART1_CR2_RESET_VALUE;  /* Set UART1_CR2 to reset value 0x00 */
	mov	0x5235+0, #0x00
;	../src/stm8s_uart1.c: 65: UART1->CR3 = UART1_CR3_RESET_VALUE;  /* Set UART1_CR3 to reset value 0x00 */
	mov	0x5236+0, #0x00
;	../src/stm8s_uart1.c: 66: UART1->CR4 = UART1_CR4_RESET_VALUE;  /* Set UART1_CR4 to reset value 0x00 */
	mov	0x5237+0, #0x00
;	../src/stm8s_uart1.c: 67: UART1->CR5 = UART1_CR5_RESET_VALUE;  /* Set UART1_CR5 to reset value 0x00 */
	mov	0x5238+0, #0x00
;	../src/stm8s_uart1.c: 69: UART1->GTR = UART1_GTR_RESET_VALUE;
	mov	0x5239+0, #0x00
;	../src/stm8s_uart1.c: 70: UART1->PSCR = UART1_PSCR_RESET_VALUE;
	mov	0x523a+0, #0x00
	ret
;	../src/stm8s_uart1.c: 90: void UART1_Init(uint32_t BaudRate, UART1_WordLength_TypeDef WordLength, 
;	-----------------------------------------
;	 function UART1_Init
;	-----------------------------------------
_UART1_Init:
	sub	sp, #33
;	../src/stm8s_uart1.c: 97: assert_param(IS_UART1_BAUDRATE_OK(BaudRate));
	ldw	x, #0x8968
	cpw	x, (0x26, sp)
	ld	a, #0x09
	sbc	a, (0x25, sp)
	clr	a
	sbc	a, (0x24, sp)
	jrnc	00113$
	ldw	y, #___str_0+0
	push	#0x61
	clrw	x
	pushw	x
	push	#0x00
	pushw	y
	call	_assert_failed
	addw	sp, #6
00113$:
;	../src/stm8s_uart1.c: 98: assert_param(IS_UART1_WORDLENGTH_OK(WordLength));
	tnz	(0x28, sp)
	jreq	00115$
	ld	a, (0x28, sp)
	cp	a, #0x10
	jreq	00115$
	ldw	y, #___str_0+0
	push	#0x62
	clrw	x
	pushw	x
	push	#0x00
	pushw	y
	call	_assert_failed
	addw	sp, #6
00115$:
;	../src/stm8s_uart1.c: 99: assert_param(IS_UART1_STOPBITS_OK(StopBits));
	tnz	(0x29, sp)
	jreq	00120$
	ld	a, (0x29, sp)
	cp	a, #0x10
	jreq	00120$
	ld	a, (0x29, sp)
	cp	a, #0x20
	jreq	00120$
	ld	a, (0x29, sp)
	cp	a, #0x30
	jreq	00120$
	ldw	y, #___str_0+0
	push	#0x63
	clrw	x
	pushw	x
	push	#0x00
	pushw	y
	call	_assert_failed
	addw	sp, #6
00120$:
;	../src/stm8s_uart1.c: 100: assert_param(IS_UART1_PARITY_OK(Parity));
	tnz	(0x2a, sp)
	jreq	00131$
	ld	a, (0x2a, sp)
	cp	a, #0x04
	jreq	00131$
	ld	a, (0x2a, sp)
	cp	a, #0x06
	jreq	00131$
	ldw	y, #___str_0+0
	push	#0x64
	clrw	x
	pushw	x
	push	#0x00
	pushw	y
	call	_assert_failed
	addw	sp, #6
00131$:
;	../src/stm8s_uart1.c: 101: assert_param(IS_UART1_MODE_OK((uint8_t)Mode));
	ld	a, (0x2c, sp)
	cp	a, #0x08
	jreq	00139$
	ld	a, (0x2c, sp)
	cp	a, #0x40
	jreq	00139$
	ld	a, (0x2c, sp)
	cp	a, #0x04
	jreq	00139$
	ld	a, (0x2c, sp)
	cp	a, #0x80
	jreq	00139$
	ld	a, (0x2c, sp)
	cp	a, #0x0c
	jrne	00314$
	ld	a, #0x01
	.byte 0x21
00314$:
	clr	a
00315$:
	tnz	a
	jrne	00139$
	tnz	a
	jrne	00139$
	ld	a, (0x2c, sp)
	cp	a, #0x44
	jreq	00139$
	ld	a, (0x2c, sp)
	cp	a, #0xc0
	jreq	00139$
	ld	a, (0x2c, sp)
	cp	a, #0x88
	jreq	00139$
	ldw	y, #___str_0+0
	push	#0x65
	clrw	x
	pushw	x
	push	#0x00
	pushw	y
	call	_assert_failed
	addw	sp, #6
00139$:
;	../src/stm8s_uart1.c: 102: assert_param(IS_UART1_SYNCMODE_OK((uint8_t)SyncMode));
	ld	a, (0x2b, sp)
	and	a, #0x88
	cp	a, #0x88
	jreq	00167$
	ld	a, (0x2b, sp)
	and	a, #0x44
	cp	a, #0x44
	jreq	00167$
	ld	a, (0x2b, sp)
	and	a, #0x22
	cp	a, #0x22
	jreq	00167$
	ld	a, (0x2b, sp)
	and	a, #0x11
	cp	a, #0x11
	jrne	00165$
00167$:
	ldw	y, #___str_0+0
	push	#0x66
	clrw	x
	pushw	x
	push	#0x00
	pushw	y
	call	_assert_failed
	addw	sp, #6
00165$:
;	../src/stm8s_uart1.c: 105: UART1->CR1 &= (uint8_t)(~UART1_CR1_M);  
	ldw	x, #0x5234
	ld	a, (x)
	and	a, #0xef
	ld	(x), a
;	../src/stm8s_uart1.c: 108: UART1->CR1 |= (uint8_t)WordLength;
	ldw	x, #0x5234
	ld	a, (x)
	or	a, (0x28, sp)
	ldw	x, #0x5234
	ld	(x), a
;	../src/stm8s_uart1.c: 111: UART1->CR3 &= (uint8_t)(~UART1_CR3_STOP);  
	ldw	x, #0x5236
	ld	a, (x)
	and	a, #0xcf
	ld	(x), a
;	../src/stm8s_uart1.c: 113: UART1->CR3 |= (uint8_t)StopBits;  
	ldw	x, #0x5236
	ld	a, (x)
	or	a, (0x29, sp)
	ldw	x, #0x5236
	ld	(x), a
;	../src/stm8s_uart1.c: 116: UART1->CR1 &= (uint8_t)(~(UART1_CR1_PCEN | UART1_CR1_PS  ));  
	ldw	x, #0x5234
	ld	a, (x)
	and	a, #0xf9
	ld	(x), a
;	../src/stm8s_uart1.c: 118: UART1->CR1 |= (uint8_t)Parity;  
	ldw	x, #0x5234
	ld	a, (x)
	or	a, (0x2a, sp)
	ldw	x, #0x5234
	ld	(x), a
;	../src/stm8s_uart1.c: 121: UART1->BRR1 &= (uint8_t)(~UART1_BRR1_DIVM);  
	ldw	x, #0x5232
	ld	a, (x)
	mov	0x5232+0, #0x00
;	../src/stm8s_uart1.c: 123: UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVM);  
	ldw	x, #0x5233
	ld	a, (x)
	and	a, #0x0f
	ld	(x), a
;	../src/stm8s_uart1.c: 125: UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVF);  
	ldw	x, #0x5233
	ld	a, (x)
	and	a, #0xf0
	ld	(x), a
;	../src/stm8s_uart1.c: 128: BaudRate_Mantissa    = ((uint32_t)CLK_GetClockFreq() / (BaudRate << 4));
	call	_CLK_GetClockFreq
	ldw	(0x14, sp), x
	ldw	x, (0x24, sp)
	ldw	(0x0d, sp), x
	ldw	x, (0x26, sp)
	ld	a, #0x04
00339$:
	sllw	x
	rlc	(0x0e, sp)
	rlc	(0x0d, sp)
	dec	a
	jrne	00339$
	ldw	(0x0f, sp), x
	ldw	x, (0x0f, sp)
	pushw	x
	ldw	x, (0x0f, sp)
	pushw	x
	ldw	x, (0x18, sp)
	pushw	x
	pushw	y
	call	__divulong
	addw	sp, #8
	ldw	(0x07, sp), x
	ldw	(0x05, sp), y
;	../src/stm8s_uart1.c: 129: BaudRate_Mantissa100 = (((uint32_t)CLK_GetClockFreq() * 100) / (BaudRate << 4));
	call	_CLK_GetClockFreq
	pushw	x
	pushw	y
	push	#0x64
	clrw	x
	pushw	x
	push	#0x00
	call	__mullong
	addw	sp, #8
	ldw	(0x0b, sp), x
	ldw	x, (0x0f, sp)
	pushw	x
	ldw	x, (0x0f, sp)
	pushw	x
	ldw	x, (0x0f, sp)
	pushw	x
	pushw	y
	call	__divulong
	addw	sp, #8
	exgw	x, y
	ldw	(0x03, sp), y
	rlwa	x
	ld	(0x01, sp), a
	rrwa	x
	ld	a, xl
;	../src/stm8s_uart1.c: 131: UART1->BRR2 |= (uint8_t)((uint8_t)(((BaudRate_Mantissa100 - (BaudRate_Mantissa * 100)) << 4) / 100) & (uint8_t)0x0F); 
	ldw	x, #0x5233
	push	a
	ld	a, (x)
	ld	(0x12, sp), a
	pop	a
	push	a
	ldw	x, (0x08, sp)
	pushw	x
	ldw	x, (0x08, sp)
	pushw	x
	push	#0x64
	clrw	x
	pushw	x
	push	#0x00
	call	__mullong
	addw	sp, #8
	ldw	(0x19, sp), x
	ldw	(0x17, sp), y
	pop	a
	ldw	y, (0x03, sp)
	subw	y, (0x18, sp)
	sbc	a, (0x17, sp)
	ld	xl, a
	ld	a, (0x01, sp)
	sbc	a, (0x16, sp)
	ld	xh, a
	ld	a, #0x04
00341$:
	sllw	y
	rlcw	x
	dec	a
	jrne	00341$
	push	#0x64
	push	#0x00
	push	#0x00
	push	#0x00
	pushw	y
	pushw	x
	call	__divulong
	addw	sp, #8
	ld	a, xl
	and	a, #0x0f
	or	a, (0x11, sp)
	ldw	x, #0x5233
	ld	(x), a
;	../src/stm8s_uart1.c: 133: UART1->BRR2 |= (uint8_t)((BaudRate_Mantissa >> 4) & (uint8_t)0xF0); 
	ldw	x, #0x5233
	ld	a, (x)
	ld	(0x21, sp), a
	ldw	x, (0x07, sp)
	ldw	y, (0x05, sp)
	srlw	y
	rrcw	x
	srlw	y
	rrcw	x
	srlw	y
	rrcw	x
	srlw	y
	rrcw	x
	ld	a, xl
	and	a, #0xf0
	push	a
	clr	(0x20, sp)
	clrw	x
	pop	a
	or	a, (0x21, sp)
	ldw	x, #0x5233
	ld	(x), a
;	../src/stm8s_uart1.c: 135: UART1->BRR1 |= (uint8_t)BaudRate_Mantissa;           
	ldw	x, #0x5232
	ld	a, (x)
	ld	(0x1c, sp), a
	ld	a, (0x08, sp)
	or	a, (0x1c, sp)
	ldw	x, #0x5232
	ld	(x), a
;	../src/stm8s_uart1.c: 138: UART1->CR2 &= (uint8_t)~(UART1_CR2_TEN | UART1_CR2_REN); 
	ldw	x, #0x5235
	ld	a, (x)
	and	a, #0xf3
	ld	(x), a
;	../src/stm8s_uart1.c: 140: UART1->CR3 &= (uint8_t)~(UART1_CR3_CPOL | UART1_CR3_CPHA | UART1_CR3_LBCL); 
	ldw	x, #0x5236
	ld	a, (x)
	and	a, #0xf8
	ld	(x), a
;	../src/stm8s_uart1.c: 142: UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & (uint8_t)(UART1_CR3_CPOL | 
	ldw	x, #0x5236
	ld	a, (x)
	ld	(0x1b, sp), a
	ld	a, (0x2b, sp)
	and	a, #0x07
	or	a, (0x1b, sp)
	ldw	x, #0x5236
	ld	(x), a
;	../src/stm8s_uart1.c: 145: if ((uint8_t)(Mode & UART1_MODE_TX_ENABLE))
	ld	a, (0x2c, sp)
	bcp	a, #0x04
	jreq	00102$
;	../src/stm8s_uart1.c: 148: UART1->CR2 |= (uint8_t)UART1_CR2_TEN;  
	ldw	x, #0x5235
	ld	a, (x)
	or	a, #0x08
	ld	(x), a
	jra	00103$
00102$:
;	../src/stm8s_uart1.c: 153: UART1->CR2 &= (uint8_t)(~UART1_CR2_TEN);  
	ldw	x, #0x5235
	ld	a, (x)
	and	a, #0xf7
	ld	(x), a
00103$:
;	../src/stm8s_uart1.c: 155: if ((uint8_t)(Mode & UART1_MODE_RX_ENABLE))
	ld	a, (0x2c, sp)
	bcp	a, #0x08
	jreq	00105$
;	../src/stm8s_uart1.c: 158: UART1->CR2 |= (uint8_t)UART1_CR2_REN;  
	ldw	x, #0x5235
	ld	a, (x)
	or	a, #0x04
	ld	(x), a
	jra	00106$
00105$:
;	../src/stm8s_uart1.c: 163: UART1->CR2 &= (uint8_t)(~UART1_CR2_REN);  
	ldw	x, #0x5235
	ld	a, (x)
	and	a, #0xfb
	ld	(x), a
00106$:
;	../src/stm8s_uart1.c: 167: if ((uint8_t)(SyncMode & UART1_SYNCMODE_CLOCK_DISABLE))
	tnz	(0x2b, sp)
	jrpl	00108$
;	../src/stm8s_uart1.c: 170: UART1->CR3 &= (uint8_t)(~UART1_CR3_CKEN); 
	ldw	x, #0x5236
	ld	a, (x)
	and	a, #0xf7
	ld	(x), a
	jra	00110$
00108$:
;	../src/stm8s_uart1.c: 174: UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & UART1_CR3_CKEN);
	ldw	x, #0x5236
	ld	a, (x)
	ld	(0x1a, sp), a
	ld	a, (0x2b, sp)
	and	a, #0x08
	or	a, (0x1a, sp)
	ldw	x, #0x5236
	ld	(x), a
00110$:
	addw	sp, #33
	ret
;	../src/stm8s_uart1.c: 184: void UART1_Cmd(FunctionalState NewState)
;	-----------------------------------------
;	 function UART1_Cmd
;	-----------------------------------------
_UART1_Cmd:
;	../src/stm8s_uart1.c: 186: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../src/stm8s_uart1.c: 189: UART1->CR1 &= (uint8_t)(~UART1_CR1_UARTD); 
	ldw	x, #0x5234
	ld	a, (x)
	and	a, #0xdf
	ld	(x), a
	jra	00104$
00102$:
;	../src/stm8s_uart1.c: 194: UART1->CR1 |= UART1_CR1_UARTD;  
	ldw	x, #0x5234
	ld	a, (x)
	or	a, #0x20
	ld	(x), a
00104$:
	ret
;	../src/stm8s_uart1.c: 211: void UART1_ITConfig(UART1_IT_TypeDef UART1_IT, FunctionalState NewState)
;	-----------------------------------------
;	 function UART1_ITConfig
;	-----------------------------------------
_UART1_ITConfig:
;	../src/stm8s_uart1.c: 259: }
	ret
;	../src/stm8s_uart1.c: 267: void UART1_HalfDuplexCmd(FunctionalState NewState)
;	-----------------------------------------
;	 function UART1_HalfDuplexCmd
;	-----------------------------------------
_UART1_HalfDuplexCmd:
;	../src/stm8s_uart1.c: 281: }
	ret
;	../src/stm8s_uart1.c: 289: void UART1_IrDAConfig(UART1_IrDAMode_TypeDef UART1_IrDAMode)
;	-----------------------------------------
;	 function UART1_IrDAConfig
;	-----------------------------------------
_UART1_IrDAConfig:
;	../src/stm8s_uart1.c: 303: }
	ret
;	../src/stm8s_uart1.c: 311: void UART1_IrDACmd(FunctionalState NewState)
;	-----------------------------------------
;	 function UART1_IrDACmd
;	-----------------------------------------
_UART1_IrDACmd:
;	../src/stm8s_uart1.c: 328: }
	ret
;	../src/stm8s_uart1.c: 337: void UART1_LINBreakDetectionConfig(UART1_LINBreakDetectionLength_TypeDef UART1_LINBreakDetectionLength)
;	-----------------------------------------
;	 function UART1_LINBreakDetectionConfig
;	-----------------------------------------
_UART1_LINBreakDetectionConfig:
;	../src/stm8s_uart1.c: 351: }
	ret
;	../src/stm8s_uart1.c: 359: void UART1_LINCmd(FunctionalState NewState)
;	-----------------------------------------
;	 function UART1_LINCmd
;	-----------------------------------------
_UART1_LINCmd:
;	../src/stm8s_uart1.c: 375: }
	ret
;	../src/stm8s_uart1.c: 383: void UART1_SmartCardCmd(FunctionalState NewState)
;	-----------------------------------------
;	 function UART1_SmartCardCmd
;	-----------------------------------------
_UART1_SmartCardCmd:
;	../src/stm8s_uart1.c: 399: }
	ret
;	../src/stm8s_uart1.c: 408: void UART1_SmartCardNACKCmd(FunctionalState NewState)
;	-----------------------------------------
;	 function UART1_SmartCardNACKCmd
;	-----------------------------------------
_UART1_SmartCardNACKCmd:
;	../src/stm8s_uart1.c: 424: }
	ret
;	../src/stm8s_uart1.c: 432: void UART1_WakeUpConfig(UART1_WakeUp_TypeDef UART1_WakeUp)
;	-----------------------------------------
;	 function UART1_WakeUpConfig
;	-----------------------------------------
_UART1_WakeUpConfig:
;	../src/stm8s_uart1.c: 440: }
	ret
;	../src/stm8s_uart1.c: 448: void UART1_ReceiverWakeUpCmd(FunctionalState NewState)
;	-----------------------------------------
;	 function UART1_ReceiverWakeUpCmd
;	-----------------------------------------
_UART1_ReceiverWakeUpCmd:
;	../src/stm8s_uart1.c: 464: }
	ret
;	../src/stm8s_uart1.c: 471: uint8_t UART1_ReceiveData8(void)
;	-----------------------------------------
;	 function UART1_ReceiveData8
;	-----------------------------------------
_UART1_ReceiveData8:
;	../src/stm8s_uart1.c: 473: return ((uint8_t)UART1->DR);
	ldw	x, #0x5231
	ld	a, (x)
	ret
;	../src/stm8s_uart1.c: 481: uint16_t UART1_ReceiveData9(void)
;	-----------------------------------------
;	 function UART1_ReceiveData9
;	-----------------------------------------
_UART1_ReceiveData9:
;	../src/stm8s_uart1.c: 489: }
	ret
;	../src/stm8s_uart1.c: 496: void UART1_SendData8(uint8_t Data)
;	-----------------------------------------
;	 function UART1_SendData8
;	-----------------------------------------
_UART1_SendData8:
;	../src/stm8s_uart1.c: 499: UART1->DR = Data;
	ldw	x, #0x5231
	ld	a, (0x03, sp)
	ld	(x), a
	ret
;	../src/stm8s_uart1.c: 508: void UART1_SendData9(uint16_t Data)
;	-----------------------------------------
;	 function UART1_SendData9
;	-----------------------------------------
_UART1_SendData9:
;	../src/stm8s_uart1.c: 518: }
	ret
;	../src/stm8s_uart1.c: 525: void UART1_SendBreak(void)
;	-----------------------------------------
;	 function UART1_SendBreak
;	-----------------------------------------
_UART1_SendBreak:
;	../src/stm8s_uart1.c: 530: }
	ret
;	../src/stm8s_uart1.c: 537: void UART1_SetAddress(uint8_t UART1_Address)
;	-----------------------------------------
;	 function UART1_SetAddress
;	-----------------------------------------
_UART1_SetAddress:
;	../src/stm8s_uart1.c: 548: }
	ret
;	../src/stm8s_uart1.c: 556: void UART1_SetGuardTime(uint8_t UART1_GuardTime)
;	-----------------------------------------
;	 function UART1_SetGuardTime
;	-----------------------------------------
_UART1_SetGuardTime:
;	../src/stm8s_uart1.c: 562: }
	ret
;	../src/stm8s_uart1.c: 586: void UART1_SetPrescaler(uint8_t UART1_Prescaler)
;	-----------------------------------------
;	 function UART1_SetPrescaler
;	-----------------------------------------
_UART1_SetPrescaler:
;	../src/stm8s_uart1.c: 592: }
	ret
;	../src/stm8s_uart1.c: 600: FlagStatus UART1_GetFlagStatus(UART1_Flag_TypeDef UART1_FLAG)
;	-----------------------------------------
;	 function UART1_GetFlagStatus
;	-----------------------------------------
_UART1_GetFlagStatus:
	pushw	x
;	../src/stm8s_uart1.c: 605: assert_param(IS_UART1_FLAG_OK(UART1_FLAG));
	ldw	x, (0x05, sp)
	cpw	x, #0x0101
	jrne	00208$
	ld	a, #0x01
	ld	(0x01, sp), a
	jra	00209$
00208$:
	clr	(0x01, sp)
00209$:
	ldw	x, (0x05, sp)
	cpw	x, #0x0210
	jrne	00211$
	ld	a, #0x01
	.byte 0x21
00211$:
	clr	a
00212$:
	ldw	x, (0x05, sp)
	cpw	x, #0x0080
	jreq	00119$
	ldw	x, (0x05, sp)
	cpw	x, #0x0040
	jreq	00119$
	ldw	x, (0x05, sp)
	cpw	x, #0x0020
	jreq	00119$
	ldw	x, (0x05, sp)
	cpw	x, #0x0010
	jreq	00119$
	ldw	x, (0x05, sp)
	cpw	x, #0x0008
	jreq	00119$
	ldw	x, (0x05, sp)
	cpw	x, #0x0004
	jreq	00119$
	ldw	x, (0x05, sp)
	cpw	x, #0x0002
	jreq	00119$
	ldw	x, (0x05, sp)
	cpw	x, #0x0001
	jreq	00119$
	tnz	(0x01, sp)
	jrne	00119$
	tnz	a
	jrne	00119$
	ldw	y, #___str_0+0
	push	a
	push	#0x5d
	push	#0x02
	clrw	x
	pushw	x
	pushw	y
	call	_assert_failed
	addw	sp, #6
	pop	a
00119$:
;	../src/stm8s_uart1.c: 611: if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
	push	a
	ld	a, (0x07, sp)
	ld	(0x03, sp), a
	pop	a
;	../src/stm8s_uart1.c: 609: if (UART1_FLAG == UART1_FLAG_LBDF)
	tnz	a
	jreq	00114$
;	../src/stm8s_uart1.c: 611: if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
	ldw	x, #0x5237
	ld	a, (x)
	and	a, (0x02, sp)
	tnz	a
	jreq	00102$
;	../src/stm8s_uart1.c: 614: status = SET;
	ld	a, #0x01
	jra	00115$
00102$:
;	../src/stm8s_uart1.c: 619: status = RESET;
	clr	a
	jra	00115$
00114$:
;	../src/stm8s_uart1.c: 622: else if (UART1_FLAG == UART1_FLAG_SBK)
	tnz	(0x01, sp)
	jreq	00111$
;	../src/stm8s_uart1.c: 624: if ((UART1->CR2 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
	ldw	x, #0x5235
	ld	a, (x)
	and	a, (0x02, sp)
	tnz	a
	jreq	00105$
;	../src/stm8s_uart1.c: 627: status = SET;
	ld	a, #0x01
	jra	00115$
00105$:
;	../src/stm8s_uart1.c: 632: status = RESET;
	clr	a
	jra	00115$
00111$:
;	../src/stm8s_uart1.c: 637: if ((UART1->SR & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
	ldw	x, #0x5230
	ld	a, (x)
	and	a, (0x02, sp)
	tnz	a
	jreq	00108$
;	../src/stm8s_uart1.c: 640: status = SET;
	ld	a, #0x01
;	../src/stm8s_uart1.c: 645: status = RESET;
	.byte 0x21
00108$:
	clr	a
00115$:
;	../src/stm8s_uart1.c: 649: return status;
	popw	x
	ret
;	../src/stm8s_uart1.c: 678: void UART1_ClearFlag(UART1_Flag_TypeDef UART1_FLAG)
;	-----------------------------------------
;	 function UART1_ClearFlag
;	-----------------------------------------
_UART1_ClearFlag:
;	../src/stm8s_uart1.c: 694: }
	ret
;	../src/stm8s_uart1.c: 709: ITStatus UART1_GetITStatus(UART1_IT_TypeDef UART1_IT)
;	-----------------------------------------
;	 function UART1_GetITStatus
;	-----------------------------------------
_UART1_GetITStatus:
;	../src/stm8s_uart1.c: 784: return 0;
	clr	a
	ret
;	../src/stm8s_uart1.c: 812: void UART1_ClearITPendingBit(UART1_IT_TypeDef UART1_IT)
;	-----------------------------------------
;	 function UART1_ClearITPendingBit
;	-----------------------------------------
_UART1_ClearITPendingBit:
;	../src/stm8s_uart1.c: 828: }
	ret
	.area CODE
___str_0:
	.ascii "../src/stm8s_uart1.c"
	.db 0x00
	.area INITIALIZER
	.area CABS (ABS)
