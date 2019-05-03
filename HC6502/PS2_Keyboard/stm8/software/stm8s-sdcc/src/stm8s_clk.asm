;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module stm8s_clk
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _CLKPrescTable
	.globl _HSIDivExp
	.globl _assert_failed
	.globl _CLK_DeInit
	.globl _CLK_FastHaltWakeUpCmd
	.globl _CLK_HSECmd
	.globl _CLK_HSICmd
	.globl _CLK_LSICmd
	.globl _CLK_CCOCmd
	.globl _CLK_ClockSwitchCmd
	.globl _CLK_SlowActiveHaltWakeUpCmd
	.globl _CLK_PeripheralClockConfig
	.globl _CLK_ClockSwitchConfig
	.globl _CLK_HSIPrescalerConfig
	.globl _CLK_CCOConfig
	.globl _CLK_ITConfig
	.globl _CLK_SYSCLKConfig
	.globl _CLK_SWIMConfig
	.globl _CLK_ClockSecuritySystemEnable
	.globl _CLK_GetSYSCLKSource
	.globl _CLK_GetClockFreq
	.globl _CLK_AdjustHSICalibrationValue
	.globl _CLK_SYSCLKEmergencyClear
	.globl _CLK_GetFlagStatus
	.globl _CLK_GetITStatus
	.globl _CLK_ClearITPendingBit
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
;	../src/stm8s_clk.c: 72: void CLK_DeInit(void)
;	-----------------------------------------
;	 function CLK_DeInit
;	-----------------------------------------
_CLK_DeInit:
;	../src/stm8s_clk.c: 74: CLK->ICKR = CLK_ICKR_RESET_VALUE;
	mov	0x50c0+0, #0x01
;	../src/stm8s_clk.c: 75: CLK->ECKR = CLK_ECKR_RESET_VALUE;
	mov	0x50c1+0, #0x00
;	../src/stm8s_clk.c: 76: CLK->SWR  = CLK_SWR_RESET_VALUE;
	mov	0x50c4+0, #0xe1
;	../src/stm8s_clk.c: 77: CLK->SWCR = CLK_SWCR_RESET_VALUE;
	mov	0x50c5+0, #0x00
;	../src/stm8s_clk.c: 78: CLK->CKDIVR = CLK_CKDIVR_RESET_VALUE;
	mov	0x50c6+0, #0x18
;	../src/stm8s_clk.c: 79: CLK->PCKENR1 = CLK_PCKENR1_RESET_VALUE;
	mov	0x50c7+0, #0xff
;	../src/stm8s_clk.c: 80: CLK->PCKENR2 = CLK_PCKENR2_RESET_VALUE;
	mov	0x50ca+0, #0xff
;	../src/stm8s_clk.c: 81: CLK->CSSR = CLK_CSSR_RESET_VALUE;
	mov	0x50c8+0, #0x00
;	../src/stm8s_clk.c: 82: CLK->CCOR = CLK_CCOR_RESET_VALUE;
	mov	0x50c9+0, #0x00
;	../src/stm8s_clk.c: 83: while ((CLK->CCOR & CLK_CCOR_CCOEN)!= 0)
00101$:
	ld	a, 0x50c9
	srl	a
	jrc	00101$
;	../src/stm8s_clk.c: 85: CLK->CCOR = CLK_CCOR_RESET_VALUE;
	mov	0x50c9+0, #0x00
;	../src/stm8s_clk.c: 86: CLK->HSITRIMR = CLK_HSITRIMR_RESET_VALUE;
	mov	0x50cc+0, #0x00
;	../src/stm8s_clk.c: 87: CLK->SWIMCCR = CLK_SWIMCCR_RESET_VALUE;
	mov	0x50cd+0, #0x00
;	../src/stm8s_clk.c: 88: }
	ret
;	../src/stm8s_clk.c: 99: void CLK_FastHaltWakeUpCmd(FunctionalState NewState)
;	-----------------------------------------
;	 function CLK_FastHaltWakeUpCmd
;	-----------------------------------------
_CLK_FastHaltWakeUpCmd:
;	../src/stm8s_clk.c: 102: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0x66
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
	ld	a, 0x50c0
;	../src/stm8s_clk.c: 104: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
	or	a, #0x04
	ld	0x50c0, a
	ret
00102$:
;	../src/stm8s_clk.c: 112: CLK->ICKR &= (uint8_t)(~CLK_ICKR_FHWU);
	and	a, #0xfb
	ld	0x50c0, a
;	../src/stm8s_clk.c: 114: }
	ret
;	../src/stm8s_clk.c: 121: void CLK_HSECmd(FunctionalState NewState)
;	-----------------------------------------
;	 function CLK_HSECmd
;	-----------------------------------------
_CLK_HSECmd:
;	../src/stm8s_clk.c: 124: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0x7c
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
	ld	a, 0x50c1
