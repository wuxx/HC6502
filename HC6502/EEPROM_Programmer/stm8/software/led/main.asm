;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 28 2016) (Linux)
; This file was generated Mon Dec  3 17:37:04 2018
;--------------------------------------------------------
	.module main
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _mdelay
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME
__interrupt_vect:
	int s_GSINIT ;reset
	int 0x0000 ;trap
	int 0x0000 ;int0
	int 0x0000 ;int1
	int 0x0000 ;int2
	int 0x0000 ;int3
	int 0x0000 ;int4
	int 0x0000 ;int5
	int 0x0000 ;int6
	int 0x0000 ;int7
	int 0x0000 ;int8
	int 0x0000 ;int9
	int 0x0000 ;int10
	int 0x0000 ;int11
	int 0x0000 ;int12
	int 0x0000 ;int13
	int 0x0000 ;int14
	int 0x0000 ;int15
	int 0x0000 ;int16
	int 0x0000 ;int17
	int 0x0000 ;int18
	int 0x0000 ;int19
	int 0x0000 ;int20
	int 0x0000 ;int21
	int 0x0000 ;int22
	int 0x0000 ;int23
	int 0x0000 ;int24
	int 0x0000 ;int25
	int 0x0000 ;int26
	int 0x0000 ;int27
	int 0x0000 ;int28
	int 0x0000 ;int29
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
__sdcc_gs_init_startup:
__sdcc_init_data:
; stm8_genXINIT() start
	ldw x, #l_DATA
	jreq	00002$
00001$:
	clr (s_DATA - 1, x)
	decw x
	jrne	00001$
00002$:
	ldw	x, #l_INITIALIZER
	jreq	00004$
00003$:
	ld	a, (s_INITIALIZER - 1, x)
	ld	(s_INITIALIZED - 1, x), a
	decw	x
	jrne	00003$
00004$:
; stm8_genXINIT() end
	.area GSFINAL
	jp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
__sdcc_program_startup:
	jp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	main.c: 19: void mdelay(unsigned int ms)
;	-----------------------------------------
;	 function mdelay
;	-----------------------------------------
_mdelay:
	sub	sp, #4
;	main.c: 22: for(i = 0; i < ms; i++) {
	clrw	x
	ldw	(0x01, sp), x
00107$:
	ldw	y, (0x01, sp)
	ldw	x, y
	cpw	x, (0x07, sp)
	jrnc	00109$
;	main.c: 23: for(x = 0; x < 100; x++);
	ldw	x, #0x0064
00105$:
	decw	x
	ldw	(0x03, sp), x
	ldw	x, (0x03, sp)
	ldw	y, (0x03, sp)
	jrne	00105$
;	main.c: 22: for(i = 0; i < ms; i++) {
	ldw	x, (0x01, sp)
	incw	x
	ldw	(0x01, sp), x
	jra	00107$
00109$:
	addw	sp, #4
	ret
;	main.c: 27: void main()
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	main.c: 31: PB_DDR |= 0x20;
	ldw	x, #0x5007
	ld	a, (x)
	or	a, #0x20
	ld	(x), a
;	main.c: 32: PB_CR1 |= 0x20;
	ldw	x, #0x5008
	ld	a, (x)
	or	a, #0x20
	ld	(x), a
;	main.c: 33: PB_CR2 |= 0x00;
	ldw	x, #0x5009
	ld	a, (x)
	ldw	x, #0x5009
	ld	(x), a
;	main.c: 35: while (1) {
00102$:
;	main.c: 36: PB_ODR ^= 0x00;
	ldw	x, #0x5005
	ld	a, (x)
	ldw	x, #0x5005
	ld	(x), a
;	main.c: 38: mdelay(1000);
	push	#0xe8
	push	#0x03
	call	_mdelay
	addw	sp, #2
;	main.c: 40: PB_ODR ^= 0xf0;
	ldw	x, #0x5005
	ld	a, (x)
	xor	a, #0xf0
	ld	(x), a
;	main.c: 42: mdelay(1000);
	push	#0xe8
	push	#0x03
	call	_mdelay
	addw	sp, #2
	jra	00102$
	ret
	.area CODE
	.area INITIALIZER
	.area CABS (ABS)
