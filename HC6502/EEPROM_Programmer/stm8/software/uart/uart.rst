                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 28 2016) (Linux)
                                      4 ; This file was generated Mon Dec  3 20:03:33 2018
                                      5 ;--------------------------------------------------------
                                      6 	.module uart
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _system_clock_init
                                     14 	.globl _strlen
                                     15 	.globl _uart_puts
                                     16 	.globl _uart_init
                                     17 ;--------------------------------------------------------
                                     18 ; ram data
                                     19 ;--------------------------------------------------------
                                     20 	.area DATA
                                     21 ;--------------------------------------------------------
                                     22 ; ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area INITIALIZED
                                     25 ;--------------------------------------------------------
                                     26 ; Stack segment in internal ram 
                                     27 ;--------------------------------------------------------
                                     28 	.area	SSEG
      000001                         29 __start__stack:
      000001                         30 	.ds	1
                                     31 
                                     32 ;--------------------------------------------------------
                                     33 ; absolute external ram data
                                     34 ;--------------------------------------------------------
                                     35 	.area DABS (ABS)
                                     36 ;--------------------------------------------------------
                                     37 ; interrupt vector 
                                     38 ;--------------------------------------------------------
                                     39 	.area HOME
      008000                         40 __interrupt_vect:
      008000 82 00 80 83             41 	int s_GSINIT ;reset
      008004 82 00 00 00             42 	int 0x0000 ;trap
      008008 82 00 00 00             43 	int 0x0000 ;int0
      00800C 82 00 00 00             44 	int 0x0000 ;int1
      008010 82 00 00 00             45 	int 0x0000 ;int2
      008014 82 00 00 00             46 	int 0x0000 ;int3
      008018 82 00 00 00             47 	int 0x0000 ;int4
      00801C 82 00 00 00             48 	int 0x0000 ;int5
      008020 82 00 00 00             49 	int 0x0000 ;int6
      008024 82 00 00 00             50 	int 0x0000 ;int7
      008028 82 00 00 00             51 	int 0x0000 ;int8
      00802C 82 00 00 00             52 	int 0x0000 ;int9
      008030 82 00 00 00             53 	int 0x0000 ;int10
      008034 82 00 00 00             54 	int 0x0000 ;int11
      008038 82 00 00 00             55 	int 0x0000 ;int12
      00803C 82 00 00 00             56 	int 0x0000 ;int13
      008040 82 00 00 00             57 	int 0x0000 ;int14
      008044 82 00 00 00             58 	int 0x0000 ;int15
      008048 82 00 00 00             59 	int 0x0000 ;int16
      00804C 82 00 00 00             60 	int 0x0000 ;int17
      008050 82 00 00 00             61 	int 0x0000 ;int18
      008054 82 00 00 00             62 	int 0x0000 ;int19
      008058 82 00 00 00             63 	int 0x0000 ;int20
      00805C 82 00 00 00             64 	int 0x0000 ;int21
      008060 82 00 00 00             65 	int 0x0000 ;int22
      008064 82 00 00 00             66 	int 0x0000 ;int23
      008068 82 00 00 00             67 	int 0x0000 ;int24
      00806C 82 00 00 00             68 	int 0x0000 ;int25
      008070 82 00 00 00             69 	int 0x0000 ;int26
      008074 82 00 00 00             70 	int 0x0000 ;int27
      008078 82 00 00 00             71 	int 0x0000 ;int28
      00807C 82 00 00 00             72 	int 0x0000 ;int29
                                     73 ;--------------------------------------------------------
                                     74 ; global & static initialisations
                                     75 ;--------------------------------------------------------
                                     76 	.area HOME
                                     77 	.area GSINIT
                                     78 	.area GSFINAL
                                     79 	.area GSINIT
      008083                         80 __sdcc_gs_init_startup:
      008083                         81 __sdcc_init_data:
                                     82 ; stm8_genXINIT() start
      008083 AE 00 00         [ 2]   83 	ldw x, #l_DATA
      008086 27 07            [ 1]   84 	jreq	00002$
      008088                         85 00001$:
      008088 72 4F 00 00      [ 1]   86 	clr (s_DATA - 1, x)
      00808C 5A               [ 2]   87 	decw x
      00808D 26 F9            [ 1]   88 	jrne	00001$
      00808F                         89 00002$:
      00808F AE 00 00         [ 2]   90 	ldw	x, #l_INITIALIZER
      008092 27 09            [ 1]   91 	jreq	00004$
      008094                         92 00003$:
      008094 D6 81 FC         [ 1]   93 	ld	a, (s_INITIALIZER - 1, x)
      008097 D7 00 00         [ 1]   94 	ld	(s_INITIALIZED - 1, x), a
      00809A 5A               [ 2]   95 	decw	x
      00809B 26 F7            [ 1]   96 	jrne	00003$
      00809D                         97 00004$:
                                     98 ; stm8_genXINIT() end
                                     99 	.area GSFINAL
      00809D CC 80 80         [ 2]  100 	jp	__sdcc_program_startup
                                    101 ;--------------------------------------------------------
                                    102 ; Home
                                    103 ;--------------------------------------------------------
                                    104 	.area HOME
                                    105 	.area HOME
      008080                        106 __sdcc_program_startup:
      008080 CC 81 35         [ 2]  107 	jp	_main
                                    108 ;	return from main will return to caller
                                    109 ;--------------------------------------------------------
                                    110 ; code
                                    111 ;--------------------------------------------------------
                                    112 	.area CODE
                                    113 ;	uart.c: 50: void system_clock_init()
                                    114 ;	-----------------------------------------
                                    115 ;	 function system_clock_init
                                    116 ;	-----------------------------------------
      0080A0                        117 _system_clock_init:
                                    118 ;	uart.c: 52: nointerrupts();
      0080A0 9B               [ 1]  119 	sim 
                                    120 ;	uart.c: 53: CLK_ICKR = 0;
      0080A1 35 00 50 C0      [ 1]  121 	mov	0x50c0+0, #0x00
                                    122 ;	uart.c: 54: CLK_ICKR |= CLK_ICKR_HSIEN;
      0080A5 72 10 50 C0      [ 1]  123 	bset	0x50c0, #0
                                    124 ;	uart.c: 55: CLK_ECKR = 0;
      0080A9 35 00 50 C1      [ 1]  125 	mov	0x50c1+0, #0x00
                                    126 ;	uart.c: 56: CLK_SWR = CLK_SWR_HSI;
      0080AD 35 E1 50 C4      [ 1]  127 	mov	0x50c4+0, #0xe1
                                    128 ;	uart.c: 57: while (0 == (CLK_ICKR & CLK_ICKR_HSIRDY));
      0080B1                        129 00101$:
      0080B1 AE 50 C0         [ 2]  130 	ldw	x, #0x50c0
      0080B4 F6               [ 1]  131 	ld	a, (x)
      0080B5 A5 02            [ 1]  132 	bcp	a, #0x02
      0080B7 27 F8            [ 1]  133 	jreq	00101$
                                    134 ;	uart.c: 58: CLK_CKDIVR = 0;
      0080B9 35 00 50 C6      [ 1]  135 	mov	0x50c6+0, #0x00
                                    136 ;	uart.c: 59: CLK_PCKENR1 = 0xFF;
      0080BD 35 FF 50 C7      [ 1]  137 	mov	0x50c7+0, #0xff
                                    138 ;	uart.c: 60: CLK_PCKENR2 = 0xFF;
      0080C1 35 FF 50 CA      [ 1]  139 	mov	0x50ca+0, #0xff
                                    140 ;	uart.c: 61: CLK_CCOR = 0;
      0080C5 35 00 50 C9      [ 1]  141 	mov	0x50c9+0, #0x00
                                    142 ;	uart.c: 62: CLK_HSITRIMR = 0;
      0080C9 35 00 50 CC      [ 1]  143 	mov	0x50cc+0, #0x00
                                    144 ;	uart.c: 63: CLK_SWIMCCR = 0;
      0080CD 35 00 50 CD      [ 1]  145 	mov	0x50cd+0, #0x00
                                    146 ;	uart.c: 65: CLK_SWCR = 0;
      0080D1 35 00 50 C5      [ 1]  147 	mov	0x50c5+0, #0x00
                                    148 ;	uart.c: 66: CLK_SWCR |= CLK_SWCR_SWEN;
      0080D5 AE 50 C5         [ 2]  149 	ldw	x, #0x50c5
      0080D8 F6               [ 1]  150 	ld	a, (x)
      0080D9 AA 02            [ 1]  151 	or	a, #0x02
      0080DB F7               [ 1]  152 	ld	(x), a
                                    153 ;	uart.c: 67: while (0 != (CLK_SWCR & CLK_SWCR_SWBSY));
      0080DC                        154 00104$:
      0080DC AE 50 C5         [ 2]  155 	ldw	x, #0x50c5
      0080DF F6               [ 1]  156 	ld	a, (x)
      0080E0 44               [ 1]  157 	srl	a
      0080E1 25 F9            [ 1]  158 	jrc	00104$
                                    159 ;	uart.c: 68: interrupts();
      0080E3 9A               [ 1]  160 	rim 
      0080E4 81               [ 4]  161 	ret
                                    162 ;	uart.c: 77: int uart_puts(const char *s) {
                                    163 ;	-----------------------------------------
                                    164 ;	 function uart_puts
                                    165 ;	-----------------------------------------
      0080E5                        166 _uart_puts:
      0080E5 52 03            [ 2]  167 	sub	sp, #3
                                    168 ;	uart.c: 79: for(i = 0; i < strlen(s); i++) {
      0080E7 0F 01            [ 1]  169 	clr	(0x01, sp)
      0080E9                        170 00106$:
      0080E9 1E 06            [ 2]  171 	ldw	x, (0x06, sp)
      0080EB 89               [ 2]  172 	pushw	x
      0080EC CD 81 EF         [ 4]  173 	call	_strlen
      0080EF 5B 02            [ 2]  174 	addw	sp, #2
      0080F1 1F 02            [ 2]  175 	ldw	(0x02, sp), x
      0080F3 5F               [ 1]  176 	clrw	x
      0080F4 7B 01            [ 1]  177 	ld	a, (0x01, sp)
      0080F6 97               [ 1]  178 	ld	xl, a
      0080F7 13 02            [ 2]  179 	cpw	x, (0x02, sp)
      0080F9 24 17            [ 1]  180 	jrnc	00104$
                                    181 ;	uart.c: 80: while(!(UART1_SR & UART_SR_TXE));
      0080FB                        182 00101$:
      0080FB AE 52 30         [ 2]  183 	ldw	x, #0x5230
      0080FE F6               [ 1]  184 	ld	a, (x)
      0080FF 4D               [ 1]  185 	tnz	a
      008100 2A F9            [ 1]  186 	jrpl	00101$
                                    187 ;	uart.c: 81: UART1_DR = s[i];
      008102 5F               [ 1]  188 	clrw	x
      008103 7B 01            [ 1]  189 	ld	a, (0x01, sp)
      008105 97               [ 1]  190 	ld	xl, a
      008106 72 FB 06         [ 2]  191 	addw	x, (0x06, sp)
      008109 F6               [ 1]  192 	ld	a, (x)
      00810A AE 52 31         [ 2]  193 	ldw	x, #0x5231
      00810D F7               [ 1]  194 	ld	(x), a
                                    195 ;	uart.c: 79: for(i = 0; i < strlen(s); i++) {
      00810E 0C 01            [ 1]  196 	inc	(0x01, sp)
      008110 20 D7            [ 2]  197 	jra	00106$
      008112                        198 00104$:
                                    199 ;	uart.c: 84: return(i);
      008112 5F               [ 1]  200 	clrw	x
      008113 7B 01            [ 1]  201 	ld	a, (0x01, sp)
      008115 97               [ 1]  202 	ld	xl, a
      008116 5B 03            [ 2]  203 	addw	sp, #3
      008118 81               [ 4]  204 	ret
                                    205 ;	uart.c: 90: void uart_init() {
                                    206 ;	-----------------------------------------
                                    207 ;	 function uart_init
                                    208 ;	-----------------------------------------
      008119                        209 _uart_init:
                                    210 ;	uart.c: 92: PD_DDR = 0xBF;
      008119 35 BF 50 11      [ 1]  211 	mov	0x5011+0, #0xbf
                                    212 ;	uart.c: 93: PD_CR1 = 0xFF;
      00811D 35 FF 50 12      [ 1]  213 	mov	0x5012+0, #0xff
                                    214 ;	uart.c: 96: UART1_CR2 = UART_CR2_TEN | UART_CR2_REN;
      008121 35 0C 52 35      [ 1]  215 	mov	0x5235+0, #0x0c
                                    216 ;	uart.c: 98: UART1_CR3 &= ~(UART_CR3_STOP1 | UART_CR3_STOP0);
      008125 AE 52 36         [ 2]  217 	ldw	x, #0x5236
      008128 F6               [ 1]  218 	ld	a, (x)
      008129 A4 CF            [ 1]  219 	and	a, #0xcf
      00812B F7               [ 1]  220 	ld	(x), a
                                    221 ;	uart.c: 100: UART1_BRR2 = 0x0B;
      00812C 35 0B 52 33      [ 1]  222 	mov	0x5233+0, #0x0b
                                    223 ;	uart.c: 101: UART1_BRR1 = 0x08;
      008130 35 08 52 32      [ 1]  224 	mov	0x5232+0, #0x08
      008134 81               [ 4]  225 	ret
                                    226 ;	uart.c: 104: int main() {
                                    227 ;	-----------------------------------------
                                    228 ;	 function main
                                    229 ;	-----------------------------------------
      008135                        230 _main:
      008135 52 08            [ 2]  231 	sub	sp, #8
                                    232 ;	uart.c: 25: PA_ODR = 0x00;
      008137 35 00 50 00      [ 1]  233 	mov	0x5000+0, #0x00
                                    234 ;	uart.c: 26: PA_DDR = 0xFF;
      00813B 35 FF 50 02      [ 1]  235 	mov	0x5002+0, #0xff
                                    236 ;	uart.c: 27: PA_CR1 = 0xFF;
      00813F 35 FF 50 03      [ 1]  237 	mov	0x5003+0, #0xff
                                    238 ;	uart.c: 28: PA_CR2 = 0x00;
      008143 35 00 50 04      [ 1]  239 	mov	0x5004+0, #0x00
                                    240 ;	uart.c: 30: PB_ODR = 0x00;
      008147 35 00 50 05      [ 1]  241 	mov	0x5005+0, #0x00
                                    242 ;	uart.c: 31: PB_DDR = 0xFF;
      00814B 35 FF 50 07      [ 1]  243 	mov	0x5007+0, #0xff
                                    244 ;	uart.c: 32: PB_CR1 = 0xFF;
      00814F 35 FF 50 08      [ 1]  245 	mov	0x5008+0, #0xff
                                    246 ;	uart.c: 33: PB_CR2 = 0x00;
      008153 35 00 50 09      [ 1]  247 	mov	0x5009+0, #0x00
                                    248 ;	uart.c: 35: PC_ODR = 0x00;
      008157 35 00 50 0A      [ 1]  249 	mov	0x500a+0, #0x00
                                    250 ;	uart.c: 36: PC_DDR = 0xFF;
      00815B 35 FF 50 0C      [ 1]  251 	mov	0x500c+0, #0xff
                                    252 ;	uart.c: 37: PC_CR1 = 0xFF;
      00815F 35 FF 50 0D      [ 1]  253 	mov	0x500d+0, #0xff
                                    254 ;	uart.c: 38: PC_CR2 = 0x00;
      008163 35 00 50 0E      [ 1]  255 	mov	0x500e+0, #0x00
                                    256 ;	uart.c: 40: PD_ODR = 0x00;
      008167 35 00 50 0F      [ 1]  257 	mov	0x500f+0, #0x00
                                    258 ;	uart.c: 41: PD_DDR = 0xFF;
      00816B 35 FF 50 11      [ 1]  259 	mov	0x5011+0, #0xff
                                    260 ;	uart.c: 42: PD_CR1 = 0xFF;
      00816F 35 FF 50 12      [ 1]  261 	mov	0x5012+0, #0xff
                                    262 ;	uart.c: 43: PD_CR2 = 0x00;
      008173 35 00 50 13      [ 1]  263 	mov	0x5013+0, #0x00
                                    264 ;	uart.c: 106: system_clock_init();
      008177 CD 80 A0         [ 4]  265 	call	_system_clock_init
                                    266 ;	uart.c: 107: uart_init();
      00817A CD 81 19         [ 4]  267 	call	_uart_init
                                    268 ;	uart.c: 109: while(1) {
      00817D                        269 00103$:
                                    270 ;	uart.c: 110: uart_puts("STM8S at 115200 baud. Welcome and keep up the good work!\r\n");
      00817D AE 81 B4         [ 2]  271 	ldw	x, #___str_0+0
      008180 89               [ 2]  272 	pushw	x
      008181 CD 80 E5         [ 4]  273 	call	_uart_puts
      008184 5B 02            [ 2]  274 	addw	sp, #2
                                    275 ;	uart.c: 111: __delay();
      008186 AE 09 00         [ 2]  276 	ldw	x, #0x0900
      008189 1F 03            [ 2]  277 	ldw	(0x03, sp), x
      00818B A6 3D            [ 1]  278 	ld	a, #0x3d
      00818D 0F 01            [ 1]  279 	clr	(0x01, sp)
      00818F                        280 00108$:
      00818F 9D               [ 1]  281 	nop 
      008190 1E 03            [ 2]  282 	ldw	x, (0x03, sp)
      008192 1D 00 01         [ 2]  283 	subw	x, #0x0001
      008195 1F 07            [ 2]  284 	ldw	(0x07, sp), x
      008197 A2 00            [ 1]  285 	sbc	a, #0x00
      008199 97               [ 1]  286 	ld	xl, a
      00819A 7B 01            [ 1]  287 	ld	a, (0x01, sp)
      00819C A2 00            [ 1]  288 	sbc	a, #0x00
      00819E 95               [ 1]  289 	ld	xh, a
      00819F 02               [ 1]  290 	rlwa	x
      0081A0 6B 01            [ 1]  291 	ld	(0x01, sp), a
      0081A2 01               [ 1]  292 	rrwa	x
      0081A3 16 07            [ 2]  293 	ldw	y, (0x07, sp)
      0081A5 17 03            [ 2]  294 	ldw	(0x03, sp), y
      0081A7 9F               [ 1]  295 	ld	a, xl
      0081A8 16 07            [ 2]  296 	ldw	y, (0x07, sp)
      0081AA 26 E3            [ 1]  297 	jrne	00108$
      0081AC 5D               [ 2]  298 	tnzw	x
      0081AD 27 CE            [ 1]  299 	jreq	00103$
      0081AF 20 DE            [ 2]  300 	jra	00108$
      0081B1 5B 08            [ 2]  301 	addw	sp, #8
      0081B3 81               [ 4]  302 	ret
                                    303 	.area CODE
      0081B4                        304 ___str_0:
      0081B4 53 54 4D 38 53 20 61   305 	.ascii "STM8S at 115200 baud. Welcome and keep up the good work!"
             74 20 31 31 35 32 30
             30 20 62 61 75 64 2E
             20 57 65 6C 63 6F 6D
             65 20 61 6E 64 20 6B
             65 65 70 20 75 70 20
             74 68 65 20 67 6F 6F
             64 20 77 6F 72 6B 21
      0081EC 0D                     306 	.db 0x0D
      0081ED 0A                     307 	.db 0x0A
      0081EE 00                     308 	.db 0x00
                                    309 	.area INITIALIZER
                                    310 	.area CABS (ABS)