;	../src/stm8s_clk.c: 126: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
	or	a, #0x01
	ld	0x50c1, a
	ret
00102$:
;	../src/stm8s_clk.c: 134: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
	and	a, #0xfe
	ld	0x50c1, a
;	../src/stm8s_clk.c: 136: }
	ret
;	../src/stm8s_clk.c: 143: void CLK_HSICmd(FunctionalState NewState)
;	-----------------------------------------
;	 function CLK_HSICmd
;	-----------------------------------------
_CLK_HSICmd:
;	../src/stm8s_clk.c: 146: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0x92
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
	ld	a, 0x50c0
;	../src/stm8s_clk.c: 148: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
	or	a, #0x01
	ld	0x50c0, a
	ret
00102$:
;	../src/stm8s_clk.c: 156: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
	and	a, #0xfe
	ld	0x50c0, a
;	../src/stm8s_clk.c: 158: }
	ret
;	../src/stm8s_clk.c: 166: void CLK_LSICmd(FunctionalState NewState)
;	-----------------------------------------
;	 function CLK_LSICmd
;	-----------------------------------------
_CLK_LSICmd:
;	../src/stm8s_clk.c: 169: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0xa9
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
	ld	a, 0x50c0
;	../src/stm8s_clk.c: 171: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
	or	a, #0x08
	ld	0x50c0, a
	ret
00102$:
;	../src/stm8s_clk.c: 179: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
	and	a, #0xf7
	ld	0x50c0, a
;	../src/stm8s_clk.c: 181: }
	ret
;	../src/stm8s_clk.c: 189: void CLK_CCOCmd(FunctionalState NewState)
;	-----------------------------------------
;	 function CLK_CCOCmd
;	-----------------------------------------
_CLK_CCOCmd:
;	../src/stm8s_clk.c: 192: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0xc0
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
	ld	a, 0x50c9
;	../src/stm8s_clk.c: 194: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
	or	a, #0x01
	ld	0x50c9, a
	ret
00102$:
;	../src/stm8s_clk.c: 202: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOEN);
	and	a, #0xfe
	ld	0x50c9, a
;	../src/stm8s_clk.c: 204: }
	ret
;	../src/stm8s_clk.c: 213: void CLK_ClockSwitchCmd(FunctionalState NewState)
;	-----------------------------------------
;	 function CLK_ClockSwitchCmd
;	-----------------------------------------
_CLK_ClockSwitchCmd:
;	../src/stm8s_clk.c: 216: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0xd8
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
	ld	a, 0x50c5
;	../src/stm8s_clk.c: 218: if (NewState != DISABLE )
	tnz	(0x03, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
	or	a, #0x02
	ld	0x50c5, a
	ret
00102$:
;	../src/stm8s_clk.c: 226: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWEN);
	and	a, #0xfd
	ld	0x50c5, a
;	../src/stm8s_clk.c: 228: }
	ret
;	../src/stm8s_clk.c: 238: void CLK_SlowActiveHaltWakeUpCmd(FunctionalState NewState)
;	-----------------------------------------
;	 function CLK_SlowActiveHaltWakeUpCmd
;	-----------------------------------------
_CLK_SlowActiveHaltWakeUpCmd:
;	../src/stm8s_clk.c: 241: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0xf1
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
	ld	a, 0x50c0
;	../src/stm8s_clk.c: 243: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
	or	a, #0x20
	ld	0x50c0, a
	ret
00102$:
;	../src/stm8s_clk.c: 251: CLK->ICKR &= (uint8_t)(~CLK_ICKR_SWUAH);
	and	a, #0xdf
	ld	0x50c0, a
;	../src/stm8s_clk.c: 253: }
	ret
;	../src/stm8s_clk.c: 263: void CLK_PeripheralClockConfig(CLK_Peripheral_TypeDef CLK_Peripheral, FunctionalState NewState)
;	-----------------------------------------
;	 function CLK_PeripheralClockConfig
;	-----------------------------------------
_CLK_PeripheralClockConfig:
	pushw	x
;	../src/stm8s_clk.c: 266: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x06, sp)
	jreq	00113$
	ld	a, (0x06, sp)
	dec	a
	jreq	00113$
	push	#0x0a
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00113$:
;	../src/stm8s_clk.c: 267: assert_param(IS_CLK_PERIPHERAL_OK(CLK_Peripheral));
	tnz	(0x05, sp)
	jreq	00118$
	ld	a, (0x05, sp)
	dec	a
	jreq	00118$
	ld	a, (0x05, sp)
	sub	a, #0x03
	jrne	00262$
	inc	a
	.byte 0x21
00262$:
	clr	a
00263$:
	tnz	a
	jrne	00118$
	tnz	a
	jrne	00118$
	tnz	a
	jrne	00118$
	ld	a, (0x05, sp)
	sub	a, #0x04
	jrne	00268$
	inc	a
	ld	xl, a
	jra	00269$
