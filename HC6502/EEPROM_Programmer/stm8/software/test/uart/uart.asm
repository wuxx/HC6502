;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 28 2016) (Linux)
; This file was generated Mon Dec  3 20:03:33 2018
;--------------------------------------------------------
	.module uart
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _system_clock_init
	.globl _strlen
	.globl _uart_puts
	.globl _uart_init
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
;	uart.c: 50: void system_clock_init()
;	-----------------------------------------
;	 function system_clock_init
;	-----------------------------------------
_system_clock_init:
;	uart.c: 52: nointerrupts();
	sim 
;	uart.c: 53: CLK_ICKR = 0;
	mov	0x50c0+0, #0x00
;	uart.c: 54: CLK_ICKR |= CLK_ICKR_HSIEN;
	bset	0x50c0, #0
;	uart.c: 55: CLK_ECKR = 0;
	mov	0x50c1+0, #0x00
;	uart.c: 56: CLK_SWR = CLK_SWR_HSI;
	mov	0x50c4+0, #0xe1
;	uart.c: 57: while (0 == (CLK_ICKR & CLK_ICKR_HSIRDY));
00101$:
	ldw	x, #0x50c0
	ld	a, (x)
	bcp	a, #0x02
	jreq	00101$
;	uart.c: 58: CLK_CKDIVR = 0;
	mov	0x50c6+0, #0x00
;	uart.c: 59: CLK_PCKENR1 = 0xFF;
	mov	0x50c7+0, #0xff
;	uart.c: 60: CLK_PCKENR2 = 0xFF;
	mov	0x50ca+0, #0xff
;	uart.c: 61: CLK_CCOR = 0;
	mov	0x50c9+0, #0x00
;	uart.c: 62: CLK_HSITRIMR = 0;
	mov	0x50cc+0, #0x00
;	uart.c: 63: CLK_SWIMCCR = 0;
	mov	0x50cd+0, #0x00
;	uart.c: 65: CLK_SWCR = 0;
	mov	0x50c5+0, #0x00
;	uart.c: 66: CLK_SWCR |= CLK_SWCR_SWEN;
	ldw	x, #0x50c5
	ld	a, (x)
	or	a, #0x02
	ld	(x), a
;	uart.c: 67: while (0 != (CLK_SWCR & CLK_SWCR_SWBSY));
00104$:
	ldw	x, #0x50c5
	ld	a, (x)
	srl	a
	jrc	00104$
;	uart.c: 68: interrupts();
	rim 
	ret
