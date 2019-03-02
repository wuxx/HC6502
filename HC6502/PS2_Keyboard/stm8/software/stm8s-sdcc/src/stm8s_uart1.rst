                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 28 2016) (Linux)
                                      4 ; This file was generated Wed Jan  2 15:12:28 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module stm8s_uart1
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _assert_failed
                                     13 	.globl _CLK_GetClockFreq
                                     14 	.globl _UART1_DeInit
                                     15 	.globl _UART1_Init
                                     16 	.globl _UART1_Cmd
                                     17 	.globl _UART1_ITConfig
                                     18 	.globl _UART1_HalfDuplexCmd
                                     19 	.globl _UART1_IrDAConfig
                                     20 	.globl _UART1_IrDACmd
                                     21 	.globl _UART1_LINBreakDetectionConfig
                                     22 	.globl _UART1_LINCmd
                                     23 	.globl _UART1_SmartCardCmd
                                     24 	.globl _UART1_SmartCardNACKCmd
                                     25 	.globl _UART1_WakeUpConfig
                                     26 	.globl _UART1_ReceiverWakeUpCmd
                                     27 	.globl _UART1_ReceiveData8
                                     28 	.globl _UART1_ReceiveData9
                                     29 	.globl _UART1_SendData8
                                     30 	.globl _UART1_SendData9
                                     31 	.globl _UART1_SendBreak
                                     32 	.globl _UART1_SetAddress
                                     33 	.globl _UART1_SetGuardTime
                                     34 	.globl _UART1_SetPrescaler
                                     35 	.globl _UART1_GetFlagStatus
                                     36 	.globl _UART1_ClearFlag
                                     37 	.globl _UART1_GetITStatus
                                     38 	.globl _UART1_ClearITPendingBit
                                     39 ;--------------------------------------------------------
                                     40 ; ram data
                                     41 ;--------------------------------------------------------
                                     42 	.area DATA
                                     43 ;--------------------------------------------------------
                                     44 ; ram data
                                     45 ;--------------------------------------------------------
                                     46 	.area INITIALIZED
                                     47 ;--------------------------------------------------------
                                     48 ; absolute external ram data
                                     49 ;--------------------------------------------------------
                                     50 	.area DABS (ABS)
                                     51 ;--------------------------------------------------------
                                     52 ; global & static initialisations
                                     53 ;--------------------------------------------------------
                                     54 	.area HOME
                                     55 	.area GSINIT
                                     56 	.area GSFINAL
                                     57 	.area GSINIT
                                     58 ;--------------------------------------------------------
                                     59 ; Home
                                     60 ;--------------------------------------------------------
                                     61 	.area HOME
                                     62 	.area HOME
                                     63 ;--------------------------------------------------------
                                     64 ; code
                                     65 ;--------------------------------------------------------
                                     66 	.area CODE
                                     67 ;	../src/stm8s_uart1.c: 53: void UART1_DeInit(void)
                                     68 ;	-----------------------------------------
                                     69 ;	 function UART1_DeInit
                                     70 ;	-----------------------------------------
      0086C8                         71 _UART1_DeInit:
                                     72 ;	../src/stm8s_uart1.c: 57: (void)UART1->SR;
      0086C8 AE 52 30         [ 2]   73 	ldw	x, #0x5230
      0086CB F6               [ 1]   74 	ld	a, (x)
                                     75 ;	../src/stm8s_uart1.c: 58: (void)UART1->DR;
      0086CC AE 52 31         [ 2]   76 	ldw	x, #0x5231
      0086CF F6               [ 1]   77 	ld	a, (x)
                                     78 ;	../src/stm8s_uart1.c: 60: UART1->BRR2 = UART1_BRR2_RESET_VALUE;  /* Set UART1_BRR2 to reset value 0x00 */
      0086D0 35 00 52 33      [ 1]   79 	mov	0x5233+0, #0x00
                                     80 ;	../src/stm8s_uart1.c: 61: UART1->BRR1 = UART1_BRR1_RESET_VALUE;  /* Set UART1_BRR1 to reset value 0x00 */
      0086D4 35 00 52 32      [ 1]   81 	mov	0x5232+0, #0x00
                                     82 ;	../src/stm8s_uart1.c: 63: UART1->CR1 = UART1_CR1_RESET_VALUE;  /* Set UART1_CR1 to reset value 0x00 */
      0086D8 35 00 52 34      [ 1]   83 	mov	0x5234+0, #0x00
                                     84 ;	../src/stm8s_uart1.c: 64: UART1->CR2 = UART1_CR2_RESET_VALUE;  /* Set UART1_CR2 to reset value 0x00 */
      0086DC 35 00 52 35      [ 1]   85 	mov	0x5235+0, #0x00
                                     86 ;	../src/stm8s_uart1.c: 65: UART1->CR3 = UART1_CR3_RESET_VALUE;  /* Set UART1_CR3 to reset value 0x00 */
      0086E0 35 00 52 36      [ 1]   87 	mov	0x5236+0, #0x00
                                     88 ;	../src/stm8s_uart1.c: 66: UART1->CR4 = UART1_CR4_RESET_VALUE;  /* Set UART1_CR4 to reset value 0x00 */
      0086E4 35 00 52 37      [ 1]   89 	mov	0x5237+0, #0x00
                                     90 ;	../src/stm8s_uart1.c: 67: UART1->CR5 = UART1_CR5_RESET_VALUE;  /* Set UART1_CR5 to reset value 0x00 */
      0086E8 35 00 52 38      [ 1]   91 	mov	0x5238+0, #0x00
                                     92 ;	../src/stm8s_uart1.c: 69: UART1->GTR = UART1_GTR_RESET_VALUE;
      0086EC 35 00 52 39      [ 1]   93 	mov	0x5239+0, #0x00
                                     94 ;	../src/stm8s_uart1.c: 70: UART1->PSCR = UART1_PSCR_RESET_VALUE;
      0086F0 35 00 52 3A      [ 1]   95 	mov	0x523a+0, #0x00
      0086F4 81               [ 4]   96 	ret
                                     97 ;	../src/stm8s_uart1.c: 90: void UART1_Init(uint32_t BaudRate, UART1_WordLength_TypeDef WordLength, 
                                     98 ;	-----------------------------------------
                                     99 ;	 function UART1_Init
                                    100 ;	-----------------------------------------
      0086F5                        101 _UART1_Init:
      0086F5 52 21            [ 2]  102 	sub	sp, #33
                                    103 ;	../src/stm8s_uart1.c: 97: assert_param(IS_UART1_BAUDRATE_OK(BaudRate));
      0086F7 AE 89 68         [ 2]  104 	ldw	x, #0x8968
      0086FA 13 26            [ 2]  105 	cpw	x, (0x26, sp)
      0086FC A6 09            [ 1]  106 	ld	a, #0x09
      0086FE 12 25            [ 1]  107 	sbc	a, (0x25, sp)
      008700 4F               [ 1]  108 	clr	a
      008701 12 24            [ 1]  109 	sbc	a, (0x24, sp)
      008703 24 11            [ 1]  110 	jrnc	00113$
      008705 90 AE 8A 5B      [ 2]  111 	ldw	y, #___str_0+0
      008709 4B 61            [ 1]  112 	push	#0x61
      00870B 5F               [ 1]  113 	clrw	x
      00870C 89               [ 2]  114 	pushw	x
      00870D 4B 00            [ 1]  115 	push	#0x00
      00870F 90 89            [ 2]  116 	pushw	y
      008711 CD 80 A8         [ 4]  117 	call	_assert_failed
      008714 5B 06            [ 2]  118 	addw	sp, #6
      008716                        119 00113$:
                                    120 ;	../src/stm8s_uart1.c: 98: assert_param(IS_UART1_WORDLENGTH_OK(WordLength));
      008716 0D 28            [ 1]  121 	tnz	(0x28, sp)
      008718 27 17            [ 1]  122 	jreq	00115$
      00871A 7B 28            [ 1]  123 	ld	a, (0x28, sp)
      00871C A1 10            [ 1]  124 	cp	a, #0x10
      00871E 27 11            [ 1]  125 	jreq	00115$
      008720 90 AE 8A 5B      [ 2]  126 	ldw	y, #___str_0+0
      008724 4B 62            [ 1]  127 	push	#0x62
      008726 5F               [ 1]  128 	clrw	x
      008727 89               [ 2]  129 	pushw	x
      008728 4B 00            [ 1]  130 	push	#0x00
      00872A 90 89            [ 2]  131 	pushw	y
      00872C CD 80 A8         [ 4]  132 	call	_assert_failed
      00872F 5B 06            [ 2]  133 	addw	sp, #6
      008731                        134 00115$:
                                    135 ;	../src/stm8s_uart1.c: 99: assert_param(IS_UART1_STOPBITS_OK(StopBits));
      008731 0D 29            [ 1]  136 	tnz	(0x29, sp)
      008733 27 23            [ 1]  137 	jreq	00120$
      008735 7B 29            [ 1]  138 	ld	a, (0x29, sp)
      008737 A1 10            [ 1]  139 	cp	a, #0x10
      008739 27 1D            [ 1]  140 	jreq	00120$
      00873B 7B 29            [ 1]  141 	ld	a, (0x29, sp)
      00873D A1 20            [ 1]  142 	cp	a, #0x20
      00873F 27 17            [ 1]  143 	jreq	00120$
      008741 7B 29            [ 1]  144 	ld	a, (0x29, sp)
      008743 A1 30            [ 1]  145 	cp	a, #0x30
      008745 27 11            [ 1]  146 	jreq	00120$
      008747 90 AE 8A 5B      [ 2]  147 	ldw	y, #___str_0+0
      00874B 4B 63            [ 1]  148 	push	#0x63
      00874D 5F               [ 1]  149 	clrw	x
      00874E 89               [ 2]  150 	pushw	x
      00874F 4B 00            [ 1]  151 	push	#0x00
      008751 90 89            [ 2]  152 	pushw	y
      008753 CD 80 A8         [ 4]  153 	call	_assert_failed
      008756 5B 06            [ 2]  154 	addw	sp, #6
      008758                        155 00120$:
                                    156 ;	../src/stm8s_uart1.c: 100: assert_param(IS_UART1_PARITY_OK(Parity));
      008758 0D 2A            [ 1]  157 	tnz	(0x2a, sp)
      00875A 27 1D            [ 1]  158 	jreq	00131$
      00875C 7B 2A            [ 1]  159 	ld	a, (0x2a, sp)
      00875E A1 04            [ 1]  160 	cp	a, #0x04
      008760 27 17            [ 1]  161 	jreq	00131$
      008762 7B 2A            [ 1]  162 	ld	a, (0x2a, sp)
      008764 A1 06            [ 1]  163 	cp	a, #0x06
      008766 27 11            [ 1]  164 	jreq	00131$
      008768 90 AE 8A 5B      [ 2]  165 	ldw	y, #___str_0+0
      00876C 4B 64            [ 1]  166 	push	#0x64
      00876E 5F               [ 1]  167 	clrw	x
      00876F 89               [ 2]  168 	pushw	x
      008770 4B 00            [ 1]  169 	push	#0x00
      008772 90 89            [ 2]  170 	pushw	y
      008774 CD 80 A8         [ 4]  171 	call	_assert_failed
      008777 5B 06            [ 2]  172 	addw	sp, #6
      008779                        173 00131$:
                                    174 ;	../src/stm8s_uart1.c: 101: assert_param(IS_UART1_MODE_OK((uint8_t)Mode));
      008779 7B 2C            [ 1]  175 	ld	a, (0x2c, sp)
      00877B A1 08            [ 1]  176 	cp	a, #0x08
      00877D 27 45            [ 1]  177 	jreq	00139$
      00877F 7B 2C            [ 1]  178 	ld	a, (0x2c, sp)
      008781 A1 40            [ 1]  179 	cp	a, #0x40
      008783 27 3F            [ 1]  180 	jreq	00139$
      008785 7B 2C            [ 1]  181 	ld	a, (0x2c, sp)
      008787 A1 04            [ 1]  182 	cp	a, #0x04
      008789 27 39            [ 1]  183 	jreq	00139$
      00878B 7B 2C            [ 1]  184 	ld	a, (0x2c, sp)
      00878D A1 80            [ 1]  185 	cp	a, #0x80
      00878F 27 33            [ 1]  186 	jreq	00139$
      008791 7B 2C            [ 1]  187 	ld	a, (0x2c, sp)
      008793 A1 0C            [ 1]  188 	cp	a, #0x0c
      008795 26 03            [ 1]  189 	jrne	00314$
      008797 A6 01            [ 1]  190 	ld	a, #0x01
      008799 21                     191 	.byte 0x21
      00879A                        192 00314$:
      00879A 4F               [ 1]  193 	clr	a
      00879B                        194 00315$:
      00879B 4D               [ 1]  195 	tnz	a
      00879C 26 26            [ 1]  196 	jrne	00139$
      00879E 4D               [ 1]  197 	tnz	a
      00879F 26 23            [ 1]  198 	jrne	00139$
      0087A1 7B 2C            [ 1]  199 	ld	a, (0x2c, sp)
      0087A3 A1 44            [ 1]  200 	cp	a, #0x44
      0087A5 27 1D            [ 1]  201 	jreq	00139$
      0087A7 7B 2C            [ 1]  202 	ld	a, (0x2c, sp)
      0087A9 A1 C0            [ 1]  203 	cp	a, #0xc0
      0087AB 27 17            [ 1]  204 	jreq	00139$
      0087AD 7B 2C            [ 1]  205 	ld	a, (0x2c, sp)
      0087AF A1 88            [ 1]  206 	cp	a, #0x88
      0087B1 27 11            [ 1]  207 	jreq	00139$
      0087B3 90 AE 8A 5B      [ 2]  208 	ldw	y, #___str_0+0
      0087B7 4B 65            [ 1]  209 	push	#0x65
      0087B9 5F               [ 1]  210 	clrw	x
      0087BA 89               [ 2]  211 	pushw	x
      0087BB 4B 00            [ 1]  212 	push	#0x00
      0087BD 90 89            [ 2]  213 	pushw	y
      0087BF CD 80 A8         [ 4]  214 	call	_assert_failed
      0087C2 5B 06            [ 2]  215 	addw	sp, #6
      0087C4                        216 00139$:
                                    217 ;	../src/stm8s_uart1.c: 102: assert_param(IS_UART1_SYNCMODE_OK((uint8_t)SyncMode));
      0087C4 7B 2B            [ 1]  218 	ld	a, (0x2b, sp)
      0087C6 A4 88            [ 1]  219 	and	a, #0x88
      0087C8 A1 88            [ 1]  220 	cp	a, #0x88
      0087CA 27 18            [ 1]  221 	jreq	00167$
      0087CC 7B 2B            [ 1]  222 	ld	a, (0x2b, sp)
      0087CE A4 44            [ 1]  223 	and	a, #0x44
      0087D0 A1 44            [ 1]  224 	cp	a, #0x44
      0087D2 27 10            [ 1]  225 	jreq	00167$
      0087D4 7B 2B            [ 1]  226 	ld	a, (0x2b, sp)
      0087D6 A4 22            [ 1]  227 	and	a, #0x22
      0087D8 A1 22            [ 1]  228 	cp	a, #0x22
      0087DA 27 08            [ 1]  229 	jreq	00167$
      0087DC 7B 2B            [ 1]  230 	ld	a, (0x2b, sp)
      0087DE A4 11            [ 1]  231 	and	a, #0x11
      0087E0 A1 11            [ 1]  232 	cp	a, #0x11
      0087E2 26 11            [ 1]  233 	jrne	00165$
      0087E4                        234 00167$:
      0087E4 90 AE 8A 5B      [ 2]  235 	ldw	y, #___str_0+0
      0087E8 4B 66            [ 1]  236 	push	#0x66
      0087EA 5F               [ 1]  237 	clrw	x
      0087EB 89               [ 2]  238 	pushw	x
      0087EC 4B 00            [ 1]  239 	push	#0x00
      0087EE 90 89            [ 2]  240 	pushw	y
      0087F0 CD 80 A8         [ 4]  241 	call	_assert_failed
      0087F3 5B 06            [ 2]  242 	addw	sp, #6
      0087F5                        243 00165$:
                                    244 ;	../src/stm8s_uart1.c: 105: UART1->CR1 &= (uint8_t)(~UART1_CR1_M);  
      0087F5 AE 52 34         [ 2]  245 	ldw	x, #0x5234
      0087F8 F6               [ 1]  246 	ld	a, (x)
      0087F9 A4 EF            [ 1]  247 	and	a, #0xef
      0087FB F7               [ 1]  248 	ld	(x), a
                                    249 ;	../src/stm8s_uart1.c: 108: UART1->CR1 |= (uint8_t)WordLength;
      0087FC AE 52 34         [ 2]  250 	ldw	x, #0x5234
      0087FF F6               [ 1]  251 	ld	a, (x)
      008800 1A 28            [ 1]  252 	or	a, (0x28, sp)
      008802 AE 52 34         [ 2]  253 	ldw	x, #0x5234
      008805 F7               [ 1]  254 	ld	(x), a
                                    255 ;	../src/stm8s_uart1.c: 111: UART1->CR3 &= (uint8_t)(~UART1_CR3_STOP);  
      008806 AE 52 36         [ 2]  256 	ldw	x, #0x5236
      008809 F6               [ 1]  257 	ld	a, (x)
      00880A A4 CF            [ 1]  258 	and	a, #0xcf
      00880C F7               [ 1]  259 	ld	(x), a
                                    260 ;	../src/stm8s_uart1.c: 113: UART1->CR3 |= (uint8_t)StopBits;  
      00880D AE 52 36         [ 2]  261 	ldw	x, #0x5236
      008810 F6               [ 1]  262 	ld	a, (x)
      008811 1A 29            [ 1]  263 	or	a, (0x29, sp)
      008813 AE 52 36         [ 2]  264 	ldw	x, #0x5236
      008816 F7               [ 1]  265 	ld	(x), a
                                    266 ;	../src/stm8s_uart1.c: 116: UART1->CR1 &= (uint8_t)(~(UART1_CR1_PCEN | UART1_CR1_PS  ));  
      008817 AE 52 34         [ 2]  267 	ldw	x, #0x5234
      00881A F6               [ 1]  268 	ld	a, (x)
      00881B A4 F9            [ 1]  269 	and	a, #0xf9
      00881D F7               [ 1]  270 	ld	(x), a
                                    271 ;	../src/stm8s_uart1.c: 118: UART1->CR1 |= (uint8_t)Parity;  
      00881E AE 52 34         [ 2]  272 	ldw	x, #0x5234
      008821 F6               [ 1]  273 	ld	a, (x)
      008822 1A 2A            [ 1]  274 	or	a, (0x2a, sp)
      008824 AE 52 34         [ 2]  275 	ldw	x, #0x5234
      008827 F7               [ 1]  276 	ld	(x), a
                                    277 ;	../src/stm8s_uart1.c: 121: UART1->BRR1 &= (uint8_t)(~UART1_BRR1_DIVM);  
      008828 AE 52 32         [ 2]  278 	ldw	x, #0x5232
      00882B F6               [ 1]  279 	ld	a, (x)
      00882C 35 00 52 32      [ 1]  280 	mov	0x5232+0, #0x00
                                    281 ;	../src/stm8s_uart1.c: 123: UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVM);  
      008830 AE 52 33         [ 2]  282 	ldw	x, #0x5233
      008833 F6               [ 1]  283 	ld	a, (x)
      008834 A4 0F            [ 1]  284 	and	a, #0x0f
      008836 F7               [ 1]  285 	ld	(x), a
                                    286 ;	../src/stm8s_uart1.c: 125: UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVF);  
      008837 AE 52 33         [ 2]  287 	ldw	x, #0x5233
      00883A F6               [ 1]  288 	ld	a, (x)
      00883B A4 F0            [ 1]  289 	and	a, #0xf0
      00883D F7               [ 1]  290 	ld	(x), a
                                    291 ;	../src/stm8s_uart1.c: 128: BaudRate_Mantissa    = ((uint32_t)CLK_GetClockFreq() / (BaudRate << 4));
      00883E CD 91 9A         [ 4]  292 	call	_CLK_GetClockFreq
      008841 1F 14            [ 2]  293 	ldw	(0x14, sp), x
      008843 1E 24            [ 2]  294 	ldw	x, (0x24, sp)
      008845 1F 0D            [ 2]  295 	ldw	(0x0d, sp), x
      008847 1E 26            [ 2]  296 	ldw	x, (0x26, sp)
      008849 A6 04            [ 1]  297 	ld	a, #0x04
      00884B                        298 00339$:
      00884B 58               [ 2]  299 	sllw	x
      00884C 09 0E            [ 1]  300 	rlc	(0x0e, sp)
      00884E 09 0D            [ 1]  301 	rlc	(0x0d, sp)
      008850 4A               [ 1]  302 	dec	a
      008851 26 F8            [ 1]  303 	jrne	00339$
      008853 1F 0F            [ 2]  304 	ldw	(0x0f, sp), x
      008855 1E 0F            [ 2]  305 	ldw	x, (0x0f, sp)
      008857 89               [ 2]  306 	pushw	x
      008858 1E 0F            [ 2]  307 	ldw	x, (0x0f, sp)
      00885A 89               [ 2]  308 	pushw	x
      00885B 1E 18            [ 2]  309 	ldw	x, (0x18, sp)
      00885D 89               [ 2]  310 	pushw	x
      00885E 90 89            [ 2]  311 	pushw	y
      008860 CD 95 4B         [ 4]  312 	call	__divulong
      008863 5B 08            [ 2]  313 	addw	sp, #8
      008865 1F 07            [ 2]  314 	ldw	(0x07, sp), x
      008867 17 05            [ 2]  315 	ldw	(0x05, sp), y
                                    316 ;	../src/stm8s_uart1.c: 129: BaudRate_Mantissa100 = (((uint32_t)CLK_GetClockFreq() * 100) / (BaudRate << 4));
      008869 CD 91 9A         [ 4]  317 	call	_CLK_GetClockFreq
      00886C 89               [ 2]  318 	pushw	x
      00886D 90 89            [ 2]  319 	pushw	y
      00886F 4B 64            [ 1]  320 	push	#0x64
      008871 5F               [ 1]  321 	clrw	x
      008872 89               [ 2]  322 	pushw	x
      008873 4B 00            [ 1]  323 	push	#0x00
      008875 CD 95 D5         [ 4]  324 	call	__mullong
      008878 5B 08            [ 2]  325 	addw	sp, #8
      00887A 1F 0B            [ 2]  326 	ldw	(0x0b, sp), x
      00887C 1E 0F            [ 2]  327 	ldw	x, (0x0f, sp)
      00887E 89               [ 2]  328 	pushw	x
      00887F 1E 0F            [ 2]  329 	ldw	x, (0x0f, sp)
      008881 89               [ 2]  330 	pushw	x
      008882 1E 0F            [ 2]  331 	ldw	x, (0x0f, sp)
      008884 89               [ 2]  332 	pushw	x
      008885 90 89            [ 2]  333 	pushw	y
      008887 CD 95 4B         [ 4]  334 	call	__divulong
      00888A 5B 08            [ 2]  335 	addw	sp, #8
      00888C 51               [ 1]  336 	exgw	x, y
      00888D 17 03            [ 2]  337 	ldw	(0x03, sp), y
      00888F 02               [ 1]  338 	rlwa	x
      008890 6B 01            [ 1]  339 	ld	(0x01, sp), a
      008892 01               [ 1]  340 	rrwa	x
      008893 9F               [ 1]  341 	ld	a, xl
                                    342 ;	../src/stm8s_uart1.c: 131: UART1->BRR2 |= (uint8_t)((uint8_t)(((BaudRate_Mantissa100 - (BaudRate_Mantissa * 100)) << 4) / 100) & (uint8_t)0x0F); 
      008894 AE 52 33         [ 2]  343 	ldw	x, #0x5233
      008897 88               [ 1]  344 	push	a
      008898 F6               [ 1]  345 	ld	a, (x)
      008899 6B 12            [ 1]  346 	ld	(0x12, sp), a
      00889B 84               [ 1]  347 	pop	a
      00889C 88               [ 1]  348 	push	a
      00889D 1E 08            [ 2]  349 	ldw	x, (0x08, sp)
      00889F 89               [ 2]  350 	pushw	x
      0088A0 1E 08            [ 2]  351 	ldw	x, (0x08, sp)
      0088A2 89               [ 2]  352 	pushw	x
      0088A3 4B 64            [ 1]  353 	push	#0x64
      0088A5 5F               [ 1]  354 	clrw	x
      0088A6 89               [ 2]  355 	pushw	x
      0088A7 4B 00            [ 1]  356 	push	#0x00
      0088A9 CD 95 D5         [ 4]  357 	call	__mullong
      0088AC 5B 08            [ 2]  358 	addw	sp, #8
      0088AE 1F 19            [ 2]  359 	ldw	(0x19, sp), x
      0088B0 17 17            [ 2]  360 	ldw	(0x17, sp), y
      0088B2 84               [ 1]  361 	pop	a
      0088B3 16 03            [ 2]  362 	ldw	y, (0x03, sp)
      0088B5 72 F2 18         [ 2]  363 	subw	y, (0x18, sp)
      0088B8 12 17            [ 1]  364 	sbc	a, (0x17, sp)
      0088BA 97               [ 1]  365 	ld	xl, a
      0088BB 7B 01            [ 1]  366 	ld	a, (0x01, sp)
      0088BD 12 16            [ 1]  367 	sbc	a, (0x16, sp)
      0088BF 95               [ 1]  368 	ld	xh, a
      0088C0 A6 04            [ 1]  369 	ld	a, #0x04
      0088C2                        370 00341$:
      0088C2 90 58            [ 2]  371 	sllw	y
      0088C4 59               [ 2]  372 	rlcw	x
      0088C5 4A               [ 1]  373 	dec	a
      0088C6 26 FA            [ 1]  374 	jrne	00341$
      0088C8 4B 64            [ 1]  375 	push	#0x64
      0088CA 4B 00            [ 1]  376 	push	#0x00
      0088CC 4B 00            [ 1]  377 	push	#0x00
      0088CE 4B 00            [ 1]  378 	push	#0x00
      0088D0 90 89            [ 2]  379 	pushw	y
      0088D2 89               [ 2]  380 	pushw	x
      0088D3 CD 95 4B         [ 4]  381 	call	__divulong
      0088D6 5B 08            [ 2]  382 	addw	sp, #8
      0088D8 9F               [ 1]  383 	ld	a, xl
      0088D9 A4 0F            [ 1]  384 	and	a, #0x0f
      0088DB 1A 11            [ 1]  385 	or	a, (0x11, sp)
      0088DD AE 52 33         [ 2]  386 	ldw	x, #0x5233
      0088E0 F7               [ 1]  387 	ld	(x), a
                                    388 ;	../src/stm8s_uart1.c: 133: UART1->BRR2 |= (uint8_t)((BaudRate_Mantissa >> 4) & (uint8_t)0xF0); 
      0088E1 AE 52 33         [ 2]  389 	ldw	x, #0x5233
      0088E4 F6               [ 1]  390 	ld	a, (x)
      0088E5 6B 21            [ 1]  391 	ld	(0x21, sp), a
      0088E7 1E 07            [ 2]  392 	ldw	x, (0x07, sp)
      0088E9 16 05            [ 2]  393 	ldw	y, (0x05, sp)
      0088EB 90 54            [ 2]  394 	srlw	y
      0088ED 56               [ 2]  395 	rrcw	x
      0088EE 90 54            [ 2]  396 	srlw	y
      0088F0 56               [ 2]  397 	rrcw	x
      0088F1 90 54            [ 2]  398 	srlw	y
      0088F3 56               [ 2]  399 	rrcw	x
      0088F4 90 54            [ 2]  400 	srlw	y
      0088F6 56               [ 2]  401 	rrcw	x
      0088F7 9F               [ 1]  402 	ld	a, xl
      0088F8 A4 F0            [ 1]  403 	and	a, #0xf0
      0088FA 88               [ 1]  404 	push	a
      0088FB 0F 20            [ 1]  405 	clr	(0x20, sp)
      0088FD 5F               [ 1]  406 	clrw	x
      0088FE 84               [ 1]  407 	pop	a
      0088FF 1A 21            [ 1]  408 	or	a, (0x21, sp)
      008901 AE 52 33         [ 2]  409 	ldw	x, #0x5233
      008904 F7               [ 1]  410 	ld	(x), a
                                    411 ;	../src/stm8s_uart1.c: 135: UART1->BRR1 |= (uint8_t)BaudRate_Mantissa;           
      008905 AE 52 32         [ 2]  412 	ldw	x, #0x5232
      008908 F6               [ 1]  413 	ld	a, (x)
      008909 6B 1C            [ 1]  414 	ld	(0x1c, sp), a
      00890B 7B 08            [ 1]  415 	ld	a, (0x08, sp)
      00890D 1A 1C            [ 1]  416 	or	a, (0x1c, sp)
      00890F AE 52 32         [ 2]  417 	ldw	x, #0x5232
      008912 F7               [ 1]  418 	ld	(x), a
                                    419 ;	../src/stm8s_uart1.c: 138: UART1->CR2 &= (uint8_t)~(UART1_CR2_TEN | UART1_CR2_REN); 
      008913 AE 52 35         [ 2]  420 	ldw	x, #0x5235
      008916 F6               [ 1]  421 	ld	a, (x)
      008917 A4 F3            [ 1]  422 	and	a, #0xf3
      008919 F7               [ 1]  423 	ld	(x), a
                                    424 ;	../src/stm8s_uart1.c: 140: UART1->CR3 &= (uint8_t)~(UART1_CR3_CPOL | UART1_CR3_CPHA | UART1_CR3_LBCL); 
      00891A AE 52 36         [ 2]  425 	ldw	x, #0x5236
      00891D F6               [ 1]  426 	ld	a, (x)
      00891E A4 F8            [ 1]  427 	and	a, #0xf8
      008920 F7               [ 1]  428 	ld	(x), a
                                    429 ;	../src/stm8s_uart1.c: 142: UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & (uint8_t)(UART1_CR3_CPOL | 
      008921 AE 52 36         [ 2]  430 	ldw	x, #0x5236
      008924 F6               [ 1]  431 	ld	a, (x)
      008925 6B 1B            [ 1]  432 	ld	(0x1b, sp), a
      008927 7B 2B            [ 1]  433 	ld	a, (0x2b, sp)
      008929 A4 07            [ 1]  434 	and	a, #0x07
      00892B 1A 1B            [ 1]  435 	or	a, (0x1b, sp)
      00892D AE 52 36         [ 2]  436 	ldw	x, #0x5236
      008930 F7               [ 1]  437 	ld	(x), a
                                    438 ;	../src/stm8s_uart1.c: 145: if ((uint8_t)(Mode & UART1_MODE_TX_ENABLE))
      008931 7B 2C            [ 1]  439 	ld	a, (0x2c, sp)
      008933 A5 04            [ 1]  440 	bcp	a, #0x04
      008935 27 09            [ 1]  441 	jreq	00102$
                                    442 ;	../src/stm8s_uart1.c: 148: UART1->CR2 |= (uint8_t)UART1_CR2_TEN;  
      008937 AE 52 35         [ 2]  443 	ldw	x, #0x5235
      00893A F6               [ 1]  444 	ld	a, (x)
      00893B AA 08            [ 1]  445 	or	a, #0x08
      00893D F7               [ 1]  446 	ld	(x), a
      00893E 20 07            [ 2]  447 	jra	00103$
      008940                        448 00102$:
                                    449 ;	../src/stm8s_uart1.c: 153: UART1->CR2 &= (uint8_t)(~UART1_CR2_TEN);  
      008940 AE 52 35         [ 2]  450 	ldw	x, #0x5235
      008943 F6               [ 1]  451 	ld	a, (x)
      008944 A4 F7            [ 1]  452 	and	a, #0xf7
      008946 F7               [ 1]  453 	ld	(x), a
      008947                        454 00103$:
                                    455 ;	../src/stm8s_uart1.c: 155: if ((uint8_t)(Mode & UART1_MODE_RX_ENABLE))
      008947 7B 2C            [ 1]  456 	ld	a, (0x2c, sp)
      008949 A5 08            [ 1]  457 	bcp	a, #0x08
      00894B 27 09            [ 1]  458 	jreq	00105$
                                    459 ;	../src/stm8s_uart1.c: 158: UART1->CR2 |= (uint8_t)UART1_CR2_REN;  
      00894D AE 52 35         [ 2]  460 	ldw	x, #0x5235
      008950 F6               [ 1]  461 	ld	a, (x)
      008951 AA 04            [ 1]  462 	or	a, #0x04
      008953 F7               [ 1]  463 	ld	(x), a
      008954 20 07            [ 2]  464 	jra	00106$
      008956                        465 00105$:
                                    466 ;	../src/stm8s_uart1.c: 163: UART1->CR2 &= (uint8_t)(~UART1_CR2_REN);  
      008956 AE 52 35         [ 2]  467 	ldw	x, #0x5235
      008959 F6               [ 1]  468 	ld	a, (x)
      00895A A4 FB            [ 1]  469 	and	a, #0xfb
      00895C F7               [ 1]  470 	ld	(x), a
      00895D                        471 00106$:
                                    472 ;	../src/stm8s_uart1.c: 167: if ((uint8_t)(SyncMode & UART1_SYNCMODE_CLOCK_DISABLE))
      00895D 0D 2B            [ 1]  473 	tnz	(0x2b, sp)
      00895F 2A 09            [ 1]  474 	jrpl	00108$
                                    475 ;	../src/stm8s_uart1.c: 170: UART1->CR3 &= (uint8_t)(~UART1_CR3_CKEN); 
      008961 AE 52 36         [ 2]  476 	ldw	x, #0x5236
      008964 F6               [ 1]  477 	ld	a, (x)
      008965 A4 F7            [ 1]  478 	and	a, #0xf7
      008967 F7               [ 1]  479 	ld	(x), a
      008968 20 10            [ 2]  480 	jra	00110$
      00896A                        481 00108$:
                                    482 ;	../src/stm8s_uart1.c: 174: UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & UART1_CR3_CKEN);
      00896A AE 52 36         [ 2]  483 	ldw	x, #0x5236
      00896D F6               [ 1]  484 	ld	a, (x)
      00896E 6B 1A            [ 1]  485 	ld	(0x1a, sp), a
      008970 7B 2B            [ 1]  486 	ld	a, (0x2b, sp)
      008972 A4 08            [ 1]  487 	and	a, #0x08
      008974 1A 1A            [ 1]  488 	or	a, (0x1a, sp)
      008976 AE 52 36         [ 2]  489 	ldw	x, #0x5236
      008979 F7               [ 1]  490 	ld	(x), a
      00897A                        491 00110$:
      00897A 5B 21            [ 2]  492 	addw	sp, #33
      00897C 81               [ 4]  493 	ret
                                    494 ;	../src/stm8s_uart1.c: 184: void UART1_Cmd(FunctionalState NewState)
                                    495 ;	-----------------------------------------
                                    496 ;	 function UART1_Cmd
                                    497 ;	-----------------------------------------
      00897D                        498 _UART1_Cmd:
                                    499 ;	../src/stm8s_uart1.c: 186: if (NewState != DISABLE)
      00897D 0D 03            [ 1]  500 	tnz	(0x03, sp)
      00897F 27 09            [ 1]  501 	jreq	00102$
                                    502 ;	../src/stm8s_uart1.c: 189: UART1->CR1 &= (uint8_t)(~UART1_CR1_UARTD); 
      008981 AE 52 34         [ 2]  503 	ldw	x, #0x5234
      008984 F6               [ 1]  504 	ld	a, (x)
      008985 A4 DF            [ 1]  505 	and	a, #0xdf
      008987 F7               [ 1]  506 	ld	(x), a
      008988 20 07            [ 2]  507 	jra	00104$
      00898A                        508 00102$:
                                    509 ;	../src/stm8s_uart1.c: 194: UART1->CR1 |= UART1_CR1_UARTD;  
      00898A AE 52 34         [ 2]  510 	ldw	x, #0x5234
      00898D F6               [ 1]  511 	ld	a, (x)
      00898E AA 20            [ 1]  512 	or	a, #0x20
      008990 F7               [ 1]  513 	ld	(x), a
      008991                        514 00104$:
      008991 81               [ 4]  515 	ret
                                    516 ;	../src/stm8s_uart1.c: 211: void UART1_ITConfig(UART1_IT_TypeDef UART1_IT, FunctionalState NewState)
                                    517 ;	-----------------------------------------
                                    518 ;	 function UART1_ITConfig
                                    519 ;	-----------------------------------------
      008992                        520 _UART1_ITConfig:
                                    521 ;	../src/stm8s_uart1.c: 259: }
      008992 81               [ 4]  522 	ret
                                    523 ;	../src/stm8s_uart1.c: 267: void UART1_HalfDuplexCmd(FunctionalState NewState)
                                    524 ;	-----------------------------------------
                                    525 ;	 function UART1_HalfDuplexCmd
                                    526 ;	-----------------------------------------
      008993                        527 _UART1_HalfDuplexCmd:
                                    528 ;	../src/stm8s_uart1.c: 281: }
      008993 81               [ 4]  529 	ret
                                    530 ;	../src/stm8s_uart1.c: 289: void UART1_IrDAConfig(UART1_IrDAMode_TypeDef UART1_IrDAMode)
                                    531 ;	-----------------------------------------
                                    532 ;	 function UART1_IrDAConfig
                                    533 ;	-----------------------------------------
      008994                        534 _UART1_IrDAConfig:
                                    535 ;	../src/stm8s_uart1.c: 303: }
      008994 81               [ 4]  536 	ret
                                    537 ;	../src/stm8s_uart1.c: 311: void UART1_IrDACmd(FunctionalState NewState)
                                    538 ;	-----------------------------------------
                                    539 ;	 function UART1_IrDACmd
                                    540 ;	-----------------------------------------
      008995                        541 _UART1_IrDACmd:
                                    542 ;	../src/stm8s_uart1.c: 328: }
      008995 81               [ 4]  543 	ret
                                    544 ;	../src/stm8s_uart1.c: 337: void UART1_LINBreakDetectionConfig(UART1_LINBreakDetectionLength_TypeDef UART1_LINBreakDetectionLength)
                                    545 ;	-----------------------------------------
                                    546 ;	 function UART1_LINBreakDetectionConfig
                                    547 ;	-----------------------------------------
      008996                        548 _UART1_LINBreakDetectionConfig:
                                    549 ;	../src/stm8s_uart1.c: 351: }
      008996 81               [ 4]  550 	ret
                                    551 ;	../src/stm8s_uart1.c: 359: void UART1_LINCmd(FunctionalState NewState)
                                    552 ;	-----------------------------------------
                                    553 ;	 function UART1_LINCmd
                                    554 ;	-----------------------------------------
      008997                        555 _UART1_LINCmd:
                                    556 ;	../src/stm8s_uart1.c: 375: }
      008997 81               [ 4]  557 	ret
                                    558 ;	../src/stm8s_uart1.c: 383: void UART1_SmartCardCmd(FunctionalState NewState)
                                    559 ;	-----------------------------------------
                                    560 ;	 function UART1_SmartCardCmd
                                    561 ;	-----------------------------------------
      008998                        562 _UART1_SmartCardCmd:
                                    563 ;	../src/stm8s_uart1.c: 399: }
      008998 81               [ 4]  564 	ret
                                    565 ;	../src/stm8s_uart1.c: 408: void UART1_SmartCardNACKCmd(FunctionalState NewState)
                                    566 ;	-----------------------------------------
                                    567 ;	 function UART1_SmartCardNACKCmd
                                    568 ;	-----------------------------------------
      008999                        569 _UART1_SmartCardNACKCmd:
                                    570 ;	../src/stm8s_uart1.c: 424: }
      008999 81               [ 4]  571 	ret
                                    572 ;	../src/stm8s_uart1.c: 432: void UART1_WakeUpConfig(UART1_WakeUp_TypeDef UART1_WakeUp)
                                    573 ;	-----------------------------------------
                                    574 ;	 function UART1_WakeUpConfig
                                    575 ;	-----------------------------------------
      00899A                        576 _UART1_WakeUpConfig:
                                    577 ;	../src/stm8s_uart1.c: 440: }
      00899A 81               [ 4]  578 	ret
                                    579 ;	../src/stm8s_uart1.c: 448: void UART1_ReceiverWakeUpCmd(FunctionalState NewState)
                                    580 ;	-----------------------------------------
                                    581 ;	 function UART1_ReceiverWakeUpCmd
                                    582 ;	-----------------------------------------
      00899B                        583 _UART1_ReceiverWakeUpCmd:
                                    584 ;	../src/stm8s_uart1.c: 464: }
      00899B 81               [ 4]  585 	ret
                                    586 ;	../src/stm8s_uart1.c: 471: uint8_t UART1_ReceiveData8(void)
                                    587 ;	-----------------------------------------
                                    588 ;	 function UART1_ReceiveData8
                                    589 ;	-----------------------------------------
      00899C                        590 _UART1_ReceiveData8:
                                    591 ;	../src/stm8s_uart1.c: 473: return ((uint8_t)UART1->DR);
      00899C AE 52 31         [ 2]  592 	ldw	x, #0x5231
      00899F F6               [ 1]  593 	ld	a, (x)
      0089A0 81               [ 4]  594 	ret
                                    595 ;	../src/stm8s_uart1.c: 481: uint16_t UART1_ReceiveData9(void)
                                    596 ;	-----------------------------------------
                                    597 ;	 function UART1_ReceiveData9
                                    598 ;	-----------------------------------------
      0089A1                        599 _UART1_ReceiveData9:
                                    600 ;	../src/stm8s_uart1.c: 489: }
      0089A1 81               [ 4]  601 	ret
                                    602 ;	../src/stm8s_uart1.c: 496: void UART1_SendData8(uint8_t Data)
                                    603 ;	-----------------------------------------
                                    604 ;	 function UART1_SendData8
                                    605 ;	-----------------------------------------
      0089A2                        606 _UART1_SendData8:
                                    607 ;	../src/stm8s_uart1.c: 499: UART1->DR = Data;
      0089A2 AE 52 31         [ 2]  608 	ldw	x, #0x5231
      0089A5 7B 03            [ 1]  609 	ld	a, (0x03, sp)
      0089A7 F7               [ 1]  610 	ld	(x), a
      0089A8 81               [ 4]  611 	ret
                                    612 ;	../src/stm8s_uart1.c: 508: void UART1_SendData9(uint16_t Data)
                                    613 ;	-----------------------------------------
                                    614 ;	 function UART1_SendData9
                                    615 ;	-----------------------------------------
      0089A9                        616 _UART1_SendData9:
                                    617 ;	../src/stm8s_uart1.c: 518: }
      0089A9 81               [ 4]  618 	ret
                                    619 ;	../src/stm8s_uart1.c: 525: void UART1_SendBreak(void)
                                    620 ;	-----------------------------------------
                                    621 ;	 function UART1_SendBreak
                                    622 ;	-----------------------------------------
      0089AA                        623 _UART1_SendBreak:
                                    624 ;	../src/stm8s_uart1.c: 530: }
      0089AA 81               [ 4]  625 	ret
                                    626 ;	../src/stm8s_uart1.c: 537: void UART1_SetAddress(uint8_t UART1_Address)
                                    627 ;	-----------------------------------------
                                    628 ;	 function UART1_SetAddress
                                    629 ;	-----------------------------------------
      0089AB                        630 _UART1_SetAddress:
                                    631 ;	../src/stm8s_uart1.c: 548: }
      0089AB 81               [ 4]  632 	ret
                                    633 ;	../src/stm8s_uart1.c: 556: void UART1_SetGuardTime(uint8_t UART1_GuardTime)
                                    634 ;	-----------------------------------------
                                    635 ;	 function UART1_SetGuardTime
                                    636 ;	-----------------------------------------
      0089AC                        637 _UART1_SetGuardTime:
                                    638 ;	../src/stm8s_uart1.c: 562: }
      0089AC 81               [ 4]  639 	ret
                                    640 ;	../src/stm8s_uart1.c: 586: void UART1_SetPrescaler(uint8_t UART1_Prescaler)
                                    641 ;	-----------------------------------------
                                    642 ;	 function UART1_SetPrescaler
                                    643 ;	-----------------------------------------
      0089AD                        644 _UART1_SetPrescaler:
                                    645 ;	../src/stm8s_uart1.c: 592: }
      0089AD 81               [ 4]  646 	ret
                                    647 ;	../src/stm8s_uart1.c: 600: FlagStatus UART1_GetFlagStatus(UART1_Flag_TypeDef UART1_FLAG)
                                    648 ;	-----------------------------------------
                                    649 ;	 function UART1_GetFlagStatus
                                    650 ;	-----------------------------------------
      0089AE                        651 _UART1_GetFlagStatus:
      0089AE 89               [ 2]  652 	pushw	x
                                    653 ;	../src/stm8s_uart1.c: 605: assert_param(IS_UART1_FLAG_OK(UART1_FLAG));
      0089AF 1E 05            [ 2]  654 	ldw	x, (0x05, sp)
      0089B1 A3 01 01         [ 2]  655 	cpw	x, #0x0101
      0089B4 26 06            [ 1]  656 	jrne	00208$
      0089B6 A6 01            [ 1]  657 	ld	a, #0x01
      0089B8 6B 01            [ 1]  658 	ld	(0x01, sp), a
      0089BA 20 02            [ 2]  659 	jra	00209$
      0089BC                        660 00208$:
      0089BC 0F 01            [ 1]  661 	clr	(0x01, sp)
      0089BE                        662 00209$:
      0089BE 1E 05            [ 2]  663 	ldw	x, (0x05, sp)
      0089C0 A3 02 10         [ 2]  664 	cpw	x, #0x0210
      0089C3 26 03            [ 1]  665 	jrne	00211$
      0089C5 A6 01            [ 1]  666 	ld	a, #0x01
      0089C7 21                     667 	.byte 0x21
      0089C8                        668 00211$:
      0089C8 4F               [ 1]  669 	clr	a
      0089C9                        670 00212$:
      0089C9 1E 05            [ 2]  671 	ldw	x, (0x05, sp)
      0089CB A3 00 80         [ 2]  672 	cpw	x, #0x0080
      0089CE 27 4B            [ 1]  673 	jreq	00119$
      0089D0 1E 05            [ 2]  674 	ldw	x, (0x05, sp)
      0089D2 A3 00 40         [ 2]  675 	cpw	x, #0x0040
      0089D5 27 44            [ 1]  676 	jreq	00119$
      0089D7 1E 05            [ 2]  677 	ldw	x, (0x05, sp)
      0089D9 A3 00 20         [ 2]  678 	cpw	x, #0x0020
      0089DC 27 3D            [ 1]  679 	jreq	00119$
      0089DE 1E 05            [ 2]  680 	ldw	x, (0x05, sp)
      0089E0 A3 00 10         [ 2]  681 	cpw	x, #0x0010
      0089E3 27 36            [ 1]  682 	jreq	00119$
      0089E5 1E 05            [ 2]  683 	ldw	x, (0x05, sp)
      0089E7 A3 00 08         [ 2]  684 	cpw	x, #0x0008
      0089EA 27 2F            [ 1]  685 	jreq	00119$
      0089EC 1E 05            [ 2]  686 	ldw	x, (0x05, sp)
      0089EE A3 00 04         [ 2]  687 	cpw	x, #0x0004
      0089F1 27 28            [ 1]  688 	jreq	00119$
      0089F3 1E 05            [ 2]  689 	ldw	x, (0x05, sp)
      0089F5 A3 00 02         [ 2]  690 	cpw	x, #0x0002
      0089F8 27 21            [ 1]  691 	jreq	00119$
      0089FA 1E 05            [ 2]  692 	ldw	x, (0x05, sp)
      0089FC A3 00 01         [ 2]  693 	cpw	x, #0x0001
      0089FF 27 1A            [ 1]  694 	jreq	00119$
      008A01 0D 01            [ 1]  695 	tnz	(0x01, sp)
      008A03 26 16            [ 1]  696 	jrne	00119$
      008A05 4D               [ 1]  697 	tnz	a
      008A06 26 13            [ 1]  698 	jrne	00119$
      008A08 90 AE 8A 5B      [ 2]  699 	ldw	y, #___str_0+0
      008A0C 88               [ 1]  700 	push	a
      008A0D 4B 5D            [ 1]  701 	push	#0x5d
      008A0F 4B 02            [ 1]  702 	push	#0x02
      008A11 5F               [ 1]  703 	clrw	x
      008A12 89               [ 2]  704 	pushw	x
      008A13 90 89            [ 2]  705 	pushw	y
      008A15 CD 80 A8         [ 4]  706 	call	_assert_failed
      008A18 5B 06            [ 2]  707 	addw	sp, #6
      008A1A 84               [ 1]  708 	pop	a
      008A1B                        709 00119$:
                                    710 ;	../src/stm8s_uart1.c: 611: if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      008A1B 88               [ 1]  711 	push	a
      008A1C 7B 07            [ 1]  712 	ld	a, (0x07, sp)
      008A1E 6B 03            [ 1]  713 	ld	(0x03, sp), a
      008A20 84               [ 1]  714 	pop	a
                                    715 ;	../src/stm8s_uart1.c: 609: if (UART1_FLAG == UART1_FLAG_LBDF)
      008A21 4D               [ 1]  716 	tnz	a
      008A22 27 10            [ 1]  717 	jreq	00114$
                                    718 ;	../src/stm8s_uart1.c: 611: if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      008A24 AE 52 37         [ 2]  719 	ldw	x, #0x5237
      008A27 F6               [ 1]  720 	ld	a, (x)
      008A28 14 02            [ 1]  721 	and	a, (0x02, sp)
      008A2A 4D               [ 1]  722 	tnz	a
      008A2B 27 04            [ 1]  723 	jreq	00102$
                                    724 ;	../src/stm8s_uart1.c: 614: status = SET;
      008A2D A6 01            [ 1]  725 	ld	a, #0x01
      008A2F 20 24            [ 2]  726 	jra	00115$
      008A31                        727 00102$:
                                    728 ;	../src/stm8s_uart1.c: 619: status = RESET;
      008A31 4F               [ 1]  729 	clr	a
      008A32 20 21            [ 2]  730 	jra	00115$
      008A34                        731 00114$:
                                    732 ;	../src/stm8s_uart1.c: 622: else if (UART1_FLAG == UART1_FLAG_SBK)
      008A34 0D 01            [ 1]  733 	tnz	(0x01, sp)
      008A36 27 10            [ 1]  734 	jreq	00111$
                                    735 ;	../src/stm8s_uart1.c: 624: if ((UART1->CR2 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      008A38 AE 52 35         [ 2]  736 	ldw	x, #0x5235
      008A3B F6               [ 1]  737 	ld	a, (x)
      008A3C 14 02            [ 1]  738 	and	a, (0x02, sp)
      008A3E 4D               [ 1]  739 	tnz	a
      008A3F 27 04            [ 1]  740 	jreq	00105$
                                    741 ;	../src/stm8s_uart1.c: 627: status = SET;
      008A41 A6 01            [ 1]  742 	ld	a, #0x01
      008A43 20 10            [ 2]  743 	jra	00115$
      008A45                        744 00105$:
                                    745 ;	../src/stm8s_uart1.c: 632: status = RESET;
      008A45 4F               [ 1]  746 	clr	a
      008A46 20 0D            [ 2]  747 	jra	00115$
      008A48                        748 00111$:
                                    749 ;	../src/stm8s_uart1.c: 637: if ((UART1->SR & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      008A48 AE 52 30         [ 2]  750 	ldw	x, #0x5230
      008A4B F6               [ 1]  751 	ld	a, (x)
      008A4C 14 02            [ 1]  752 	and	a, (0x02, sp)
      008A4E 4D               [ 1]  753 	tnz	a
      008A4F 27 03            [ 1]  754 	jreq	00108$
                                    755 ;	../src/stm8s_uart1.c: 640: status = SET;
      008A51 A6 01            [ 1]  756 	ld	a, #0x01
                                    757 ;	../src/stm8s_uart1.c: 645: status = RESET;
      008A53 21                     758 	.byte 0x21
      008A54                        759 00108$:
      008A54 4F               [ 1]  760 	clr	a
      008A55                        761 00115$:
                                    762 ;	../src/stm8s_uart1.c: 649: return status;
      008A55 85               [ 2]  763 	popw	x
      008A56 81               [ 4]  764 	ret
                                    765 ;	../src/stm8s_uart1.c: 678: void UART1_ClearFlag(UART1_Flag_TypeDef UART1_FLAG)
                                    766 ;	-----------------------------------------
                                    767 ;	 function UART1_ClearFlag
                                    768 ;	-----------------------------------------
      008A57                        769 _UART1_ClearFlag:
                                    770 ;	../src/stm8s_uart1.c: 694: }
      008A57 81               [ 4]  771 	ret
                                    772 ;	../src/stm8s_uart1.c: 709: ITStatus UART1_GetITStatus(UART1_IT_TypeDef UART1_IT)
                                    773 ;	-----------------------------------------
                                    774 ;	 function UART1_GetITStatus
                                    775 ;	-----------------------------------------
      008A58                        776 _UART1_GetITStatus:
                                    777 ;	../src/stm8s_uart1.c: 784: return 0;
      008A58 4F               [ 1]  778 	clr	a
      008A59 81               [ 4]  779 	ret
                                    780 ;	../src/stm8s_uart1.c: 812: void UART1_ClearITPendingBit(UART1_IT_TypeDef UART1_IT)
                                    781 ;	-----------------------------------------
                                    782 ;	 function UART1_ClearITPendingBit
                                    783 ;	-----------------------------------------
      008A5A                        784 _UART1_ClearITPendingBit:
                                    785 ;	../src/stm8s_uart1.c: 828: }
      008A5A 81               [ 4]  786 	ret
                                    787 	.area CODE
      008A5B                        788 ___str_0:
      008A5B 2E 2E 2F 73 72 63 2F   789 	.ascii "../src/stm8s_uart1.c"
             73 74 6D 38 73 5F 75
             61 72 74 31 2E 63
      008A6F 00                     790 	.db 0x00
                                    791 	.area INITIALIZER
                                    792 	.area CABS (ABS)