00268$:
	clr	a
	ld	xl, a
00269$:
	ld	a, xl
	tnz	a
	jrne	00118$
	ld	a, (0x05, sp)
	sub	a, #0x05
	jrne	00272$
	inc	a
	.byte 0x21
00272$:
	clr	a
00273$:
	tnz	a
	jrne	00118$
	tnz	a
	jrne	00118$
	ld	a, xl
	tnz	a
	jrne	00118$
	ld	a, (0x05, sp)
	cp	a, #0x06
	jreq	00118$
	ld	a, (0x05, sp)
	cp	a, #0x07
	jreq	00118$
	ld	a, (0x05, sp)
	cp	a, #0x17
	jreq	00118$
	ld	a, (0x05, sp)
	cp	a, #0x13
	jreq	00118$
	ld	a, (0x05, sp)
	cp	a, #0x12
	jreq	00118$
	push	#0x0b
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00118$:
;	../src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
	ld	a, (0x05, sp)
	and	a, #0x0f
	push	a
	ld	a, #0x01
	ld	(0x03, sp), a
	pop	a
	tnz	a
	jreq	00293$
00292$:
	sll	(0x02, sp)
	dec	a
	jrne	00292$
00293$:
;	../src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
	ld	a, (0x02, sp)
	cpl	a
	ld	(0x01, sp), a
;	../src/stm8s_clk.c: 269: if (((uint8_t)CLK_Peripheral & (uint8_t)0x10) == 0x00)
	ld	a, (0x05, sp)
	bcp	a, #0x10
	jrne	00108$
;	../src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
	ld	a, 0x50c7
;	../src/stm8s_clk.c: 271: if (NewState != DISABLE)
	tnz	(0x06, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
	or	a, (0x02, sp)
	ld	0x50c7, a
	jra	00110$
00102$:
;	../src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
	and	a, (0x01, sp)
	ld	0x50c7, a
	jra	00110$
00108$:
;	../src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
	ld	a, 0x50ca
;	../src/stm8s_clk.c: 284: if (NewState != DISABLE)
	tnz	(0x06, sp)
	jreq	00105$
;	../src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
	or	a, (0x02, sp)
	ld	0x50ca, a
	jra	00110$
00105$:
;	../src/stm8s_clk.c: 292: CLK->PCKENR2 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
	and	a, (0x01, sp)
	ld	0x50ca, a
00110$:
;	../src/stm8s_clk.c: 295: }
	popw	x
	ret
;	../src/stm8s_clk.c: 309: ErrorStatus CLK_ClockSwitchConfig(CLK_SwitchMode_TypeDef CLK_SwitchMode, CLK_Source_TypeDef CLK_NewClock, FunctionalState ITState, CLK_CurrentClockState_TypeDef CLK_CurrentClockState)
;	-----------------------------------------
;	 function CLK_ClockSwitchConfig
;	-----------------------------------------
_CLK_ClockSwitchConfig:
	push	a
;	../src/stm8s_clk.c: 316: assert_param(IS_CLK_SOURCE_OK(CLK_NewClock));
	ld	a, (0x05, sp)
	cp	a, #0xe1
	jreq	00140$
	ld	a, (0x05, sp)
	cp	a, #0xd2
	jreq	00140$
	ld	a, (0x05, sp)
	cp	a, #0xb4
	jreq	00140$
	push	#0x3c
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00140$:
;	../src/stm8s_clk.c: 317: assert_param(IS_CLK_SWITCHMODE_OK(CLK_SwitchMode));
	ld	a, (0x04, sp)
	dec	a
	jrne	00309$
	ld	a, #0x01
	ld	(0x01, sp), a
	.byte 0xc1
00309$:
	clr	(0x01, sp)
00310$:
	tnz	(0x04, sp)
	jreq	00148$
	tnz	(0x01, sp)
	jrne	00148$
	push	#0x3d
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00148$:
;	../src/stm8s_clk.c: 318: assert_param(IS_FUNCTIONALSTATE_OK(ITState));
	tnz	(0x06, sp)
	jreq	00153$
	ld	a, (0x06, sp)
	dec	a
	jreq	00153$
	push	#0x3e
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00153$:
;	../src/stm8s_clk.c: 319: assert_param(IS_CLK_CURRENTCLOCKSTATE_OK(CLK_CurrentClockState));
	tnz	(0x07, sp)
	jreq	00158$
	ld	a, (0x07, sp)
	dec	a
	jreq	00158$
	push	#0x3f
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00158$:
;	../src/stm8s_clk.c: 322: clock_master = (CLK_Source_TypeDef)CLK->CMSR;
	ld	a, 0x50c3
	ld	yl, a
;	../src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
	ld	a, 0x50c5
;	../src/stm8s_clk.c: 325: if (CLK_SwitchMode == CLK_SWITCHMODE_AUTO)
	tnz	(0x01, sp)
	jreq	00122$
