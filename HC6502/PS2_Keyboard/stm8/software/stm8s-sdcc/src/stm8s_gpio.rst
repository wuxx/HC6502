                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_gpio
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _assert_failed
                                     12 	.globl _GPIO_DeInit
                                     13 	.globl _GPIO_Init
                                     14 	.globl _GPIO_Write
                                     15 	.globl _GPIO_WriteHigh
                                     16 	.globl _GPIO_WriteLow
                                     17 	.globl _GPIO_WriteReverse
                                     18 	.globl _GPIO_ReadOutputData
                                     19 	.globl _GPIO_ReadInputData
                                     20 	.globl _GPIO_ReadInputPin
                                     21 	.globl _GPIO_ExternalPullUpConfig
                                     22 ;--------------------------------------------------------
                                     23 ; ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area DATA
                                     26 ;--------------------------------------------------------
                                     27 ; ram data
                                     28 ;--------------------------------------------------------
                                     29 	.area INITIALIZED
                                     30 ;--------------------------------------------------------
                                     31 ; absolute external ram data
                                     32 ;--------------------------------------------------------
                                     33 	.area DABS (ABS)
                                     34 
                                     35 ; default segment ordering for linker
                                     36 	.area HOME
                                     37 	.area GSINIT
                                     38 	.area GSFINAL
                                     39 	.area CONST
                                     40 	.area INITIALIZER
                                     41 	.area CODE
                                     42 
                                     43 ;--------------------------------------------------------
                                     44 ; global & static initialisations
                                     45 ;--------------------------------------------------------
                                     46 	.area HOME
                                     47 	.area GSINIT
                                     48 	.area GSFINAL
                                     49 	.area GSINIT
                                     50 ;--------------------------------------------------------
                                     51 ; Home
                                     52 ;--------------------------------------------------------
                                     53 	.area HOME
                                     54 	.area HOME
                                     55 ;--------------------------------------------------------
                                     56 ; code
                                     57 ;--------------------------------------------------------
                                     58 	.area CODE
                                     59 ;	../src/stm8s_gpio.c: 53: void GPIO_DeInit(GPIO_TypeDef* GPIOx)
                                     60 ;	-----------------------------------------
                                     61 ;	 function GPIO_DeInit
                                     62 ;	-----------------------------------------
      0089E6                         63 _GPIO_DeInit:
                                     64 ;	../src/stm8s_gpio.c: 55: GPIOx->ODR = GPIO_ODR_RESET_VALUE; /* Reset Output Data Register */
      0089E6 16 03            [ 2]   65 	ldw	y, (0x03, sp)
      0089E8 90 7F            [ 1]   66 	clr	(y)
                                     67 ;	../src/stm8s_gpio.c: 56: GPIOx->DDR = GPIO_DDR_RESET_VALUE; /* Reset Data Direction Register */
      0089EA 93               [ 1]   68 	ldw	x, y
      0089EB 5C               [ 1]   69 	incw	x
      0089EC 5C               [ 1]   70 	incw	x
      0089ED 7F               [ 1]   71 	clr	(x)
                                     72 ;	../src/stm8s_gpio.c: 57: GPIOx->CR1 = GPIO_CR1_RESET_VALUE; /* Reset Control Register 1 */
      0089EE 93               [ 1]   73 	ldw	x, y
      0089EF 6F 03            [ 1]   74 	clr	(0x0003, x)
                                     75 ;	../src/stm8s_gpio.c: 58: GPIOx->CR2 = GPIO_CR2_RESET_VALUE; /* Reset Control Register 2 */
      0089F1 93               [ 1]   76 	ldw	x, y
      0089F2 6F 04            [ 1]   77 	clr	(0x0004, x)
                                     78 ;	../src/stm8s_gpio.c: 59: }
      0089F4 81               [ 4]   79 	ret
                                     80 ;	../src/stm8s_gpio.c: 71: void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, GPIO_Mode_TypeDef GPIO_Mode)
                                     81 ;	-----------------------------------------
                                     82 ;	 function GPIO_Init
                                     83 ;	-----------------------------------------
      0089F5                         84 _GPIO_Init:
      0089F5 52 05            [ 2]   85 	sub	sp, #5
                                     86 ;	../src/stm8s_gpio.c: 77: assert_param(IS_GPIO_MODE_OK(GPIO_Mode));
      0089F7 0D 0B            [ 1]   87 	tnz	(0x0b, sp)
      0089F9 27 51            [ 1]   88 	jreq	00116$
      0089FB 7B 0B            [ 1]   89 	ld	a, (0x0b, sp)
      0089FD A1 40            [ 1]   90 	cp	a, #0x40
      0089FF 27 4B            [ 1]   91 	jreq	00116$
      008A01 7B 0B            [ 1]   92 	ld	a, (0x0b, sp)
      008A03 A1 20            [ 1]   93 	cp	a, #0x20
      008A05 27 45            [ 1]   94 	jreq	00116$
      008A07 7B 0B            [ 1]   95 	ld	a, (0x0b, sp)
      008A09 A1 60            [ 1]   96 	cp	a, #0x60
      008A0B 27 3F            [ 1]   97 	jreq	00116$
      008A0D 7B 0B            [ 1]   98 	ld	a, (0x0b, sp)
      008A0F A1 A0            [ 1]   99 	cp	a, #0xa0
      008A11 27 39            [ 1]  100 	jreq	00116$
      008A13 7B 0B            [ 1]  101 	ld	a, (0x0b, sp)
      008A15 A1 E0            [ 1]  102 	cp	a, #0xe0
      008A17 27 33            [ 1]  103 	jreq	00116$
      008A19 7B 0B            [ 1]  104 	ld	a, (0x0b, sp)
      008A1B A1 80            [ 1]  105 	cp	a, #0x80
      008A1D 27 2D            [ 1]  106 	jreq	00116$
      008A1F 7B 0B            [ 1]  107 	ld	a, (0x0b, sp)
      008A21 A1 C0            [ 1]  108 	cp	a, #0xc0
      008A23 27 27            [ 1]  109 	jreq	00116$
      008A25 7B 0B            [ 1]  110 	ld	a, (0x0b, sp)
      008A27 A1 B0            [ 1]  111 	cp	a, #0xb0
      008A29 27 21            [ 1]  112 	jreq	00116$
      008A2B 7B 0B            [ 1]  113 	ld	a, (0x0b, sp)
      008A2D A1 F0            [ 1]  114 	cp	a, #0xf0
      008A2F 27 1B            [ 1]  115 	jreq	00116$
      008A31 7B 0B            [ 1]  116 	ld	a, (0x0b, sp)
      008A33 A1 90            [ 1]  117 	cp	a, #0x90
      008A35 27 15            [ 1]  118 	jreq	00116$
      008A37 7B 0B            [ 1]  119 	ld	a, (0x0b, sp)
      008A39 A1 D0            [ 1]  120 	cp	a, #0xd0
      008A3B 27 0F            [ 1]  121 	jreq	00116$
      008A3D 4B 4D            [ 1]  122 	push	#0x4d
      008A3F 5F               [ 1]  123 	clrw	x
      008A40 89               [ 2]  124 	pushw	x
      008A41 4B 00            [ 1]  125 	push	#0x00
      008A43 4B 04            [ 1]  126 	push	#<___str_0
      008A45 4B 82            [ 1]  127 	push	#(___str_0 >> 8)
      008A47 CD 82 CE         [ 4]  128 	call	_assert_failed
      008A4A 5B 06            [ 2]  129 	addw	sp, #6
      008A4C                        130 00116$:
                                    131 ;	../src/stm8s_gpio.c: 78: assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
      008A4C 0D 0A            [ 1]  132 	tnz	(0x0a, sp)
      008A4E 26 0F            [ 1]  133 	jrne	00151$
      008A50 4B 4E            [ 1]  134 	push	#0x4e
      008A52 5F               [ 1]  135 	clrw	x
      008A53 89               [ 2]  136 	pushw	x
      008A54 4B 00            [ 1]  137 	push	#0x00
      008A56 4B 04            [ 1]  138 	push	#<___str_0
      008A58 4B 82            [ 1]  139 	push	#(___str_0 >> 8)
      008A5A CD 82 CE         [ 4]  140 	call	_assert_failed
      008A5D 5B 06            [ 2]  141 	addw	sp, #6
      008A5F                        142 00151$:
                                    143 ;	../src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008A5F 16 08            [ 2]  144 	ldw	y, (0x08, sp)
      008A61 93               [ 1]  145 	ldw	x, y
      008A62 1C 00 04         [ 2]  146 	addw	x, #0x0004
      008A65 1F 02            [ 2]  147 	ldw	(0x02, sp), x
      008A67 F6               [ 1]  148 	ld	a, (x)
      008A68 88               [ 1]  149 	push	a
      008A69 7B 0B            [ 1]  150 	ld	a, (0x0b, sp)
      008A6B 43               [ 1]  151 	cpl	a
      008A6C 6B 02            [ 1]  152 	ld	(0x02, sp), a
      008A6E 84               [ 1]  153 	pop	a
      008A6F 14 01            [ 1]  154 	and	a, (0x01, sp)
      008A71 1E 02            [ 2]  155 	ldw	x, (0x02, sp)
      008A73 F7               [ 1]  156 	ld	(x), a
                                    157 ;	../src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      008A74 93               [ 1]  158 	ldw	x, y
      008A75 5C               [ 1]  159 	incw	x
      008A76 5C               [ 1]  160 	incw	x
      008A77 1F 04            [ 2]  161 	ldw	(0x04, sp), x
                                    162 ;	../src/stm8s_gpio.c: 87: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x80) != (uint8_t)0x00) /* Output mode */
      008A79 0D 0B            [ 1]  163 	tnz	(0x0b, sp)
      008A7B 2A 1E            [ 1]  164 	jrpl	00105$
                                    165 ;	../src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      008A7D 90 F6            [ 1]  166 	ld	a, (y)
                                    167 ;	../src/stm8s_gpio.c: 89: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x10) != (uint8_t)0x00) /* High level */
      008A7F 88               [ 1]  168 	push	a
      008A80 7B 0C            [ 1]  169 	ld	a, (0x0c, sp)
      008A82 A5 10            [ 1]  170 	bcp	a, #0x10
      008A84 84               [ 1]  171 	pop	a
      008A85 27 06            [ 1]  172 	jreq	00102$
                                    173 ;	../src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      008A87 1A 0A            [ 1]  174 	or	a, (0x0a, sp)
      008A89 90 F7            [ 1]  175 	ld	(y), a
      008A8B 20 04            [ 2]  176 	jra	00103$
      008A8D                        177 00102$:
                                    178 ;	../src/stm8s_gpio.c: 95: GPIOx->ODR &= (uint8_t)(~(GPIO_Pin));
      008A8D 14 01            [ 1]  179 	and	a, (0x01, sp)
      008A8F 90 F7            [ 1]  180 	ld	(y), a
      008A91                        181 00103$:
                                    182 ;	../src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      008A91 1E 04            [ 2]  183 	ldw	x, (0x04, sp)
      008A93 F6               [ 1]  184 	ld	a, (x)
      008A94 1A 0A            [ 1]  185 	or	a, (0x0a, sp)
      008A96 1E 04            [ 2]  186 	ldw	x, (0x04, sp)
      008A98 F7               [ 1]  187 	ld	(x), a
      008A99 20 08            [ 2]  188 	jra	00106$
      008A9B                        189 00105$:
                                    190 ;	../src/stm8s_gpio.c: 103: GPIOx->DDR &= (uint8_t)(~(GPIO_Pin));
      008A9B 1E 04            [ 2]  191 	ldw	x, (0x04, sp)
      008A9D F6               [ 1]  192 	ld	a, (x)
      008A9E 14 01            [ 1]  193 	and	a, (0x01, sp)
      008AA0 1E 04            [ 2]  194 	ldw	x, (0x04, sp)
      008AA2 F7               [ 1]  195 	ld	(x), a
      008AA3                        196 00106$:
                                    197 ;	../src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008AA3 93               [ 1]  198 	ldw	x, y
      008AA4 1C 00 03         [ 2]  199 	addw	x, #0x0003
      008AA7 F6               [ 1]  200 	ld	a, (x)
                                    201 ;	../src/stm8s_gpio.c: 110: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x40) != (uint8_t)0x00) /* Pull-Up or Push-Pull */
      008AA8 88               [ 1]  202 	push	a
      008AA9 7B 0C            [ 1]  203 	ld	a, (0x0c, sp)
      008AAB A5 40            [ 1]  204 	bcp	a, #0x40
      008AAD 84               [ 1]  205 	pop	a
      008AAE 27 05            [ 1]  206 	jreq	00108$
                                    207 ;	../src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008AB0 1A 0A            [ 1]  208 	or	a, (0x0a, sp)
      008AB2 F7               [ 1]  209 	ld	(x), a
      008AB3 20 03            [ 2]  210 	jra	00109$
      008AB5                        211 00108$:
                                    212 ;	../src/stm8s_gpio.c: 116: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      008AB5 14 01            [ 1]  213 	and	a, (0x01, sp)
      008AB7 F7               [ 1]  214 	ld	(x), a
      008AB8                        215 00109$:
                                    216 ;	../src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008AB8 1E 02            [ 2]  217 	ldw	x, (0x02, sp)
      008ABA F6               [ 1]  218 	ld	a, (x)
                                    219 ;	../src/stm8s_gpio.c: 123: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x20) != (uint8_t)0x00) /* Interrupt or Slow slope */
      008ABB 88               [ 1]  220 	push	a
      008ABC 7B 0C            [ 1]  221 	ld	a, (0x0c, sp)
      008ABE A5 20            [ 1]  222 	bcp	a, #0x20
      008AC0 84               [ 1]  223 	pop	a
      008AC1 27 07            [ 1]  224 	jreq	00111$
                                    225 ;	../src/stm8s_gpio.c: 125: GPIOx->CR2 |= (uint8_t)GPIO_Pin;
      008AC3 1A 0A            [ 1]  226 	or	a, (0x0a, sp)
      008AC5 1E 02            [ 2]  227 	ldw	x, (0x02, sp)
      008AC7 F7               [ 1]  228 	ld	(x), a
      008AC8 20 05            [ 2]  229 	jra	00113$
      008ACA                        230 00111$:
                                    231 ;	../src/stm8s_gpio.c: 129: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008ACA 14 01            [ 1]  232 	and	a, (0x01, sp)
      008ACC 1E 02            [ 2]  233 	ldw	x, (0x02, sp)
      008ACE F7               [ 1]  234 	ld	(x), a
      008ACF                        235 00113$:
                                    236 ;	../src/stm8s_gpio.c: 131: }
      008ACF 5B 05            [ 2]  237 	addw	sp, #5
      008AD1 81               [ 4]  238 	ret
                                    239 ;	../src/stm8s_gpio.c: 141: void GPIO_Write(GPIO_TypeDef* GPIOx, uint8_t PortVal)
                                    240 ;	-----------------------------------------
                                    241 ;	 function GPIO_Write
                                    242 ;	-----------------------------------------
      008AD2                        243 _GPIO_Write:
                                    244 ;	../src/stm8s_gpio.c: 143: GPIOx->ODR = PortVal;
      008AD2 1E 03            [ 2]  245 	ldw	x, (0x03, sp)
      008AD4 7B 05            [ 1]  246 	ld	a, (0x05, sp)
      008AD6 F7               [ 1]  247 	ld	(x), a
                                    248 ;	../src/stm8s_gpio.c: 144: }
      008AD7 81               [ 4]  249 	ret
                                    250 ;	../src/stm8s_gpio.c: 154: void GPIO_WriteHigh(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    251 ;	-----------------------------------------
                                    252 ;	 function GPIO_WriteHigh
                                    253 ;	-----------------------------------------
      008AD8                        254 _GPIO_WriteHigh:
                                    255 ;	../src/stm8s_gpio.c: 156: GPIOx->ODR |= (uint8_t)PortPins;
      008AD8 1E 03            [ 2]  256 	ldw	x, (0x03, sp)
      008ADA F6               [ 1]  257 	ld	a, (x)
      008ADB 1A 05            [ 1]  258 	or	a, (0x05, sp)
      008ADD F7               [ 1]  259 	ld	(x), a
                                    260 ;	../src/stm8s_gpio.c: 157: }
      008ADE 81               [ 4]  261 	ret
                                    262 ;	../src/stm8s_gpio.c: 167: void GPIO_WriteLow(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    263 ;	-----------------------------------------
                                    264 ;	 function GPIO_WriteLow
                                    265 ;	-----------------------------------------
      008ADF                        266 _GPIO_WriteLow:
      008ADF 88               [ 1]  267 	push	a
                                    268 ;	../src/stm8s_gpio.c: 169: GPIOx->ODR &= (uint8_t)(~PortPins);
      008AE0 1E 04            [ 2]  269 	ldw	x, (0x04, sp)
      008AE2 F6               [ 1]  270 	ld	a, (x)
      008AE3 6B 01            [ 1]  271 	ld	(0x01, sp), a
      008AE5 7B 06            [ 1]  272 	ld	a, (0x06, sp)
      008AE7 43               [ 1]  273 	cpl	a
      008AE8 14 01            [ 1]  274 	and	a, (0x01, sp)
      008AEA F7               [ 1]  275 	ld	(x), a
                                    276 ;	../src/stm8s_gpio.c: 170: }
      008AEB 84               [ 1]  277 	pop	a
      008AEC 81               [ 4]  278 	ret
                                    279 ;	../src/stm8s_gpio.c: 180: void GPIO_WriteReverse(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    280 ;	-----------------------------------------
                                    281 ;	 function GPIO_WriteReverse
                                    282 ;	-----------------------------------------
      008AED                        283 _GPIO_WriteReverse:
                                    284 ;	../src/stm8s_gpio.c: 182: GPIOx->ODR ^= (uint8_t)PortPins;
      008AED 1E 03            [ 2]  285 	ldw	x, (0x03, sp)
      008AEF F6               [ 1]  286 	ld	a, (x)
      008AF0 18 05            [ 1]  287 	xor	a, (0x05, sp)
      008AF2 F7               [ 1]  288 	ld	(x), a
                                    289 ;	../src/stm8s_gpio.c: 183: }
      008AF3 81               [ 4]  290 	ret
                                    291 ;	../src/stm8s_gpio.c: 191: uint8_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
                                    292 ;	-----------------------------------------
                                    293 ;	 function GPIO_ReadOutputData
                                    294 ;	-----------------------------------------
      008AF4                        295 _GPIO_ReadOutputData:
                                    296 ;	../src/stm8s_gpio.c: 193: return ((uint8_t)GPIOx->ODR);
      008AF4 1E 03            [ 2]  297 	ldw	x, (0x03, sp)
      008AF6 F6               [ 1]  298 	ld	a, (x)
                                    299 ;	../src/stm8s_gpio.c: 194: }
      008AF7 81               [ 4]  300 	ret
                                    301 ;	../src/stm8s_gpio.c: 202: uint8_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
                                    302 ;	-----------------------------------------
                                    303 ;	 function GPIO_ReadInputData
                                    304 ;	-----------------------------------------
      008AF8                        305 _GPIO_ReadInputData:
                                    306 ;	../src/stm8s_gpio.c: 204: return ((uint8_t)GPIOx->IDR);
      008AF8 1E 03            [ 2]  307 	ldw	x, (0x03, sp)
      008AFA E6 01            [ 1]  308 	ld	a, (0x1, x)
                                    309 ;	../src/stm8s_gpio.c: 205: }
      008AFC 81               [ 4]  310 	ret
                                    311 ;	../src/stm8s_gpio.c: 213: BitStatus GPIO_ReadInputPin(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
                                    312 ;	-----------------------------------------
                                    313 ;	 function GPIO_ReadInputPin
                                    314 ;	-----------------------------------------
      008AFD                        315 _GPIO_ReadInputPin:
                                    316 ;	../src/stm8s_gpio.c: 215: return ((BitStatus)(GPIOx->IDR & (uint8_t)GPIO_Pin));
      008AFD 1E 03            [ 2]  317 	ldw	x, (0x03, sp)
      008AFF E6 01            [ 1]  318 	ld	a, (0x1, x)
      008B01 14 05            [ 1]  319 	and	a, (0x05, sp)
                                    320 ;	../src/stm8s_gpio.c: 216: }
      008B03 81               [ 4]  321 	ret
                                    322 ;	../src/stm8s_gpio.c: 225: void GPIO_ExternalPullUpConfig(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, FunctionalState NewState)
                                    323 ;	-----------------------------------------
                                    324 ;	 function GPIO_ExternalPullUpConfig
                                    325 ;	-----------------------------------------
      008B04                        326 _GPIO_ExternalPullUpConfig:
      008B04 88               [ 1]  327 	push	a
                                    328 ;	../src/stm8s_gpio.c: 228: assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
      008B05 0D 06            [ 1]  329 	tnz	(0x06, sp)
      008B07 26 0F            [ 1]  330 	jrne	00107$
      008B09 4B E4            [ 1]  331 	push	#0xe4
      008B0B 5F               [ 1]  332 	clrw	x
      008B0C 89               [ 2]  333 	pushw	x
      008B0D 4B 00            [ 1]  334 	push	#0x00
      008B0F 4B 04            [ 1]  335 	push	#<___str_0
      008B11 4B 82            [ 1]  336 	push	#(___str_0 >> 8)
      008B13 CD 82 CE         [ 4]  337 	call	_assert_failed
      008B16 5B 06            [ 2]  338 	addw	sp, #6
      008B18                        339 00107$:
                                    340 ;	../src/stm8s_gpio.c: 229: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008B18 0D 07            [ 1]  341 	tnz	(0x07, sp)
      008B1A 27 14            [ 1]  342 	jreq	00109$
      008B1C 7B 07            [ 1]  343 	ld	a, (0x07, sp)
      008B1E 4A               [ 1]  344 	dec	a
      008B1F 27 0F            [ 1]  345 	jreq	00109$
      008B21 4B E5            [ 1]  346 	push	#0xe5
      008B23 5F               [ 1]  347 	clrw	x
      008B24 89               [ 2]  348 	pushw	x
      008B25 4B 00            [ 1]  349 	push	#0x00
      008B27 4B 04            [ 1]  350 	push	#<___str_0
      008B29 4B 82            [ 1]  351 	push	#(___str_0 >> 8)
      008B2B CD 82 CE         [ 4]  352 	call	_assert_failed
      008B2E 5B 06            [ 2]  353 	addw	sp, #6
      008B30                        354 00109$:
                                    355 ;	../src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008B30 1E 04            [ 2]  356 	ldw	x, (0x04, sp)
      008B32 1C 00 03         [ 2]  357 	addw	x, #0x0003
      008B35 F6               [ 1]  358 	ld	a, (x)
                                    359 ;	../src/stm8s_gpio.c: 231: if (NewState != DISABLE) /* External Pull-Up Set*/
      008B36 0D 07            [ 1]  360 	tnz	(0x07, sp)
      008B38 27 05            [ 1]  361 	jreq	00102$
                                    362 ;	../src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008B3A 1A 06            [ 1]  363 	or	a, (0x06, sp)
      008B3C F7               [ 1]  364 	ld	(x), a
      008B3D 20 0A            [ 2]  365 	jra	00104$
      008B3F                        366 00102$:
                                    367 ;	../src/stm8s_gpio.c: 236: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      008B3F 88               [ 1]  368 	push	a
      008B40 7B 07            [ 1]  369 	ld	a, (0x07, sp)
      008B42 43               [ 1]  370 	cpl	a
      008B43 6B 02            [ 1]  371 	ld	(0x02, sp), a
      008B45 84               [ 1]  372 	pop	a
      008B46 14 01            [ 1]  373 	and	a, (0x01, sp)
      008B48 F7               [ 1]  374 	ld	(x), a
      008B49                        375 00104$:
                                    376 ;	../src/stm8s_gpio.c: 238: }
      008B49 84               [ 1]  377 	pop	a
      008B4A 81               [ 4]  378 	ret
                                    379 	.area CODE
                                    380 	.area CONST
      008204                        381 ___str_0:
      008204 2E 2E 2F 73 72 63 2F   382 	.ascii "../src/stm8s_gpio.c"
             73 74 6D 38 73 5F 67
             70 69 6F 2E 63
      008217 00                     383 	.db 0x00
                                    384 	.area INITIALIZER
                                    385 	.area CABS (ABS)
