                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 28 2016) (Linux)
                                      4 ; This file was generated Wed Jan  2 15:12:42 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module stm8s_exti
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _assert_failed
                                     13 	.globl _EXTI_DeInit
                                     14 	.globl _EXTI_SetExtIntSensitivity
                                     15 	.globl _EXTI_SetTLISensitivity
                                     16 	.globl _EXTI_GetExtIntSensitivity
                                     17 	.globl _EXTI_GetTLISensitivity
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area DATA
                                     22 ;--------------------------------------------------------
                                     23 ; ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area INITIALIZED
                                     26 ;--------------------------------------------------------
                                     27 ; absolute external ram data
                                     28 ;--------------------------------------------------------
                                     29 	.area DABS (ABS)
                                     30 ;--------------------------------------------------------
                                     31 ; global & static initialisations
                                     32 ;--------------------------------------------------------
                                     33 	.area HOME
                                     34 	.area GSINIT
                                     35 	.area GSFINAL
                                     36 	.area GSINIT
                                     37 ;--------------------------------------------------------
                                     38 ; Home
                                     39 ;--------------------------------------------------------
                                     40 	.area HOME
                                     41 	.area HOME
                                     42 ;--------------------------------------------------------
                                     43 ; code
                                     44 ;--------------------------------------------------------
                                     45 	.area CODE
                                     46 ;	../src/stm8s_exti.c: 53: void EXTI_DeInit(void)
                                     47 ;	-----------------------------------------
                                     48 ;	 function EXTI_DeInit
                                     49 ;	-----------------------------------------
      00938A                         50 _EXTI_DeInit:
                                     51 ;	../src/stm8s_exti.c: 55: EXTI->CR1 = EXTI_CR1_RESET_VALUE;
      00938A 35 00 50 A0      [ 1]   52 	mov	0x50a0+0, #0x00
                                     53 ;	../src/stm8s_exti.c: 56: EXTI->CR2 = EXTI_CR2_RESET_VALUE;
      00938E 35 00 50 A1      [ 1]   54 	mov	0x50a1+0, #0x00
      009392 81               [ 4]   55 	ret
                                     56 ;	../src/stm8s_exti.c: 70: void EXTI_SetExtIntSensitivity(EXTI_Port_TypeDef Port, EXTI_Sensitivity_TypeDef SensitivityValue)
                                     57 ;	-----------------------------------------
                                     58 ;	 function EXTI_SetExtIntSensitivity
                                     59 ;	-----------------------------------------
      009393                         60 _EXTI_SetExtIntSensitivity:
      009393 52 03            [ 2]   61 	sub	sp, #3
                                     62 ;	../src/stm8s_exti.c: 73: assert_param(IS_EXTI_PORT_OK(Port));
      009395 0D 06            [ 1]   63 	tnz	(0x06, sp)
      009397 27 29            [ 1]   64 	jreq	00111$
      009399 7B 06            [ 1]   65 	ld	a, (0x06, sp)
      00939B A1 01            [ 1]   66 	cp	a, #0x01
      00939D 27 23            [ 1]   67 	jreq	00111$
      00939F 7B 06            [ 1]   68 	ld	a, (0x06, sp)
      0093A1 A1 02            [ 1]   69 	cp	a, #0x02
      0093A3 27 1D            [ 1]   70 	jreq	00111$
      0093A5 7B 06            [ 1]   71 	ld	a, (0x06, sp)
      0093A7 A1 03            [ 1]   72 	cp	a, #0x03
      0093A9 27 17            [ 1]   73 	jreq	00111$
      0093AB 7B 06            [ 1]   74 	ld	a, (0x06, sp)
      0093AD A1 04            [ 1]   75 	cp	a, #0x04
      0093AF 27 11            [ 1]   76 	jreq	00111$
      0093B1 90 AE 95 37      [ 2]   77 	ldw	y, #___str_0+0
      0093B5 4B 49            [ 1]   78 	push	#0x49
      0093B7 5F               [ 1]   79 	clrw	x
      0093B8 89               [ 2]   80 	pushw	x
      0093B9 4B 00            [ 1]   81 	push	#0x00
      0093BB 90 89            [ 2]   82 	pushw	y
      0093BD CD 80 A8         [ 4]   83 	call	_assert_failed
      0093C0 5B 06            [ 2]   84 	addw	sp, #6
      0093C2                         85 00111$:
                                     86 ;	../src/stm8s_exti.c: 74: assert_param(IS_EXTI_SENSITIVITY_OK(SensitivityValue));
      0093C2 0D 07            [ 1]   87 	tnz	(0x07, sp)
      0093C4 27 23            [ 1]   88 	jreq	00125$
      0093C6 7B 07            [ 1]   89 	ld	a, (0x07, sp)
      0093C8 A1 01            [ 1]   90 	cp	a, #0x01
      0093CA 27 1D            [ 1]   91 	jreq	00125$
      0093CC 7B 07            [ 1]   92 	ld	a, (0x07, sp)
      0093CE A1 02            [ 1]   93 	cp	a, #0x02
      0093D0 27 17            [ 1]   94 	jreq	00125$
      0093D2 7B 07            [ 1]   95 	ld	a, (0x07, sp)
      0093D4 A1 03            [ 1]   96 	cp	a, #0x03
      0093D6 27 11            [ 1]   97 	jreq	00125$
      0093D8 90 AE 95 37      [ 2]   98 	ldw	y, #___str_0+0
      0093DC 4B 4A            [ 1]   99 	push	#0x4a
      0093DE 5F               [ 1]  100 	clrw	x
      0093DF 89               [ 2]  101 	pushw	x
      0093E0 4B 00            [ 1]  102 	push	#0x00
      0093E2 90 89            [ 2]  103 	pushw	y
      0093E4 CD 80 A8         [ 4]  104 	call	_assert_failed
      0093E7 5B 06            [ 2]  105 	addw	sp, #6
      0093E9                        106 00125$:
                                    107 ;	../src/stm8s_exti.c: 77: switch (Port)
      0093E9 7B 06            [ 1]  108 	ld	a, (0x06, sp)
      0093EB A1 04            [ 1]  109 	cp	a, #0x04
      0093ED 23 03            [ 2]  110 	jrule	00198$
      0093EF CC 94 78         [ 2]  111 	jp	00108$
      0093F2                        112 00198$:
      0093F2 5F               [ 1]  113 	clrw	x
      0093F3 7B 06            [ 1]  114 	ld	a, (0x06, sp)
      0093F5 97               [ 1]  115 	ld	xl, a
      0093F6 58               [ 2]  116 	sllw	x
      0093F7 DE 93 FB         [ 2]  117 	ldw	x, (#00199$, x)
      0093FA FC               [ 2]  118 	jp	(x)
      0093FB                        119 00199$:
      0093FB 94 05                  120 	.dw	#00101$
      0093FD 94 18                  121 	.dw	#00102$
      0093FF 94 31                  122 	.dw	#00103$
      009401 94 4B                  123 	.dw	#00104$
      009403 94 67                  124 	.dw	#00105$
                                    125 ;	../src/stm8s_exti.c: 79: case EXTI_PORT_GPIOA:
      009405                        126 00101$:
                                    127 ;	../src/stm8s_exti.c: 80: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PAIS);
      009405 AE 50 A0         [ 2]  128 	ldw	x, #0x50a0
      009408 F6               [ 1]  129 	ld	a, (x)
      009409 A4 FC            [ 1]  130 	and	a, #0xfc
      00940B F7               [ 1]  131 	ld	(x), a
                                    132 ;	../src/stm8s_exti.c: 81: EXTI->CR1 |= (uint8_t)(SensitivityValue);
      00940C AE 50 A0         [ 2]  133 	ldw	x, #0x50a0
      00940F F6               [ 1]  134 	ld	a, (x)
      009410 1A 07            [ 1]  135 	or	a, (0x07, sp)
      009412 AE 50 A0         [ 2]  136 	ldw	x, #0x50a0
      009415 F7               [ 1]  137 	ld	(x), a
                                    138 ;	../src/stm8s_exti.c: 82: break;
      009416 20 60            [ 2]  139 	jra	00108$
                                    140 ;	../src/stm8s_exti.c: 83: case EXTI_PORT_GPIOB:
      009418                        141 00102$:
                                    142 ;	../src/stm8s_exti.c: 84: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PBIS);
      009418 AE 50 A0         [ 2]  143 	ldw	x, #0x50a0
      00941B F6               [ 1]  144 	ld	a, (x)
      00941C A4 F3            [ 1]  145 	and	a, #0xf3
      00941E F7               [ 1]  146 	ld	(x), a
                                    147 ;	../src/stm8s_exti.c: 85: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 2);
      00941F AE 50 A0         [ 2]  148 	ldw	x, #0x50a0
      009422 F6               [ 1]  149 	ld	a, (x)
      009423 6B 01            [ 1]  150 	ld	(0x01, sp), a
      009425 7B 07            [ 1]  151 	ld	a, (0x07, sp)
      009427 48               [ 1]  152 	sll	a
      009428 48               [ 1]  153 	sll	a
      009429 1A 01            [ 1]  154 	or	a, (0x01, sp)
      00942B AE 50 A0         [ 2]  155 	ldw	x, #0x50a0
      00942E F7               [ 1]  156 	ld	(x), a
                                    157 ;	../src/stm8s_exti.c: 86: break;
      00942F 20 47            [ 2]  158 	jra	00108$
                                    159 ;	../src/stm8s_exti.c: 87: case EXTI_PORT_GPIOC:
      009431                        160 00103$:
                                    161 ;	../src/stm8s_exti.c: 88: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PCIS);
      009431 AE 50 A0         [ 2]  162 	ldw	x, #0x50a0
      009434 F6               [ 1]  163 	ld	a, (x)
      009435 A4 CF            [ 1]  164 	and	a, #0xcf
      009437 F7               [ 1]  165 	ld	(x), a
                                    166 ;	../src/stm8s_exti.c: 89: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 4);
      009438 AE 50 A0         [ 2]  167 	ldw	x, #0x50a0
      00943B F6               [ 1]  168 	ld	a, (x)
      00943C 6B 03            [ 1]  169 	ld	(0x03, sp), a
      00943E 7B 07            [ 1]  170 	ld	a, (0x07, sp)
      009440 4E               [ 1]  171 	swap	a
      009441 A4 F0            [ 1]  172 	and	a, #0xf0
      009443 1A 03            [ 1]  173 	or	a, (0x03, sp)
      009445 AE 50 A0         [ 2]  174 	ldw	x, #0x50a0
      009448 F7               [ 1]  175 	ld	(x), a
                                    176 ;	../src/stm8s_exti.c: 90: break;
      009449 20 2D            [ 2]  177 	jra	00108$
                                    178 ;	../src/stm8s_exti.c: 91: case EXTI_PORT_GPIOD:
      00944B                        179 00104$:
                                    180 ;	../src/stm8s_exti.c: 92: EXTI->CR1 &= (uint8_t)(~EXTI_CR1_PDIS);
      00944B AE 50 A0         [ 2]  181 	ldw	x, #0x50a0
      00944E F6               [ 1]  182 	ld	a, (x)
      00944F A4 3F            [ 1]  183 	and	a, #0x3f
      009451 F7               [ 1]  184 	ld	(x), a
                                    185 ;	../src/stm8s_exti.c: 93: EXTI->CR1 |= (uint8_t)((uint8_t)(SensitivityValue) << 6);
      009452 AE 50 A0         [ 2]  186 	ldw	x, #0x50a0
      009455 F6               [ 1]  187 	ld	a, (x)
      009456 6B 02            [ 1]  188 	ld	(0x02, sp), a
      009458 7B 07            [ 1]  189 	ld	a, (0x07, sp)
      00945A 4E               [ 1]  190 	swap	a
      00945B A4 F0            [ 1]  191 	and	a, #0xf0
      00945D 48               [ 1]  192 	sll	a
      00945E 48               [ 1]  193 	sll	a
      00945F 1A 02            [ 1]  194 	or	a, (0x02, sp)
      009461 AE 50 A0         [ 2]  195 	ldw	x, #0x50a0
      009464 F7               [ 1]  196 	ld	(x), a
                                    197 ;	../src/stm8s_exti.c: 94: break;
      009465 20 11            [ 2]  198 	jra	00108$
                                    199 ;	../src/stm8s_exti.c: 95: case EXTI_PORT_GPIOE:
      009467                        200 00105$:
                                    201 ;	../src/stm8s_exti.c: 96: EXTI->CR2 &= (uint8_t)(~EXTI_CR2_PEIS);
      009467 AE 50 A1         [ 2]  202 	ldw	x, #0x50a1
      00946A F6               [ 1]  203 	ld	a, (x)
      00946B A4 FC            [ 1]  204 	and	a, #0xfc
      00946D F7               [ 1]  205 	ld	(x), a
                                    206 ;	../src/stm8s_exti.c: 97: EXTI->CR2 |= (uint8_t)(SensitivityValue);
      00946E AE 50 A1         [ 2]  207 	ldw	x, #0x50a1
      009471 F6               [ 1]  208 	ld	a, (x)
      009472 1A 07            [ 1]  209 	or	a, (0x07, sp)
      009474 AE 50 A1         [ 2]  210 	ldw	x, #0x50a1
      009477 F7               [ 1]  211 	ld	(x), a
                                    212 ;	../src/stm8s_exti.c: 101: }
      009478                        213 00108$:
      009478 5B 03            [ 2]  214 	addw	sp, #3
      00947A 81               [ 4]  215 	ret
                                    216 ;	../src/stm8s_exti.c: 111: void EXTI_SetTLISensitivity(EXTI_TLISensitivity_TypeDef SensitivityValue)
                                    217 ;	-----------------------------------------
                                    218 ;	 function EXTI_SetTLISensitivity
                                    219 ;	-----------------------------------------
      00947B                        220 _EXTI_SetTLISensitivity:
                                    221 ;	../src/stm8s_exti.c: 114: assert_param(IS_EXTI_TLISENSITIVITY_OK(SensitivityValue));
      00947B 0D 03            [ 1]  222 	tnz	(0x03, sp)
      00947D 27 17            [ 1]  223 	jreq	00104$
      00947F 7B 03            [ 1]  224 	ld	a, (0x03, sp)
      009481 A1 04            [ 1]  225 	cp	a, #0x04
      009483 27 11            [ 1]  226 	jreq	00104$
      009485 90 AE 95 37      [ 2]  227 	ldw	y, #___str_0+0
      009489 4B 72            [ 1]  228 	push	#0x72
      00948B 5F               [ 1]  229 	clrw	x
      00948C 89               [ 2]  230 	pushw	x
      00948D 4B 00            [ 1]  231 	push	#0x00
      00948F 90 89            [ 2]  232 	pushw	y
      009491 CD 80 A8         [ 4]  233 	call	_assert_failed
      009494 5B 06            [ 2]  234 	addw	sp, #6
      009496                        235 00104$:
                                    236 ;	../src/stm8s_exti.c: 117: EXTI->CR2 &= (uint8_t)(~EXTI_CR2_TLIS);
      009496 AE 50 A1         [ 2]  237 	ldw	x, #0x50a1
      009499 F6               [ 1]  238 	ld	a, (x)
      00949A A4 FB            [ 1]  239 	and	a, #0xfb
      00949C F7               [ 1]  240 	ld	(x), a
                                    241 ;	../src/stm8s_exti.c: 118: EXTI->CR2 |= (uint8_t)(SensitivityValue);
      00949D AE 50 A1         [ 2]  242 	ldw	x, #0x50a1
      0094A0 F6               [ 1]  243 	ld	a, (x)
      0094A1 1A 03            [ 1]  244 	or	a, (0x03, sp)
      0094A3 AE 50 A1         [ 2]  245 	ldw	x, #0x50a1
      0094A6 F7               [ 1]  246 	ld	(x), a
      0094A7 81               [ 4]  247 	ret
                                    248 ;	../src/stm8s_exti.c: 126: EXTI_Sensitivity_TypeDef EXTI_GetExtIntSensitivity(EXTI_Port_TypeDef Port)
                                    249 ;	-----------------------------------------
                                    250 ;	 function EXTI_GetExtIntSensitivity
                                    251 ;	-----------------------------------------
      0094A8                        252 _EXTI_GetExtIntSensitivity:
      0094A8 88               [ 1]  253 	push	a
                                    254 ;	../src/stm8s_exti.c: 128: uint8_t value = 0;
      0094A9 0F 01            [ 1]  255 	clr	(0x01, sp)
                                    256 ;	../src/stm8s_exti.c: 131: assert_param(IS_EXTI_PORT_OK(Port));
      0094AB 0D 04            [ 1]  257 	tnz	(0x04, sp)
      0094AD 27 29            [ 1]  258 	jreq	00111$
      0094AF 7B 04            [ 1]  259 	ld	a, (0x04, sp)
      0094B1 A1 01            [ 1]  260 	cp	a, #0x01
      0094B3 27 23            [ 1]  261 	jreq	00111$
      0094B5 7B 04            [ 1]  262 	ld	a, (0x04, sp)
      0094B7 A1 02            [ 1]  263 	cp	a, #0x02
      0094B9 27 1D            [ 1]  264 	jreq	00111$
      0094BB 7B 04            [ 1]  265 	ld	a, (0x04, sp)
      0094BD A1 03            [ 1]  266 	cp	a, #0x03
      0094BF 27 17            [ 1]  267 	jreq	00111$
      0094C1 7B 04            [ 1]  268 	ld	a, (0x04, sp)
      0094C3 A1 04            [ 1]  269 	cp	a, #0x04
      0094C5 27 11            [ 1]  270 	jreq	00111$
      0094C7 90 AE 95 37      [ 2]  271 	ldw	y, #___str_0+0
      0094CB 4B 83            [ 1]  272 	push	#0x83
      0094CD 5F               [ 1]  273 	clrw	x
      0094CE 89               [ 2]  274 	pushw	x
      0094CF 4B 00            [ 1]  275 	push	#0x00
      0094D1 90 89            [ 2]  276 	pushw	y
      0094D3 CD 80 A8         [ 4]  277 	call	_assert_failed
      0094D6 5B 06            [ 2]  278 	addw	sp, #6
      0094D8                        279 00111$:
                                    280 ;	../src/stm8s_exti.c: 133: switch (Port)
      0094D8 7B 04            [ 1]  281 	ld	a, (0x04, sp)
      0094DA A1 04            [ 1]  282 	cp	a, #0x04
      0094DC 22 4D            [ 1]  283 	jrugt	00107$
      0094DE 5F               [ 1]  284 	clrw	x
      0094DF 7B 04            [ 1]  285 	ld	a, (0x04, sp)
      0094E1 97               [ 1]  286 	ld	xl, a
      0094E2 58               [ 2]  287 	sllw	x
      0094E3 DE 94 E7         [ 2]  288 	ldw	x, (#00162$, x)
      0094E6 FC               [ 2]  289 	jp	(x)
      0094E7                        290 00162$:
      0094E7 94 F1                  291 	.dw	#00101$
      0094E9 94 FB                  292 	.dw	#00102$
      0094EB 95 07                  293 	.dw	#00103$
      0094ED 95 14                  294 	.dw	#00104$
      0094EF 95 23                  295 	.dw	#00105$
                                    296 ;	../src/stm8s_exti.c: 135: case EXTI_PORT_GPIOA:
      0094F1                        297 00101$:
                                    298 ;	../src/stm8s_exti.c: 136: value = (uint8_t)(EXTI->CR1 & EXTI_CR1_PAIS);
      0094F1 AE 50 A0         [ 2]  299 	ldw	x, #0x50a0
      0094F4 F6               [ 1]  300 	ld	a, (x)
      0094F5 A4 03            [ 1]  301 	and	a, #0x03
      0094F7 6B 01            [ 1]  302 	ld	(0x01, sp), a
                                    303 ;	../src/stm8s_exti.c: 137: break;
      0094F9 20 30            [ 2]  304 	jra	00107$
                                    305 ;	../src/stm8s_exti.c: 138: case EXTI_PORT_GPIOB:
      0094FB                        306 00102$:
                                    307 ;	../src/stm8s_exti.c: 139: value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PBIS) >> 2);
      0094FB AE 50 A0         [ 2]  308 	ldw	x, #0x50a0
      0094FE F6               [ 1]  309 	ld	a, (x)
      0094FF A4 0C            [ 1]  310 	and	a, #0x0c
      009501 44               [ 1]  311 	srl	a
      009502 44               [ 1]  312 	srl	a
      009503 6B 01            [ 1]  313 	ld	(0x01, sp), a
                                    314 ;	../src/stm8s_exti.c: 140: break;
      009505 20 24            [ 2]  315 	jra	00107$
                                    316 ;	../src/stm8s_exti.c: 141: case EXTI_PORT_GPIOC:
      009507                        317 00103$:
                                    318 ;	../src/stm8s_exti.c: 142: value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PCIS) >> 4);
      009507 AE 50 A0         [ 2]  319 	ldw	x, #0x50a0
      00950A F6               [ 1]  320 	ld	a, (x)
      00950B A4 30            [ 1]  321 	and	a, #0x30
      00950D 4E               [ 1]  322 	swap	a
      00950E A4 0F            [ 1]  323 	and	a, #0x0f
      009510 6B 01            [ 1]  324 	ld	(0x01, sp), a
                                    325 ;	../src/stm8s_exti.c: 143: break;
      009512 20 17            [ 2]  326 	jra	00107$
                                    327 ;	../src/stm8s_exti.c: 144: case EXTI_PORT_GPIOD:
      009514                        328 00104$:
                                    329 ;	../src/stm8s_exti.c: 145: value = (uint8_t)((uint8_t)(EXTI->CR1 & EXTI_CR1_PDIS) >> 6);
      009514 AE 50 A0         [ 2]  330 	ldw	x, #0x50a0
      009517 F6               [ 1]  331 	ld	a, (x)
      009518 A4 C0            [ 1]  332 	and	a, #0xc0
      00951A 4E               [ 1]  333 	swap	a
      00951B A4 0F            [ 1]  334 	and	a, #0x0f
      00951D 44               [ 1]  335 	srl	a
      00951E 44               [ 1]  336 	srl	a
      00951F 6B 01            [ 1]  337 	ld	(0x01, sp), a
                                    338 ;	../src/stm8s_exti.c: 146: break;
      009521 20 08            [ 2]  339 	jra	00107$
                                    340 ;	../src/stm8s_exti.c: 147: case EXTI_PORT_GPIOE:
      009523                        341 00105$:
                                    342 ;	../src/stm8s_exti.c: 148: value = (uint8_t)(EXTI->CR2 & EXTI_CR2_PEIS);
      009523 AE 50 A1         [ 2]  343 	ldw	x, #0x50a1
      009526 F6               [ 1]  344 	ld	a, (x)
      009527 A4 03            [ 1]  345 	and	a, #0x03
      009529 6B 01            [ 1]  346 	ld	(0x01, sp), a
                                    347 ;	../src/stm8s_exti.c: 152: }
      00952B                        348 00107$:
                                    349 ;	../src/stm8s_exti.c: 154: return((EXTI_Sensitivity_TypeDef)value);
      00952B 7B 01            [ 1]  350 	ld	a, (0x01, sp)
      00952D 5B 01            [ 2]  351 	addw	sp, #1
      00952F 81               [ 4]  352 	ret
                                    353 ;	../src/stm8s_exti.c: 162: EXTI_TLISensitivity_TypeDef EXTI_GetTLISensitivity(void)
                                    354 ;	-----------------------------------------
                                    355 ;	 function EXTI_GetTLISensitivity
                                    356 ;	-----------------------------------------
      009530                        357 _EXTI_GetTLISensitivity:
                                    358 ;	../src/stm8s_exti.c: 167: value = (uint8_t)(EXTI->CR2 & EXTI_CR2_TLIS);
      009530 AE 50 A1         [ 2]  359 	ldw	x, #0x50a1
      009533 F6               [ 1]  360 	ld	a, (x)
      009534 A4 04            [ 1]  361 	and	a, #0x04
                                    362 ;	../src/stm8s_exti.c: 169: return((EXTI_TLISensitivity_TypeDef)value);
      009536 81               [ 4]  363 	ret
                                    364 	.area CODE
      009537                        365 ___str_0:
      009537 2E 2E 2F 73 72 63 2F   366 	.ascii "../src/stm8s_exti.c"
             73 74 6D 38 73 5F 65
             78 74 69 2E 63
      00954A 00                     367 	.db 0x00
                                    368 	.area INITIALIZER
                                    369 	.area CABS (ABS)