;	../src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
	or	a, #0x02
	ld	0x50c5, a
	ld	a, 0x50c5
;	../src/stm8s_clk.c: 331: if (ITState != DISABLE)
	tnz	(0x06, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 333: CLK->SWCR |= CLK_SWCR_SWIEN;
	or	a, #0x04
	ld	0x50c5, a
	jra	00103$
00102$:
;	../src/stm8s_clk.c: 337: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
	and	a, #0xfb
	ld	0x50c5, a
00103$:
;	../src/stm8s_clk.c: 341: CLK->SWR = (uint8_t)CLK_NewClock;
	ldw	x, #0x50c4
	ld	a, (0x05, sp)
	ld	(x), a
;	../src/stm8s_clk.c: 344: while((((CLK->SWCR & CLK_SWCR_SWBSY) != 0 )&& (DownCounter != 0)))
	clrw	x
	decw	x
00105$:
	ld	a, 0x50c5
	srl	a
	jrnc	00107$
	tnzw	x
	jreq	00107$
;	../src/stm8s_clk.c: 346: DownCounter--;
	decw	x
	jra	00105$
00107$:
;	../src/stm8s_clk.c: 349: if(DownCounter != 0)
	tnzw	x
	jreq	00109$
;	../src/stm8s_clk.c: 351: Swif = SUCCESS;
	ld	a, #0x01
	ld	xl, a
	jra	00123$
00109$:
;	../src/stm8s_clk.c: 355: Swif = ERROR;
	clr	a
	ld	xl, a
	jra	00123$
00122$:
;	../src/stm8s_clk.c: 361: if (ITState != DISABLE)
	tnz	(0x06, sp)
	jreq	00112$
;	../src/stm8s_clk.c: 363: CLK->SWCR |= CLK_SWCR_SWIEN;
	or	a, #0x04
	ld	0x50c5, a
	jra	00113$
00112$:
;	../src/stm8s_clk.c: 367: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
	and	a, #0xfb
	ld	0x50c5, a
00113$:
;	../src/stm8s_clk.c: 371: CLK->SWR = (uint8_t)CLK_NewClock;
	ldw	x, #0x50c4
	ld	a, (0x05, sp)
	ld	(x), a
;	../src/stm8s_clk.c: 374: while((((CLK->SWCR & CLK_SWCR_SWIF) != 0 ) && (DownCounter != 0)))
	clrw	x
	decw	x
00115$:
	ld	a, 0x50c5
	bcp	a, #0x08
	jreq	00117$
	tnzw	x
	jreq	00117$
;	../src/stm8s_clk.c: 376: DownCounter--;
	decw	x
	jra	00115$
00117$:
;	../src/stm8s_clk.c: 379: if(DownCounter != 0)
	tnzw	x
	jreq	00119$
;	../src/stm8s_clk.c: 382: CLK->SWCR |= CLK_SWCR_SWEN;
	bset	20677, #1
;	../src/stm8s_clk.c: 383: Swif = SUCCESS;
	ld	a, #0x01
	ld	xl, a
	jra	00123$
00119$:
;	../src/stm8s_clk.c: 387: Swif = ERROR;
	clr	a
	ld	xl, a
00123$:
;	../src/stm8s_clk.c: 390: if(Swif != ERROR)
	ld	a, xl
	tnz	a
	jreq	00136$
;	../src/stm8s_clk.c: 393: if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSI))
	tnz	(0x07, sp)
	jrne	00132$
	ld	a, yl
	cp	a, #0xe1
	jrne	00132$
;	../src/stm8s_clk.c: 395: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
	bres	20672, #0
	jra	00136$
00132$:
;	../src/stm8s_clk.c: 397: else if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_LSI))
	tnz	(0x07, sp)
	jrne	00128$
	ld	a, yl
	cp	a, #0xd2
	jrne	00128$
;	../src/stm8s_clk.c: 399: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
	bres	20672, #3
	jra	00136$
00128$:
;	../src/stm8s_clk.c: 401: else if ((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSE))
	tnz	(0x07, sp)
	jrne	00136$
	ld	a, yl
	cp	a, #0xb4
	jrne	00136$
;	../src/stm8s_clk.c: 403: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
	bres	20673, #0
00136$:
;	../src/stm8s_clk.c: 406: return(Swif);
	ld	a, xl
;	../src/stm8s_clk.c: 407: }
	addw	sp, #1
	ret
;	../src/stm8s_clk.c: 415: void CLK_HSIPrescalerConfig(CLK_Prescaler_TypeDef HSIPrescaler)
;	-----------------------------------------
;	 function CLK_HSIPrescalerConfig
;	-----------------------------------------
_CLK_HSIPrescalerConfig:
;	../src/stm8s_clk.c: 418: assert_param(IS_CLK_HSIPRESCALER_OK(HSIPrescaler));
	tnz	(0x03, sp)
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x08
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x10
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x18
	jreq	00104$
	push	#0xa2
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../src/stm8s_clk.c: 421: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
	ld	a, 0x50c6
	and	a, #0xe7
	ld	0x50c6, a