;	uart.c: 77: int uart_puts(const char *s) {
;	-----------------------------------------
;	 function uart_puts
;	-----------------------------------------
_uart_puts:
	sub	sp, #3
;	uart.c: 79: for(i = 0; i < strlen(s); i++) {
	clr	(0x01, sp)
00106$:
	ldw	x, (0x06, sp)
	pushw	x
	call	_strlen
	addw	sp, #2
	ldw	(0x02, sp), x
	clrw	x
	ld	a, (0x01, sp)
	ld	xl, a
	cpw	x, (0x02, sp)
	jrnc	00104$
;	uart.c: 80: while(!(UART1_SR & UART_SR_TXE));
00101$:
	ldw	x, #0x5230
	ld	a, (x)
	tnz	a
	jrpl	00101$
;	uart.c: 81: UART1_DR = s[i];
	clrw	x
	ld	a, (0x01, sp)
	ld	xl, a
	addw	x, (0x06, sp)
	ld	a, (x)
	ldw	x, #0x5231
	ld	(x), a
;	uart.c: 79: for(i = 0; i < strlen(s); i++) {
	inc	(0x01, sp)
	jra	00106$
00104$:
;	uart.c: 84: return(i);
	clrw	x
	ld	a, (0x01, sp)
	ld	xl, a
	addw	sp, #3
	ret
;	uart.c: 90: void uart_init() {
;	-----------------------------------------
;	 function uart_init
;	-----------------------------------------
_uart_init:
;	uart.c: 92: PD_DDR = 0xBF;
	mov	0x5011+0, #0xbf
;	uart.c: 93: PD_CR1 = 0xFF;
	mov	0x5012+0, #0xff
;	uart.c: 96: UART1_CR2 = UART_CR2_TEN | UART_CR2_REN;
	mov	0x5235+0, #0x0c
;	uart.c: 98: UART1_CR3 &= ~(UART_CR3_STOP1 | UART_CR3_STOP0);
	ldw	x, #0x5236
	ld	a, (x)
	and	a, #0xcf
	ld	(x), a
;	uart.c: 100: UART1_BRR2 = 0x0B;
	mov	0x5233+0, #0x0b
;	uart.c: 101: UART1_BRR1 = 0x08;
	mov	0x5232+0, #0x08
	ret
;	uart.c: 104: int main() {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	sub	sp, #8
;	uart.c: 25: PA_ODR = 0x00;
	mov	0x5000+0, #0x00
;	uart.c: 26: PA_DDR = 0xFF;
	mov	0x5002+0, #0xff
;	uart.c: 27: PA_CR1 = 0xFF;
	mov	0x5003+0, #0xff
;	uart.c: 28: PA_CR2 = 0x00;
	mov	0x5004+0, #0x00
;	uart.c: 30: PB_ODR = 0x00;
	mov	0x5005+0, #0x00
;	uart.c: 31: PB_DDR = 0xFF;
	mov	0x5007+0, #0xff
;	uart.c: 32: PB_CR1 = 0xFF;
	mov	0x5008+0, #0xff
;	uart.c: 33: PB_CR2 = 0x00;
	mov	0x5009+0, #0x00
;	uart.c: 35: PC_ODR = 0x00;
	mov	0x500a+0, #0x00
;	uart.c: 36: PC_DDR = 0xFF;
	mov	0x500c+0, #0xff
;	uart.c: 37: PC_CR1 = 0xFF;
	mov	0x500d+0, #0xff
;	uart.c: 38: PC_CR2 = 0x00;
	mov	0x500e+0, #0x00
;	uart.c: 40: PD_ODR = 0x00;
	mov	0x500f+0, #0x00
;	uart.c: 41: PD_DDR = 0xFF;
	mov	0x5011+0, #0xff
;	uart.c: 42: PD_CR1 = 0xFF;
	mov	0x5012+0, #0xff
;	uart.c: 43: PD_CR2 = 0x00;
	mov	0x5013+0, #0x00
;	uart.c: 106: system_clock_init();
	call	_system_clock_init
;	uart.c: 107: uart_init();
	call	_uart_init
;	uart.c: 109: while(1) {
00103$:
;	uart.c: 110: uart_puts("STM8S at 115200 baud. Welcome and keep up the good work!\r\n");
	ldw	x, #___str_0+0
	pushw	x
	call	_uart_puts
	addw	sp, #2
;	uart.c: 111: __delay();
	ldw	x, #0x0900
	ldw	(0x03, sp), x
	ld	a, #0x3d
	clr	(0x01, sp)
00108$:
	nop 
	ldw	x, (0x03, sp)
	subw	x, #0x0001
	ldw	(0x07, sp), x
	sbc	a, #0x00
	ld	xl, a
	ld	a, (0x01, sp)
	sbc	a, #0x00
	ld	xh, a
	rlwa	x
	ld	(0x01, sp), a
	rrwa	x
	ldw	y, (0x07, sp)
	ldw	(0x03, sp), y
	ld	a, xl
	ldw	y, (0x07, sp)
	jrne	00108$
	tnzw	x
	jreq	00103$
	jra	00108$
	addw	sp, #8
	ret
	.area CODE
___str_0:
	.ascii "STM8S at 115200 baud. Welcome and keep up the good work!"
	.db 0x0D
	.db 0x0A
	.db 0x00
	.area INITIALIZER
	.area CABS (ABS)
