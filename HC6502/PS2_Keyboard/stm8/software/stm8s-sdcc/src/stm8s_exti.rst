                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_exti
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _assert_failed
                                     12 	.globl _EXTI_DeInit
                                     13 	.globl _EXTI_SetExtIntSensitivity
                                     14 	.globl _EXTI_SetTLISensitivity
                                     15 	.globl _EXTI_GetExtIntSensitivity
                                     16 	.globl _EXTI_GetTLISensitivity
                                     17 ;--------------------------------------------------------
                                     18 ; ram data
                                     19 ;--------------------------------------------------------
                                     20 	.area DATA
                                     21 ;--------------------------------------------------------
                                     22 ; ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area INITIALIZED
                                     25 ;--------------------------------------------------------
                                     26 ; absolute external ram data
                                     27 ;--------------------------------------------------------
                                     28 	.area DABS (ABS)
                                     29 
                                     30 ; default segment ordering for linker
                                     31 	.area HOME
                                     32 	.area GSINIT
                                     33 	.area GSFINAL
                                     34 	.area CONST
                                     35 	.area INITIALIZER
                                     36 	.area CODE
                                     37 
                                     38 ;--------------------------------------------------------
                                     39 ; global & static initialisations
                                     40 ;--------------------------------------------------------
                                     41 	.area HOME
                                     42 	.area GSINIT
                                     43 	.area GSFINAL
                                     44 	.area GSINIT
                                     45 ;--------------------------------------------------------
                                     46 ; Home
                                     47 ;--------------------------------------------------------
                                     48 	.area HOME
                                     49 	.area HOME
                                     50 ;--------------------------------------------------------
                                     51 ; code
                                     52 ;--------------------------------------------------------
                                     53 	.area CODE
                                     54 ;	../src/stm8s_exti.c: 53: void EXTI_DeInit(void)
                                     55 ;	-----------------------------------------
                                     56 ;	 function EXTI_DeInit
                                     57 ;	-----------------------------------------
      00920B                         58 _EXTI_DeInit:
                                     59 ;	../src/stm8s_exti.c: 55: EXTI->CR1 = EXTI_CR1_RESET_VALUE;
      00920B 35 00 50 A0      [ 1]   60 	mov	0x50a0+0, #0x00
                                     61 ;	../src/stm8s_exti.c: 56: EXTI->CR2 = EXTI_CR2_RESET_VALUE;
      00920F 35 00 50 A1      [ 1]   62 	mov	0x50a1+0, #0x00
                                     63 ;	../src/stm8s_exti.c: 57: }
      009213 81               [ 4]   64 	ret
                                     65 ;	../src/stm8s_exti.c: 70: void EXTI_SetExtIntSensitivity(EXTI_Port_TypeDef Port, EXTI_Sensitivity_TypeDef SensitivityValue)
                                     66 ;	-----------------------------------------
                                     67 ;	 function EXTI_SetExtIntSensitivity
                                     68 ;	-----------------------------------------
      009214                         69 _EXTI_SetExtIntSensitivity:
      009214 89               [ 2]   70 	pushw	x
                                     71 ;	../src/stm8s_exti.c: 73: assert_param(IS_EXTI_PORT_OK(Port));
      009215 0D 05            [ 1]   72 	tnz	(0x05, sp)
      009217 27 26            [ 1]   73 	jreq	00111$
      009219 7B 05            [ 1]   74 	ld	a, (0x05, sp)
      00921B 4A               [ 1]   75 	dec	a
      00921C 27 21            [ 1]   76 	jreq	00111$
      00921E 7B 05            [ 1]   77 	ld	a, (0x05, sp)
      009220 A1 02            [ 1]   78 	cp	a, #0x02
      009222 27 1B            [ 1]   79 	jreq	00111$
      009224 7B 05            [ 1]   80 	ld	a, (0x05, sp)
      009226 A1 03            [ 1]   81 	cp	a, #0x03
      009228 27 15            [ 1]   82 	jreq	00111$
      00922A 7B 05            [ 1]   83 	ld	a, (0x05, sp)
      00922C A1 04            [ 1]   84 	cp	a, #0x04
      00922E 27 0F            [ 1]   85 	jreq	00111$
      009230 4B 49            [ 1]   86 	push	#0x49
      009232 5F               [ 1]   87 	clrw	x
      009233 89               [ 2]   88 	pushw	x
      009234 4B 00            [ 1]   89 	push	#0x00
      009236 4B 37            [ 1]   90 	push	#<___str_0
      009238 4B 82            [ 1]   91 	push	#(___str_0 >> 8)
      00923A CD 82 CE         [ 4]   92 	call	_assert_failed
      00923D 5B 06            [ 2]   93 	addw	sp, #6
      00923F                         94 00111$:
                                     95 ;	../src/stm8s_exti.c: 74: assert_param(IS_EXTI_SENSITIVITY_OK(SensitivityValue));
      00923F 0D 06            [ 1]   96 	tnz	(0x06, sp)
      009241 27 20            [ 1]   97 	jreq	00125$
      009243 7B 06            [ 1]   98 	ld	a, (0x06, sp)
      009245 4A               [ 1]   99 	dec	a
      009246 27 1B            [ 1]  100 	jreq	00125$
      009248 7B 06            [ 1]  101 	ld	a, (0x06, sp)
      00924A A1 02            [ 1]  102 	cp	a, #0x02
      00924C 27 15            [ 1]  103 	jreq	00125$
      00924E 7B 06            [ 1]  104 	ld	a, (0x06, sp)
      009250 A1 03            [ 1]  105 	cp	a, #0x03
      009252 27 0F            [ 1]  106 	jreq	00125$
      009254 4B 4A            [ 1]  107 	push	#0x4a
      009256 5F               [ 1]  108 	clrw	x
      009257 89               [ 2]  109 	pushw	x
      009258 4B 00            [ 1]  110 	push	#0x00
      00925A 4B 37            [ 1]  111 	push	#<___str_0
      00925C 4B 82            [ 1]  112 	push	#(___str_0 >> 8)
      00925E CD 82 CE         [ 4]  113 	call	_assert_failed
      009261 5B 06            [ 2]  114 	addw	sp, #6
      009263                        115 00125$:
                                    116 ;	../src/stm8s_exti.c: 77: switch (Port)
      009263 7B 05            [ 1]  117 	ld	a, (0x05, sp)
      009265 A1 04            [ 1]  118 	cp	a, #0x04
      009267 23 03            [ 2]  119 	jrule	00208$
      009269 CC 92 F0         [ 2]  120 	jp	00108$
      00926C                        121 00208$:
                                    122 ;	../src/stm8s_exti.c: 85: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 2);
      00926C 7B 06            [ 1]  123 	ld	a, (0x06, sp)
      00926E 90 97            [ 1]  124 	ld	yl, a
                                    125 ;	../src/stm8s_exti.c: 77: switch (Port)
      009270 5F               [ 1]  126 	clrw	x
      009271 7B 05            [ 1]  127 	ld	a, (0x05, sp)
      009273 97               [ 1]  128 	ld	xl, a
      009274 58               [ 2]  129 	sllw	x
      009275 DE 92 79         [ 2]  130 	ldw	x, (#00209$, x)
      009278 FC               [ 2]  131 	jp	(x)
      009279                        132 00209$:
      009279 92 83                  133 	.dw	#00101$
      00927B 92 95                  134 	.dw	#00102$
      00927D 92 AC                  135 	.dw	#00103$
      00927F 92 C5                  136 	.dw	#00104$
      009281 92 E0                  137 	.dw	#00105$
                                    138 ;	../src/stm8s_exti.c: 79: case EXTI_PORT_GPIOA:
      009283                        139 00101$:
                                    140 ;	../src/stm8s_exti.c: 80: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PAIS);
      009283 C6 50 A0         [ 1]  141 	ld	a, 0x50a0
      009286 A4 FC            [ 1]  142 	and	a, #0xfc
      009288 C7 50 A0         [ 1]  143 	ld	0x50a0, a
                                    144 ;	../src/stm8s_exti.c: 81: EXTI->CR1 |= (uint8_t)(SensitivityValue);
      00928B C6 50 A0         [ 1]  145 	ld	a, 0x50a0
      00928E 1A 06            [ 1]  146 	or	a, (0x06, sp)
      009290 C7 50 A0         [ 1]  147 	ld	0x50a0, a
                                    148 ;	../src/stm8s_exti.c: 82: break;
      009293 20 5B            [ 2]  149 	jra	00108$
                                    150 ;	../src/stm8s_exti.c: 83: case EXTI_PORT_GPIOB:
      009295                        151 00102$:
                                    152 ;	../src/stm8s_exti.c: 84: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PBIS);
      009295 C6 50 A0         [ 1]  153 	ld	a, 0x50a0
      009298 A4 F3            [ 1]  154 	and	a, #0xf3
      00929A C7 50 A0         [ 1]  155 	ld	0x50a0, a
                                    156 ;	../src/stm8s_exti.c: 85: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 2);
      00929D C6 50 A0         [ 1]  157 	ld	a, 0x50a0
      0092A0 93               [ 1]  158 	ldw	x, y
      0092A1 58               [ 2]  159 	sllw	x
      0092A2 58               [ 2]  160 	sllw	x
      0092A3 89               [ 2]  161 	pushw	x
      0092A4 1A 02            [ 1]  162 	or	a, (2, sp)
      0092A6 85               [ 2]  163 	popw	x
      0092A7 C7 50 A0         [ 1]  164 	ld	0x50a0, a
                                    165 ;	../src/stm8s_exti.c: 86: break;
      0092AA 20 44            [ 2]  166 	jra	00108$
                                    167 ;	../src/stm8s_exti.c: 87: case EXTI_PORT_GPIOC:
      0092AC                        168 00103$:
                                    169 ;	../src/stm8s_exti.c: 88: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PCIS);
      0092AC C6 50 A0         [ 1]  170 	ld	a, 0x50a0
      0092AF A4 CF            [ 1]  171 	and	a, #0xcf
      0092B1 C7 50 A0         [ 1]  172 	ld	0x50a0, a
                                    173 ;	../src/stm8s_exti.c: 89: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 4);
      0092B4 C6 50 A0         [ 1]  174 	ld	a, 0x50a0
      0092B7 6B 02            [ 1]  175 	ld	(0x02, sp), a
      0092B9 90 9F            [ 1]  176 	ld	a, yl
      0092BB 4E               [ 1]  177 	swap	a
      0092BC A4 F0            [ 1]  178 	and	a, #0xf0
      0092BE 1A 02            [ 1]  179 	or	a, (0x02, sp)
      0092C0 C7 50 A0         [ 1]  180 	ld	0x50a0, a
                                    181 ;	../src/stm8s_exti.c: 90: break;
      0092C3 20 2B            [ 2]  182 	jra	00108$
                                    183 ;	../src/stm8s_exti.c: 91: case EXTI_PORT_GPIOD:
      0092C5                        184 00104$:
                                    185 ;	../src/stm8s_exti.c: 92: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PDIS);
      0092C5 C6 50 A0         [ 1]  186 	ld	a, 0x50a0
      0092C8 A4 3F            [ 1]  187 	and	a, #0x3f
      0092CA C7 50 A0         [ 1]  188 	ld	0x50a0, a
                                    189 ;	../src/stm8s_exti.c: 93: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 6);
      0092CD C6 50 A0         [ 1]  190 	ld	a, 0x50a0
      0092D0 6B 01            [ 1]  191 	ld	(0x01, sp), a
      0092D2 90 9F            [ 1]  192 	ld	a, yl
      0092D4 4E               [ 1]  193 	swap	a
      0092D5 A4 F0            [ 1]  194 	and	a, #0xf0
      0092D7 48               [ 1]  195 	sll	a
      0092D8 48               [ 1]  196 	sll	a
      0092D9 1A 01            [ 1]  197 	or	a, (0x01, sp)
      0092DB C7 50 A0         [ 1]  198 	ld	0x50a0, a
                                    199 ;	../src/stm8s_exti.c: 94: break;
      0092DE 20 10            [ 2]  200 	jra	00108$
                                    201 ;	../src/stm8s_exti.c: 95: case EXTI_PORT_GPIOE:
      0092E0                        202 00105$:
                                    203 ;	../src/stm8s_exti.c: 96: EXTI->CR2 &= (uint8_t)(~EXTI_CR2_PEIS);
      0092E0 C6 50 A1         [ 1]  204 	ld	a, 0x50a1
      0092E3 A4 FC            [ 1]  205 	and	a, #0xfc
      0092E5 C7 50 A1         [ 1]  206 	ld	0x50a1, a
                                    207 ;	../src/stm8s_exti.c: 97: EXTI->CR2 |= (uint8_t)(SensitivityValue);
      0092E8 C6 50 A1         [ 1]  208 	ld	a, 0x50a1
      0092EB 1A 06            [ 1]  209 	or	a, (0x06, sp)
      0092ED C7 50 A1         [ 1]  210 	ld	0x50a1, a
                                    211 ;	../src/stm8s_exti.c: 101: }
      0092F0                        212 00108$:
                                    213 ;	../src/stm8s_exti.c: 102: }
      0092F0 85               [ 2]  214 	popw	x
      0092F1 81               [ 4]  215 	ret
                                    216 ;	../src/stm8s_exti.c: 111: void EXTI_SetTLISensitivity(EXTI_TLISensitivity_TypeDef SensitivityValue)
                                    217 ;	-----------------------------------------
                                    218 ;	 function EXTI_SetTLISensitivity
                                    219 ;	-----------------------------------------
      0092F2                        220 _EXTI_SetTLISensitivity:
                                    221 ;	../src/stm8s_exti.c: 114: assert_param(IS_EXTI_TLISENSITIVITY_OK(SensitivityValue));
      0092F2 0D 03            [ 1]  222 	tnz	(0x03, sp)
      0092F4 27 15            [ 1]  223 	jreq	00104$
      0092F6 7B 03            [ 1]  224 	ld	a, (0x03, sp)
      0092F8 A1 04            [ 1]  225 	cp	a, #0x04
      0092FA 27 0F            [ 1]  226 	jreq	00104$
      0092FC 4B 72            [ 1]  227 	push	#0x72
      0092FE 5F               [ 1]  228 	clrw	x
      0092FF 89               [ 2]  229 	pushw	x
      009300 4B 00            [ 1]  230 	push	#0x00
      009302 4B 37            [ 1]  231 	push	#<___str_0
      009304 4B 82            [ 1]  232 	push	#(___str_0 >> 8)
      009306 CD 82 CE         [ 4]  233 	call	_assert_failed
      009309 5B 06            [ 2]  234 	addw	sp, #6
      00930B                        235 00104$:
                                    236 ;	../src/stm8s_exti.c: 117: EXTI->CR2 &= (uint8_t)(~EXTI_CR2_TLIS);
      00930B C6 50 A1         [ 1]  237 	ld	a, 0x50a1
      00930E A4 FB            [ 1]  238 	and	a, #0xfb
      009310 C7 50 A1         [ 1]  239 	ld	0x50a1, a
                                    240 ;	../src/stm8s_exti.c: 118: EXTI->CR2 |= (uint8_t)(SensitivityValue);
      009313 C6 50 A1         [ 1]  241 	ld	a, 0x50a1
      009316 1A 03            [ 1]  242 	or	a, (0x03, sp)
      009318 C7 50 A1         [ 1]  243 	ld	0x50a1, a
                                    244 ;	../src/stm8s_exti.c: 119: }
      00931B 81               [ 4]  245 	ret
                                    246 ;	../src/stm8s_exti.c: 126: EXTI_Sensitivity_TypeDef EXTI_GetExtIntSensitivity(EXTI_Port_TypeDef Port)
                                    247 ;	-----------------------------------------
                                    248 ;	 function EXTI_GetExtIntSensitivity
                                    249 ;	-----------------------------------------
      00931C                        250 _EXTI_GetExtIntSensitivity:
                                    251 ;	../src/stm8s_exti.c: 128: uint8_t value = 0;
      00931C 4F               [ 1]  252 	clr	a
                                    253 ;	../src/stm8s_exti.c: 131: assert_param(IS_EXTI_PORT_OK(Port));
      00931D 0D 03            [ 1]  254 	tnz	(0x03, sp)
      00931F 27 30            [ 1]  255 	jreq	00111$
      009321 88               [ 1]  256 	push	a
      009322 7B 04            [ 1]  257 	ld	a, (0x04, sp)
      009324 4A               [ 1]  258 	dec	a
      009325 84               [ 1]  259 	pop	a
      009326 27 29            [ 1]  260 	jreq	00111$
      009328 88               [ 1]  261 	push	a
      009329 7B 04            [ 1]  262 	ld	a, (0x04, sp)
      00932B A1 02            [ 1]  263 	cp	a, #0x02
      00932D 84               [ 1]  264 	pop	a
      00932E 27 21            [ 1]  265 	jreq	00111$
      009330 88               [ 1]  266 	push	a
      009331 7B 04            [ 1]  267 	ld	a, (0x04, sp)
      009333 A1 03            [ 1]  268 	cp	a, #0x03
      009335 84               [ 1]  269 	pop	a
      009336 27 19            [ 1]  270 	jreq	00111$
      009338 88               [ 1]  271 	push	a
      009339 7B 04            [ 1]  272 	ld	a, (0x04, sp)
      00933B A1 04            [ 1]  273 	cp	a, #0x04
      00933D 84               [ 1]  274 	pop	a
      00933E 27 11            [ 1]  275 	jreq	00111$
      009340 88               [ 1]  276 	push	a
      009341 4B 83            [ 1]  277 	push	#0x83
      009343 5F               [ 1]  278 	clrw	x
      009344 89               [ 2]  279 	pushw	x
      009345 4B 00            [ 1]  280 	push	#0x00
      009347 4B 37            [ 1]  281 	push	#<___str_0
      009349 4B 82            [ 1]  282 	push	#(___str_0 >> 8)
      00934B CD 82 CE         [ 4]  283 	call	_assert_failed
      00934E 5B 06            [ 2]  284 	addw	sp, #6
      009350 84               [ 1]  285 	pop	a
      009351                        286 00111$:
                                    287 ;	../src/stm8s_exti.c: 133: switch (Port)
      009351 88               [ 1]  288 	push	a
      009352 7B 04            [ 1]  289 	ld	a, (0x04, sp)
      009354 A1 04            [ 1]  290 	cp	a, #0x04
      009356 84               [ 1]  291 	pop	a
      009357 23 01            [ 2]  292 	jrule	00167$
      009359 81               [ 4]  293 	ret
      00935A                        294 00167$:
      00935A 5F               [ 1]  295 	clrw	x
      00935B 7B 03            [ 1]  296 	ld	a, (0x03, sp)
      00935D 97               [ 1]  297 	ld	xl, a
      00935E 58               [ 2]  298 	sllw	x
      00935F DE 93 63         [ 2]  299 	ldw	x, (#00168$, x)
      009362 FC               [ 2]  300 	jp	(x)
      009363                        301 00168$:
      009363 93 6D                  302 	.dw	#00101$
      009365 93 73                  303 	.dw	#00102$
      009367 93 7B                  304 	.dw	#00103$
      009369 93 84                  305 	.dw	#00104$
      00936B 93 8F                  306 	.dw	#00105$
                                    307 ;	../src/stm8s_exti.c: 135: case EXTI_PORT_GPIOA:
      00936D                        308 00101$:
                                    309 ;	../src/stm8s_exti.c: 136: value = (uint8_t)(EXTI->CR1 & EXTI_CR1_PAIS);
      00936D C6 50 A0         [ 1]  310 	ld	a, 0x50a0
      009370 A4 03            [ 1]  311 	and	a, #0x03
                                    312 ;	../src/stm8s_exti.c: 137: break;
      009372 81               [ 4]  313 	ret
                                    314 ;	../src/stm8s_exti.c: 138: case EXTI_PORT_GPIOB:
      009373                        315 00102$:
                                    316 ;	../src/stm8s_exti.c: 139: value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PBIS) >> 2);
      009373 C6 50 A0         [ 1]  317 	ld	a, 0x50a0
      009376 A4 0C            [ 1]  318 	and	a, #0x0c
      009378 44               [ 1]  319 	srl	a
      009379 44               [ 1]  320 	srl	a
                                    321 ;	../src/stm8s_exti.c: 140: break;
      00937A 81               [ 4]  322 	ret
                                    323 ;	../src/stm8s_exti.c: 141: case EXTI_PORT_GPIOC:
      00937B                        324 00103$:
                                    325 ;	../src/stm8s_exti.c: 142: value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PCIS) >> 4);
      00937B C6 50 A0         [ 1]  326 	ld	a, 0x50a0
      00937E A4 30            [ 1]  327 	and	a, #0x30
      009380 4E               [ 1]  328 	swap	a
      009381 A4 0F            [ 1]  329 	and	a, #0x0f
                                    330 ;	../src/stm8s_exti.c: 143: break;
      009383 81               [ 4]  331 	ret
                                    332 ;	../src/stm8s_exti.c: 144: case EXTI_PORT_GPIOD:
      009384                        333 00104$:
                                    334 ;	../src/stm8s_exti.c: 145: value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PDIS) >> 6);
      009384 C6 50 A0         [ 1]  335 	ld	a, 0x50a0
      009387 A4 C0            [ 1]  336 	and	a, #0xc0
      009389 4E               [ 1]  337 	swap	a
      00938A A4 0F            [ 1]  338 	and	a, #0x0f
      00938C 44               [ 1]  339 	srl	a
      00938D 44               [ 1]  340 	srl	a
                                    341 ;	../src/stm8s_exti.c: 146: break;
      00938E 81               [ 4]  342 	ret
                                    343 ;	../src/stm8s_exti.c: 147: case EXTI_PORT_GPIOE:
      00938F                        344 00105$:
                                    345 ;	../src/stm8s_exti.c: 148: value = (uint8_t)(EXTI->CR2 & EXTI_CR2_PEIS);
      00938F C6 50 A1         [ 1]  346 	ld	a, 0x50a1
      009392 A4 03            [ 1]  347 	and	a, #0x03
                                    348 ;	../src/stm8s_exti.c: 152: }
                                    349 ;	../src/stm8s_exti.c: 154: return((EXTI_Sensitivity_TypeDef)value);
                                    350 ;	../src/stm8s_exti.c: 155: }
      009394 81               [ 4]  351 	ret
                                    352 ;	../src/stm8s_exti.c: 162: EXTI_TLISensitivity_TypeDef EXTI_GetTLISensitivity(void)
                                    353 ;	-----------------------------------------
                                    354 ;	 function EXTI_GetTLISensitivity
                                    355 ;	-----------------------------------------
      009395                        356 _EXTI_GetTLISensitivity:
                                    357 ;	../src/stm8s_exti.c: 167: value = (uint8_t)(EXTI->CR2 & EXTI_CR2_TLIS);
      009395 C6 50 A1         [ 1]  358 	ld	a, 0x50a1
      009398 A4 04            [ 1]  359 	and	a, #0x04
                                    360 ;	../src/stm8s_exti.c: 169: return((EXTI_TLISensitivity_TypeDef)value);
                                    361 ;	../src/stm8s_exti.c: 170: }
      00939A 81               [ 4]  362 	ret
                                    363 	.area CODE
                                    364 	.area CONST
      008237                        365 ___str_0:
      008237 2E 2E 2F 73 72 63 2F   366 	.ascii "../src/stm8s_exti.c"
             73 74 6D 38 73 5F 65
             78 74 69 2E 63
      00824A 00                     367 	.db 0x00
                                    368 	.area INITIALIZER
                                    369 	.area CABS (ABS)