;	../src/stm8s_clk.c: 424: CLK->CKDIVR |= (uint8_t)HSIPrescaler;
	ld	a, 0x50c6
	or	a, (0x03, sp)
	ld	0x50c6, a
;	../src/stm8s_clk.c: 425: }
	ret
;	../src/stm8s_clk.c: 436: void CLK_CCOConfig(CLK_Output_TypeDef CLK_CCO)
;	-----------------------------------------
;	 function CLK_CCOConfig
;	-----------------------------------------
_CLK_CCOConfig:
;	../src/stm8s_clk.c: 439: assert_param(IS_CLK_OUTPUT_OK(CLK_CCO));
	tnz	(0x03, sp)
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x04
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x02
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x08
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x0a
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x0c
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x0e
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x10
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x12
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x14
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x16
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x18
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x1a
	jreq	00104$
	push	#0xb7
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../src/stm8s_clk.c: 442: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOSEL);
	ld	a, 0x50c9
	and	a, #0xe1
	ld	0x50c9, a
;	../src/stm8s_clk.c: 445: CLK->CCOR |= (uint8_t)CLK_CCO;
	ld	a, 0x50c9
	or	a, (0x03, sp)
	ld	0x50c9, a
;	../src/stm8s_clk.c: 448: CLK->CCOR |= CLK_CCOR_CCOEN;
	bset	20681, #0
;	../src/stm8s_clk.c: 449: }
	ret
;	../src/stm8s_clk.c: 459: void CLK_ITConfig(CLK_IT_TypeDef CLK_IT, FunctionalState NewState)
;	-----------------------------------------
;	 function CLK_ITConfig
;	-----------------------------------------
_CLK_ITConfig:
	push	a
;	../src/stm8s_clk.c: 462: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x05, sp)
	jreq	00115$
	ld	a, (0x05, sp)
	dec	a
	jreq	00115$
	push	#0xce
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00115$:
;	../src/stm8s_clk.c: 463: assert_param(IS_CLK_IT_OK(CLK_IT));
	ld	a, (0x04, sp)
	sub	a, #0x0c
	jrne	00174$
	inc	a
	ld	(0x01, sp), a
	.byte 0xc1
00174$:
	clr	(0x01, sp)
00175$:
	ld	a, (0x04, sp)
	sub	a, #0x1c
	jrne	00177$
	inc	a
	.byte 0x21
00177$:
	clr	a
00178$:
	tnz	(0x01, sp)
	jrne	00120$
	tnz	a
	jrne	00120$
	push	a
	push	#0xcf
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
	pop	a
00120$:
;	../src/stm8s_clk.c: 465: if (NewState != DISABLE)
	tnz	(0x05, sp)
	jreq	00110$
;	../src/stm8s_clk.c: 467: switch (CLK_IT)
	tnz	(0x01, sp)
	jrne	00102$
	tnz	a
	jreq	00112$
;	../src/stm8s_clk.c: 470: CLK->SWCR |= CLK_SWCR_SWIEN;
	bset	20677, #2
;	../src/stm8s_clk.c: 471: break;
	jra	00112$
;	../src/stm8s_clk.c: 472: case CLK_IT_CSSD: /* Enable the clock security system detection interrupt */
00102$:
;	../src/stm8s_clk.c: 473: CLK->CSSR |= CLK_CSSR_CSSDIE;
	bset	20680, #2
;	../src/stm8s_clk.c: 474: break;
	jra	00112$
;	../src/stm8s_clk.c: 477: }
00110$:
;	../src/stm8s_clk.c: 481: switch (CLK_IT)
	tnz	(0x01, sp)
	jrne	00106$
	tnz	a
	jreq	00112$
;	../src/stm8s_clk.c: 484: CLK->SWCR  &= (uint8_t)(~CLK_SWCR_SWIEN);
	bres	20677, #2
;	../src/stm8s_clk.c: 485: break;
	jra	00112$
;	../src/stm8s_clk.c: 486: case CLK_IT_CSSD: /* Disable the clock security system detection interrupt */
00106$:
;	../src/stm8s_clk.c: 487: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSDIE);
	bres	20680, #2
;	../src/stm8s_clk.c: 491: }
00112$:
;	../src/stm8s_clk.c: 493: }
	pop	a
	ret
;	../src/stm8s_clk.c: 500: void CLK_SYSCLKConfig(CLK_Prescaler_TypeDef CLK_Prescaler)
;	-----------------------------------------
;	 function CLK_SYSCLKConfig
;	-----------------------------------------
_CLK_SYSCLKConfig:
	pushw	x
