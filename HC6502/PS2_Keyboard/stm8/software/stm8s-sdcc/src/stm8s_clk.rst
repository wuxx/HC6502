                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_clk
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _CLKPrescTable
                                     12 	.globl _HSIDivExp
                                     13 	.globl _assert_failed
                                     14 	.globl _CLK_DeInit
                                     15 	.globl _CLK_FastHaltWakeUpCmd
                                     16 	.globl _CLK_HSECmd
                                     17 	.globl _CLK_HSICmd
                                     18 	.globl _CLK_LSICmd
                                     19 	.globl _CLK_CCOCmd
                                     20 	.globl _CLK_ClockSwitchCmd
                                     21 	.globl _CLK_SlowActiveHaltWakeUpCmd
                                     22 	.globl _CLK_PeripheralClockConfig
                                     23 	.globl _CLK_ClockSwitchConfig
                                     24 	.globl _CLK_HSIPrescalerConfig
                                     25 	.globl _CLK_CCOConfig
                                     26 	.globl _CLK_ITConfig
                                     27 	.globl _CLK_SYSCLKConfig
                                     28 	.globl _CLK_SWIMConfig
                                     29 	.globl _CLK_ClockSecuritySystemEnable
                                     30 	.globl _CLK_GetSYSCLKSource
                                     31 	.globl _CLK_GetClockFreq
                                     32 	.globl _CLK_AdjustHSICalibrationValue
                                     33 	.globl _CLK_SYSCLKEmergencyClear
                                     34 	.globl _CLK_GetFlagStatus
                                     35 	.globl _CLK_GetITStatus
                                     36 	.globl _CLK_ClearITPendingBit
                                     37 ;--------------------------------------------------------
                                     38 ; ram data
                                     39 ;--------------------------------------------------------
                                     40 	.area DATA
                                     41 ;--------------------------------------------------------
                                     42 ; ram data
                                     43 ;--------------------------------------------------------
                                     44 	.area INITIALIZED
                                     45 ;--------------------------------------------------------
                                     46 ; absolute external ram data
                                     47 ;--------------------------------------------------------
                                     48 	.area DABS (ABS)
                                     49 
                                     50 ; default segment ordering for linker
                                     51 	.area HOME
                                     52 	.area GSINIT
                                     53 	.area GSFINAL
                                     54 	.area CONST
                                     55 	.area INITIALIZER
                                     56 	.area CODE
                                     57 
                                     58 ;--------------------------------------------------------
                                     59 ; global & static initialisations
                                     60 ;--------------------------------------------------------
                                     61 	.area HOME
                                     62 	.area GSINIT
                                     63 	.area GSFINAL
                                     64 	.area GSINIT
                                     65 ;--------------------------------------------------------
                                     66 ; Home
                                     67 ;--------------------------------------------------------
                                     68 	.area HOME
                                     69 	.area HOME
                                     70 ;--------------------------------------------------------
                                     71 ; code
                                     72 ;--------------------------------------------------------
                                     73 	.area CODE
                                     74 ;	../src/stm8s_clk.c: 72: void CLK_DeInit(void)
                                     75 ;	-----------------------------------------
                                     76 ;	 function CLK_DeInit
                                     77 ;	-----------------------------------------
      008B4B                         78 _CLK_DeInit:
                                     79 ;	../src/stm8s_clk.c: 74: CLK->ICKR = CLK_ICKR_RESET_VALUE;
      008B4B 35 01 50 C0      [ 1]   80 	mov	0x50c0+0, #0x01
                                     81 ;	../src/stm8s_clk.c: 75: CLK->ECKR = CLK_ECKR_RESET_VALUE;
      008B4F 35 00 50 C1      [ 1]   82 	mov	0x50c1+0, #0x00
                                     83 ;	../src/stm8s_clk.c: 76: CLK->SWR  = CLK_SWR_RESET_VALUE;
      008B53 35 E1 50 C4      [ 1]   84 	mov	0x50c4+0, #0xe1
                                     85 ;	../src/stm8s_clk.c: 77: CLK->SWCR = CLK_SWCR_RESET_VALUE;
      008B57 35 00 50 C5      [ 1]   86 	mov	0x50c5+0, #0x00
                                     87 ;	../src/stm8s_clk.c: 78: CLK->CKDIVR = CLK_CKDIVR_RESET_VALUE;
      008B5B 35 18 50 C6      [ 1]   88 	mov	0x50c6+0, #0x18
                                     89 ;	../src/stm8s_clk.c: 79: CLK->PCKENR1 = CLK_PCKENR1_RESET_VALUE;
      008B5F 35 FF 50 C7      [ 1]   90 	mov	0x50c7+0, #0xff
                                     91 ;	../src/stm8s_clk.c: 80: CLK->PCKENR2 = CLK_PCKENR2_RESET_VALUE;
      008B63 35 FF 50 CA      [ 1]   92 	mov	0x50ca+0, #0xff
                                     93 ;	../src/stm8s_clk.c: 81: CLK->CSSR = CLK_CSSR_RESET_VALUE;
      008B67 35 00 50 C8      [ 1]   94 	mov	0x50c8+0, #0x00
                                     95 ;	../src/stm8s_clk.c: 82: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      008B6B 35 00 50 C9      [ 1]   96 	mov	0x50c9+0, #0x00
                                     97 ;	../src/stm8s_clk.c: 83: while ((CLK->CCOR & CLK_CCOR_CCOEN)!= 0)
      008B6F                         98 00101$:
      008B6F C6 50 C9         [ 1]   99 	ld	a, 0x50c9
      008B72 44               [ 1]  100 	srl	a
      008B73 25 FA            [ 1]  101 	jrc	00101$
                                    102 ;	../src/stm8s_clk.c: 85: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      008B75 35 00 50 C9      [ 1]  103 	mov	0x50c9+0, #0x00
                                    104 ;	../src/stm8s_clk.c: 86: CLK->HSITRIMR = CLK_HSITRIMR_RESET_VALUE;
      008B79 35 00 50 CC      [ 1]  105 	mov	0x50cc+0, #0x00
                                    106 ;	../src/stm8s_clk.c: 87: CLK->SWIMCCR = CLK_SWIMCCR_RESET_VALUE;
      008B7D 35 00 50 CD      [ 1]  107 	mov	0x50cd+0, #0x00
                                    108 ;	../src/stm8s_clk.c: 88: }
      008B81 81               [ 4]  109 	ret
                                    110 ;	../src/stm8s_clk.c: 99: void CLK_FastHaltWakeUpCmd(FunctionalState NewState)
                                    111 ;	-----------------------------------------
                                    112 ;	 function CLK_FastHaltWakeUpCmd
                                    113 ;	-----------------------------------------
      008B82                        114 _CLK_FastHaltWakeUpCmd:
                                    115 ;	../src/stm8s_clk.c: 102: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008B82 0D 03            [ 1]  116 	tnz	(0x03, sp)
      008B84 27 14            [ 1]  117 	jreq	00107$
      008B86 7B 03            [ 1]  118 	ld	a, (0x03, sp)
      008B88 4A               [ 1]  119 	dec	a
      008B89 27 0F            [ 1]  120 	jreq	00107$
      008B8B 4B 66            [ 1]  121 	push	#0x66
      008B8D 5F               [ 1]  122 	clrw	x
      008B8E 89               [ 2]  123 	pushw	x
      008B8F 4B 00            [ 1]  124 	push	#0x00
      008B91 4B 24            [ 1]  125 	push	#<___str_0
      008B93 4B 82            [ 1]  126 	push	#(___str_0 >> 8)
      008B95 CD 82 CE         [ 4]  127 	call	_assert_failed
      008B98 5B 06            [ 2]  128 	addw	sp, #6
      008B9A                        129 00107$:
                                    130 ;	../src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
      008B9A C6 50 C0         [ 1]  131 	ld	a, 0x50c0
                                    132 ;	../src/stm8s_clk.c: 104: if (NewState != DISABLE)
      008B9D 0D 03            [ 1]  133 	tnz	(0x03, sp)
      008B9F 27 06            [ 1]  134 	jreq	00102$
                                    135 ;	../src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
      008BA1 AA 04            [ 1]  136 	or	a, #0x04
      008BA3 C7 50 C0         [ 1]  137 	ld	0x50c0, a
      008BA6 81               [ 4]  138 	ret
      008BA7                        139 00102$:
                                    140 ;	../src/stm8s_clk.c: 112: CLK->ICKR &= (uint8_t)(~CLK_ICKR_FHWU);
      008BA7 A4 FB            [ 1]  141 	and	a, #0xfb
      008BA9 C7 50 C0         [ 1]  142 	ld	0x50c0, a
                                    143 ;	../src/stm8s_clk.c: 114: }
      008BAC 81               [ 4]  144 	ret
                                    145 ;	../src/stm8s_clk.c: 121: void CLK_HSECmd(FunctionalState NewState)
                                    146 ;	-----------------------------------------
                                    147 ;	 function CLK_HSECmd
                                    148 ;	-----------------------------------------
      008BAD                        149 _CLK_HSECmd:
                                    150 ;	../src/stm8s_clk.c: 124: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008BAD 0D 03            [ 1]  151 	tnz	(0x03, sp)
      008BAF 27 14            [ 1]  152 	jreq	00107$
      008BB1 7B 03            [ 1]  153 	ld	a, (0x03, sp)
      008BB3 4A               [ 1]  154 	dec	a
      008BB4 27 0F            [ 1]  155 	jreq	00107$
      008BB6 4B 7C            [ 1]  156 	push	#0x7c
      008BB8 5F               [ 1]  157 	clrw	x
      008BB9 89               [ 2]  158 	pushw	x
      008BBA 4B 00            [ 1]  159 	push	#0x00
      008BBC 4B 24            [ 1]  160 	push	#<___str_0
      008BBE 4B 82            [ 1]  161 	push	#(___str_0 >> 8)
      008BC0 CD 82 CE         [ 4]  162 	call	_assert_failed
      008BC3 5B 06            [ 2]  163 	addw	sp, #6
      008BC5                        164 00107$:
                                    165 ;	../src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
      008BC5 C6 50 C1         [ 1]  166 	ld	a, 0x50c1
                                    167 ;	../src/stm8s_clk.c: 126: if (NewState != DISABLE)
      008BC8 0D 03            [ 1]  168 	tnz	(0x03, sp)
      008BCA 27 06            [ 1]  169 	jreq	00102$
                                    170 ;	../src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
      008BCC AA 01            [ 1]  171 	or	a, #0x01
      008BCE C7 50 C1         [ 1]  172 	ld	0x50c1, a
      008BD1 81               [ 4]  173 	ret
      008BD2                        174 00102$:
                                    175 ;	../src/stm8s_clk.c: 134: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      008BD2 A4 FE            [ 1]  176 	and	a, #0xfe
      008BD4 C7 50 C1         [ 1]  177 	ld	0x50c1, a
                                    178 ;	../src/stm8s_clk.c: 136: }
      008BD7 81               [ 4]  179 	ret
                                    180 ;	../src/stm8s_clk.c: 143: void CLK_HSICmd(FunctionalState NewState)
                                    181 ;	-----------------------------------------
                                    182 ;	 function CLK_HSICmd
                                    183 ;	-----------------------------------------
      008BD8                        184 _CLK_HSICmd:
                                    185 ;	../src/stm8s_clk.c: 146: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008BD8 0D 03            [ 1]  186 	tnz	(0x03, sp)
      008BDA 27 14            [ 1]  187 	jreq	00107$
      008BDC 7B 03            [ 1]  188 	ld	a, (0x03, sp)
      008BDE 4A               [ 1]  189 	dec	a
      008BDF 27 0F            [ 1]  190 	jreq	00107$
      008BE1 4B 92            [ 1]  191 	push	#0x92
      008BE3 5F               [ 1]  192 	clrw	x
      008BE4 89               [ 2]  193 	pushw	x
      008BE5 4B 00            [ 1]  194 	push	#0x00
      008BE7 4B 24            [ 1]  195 	push	#<___str_0
      008BE9 4B 82            [ 1]  196 	push	#(___str_0 >> 8)
      008BEB CD 82 CE         [ 4]  197 	call	_assert_failed
      008BEE 5B 06            [ 2]  198 	addw	sp, #6
      008BF0                        199 00107$:
                                    200 ;	../src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
      008BF0 C6 50 C0         [ 1]  201 	ld	a, 0x50c0
                                    202 ;	../src/stm8s_clk.c: 148: if (NewState != DISABLE)
      008BF3 0D 03            [ 1]  203 	tnz	(0x03, sp)
      008BF5 27 06            [ 1]  204 	jreq	00102$
                                    205 ;	../src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
      008BF7 AA 01            [ 1]  206 	or	a, #0x01
      008BF9 C7 50 C0         [ 1]  207 	ld	0x50c0, a
      008BFC 81               [ 4]  208 	ret
      008BFD                        209 00102$:
                                    210 ;	../src/stm8s_clk.c: 156: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      008BFD A4 FE            [ 1]  211 	and	a, #0xfe
      008BFF C7 50 C0         [ 1]  212 	ld	0x50c0, a
                                    213 ;	../src/stm8s_clk.c: 158: }
      008C02 81               [ 4]  214 	ret
                                    215 ;	../src/stm8s_clk.c: 166: void CLK_LSICmd(FunctionalState NewState)
                                    216 ;	-----------------------------------------
                                    217 ;	 function CLK_LSICmd
                                    218 ;	-----------------------------------------
      008C03                        219 _CLK_LSICmd:
                                    220 ;	../src/stm8s_clk.c: 169: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008C03 0D 03            [ 1]  221 	tnz	(0x03, sp)
      008C05 27 14            [ 1]  222 	jreq	00107$
      008C07 7B 03            [ 1]  223 	ld	a, (0x03, sp)
      008C09 4A               [ 1]  224 	dec	a
      008C0A 27 0F            [ 1]  225 	jreq	00107$
      008C0C 4B A9            [ 1]  226 	push	#0xa9
      008C0E 5F               [ 1]  227 	clrw	x
      008C0F 89               [ 2]  228 	pushw	x
      008C10 4B 00            [ 1]  229 	push	#0x00
      008C12 4B 24            [ 1]  230 	push	#<___str_0
      008C14 4B 82            [ 1]  231 	push	#(___str_0 >> 8)
      008C16 CD 82 CE         [ 4]  232 	call	_assert_failed
      008C19 5B 06            [ 2]  233 	addw	sp, #6
      008C1B                        234 00107$:
                                    235 ;	../src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
      008C1B C6 50 C0         [ 1]  236 	ld	a, 0x50c0
                                    237 ;	../src/stm8s_clk.c: 171: if (NewState != DISABLE)
      008C1E 0D 03            [ 1]  238 	tnz	(0x03, sp)
      008C20 27 06            [ 1]  239 	jreq	00102$
                                    240 ;	../src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
      008C22 AA 08            [ 1]  241 	or	a, #0x08
      008C24 C7 50 C0         [ 1]  242 	ld	0x50c0, a
      008C27 81               [ 4]  243 	ret
      008C28                        244 00102$:
                                    245 ;	../src/stm8s_clk.c: 179: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      008C28 A4 F7            [ 1]  246 	and	a, #0xf7
      008C2A C7 50 C0         [ 1]  247 	ld	0x50c0, a
                                    248 ;	../src/stm8s_clk.c: 181: }
      008C2D 81               [ 4]  249 	ret
                                    250 ;	../src/stm8s_clk.c: 189: void CLK_CCOCmd(FunctionalState NewState)
                                    251 ;	-----------------------------------------
                                    252 ;	 function CLK_CCOCmd
                                    253 ;	-----------------------------------------
      008C2E                        254 _CLK_CCOCmd:
                                    255 ;	../src/stm8s_clk.c: 192: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008C2E 0D 03            [ 1]  256 	tnz	(0x03, sp)
      008C30 27 14            [ 1]  257 	jreq	00107$
      008C32 7B 03            [ 1]  258 	ld	a, (0x03, sp)
      008C34 4A               [ 1]  259 	dec	a
      008C35 27 0F            [ 1]  260 	jreq	00107$
      008C37 4B C0            [ 1]  261 	push	#0xc0
      008C39 5F               [ 1]  262 	clrw	x
      008C3A 89               [ 2]  263 	pushw	x
      008C3B 4B 00            [ 1]  264 	push	#0x00
      008C3D 4B 24            [ 1]  265 	push	#<___str_0
      008C3F 4B 82            [ 1]  266 	push	#(___str_0 >> 8)
      008C41 CD 82 CE         [ 4]  267 	call	_assert_failed
      008C44 5B 06            [ 2]  268 	addw	sp, #6
      008C46                        269 00107$:
                                    270 ;	../src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
      008C46 C6 50 C9         [ 1]  271 	ld	a, 0x50c9
                                    272 ;	../src/stm8s_clk.c: 194: if (NewState != DISABLE)
      008C49 0D 03            [ 1]  273 	tnz	(0x03, sp)
      008C4B 27 06            [ 1]  274 	jreq	00102$
                                    275 ;	../src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
      008C4D AA 01            [ 1]  276 	or	a, #0x01
      008C4F C7 50 C9         [ 1]  277 	ld	0x50c9, a
      008C52 81               [ 4]  278 	ret
      008C53                        279 00102$:
                                    280 ;	../src/stm8s_clk.c: 202: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOEN);
      008C53 A4 FE            [ 1]  281 	and	a, #0xfe
      008C55 C7 50 C9         [ 1]  282 	ld	0x50c9, a
                                    283 ;	../src/stm8s_clk.c: 204: }
      008C58 81               [ 4]  284 	ret
                                    285 ;	../src/stm8s_clk.c: 213: void CLK_ClockSwitchCmd(FunctionalState NewState)
                                    286 ;	-----------------------------------------
                                    287 ;	 function CLK_ClockSwitchCmd
                                    288 ;	-----------------------------------------
      008C59                        289 _CLK_ClockSwitchCmd:
                                    290 ;	../src/stm8s_clk.c: 216: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008C59 0D 03            [ 1]  291 	tnz	(0x03, sp)
      008C5B 27 14            [ 1]  292 	jreq	00107$
      008C5D 7B 03            [ 1]  293 	ld	a, (0x03, sp)
      008C5F 4A               [ 1]  294 	dec	a
      008C60 27 0F            [ 1]  295 	jreq	00107$
      008C62 4B D8            [ 1]  296 	push	#0xd8
      008C64 5F               [ 1]  297 	clrw	x
      008C65 89               [ 2]  298 	pushw	x
      008C66 4B 00            [ 1]  299 	push	#0x00
      008C68 4B 24            [ 1]  300 	push	#<___str_0
      008C6A 4B 82            [ 1]  301 	push	#(___str_0 >> 8)
      008C6C CD 82 CE         [ 4]  302 	call	_assert_failed
      008C6F 5B 06            [ 2]  303 	addw	sp, #6
      008C71                        304 00107$:
                                    305 ;	../src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
      008C71 C6 50 C5         [ 1]  306 	ld	a, 0x50c5
                                    307 ;	../src/stm8s_clk.c: 218: if (NewState != DISABLE )
      008C74 0D 03            [ 1]  308 	tnz	(0x03, sp)
      008C76 27 06            [ 1]  309 	jreq	00102$
                                    310 ;	../src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
      008C78 AA 02            [ 1]  311 	or	a, #0x02
      008C7A C7 50 C5         [ 1]  312 	ld	0x50c5, a
      008C7D 81               [ 4]  313 	ret
      008C7E                        314 00102$:
                                    315 ;	../src/stm8s_clk.c: 226: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWEN);
      008C7E A4 FD            [ 1]  316 	and	a, #0xfd
      008C80 C7 50 C5         [ 1]  317 	ld	0x50c5, a
                                    318 ;	../src/stm8s_clk.c: 228: }
      008C83 81               [ 4]  319 	ret
                                    320 ;	../src/stm8s_clk.c: 238: void CLK_SlowActiveHaltWakeUpCmd(FunctionalState NewState)
                                    321 ;	-----------------------------------------
                                    322 ;	 function CLK_SlowActiveHaltWakeUpCmd
                                    323 ;	-----------------------------------------
      008C84                        324 _CLK_SlowActiveHaltWakeUpCmd:
                                    325 ;	../src/stm8s_clk.c: 241: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008C84 0D 03            [ 1]  326 	tnz	(0x03, sp)
      008C86 27 14            [ 1]  327 	jreq	00107$
      008C88 7B 03            [ 1]  328 	ld	a, (0x03, sp)
      008C8A 4A               [ 1]  329 	dec	a
      008C8B 27 0F            [ 1]  330 	jreq	00107$
      008C8D 4B F1            [ 1]  331 	push	#0xf1
      008C8F 5F               [ 1]  332 	clrw	x
      008C90 89               [ 2]  333 	pushw	x
      008C91 4B 00            [ 1]  334 	push	#0x00
      008C93 4B 24            [ 1]  335 	push	#<___str_0
      008C95 4B 82            [ 1]  336 	push	#(___str_0 >> 8)
      008C97 CD 82 CE         [ 4]  337 	call	_assert_failed
      008C9A 5B 06            [ 2]  338 	addw	sp, #6
      008C9C                        339 00107$:
                                    340 ;	../src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
      008C9C C6 50 C0         [ 1]  341 	ld	a, 0x50c0
                                    342 ;	../src/stm8s_clk.c: 243: if (NewState != DISABLE)
      008C9F 0D 03            [ 1]  343 	tnz	(0x03, sp)
      008CA1 27 06            [ 1]  344 	jreq	00102$
                                    345 ;	../src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
      008CA3 AA 20            [ 1]  346 	or	a, #0x20
      008CA5 C7 50 C0         [ 1]  347 	ld	0x50c0, a
      008CA8 81               [ 4]  348 	ret
      008CA9                        349 00102$:
                                    350 ;	../src/stm8s_clk.c: 251: CLK->ICKR &= (uint8_t)(~CLK_ICKR_SWUAH);
      008CA9 A4 DF            [ 1]  351 	and	a, #0xdf
      008CAB C7 50 C0         [ 1]  352 	ld	0x50c0, a
                                    353 ;	../src/stm8s_clk.c: 253: }
      008CAE 81               [ 4]  354 	ret
                                    355 ;	../src/stm8s_clk.c: 263: void CLK_PeripheralClockConfig(CLK_Peripheral_TypeDef CLK_Peripheral, FunctionalState NewState)
                                    356 ;	-----------------------------------------
                                    357 ;	 function CLK_PeripheralClockConfig
                                    358 ;	-----------------------------------------
      008CAF                        359 _CLK_PeripheralClockConfig:
      008CAF 89               [ 2]  360 	pushw	x
                                    361 ;	../src/stm8s_clk.c: 266: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008CB0 0D 06            [ 1]  362 	tnz	(0x06, sp)
      008CB2 27 14            [ 1]  363 	jreq	00113$
      008CB4 7B 06            [ 1]  364 	ld	a, (0x06, sp)
      008CB6 4A               [ 1]  365 	dec	a
      008CB7 27 0F            [ 1]  366 	jreq	00113$
      008CB9 4B 0A            [ 1]  367 	push	#0x0a
      008CBB 4B 01            [ 1]  368 	push	#0x01
      008CBD 5F               [ 1]  369 	clrw	x
      008CBE 89               [ 2]  370 	pushw	x
      008CBF 4B 24            [ 1]  371 	push	#<___str_0
      008CC1 4B 82            [ 1]  372 	push	#(___str_0 >> 8)
      008CC3 CD 82 CE         [ 4]  373 	call	_assert_failed
      008CC6 5B 06            [ 2]  374 	addw	sp, #6
      008CC8                        375 00113$:
                                    376 ;	../src/stm8s_clk.c: 267: assert_param(IS_CLK_PERIPHERAL_OK(CLK_Peripheral));
      008CC8 0D 05            [ 1]  377 	tnz	(0x05, sp)
      008CCA 27 67            [ 1]  378 	jreq	00118$
      008CCC 7B 05            [ 1]  379 	ld	a, (0x05, sp)
      008CCE 4A               [ 1]  380 	dec	a
      008CCF 27 62            [ 1]  381 	jreq	00118$
      008CD1 7B 05            [ 1]  382 	ld	a, (0x05, sp)
      008CD3 A0 03            [ 1]  383 	sub	a, #0x03
      008CD5 26 02            [ 1]  384 	jrne	00262$
      008CD7 4C               [ 1]  385 	inc	a
      008CD8 21                     386 	.byte 0x21
      008CD9                        387 00262$:
      008CD9 4F               [ 1]  388 	clr	a
      008CDA                        389 00263$:
      008CDA 4D               [ 1]  390 	tnz	a
      008CDB 26 56            [ 1]  391 	jrne	00118$
      008CDD 4D               [ 1]  392 	tnz	a
      008CDE 26 53            [ 1]  393 	jrne	00118$
      008CE0 4D               [ 1]  394 	tnz	a
      008CE1 26 50            [ 1]  395 	jrne	00118$
      008CE3 7B 05            [ 1]  396 	ld	a, (0x05, sp)
      008CE5 A0 04            [ 1]  397 	sub	a, #0x04
      008CE7 26 04            [ 1]  398 	jrne	00268$
      008CE9 4C               [ 1]  399 	inc	a
      008CEA 97               [ 1]  400 	ld	xl, a
      008CEB 20 02            [ 2]  401 	jra	00269$
      008CED                        402 00268$:
      008CED 4F               [ 1]  403 	clr	a
      008CEE 97               [ 1]  404 	ld	xl, a
      008CEF                        405 00269$:
      008CEF 9F               [ 1]  406 	ld	a, xl
      008CF0 4D               [ 1]  407 	tnz	a
      008CF1 26 40            [ 1]  408 	jrne	00118$
      008CF3 7B 05            [ 1]  409 	ld	a, (0x05, sp)
      008CF5 A0 05            [ 1]  410 	sub	a, #0x05
      008CF7 26 02            [ 1]  411 	jrne	00272$
      008CF9 4C               [ 1]  412 	inc	a
      008CFA 21                     413 	.byte 0x21
      008CFB                        414 00272$:
      008CFB 4F               [ 1]  415 	clr	a
      008CFC                        416 00273$:
      008CFC 4D               [ 1]  417 	tnz	a
      008CFD 26 34            [ 1]  418 	jrne	00118$
      008CFF 4D               [ 1]  419 	tnz	a
      008D00 26 31            [ 1]  420 	jrne	00118$
      008D02 9F               [ 1]  421 	ld	a, xl
      008D03 4D               [ 1]  422 	tnz	a
      008D04 26 2D            [ 1]  423 	jrne	00118$
      008D06 7B 05            [ 1]  424 	ld	a, (0x05, sp)
      008D08 A1 06            [ 1]  425 	cp	a, #0x06
      008D0A 27 27            [ 1]  426 	jreq	00118$
      008D0C 7B 05            [ 1]  427 	ld	a, (0x05, sp)
      008D0E A1 07            [ 1]  428 	cp	a, #0x07
      008D10 27 21            [ 1]  429 	jreq	00118$
      008D12 7B 05            [ 1]  430 	ld	a, (0x05, sp)
      008D14 A1 17            [ 1]  431 	cp	a, #0x17
      008D16 27 1B            [ 1]  432 	jreq	00118$
      008D18 7B 05            [ 1]  433 	ld	a, (0x05, sp)
      008D1A A1 13            [ 1]  434 	cp	a, #0x13
      008D1C 27 15            [ 1]  435 	jreq	00118$
      008D1E 7B 05            [ 1]  436 	ld	a, (0x05, sp)
      008D20 A1 12            [ 1]  437 	cp	a, #0x12
      008D22 27 0F            [ 1]  438 	jreq	00118$
      008D24 4B 0B            [ 1]  439 	push	#0x0b
      008D26 4B 01            [ 1]  440 	push	#0x01
      008D28 5F               [ 1]  441 	clrw	x
      008D29 89               [ 2]  442 	pushw	x
      008D2A 4B 24            [ 1]  443 	push	#<___str_0
      008D2C 4B 82            [ 1]  444 	push	#(___str_0 >> 8)
      008D2E CD 82 CE         [ 4]  445 	call	_assert_failed
      008D31 5B 06            [ 2]  446 	addw	sp, #6
      008D33                        447 00118$:
                                    448 ;	../src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008D33 7B 05            [ 1]  449 	ld	a, (0x05, sp)
      008D35 A4 0F            [ 1]  450 	and	a, #0x0f
      008D37 88               [ 1]  451 	push	a
      008D38 A6 01            [ 1]  452 	ld	a, #0x01
      008D3A 6B 03            [ 1]  453 	ld	(0x03, sp), a
      008D3C 84               [ 1]  454 	pop	a
      008D3D 4D               [ 1]  455 	tnz	a
      008D3E 27 05            [ 1]  456 	jreq	00293$
      008D40                        457 00292$:
      008D40 08 02            [ 1]  458 	sll	(0x02, sp)
      008D42 4A               [ 1]  459 	dec	a
      008D43 26 FB            [ 1]  460 	jrne	00292$
      008D45                        461 00293$:
                                    462 ;	../src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008D45 7B 02            [ 1]  463 	ld	a, (0x02, sp)
      008D47 43               [ 1]  464 	cpl	a
      008D48 6B 01            [ 1]  465 	ld	(0x01, sp), a
                                    466 ;	../src/stm8s_clk.c: 269: if (((uint8_t)CLK_Peripheral & (uint8_t)0x10) == 0x00)
      008D4A 7B 05            [ 1]  467 	ld	a, (0x05, sp)
      008D4C A5 10            [ 1]  468 	bcp	a, #0x10
      008D4E 26 15            [ 1]  469 	jrne	00108$
                                    470 ;	../src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008D50 C6 50 C7         [ 1]  471 	ld	a, 0x50c7
                                    472 ;	../src/stm8s_clk.c: 271: if (NewState != DISABLE)
      008D53 0D 06            [ 1]  473 	tnz	(0x06, sp)
      008D55 27 07            [ 1]  474 	jreq	00102$
                                    475 ;	../src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008D57 1A 02            [ 1]  476 	or	a, (0x02, sp)
      008D59 C7 50 C7         [ 1]  477 	ld	0x50c7, a
      008D5C 20 1A            [ 2]  478 	jra	00110$
      008D5E                        479 00102$:
                                    480 ;	../src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008D5E 14 01            [ 1]  481 	and	a, (0x01, sp)
      008D60 C7 50 C7         [ 1]  482 	ld	0x50c7, a
      008D63 20 13            [ 2]  483 	jra	00110$
      008D65                        484 00108$:
                                    485 ;	../src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008D65 C6 50 CA         [ 1]  486 	ld	a, 0x50ca
                                    487 ;	../src/stm8s_clk.c: 284: if (NewState != DISABLE)
      008D68 0D 06            [ 1]  488 	tnz	(0x06, sp)
      008D6A 27 07            [ 1]  489 	jreq	00105$
                                    490 ;	../src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008D6C 1A 02            [ 1]  491 	or	a, (0x02, sp)
      008D6E C7 50 CA         [ 1]  492 	ld	0x50ca, a
      008D71 20 05            [ 2]  493 	jra	00110$
      008D73                        494 00105$:
                                    495 ;	../src/stm8s_clk.c: 292: CLK->PCKENR2 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008D73 14 01            [ 1]  496 	and	a, (0x01, sp)
      008D75 C7 50 CA         [ 1]  497 	ld	0x50ca, a
      008D78                        498 00110$:
                                    499 ;	../src/stm8s_clk.c: 295: }
      008D78 85               [ 2]  500 	popw	x
      008D79 81               [ 4]  501 	ret
                                    502 ;	../src/stm8s_clk.c: 309: ErrorStatus CLK_ClockSwitchConfig(CLK_SwitchMode_TypeDef CLK_SwitchMode, CLK_Source_TypeDef CLK_NewClock, FunctionalState ITState, CLK_CurrentClockState_TypeDef CLK_CurrentClockState)
                                    503 ;	-----------------------------------------
                                    504 ;	 function CLK_ClockSwitchConfig
                                    505 ;	-----------------------------------------
      008D7A                        506 _CLK_ClockSwitchConfig:
      008D7A 88               [ 1]  507 	push	a
                                    508 ;	../src/stm8s_clk.c: 316: assert_param(IS_CLK_SOURCE_OK(CLK_NewClock));
      008D7B 7B 05            [ 1]  509 	ld	a, (0x05, sp)
      008D7D A1 E1            [ 1]  510 	cp	a, #0xe1
      008D7F 27 1B            [ 1]  511 	jreq	00140$
      008D81 7B 05            [ 1]  512 	ld	a, (0x05, sp)
      008D83 A1 D2            [ 1]  513 	cp	a, #0xd2
      008D85 27 15            [ 1]  514 	jreq	00140$
      008D87 7B 05            [ 1]  515 	ld	a, (0x05, sp)
      008D89 A1 B4            [ 1]  516 	cp	a, #0xb4
      008D8B 27 0F            [ 1]  517 	jreq	00140$
      008D8D 4B 3C            [ 1]  518 	push	#0x3c
      008D8F 4B 01            [ 1]  519 	push	#0x01
      008D91 5F               [ 1]  520 	clrw	x
      008D92 89               [ 2]  521 	pushw	x
      008D93 4B 24            [ 1]  522 	push	#<___str_0
      008D95 4B 82            [ 1]  523 	push	#(___str_0 >> 8)
      008D97 CD 82 CE         [ 4]  524 	call	_assert_failed
      008D9A 5B 06            [ 2]  525 	addw	sp, #6
      008D9C                        526 00140$:
                                    527 ;	../src/stm8s_clk.c: 317: assert_param(IS_CLK_SWITCHMODE_OK(CLK_SwitchMode));
      008D9C 7B 04            [ 1]  528 	ld	a, (0x04, sp)
      008D9E 4A               [ 1]  529 	dec	a
      008D9F 26 05            [ 1]  530 	jrne	00309$
      008DA1 A6 01            [ 1]  531 	ld	a, #0x01
      008DA3 6B 01            [ 1]  532 	ld	(0x01, sp), a
      008DA5 C1                     533 	.byte 0xc1
      008DA6                        534 00309$:
      008DA6 0F 01            [ 1]  535 	clr	(0x01, sp)
      008DA8                        536 00310$:
      008DA8 0D 04            [ 1]  537 	tnz	(0x04, sp)
      008DAA 27 13            [ 1]  538 	jreq	00148$
      008DAC 0D 01            [ 1]  539 	tnz	(0x01, sp)
      008DAE 26 0F            [ 1]  540 	jrne	00148$
      008DB0 4B 3D            [ 1]  541 	push	#0x3d
      008DB2 4B 01            [ 1]  542 	push	#0x01
      008DB4 5F               [ 1]  543 	clrw	x
      008DB5 89               [ 2]  544 	pushw	x
      008DB6 4B 24            [ 1]  545 	push	#<___str_0
      008DB8 4B 82            [ 1]  546 	push	#(___str_0 >> 8)
      008DBA CD 82 CE         [ 4]  547 	call	_assert_failed
      008DBD 5B 06            [ 2]  548 	addw	sp, #6
      008DBF                        549 00148$:
                                    550 ;	../src/stm8s_clk.c: 318: assert_param(IS_FUNCTIONALSTATE_OK(ITState));
      008DBF 0D 06            [ 1]  551 	tnz	(0x06, sp)
      008DC1 27 14            [ 1]  552 	jreq	00153$
      008DC3 7B 06            [ 1]  553 	ld	a, (0x06, sp)
      008DC5 4A               [ 1]  554 	dec	a
      008DC6 27 0F            [ 1]  555 	jreq	00153$
      008DC8 4B 3E            [ 1]  556 	push	#0x3e
      008DCA 4B 01            [ 1]  557 	push	#0x01
      008DCC 5F               [ 1]  558 	clrw	x
      008DCD 89               [ 2]  559 	pushw	x
      008DCE 4B 24            [ 1]  560 	push	#<___str_0
      008DD0 4B 82            [ 1]  561 	push	#(___str_0 >> 8)
      008DD2 CD 82 CE         [ 4]  562 	call	_assert_failed
      008DD5 5B 06            [ 2]  563 	addw	sp, #6
      008DD7                        564 00153$:
                                    565 ;	../src/stm8s_clk.c: 319: assert_param(IS_CLK_CURRENTCLOCKSTATE_OK(CLK_CurrentClockState));
      008DD7 0D 07            [ 1]  566 	tnz	(0x07, sp)
      008DD9 27 14            [ 1]  567 	jreq	00158$
      008DDB 7B 07            [ 1]  568 	ld	a, (0x07, sp)
      008DDD 4A               [ 1]  569 	dec	a
      008DDE 27 0F            [ 1]  570 	jreq	00158$
      008DE0 4B 3F            [ 1]  571 	push	#0x3f
      008DE2 4B 01            [ 1]  572 	push	#0x01
      008DE4 5F               [ 1]  573 	clrw	x
      008DE5 89               [ 2]  574 	pushw	x
      008DE6 4B 24            [ 1]  575 	push	#<___str_0
      008DE8 4B 82            [ 1]  576 	push	#(___str_0 >> 8)
      008DEA CD 82 CE         [ 4]  577 	call	_assert_failed
      008DED 5B 06            [ 2]  578 	addw	sp, #6
      008DEF                        579 00158$:
                                    580 ;	../src/stm8s_clk.c: 322: clock_master = (CLK_Source_TypeDef)CLK->CMSR;
      008DEF C6 50 C3         [ 1]  581 	ld	a, 0x50c3
      008DF2 90 97            [ 1]  582 	ld	yl, a
                                    583 ;	../src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
      008DF4 C6 50 C5         [ 1]  584 	ld	a, 0x50c5
                                    585 ;	../src/stm8s_clk.c: 325: if (CLK_SwitchMode == CLK_SWITCHMODE_AUTO)
      008DF7 0D 01            [ 1]  586 	tnz	(0x01, sp)
      008DF9 27 38            [ 1]  587 	jreq	00122$
                                    588 ;	../src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
      008DFB AA 02            [ 1]  589 	or	a, #0x02
      008DFD C7 50 C5         [ 1]  590 	ld	0x50c5, a
      008E00 C6 50 C5         [ 1]  591 	ld	a, 0x50c5
                                    592 ;	../src/stm8s_clk.c: 331: if (ITState != DISABLE)
      008E03 0D 06            [ 1]  593 	tnz	(0x06, sp)
      008E05 27 07            [ 1]  594 	jreq	00102$
                                    595 ;	../src/stm8s_clk.c: 333: CLK->SWCR |= CLK_SWCR_SWIEN;
      008E07 AA 04            [ 1]  596 	or	a, #0x04
      008E09 C7 50 C5         [ 1]  597 	ld	0x50c5, a
      008E0C 20 05            [ 2]  598 	jra	00103$
      008E0E                        599 00102$:
                                    600 ;	../src/stm8s_clk.c: 337: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      008E0E A4 FB            [ 1]  601 	and	a, #0xfb
      008E10 C7 50 C5         [ 1]  602 	ld	0x50c5, a
      008E13                        603 00103$:
                                    604 ;	../src/stm8s_clk.c: 341: CLK->SWR = (uint8_t)CLK_NewClock;
      008E13 AE 50 C4         [ 2]  605 	ldw	x, #0x50c4
      008E16 7B 05            [ 1]  606 	ld	a, (0x05, sp)
      008E18 F7               [ 1]  607 	ld	(x), a
                                    608 ;	../src/stm8s_clk.c: 344: while((((CLK->SWCR & CLK_SWCR_SWBSY) != 0 )&& (DownCounter != 0)))
      008E19 5F               [ 1]  609 	clrw	x
      008E1A 5A               [ 2]  610 	decw	x
      008E1B                        611 00105$:
      008E1B C6 50 C5         [ 1]  612 	ld	a, 0x50c5
      008E1E 44               [ 1]  613 	srl	a
      008E1F 24 06            [ 1]  614 	jrnc	00107$
      008E21 5D               [ 2]  615 	tnzw	x
      008E22 27 03            [ 1]  616 	jreq	00107$
                                    617 ;	../src/stm8s_clk.c: 346: DownCounter--;
      008E24 5A               [ 2]  618 	decw	x
      008E25 20 F4            [ 2]  619 	jra	00105$
      008E27                        620 00107$:
                                    621 ;	../src/stm8s_clk.c: 349: if(DownCounter != 0)
      008E27 5D               [ 2]  622 	tnzw	x
      008E28 27 05            [ 1]  623 	jreq	00109$
                                    624 ;	../src/stm8s_clk.c: 351: Swif = SUCCESS;
      008E2A A6 01            [ 1]  625 	ld	a, #0x01
      008E2C 97               [ 1]  626 	ld	xl, a
      008E2D 20 37            [ 2]  627 	jra	00123$
      008E2F                        628 00109$:
                                    629 ;	../src/stm8s_clk.c: 355: Swif = ERROR;
      008E2F 4F               [ 1]  630 	clr	a
      008E30 97               [ 1]  631 	ld	xl, a
      008E31 20 33            [ 2]  632 	jra	00123$
      008E33                        633 00122$:
                                    634 ;	../src/stm8s_clk.c: 361: if (ITState != DISABLE)
      008E33 0D 06            [ 1]  635 	tnz	(0x06, sp)
      008E35 27 07            [ 1]  636 	jreq	00112$
                                    637 ;	../src/stm8s_clk.c: 363: CLK->SWCR |= CLK_SWCR_SWIEN;
      008E37 AA 04            [ 1]  638 	or	a, #0x04
      008E39 C7 50 C5         [ 1]  639 	ld	0x50c5, a
      008E3C 20 05            [ 2]  640 	jra	00113$
      008E3E                        641 00112$:
                                    642 ;	../src/stm8s_clk.c: 367: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      008E3E A4 FB            [ 1]  643 	and	a, #0xfb
      008E40 C7 50 C5         [ 1]  644 	ld	0x50c5, a
      008E43                        645 00113$:
                                    646 ;	../src/stm8s_clk.c: 371: CLK->SWR = (uint8_t)CLK_NewClock;
      008E43 AE 50 C4         [ 2]  647 	ldw	x, #0x50c4
      008E46 7B 05            [ 1]  648 	ld	a, (0x05, sp)
      008E48 F7               [ 1]  649 	ld	(x), a
                                    650 ;	../src/stm8s_clk.c: 374: while((((CLK->SWCR & CLK_SWCR_SWIF) != 0 ) && (DownCounter != 0)))
      008E49 5F               [ 1]  651 	clrw	x
      008E4A 5A               [ 2]  652 	decw	x
      008E4B                        653 00115$:
      008E4B C6 50 C5         [ 1]  654 	ld	a, 0x50c5
      008E4E A5 08            [ 1]  655 	bcp	a, #0x08
      008E50 27 06            [ 1]  656 	jreq	00117$
      008E52 5D               [ 2]  657 	tnzw	x
      008E53 27 03            [ 1]  658 	jreq	00117$
                                    659 ;	../src/stm8s_clk.c: 376: DownCounter--;
      008E55 5A               [ 2]  660 	decw	x
      008E56 20 F3            [ 2]  661 	jra	00115$
      008E58                        662 00117$:
                                    663 ;	../src/stm8s_clk.c: 379: if(DownCounter != 0)
      008E58 5D               [ 2]  664 	tnzw	x
      008E59 27 09            [ 1]  665 	jreq	00119$
                                    666 ;	../src/stm8s_clk.c: 382: CLK->SWCR |= CLK_SWCR_SWEN;
      008E5B 72 12 50 C5      [ 1]  667 	bset	20677, #1
                                    668 ;	../src/stm8s_clk.c: 383: Swif = SUCCESS;
      008E5F A6 01            [ 1]  669 	ld	a, #0x01
      008E61 97               [ 1]  670 	ld	xl, a
      008E62 20 02            [ 2]  671 	jra	00123$
      008E64                        672 00119$:
                                    673 ;	../src/stm8s_clk.c: 387: Swif = ERROR;
      008E64 4F               [ 1]  674 	clr	a
      008E65 97               [ 1]  675 	ld	xl, a
      008E66                        676 00123$:
                                    677 ;	../src/stm8s_clk.c: 390: if(Swif != ERROR)
      008E66 9F               [ 1]  678 	ld	a, xl
      008E67 4D               [ 1]  679 	tnz	a
      008E68 27 2E            [ 1]  680 	jreq	00136$
                                    681 ;	../src/stm8s_clk.c: 393: if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSI))
      008E6A 0D 07            [ 1]  682 	tnz	(0x07, sp)
      008E6C 26 0C            [ 1]  683 	jrne	00132$
      008E6E 90 9F            [ 1]  684 	ld	a, yl
      008E70 A1 E1            [ 1]  685 	cp	a, #0xe1
      008E72 26 06            [ 1]  686 	jrne	00132$
                                    687 ;	../src/stm8s_clk.c: 395: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      008E74 72 11 50 C0      [ 1]  688 	bres	20672, #0
      008E78 20 1E            [ 2]  689 	jra	00136$
      008E7A                        690 00132$:
                                    691 ;	../src/stm8s_clk.c: 397: else if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_LSI))
      008E7A 0D 07            [ 1]  692 	tnz	(0x07, sp)
      008E7C 26 0C            [ 1]  693 	jrne	00128$
      008E7E 90 9F            [ 1]  694 	ld	a, yl
      008E80 A1 D2            [ 1]  695 	cp	a, #0xd2
      008E82 26 06            [ 1]  696 	jrne	00128$
                                    697 ;	../src/stm8s_clk.c: 399: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      008E84 72 17 50 C0      [ 1]  698 	bres	20672, #3
      008E88 20 0E            [ 2]  699 	jra	00136$
      008E8A                        700 00128$:
                                    701 ;	../src/stm8s_clk.c: 401: else if ((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSE))
      008E8A 0D 07            [ 1]  702 	tnz	(0x07, sp)
      008E8C 26 0A            [ 1]  703 	jrne	00136$
      008E8E 90 9F            [ 1]  704 	ld	a, yl
      008E90 A1 B4            [ 1]  705 	cp	a, #0xb4
      008E92 26 04            [ 1]  706 	jrne	00136$
                                    707 ;	../src/stm8s_clk.c: 403: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      008E94 72 11 50 C1      [ 1]  708 	bres	20673, #0
      008E98                        709 00136$:
                                    710 ;	../src/stm8s_clk.c: 406: return(Swif);
      008E98 9F               [ 1]  711 	ld	a, xl
                                    712 ;	../src/stm8s_clk.c: 407: }
      008E99 5B 01            [ 2]  713 	addw	sp, #1
      008E9B 81               [ 4]  714 	ret
                                    715 ;	../src/stm8s_clk.c: 415: void CLK_HSIPrescalerConfig(CLK_Prescaler_TypeDef HSIPrescaler)
                                    716 ;	-----------------------------------------
                                    717 ;	 function CLK_HSIPrescalerConfig
                                    718 ;	-----------------------------------------
      008E9C                        719 _CLK_HSIPrescalerConfig:
                                    720 ;	../src/stm8s_clk.c: 418: assert_param(IS_CLK_HSIPRESCALER_OK(HSIPrescaler));
      008E9C 0D 03            [ 1]  721 	tnz	(0x03, sp)
      008E9E 27 21            [ 1]  722 	jreq	00104$
      008EA0 7B 03            [ 1]  723 	ld	a, (0x03, sp)
      008EA2 A1 08            [ 1]  724 	cp	a, #0x08
      008EA4 27 1B            [ 1]  725 	jreq	00104$
      008EA6 7B 03            [ 1]  726 	ld	a, (0x03, sp)
      008EA8 A1 10            [ 1]  727 	cp	a, #0x10
      008EAA 27 15            [ 1]  728 	jreq	00104$
      008EAC 7B 03            [ 1]  729 	ld	a, (0x03, sp)
      008EAE A1 18            [ 1]  730 	cp	a, #0x18
      008EB0 27 0F            [ 1]  731 	jreq	00104$
      008EB2 4B A2            [ 1]  732 	push	#0xa2
      008EB4 4B 01            [ 1]  733 	push	#0x01
      008EB6 5F               [ 1]  734 	clrw	x
      008EB7 89               [ 2]  735 	pushw	x
      008EB8 4B 24            [ 1]  736 	push	#<___str_0
      008EBA 4B 82            [ 1]  737 	push	#(___str_0 >> 8)
      008EBC CD 82 CE         [ 4]  738 	call	_assert_failed
      008EBF 5B 06            [ 2]  739 	addw	sp, #6
      008EC1                        740 00104$:
                                    741 ;	../src/stm8s_clk.c: 421: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      008EC1 C6 50 C6         [ 1]  742 	ld	a, 0x50c6
      008EC4 A4 E7            [ 1]  743 	and	a, #0xe7
      008EC6 C7 50 C6         [ 1]  744 	ld	0x50c6, a
                                    745 ;	../src/stm8s_clk.c: 424: CLK->CKDIVR |= (uint8_t)HSIPrescaler;
      008EC9 C6 50 C6         [ 1]  746 	ld	a, 0x50c6
      008ECC 1A 03            [ 1]  747 	or	a, (0x03, sp)
      008ECE C7 50 C6         [ 1]  748 	ld	0x50c6, a
                                    749 ;	../src/stm8s_clk.c: 425: }
      008ED1 81               [ 4]  750 	ret
                                    751 ;	../src/stm8s_clk.c: 436: void CLK_CCOConfig(CLK_Output_TypeDef CLK_CCO)
                                    752 ;	-----------------------------------------
                                    753 ;	 function CLK_CCOConfig
                                    754 ;	-----------------------------------------
      008ED2                        755 _CLK_CCOConfig:
                                    756 ;	../src/stm8s_clk.c: 439: assert_param(IS_CLK_OUTPUT_OK(CLK_CCO));
      008ED2 0D 03            [ 1]  757 	tnz	(0x03, sp)
      008ED4 27 57            [ 1]  758 	jreq	00104$
      008ED6 7B 03            [ 1]  759 	ld	a, (0x03, sp)
      008ED8 A1 04            [ 1]  760 	cp	a, #0x04
      008EDA 27 51            [ 1]  761 	jreq	00104$
      008EDC 7B 03            [ 1]  762 	ld	a, (0x03, sp)
      008EDE A1 02            [ 1]  763 	cp	a, #0x02
      008EE0 27 4B            [ 1]  764 	jreq	00104$
      008EE2 7B 03            [ 1]  765 	ld	a, (0x03, sp)
      008EE4 A1 08            [ 1]  766 	cp	a, #0x08
      008EE6 27 45            [ 1]  767 	jreq	00104$
      008EE8 7B 03            [ 1]  768 	ld	a, (0x03, sp)
      008EEA A1 0A            [ 1]  769 	cp	a, #0x0a
      008EEC 27 3F            [ 1]  770 	jreq	00104$
      008EEE 7B 03            [ 1]  771 	ld	a, (0x03, sp)
      008EF0 A1 0C            [ 1]  772 	cp	a, #0x0c
      008EF2 27 39            [ 1]  773 	jreq	00104$
      008EF4 7B 03            [ 1]  774 	ld	a, (0x03, sp)
      008EF6 A1 0E            [ 1]  775 	cp	a, #0x0e
      008EF8 27 33            [ 1]  776 	jreq	00104$
      008EFA 7B 03            [ 1]  777 	ld	a, (0x03, sp)
      008EFC A1 10            [ 1]  778 	cp	a, #0x10
      008EFE 27 2D            [ 1]  779 	jreq	00104$
      008F00 7B 03            [ 1]  780 	ld	a, (0x03, sp)
      008F02 A1 12            [ 1]  781 	cp	a, #0x12
      008F04 27 27            [ 1]  782 	jreq	00104$
      008F06 7B 03            [ 1]  783 	ld	a, (0x03, sp)
      008F08 A1 14            [ 1]  784 	cp	a, #0x14
      008F0A 27 21            [ 1]  785 	jreq	00104$
      008F0C 7B 03            [ 1]  786 	ld	a, (0x03, sp)
      008F0E A1 16            [ 1]  787 	cp	a, #0x16
      008F10 27 1B            [ 1]  788 	jreq	00104$
      008F12 7B 03            [ 1]  789 	ld	a, (0x03, sp)
      008F14 A1 18            [ 1]  790 	cp	a, #0x18
      008F16 27 15            [ 1]  791 	jreq	00104$
      008F18 7B 03            [ 1]  792 	ld	a, (0x03, sp)
      008F1A A1 1A            [ 1]  793 	cp	a, #0x1a
      008F1C 27 0F            [ 1]  794 	jreq	00104$
      008F1E 4B B7            [ 1]  795 	push	#0xb7
      008F20 4B 01            [ 1]  796 	push	#0x01
      008F22 5F               [ 1]  797 	clrw	x
      008F23 89               [ 2]  798 	pushw	x
      008F24 4B 24            [ 1]  799 	push	#<___str_0
      008F26 4B 82            [ 1]  800 	push	#(___str_0 >> 8)
      008F28 CD 82 CE         [ 4]  801 	call	_assert_failed
      008F2B 5B 06            [ 2]  802 	addw	sp, #6
      008F2D                        803 00104$:
                                    804 ;	../src/stm8s_clk.c: 442: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOSEL);
      008F2D C6 50 C9         [ 1]  805 	ld	a, 0x50c9
      008F30 A4 E1            [ 1]  806 	and	a, #0xe1
      008F32 C7 50 C9         [ 1]  807 	ld	0x50c9, a
                                    808 ;	../src/stm8s_clk.c: 445: CLK->CCOR |= (uint8_t)CLK_CCO;
      008F35 C6 50 C9         [ 1]  809 	ld	a, 0x50c9
      008F38 1A 03            [ 1]  810 	or	a, (0x03, sp)
      008F3A C7 50 C9         [ 1]  811 	ld	0x50c9, a
                                    812 ;	../src/stm8s_clk.c: 448: CLK->CCOR |= CLK_CCOR_CCOEN;
      008F3D 72 10 50 C9      [ 1]  813 	bset	20681, #0
                                    814 ;	../src/stm8s_clk.c: 449: }
      008F41 81               [ 4]  815 	ret
                                    816 ;	../src/stm8s_clk.c: 459: void CLK_ITConfig(CLK_IT_TypeDef CLK_IT, FunctionalState NewState)
                                    817 ;	-----------------------------------------
                                    818 ;	 function CLK_ITConfig
                                    819 ;	-----------------------------------------
      008F42                        820 _CLK_ITConfig:
      008F42 88               [ 1]  821 	push	a
                                    822 ;	../src/stm8s_clk.c: 462: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008F43 0D 05            [ 1]  823 	tnz	(0x05, sp)
      008F45 27 14            [ 1]  824 	jreq	00115$
      008F47 7B 05            [ 1]  825 	ld	a, (0x05, sp)
      008F49 4A               [ 1]  826 	dec	a
      008F4A 27 0F            [ 1]  827 	jreq	00115$
      008F4C 4B CE            [ 1]  828 	push	#0xce
      008F4E 4B 01            [ 1]  829 	push	#0x01
      008F50 5F               [ 1]  830 	clrw	x
      008F51 89               [ 2]  831 	pushw	x
      008F52 4B 24            [ 1]  832 	push	#<___str_0
      008F54 4B 82            [ 1]  833 	push	#(___str_0 >> 8)
      008F56 CD 82 CE         [ 4]  834 	call	_assert_failed
      008F59 5B 06            [ 2]  835 	addw	sp, #6
      008F5B                        836 00115$:
                                    837 ;	../src/stm8s_clk.c: 463: assert_param(IS_CLK_IT_OK(CLK_IT));
      008F5B 7B 04            [ 1]  838 	ld	a, (0x04, sp)
      008F5D A0 0C            [ 1]  839 	sub	a, #0x0c
      008F5F 26 04            [ 1]  840 	jrne	00174$
      008F61 4C               [ 1]  841 	inc	a
      008F62 6B 01            [ 1]  842 	ld	(0x01, sp), a
      008F64 C1                     843 	.byte 0xc1
      008F65                        844 00174$:
      008F65 0F 01            [ 1]  845 	clr	(0x01, sp)
      008F67                        846 00175$:
      008F67 7B 04            [ 1]  847 	ld	a, (0x04, sp)
      008F69 A0 1C            [ 1]  848 	sub	a, #0x1c
      008F6B 26 02            [ 1]  849 	jrne	00177$
      008F6D 4C               [ 1]  850 	inc	a
      008F6E 21                     851 	.byte 0x21
      008F6F                        852 00177$:
      008F6F 4F               [ 1]  853 	clr	a
      008F70                        854 00178$:
      008F70 0D 01            [ 1]  855 	tnz	(0x01, sp)
      008F72 26 14            [ 1]  856 	jrne	00120$
      008F74 4D               [ 1]  857 	tnz	a
      008F75 26 11            [ 1]  858 	jrne	00120$
      008F77 88               [ 1]  859 	push	a
      008F78 4B CF            [ 1]  860 	push	#0xcf
      008F7A 4B 01            [ 1]  861 	push	#0x01
      008F7C 5F               [ 1]  862 	clrw	x
      008F7D 89               [ 2]  863 	pushw	x
      008F7E 4B 24            [ 1]  864 	push	#<___str_0
      008F80 4B 82            [ 1]  865 	push	#(___str_0 >> 8)
      008F82 CD 82 CE         [ 4]  866 	call	_assert_failed
      008F85 5B 06            [ 2]  867 	addw	sp, #6
      008F87 84               [ 1]  868 	pop	a
      008F88                        869 00120$:
                                    870 ;	../src/stm8s_clk.c: 465: if (NewState != DISABLE)
      008F88 0D 05            [ 1]  871 	tnz	(0x05, sp)
      008F8A 27 13            [ 1]  872 	jreq	00110$
                                    873 ;	../src/stm8s_clk.c: 467: switch (CLK_IT)
      008F8C 0D 01            [ 1]  874 	tnz	(0x01, sp)
      008F8E 26 09            [ 1]  875 	jrne	00102$
      008F90 4D               [ 1]  876 	tnz	a
      008F91 27 1D            [ 1]  877 	jreq	00112$
                                    878 ;	../src/stm8s_clk.c: 470: CLK->SWCR |= CLK_SWCR_SWIEN;
      008F93 72 14 50 C5      [ 1]  879 	bset	20677, #2
                                    880 ;	../src/stm8s_clk.c: 471: break;
      008F97 20 17            [ 2]  881 	jra	00112$
                                    882 ;	../src/stm8s_clk.c: 472: case CLK_IT_CSSD: /* Enable the clock security system detection interrupt */
      008F99                        883 00102$:
                                    884 ;	../src/stm8s_clk.c: 473: CLK->CSSR |= CLK_CSSR_CSSDIE;
      008F99 72 14 50 C8      [ 1]  885 	bset	20680, #2
                                    886 ;	../src/stm8s_clk.c: 474: break;
      008F9D 20 11            [ 2]  887 	jra	00112$
                                    888 ;	../src/stm8s_clk.c: 477: }
      008F9F                        889 00110$:
                                    890 ;	../src/stm8s_clk.c: 481: switch (CLK_IT)
      008F9F 0D 01            [ 1]  891 	tnz	(0x01, sp)
      008FA1 26 09            [ 1]  892 	jrne	00106$
      008FA3 4D               [ 1]  893 	tnz	a
      008FA4 27 0A            [ 1]  894 	jreq	00112$
                                    895 ;	../src/stm8s_clk.c: 484: CLK->SWCR  &= (uint8_t)(~CLK_SWCR_SWIEN);
      008FA6 72 15 50 C5      [ 1]  896 	bres	20677, #2
                                    897 ;	../src/stm8s_clk.c: 485: break;
      008FAA 20 04            [ 2]  898 	jra	00112$
                                    899 ;	../src/stm8s_clk.c: 486: case CLK_IT_CSSD: /* Disable the clock security system detection interrupt */
      008FAC                        900 00106$:
                                    901 ;	../src/stm8s_clk.c: 487: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSDIE);
      008FAC 72 15 50 C8      [ 1]  902 	bres	20680, #2
                                    903 ;	../src/stm8s_clk.c: 491: }
      008FB0                        904 00112$:
                                    905 ;	../src/stm8s_clk.c: 493: }
      008FB0 84               [ 1]  906 	pop	a
      008FB1 81               [ 4]  907 	ret
                                    908 ;	../src/stm8s_clk.c: 500: void CLK_SYSCLKConfig(CLK_Prescaler_TypeDef CLK_Prescaler)
                                    909 ;	-----------------------------------------
                                    910 ;	 function CLK_SYSCLKConfig
                                    911 ;	-----------------------------------------
      008FB2                        912 _CLK_SYSCLKConfig:
      008FB2 89               [ 2]  913 	pushw	x
                                    914 ;	../src/stm8s_clk.c: 503: assert_param(IS_CLK_PRESCALER_OK(CLK_Prescaler));
      008FB3 0D 05            [ 1]  915 	tnz	(0x05, sp)
      008FB5 27 51            [ 1]  916 	jreq	00107$
      008FB7 7B 05            [ 1]  917 	ld	a, (0x05, sp)
      008FB9 A1 08            [ 1]  918 	cp	a, #0x08
      008FBB 27 4B            [ 1]  919 	jreq	00107$
      008FBD 7B 05            [ 1]  920 	ld	a, (0x05, sp)
      008FBF A1 10            [ 1]  921 	cp	a, #0x10
      008FC1 27 45            [ 1]  922 	jreq	00107$
      008FC3 7B 05            [ 1]  923 	ld	a, (0x05, sp)
      008FC5 A1 18            [ 1]  924 	cp	a, #0x18
      008FC7 27 3F            [ 1]  925 	jreq	00107$
      008FC9 7B 05            [ 1]  926 	ld	a, (0x05, sp)
      008FCB A1 80            [ 1]  927 	cp	a, #0x80
      008FCD 27 39            [ 1]  928 	jreq	00107$
      008FCF 7B 05            [ 1]  929 	ld	a, (0x05, sp)
      008FD1 A1 81            [ 1]  930 	cp	a, #0x81
      008FD3 27 33            [ 1]  931 	jreq	00107$
      008FD5 7B 05            [ 1]  932 	ld	a, (0x05, sp)
      008FD7 A1 82            [ 1]  933 	cp	a, #0x82
      008FD9 27 2D            [ 1]  934 	jreq	00107$
      008FDB 7B 05            [ 1]  935 	ld	a, (0x05, sp)
      008FDD A1 83            [ 1]  936 	cp	a, #0x83
      008FDF 27 27            [ 1]  937 	jreq	00107$
      008FE1 7B 05            [ 1]  938 	ld	a, (0x05, sp)
      008FE3 A1 84            [ 1]  939 	cp	a, #0x84
      008FE5 27 21            [ 1]  940 	jreq	00107$
      008FE7 7B 05            [ 1]  941 	ld	a, (0x05, sp)
      008FE9 A1 85            [ 1]  942 	cp	a, #0x85
      008FEB 27 1B            [ 1]  943 	jreq	00107$
      008FED 7B 05            [ 1]  944 	ld	a, (0x05, sp)
      008FEF A1 86            [ 1]  945 	cp	a, #0x86
      008FF1 27 15            [ 1]  946 	jreq	00107$
      008FF3 7B 05            [ 1]  947 	ld	a, (0x05, sp)
      008FF5 A1 87            [ 1]  948 	cp	a, #0x87
      008FF7 27 0F            [ 1]  949 	jreq	00107$
      008FF9 4B F7            [ 1]  950 	push	#0xf7
      008FFB 4B 01            [ 1]  951 	push	#0x01
      008FFD 5F               [ 1]  952 	clrw	x
      008FFE 89               [ 2]  953 	pushw	x
      008FFF 4B 24            [ 1]  954 	push	#<___str_0
      009001 4B 82            [ 1]  955 	push	#(___str_0 >> 8)
      009003 CD 82 CE         [ 4]  956 	call	_assert_failed
      009006 5B 06            [ 2]  957 	addw	sp, #6
      009008                        958 00107$:
                                    959 ;	../src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      009008 C6 50 C6         [ 1]  960 	ld	a, 0x50c6
                                    961 ;	../src/stm8s_clk.c: 505: if (((uint8_t)CLK_Prescaler & (uint8_t)0x80) == 0x00) /* Bit7 = 0 means HSI divider */
      00900B 0D 05            [ 1]  962 	tnz	(0x05, sp)
      00900D 2B 15            [ 1]  963 	jrmi	00102$
                                    964 ;	../src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      00900F A4 E7            [ 1]  965 	and	a, #0xe7
      009011 C7 50 C6         [ 1]  966 	ld	0x50c6, a
                                    967 ;	../src/stm8s_clk.c: 508: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_HSIDIV);
      009014 C6 50 C6         [ 1]  968 	ld	a, 0x50c6
      009017 6B 02            [ 1]  969 	ld	(0x02, sp), a
      009019 7B 05            [ 1]  970 	ld	a, (0x05, sp)
      00901B A4 18            [ 1]  971 	and	a, #0x18
      00901D 1A 02            [ 1]  972 	or	a, (0x02, sp)
      00901F C7 50 C6         [ 1]  973 	ld	0x50c6, a
      009022 20 13            [ 2]  974 	jra	00104$
      009024                        975 00102$:
                                    976 ;	../src/stm8s_clk.c: 512: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_CPUDIV);
      009024 A4 F8            [ 1]  977 	and	a, #0xf8
      009026 C7 50 C6         [ 1]  978 	ld	0x50c6, a
                                    979 ;	../src/stm8s_clk.c: 513: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_CPUDIV);
      009029 C6 50 C6         [ 1]  980 	ld	a, 0x50c6
      00902C 6B 01            [ 1]  981 	ld	(0x01, sp), a
      00902E 7B 05            [ 1]  982 	ld	a, (0x05, sp)
      009030 A4 07            [ 1]  983 	and	a, #0x07
      009032 1A 01            [ 1]  984 	or	a, (0x01, sp)
      009034 C7 50 C6         [ 1]  985 	ld	0x50c6, a
      009037                        986 00104$:
                                    987 ;	../src/stm8s_clk.c: 515: }
      009037 85               [ 2]  988 	popw	x
      009038 81               [ 4]  989 	ret
                                    990 ;	../src/stm8s_clk.c: 523: void CLK_SWIMConfig(CLK_SWIMDivider_TypeDef CLK_SWIMDivider)
                                    991 ;	-----------------------------------------
                                    992 ;	 function CLK_SWIMConfig
                                    993 ;	-----------------------------------------
      009039                        994 _CLK_SWIMConfig:
                                    995 ;	../src/stm8s_clk.c: 526: assert_param(IS_CLK_SWIMDIVIDER_OK(CLK_SWIMDivider));
      009039 0D 03            [ 1]  996 	tnz	(0x03, sp)
      00903B 27 14            [ 1]  997 	jreq	00107$
      00903D 7B 03            [ 1]  998 	ld	a, (0x03, sp)
      00903F 4A               [ 1]  999 	dec	a
      009040 27 0F            [ 1] 1000 	jreq	00107$
      009042 4B 0E            [ 1] 1001 	push	#0x0e
      009044 4B 02            [ 1] 1002 	push	#0x02
      009046 5F               [ 1] 1003 	clrw	x
      009047 89               [ 2] 1004 	pushw	x
      009048 4B 24            [ 1] 1005 	push	#<___str_0
      00904A 4B 82            [ 1] 1006 	push	#(___str_0 >> 8)
      00904C CD 82 CE         [ 4] 1007 	call	_assert_failed
      00904F 5B 06            [ 2] 1008 	addw	sp, #6
      009051                       1009 00107$:
                                   1010 ;	../src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
      009051 C6 50 CD         [ 1] 1011 	ld	a, 0x50cd
                                   1012 ;	../src/stm8s_clk.c: 528: if (CLK_SWIMDivider != CLK_SWIMDIVIDER_2)
      009054 0D 03            [ 1] 1013 	tnz	(0x03, sp)
      009056 27 06            [ 1] 1014 	jreq	00102$
                                   1015 ;	../src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
      009058 AA 01            [ 1] 1016 	or	a, #0x01
      00905A C7 50 CD         [ 1] 1017 	ld	0x50cd, a
      00905D 81               [ 4] 1018 	ret
      00905E                       1019 00102$:
                                   1020 ;	../src/stm8s_clk.c: 536: CLK->SWIMCCR &= (uint8_t)(~CLK_SWIMCCR_SWIMDIV);
      00905E A4 FE            [ 1] 1021 	and	a, #0xfe
      009060 C7 50 CD         [ 1] 1022 	ld	0x50cd, a
                                   1023 ;	../src/stm8s_clk.c: 538: }
      009063 81               [ 4] 1024 	ret
                                   1025 ;	../src/stm8s_clk.c: 547: void CLK_ClockSecuritySystemEnable(void)
                                   1026 ;	-----------------------------------------
                                   1027 ;	 function CLK_ClockSecuritySystemEnable
                                   1028 ;	-----------------------------------------
      009064                       1029 _CLK_ClockSecuritySystemEnable:
                                   1030 ;	../src/stm8s_clk.c: 550: CLK->CSSR |= CLK_CSSR_CSSEN;
      009064 72 10 50 C8      [ 1] 1031 	bset	20680, #0
                                   1032 ;	../src/stm8s_clk.c: 551: }
      009068 81               [ 4] 1033 	ret
                                   1034 ;	../src/stm8s_clk.c: 559: CLK_Source_TypeDef CLK_GetSYSCLKSource(void)
                                   1035 ;	-----------------------------------------
                                   1036 ;	 function CLK_GetSYSCLKSource
                                   1037 ;	-----------------------------------------
      009069                       1038 _CLK_GetSYSCLKSource:
                                   1039 ;	../src/stm8s_clk.c: 561: return((CLK_Source_TypeDef)CLK->CMSR);
      009069 C6 50 C3         [ 1] 1040 	ld	a, 0x50c3
                                   1041 ;	../src/stm8s_clk.c: 562: }
      00906C 81               [ 4] 1042 	ret
                                   1043 ;	../src/stm8s_clk.c: 569: uint32_t CLK_GetClockFreq(void)
                                   1044 ;	-----------------------------------------
                                   1045 ;	 function CLK_GetClockFreq
                                   1046 ;	-----------------------------------------
      00906D                       1047 _CLK_GetClockFreq:
      00906D 52 05            [ 2] 1048 	sub	sp, #5
                                   1049 ;	../src/stm8s_clk.c: 576: clocksource = (CLK_Source_TypeDef)CLK->CMSR;
      00906F C6 50 C3         [ 1] 1050 	ld	a, 0x50c3
      009072 6B 01            [ 1] 1051 	ld	(0x01, sp), a
                                   1052 ;	../src/stm8s_clk.c: 578: if (clocksource == CLK_SOURCE_HSI)
      009074 7B 01            [ 1] 1053 	ld	a, (0x01, sp)
      009076 A1 E1            [ 1] 1054 	cp	a, #0xe1
      009078 26 22            [ 1] 1055 	jrne	00105$
                                   1056 ;	../src/stm8s_clk.c: 580: tmp = (uint8_t)(CLK->CKDIVR & CLK_CKDIVR_HSIDIV);
      00907A C6 50 C6         [ 1] 1057 	ld	a, 0x50c6
      00907D A4 18            [ 1] 1058 	and	a, #0x18
                                   1059 ;	../src/stm8s_clk.c: 581: tmp = (uint8_t)(tmp >> 3);
      00907F 44               [ 1] 1060 	srl	a
      009080 44               [ 1] 1061 	srl	a
      009081 44               [ 1] 1062 	srl	a
                                   1063 ;	../src/stm8s_clk.c: 582: clockfrequency = HSI_VALUE >> HSIDivExp[tmp];
      009082 5F               [ 1] 1064 	clrw	x
      009083 97               [ 1] 1065 	ld	xl, a
      009084 1C 82 18         [ 2] 1066 	addw	x, #_HSIDivExp
      009087 F6               [ 1] 1067 	ld	a, (x)
      009088 AE 24 00         [ 2] 1068 	ldw	x, #0x2400
      00908B 90 AE 00 F4      [ 2] 1069 	ldw	y, #0x00f4
      00908F 4D               [ 1] 1070 	tnz	a
      009090 27 06            [ 1] 1071 	jreq	00123$
      009092                       1072 00122$:
      009092 90 54            [ 2] 1073 	srlw	y
      009094 56               [ 2] 1074 	rrcw	x
      009095 4A               [ 1] 1075 	dec	a
      009096 26 FA            [ 1] 1076 	jrne	00122$
      009098                       1077 00123$:
      009098 1F 04            [ 2] 1078 	ldw	(0x04, sp), x
      00909A 20 1A            [ 2] 1079 	jra	00106$
      00909C                       1080 00105$:
                                   1081 ;	../src/stm8s_clk.c: 584: else if ( clocksource == CLK_SOURCE_LSI)
      00909C 7B 01            [ 1] 1082 	ld	a, (0x01, sp)
      00909E A1 D2            [ 1] 1083 	cp	a, #0xd2
      0090A0 26 0B            [ 1] 1084 	jrne	00102$
                                   1085 ;	../src/stm8s_clk.c: 586: clockfrequency = LSI_VALUE;
      0090A2 AE F4 00         [ 2] 1086 	ldw	x, #0xf400
      0090A5 1F 04            [ 2] 1087 	ldw	(0x04, sp), x
      0090A7 90 AE 00 01      [ 2] 1088 	ldw	y, #0x0001
      0090AB 20 09            [ 2] 1089 	jra	00106$
      0090AD                       1090 00102$:
                                   1091 ;	../src/stm8s_clk.c: 590: clockfrequency = HSE_VALUE;
      0090AD AE 24 00         [ 2] 1092 	ldw	x, #0x2400
      0090B0 1F 04            [ 2] 1093 	ldw	(0x04, sp), x
      0090B2 90 AE 00 F4      [ 2] 1094 	ldw	y, #0x00f4
      0090B6                       1095 00106$:
                                   1096 ;	../src/stm8s_clk.c: 593: return((uint32_t)clockfrequency);
      0090B6 1E 04            [ 2] 1097 	ldw	x, (0x04, sp)
                                   1098 ;	../src/stm8s_clk.c: 594: }
      0090B8 5B 05            [ 2] 1099 	addw	sp, #5
      0090BA 81               [ 4] 1100 	ret
                                   1101 ;	../src/stm8s_clk.c: 603: void CLK_AdjustHSICalibrationValue(CLK_HSITrimValue_TypeDef CLK_HSICalibrationValue)
                                   1102 ;	-----------------------------------------
                                   1103 ;	 function CLK_AdjustHSICalibrationValue
                                   1104 ;	-----------------------------------------
      0090BB                       1105 _CLK_AdjustHSICalibrationValue:
                                   1106 ;	../src/stm8s_clk.c: 606: assert_param(IS_CLK_HSITRIMVALUE_OK(CLK_HSICalibrationValue));
      0090BB 0D 03            [ 1] 1107 	tnz	(0x03, sp)
      0090BD 27 38            [ 1] 1108 	jreq	00104$
      0090BF 7B 03            [ 1] 1109 	ld	a, (0x03, sp)
      0090C1 4A               [ 1] 1110 	dec	a
      0090C2 27 33            [ 1] 1111 	jreq	00104$
      0090C4 7B 03            [ 1] 1112 	ld	a, (0x03, sp)
      0090C6 A1 02            [ 1] 1113 	cp	a, #0x02
      0090C8 27 2D            [ 1] 1114 	jreq	00104$
      0090CA 7B 03            [ 1] 1115 	ld	a, (0x03, sp)
      0090CC A1 03            [ 1] 1116 	cp	a, #0x03
      0090CE 27 27            [ 1] 1117 	jreq	00104$
      0090D0 7B 03            [ 1] 1118 	ld	a, (0x03, sp)
      0090D2 A1 04            [ 1] 1119 	cp	a, #0x04
      0090D4 27 21            [ 1] 1120 	jreq	00104$
      0090D6 7B 03            [ 1] 1121 	ld	a, (0x03, sp)
      0090D8 A1 05            [ 1] 1122 	cp	a, #0x05
      0090DA 27 1B            [ 1] 1123 	jreq	00104$
      0090DC 7B 03            [ 1] 1124 	ld	a, (0x03, sp)
      0090DE A1 06            [ 1] 1125 	cp	a, #0x06
      0090E0 27 15            [ 1] 1126 	jreq	00104$
      0090E2 7B 03            [ 1] 1127 	ld	a, (0x03, sp)
      0090E4 A1 07            [ 1] 1128 	cp	a, #0x07
      0090E6 27 0F            [ 1] 1129 	jreq	00104$
      0090E8 4B 5E            [ 1] 1130 	push	#0x5e
      0090EA 4B 02            [ 1] 1131 	push	#0x02
      0090EC 5F               [ 1] 1132 	clrw	x
      0090ED 89               [ 2] 1133 	pushw	x
      0090EE 4B 24            [ 1] 1134 	push	#<___str_0
      0090F0 4B 82            [ 1] 1135 	push	#(___str_0 >> 8)
      0090F2 CD 82 CE         [ 4] 1136 	call	_assert_failed
      0090F5 5B 06            [ 2] 1137 	addw	sp, #6
      0090F7                       1138 00104$:
                                   1139 ;	../src/stm8s_clk.c: 609: CLK->HSITRIMR = (uint8_t)( (uint8_t)(CLK->HSITRIMR & (uint8_t)(~CLK_HSITRIMR_HSITRIM))|((uint8_t)CLK_HSICalibrationValue));
      0090F7 C6 50 CC         [ 1] 1140 	ld	a, 0x50cc
      0090FA A4 F8            [ 1] 1141 	and	a, #0xf8
      0090FC 1A 03            [ 1] 1142 	or	a, (0x03, sp)
      0090FE C7 50 CC         [ 1] 1143 	ld	0x50cc, a
                                   1144 ;	../src/stm8s_clk.c: 610: }
      009101 81               [ 4] 1145 	ret
                                   1146 ;	../src/stm8s_clk.c: 621: void CLK_SYSCLKEmergencyClear(void)
                                   1147 ;	-----------------------------------------
                                   1148 ;	 function CLK_SYSCLKEmergencyClear
                                   1149 ;	-----------------------------------------
      009102                       1150 _CLK_SYSCLKEmergencyClear:
                                   1151 ;	../src/stm8s_clk.c: 623: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWBSY);
      009102 72 11 50 C5      [ 1] 1152 	bres	20677, #0
                                   1153 ;	../src/stm8s_clk.c: 624: }
      009106 81               [ 4] 1154 	ret
                                   1155 ;	../src/stm8s_clk.c: 633: FlagStatus CLK_GetFlagStatus(CLK_Flag_TypeDef CLK_FLAG)
                                   1156 ;	-----------------------------------------
                                   1157 ;	 function CLK_GetFlagStatus
                                   1158 ;	-----------------------------------------
      009107                       1159 _CLK_GetFlagStatus:
      009107 88               [ 1] 1160 	push	a
                                   1161 ;	../src/stm8s_clk.c: 640: assert_param(IS_CLK_FLAG_OK(CLK_FLAG));
      009108 1E 04            [ 2] 1162 	ldw	x, (0x04, sp)
      00910A A3 01 10         [ 2] 1163 	cpw	x, #0x0110
      00910D 27 47            [ 1] 1164 	jreq	00119$
      00910F 1E 04            [ 2] 1165 	ldw	x, (0x04, sp)
      009111 A3 01 02         [ 2] 1166 	cpw	x, #0x0102
      009114 27 40            [ 1] 1167 	jreq	00119$
      009116 1E 04            [ 2] 1168 	ldw	x, (0x04, sp)
      009118 A3 02 02         [ 2] 1169 	cpw	x, #0x0202
      00911B 27 39            [ 1] 1170 	jreq	00119$
      00911D 1E 04            [ 2] 1171 	ldw	x, (0x04, sp)
      00911F A3 03 08         [ 2] 1172 	cpw	x, #0x0308
      009122 27 32            [ 1] 1173 	jreq	00119$
      009124 1E 04            [ 2] 1174 	ldw	x, (0x04, sp)
      009126 A3 03 01         [ 2] 1175 	cpw	x, #0x0301
      009129 27 2B            [ 1] 1176 	jreq	00119$
      00912B 1E 04            [ 2] 1177 	ldw	x, (0x04, sp)
      00912D A3 04 08         [ 2] 1178 	cpw	x, #0x0408
      009130 27 24            [ 1] 1179 	jreq	00119$
      009132 1E 04            [ 2] 1180 	ldw	x, (0x04, sp)
      009134 A3 04 02         [ 2] 1181 	cpw	x, #0x0402
      009137 27 1D            [ 1] 1182 	jreq	00119$
      009139 1E 04            [ 2] 1183 	ldw	x, (0x04, sp)
      00913B A3 05 04         [ 2] 1184 	cpw	x, #0x0504
      00913E 27 16            [ 1] 1185 	jreq	00119$
      009140 1E 04            [ 2] 1186 	ldw	x, (0x04, sp)
      009142 A3 05 02         [ 2] 1187 	cpw	x, #0x0502
      009145 27 0F            [ 1] 1188 	jreq	00119$
      009147 4B 80            [ 1] 1189 	push	#0x80
      009149 4B 02            [ 1] 1190 	push	#0x02
      00914B 5F               [ 1] 1191 	clrw	x
      00914C 89               [ 2] 1192 	pushw	x
      00914D 4B 24            [ 1] 1193 	push	#<___str_0
      00914F 4B 82            [ 1] 1194 	push	#(___str_0 >> 8)
      009151 CD 82 CE         [ 4] 1195 	call	_assert_failed
      009154 5B 06            [ 2] 1196 	addw	sp, #6
      009156                       1197 00119$:
                                   1198 ;	../src/stm8s_clk.c: 643: statusreg = (uint16_t)((uint16_t)CLK_FLAG & (uint16_t)0xFF00);
      009156 4F               [ 1] 1199 	clr	a
      009157 97               [ 1] 1200 	ld	xl, a
      009158 7B 04            [ 1] 1201 	ld	a, (0x04, sp)
      00915A 95               [ 1] 1202 	ld	xh, a
                                   1203 ;	../src/stm8s_clk.c: 646: if (statusreg == 0x0100) /* The flag to check is in ICKRregister */
      00915B A3 01 00         [ 2] 1204 	cpw	x, #0x0100
      00915E 26 05            [ 1] 1205 	jrne	00111$
                                   1206 ;	../src/stm8s_clk.c: 648: tmpreg = CLK->ICKR;
      009160 C6 50 C0         [ 1] 1207 	ld	a, 0x50c0
      009163 20 21            [ 2] 1208 	jra	00112$
      009165                       1209 00111$:
                                   1210 ;	../src/stm8s_clk.c: 650: else if (statusreg == 0x0200) /* The flag to check is in ECKRregister */
      009165 A3 02 00         [ 2] 1211 	cpw	x, #0x0200
      009168 26 05            [ 1] 1212 	jrne	00108$
                                   1213 ;	../src/stm8s_clk.c: 652: tmpreg = CLK->ECKR;
      00916A C6 50 C1         [ 1] 1214 	ld	a, 0x50c1
      00916D 20 17            [ 2] 1215 	jra	00112$
      00916F                       1216 00108$:
                                   1217 ;	../src/stm8s_clk.c: 654: else if (statusreg == 0x0300) /* The flag to check is in SWIC register */
      00916F A3 03 00         [ 2] 1218 	cpw	x, #0x0300
      009172 26 05            [ 1] 1219 	jrne	00105$
                                   1220 ;	../src/stm8s_clk.c: 656: tmpreg = CLK->SWCR;
      009174 C6 50 C5         [ 1] 1221 	ld	a, 0x50c5
      009177 20 0D            [ 2] 1222 	jra	00112$
      009179                       1223 00105$:
                                   1224 ;	../src/stm8s_clk.c: 658: else if (statusreg == 0x0400) /* The flag to check is in CSS register */
      009179 A3 04 00         [ 2] 1225 	cpw	x, #0x0400
      00917C 26 05            [ 1] 1226 	jrne	00102$
                                   1227 ;	../src/stm8s_clk.c: 660: tmpreg = CLK->CSSR;
      00917E C6 50 C8         [ 1] 1228 	ld	a, 0x50c8
      009181 20 03            [ 2] 1229 	jra	00112$
      009183                       1230 00102$:
                                   1231 ;	../src/stm8s_clk.c: 664: tmpreg = CLK->CCOR;
      009183 C6 50 C9         [ 1] 1232 	ld	a, 0x50c9
      009186                       1233 00112$:
                                   1234 ;	../src/stm8s_clk.c: 667: if ((tmpreg & (uint8_t)CLK_FLAG) != (uint8_t)RESET)
      009186 88               [ 1] 1235 	push	a
      009187 7B 06            [ 1] 1236 	ld	a, (0x06, sp)
      009189 6B 02            [ 1] 1237 	ld	(0x02, sp), a
      00918B 84               [ 1] 1238 	pop	a
      00918C 14 01            [ 1] 1239 	and	a, (0x01, sp)
      00918E 27 03            [ 1] 1240 	jreq	00114$
                                   1241 ;	../src/stm8s_clk.c: 669: bitstatus = SET;
      009190 A6 01            [ 1] 1242 	ld	a, #0x01
                                   1243 ;	../src/stm8s_clk.c: 673: bitstatus = RESET;
      009192 21                    1244 	.byte 0x21
      009193                       1245 00114$:
      009193 4F               [ 1] 1246 	clr	a
      009194                       1247 00115$:
                                   1248 ;	../src/stm8s_clk.c: 677: return((FlagStatus)bitstatus);
                                   1249 ;	../src/stm8s_clk.c: 678: }
      009194 5B 01            [ 2] 1250 	addw	sp, #1
      009196 81               [ 4] 1251 	ret
                                   1252 ;	../src/stm8s_clk.c: 686: ITStatus CLK_GetITStatus(CLK_IT_TypeDef CLK_IT)
                                   1253 ;	-----------------------------------------
                                   1254 ;	 function CLK_GetITStatus
                                   1255 ;	-----------------------------------------
      009197                       1256 _CLK_GetITStatus:
                                   1257 ;	../src/stm8s_clk.c: 691: assert_param(IS_CLK_IT_OK(CLK_IT));
      009197 7B 03            [ 1] 1258 	ld	a, (0x03, sp)
      009199 A0 1C            [ 1] 1259 	sub	a, #0x1c
      00919B 26 02            [ 1] 1260 	jrne	00143$
      00919D 4C               [ 1] 1261 	inc	a
      00919E 21                    1262 	.byte 0x21
      00919F                       1263 00143$:
      00919F 4F               [ 1] 1264 	clr	a
      0091A0                       1265 00144$:
      0091A0 88               [ 1] 1266 	push	a
      0091A1 7B 04            [ 1] 1267 	ld	a, (0x04, sp)
      0091A3 A1 0C            [ 1] 1268 	cp	a, #0x0c
      0091A5 84               [ 1] 1269 	pop	a
      0091A6 27 14            [ 1] 1270 	jreq	00113$
      0091A8 4D               [ 1] 1271 	tnz	a
      0091A9 26 11            [ 1] 1272 	jrne	00113$
      0091AB 88               [ 1] 1273 	push	a
      0091AC 4B B3            [ 1] 1274 	push	#0xb3
      0091AE 4B 02            [ 1] 1275 	push	#0x02
      0091B0 5F               [ 1] 1276 	clrw	x
      0091B1 89               [ 2] 1277 	pushw	x
      0091B2 4B 24            [ 1] 1278 	push	#<___str_0
      0091B4 4B 82            [ 1] 1279 	push	#(___str_0 >> 8)
      0091B6 CD 82 CE         [ 4] 1280 	call	_assert_failed
      0091B9 5B 06            [ 2] 1281 	addw	sp, #6
      0091BB 84               [ 1] 1282 	pop	a
      0091BC                       1283 00113$:
                                   1284 ;	../src/stm8s_clk.c: 693: if (CLK_IT == CLK_IT_SWIF)
      0091BC 4D               [ 1] 1285 	tnz	a
      0091BD 27 0D            [ 1] 1286 	jreq	00108$
                                   1287 ;	../src/stm8s_clk.c: 696: if ((CLK->SWCR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      0091BF C6 50 C5         [ 1] 1288 	ld	a, 0x50c5
      0091C2 14 03            [ 1] 1289 	and	a, (0x03, sp)
                                   1290 ;	../src/stm8s_clk.c: 698: bitstatus = SET;
      0091C4 A0 0C            [ 1] 1291 	sub	a, #0x0c
      0091C6 26 02            [ 1] 1292 	jrne	00102$
      0091C8 4C               [ 1] 1293 	inc	a
      0091C9 81               [ 4] 1294 	ret
      0091CA                       1295 00102$:
                                   1296 ;	../src/stm8s_clk.c: 702: bitstatus = RESET;
      0091CA 4F               [ 1] 1297 	clr	a
      0091CB 81               [ 4] 1298 	ret
      0091CC                       1299 00108$:
                                   1300 ;	../src/stm8s_clk.c: 708: if ((CLK->CSSR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      0091CC C6 50 C8         [ 1] 1301 	ld	a, 0x50c8
      0091CF 14 03            [ 1] 1302 	and	a, (0x03, sp)
                                   1303 ;	../src/stm8s_clk.c: 710: bitstatus = SET;
      0091D1 A0 0C            [ 1] 1304 	sub	a, #0x0c
      0091D3 26 02            [ 1] 1305 	jrne	00105$
      0091D5 4C               [ 1] 1306 	inc	a
      0091D6 81               [ 4] 1307 	ret
      0091D7                       1308 00105$:
                                   1309 ;	../src/stm8s_clk.c: 714: bitstatus = RESET;
      0091D7 4F               [ 1] 1310 	clr	a
                                   1311 ;	../src/stm8s_clk.c: 719: return bitstatus;
                                   1312 ;	../src/stm8s_clk.c: 720: }
      0091D8 81               [ 4] 1313 	ret
                                   1314 ;	../src/stm8s_clk.c: 728: void CLK_ClearITPendingBit(CLK_IT_TypeDef CLK_IT)
                                   1315 ;	-----------------------------------------
                                   1316 ;	 function CLK_ClearITPendingBit
                                   1317 ;	-----------------------------------------
      0091D9                       1318 _CLK_ClearITPendingBit:
                                   1319 ;	../src/stm8s_clk.c: 731: assert_param(IS_CLK_IT_OK(CLK_IT));
      0091D9 7B 03            [ 1] 1320 	ld	a, (0x03, sp)
      0091DB A0 0C            [ 1] 1321 	sub	a, #0x0c
      0091DD 26 02            [ 1] 1322 	jrne	00127$
      0091DF 4C               [ 1] 1323 	inc	a
      0091E0 21                    1324 	.byte 0x21
      0091E1                       1325 00127$:
      0091E1 4F               [ 1] 1326 	clr	a
      0091E2                       1327 00128$:
      0091E2 4D               [ 1] 1328 	tnz	a
      0091E3 26 19            [ 1] 1329 	jrne	00107$
      0091E5 88               [ 1] 1330 	push	a
      0091E6 7B 04            [ 1] 1331 	ld	a, (0x04, sp)
      0091E8 A1 1C            [ 1] 1332 	cp	a, #0x1c
      0091EA 84               [ 1] 1333 	pop	a
      0091EB 27 11            [ 1] 1334 	jreq	00107$
      0091ED 88               [ 1] 1335 	push	a
      0091EE 4B DB            [ 1] 1336 	push	#0xdb
      0091F0 4B 02            [ 1] 1337 	push	#0x02
      0091F2 5F               [ 1] 1338 	clrw	x
      0091F3 89               [ 2] 1339 	pushw	x
      0091F4 4B 24            [ 1] 1340 	push	#<___str_0
      0091F6 4B 82            [ 1] 1341 	push	#(___str_0 >> 8)
      0091F8 CD 82 CE         [ 4] 1342 	call	_assert_failed
      0091FB 5B 06            [ 2] 1343 	addw	sp, #6
      0091FD 84               [ 1] 1344 	pop	a
      0091FE                       1345 00107$:
                                   1346 ;	../src/stm8s_clk.c: 733: if (CLK_IT == (uint8_t)CLK_IT_CSSD)
      0091FE 4D               [ 1] 1347 	tnz	a
      0091FF 27 05            [ 1] 1348 	jreq	00102$
                                   1349 ;	../src/stm8s_clk.c: 736: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSD);
      009201 72 17 50 C8      [ 1] 1350 	bres	20680, #3
      009205 81               [ 4] 1351 	ret
      009206                       1352 00102$:
                                   1353 ;	../src/stm8s_clk.c: 741: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIF);
      009206 72 17 50 C5      [ 1] 1354 	bres	20677, #3
                                   1355 ;	../src/stm8s_clk.c: 744: }
      00920A 81               [ 4] 1356 	ret
                                   1357 	.area CODE
                                   1358 	.area CONST
      008218                       1359 _HSIDivExp:
      008218 00                    1360 	.db #0x00	; 0
      008219 01                    1361 	.db #0x01	; 1
      00821A 02                    1362 	.db #0x02	; 2
      00821B 03                    1363 	.db #0x03	; 3
      00821C                       1364 _CLKPrescTable:
      00821C 01                    1365 	.db #0x01	; 1
      00821D 02                    1366 	.db #0x02	; 2
      00821E 04                    1367 	.db #0x04	; 4
      00821F 08                    1368 	.db #0x08	; 8
      008220 0A                    1369 	.db #0x0a	; 10
      008221 10                    1370 	.db #0x10	; 16
      008222 14                    1371 	.db #0x14	; 20
      008223 28                    1372 	.db #0x28	; 40
      008224                       1373 ___str_0:
      008224 2E 2E 2F 73 72 63 2F  1374 	.ascii "../src/stm8s_clk.c"
             73 74 6D 38 73 5F 63
             6C 6B 2E 63
      008236 00                    1375 	.db 0x00
                                   1376 	.area INITIALIZER
                                   1377 	.area CABS (ABS)
