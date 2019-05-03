;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module stm8s_exti
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _assert_failed
	.globl _EXTI_DeInit
	.globl _EXTI_SetExtIntSensitivity
	.globl _EXTI_SetTLISensitivity
	.globl _EXTI_GetExtIntSensitivity
	.globl _EXTI_GetTLISensitivity
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

; default segment ordering for linker
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area CONST
	.area INITIALIZER
	.area CODE

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
;	../src/stm8s_exti.c: 53: void EXTI_DeInit(void)
;	-----------------------------------------
;	 function EXTI_DeInit
;	-----------------------------------------
_EXTI_DeInit:
;	../src/stm8s_exti.c: 55: EXTI->CR1 = EXTI_CR1_RESET_VALUE;
	mov	0x50a0+0, #0x00
;	../src/stm8s_exti.c: 56: EXTI->CR2 = EXTI_CR2_RESET_VALUE;
	mov	0x50a1+0, #0x00
;	../src/stm8s_exti.c: 57: }
	ret
;	../src/stm8s_exti.c: 70: void EXTI_SetExtIntSensitivity(EXTI_Port_TypeDef Port, EXTI_Sensitivity_TypeDef SensitivityValue)
;	-----------------------------------------
;	 function EXTI_SetExtIntSensitivity
;	-----------------------------------------
_EXTI_SetExtIntSensitivity:
	pushw	x
;	../src/stm8s_exti.c: 73: assert_param(IS_EXTI_PORT_OK(Port));
	tnz	(0x05, sp)
	jreq	00111$
	ld	a, (0x05, sp)
	dec	a
	jreq	00111$
	ld	a, (0x05, sp)
	cp	a, #0x02
	jreq	00111$
	ld	a, (0x05, sp)
	cp	a, #0x03
	jreq	00111$
	ld	a, (0x05, sp)
	cp	a, #0x04
	jreq	00111$
	push	#0x49
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00111$:
;	../src/stm8s_exti.c: 74: assert_param(IS_EXTI_SENSITIVITY_OK(SensitivityValue));
	tnz	(0x06, sp)
	jreq	00125$
	ld	a, (0x06, sp)
	dec	a
	jreq	00125$
	ld	a, (0x06, sp)
	cp	a, #0x02
	jreq	00125$
	ld	a, (0x06, sp)
	cp	a, #0x03
	jreq	00125$
	push	#0x4a
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00125$:
;	../src/stm8s_exti.c: 77: switch (Port)
	ld	a, (0x05, sp)
	cp	a, #0x04
	jrule	00208$
	jp	00108$
00208$:
;	../src/stm8s_exti.c: 85: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 2);
	ld	a, (0x06, sp)
	ld	yl, a
;	../src/stm8s_exti.c: 77: switch (Port)
	clrw	x
	ld	a, (0x05, sp)
	ld	xl, a
	sllw	x
	ldw	x, (#00209$, x)
	jp	(x)
00209$:
	.dw	#00101$
	.dw	#00102$
	.dw	#00103$
	.dw	#00104$
	.dw	#00105$
;	../src/stm8s_exti.c: 79: case EXTI_PORT_GPIOA:
00101$:
;	../src/stm8s_exti.c: 80: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PAIS);
	ld	a, 0x50a0
	and	a, #0xfc
	ld	0x50a0, a
;	../src/stm8s_exti.c: 81: EXTI->CR1 |= (uint8_t)(SensitivityValue);
	ld	a, 0x50a0
	or	a, (0x06, sp)
	ld	0x50a0, a
;	../src/stm8s_exti.c: 82: break;
	jra	00108$
;	../src/stm8s_exti.c: 83: case EXTI_PORT_GPIOB:
00102$:
;	../src/stm8s_exti.c: 84: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PBIS);
	ld	a, 0x50a0
	and	a, #0xf3
	ld	0x50a0, a
;	../src/stm8s_exti.c: 85: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 2);
	ld	a, 0x50a0
	ldw	x, y
	sllw	x
	sllw	x
	pushw	x
	or	a, (2, sp)
	popw	x
	ld	0x50a0, a
;	../src/stm8s_exti.c: 86: break;
	jra	00108$
;	../src/stm8s_exti.c: 87: case EXTI_PORT_GPIOC:
00103$:
;	../src/stm8s_exti.c: 88: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PCIS);
	ld	a, 0x50a0
	and	a, #0xcf
	ld	0x50a0, a
;	../src/stm8s_exti.c: 89: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 4);
	ld	a, 0x50a0
	ld	(0x02, sp), a
	ld	a, yl
	swap	a
	and	a, #0xf0
	or	a, (0x02, sp)
	ld	0x50a0, a
;	../src/stm8s_exti.c: 90: break;
	jra	00108$
;	../src/stm8s_exti.c: 91: case EXTI_PORT_GPIOD:
00104$:
;	../src/stm8s_exti.c: 92: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PDIS);
	ld	a, 0x50a0
	and	a, #0x3f
	ld	0x50a0, a
;	../src/stm8s_exti.c: 93: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 6);
	ld	a, 0x50a0
	ld	(0x01, sp), a
	ld	a, yl
	swap	a
	and	a, #0xf0
	sll	a
	sll	a
	or	a, (0x01, sp)
	ld	0x50a0, a
;	../src/stm8s_exti.c: 94: break;
	jra	00108$
;	../src/stm8s_exti.c: 95: case EXTI_PORT_GPIOE:
00105$:
;	../src/stm8s_exti.c: 96: EXTI->CR2 &= (uint8_t)(~EXTI_CR2_PEIS);
	ld	a, 0x50a1
	and	a, #0xfc
	ld	0x50a1, a