;	../src/stm8s_clk.c: 503: assert_param(IS_CLK_PRESCALER_OK(CLK_Prescaler));
	tnz	(0x05, sp)
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x08
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x10
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x18
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x80
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x81
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x82
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x83
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x84
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x85
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x86
	jreq	00107$
	ld	a, (0x05, sp)
	cp	a, #0x87
	jreq	00107$
	push	#0xf7
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
	ld	a, 0x50c6
;	../src/stm8s_clk.c: 505: if (((uint8_t)CLK_Prescaler & (uint8_t)0x80) == 0x00) /* Bit7 = 0 means HSI divider */
	tnz	(0x05, sp)
	jrmi	00102$
;	../src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
	and	a, #0xe7
	ld	0x50c6, a
;	../src/stm8s_clk.c: 508: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_HSIDIV);
	ld	a, 0x50c6
	ld	(0x02, sp), a
	ld	a, (0x05, sp)
	and	a, #0x18
	or	a, (0x02, sp)
	ld	0x50c6, a
	jra	00104$
00102$:
;	../src/stm8s_clk.c: 512: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_CPUDIV);
	and	a, #0xf8
	ld	0x50c6, a
;	../src/stm8s_clk.c: 513: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_CPUDIV);
	ld	a, 0x50c6
	ld	(0x01, sp), a
	ld	a, (0x05, sp)
	and	a, #0x07
	or	a, (0x01, sp)
	ld	0x50c6, a
00104$:
;	../src/stm8s_clk.c: 515: }
	popw	x
	ret
;	../src/stm8s_clk.c: 523: void CLK_SWIMConfig(CLK_SWIMDivider_TypeDef CLK_SWIMDivider)
;	-----------------------------------------
;	 function CLK_SWIMConfig
;	-----------------------------------------
_CLK_SWIMConfig:
;	../src/stm8s_clk.c: 526: assert_param(IS_CLK_SWIMDIVIDER_OK(CLK_SWIMDivider));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0x0e
	push	#0x02
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
	ld	a, 0x50cd
;	../src/stm8s_clk.c: 528: if (CLK_SWIMDivider != CLK_SWIMDIVIDER_2)
	tnz	(0x03, sp)
	jreq	00102$
;	../src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
	or	a, #0x01
	ld	0x50cd, a
	ret
00102$:
;	../src/stm8s_clk.c: 536: CLK->SWIMCCR &= (uint8_t)(~CLK_SWIMCCR_SWIMDIV);
	and	a, #0xfe
	ld	0x50cd, a
;	../src/stm8s_clk.c: 538: }
	ret
;	../src/stm8s_clk.c: 547: void CLK_ClockSecuritySystemEnable(void)
;	-----------------------------------------
;	 function CLK_ClockSecuritySystemEnable
;	-----------------------------------------
_CLK_ClockSecuritySystemEnable:
;	../src/stm8s_clk.c: 550: CLK->CSSR |= CLK_CSSR_CSSEN;
	bset	20680, #0
;	../src/stm8s_clk.c: 551: }
	ret
;	../src/stm8s_clk.c: 559: CLK_Source_TypeDef CLK_GetSYSCLKSource(void)
;	-----------------------------------------
;	 function CLK_GetSYSCLKSource
;	-----------------------------------------
_CLK_GetSYSCLKSource:
;	../src/stm8s_clk.c: 561: return((CLK_Source_TypeDef)CLK->CMSR);
	ld	a, 0x50c3
;	../src/stm8s_clk.c: 562: }
	ret
;	../src/stm8s_clk.c: 569: uint32_t CLK_GetClockFreq(void)
;	-----------------------------------------
;	 function CLK_GetClockFreq
;	-----------------------------------------
_CLK_GetClockFreq:
	sub	sp, #5
;	../src/stm8s_clk.c: 576: clocksource = (CLK_Source_TypeDef)CLK->CMSR;
	ld	a, 0x50c3
	ld	(0x01, sp), a
;	../src/stm8s_clk.c: 578: if (clocksource == CLK_SOURCE_HSI)
	ld	a, (0x01, sp)
	cp	a, #0xe1
	jrne	00105$
;	../src/stm8s_clk.c: 580: tmp = (uint8_t)(CLK->CKDIVR & CLK_CKDIVR_HSIDIV);
	ld	a, 0x50c6
	and	a, #0x18
;	../src/stm8s_clk.c: 581: tmp = (uint8_t)(tmp >> 3);
	srl	a
	srl	a
	srl	a
;	../src/stm8s_clk.c: 582: clockfrequency = HSI_VALUE >> HSIDivExp[tmp];
	clrw	x
	ld	xl, a
	addw	x, #_HSIDivExp
	ld	a, (x)
	ldw	x, #0x2400
	ldw	y, #0x00f4
	tnz	a
	jreq	00123$
00122$:
	srlw	y
	rrcw	x
	dec	a
	jrne	00122$
