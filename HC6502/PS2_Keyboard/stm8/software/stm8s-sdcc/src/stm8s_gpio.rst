                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 28 2016) (Linux)
                                      4 ; This file was generated Wed Jan  2 15:12:32 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module stm8s_gpio
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _assert_failed
                                     13 	.globl _GPIO_DeInit
                                     14 	.globl _GPIO_Init
                                     15 	.globl _GPIO_Write
                                     16 	.globl _GPIO_WriteHigh
                                     17 	.globl _GPIO_WriteLow
                                     18 	.globl _GPIO_WriteReverse
                                     19 	.globl _GPIO_ReadOutputData
                                     20 	.globl _GPIO_ReadInputData
                                     21 	.globl _GPIO_ReadInputPin
                                     22 	.globl _GPIO_ExternalPullUpConfig
                                     23 ;--------------------------------------------------------
                                     24 ; ram data
                                     25 ;--------------------------------------------------------
                                     26 	.area DATA
                                     27 ;--------------------------------------------------------
                                     28 ; ram data
                                     29 ;--------------------------------------------------------
                                     30 	.area INITIALIZED
                                     31 ;--------------------------------------------------------
                                     32 ; absolute external ram data
                                     33 ;--------------------------------------------------------
                                     34 	.area DABS (ABS)
                                     35 ;--------------------------------------------------------
                                     36 ; global & static initialisations
                                     37 ;--------------------------------------------------------
                                     38 	.area HOME
                                     39 	.area GSINIT
                                     40 	.area GSFINAL
                                     41 	.area GSINIT
                                     42 ;--------------------------------------------------------
                                     43 ; Home
                                     44 ;--------------------------------------------------------
                                     45 	.area HOME
                                     46 	.area HOME
                                     47 ;--------------------------------------------------------
                                     48 ; code
                                     49 ;--------------------------------------------------------
                                     50 	.area CODE
                                     51 ;	../src/stm8s_gpio.c: 53: void GPIO_DeInit(GPIO_TypeDef* GPIOx)
                                     52 ;	-----------------------------------------
                                     53 ;	 function GPIO_DeInit
                                     54 ;	-----------------------------------------
      008A70                         55 _GPIO_DeInit:
      008A70 89               [ 2]   56 	pushw	x
                                     57 ;	../src/stm8s_gpio.c: 55: GPIOx->ODR = GPIO_ODR_RESET_VALUE; /* Reset Output Data Register */
      008A71 16 05            [ 2]   58 	ldw	y, (0x05, sp)
      008A73 17 01            [ 2]   59 	ldw	(0x01, sp), y
      008A75 1E 01            [ 2]   60 	ldw	x, (0x01, sp)
      008A77 7F               [ 1]   61 	clr	(x)
                                     62 ;	../src/stm8s_gpio.c: 56: GPIOx->DDR = GPIO_DDR_RESET_VALUE; /* Reset Data Direction Register */
      008A78 1E 01            [ 2]   63 	ldw	x, (0x01, sp)
      008A7A 5C               [ 2]   64 	incw	x
      008A7B 5C               [ 2]   65 	incw	x
      008A7C 7F               [ 1]   66 	clr	(x)
                                     67 ;	../src/stm8s_gpio.c: 57: GPIOx->CR1 = GPIO_CR1_RESET_VALUE; /* Reset Control Register 1 */
      008A7D 1E 01            [ 2]   68 	ldw	x, (0x01, sp)
      008A7F 1C 00 03         [ 2]   69 	addw	x, #0x0003
      008A82 7F               [ 1]   70 	clr	(x)
                                     71 ;	../src/stm8s_gpio.c: 58: GPIOx->CR2 = GPIO_CR2_RESET_VALUE; /* Reset Control Register 2 */
      008A83 1E 01            [ 2]   72 	ldw	x, (0x01, sp)
      008A85 1C 00 04         [ 2]   73 	addw	x, #0x0004
      008A88 7F               [ 1]   74 	clr	(x)
      008A89 85               [ 2]   75 	popw	x
      008A8A 81               [ 4]   76 	ret
                                     77 ;	../src/stm8s_gpio.c: 71: void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, GPIO_Mode_TypeDef GPIO_Mode)
                                     78 ;	-----------------------------------------
                                     79 ;	 function GPIO_Init
                                     80 ;	-----------------------------------------
      008A8B                         81 _GPIO_Init:
      008A8B 52 05            [ 2]   82 	sub	sp, #5
                                     83 ;	../src/stm8s_gpio.c: 77: assert_param(IS_GPIO_MODE_OK(GPIO_Mode));
      008A8D 0D 0B            [ 1]   84 	tnz	(0x0b, sp)
      008A8F 27 53            [ 1]   85 	jreq	00116$
      008A91 7B 0B            [ 1]   86 	ld	a, (0x0b, sp)
      008A93 A1 40            [ 1]   87 	cp	a, #0x40
      008A95 27 4D            [ 1]   88 	jreq	00116$
      008A97 7B 0B            [ 1]   89 	ld	a, (0x0b, sp)
      008A99 A1 20            [ 1]   90 	cp	a, #0x20
      008A9B 27 47            [ 1]   91 	jreq	00116$
      008A9D 7B 0B            [ 1]   92 	ld	a, (0x0b, sp)
      008A9F A1 60            [ 1]   93 	cp	a, #0x60
      008AA1 27 41            [ 1]   94 	jreq	00116$
      008AA3 7B 0B            [ 1]   95 	ld	a, (0x0b, sp)
      008AA5 A1 A0            [ 1]   96 	cp	a, #0xa0
      008AA7 27 3B            [ 1]   97 	jreq	00116$
      008AA9 7B 0B            [ 1]   98 	ld	a, (0x0b, sp)
      008AAB A1 E0            [ 1]   99 	cp	a, #0xe0
      008AAD 27 35            [ 1]  100 	jreq	00116$
      008AAF 7B 0B            [ 1]  101 	ld	a, (0x0b, sp)
      008AB1 A1 80            [ 1]  102 	cp	a, #0x80
      008AB3 27 2F            [ 1]  103 	jreq	00116$
      008AB5 7B 0B            [ 1]  104 	ld	a, (0x0b, sp)
      008AB7 A1 C0            [ 1]  105 	cp	a, #0xc0
      008AB9 27 29            [ 1]  106 	jreq	00116$
      008ABB 7B 0B            [ 1]  107 	ld	a, (0x0b, sp)
      008ABD A1 B0            [ 1]  108 	cp	a, #0xb0
      008ABF 27 23            [ 1]  109 	jreq	00116$
      008AC1 7B 0B            [ 1]  110 	ld	a, (0x0b, sp)
      008AC3 A1 F0            [ 1]  111 	cp	a, #0xf0
      008AC5 27 1D            [ 1]  112 	jreq	00116$
      008AC7 7B 0B            [ 1]  113 	ld	a, (0x0b, sp)
      008AC9 A1 90            [ 1]  114 	cp	a, #0x90
      008ACB 27 17            [ 1]  115 	jreq	00116$
      008ACD 7B 0B            [ 1]  116 	ld	a, (0x0b, sp)
      008ACF A1 D0            [ 1]  117 	cp	a, #0xd0
      008AD1 27 11            [ 1]  118 	jreq	00116$
      008AD3 90 AE 8B EC      [ 2]  119 	ldw	y, #___str_0+0
      008AD7 4B 4D            [ 1]  120 	push	#0x4d
      008AD9 5F               [ 1]  121 	clrw	x
      008ADA 89               [ 2]  122 	pushw	x
      008ADB 4B 00            [ 1]  123 	push	#0x00
      008ADD 90 89            [ 2]  124 	pushw	y
      008ADF CD 80 A8         [ 4]  125 	call	_assert_failed
      008AE2 5B 06            [ 2]  126 	addw	sp, #6
      008AE4                        127 00116$:
                                    128 ;	../src/stm8s_gpio.c: 78: assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
      008AE4 0D 0A            [ 1]  129 	tnz	(0x0a, sp)
      008AE6 26 11            [ 1]  130 	jrne	00151$
      008AE8 90 AE 8B EC      [ 2]  131 	ldw	y, #___str_0+0
      008AEC 4B 4E            [ 1]  132 	push	#0x4e
      008AEE 5F               [ 1]  133 	clrw	x
      008AEF 89               [ 2]  134 	pushw	x
      008AF0 4B 00            [ 1]  135 	push	#0x00
      008AF2 90 89            [ 2]  136 	pushw	y
      008AF4 CD 80 A8         [ 4]  137 	call	_assert_failed
      008AF7 5B 06            [ 2]  138 	addw	sp, #6
      008AF9                        139 00151$:
                                    140 ;	../src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008AF9 16 08            [ 2]  141 	ldw	y, (0x08, sp)
      008AFB 17 01            [ 2]  142 	ldw	(0x01, sp), y
      008AFD 1E 01            [ 2]  143 	ldw	x, (0x01, sp)
      008AFF 1C 00 04         [ 2]  144 	addw	x, #0x0004
      008B02 1F 03            [ 2]  145 	ldw	(0x03, sp), x
      008B04 1E 03            [ 2]  146 	ldw	x, (0x03, sp)
      008B06 F6               [ 1]  147 	ld	a, (x)
      008B07 95               [ 1]  148 	ld	xh, a
      008B08 7B 0A            [ 1]  149 	ld	a, (0x0a, sp)
      008B0A 43               [ 1]  150 	cpl	a
      008B0B 6B 05            [ 1]  151 	ld	(0x05, sp), a
      008B0D 9E               [ 1]  152 	ld	a, xh
      008B0E 14 05            [ 1]  153 	and	a, (0x05, sp)
      008B10 1E 03            [ 2]  154 	ldw	x, (0x03, sp)
      008B12 F7               [ 1]  155 	ld	(x), a
                                    156 ;	../src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      008B13 1E 01            [ 2]  157 	ldw	x, (0x01, sp)
      008B15 5C               [ 2]  158 	incw	x
      008B16 5C               [ 2]  159 	incw	x
                                    160 ;	../src/stm8s_gpio.c: 87: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x80) != (uint8_t)0x00) /* Output mode */
      008B17 0D 0B            [ 1]  161 	tnz	(0x0b, sp)
      008B19 2A 20            [ 1]  162 	jrpl	00105$
                                    163 ;	../src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      008B1B 16 01            [ 2]  164 	ldw	y, (0x01, sp)
      008B1D 90 F6            [ 1]  165 	ld	a, (y)
                                    166 ;	../src/stm8s_gpio.c: 89: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x10) != (uint8_t)0x00) /* High level */
      008B1F 88               [ 1]  167 	push	a
      008B20 7B 0C            [ 1]  168 	ld	a, (0x0c, sp)
      008B22 A5 10            [ 1]  169 	bcp	a, #0x10
      008B24 84               [ 1]  170 	pop	a
      008B25 27 08            [ 1]  171 	jreq	00102$
                                    172 ;	../src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      008B27 1A 0A            [ 1]  173 	or	a, (0x0a, sp)
      008B29 16 01            [ 2]  174 	ldw	y, (0x01, sp)
      008B2B 90 F7            [ 1]  175 	ld	(y), a
      008B2D 20 06            [ 2]  176 	jra	00103$
      008B2F                        177 00102$:
                                    178 ;	../src/stm8s_gpio.c: 95: GPIOx->ODR &= (uint8_t)(~(GPIO_Pin));
      008B2F 14 05            [ 1]  179 	and	a, (0x05, sp)
      008B31 16 01            [ 2]  180 	ldw	y, (0x01, sp)
      008B33 90 F7            [ 1]  181 	ld	(y), a
      008B35                        182 00103$:
                                    183 ;	../src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      008B35 F6               [ 1]  184 	ld	a, (x)
      008B36 1A 0A            [ 1]  185 	or	a, (0x0a, sp)
      008B38 F7               [ 1]  186 	ld	(x), a
      008B39 20 04            [ 2]  187 	jra	00106$
      008B3B                        188 00105$:
                                    189 ;	../src/stm8s_gpio.c: 103: GPIOx->DDR &= (uint8_t)(~(GPIO_Pin));
      008B3B F6               [ 1]  190 	ld	a, (x)
      008B3C 14 05            [ 1]  191 	and	a, (0x05, sp)
      008B3E F7               [ 1]  192 	ld	(x), a
      008B3F                        193 00106$:
                                    194 ;	../src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008B3F 1E 01            [ 2]  195 	ldw	x, (0x01, sp)
      008B41 1C 00 03         [ 2]  196 	addw	x, #0x0003
                                    197 ;	../src/stm8s_gpio.c: 110: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x40) != (uint8_t)0x00) /* Pull-Up or Push-Pull */
      008B44 7B 0B            [ 1]  198 	ld	a, (0x0b, sp)
      008B46 A5 40            [ 1]  199 	bcp	a, #0x40
      008B48 27 06            [ 1]  200 	jreq	00108$
                                    201 ;	../src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008B4A F6               [ 1]  202 	ld	a, (x)
      008B4B 1A 0A            [ 1]  203 	or	a, (0x0a, sp)
      008B4D F7               [ 1]  204 	ld	(x), a
      008B4E 20 04            [ 2]  205 	jra	00109$
      008B50                        206 00108$:
                                    207 ;	../src/stm8s_gpio.c: 116: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      008B50 F6               [ 1]  208 	ld	a, (x)
      008B51 14 05            [ 1]  209 	and	a, (0x05, sp)
      008B53 F7               [ 1]  210 	ld	(x), a
      008B54                        211 00109$:
                                    212 ;	../src/stm8s_gpio.c: 123: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x20) != (uint8_t)0x00) /* Interrupt or Slow slope */
      008B54 7B 0B            [ 1]  213 	ld	a, (0x0b, sp)
      008B56 A5 20            [ 1]  214 	bcp	a, #0x20
      008B58 27 0A            [ 1]  215 	jreq	00111$
                                    216 ;	../src/stm8s_gpio.c: 125: GPIOx->CR2 |= (uint8_t)GPIO_Pin;
      008B5A 1E 03            [ 2]  217 	ldw	x, (0x03, sp)
      008B5C F6               [ 1]  218 	ld	a, (x)
      008B5D 1A 0A            [ 1]  219 	or	a, (0x0a, sp)
      008B5F 1E 03            [ 2]  220 	ldw	x, (0x03, sp)
      008B61 F7               [ 1]  221 	ld	(x), a
      008B62 20 08            [ 2]  222 	jra	00113$
      008B64                        223 00111$:
                                    224 ;	../src/stm8s_gpio.c: 129: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008B64 1E 03            [ 2]  225 	ldw	x, (0x03, sp)
      008B66 F6               [ 1]  226 	ld	a, (x)
      008B67 14 05            [ 1]  227 	and	a, (0x05, sp)
      008B69 1E 03            [ 2]  228 	ldw	x, (0x03, sp)
      008B6B F7               [ 1]  229 	ld	(x), a
      008B6C                        230 00113$:
      008B6C 5B 05            [ 2]  231 	addw	sp, #5
      008B6E 81               [ 4]  232 	ret
                                    233 ;	../src/stm8s_gpio.c: 141: void GPIO_Write(GPIO_TypeDef* GPIOx, uint8_t PortVal)
                                    234 ;	-----------------------------------------
                                    235 ;	 function GPIO_Write
                                    236 ;	-----------------------------------------
      008B6F                        237 _GPIO_Write:
                                    238 ;	../src/stm8s_gpio.c: 143: GPIOx->ODR = PortVal;
      008B6F 1E 03            [ 2]  239 	ldw	x, (0x03, sp)
      008B71 7B 05            [ 1]  240 	ld	a, (0x05, sp)
      008B73 F7               [ 1]  241 	ld	(x), a
      008B74 81               [ 4]  242 	ret
                                    243 ;	../src/stm8s_gpio.c: 154: void GPIO_WriteHigh(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    244 ;	-----------------------------------------
                                    245 ;	 function GPIO_WriteHigh
                                    246 ;	-----------------------------------------
      008B75                        247 _GPIO_WriteHigh:
                                    248 ;	../src/stm8s_gpio.c: 156: GPIOx->ODR |= (uint8_t)PortPins;
      008B75 1E 03            [ 2]  249 	ldw	x, (0x03, sp)
      008B77 F6               [ 1]  250 	ld	a, (x)
      008B78 1A 05            [ 1]  251 	or	a, (0x05, sp)
      008B7A F7               [ 1]  252 	ld	(x), a
      008B7B 81               [ 4]  253 	ret
                                    254 ;	../src/stm8s_gpio.c: 167: void GPIO_WriteLow(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    255 ;	-----------------------------------------
                                    256 ;	 function GPIO_WriteLow
                                    257 ;	-----------------------------------------
      008B7C                        258 _GPIO_WriteLow:
      008B7C 88               [ 1]  259 	push	a
                                    260 ;	../src/stm8s_gpio.c: 169: GPIOx->ODR &= (uint8_t)(~PortPins);
      008B7D 1E 04            [ 2]  261 	ldw	x, (0x04, sp)
      008B7F F6               [ 1]  262 	ld	a, (x)
      008B80 6B 01            [ 1]  263 	ld	(0x01, sp), a
      008B82 7B 06            [ 1]  264 	ld	a, (0x06, sp)
      008B84 43               [ 1]  265 	cpl	a
      008B85 14 01            [ 1]  266 	and	a, (0x01, sp)
      008B87 F7               [ 1]  267 	ld	(x), a
      008B88 84               [ 1]  268 	pop	a
      008B89 81               [ 4]  269 	ret
                                    270 ;	../src/stm8s_gpio.c: 180: void GPIO_WriteReverse(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    271 ;	-----------------------------------------
                                    272 ;	 function GPIO_WriteReverse
                                    273 ;	-----------------------------------------
      008B8A                        274 _GPIO_WriteReverse:
                                    275 ;	../src/stm8s_gpio.c: 182: GPIOx->ODR ^= (uint8_t)PortPins;
      008B8A 1E 03            [ 2]  276 	ldw	x, (0x03, sp)
      008B8C F6               [ 1]  277 	ld	a, (x)
      008B8D 18 05            [ 1]  278 	xor	a, (0x05, sp)
      008B8F F7               [ 1]  279 	ld	(x), a
      008B90 81               [ 4]  280 	ret
                                    281 ;	../src/stm8s_gpio.c: 191: uint8_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
                                    282 ;	-----------------------------------------
                                    283 ;	 function GPIO_ReadOutputData
                                    284 ;	-----------------------------------------
      008B91                        285 _GPIO_ReadOutputData:
                                    286 ;	../src/stm8s_gpio.c: 193: return ((uint8_t)GPIOx->ODR);
      008B91 1E 03            [ 2]  287 	ldw	x, (0x03, sp)
      008B93 F6               [ 1]  288 	ld	a, (x)
      008B94 81               [ 4]  289 	ret
                                    290 ;	../src/stm8s_gpio.c: 202: uint8_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
                                    291 ;	-----------------------------------------
                                    292 ;	 function GPIO_ReadInputData
                                    293 ;	-----------------------------------------
      008B95                        294 _GPIO_ReadInputData:
                                    295 ;	../src/stm8s_gpio.c: 204: return ((uint8_t)GPIOx->IDR);
      008B95 1E 03            [ 2]  296 	ldw	x, (0x03, sp)
      008B97 E6 01            [ 1]  297 	ld	a, (0x1, x)
      008B99 81               [ 4]  298 	ret
                                    299 ;	../src/stm8s_gpio.c: 213: BitStatus GPIO_ReadInputPin(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
                                    300 ;	-----------------------------------------
                                    301 ;	 function GPIO_ReadInputPin
                                    302 ;	-----------------------------------------
      008B9A                        303 _GPIO_ReadInputPin:
                                    304 ;	../src/stm8s_gpio.c: 215: return ((BitStatus)(GPIOx->IDR & (uint8_t)GPIO_Pin));
      008B9A 1E 03            [ 2]  305 	ldw	x, (0x03, sp)
      008B9C E6 01            [ 1]  306 	ld	a, (0x1, x)
      008B9E 14 05            [ 1]  307 	and	a, (0x05, sp)
      008BA0 81               [ 4]  308 	ret
                                    309 ;	../src/stm8s_gpio.c: 225: void GPIO_ExternalPullUpConfig(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, FunctionalState NewState)
                                    310 ;	-----------------------------------------
                                    311 ;	 function GPIO_ExternalPullUpConfig
                                    312 ;	-----------------------------------------
      008BA1                        313 _GPIO_ExternalPullUpConfig:
      008BA1 88               [ 1]  314 	push	a
                                    315 ;	../src/stm8s_gpio.c: 228: assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
      008BA2 0D 06            [ 1]  316 	tnz	(0x06, sp)
      008BA4 26 11            [ 1]  317 	jrne	00107$
      008BA6 90 AE 8B EC      [ 2]  318 	ldw	y, #___str_0+0
      008BAA 4B E4            [ 1]  319 	push	#0xe4
      008BAC 5F               [ 1]  320 	clrw	x
      008BAD 89               [ 2]  321 	pushw	x
      008BAE 4B 00            [ 1]  322 	push	#0x00
      008BB0 90 89            [ 2]  323 	pushw	y
      008BB2 CD 80 A8         [ 4]  324 	call	_assert_failed
      008BB5 5B 06            [ 2]  325 	addw	sp, #6
      008BB7                        326 00107$:
                                    327 ;	../src/stm8s_gpio.c: 229: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008BB7 0D 07            [ 1]  328 	tnz	(0x07, sp)
      008BB9 27 17            [ 1]  329 	jreq	00109$
      008BBB 7B 07            [ 1]  330 	ld	a, (0x07, sp)
      008BBD A1 01            [ 1]  331 	cp	a, #0x01
      008BBF 27 11            [ 1]  332 	jreq	00109$
      008BC1 90 AE 8B EC      [ 2]  333 	ldw	y, #___str_0+0
      008BC5 4B E5            [ 1]  334 	push	#0xe5
      008BC7 5F               [ 1]  335 	clrw	x
      008BC8 89               [ 2]  336 	pushw	x
      008BC9 4B 00            [ 1]  337 	push	#0x00
      008BCB 90 89            [ 2]  338 	pushw	y
      008BCD CD 80 A8         [ 4]  339 	call	_assert_failed
      008BD0 5B 06            [ 2]  340 	addw	sp, #6
      008BD2                        341 00109$:
                                    342 ;	../src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008BD2 1E 04            [ 2]  343 	ldw	x, (0x04, sp)
      008BD4 1C 00 03         [ 2]  344 	addw	x, #0x0003
                                    345 ;	../src/stm8s_gpio.c: 231: if (NewState != DISABLE) /* External Pull-Up Set*/
      008BD7 0D 07            [ 1]  346 	tnz	(0x07, sp)
      008BD9 27 06            [ 1]  347 	jreq	00102$
                                    348 ;	../src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008BDB F6               [ 1]  349 	ld	a, (x)
      008BDC 1A 06            [ 1]  350 	or	a, (0x06, sp)
      008BDE F7               [ 1]  351 	ld	(x), a
      008BDF 20 09            [ 2]  352 	jra	00104$
      008BE1                        353 00102$:
                                    354 ;	../src/stm8s_gpio.c: 236: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      008BE1 F6               [ 1]  355 	ld	a, (x)
      008BE2 6B 01            [ 1]  356 	ld	(0x01, sp), a
      008BE4 7B 06            [ 1]  357 	ld	a, (0x06, sp)
      008BE6 43               [ 1]  358 	cpl	a
      008BE7 14 01            [ 1]  359 	and	a, (0x01, sp)
      008BE9 F7               [ 1]  360 	ld	(x), a
      008BEA                        361 00104$:
      008BEA 84               [ 1]  362 	pop	a
      008BEB 81               [ 4]  363 	ret
                                    364 	.area CODE
      008BEC                        365 ___str_0:
      008BEC 2E 2E 2F 73 72 63 2F   366 	.ascii "../src/stm8s_gpio.c"
             73 74 6D 38 73 5F 67
             70 69 6F 2E 63
      008BFF 00                     367 	.db 0x00
                                    368 	.area INITIALIZER
                                    369 	.area CABS (ABS)