;	../src/stm8s_exti.c: 97: EXTI->CR2 |= (uint8_t)(SensitivityValue);
	ld	a, 0x50a1
	or	a, (0x06, sp)
	ld	0x50a1, a
;	../src/stm8s_exti.c: 101: }
00108$:
;	../src/stm8s_exti.c: 102: }
	popw	x
	ret
;	../src/stm8s_exti.c: 111: void EXTI_SetTLISensitivity(EXTI_TLISensitivity_TypeDef SensitivityValue)
;	-----------------------------------------
;	 function EXTI_SetTLISensitivity
;	-----------------------------------------
_EXTI_SetTLISensitivity:
;	../src/stm8s_exti.c: 114: assert_param(IS_EXTI_TLISENSITIVITY_OK(SensitivityValue));
	tnz	(0x03, sp)
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x04
	jreq	00104$
	push	#0x72
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../src/stm8s_exti.c: 117: EXTI->CR2 &= (uint8_t)(~EXTI_CR2_TLIS);
	ld	a, 0x50a1
	and	a, #0xfb
	ld	0x50a1, a
;	../src/stm8s_exti.c: 118: EXTI->CR2 |= (uint8_t)(SensitivityValue);
	ld	a, 0x50a1
	or	a, (0x03, sp)
	ld	0x50a1, a
;	../src/stm8s_exti.c: 119: }
	ret
;	../src/stm8s_exti.c: 126: EXTI_Sensitivity_TypeDef EXTI_GetExtIntSensitivity(EXTI_Port_TypeDef Port)
;	-----------------------------------------
;	 function EXTI_GetExtIntSensitivity
;	-----------------------------------------
_EXTI_GetExtIntSensitivity:
;	../src/stm8s_exti.c: 128: uint8_t value = 0;
	clr	a
;	../src/stm8s_exti.c: 131: assert_param(IS_EXTI_PORT_OK(Port));
	tnz	(0x03, sp)
	jreq	00111$
	push	a
	ld	a, (0x04, sp)
	dec	a
	pop	a
	jreq	00111$
	push	a
	ld	a, (0x04, sp)
	cp	a, #0x02
	pop	a
	jreq	00111$
	push	a
	ld	a, (0x04, sp)
	cp	a, #0x03
	pop	a
	jreq	00111$
	push	a
	ld	a, (0x04, sp)
	cp	a, #0x04
	pop	a
	jreq	00111$
	push	a
	push	#0x83
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
	pop	a
00111$:
;	../src/stm8s_exti.c: 133: switch (Port)
	push	a
	ld	a, (0x04, sp)
	cp	a, #0x04
	pop	a
	jrule	00167$
	ret
00167$:
	clrw	x
	ld	a, (0x03, sp)
	ld	xl, a
	sllw	x
	ldw	x, (#00168$, x)
	jp	(x)
00168$:
	.dw	#00101$
	.dw	#00102$
	.dw	#00103$
	.dw	#00104$
	.dw	#00105$
;	../src/stm8s_exti.c: 135: case EXTI_PORT_GPIOA:
00101$:
;	../src/stm8s_exti.c: 136: value = (uint8_t)(EXTI->CR1 & EXTI_CR1_PAIS);
	ld	a, 0x50a0
	and	a, #0x03
;	../src/stm8s_exti.c: 137: break;
	ret
;	../src/stm8s_exti.c: 138: case EXTI_PORT_GPIOB:
00102$:
;	../src/stm8s_exti.c: 139: value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PBIS) >> 2);
	ld	a, 0x50a0
	and	a, #0x0c
	srl	a
	srl	a
;	../src/stm8s_exti.c: 140: break;
	ret
;	../src/stm8s_exti.c: 141: case EXTI_PORT_GPIOC:
00103$:
;	../src/stm8s_exti.c: 142: value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PCIS) >> 4);
	ld	a, 0x50a0
	and	a, #0x30
	swap	a
	and	a, #0x0f
;	../src/stm8s_exti.c: 143: break;
	ret
;	../src/stm8s_exti.c: 144: case EXTI_PORT_GPIOD:
00104$:
;	../src/stm8s_exti.c: 145: value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PDIS) >> 6);
	ld	a, 0x50a0
	and	a, #0xc0
	swap	a
	and	a, #0x0f
	srl	a
	srl	a
;	../src/stm8s_exti.c: 146: break;
	ret
;	../src/stm8s_exti.c: 147: case EXTI_PORT_GPIOE:
00105$:
;	../src/stm8s_exti.c: 148: value = (uint8_t)(EXTI->CR2 & EXTI_CR2_PEIS);
	ld	a, 0x50a1
	and	a, #0x03
;	../src/stm8s_exti.c: 152: }
;	../src/stm8s_exti.c: 154: return((EXTI_Sensitivity_TypeDef)value);
;	../src/stm8s_exti.c: 155: }
	ret
;	../src/stm8s_exti.c: 162: EXTI_TLISensitivity_TypeDef EXTI_GetTLISensitivity(void)
;	-----------------------------------------
;	 function EXTI_GetTLISensitivity
;	-----------------------------------------
_EXTI_GetTLISensitivity:
;	../src/stm8s_exti.c: 167: value = (uint8_t)(EXTI->CR2 & EXTI_CR2_TLIS);
	ld	a, 0x50a1
	and	a, #0x04
;	../src/stm8s_exti.c: 169: return((EXTI_TLISensitivity_TypeDef)value);
;	../src/stm8s_exti.c: 170: }
	ret
	.area CODE
	.area CONST
___str_0:
	.ascii "../src/stm8s_exti.c"
	.db 0x00
	.area INITIALIZER
	.area CABS (ABS)