00123$:
	ldw	(0x04, sp), x
	jra	00106$
00105$:
;	../src/stm8s_clk.c: 584: else if ( clocksource == CLK_SOURCE_LSI)
	ld	a, (0x01, sp)
	cp	a, #0xd2
	jrne	00102$
;	../src/stm8s_clk.c: 586: clockfrequency = LSI_VALUE;
	ldw	x, #0xf400
	ldw	(0x04, sp), x
	ldw	y, #0x0001
	jra	00106$
00102$:
;	../src/stm8s_clk.c: 590: clockfrequency = HSE_VALUE;
	ldw	x, #0x2400
	ldw	(0x04, sp), x
	ldw	y, #0x00f4
00106$:
;	../src/stm8s_clk.c: 593: return((uint32_t)clockfrequency);
	ldw	x, (0x04, sp)
;	../src/stm8s_clk.c: 594: }
	addw	sp, #5
	ret
;	../src/stm8s_clk.c: 603: void CLK_AdjustHSICalibrationValue(CLK_HSITrimValue_TypeDef CLK_HSICalibrationValue)
;	-----------------------------------------
;	 function CLK_AdjustHSICalibrationValue
;	-----------------------------------------
_CLK_AdjustHSICalibrationValue:
;	../src/stm8s_clk.c: 606: assert_param(IS_CLK_HSITRIMVALUE_OK(CLK_HSICalibrationValue));
	tnz	(0x03, sp)
	jreq	00104$
	ld	a, (0x03, sp)
	dec	a
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x02
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x03
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x04
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x05
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x06
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x07
	jreq	00104$
	push	#0x5e
	push	#0x02
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../src/stm8s_clk.c: 609: CLK->HSITRIMR = (uint8_t)( (uint8_t)(CLK->HSITRIMR & (uint8_t)(~CLK_HSITRIMR_HSITRIM))|((uint8_t)CLK_HSICalibrationValue));
	ld	a, 0x50cc
	and	a, #0xf8
	or	a, (0x03, sp)
	ld	0x50cc, a
;	../src/stm8s_clk.c: 610: }
	ret
;	../src/stm8s_clk.c: 621: void CLK_SYSCLKEmergencyClear(void)
;	-----------------------------------------
;	 function CLK_SYSCLKEmergencyClear
;	-----------------------------------------
_CLK_SYSCLKEmergencyClear:
;	../src/stm8s_clk.c: 623: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWBSY);
	bres	20677, #0
;	../src/stm8s_clk.c: 624: }
	ret
;	../src/stm8s_clk.c: 633: FlagStatus CLK_GetFlagStatus(CLK_Flag_TypeDef CLK_FLAG)
;	-----------------------------------------
;	 function CLK_GetFlagStatus
;	-----------------------------------------
_CLK_GetFlagStatus:
	push	a
;	../src/stm8s_clk.c: 640: assert_param(IS_CLK_FLAG_OK(CLK_FLAG));
	ldw	x, (0x04, sp)
	cpw	x, #0x0110
	jreq	00119$
	ldw	x, (0x04, sp)
	cpw	x, #0x0102
	jreq	00119$
	ldw	x, (0x04, sp)
	cpw	x, #0x0202
	jreq	00119$
	ldw	x, (0x04, sp)
	cpw	x, #0x0308
	jreq	00119$
	ldw	x, (0x04, sp)
	cpw	x, #0x0301
	jreq	00119$
	ldw	x, (0x04, sp)
	cpw	x, #0x0408
	jreq	00119$
	ldw	x, (0x04, sp)
	cpw	x, #0x0402
	jreq	00119$
	ldw	x, (0x04, sp)
	cpw	x, #0x0504
	jreq	00119$
	ldw	x, (0x04, sp)
	cpw	x, #0x0502
	jreq	00119$
	push	#0x80
	push	#0x02
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00119$:
;	../src/stm8s_clk.c: 643: statusreg = (uint16_t)((uint16_t)CLK_FLAG & (uint16_t)0xFF00);
	clr	a
	ld	xl, a
	ld	a, (0x04, sp)
	ld	xh, a
;	../src/stm8s_clk.c: 646: if (statusreg == 0x0100) /* The flag to check is in ICKRregister */
	cpw	x, #0x0100
	jrne	00111$
;	../src/stm8s_clk.c: 648: tmpreg = CLK->ICKR;
	ld	a, 0x50c0
	jra	00112$
00111$:
;	../src/stm8s_clk.c: 650: else if (statusreg == 0x0200) /* The flag to check is in ECKRregister */
	cpw	x, #0x0200
	jrne	00108$
;	../src/stm8s_clk.c: 652: tmpreg = CLK->ECKR;
	ld	a, 0x50c1
	jra	00112$
00108$:
;	../src/stm8s_clk.c: 654: else if (statusreg == 0x0300) /* The flag to check is in SWIC register */
	cpw	x, #0x0300
	jrne	00105$
