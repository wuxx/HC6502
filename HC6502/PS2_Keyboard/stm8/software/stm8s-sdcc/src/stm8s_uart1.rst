                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_uart1
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _assert_failed
                                     12 	.globl _CLK_GetClockFreq
                                     13 	.globl _UART1_DeInit
                                     14 	.globl _UART1_Init
                                     15 	.globl _UART1_Cmd
                                     16 	.globl _UART1_ITConfig
                                     17 	.globl _UART1_HalfDuplexCmd
                                     18 	.globl _UART1_IrDAConfig
                                     19 	.globl _UART1_IrDACmd
                                     20 	.globl _UART1_LINBreakDetectionConfig
                                     21 	.globl _UART1_LINCmd
                                     22 	.globl _UART1_SmartCardCmd
                                     23 	.globl _UART1_SmartCardNACKCmd
                                     24 	.globl _UART1_WakeUpConfig
                                     25 	.globl _UART1_ReceiverWakeUpCmd
                                     26 	.globl _UART1_ReceiveData8
                                     27 	.globl _UART1_ReceiveData9
                                     28 	.globl _UART1_SendData8
                                     29 	.globl _UART1_SendData9
                                     30 	.globl _UART1_SendBreak
                                     31 	.globl _UART1_SetAddress
                                     32 	.globl _UART1_SetGuardTime
                                     33 	.globl _UART1_SetPrescaler
                                     34 	.globl _UART1_GetFlagStatus
                                     35 	.globl _UART1_ClearFlag
                                     36 	.globl _UART1_GetITStatus
                                     37 	.globl _UART1_ClearITPendingBit
                                     38 ;--------------------------------------------------------
                                     39 ; ram data
                                     40 ;--------------------------------------------------------
                                     41 	.area DATA
                                     42 ;--------------------------------------------------------
                                     43 ; ram data
                                     44 ;--------------------------------------------------------
                                     45 	.area INITIALIZED
                                     46 ;--------------------------------------------------------
                                     47 ; absolute external ram data
                                     48 ;--------------------------------------------------------
                                     49 	.area DABS (ABS)
                                     50 
                                     51 ; default segment ordering for linker
                                     52 	.area HOME
                                     53 	.area GSINIT
                                     54 	.area GSFINAL
                                     55 	.area CONST
                                     56 	.area INITIALIZER
                                     57 	.area CODE
                                     58 
                                     59 ;--------------------------------------------------------
                                     60 ; global & static initialisations
                                     61 ;--------------------------------------------------------
                                     62 	.area HOME
                                     63 	.area GSINIT
                                     64 	.area GSFINAL
                                     65 	.area GSINIT
                                     66 ;--------------------------------------------------------
                                     67 ; Home
                                     68 ;--------------------------------------------------------
                                     69 	.area HOME
                                     70 	.area HOME
                                     71 ;--------------------------------------------------------
                                     72 ; code
                                     73 ;--------------------------------------------------------
                                     74 	.area CODE
                                     75 ;	../src/stm8s_uart1.c: 53: void UART1_DeInit(void)
                                     76 ;	-----------------------------------------
                                     77 ;	 function UART1_DeInit
                                     78 ;	-----------------------------------------
      00868F                         79 _UART1_DeInit:
                                     80 ;	../src/stm8s_uart1.c: 57: (void)UART1->SR;
      00868F C6 52 30         [ 1]   81 	ld	a, 0x5230
                                     82 ;	../src/stm8s_uart1.c: 58: (void)UART1->DR;
      008692 C6 52 31         [ 1]   83 	ld	a, 0x5231
                                     84 ;	../src/stm8s_uart1.c: 60: UART1->BRR2 = UART1_BRR2_RESET_VALUE;  /* Set UART1_BRR2 to reset value 0x00 */
      008695 35 00 52 33      [ 1]   85 	mov	0x5233+0, #0x00
                                     86 ;	../src/stm8s_uart1.c: 61: UART1->BRR1 = UART1_BRR1_RESET_VALUE;  /* Set UART1_BRR1 to reset value 0x00 */
      008699 35 00 52 32      [ 1]   87 	mov	0x5232+0, #0x00
                                     88 ;	../src/stm8s_uart1.c: 63: UART1->CR1 = UART1_CR1_RESET_VALUE;  /* Set UART1_CR1 to reset value 0x00 */
      00869D 35 00 52 34      [ 1]   89 	mov	0x5234+0, #0x00
                                     90 ;	../src/stm8s_uart1.c: 64: UART1->CR2 = UART1_CR2_RESET_VALUE;  /* Set UART1_CR2 to reset value 0x00 */
      0086A1 35 00 52 35      [ 1]   91 	mov	0x5235+0, #0x00
                                     92 ;	../src/stm8s_uart1.c: 65: UART1->CR3 = UART1_CR3_RESET_VALUE;  /* Set UART1_CR3 to reset value 0x00 */
      0086A5 35 00 52 36      [ 1]   93 	mov	0x5236+0, #0x00
                                     94 ;	../src/stm8s_uart1.c: 66: UART1->CR4 = UART1_CR4_RESET_VALUE;  /* Set UART1_CR4 to reset value 0x00 */
      0086A9 35 00 52 37      [ 1]   95 	mov	0x5237+0, #0x00
                                     96 ;	../src/stm8s_uart1.c: 67: UART1->CR5 = UART1_CR5_RESET_VALUE;  /* Set UART1_CR5 to reset value 0x00 */
      0086AD 35 00 52 38      [ 1]   97 	mov	0x5238+0, #0x00
                                     98 ;	../src/stm8s_uart1.c: 69: UART1->GTR = UART1_GTR_RESET_VALUE;
      0086B1 35 00 52 39      [ 1]   99 	mov	0x5239+0, #0x00
                                    100 ;	../src/stm8s_uart1.c: 70: UART1->PSCR = UART1_PSCR_RESET_VALUE;
      0086B5 35 00 52 3A      [ 1]  101 	mov	0x523a+0, #0x00
                                    102 ;	../src/stm8s_uart1.c: 71: }
      0086B9 81               [ 4]  103 	ret
                                    104 ;	../src/stm8s_uart1.c: 90: void UART1_Init(uint32_t BaudRate, UART1_WordLength_TypeDef WordLength, 
                                    105 ;	-----------------------------------------
                                    106 ;	 function UART1_Init
                                    107 ;	-----------------------------------------
      0086BA                        108 _UART1_Init:
      0086BA 52 1D            [ 2]  109 	sub	sp, #29
                                    110 ;	../src/stm8s_uart1.c: 97: assert_param(IS_UART1_BAUDRATE_OK(BaudRate));
      0086BC AE 89 68         [ 2]  111 	ldw	x, #0x8968
      0086BF 13 22            [ 2]  112 	cpw	x, (0x22, sp)
      0086C1 A6 09            [ 1]  113 	ld	a, #0x09
      0086C3 12 21            [ 1]  114 	sbc	a, (0x21, sp)
      0086C5 4F               [ 1]  115 	clr	a
      0086C6 12 20            [ 1]  116 	sbc	a, (0x20, sp)
      0086C8 24 0F            [ 1]  117 	jrnc	00113$
      0086CA 4B 61            [ 1]  118 	push	#0x61
      0086CC 5F               [ 1]  119 	clrw	x
      0086CD 89               [ 2]  120 	pushw	x
      0086CE 4B 00            [ 1]  121 	push	#0x00
      0086D0 4B EF            [ 1]  122 	push	#<___str_0
      0086D2 4B 81            [ 1]  123 	push	#(___str_0 >> 8)
      0086D4 CD 82 CE         [ 4]  124 	call	_assert_failed
      0086D7 5B 06            [ 2]  125 	addw	sp, #6
      0086D9                        126 00113$:
                                    127 ;	../src/stm8s_uart1.c: 98: assert_param(IS_UART1_WORDLENGTH_OK(WordLength));
      0086D9 0D 24            [ 1]  128 	tnz	(0x24, sp)
      0086DB 27 15            [ 1]  129 	jreq	00115$
      0086DD 7B 24            [ 1]  130 	ld	a, (0x24, sp)
      0086DF A1 10            [ 1]  131 	cp	a, #0x10
      0086E1 27 0F            [ 1]  132 	jreq	00115$
      0086E3 4B 62            [ 1]  133 	push	#0x62
      0086E5 5F               [ 1]  134 	clrw	x
      0086E6 89               [ 2]  135 	pushw	x
      0086E7 4B 00            [ 1]  136 	push	#0x00
      0086E9 4B EF            [ 1]  137 	push	#<___str_0
      0086EB 4B 81            [ 1]  138 	push	#(___str_0 >> 8)
      0086ED CD 82 CE         [ 4]  139 	call	_assert_failed
      0086F0 5B 06            [ 2]  140 	addw	sp, #6
      0086F2                        141 00115$:
                                    142 ;	../src/stm8s_uart1.c: 99: assert_param(IS_UART1_STOPBITS_OK(StopBits));
      0086F2 0D 25            [ 1]  143 	tnz	(0x25, sp)
      0086F4 27 21            [ 1]  144 	jreq	00120$
      0086F6 7B 25            [ 1]  145 	ld	a, (0x25, sp)
      0086F8 A1 10            [ 1]  146 	cp	a, #0x10
      0086FA 27 1B            [ 1]  147 	jreq	00120$
      0086FC 7B 25            [ 1]  148 	ld	a, (0x25, sp)
      0086FE A1 20            [ 1]  149 	cp	a, #0x20
      008700 27 15            [ 1]  150 	jreq	00120$
      008702 7B 25            [ 1]  151 	ld	a, (0x25, sp)
      008704 A1 30            [ 1]  152 	cp	a, #0x30
      008706 27 0F            [ 1]  153 	jreq	00120$
      008708 4B 63            [ 1]  154 	push	#0x63
      00870A 5F               [ 1]  155 	clrw	x
      00870B 89               [ 2]  156 	pushw	x
      00870C 4B 00            [ 1]  157 	push	#0x00
      00870E 4B EF            [ 1]  158 	push	#<___str_0
      008710 4B 81            [ 1]  159 	push	#(___str_0 >> 8)
      008712 CD 82 CE         [ 4]  160 	call	_assert_failed
      008715 5B 06            [ 2]  161 	addw	sp, #6
      008717                        162 00120$:
                                    163 ;	../src/stm8s_uart1.c: 100: assert_param(IS_UART1_PARITY_OK(Parity));
      008717 0D 26            [ 1]  164 	tnz	(0x26, sp)
      008719 27 1B            [ 1]  165 	jreq	00131$
      00871B 7B 26            [ 1]  166 	ld	a, (0x26, sp)
      00871D A1 04            [ 1]  167 	cp	a, #0x04
      00871F 27 15            [ 1]  168 	jreq	00131$
      008721 7B 26            [ 1]  169 	ld	a, (0x26, sp)
      008723 A1 06            [ 1]  170 	cp	a, #0x06
      008725 27 0F            [ 1]  171 	jreq	00131$
      008727 4B 64            [ 1]  172 	push	#0x64
      008729 5F               [ 1]  173 	clrw	x
      00872A 89               [ 2]  174 	pushw	x
      00872B 4B 00            [ 1]  175 	push	#0x00
      00872D 4B EF            [ 1]  176 	push	#<___str_0
      00872F 4B 81            [ 1]  177 	push	#(___str_0 >> 8)
      008731 CD 82 CE         [ 4]  178 	call	_assert_failed
      008734 5B 06            [ 2]  179 	addw	sp, #6
      008736                        180 00131$:
                                    181 ;	../src/stm8s_uart1.c: 101: assert_param(IS_UART1_MODE_OK((uint8_t)Mode));
      008736 7B 28            [ 1]  182 	ld	a, (0x28, sp)
      008738 A1 08            [ 1]  183 	cp	a, #0x08
      00873A 27 42            [ 1]  184 	jreq	00139$
      00873C 7B 28            [ 1]  185 	ld	a, (0x28, sp)
      00873E A1 40            [ 1]  186 	cp	a, #0x40
      008740 27 3C            [ 1]  187 	jreq	00139$
      008742 7B 28            [ 1]  188 	ld	a, (0x28, sp)
      008744 A1 04            [ 1]  189 	cp	a, #0x04
      008746 27 36            [ 1]  190 	jreq	00139$
      008748 7B 28            [ 1]  191 	ld	a, (0x28, sp)
      00874A A1 80            [ 1]  192 	cp	a, #0x80
      00874C 27 30            [ 1]  193 	jreq	00139$
      00874E 7B 28            [ 1]  194 	ld	a, (0x28, sp)
      008750 A0 0C            [ 1]  195 	sub	a, #0x0c
      008752 26 02            [ 1]  196 	jrne	00339$
      008754 4C               [ 1]  197 	inc	a
      008755 21                     198 	.byte 0x21
      008756                        199 00339$:
      008756 4F               [ 1]  200 	clr	a
      008757                        201 00340$:
      008757 4D               [ 1]  202 	tnz	a
      008758 26 24            [ 1]  203 	jrne	00139$
      00875A 4D               [ 1]  204 	tnz	a
      00875B 26 21            [ 1]  205 	jrne	00139$
      00875D 7B 28            [ 1]  206 	ld	a, (0x28, sp)
      00875F A1 44            [ 1]  207 	cp	a, #0x44
      008761 27 1B            [ 1]  208 	jreq	00139$
      008763 7B 28            [ 1]  209 	ld	a, (0x28, sp)
      008765 A1 C0            [ 1]  210 	cp	a, #0xc0
      008767 27 15            [ 1]  211 	jreq	00139$
      008769 7B 28            [ 1]  212 	ld	a, (0x28, sp)
      00876B A1 88            [ 1]  213 	cp	a, #0x88
      00876D 27 0F            [ 1]  214 	jreq	00139$
      00876F 4B 65            [ 1]  215 	push	#0x65
      008771 5F               [ 1]  216 	clrw	x
      008772 89               [ 2]  217 	pushw	x
      008773 4B 00            [ 1]  218 	push	#0x00
      008775 4B EF            [ 1]  219 	push	#<___str_0
      008777 4B 81            [ 1]  220 	push	#(___str_0 >> 8)
      008779 CD 82 CE         [ 4]  221 	call	_assert_failed
      00877C 5B 06            [ 2]  222 	addw	sp, #6
      00877E                        223 00139$:
                                    224 ;	../src/stm8s_uart1.c: 102: assert_param(IS_UART1_SYNCMODE_OK((uint8_t)SyncMode));
      00877E 7B 27            [ 1]  225 	ld	a, (0x27, sp)
      008780 A4 88            [ 1]  226 	and	a, #0x88
      008782 A1 88            [ 1]  227 	cp	a, #0x88
      008784 27 18            [ 1]  228 	jreq	00167$
      008786 7B 27            [ 1]  229 	ld	a, (0x27, sp)
      008788 A4 44            [ 1]  230 	and	a, #0x44
      00878A A1 44            [ 1]  231 	cp	a, #0x44
      00878C 27 10            [ 1]  232 	jreq	00167$
      00878E 7B 27            [ 1]  233 	ld	a, (0x27, sp)
      008790 A4 22            [ 1]  234 	and	a, #0x22
      008792 A1 22            [ 1]  235 	cp	a, #0x22
      008794 27 08            [ 1]  236 	jreq	00167$
      008796 7B 27            [ 1]  237 	ld	a, (0x27, sp)
      008798 A4 11            [ 1]  238 	and	a, #0x11
      00879A A1 11            [ 1]  239 	cp	a, #0x11
      00879C 26 0F            [ 1]  240 	jrne	00165$
      00879E                        241 00167$:
      00879E 4B 66            [ 1]  242 	push	#0x66
      0087A0 5F               [ 1]  243 	clrw	x
      0087A1 89               [ 2]  244 	pushw	x
      0087A2 4B 00            [ 1]  245 	push	#0x00
      0087A4 4B EF            [ 1]  246 	push	#<___str_0
      0087A6 4B 81            [ 1]  247 	push	#(___str_0 >> 8)
      0087A8 CD 82 CE         [ 4]  248 	call	_assert_failed
      0087AB 5B 06            [ 2]  249 	addw	sp, #6
      0087AD                        250 00165$:
                                    251 ;	../src/stm8s_uart1.c: 105: UART1->CR1 &= (uint8_t)(~UART1_CR1_M);  
      0087AD 72 19 52 34      [ 1]  252 	bres	21044, #4
                                    253 ;	../src/stm8s_uart1.c: 108: UART1->CR1 |= (uint8_t)WordLength;
      0087B1 C6 52 34         [ 1]  254 	ld	a, 0x5234
      0087B4 1A 24            [ 1]  255 	or	a, (0x24, sp)
      0087B6 C7 52 34         [ 1]  256 	ld	0x5234, a
                                    257 ;	../src/stm8s_uart1.c: 111: UART1->CR3 &= (uint8_t)(~UART1_CR3_STOP);  
      0087B9 C6 52 36         [ 1]  258 	ld	a, 0x5236
      0087BC A4 CF            [ 1]  259 	and	a, #0xcf
      0087BE C7 52 36         [ 1]  260 	ld	0x5236, a
                                    261 ;	../src/stm8s_uart1.c: 113: UART1->CR3 |= (uint8_t)StopBits;  
      0087C1 C6 52 36         [ 1]  262 	ld	a, 0x5236
      0087C4 1A 25            [ 1]  263 	or	a, (0x25, sp)
      0087C6 C7 52 36         [ 1]  264 	ld	0x5236, a
                                    265 ;	../src/stm8s_uart1.c: 116: UART1->CR1 &= (uint8_t)(~(UART1_CR1_PCEN | UART1_CR1_PS  ));  
      0087C9 C6 52 34         [ 1]  266 	ld	a, 0x5234
      0087CC A4 F9            [ 1]  267 	and	a, #0xf9
      0087CE C7 52 34         [ 1]  268 	ld	0x5234, a
                                    269 ;	../src/stm8s_uart1.c: 118: UART1->CR1 |= (uint8_t)Parity;  
      0087D1 C6 52 34         [ 1]  270 	ld	a, 0x5234
      0087D4 1A 26            [ 1]  271 	or	a, (0x26, sp)
      0087D6 C7 52 34         [ 1]  272 	ld	0x5234, a
                                    273 ;	../src/stm8s_uart1.c: 121: UART1->BRR1 &= (uint8_t)(~UART1_BRR1_DIVM);  
      0087D9 C6 52 32         [ 1]  274 	ld	a, 0x5232
      0087DC 35 00 52 32      [ 1]  275 	mov	0x5232+0, #0x00
                                    276 ;	../src/stm8s_uart1.c: 123: UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVM);  
      0087E0 C6 52 33         [ 1]  277 	ld	a, 0x5233
      0087E3 A4 0F            [ 1]  278 	and	a, #0x0f
      0087E5 C7 52 33         [ 1]  279 	ld	0x5233, a
                                    280 ;	../src/stm8s_uart1.c: 125: UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVF);  
      0087E8 C6 52 33         [ 1]  281 	ld	a, 0x5233
      0087EB A4 F0            [ 1]  282 	and	a, #0xf0
      0087ED C7 52 33         [ 1]  283 	ld	0x5233, a
                                    284 ;	../src/stm8s_uart1.c: 128: BaudRate_Mantissa    = ((uint32_t)CLK_GetClockFreq() / (BaudRate << 4));
      0087F0 CD 90 6D         [ 4]  285 	call	_CLK_GetClockFreq
      0087F3 1F 05            [ 2]  286 	ldw	(0x05, sp), x
      0087F5 1E 20            [ 2]  287 	ldw	x, (0x20, sp)
      0087F7 1F 08            [ 2]  288 	ldw	(0x08, sp), x
      0087F9 1E 22            [ 2]  289 	ldw	x, (0x22, sp)
      0087FB A6 04            [ 1]  290 	ld	a, #0x04
      0087FD                        291 00364$:
      0087FD 58               [ 2]  292 	sllw	x
      0087FE 09 09            [ 1]  293 	rlc	(0x09, sp)
      008800 09 08            [ 1]  294 	rlc	(0x08, sp)
      008802 4A               [ 1]  295 	dec	a
      008803 26 F8            [ 1]  296 	jrne	00364$
      008805 1F 0A            [ 2]  297 	ldw	(0x0a, sp), x
      008807 89               [ 2]  298 	pushw	x
      008808 1E 0A            [ 2]  299 	ldw	x, (0x0a, sp)
      00880A 89               [ 2]  300 	pushw	x
      00880B 1E 09            [ 2]  301 	ldw	x, (0x09, sp)
      00880D 89               [ 2]  302 	pushw	x
      00880E 90 89            [ 2]  303 	pushw	y
      008810 CD 93 9B         [ 4]  304 	call	__divulong
      008813 5B 08            [ 2]  305 	addw	sp, #8
      008815 1F 1C            [ 2]  306 	ldw	(0x1c, sp), x
      008817 17 1A            [ 2]  307 	ldw	(0x1a, sp), y
                                    308 ;	../src/stm8s_uart1.c: 129: BaudRate_Mantissa100 = (((uint32_t)CLK_GetClockFreq() * 100) / (BaudRate << 4));
      008819 CD 90 6D         [ 4]  309 	call	_CLK_GetClockFreq
      00881C 89               [ 2]  310 	pushw	x
      00881D 90 89            [ 2]  311 	pushw	y
      00881F 4B 64            [ 1]  312 	push	#0x64
      008821 5F               [ 1]  313 	clrw	x
      008822 89               [ 2]  314 	pushw	x
      008823 4B 00            [ 1]  315 	push	#0x00
      008825 CD 94 4C         [ 4]  316 	call	__mullong
      008828 5B 08            [ 2]  317 	addw	sp, #8
      00882A 1F 14            [ 2]  318 	ldw	(0x14, sp), x
      00882C 1E 0A            [ 2]  319 	ldw	x, (0x0a, sp)
      00882E 89               [ 2]  320 	pushw	x
      00882F 1E 0A            [ 2]  321 	ldw	x, (0x0a, sp)
      008831 89               [ 2]  322 	pushw	x
      008832 1E 18            [ 2]  323 	ldw	x, (0x18, sp)
      008834 89               [ 2]  324 	pushw	x
      008835 90 89            [ 2]  325 	pushw	y
      008837 CD 93 9B         [ 4]  326 	call	__divulong
      00883A 5B 08            [ 2]  327 	addw	sp, #8
      00883C 90 9E            [ 1]  328 	ld	a, yh
      00883E 1F 18            [ 2]  329 	ldw	(0x18, sp), x
      008840 6B 16            [ 1]  330 	ld	(0x16, sp), a
      008842 90 9F            [ 1]  331 	ld	a, yl
                                    332 ;	../src/stm8s_uart1.c: 131: UART1->BRR2 |= (uint8_t)((uint8_t)(((BaudRate_Mantissa100 - (BaudRate_Mantissa * 100)) << 4) / 100) & (uint8_t)0x0F); 
      008844 AE 52 33         [ 2]  333 	ldw	x, #0x5233
      008847 88               [ 1]  334 	push	a
      008848 F6               [ 1]  335 	ld	a, (x)
      008849 6B 08            [ 1]  336 	ld	(0x08, sp), a
      00884B 1E 1D            [ 2]  337 	ldw	x, (0x1d, sp)
      00884D 89               [ 2]  338 	pushw	x
      00884E 1E 1D            [ 2]  339 	ldw	x, (0x1d, sp)
      008850 89               [ 2]  340 	pushw	x
      008851 4B 64            [ 1]  341 	push	#0x64
      008853 5F               [ 1]  342 	clrw	x
      008854 89               [ 2]  343 	pushw	x
      008855 4B 00            [ 1]  344 	push	#0x00
      008857 CD 94 4C         [ 4]  345 	call	__mullong
      00885A 5B 08            [ 2]  346 	addw	sp, #8
      00885C 1F 11            [ 2]  347 	ldw	(0x11, sp), x
      00885E 17 0F            [ 2]  348 	ldw	(0x0f, sp), y
      008860 84               [ 1]  349 	pop	a
      008861 16 18            [ 2]  350 	ldw	y, (0x18, sp)
      008863 72 F2 10         [ 2]  351 	subw	y, (0x10, sp)
      008866 12 0F            [ 1]  352 	sbc	a, (0x0f, sp)
      008868 97               [ 1]  353 	ld	xl, a
      008869 7B 16            [ 1]  354 	ld	a, (0x16, sp)
      00886B 12 0E            [ 1]  355 	sbc	a, (0x0e, sp)
      00886D 95               [ 1]  356 	ld	xh, a
      00886E A6 04            [ 1]  357 	ld	a, #0x04
      008870                        358 00366$:
      008870 90 58            [ 2]  359 	sllw	y
      008872 59               [ 2]  360 	rlcw	x
      008873 4A               [ 1]  361 	dec	a
      008874 26 FA            [ 1]  362 	jrne	00366$
      008876 4B 64            [ 1]  363 	push	#0x64
      008878 4B 00            [ 1]  364 	push	#0x00
      00887A 4B 00            [ 1]  365 	push	#0x00
      00887C 4B 00            [ 1]  366 	push	#0x00
      00887E 90 89            [ 2]  367 	pushw	y
      008880 89               [ 2]  368 	pushw	x
      008881 CD 93 9B         [ 4]  369 	call	__divulong
      008884 5B 08            [ 2]  370 	addw	sp, #8
      008886 9F               [ 1]  371 	ld	a, xl
      008887 A4 0F            [ 1]  372 	and	a, #0x0f
      008889 1A 07            [ 1]  373 	or	a, (0x07, sp)
      00888B C7 52 33         [ 1]  374 	ld	0x5233, a
                                    375 ;	../src/stm8s_uart1.c: 133: UART1->BRR2 |= (uint8_t)((BaudRate_Mantissa >> 4) & (uint8_t)0xF0); 
      00888E C6 52 33         [ 1]  376 	ld	a, 0x5233
      008891 6B 01            [ 1]  377 	ld	(0x01, sp), a
      008893 1E 1C            [ 2]  378 	ldw	x, (0x1c, sp)
      008895 A6 10            [ 1]  379 	ld	a, #0x10
      008897 62               [ 2]  380 	div	x, a
      008898 9F               [ 1]  381 	ld	a, xl
      008899 A4 F0            [ 1]  382 	and	a, #0xf0
      00889B 1A 01            [ 1]  383 	or	a, (0x01, sp)
      00889D C7 52 33         [ 1]  384 	ld	0x5233, a
                                    385 ;	../src/stm8s_uart1.c: 135: UART1->BRR1 |= (uint8_t)BaudRate_Mantissa;           
      0088A0 C6 52 32         [ 1]  386 	ld	a, 0x5232
      0088A3 6B 02            [ 1]  387 	ld	(0x02, sp), a
      0088A5 7B 1D            [ 1]  388 	ld	a, (0x1d, sp)
      0088A7 1A 02            [ 1]  389 	or	a, (0x02, sp)
      0088A9 C7 52 32         [ 1]  390 	ld	0x5232, a
                                    391 ;	../src/stm8s_uart1.c: 138: UART1->CR2 &= (uint8_t)~(UART1_CR2_TEN | UART1_CR2_REN); 
      0088AC C6 52 35         [ 1]  392 	ld	a, 0x5235
      0088AF A4 F3            [ 1]  393 	and	a, #0xf3
      0088B1 C7 52 35         [ 1]  394 	ld	0x5235, a
                                    395 ;	../src/stm8s_uart1.c: 140: UART1->CR3 &= (uint8_t)~(UART1_CR3_CPOL | UART1_CR3_CPHA | UART1_CR3_LBCL); 
      0088B4 C6 52 36         [ 1]  396 	ld	a, 0x5236
      0088B7 A4 F8            [ 1]  397 	and	a, #0xf8
      0088B9 C7 52 36         [ 1]  398 	ld	0x5236, a
                                    399 ;	../src/stm8s_uart1.c: 142: UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & (uint8_t)(UART1_CR3_CPOL | 
      0088BC C6 52 36         [ 1]  400 	ld	a, 0x5236
      0088BF 6B 0C            [ 1]  401 	ld	(0x0c, sp), a
      0088C1 7B 27            [ 1]  402 	ld	a, (0x27, sp)
      0088C3 A4 07            [ 1]  403 	and	a, #0x07
      0088C5 1A 0C            [ 1]  404 	or	a, (0x0c, sp)
      0088C7 C7 52 36         [ 1]  405 	ld	0x5236, a
                                    406 ;	../src/stm8s_uart1.c: 138: UART1->CR2 &= (uint8_t)~(UART1_CR2_TEN | UART1_CR2_REN); 
      0088CA C6 52 35         [ 1]  407 	ld	a, 0x5235
                                    408 ;	../src/stm8s_uart1.c: 145: if ((uint8_t)(Mode & UART1_MODE_TX_ENABLE))
      0088CD 88               [ 1]  409 	push	a
      0088CE 7B 29            [ 1]  410 	ld	a, (0x29, sp)
      0088D0 A5 04            [ 1]  411 	bcp	a, #0x04
      0088D2 84               [ 1]  412 	pop	a
      0088D3 27 07            [ 1]  413 	jreq	00102$
                                    414 ;	../src/stm8s_uart1.c: 148: UART1->CR2 |= (uint8_t)UART1_CR2_TEN;  
      0088D5 AA 08            [ 1]  415 	or	a, #0x08
      0088D7 C7 52 35         [ 1]  416 	ld	0x5235, a
      0088DA 20 05            [ 2]  417 	jra	00103$
      0088DC                        418 00102$:
                                    419 ;	../src/stm8s_uart1.c: 153: UART1->CR2 &= (uint8_t)(~UART1_CR2_TEN);  
      0088DC A4 F7            [ 1]  420 	and	a, #0xf7
      0088DE C7 52 35         [ 1]  421 	ld	0x5235, a
      0088E1                        422 00103$:
                                    423 ;	../src/stm8s_uart1.c: 138: UART1->CR2 &= (uint8_t)~(UART1_CR2_TEN | UART1_CR2_REN); 
      0088E1 C6 52 35         [ 1]  424 	ld	a, 0x5235
                                    425 ;	../src/stm8s_uart1.c: 155: if ((uint8_t)(Mode & UART1_MODE_RX_ENABLE))
      0088E4 88               [ 1]  426 	push	a
      0088E5 7B 29            [ 1]  427 	ld	a, (0x29, sp)
      0088E7 A5 08            [ 1]  428 	bcp	a, #0x08
      0088E9 84               [ 1]  429 	pop	a
      0088EA 27 07            [ 1]  430 	jreq	00105$
                                    431 ;	../src/stm8s_uart1.c: 158: UART1->CR2 |= (uint8_t)UART1_CR2_REN;  
      0088EC AA 04            [ 1]  432 	or	a, #0x04
      0088EE C7 52 35         [ 1]  433 	ld	0x5235, a
      0088F1 20 05            [ 2]  434 	jra	00106$
      0088F3                        435 00105$:
                                    436 ;	../src/stm8s_uart1.c: 163: UART1->CR2 &= (uint8_t)(~UART1_CR2_REN);  
      0088F3 A4 FB            [ 1]  437 	and	a, #0xfb
      0088F5 C7 52 35         [ 1]  438 	ld	0x5235, a
      0088F8                        439 00106$:
                                    440 ;	../src/stm8s_uart1.c: 111: UART1->CR3 &= (uint8_t)(~UART1_CR3_STOP);  
      0088F8 C6 52 36         [ 1]  441 	ld	a, 0x5236
                                    442 ;	../src/stm8s_uart1.c: 167: if ((uint8_t)(SyncMode & UART1_SYNCMODE_CLOCK_DISABLE))
      0088FB 0D 27            [ 1]  443 	tnz	(0x27, sp)
      0088FD 2A 07            [ 1]  444 	jrpl	00108$
                                    445 ;	../src/stm8s_uart1.c: 170: UART1->CR3 &= (uint8_t)(~UART1_CR3_CKEN); 
      0088FF A4 F7            [ 1]  446 	and	a, #0xf7
      008901 C7 52 36         [ 1]  447 	ld	0x5236, a
      008904 20 0D            [ 2]  448 	jra	00110$
      008906                        449 00108$:
                                    450 ;	../src/stm8s_uart1.c: 174: UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & UART1_CR3_CKEN);
      008906 88               [ 1]  451 	push	a
      008907 7B 28            [ 1]  452 	ld	a, (0x28, sp)
      008909 A4 08            [ 1]  453 	and	a, #0x08
      00890B 6B 0E            [ 1]  454 	ld	(0x0e, sp), a
      00890D 84               [ 1]  455 	pop	a
      00890E 1A 0D            [ 1]  456 	or	a, (0x0d, sp)
      008910 C7 52 36         [ 1]  457 	ld	0x5236, a
      008913                        458 00110$:
                                    459 ;	../src/stm8s_uart1.c: 176: }
      008913 5B 1D            [ 2]  460 	addw	sp, #29
      008915 81               [ 4]  461 	ret
                                    462 ;	../src/stm8s_uart1.c: 184: void UART1_Cmd(FunctionalState NewState)
                                    463 ;	-----------------------------------------
                                    464 ;	 function UART1_Cmd
                                    465 ;	-----------------------------------------
      008916                        466 _UART1_Cmd:
                                    467 ;	../src/stm8s_uart1.c: 189: UART1->CR1 &= (uint8_t)(~UART1_CR1_UARTD); 
      008916 C6 52 34         [ 1]  468 	ld	a, 0x5234
                                    469 ;	../src/stm8s_uart1.c: 186: if (NewState != DISABLE)
      008919 0D 03            [ 1]  470 	tnz	(0x03, sp)
      00891B 27 06            [ 1]  471 	jreq	00102$
                                    472 ;	../src/stm8s_uart1.c: 189: UART1->CR1 &= (uint8_t)(~UART1_CR1_UARTD); 
      00891D A4 DF            [ 1]  473 	and	a, #0xdf
      00891F C7 52 34         [ 1]  474 	ld	0x5234, a
      008922 81               [ 4]  475 	ret
      008923                        476 00102$:
                                    477 ;	../src/stm8s_uart1.c: 194: UART1->CR1 |= UART1_CR1_UARTD;  
      008923 AA 20            [ 1]  478 	or	a, #0x20
      008925 C7 52 34         [ 1]  479 	ld	0x5234, a
                                    480 ;	../src/stm8s_uart1.c: 196: }
      008928 81               [ 4]  481 	ret
                                    482 ;	../src/stm8s_uart1.c: 211: void UART1_ITConfig(UART1_IT_TypeDef UART1_IT, FunctionalState NewState)
                                    483 ;	-----------------------------------------
                                    484 ;	 function UART1_ITConfig
                                    485 ;	-----------------------------------------
      008929                        486 _UART1_ITConfig:
                                    487 ;	../src/stm8s_uart1.c: 259: }
      008929 81               [ 4]  488 	ret
                                    489 ;	../src/stm8s_uart1.c: 267: void UART1_HalfDuplexCmd(FunctionalState NewState)
                                    490 ;	-----------------------------------------
                                    491 ;	 function UART1_HalfDuplexCmd
                                    492 ;	-----------------------------------------
      00892A                        493 _UART1_HalfDuplexCmd:
                                    494 ;	../src/stm8s_uart1.c: 281: }
      00892A 81               [ 4]  495 	ret
                                    496 ;	../src/stm8s_uart1.c: 289: void UART1_IrDAConfig(UART1_IrDAMode_TypeDef UART1_IrDAMode)
                                    497 ;	-----------------------------------------
                                    498 ;	 function UART1_IrDAConfig
                                    499 ;	-----------------------------------------
      00892B                        500 _UART1_IrDAConfig:
                                    501 ;	../src/stm8s_uart1.c: 303: }
      00892B 81               [ 4]  502 	ret
                                    503 ;	../src/stm8s_uart1.c: 311: void UART1_IrDACmd(FunctionalState NewState)
                                    504 ;	-----------------------------------------
                                    505 ;	 function UART1_IrDACmd
                                    506 ;	-----------------------------------------
      00892C                        507 _UART1_IrDACmd:
                                    508 ;	../src/stm8s_uart1.c: 328: }
      00892C 81               [ 4]  509 	ret
                                    510 ;	../src/stm8s_uart1.c: 337: void UART1_LINBreakDetectionConfig(UART1_LINBreakDetectionLength_TypeDef UART1_LINBreakDetectionLength)
                                    511 ;	-----------------------------------------
                                    512 ;	 function UART1_LINBreakDetectionConfig
                                    513 ;	-----------------------------------------
      00892D                        514 _UART1_LINBreakDetectionConfig:
                                    515 ;	../src/stm8s_uart1.c: 351: }
      00892D 81               [ 4]  516 	ret
                                    517 ;	../src/stm8s_uart1.c: 359: void UART1_LINCmd(FunctionalState NewState)
                                    518 ;	-----------------------------------------
                                    519 ;	 function UART1_LINCmd
                                    520 ;	-----------------------------------------
      00892E                        521 _UART1_LINCmd:
                                    522 ;	../src/stm8s_uart1.c: 375: }
      00892E 81               [ 4]  523 	ret
                                    524 ;	../src/stm8s_uart1.c: 383: void UART1_SmartCardCmd(FunctionalState NewState)
                                    525 ;	-----------------------------------------
                                    526 ;	 function UART1_SmartCardCmd
                                    527 ;	-----------------------------------------
      00892F                        528 _UART1_SmartCardCmd:
                                    529 ;	../src/stm8s_uart1.c: 399: }
      00892F 81               [ 4]  530 	ret
                                    531 ;	../src/stm8s_uart1.c: 408: void UART1_SmartCardNACKCmd(FunctionalState NewState)
                                    532 ;	-----------------------------------------
                                    533 ;	 function UART1_SmartCardNACKCmd
                                    534 ;	-----------------------------------------
      008930                        535 _UART1_SmartCardNACKCmd:
                                    536 ;	../src/stm8s_uart1.c: 424: }
      008930 81               [ 4]  537 	ret
                                    538 ;	../src/stm8s_uart1.c: 432: void UART1_WakeUpConfig(UART1_WakeUp_TypeDef UART1_WakeUp)
                                    539 ;	-----------------------------------------
                                    540 ;	 function UART1_WakeUpConfig
                                    541 ;	-----------------------------------------
      008931                        542 _UART1_WakeUpConfig:
                                    543 ;	../src/stm8s_uart1.c: 440: }
      008931 81               [ 4]  544 	ret
                                    545 ;	../src/stm8s_uart1.c: 448: void UART1_ReceiverWakeUpCmd(FunctionalState NewState)
                                    546 ;	-----------------------------------------
                                    547 ;	 function UART1_ReceiverWakeUpCmd
                                    548 ;	-----------------------------------------
      008932                        549 _UART1_ReceiverWakeUpCmd:
                                    550 ;	../src/stm8s_uart1.c: 464: }
      008932 81               [ 4]  551 	ret
                                    552 ;	../src/stm8s_uart1.c: 471: uint8_t UART1_ReceiveData8(void)
                                    553 ;	-----------------------------------------
                                    554 ;	 function UART1_ReceiveData8
                                    555 ;	-----------------------------------------
      008933                        556 _UART1_ReceiveData8:
                                    557 ;	../src/stm8s_uart1.c: 473: return ((uint8_t)UART1->DR);
      008933 C6 52 31         [ 1]  558 	ld	a, 0x5231
                                    559 ;	../src/stm8s_uart1.c: 474: }
      008936 81               [ 4]  560 	ret
                                    561 ;	../src/stm8s_uart1.c: 481: uint16_t UART1_ReceiveData9(void)
                                    562 ;	-----------------------------------------
                                    563 ;	 function UART1_ReceiveData9
                                    564 ;	-----------------------------------------
      008937                        565 _UART1_ReceiveData9:
                                    566 ;	../src/stm8s_uart1.c: 489: }
      008937 81               [ 4]  567 	ret
                                    568 ;	../src/stm8s_uart1.c: 496: void UART1_SendData8(uint8_t Data)
                                    569 ;	-----------------------------------------
                                    570 ;	 function UART1_SendData8
                                    571 ;	-----------------------------------------
      008938                        572 _UART1_SendData8:
                                    573 ;	../src/stm8s_uart1.c: 499: UART1->DR = Data;
      008938 AE 52 31         [ 2]  574 	ldw	x, #0x5231
      00893B 7B 03            [ 1]  575 	ld	a, (0x03, sp)
      00893D F7               [ 1]  576 	ld	(x), a
                                    577 ;	../src/stm8s_uart1.c: 500: }
      00893E 81               [ 4]  578 	ret
                                    579 ;	../src/stm8s_uart1.c: 508: void UART1_SendData9(uint16_t Data)
                                    580 ;	-----------------------------------------
                                    581 ;	 function UART1_SendData9
                                    582 ;	-----------------------------------------
      00893F                        583 _UART1_SendData9:
                                    584 ;	../src/stm8s_uart1.c: 518: }
      00893F 81               [ 4]  585 	ret
                                    586 ;	../src/stm8s_uart1.c: 525: void UART1_SendBreak(void)
                                    587 ;	-----------------------------------------
                                    588 ;	 function UART1_SendBreak
                                    589 ;	-----------------------------------------
      008940                        590 _UART1_SendBreak:
                                    591 ;	../src/stm8s_uart1.c: 530: }
      008940 81               [ 4]  592 	ret
                                    593 ;	../src/stm8s_uart1.c: 537: void UART1_SetAddress(uint8_t UART1_Address)
                                    594 ;	-----------------------------------------
                                    595 ;	 function UART1_SetAddress
                                    596 ;	-----------------------------------------
      008941                        597 _UART1_SetAddress:
                                    598 ;	../src/stm8s_uart1.c: 548: }
      008941 81               [ 4]  599 	ret
                                    600 ;	../src/stm8s_uart1.c: 556: void UART1_SetGuardTime(uint8_t UART1_GuardTime)
                                    601 ;	-----------------------------------------
                                    602 ;	 function UART1_SetGuardTime
                                    603 ;	-----------------------------------------
      008942                        604 _UART1_SetGuardTime:
                                    605 ;	../src/stm8s_uart1.c: 562: }
      008942 81               [ 4]  606 	ret
                                    607 ;	../src/stm8s_uart1.c: 586: void UART1_SetPrescaler(uint8_t UART1_Prescaler)
                                    608 ;	-----------------------------------------
                                    609 ;	 function UART1_SetPrescaler
                                    610 ;	-----------------------------------------
      008943                        611 _UART1_SetPrescaler:
                                    612 ;	../src/stm8s_uart1.c: 592: }
      008943 81               [ 4]  613 	ret
                                    614 ;	../src/stm8s_uart1.c: 600: FlagStatus UART1_GetFlagStatus(UART1_Flag_TypeDef UART1_FLAG)
                                    615 ;	-----------------------------------------
                                    616 ;	 function UART1_GetFlagStatus
                                    617 ;	-----------------------------------------
      008944                        618 _UART1_GetFlagStatus:
      008944 89               [ 2]  619 	pushw	x
                                    620 ;	../src/stm8s_uart1.c: 605: assert_param(IS_UART1_FLAG_OK(UART1_FLAG));
      008945 1E 05            [ 2]  621 	ldw	x, (0x05, sp)
      008947 A3 01 01         [ 2]  622 	cpw	x, #0x0101
      00894A 26 05            [ 1]  623 	jrne	00223$
      00894C A6 01            [ 1]  624 	ld	a, #0x01
      00894E 6B 01            [ 1]  625 	ld	(0x01, sp), a
      008950 C1                     626 	.byte 0xc1
      008951                        627 00223$:
      008951 0F 01            [ 1]  628 	clr	(0x01, sp)
      008953                        629 00224$:
      008953 1E 05            [ 2]  630 	ldw	x, (0x05, sp)
      008955 A3 02 10         [ 2]  631 	cpw	x, #0x0210
      008958 26 03            [ 1]  632 	jrne	00226$
      00895A A6 01            [ 1]  633 	ld	a, #0x01
      00895C 21                     634 	.byte 0x21
      00895D                        635 00226$:
      00895D 4F               [ 1]  636 	clr	a
      00895E                        637 00227$:
      00895E 1E 05            [ 2]  638 	ldw	x, (0x05, sp)
      008960 A3 00 80         [ 2]  639 	cpw	x, #0x0080
      008963 27 47            [ 1]  640 	jreq	00119$
      008965 1E 05            [ 2]  641 	ldw	x, (0x05, sp)
      008967 A3 00 40         [ 2]  642 	cpw	x, #0x0040
      00896A 27 40            [ 1]  643 	jreq	00119$
      00896C 1E 05            [ 2]  644 	ldw	x, (0x05, sp)
      00896E A3 00 20         [ 2]  645 	cpw	x, #0x0020
      008971 27 39            [ 1]  646 	jreq	00119$
      008973 1E 05            [ 2]  647 	ldw	x, (0x05, sp)
      008975 A3 00 10         [ 2]  648 	cpw	x, #0x0010
      008978 27 32            [ 1]  649 	jreq	00119$
      00897A 1E 05            [ 2]  650 	ldw	x, (0x05, sp)
      00897C A3 00 08         [ 2]  651 	cpw	x, #0x0008
      00897F 27 2B            [ 1]  652 	jreq	00119$
      008981 1E 05            [ 2]  653 	ldw	x, (0x05, sp)
      008983 A3 00 04         [ 2]  654 	cpw	x, #0x0004
      008986 27 24            [ 1]  655 	jreq	00119$
      008988 1E 05            [ 2]  656 	ldw	x, (0x05, sp)
      00898A A3 00 02         [ 2]  657 	cpw	x, #0x0002
      00898D 27 1D            [ 1]  658 	jreq	00119$
      00898F 1E 05            [ 2]  659 	ldw	x, (0x05, sp)
      008991 5A               [ 2]  660 	decw	x
      008992 27 18            [ 1]  661 	jreq	00119$
      008994 0D 01            [ 1]  662 	tnz	(0x01, sp)
      008996 26 14            [ 1]  663 	jrne	00119$
      008998 4D               [ 1]  664 	tnz	a
      008999 26 11            [ 1]  665 	jrne	00119$
      00899B 88               [ 1]  666 	push	a
      00899C 4B 5D            [ 1]  667 	push	#0x5d
      00899E 4B 02            [ 1]  668 	push	#0x02
      0089A0 5F               [ 1]  669 	clrw	x
      0089A1 89               [ 2]  670 	pushw	x
      0089A2 4B EF            [ 1]  671 	push	#<___str_0
      0089A4 4B 81            [ 1]  672 	push	#(___str_0 >> 8)
      0089A6 CD 82 CE         [ 4]  673 	call	_assert_failed
      0089A9 5B 06            [ 2]  674 	addw	sp, #6
      0089AB 84               [ 1]  675 	pop	a
      0089AC                        676 00119$:
                                    677 ;	../src/stm8s_uart1.c: 611: if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      0089AC 88               [ 1]  678 	push	a
      0089AD 7B 07            [ 1]  679 	ld	a, (0x07, sp)
      0089AF 6B 03            [ 1]  680 	ld	(0x03, sp), a
      0089B1 84               [ 1]  681 	pop	a
                                    682 ;	../src/stm8s_uart1.c: 609: if (UART1_FLAG == UART1_FLAG_LBDF)
      0089B2 4D               [ 1]  683 	tnz	a
      0089B3 27 0E            [ 1]  684 	jreq	00114$
                                    685 ;	../src/stm8s_uart1.c: 611: if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      0089B5 C6 52 37         [ 1]  686 	ld	a, 0x5237
      0089B8 14 02            [ 1]  687 	and	a, (0x02, sp)
      0089BA 27 04            [ 1]  688 	jreq	00102$
                                    689 ;	../src/stm8s_uart1.c: 614: status = SET;
      0089BC A6 01            [ 1]  690 	ld	a, #0x01
      0089BE 20 20            [ 2]  691 	jra	00115$
      0089C0                        692 00102$:
                                    693 ;	../src/stm8s_uart1.c: 619: status = RESET;
      0089C0 4F               [ 1]  694 	clr	a
      0089C1 20 1D            [ 2]  695 	jra	00115$
      0089C3                        696 00114$:
                                    697 ;	../src/stm8s_uart1.c: 622: else if (UART1_FLAG == UART1_FLAG_SBK)
      0089C3 0D 01            [ 1]  698 	tnz	(0x01, sp)
      0089C5 27 0E            [ 1]  699 	jreq	00111$
                                    700 ;	../src/stm8s_uart1.c: 624: if ((UART1->CR2 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      0089C7 C6 52 35         [ 1]  701 	ld	a, 0x5235
      0089CA 14 02            [ 1]  702 	and	a, (0x02, sp)
      0089CC 27 04            [ 1]  703 	jreq	00105$
                                    704 ;	../src/stm8s_uart1.c: 627: status = SET;
      0089CE A6 01            [ 1]  705 	ld	a, #0x01
      0089D0 20 0E            [ 2]  706 	jra	00115$
      0089D2                        707 00105$:
                                    708 ;	../src/stm8s_uart1.c: 632: status = RESET;
      0089D2 4F               [ 1]  709 	clr	a
      0089D3 20 0B            [ 2]  710 	jra	00115$
      0089D5                        711 00111$:
                                    712 ;	../src/stm8s_uart1.c: 637: if ((UART1->SR & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      0089D5 C6 52 30         [ 1]  713 	ld	a, 0x5230
      0089D8 14 02            [ 1]  714 	and	a, (0x02, sp)
      0089DA 27 03            [ 1]  715 	jreq	00108$
                                    716 ;	../src/stm8s_uart1.c: 640: status = SET;
      0089DC A6 01            [ 1]  717 	ld	a, #0x01
                                    718 ;	../src/stm8s_uart1.c: 645: status = RESET;
      0089DE 21                     719 	.byte 0x21
      0089DF                        720 00108$:
      0089DF 4F               [ 1]  721 	clr	a
      0089E0                        722 00115$:
                                    723 ;	../src/stm8s_uart1.c: 649: return status;
                                    724 ;	../src/stm8s_uart1.c: 650: }
      0089E0 85               [ 2]  725 	popw	x
      0089E1 81               [ 4]  726 	ret
                                    727 ;	../src/stm8s_uart1.c: 678: void UART1_ClearFlag(UART1_Flag_TypeDef UART1_FLAG)
                                    728 ;	-----------------------------------------
                                    729 ;	 function UART1_ClearFlag
                                    730 ;	-----------------------------------------
      0089E2                        731 _UART1_ClearFlag:
                                    732 ;	../src/stm8s_uart1.c: 694: }
      0089E2 81               [ 4]  733 	ret
                                    734 ;	../src/stm8s_uart1.c: 709: ITStatus UART1_GetITStatus(UART1_IT_TypeDef UART1_IT)
                                    735 ;	-----------------------------------------
                                    736 ;	 function UART1_GetITStatus
                                    737 ;	-----------------------------------------
      0089E3                        738 _UART1_GetITStatus:
                                    739 ;	../src/stm8s_uart1.c: 784: return 0;
      0089E3 4F               [ 1]  740 	clr	a
                                    741 ;	../src/stm8s_uart1.c: 785: }
      0089E4 81               [ 4]  742 	ret
                                    743 ;	../src/stm8s_uart1.c: 812: void UART1_ClearITPendingBit(UART1_IT_TypeDef UART1_IT)
                                    744 ;	-----------------------------------------
                                    745 ;	 function UART1_ClearITPendingBit
                                    746 ;	-----------------------------------------
      0089E5                        747 _UART1_ClearITPendingBit:
                                    748 ;	../src/stm8s_uart1.c: 828: }
      0089E5 81               [ 4]  749 	ret
                                    750 	.area CODE
                                    751 	.area CONST
      0081EF                        752 ___str_0:
      0081EF 2E 2E 2F 73 72 63 2F   753 	.ascii "../src/stm8s_uart1.c"
             73 74 6D 38 73 5F 75
             61 72 74 31 2E 63
      008203 00                     754 	.db 0x00
                                    755 	.area INITIALIZER
                                    756 	.area CABS (ABS)