;	../src/stm8s_clk.c: 656: tmpreg = CLK->SWCR;
	ld	a, 0x50c5
	jra	00112$
00105$:
;	../src/stm8s_clk.c: 658: else if (statusreg == 0x0400) /* The flag to check is in CSS register */
	cpw	x, #0x0400
	jrne	00102$
;	../src/stm8s_clk.c: 660: tmpreg = CLK->CSSR;
	ld	a, 0x50c8
	jra	00112$
00102$:
;	../src/stm8s_clk.c: 664: tmpreg = CLK->CCOR;
	ld	a, 0x50c9
00112$:
;	../src/stm8s_clk.c: 667: if ((tmpreg & (uint8_t)CLK_FLAG) != (uint8_t)RESET)
	push	a
	ld	a, (0x06, sp)
	ld	(0x02, sp), a
	pop	a
	and	a, (0x01, sp)
	jreq	00114$
;	../src/stm8s_clk.c: 669: bitstatus = SET;
	ld	a, #0x01
;	../src/stm8s_clk.c: 673: bitstatus = RESET;
	.byte 0x21
00114$:
	clr	a
00115$:
;	../src/stm8s_clk.c: 677: return((FlagStatus)bitstatus);
;	../src/stm8s_clk.c: 678: }
	addw	sp, #1
	ret
;	../src/stm8s_clk.c: 686: ITStatus CLK_GetITStatus(CLK_IT_TypeDef CLK_IT)
;	-----------------------------------------
;	 function CLK_GetITStatus
;	-----------------------------------------
_CLK_GetITStatus:
;	../src/stm8s_clk.c: 691: assert_param(IS_CLK_IT_OK(CLK_IT));
	ld	a, (0x03, sp)
	sub	a, #0x1c
	jrne	00143$
	inc	a
	.byte 0x21
00143$:
	clr	a
00144$:
	push	a
	ld	a, (0x04, sp)
	cp	a, #0x0c
	pop	a
	jreq	00113$
	tnz	a
	jrne	00113$
	push	a
	push	#0xb3
	push	#0x02
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
	pop	a
00113$:
;	../src/stm8s_clk.c: 693: if (CLK_IT == CLK_IT_SWIF)
	tnz	a
	jreq	00108$
;	../src/stm8s_clk.c: 696: if ((CLK->SWCR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
	ld	a, 0x50c5
	and	a, (0x03, sp)
;	../src/stm8s_clk.c: 698: bitstatus = SET;
	sub	a, #0x0c
	jrne	00102$
	inc	a
	ret
00102$:
;	../src/stm8s_clk.c: 702: bitstatus = RESET;
	clr	a
	ret
00108$:
;	../src/stm8s_clk.c: 708: if ((CLK->CSSR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
	ld	a, 0x50c8
	and	a, (0x03, sp)
;	../src/stm8s_clk.c: 710: bitstatus = SET;
	sub	a, #0x0c
	jrne	00105$
	inc	a
	ret
00105$:
;	../src/stm8s_clk.c: 714: bitstatus = RESET;
	clr	a
;	../src/stm8s_clk.c: 719: return bitstatus;
;	../src/stm8s_clk.c: 720: }
	ret
;	../src/stm8s_clk.c: 728: void CLK_ClearITPendingBit(CLK_IT_TypeDef CLK_IT)
;	-----------------------------------------
;	 function CLK_ClearITPendingBit
;	-----------------------------------------
_CLK_ClearITPendingBit:
;	../src/stm8s_clk.c: 731: assert_param(IS_CLK_IT_OK(CLK_IT));
	ld	a, (0x03, sp)
	sub	a, #0x0c
	jrne	00127$
	inc	a
	.byte 0x21
00127$:
	clr	a
00128$:
	tnz	a
	jrne	00107$
	push	a
	ld	a, (0x04, sp)
	cp	a, #0x1c
	pop	a
	jreq	00107$
	push	a
	push	#0xdb
	push	#0x02
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
	pop	a
00107$:
;	../src/stm8s_clk.c: 733: if (CLK_IT == (uint8_t)CLK_IT_CSSD)
	tnz	a
	jreq	00102$
;	../src/stm8s_clk.c: 736: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSD);
	bres	20680, #3
	ret
00102$:
;	../src/stm8s_clk.c: 741: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIF);
	bres	20677, #3
;	../src/stm8s_clk.c: 744: }
	ret
	.area CODE
	.area CONST
_HSIDivExp:
	.db #0x00	; 0
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x03	; 3
_CLKPrescTable:
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x04	; 4
	.db #0x08	; 8
	.db #0x0a	; 10
	.db #0x10	; 16
	.db #0x14	; 20
	.db #0x28	; 40
___str_0:
	.ascii "../src/stm8s_clk.c"
	.db 0x00
	.area INITIALIZER
	.area CABS (ABS)
