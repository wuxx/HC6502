                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 28 2016) (Linux)
                                      4 ; This file was generated Wed Jan  2 15:12:41 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module stm8s_clk
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _CLKPrescTable
                                     13 	.globl _HSIDivExp
                                     14 	.globl _assert_failed
                                     15 	.globl _CLK_DeInit
                                     16 	.globl _CLK_FastHaltWakeUpCmd
                                     17 	.globl _CLK_HSECmd
                                     18 	.globl _CLK_HSICmd
                                     19 	.globl _CLK_LSICmd
                                     20 	.globl _CLK_CCOCmd
                                     21 	.globl _CLK_ClockSwitchCmd
                                     22 	.globl _CLK_SlowActiveHaltWakeUpCmd
                                     23 	.globl _CLK_PeripheralClockConfig
                                     24 	.globl _CLK_ClockSwitchConfig
                                     25 	.globl _CLK_HSIPrescalerConfig
                                     26 	.globl _CLK_CCOConfig
                                     27 	.globl _CLK_ITConfig
                                     28 	.globl _CLK_SYSCLKConfig
                                     29 	.globl _CLK_SWIMConfig
                                     30 	.globl _CLK_ClockSecuritySystemEnable
                                     31 	.globl _CLK_GetSYSCLKSource
                                     32 	.globl _CLK_GetClockFreq
                                     33 	.globl _CLK_AdjustHSICalibrationValue
                                     34 	.globl _CLK_SYSCLKEmergencyClear
                                     35 	.globl _CLK_GetFlagStatus
                                     36 	.globl _CLK_GetITStatus
                                     37 	.globl _CLK_ClearITPendingBit
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
                                     50 ;--------------------------------------------------------
                                     51 ; global & static initialisations
                                     52 ;--------------------------------------------------------
                                     53 	.area HOME
                                     54 	.area GSINIT
                                     55 	.area GSFINAL
                                     56 	.area GSINIT
                                     57 ;--------------------------------------------------------
                                     58 ; Home
                                     59 ;--------------------------------------------------------
                                     60 	.area HOME
                                     61 	.area HOME
                                     62 ;--------------------------------------------------------
                                     63 ; code
                                     64 ;--------------------------------------------------------
                                     65 	.area CODE
                                     66 ;	../src/stm8s_clk.c: 72: void CLK_DeInit(void)
                                     67 ;	-----------------------------------------
                                     68 ;	 function CLK_DeInit
                                     69 ;	-----------------------------------------
      008C00                         70 _CLK_DeInit:
                                     71 ;	../src/stm8s_clk.c: 74: CLK->ICKR = CLK_ICKR_RESET_VALUE;
      008C00 35 01 50 C0      [ 1]   72 	mov	0x50c0+0, #0x01
                                     73 ;	../src/stm8s_clk.c: 75: CLK->ECKR = CLK_ECKR_RESET_VALUE;
      008C04 35 00 50 C1      [ 1]   74 	mov	0x50c1+0, #0x00
                                     75 ;	../src/stm8s_clk.c: 76: CLK->SWR  = CLK_SWR_RESET_VALUE;
      008C08 35 E1 50 C4      [ 1]   76 	mov	0x50c4+0, #0xe1
                                     77 ;	../src/stm8s_clk.c: 77: CLK->SWCR = CLK_SWCR_RESET_VALUE;
      008C0C 35 00 50 C5      [ 1]   78 	mov	0x50c5+0, #0x00
                                     79 ;	../src/stm8s_clk.c: 78: CLK->CKDIVR = CLK_CKDIVR_RESET_VALUE;
      008C10 35 18 50 C6      [ 1]   80 	mov	0x50c6+0, #0x18
                                     81 ;	../src/stm8s_clk.c: 79: CLK->PCKENR1 = CLK_PCKENR1_RESET_VALUE;
      008C14 35 FF 50 C7      [ 1]   82 	mov	0x50c7+0, #0xff
                                     83 ;	../src/stm8s_clk.c: 80: CLK->PCKENR2 = CLK_PCKENR2_RESET_VALUE;
      008C18 35 FF 50 CA      [ 1]   84 	mov	0x50ca+0, #0xff
                                     85 ;	../src/stm8s_clk.c: 81: CLK->CSSR = CLK_CSSR_RESET_VALUE;
      008C1C 35 00 50 C8      [ 1]   86 	mov	0x50c8+0, #0x00
                                     87 ;	../src/stm8s_clk.c: 82: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      008C20 35 00 50 C9      [ 1]   88 	mov	0x50c9+0, #0x00
                                     89 ;	../src/stm8s_clk.c: 83: while ((CLK->CCOR & CLK_CCOR_CCOEN)!= 0)
      008C24                         90 00101$:
      008C24 AE 50 C9         [ 2]   91 	ldw	x, #0x50c9
      008C27 F6               [ 1]   92 	ld	a, (x)
      008C28 44               [ 1]   93 	srl	a
      008C29 25 F9            [ 1]   94 	jrc	00101$
                                     95 ;	../src/stm8s_clk.c: 85: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      008C2B 35 00 50 C9      [ 1]   96 	mov	0x50c9+0, #0x00
                                     97 ;	../src/stm8s_clk.c: 86: CLK->HSITRIMR = CLK_HSITRIMR_RESET_VALUE;
      008C2F 35 00 50 CC      [ 1]   98 	mov	0x50cc+0, #0x00
                                     99 ;	../src/stm8s_clk.c: 87: CLK->SWIMCCR = CLK_SWIMCCR_RESET_VALUE;
      008C33 35 00 50 CD      [ 1]  100 	mov	0x50cd+0, #0x00
      008C37 81               [ 4]  101 	ret
                                    102 ;	../src/stm8s_clk.c: 99: void CLK_FastHaltWakeUpCmd(FunctionalState NewState)
                                    103 ;	-----------------------------------------
                                    104 ;	 function CLK_FastHaltWakeUpCmd
                                    105 ;	-----------------------------------------
      008C38                        106 _CLK_FastHaltWakeUpCmd:
                                    107 ;	../src/stm8s_clk.c: 102: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008C38 0D 03            [ 1]  108 	tnz	(0x03, sp)
      008C3A 27 17            [ 1]  109 	jreq	00107$
      008C3C 7B 03            [ 1]  110 	ld	a, (0x03, sp)
      008C3E A1 01            [ 1]  111 	cp	a, #0x01
      008C40 27 11            [ 1]  112 	jreq	00107$
      008C42 90 AE 93 77      [ 2]  113 	ldw	y, #___str_0+0
      008C46 4B 66            [ 1]  114 	push	#0x66
      008C48 5F               [ 1]  115 	clrw	x
      008C49 89               [ 2]  116 	pushw	x
      008C4A 4B 00            [ 1]  117 	push	#0x00
      008C4C 90 89            [ 2]  118 	pushw	y
      008C4E CD 80 A8         [ 4]  119 	call	_assert_failed
      008C51 5B 06            [ 2]  120 	addw	sp, #6
      008C53                        121 00107$:
                                    122 ;	../src/stm8s_clk.c: 104: if (NewState != DISABLE)
      008C53 0D 03            [ 1]  123 	tnz	(0x03, sp)
      008C55 27 09            [ 1]  124 	jreq	00102$
                                    125 ;	../src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
      008C57 AE 50 C0         [ 2]  126 	ldw	x, #0x50c0
      008C5A F6               [ 1]  127 	ld	a, (x)
      008C5B AA 04            [ 1]  128 	or	a, #0x04
      008C5D F7               [ 1]  129 	ld	(x), a
      008C5E 20 07            [ 2]  130 	jra	00104$
      008C60                        131 00102$:
                                    132 ;	../src/stm8s_clk.c: 112: CLK->ICKR &= (uint8_t)(~CLK_ICKR_FHWU);
      008C60 AE 50 C0         [ 2]  133 	ldw	x, #0x50c0
      008C63 F6               [ 1]  134 	ld	a, (x)
      008C64 A4 FB            [ 1]  135 	and	a, #0xfb
      008C66 F7               [ 1]  136 	ld	(x), a
      008C67                        137 00104$:
      008C67 81               [ 4]  138 	ret
                                    139 ;	../src/stm8s_clk.c: 121: void CLK_HSECmd(FunctionalState NewState)
                                    140 ;	-----------------------------------------
                                    141 ;	 function CLK_HSECmd
                                    142 ;	-----------------------------------------
      008C68                        143 _CLK_HSECmd:
                                    144 ;	../src/stm8s_clk.c: 124: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008C68 0D 03            [ 1]  145 	tnz	(0x03, sp)
      008C6A 27 17            [ 1]  146 	jreq	00107$
      008C6C 7B 03            [ 1]  147 	ld	a, (0x03, sp)
      008C6E A1 01            [ 1]  148 	cp	a, #0x01
      008C70 27 11            [ 1]  149 	jreq	00107$
      008C72 90 AE 93 77      [ 2]  150 	ldw	y, #___str_0+0
      008C76 4B 7C            [ 1]  151 	push	#0x7c
      008C78 5F               [ 1]  152 	clrw	x
      008C79 89               [ 2]  153 	pushw	x
      008C7A 4B 00            [ 1]  154 	push	#0x00
      008C7C 90 89            [ 2]  155 	pushw	y
      008C7E CD 80 A8         [ 4]  156 	call	_assert_failed
      008C81 5B 06            [ 2]  157 	addw	sp, #6
      008C83                        158 00107$:
                                    159 ;	../src/stm8s_clk.c: 126: if (NewState != DISABLE)
      008C83 0D 03            [ 1]  160 	tnz	(0x03, sp)
      008C85 27 06            [ 1]  161 	jreq	00102$
                                    162 ;	../src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
      008C87 72 10 50 C1      [ 1]  163 	bset	0x50c1, #0
      008C8B 20 04            [ 2]  164 	jra	00104$
      008C8D                        165 00102$:
                                    166 ;	../src/stm8s_clk.c: 134: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      008C8D 72 11 50 C1      [ 1]  167 	bres	0x50c1, #0
      008C91                        168 00104$:
      008C91 81               [ 4]  169 	ret
                                    170 ;	../src/stm8s_clk.c: 143: void CLK_HSICmd(FunctionalState NewState)
                                    171 ;	-----------------------------------------
                                    172 ;	 function CLK_HSICmd
                                    173 ;	-----------------------------------------
      008C92                        174 _CLK_HSICmd:
                                    175 ;	../src/stm8s_clk.c: 146: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008C92 0D 03            [ 1]  176 	tnz	(0x03, sp)
      008C94 27 17            [ 1]  177 	jreq	00107$
      008C96 7B 03            [ 1]  178 	ld	a, (0x03, sp)
      008C98 A1 01            [ 1]  179 	cp	a, #0x01
      008C9A 27 11            [ 1]  180 	jreq	00107$
      008C9C 90 AE 93 77      [ 2]  181 	ldw	y, #___str_0+0
      008CA0 4B 92            [ 1]  182 	push	#0x92
      008CA2 5F               [ 1]  183 	clrw	x
      008CA3 89               [ 2]  184 	pushw	x
      008CA4 4B 00            [ 1]  185 	push	#0x00
      008CA6 90 89            [ 2]  186 	pushw	y
      008CA8 CD 80 A8         [ 4]  187 	call	_assert_failed
      008CAB 5B 06            [ 2]  188 	addw	sp, #6
      008CAD                        189 00107$:
                                    190 ;	../src/stm8s_clk.c: 148: if (NewState != DISABLE)
      008CAD 0D 03            [ 1]  191 	tnz	(0x03, sp)
      008CAF 27 06            [ 1]  192 	jreq	00102$
                                    193 ;	../src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
      008CB1 72 10 50 C0      [ 1]  194 	bset	0x50c0, #0
      008CB5 20 04            [ 2]  195 	jra	00104$
      008CB7                        196 00102$:
                                    197 ;	../src/stm8s_clk.c: 156: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      008CB7 72 11 50 C0      [ 1]  198 	bres	0x50c0, #0
      008CBB                        199 00104$:
      008CBB 81               [ 4]  200 	ret
                                    201 ;	../src/stm8s_clk.c: 166: void CLK_LSICmd(FunctionalState NewState)
                                    202 ;	-----------------------------------------
                                    203 ;	 function CLK_LSICmd
                                    204 ;	-----------------------------------------
      008CBC                        205 _CLK_LSICmd:
                                    206 ;	../src/stm8s_clk.c: 169: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008CBC 0D 03            [ 1]  207 	tnz	(0x03, sp)
      008CBE 27 17            [ 1]  208 	jreq	00107$
      008CC0 7B 03            [ 1]  209 	ld	a, (0x03, sp)
      008CC2 A1 01            [ 1]  210 	cp	a, #0x01
      008CC4 27 11            [ 1]  211 	jreq	00107$
      008CC6 90 AE 93 77      [ 2]  212 	ldw	y, #___str_0+0
      008CCA 4B A9            [ 1]  213 	push	#0xa9
      008CCC 5F               [ 1]  214 	clrw	x
      008CCD 89               [ 2]  215 	pushw	x
      008CCE 4B 00            [ 1]  216 	push	#0x00
      008CD0 90 89            [ 2]  217 	pushw	y
      008CD2 CD 80 A8         [ 4]  218 	call	_assert_failed
      008CD5 5B 06            [ 2]  219 	addw	sp, #6
      008CD7                        220 00107$:
                                    221 ;	../src/stm8s_clk.c: 171: if (NewState != DISABLE)
      008CD7 0D 03            [ 1]  222 	tnz	(0x03, sp)
      008CD9 27 09            [ 1]  223 	jreq	00102$
                                    224 ;	../src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
      008CDB AE 50 C0         [ 2]  225 	ldw	x, #0x50c0
      008CDE F6               [ 1]  226 	ld	a, (x)
      008CDF AA 08            [ 1]  227 	or	a, #0x08
      008CE1 F7               [ 1]  228 	ld	(x), a
      008CE2 20 07            [ 2]  229 	jra	00104$
      008CE4                        230 00102$:
                                    231 ;	../src/stm8s_clk.c: 179: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      008CE4 AE 50 C0         [ 2]  232 	ldw	x, #0x50c0
      008CE7 F6               [ 1]  233 	ld	a, (x)
      008CE8 A4 F7            [ 1]  234 	and	a, #0xf7
      008CEA F7               [ 1]  235 	ld	(x), a
      008CEB                        236 00104$:
      008CEB 81               [ 4]  237 	ret
                                    238 ;	../src/stm8s_clk.c: 189: void CLK_CCOCmd(FunctionalState NewState)
                                    239 ;	-----------------------------------------
                                    240 ;	 function CLK_CCOCmd
                                    241 ;	-----------------------------------------
      008CEC                        242 _CLK_CCOCmd:
                                    243 ;	../src/stm8s_clk.c: 192: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008CEC 0D 03            [ 1]  244 	tnz	(0x03, sp)
      008CEE 27 17            [ 1]  245 	jreq	00107$
      008CF0 7B 03            [ 1]  246 	ld	a, (0x03, sp)
      008CF2 A1 01            [ 1]  247 	cp	a, #0x01
      008CF4 27 11            [ 1]  248 	jreq	00107$
      008CF6 90 AE 93 77      [ 2]  249 	ldw	y, #___str_0+0
      008CFA 4B C0            [ 1]  250 	push	#0xc0
      008CFC 5F               [ 1]  251 	clrw	x
      008CFD 89               [ 2]  252 	pushw	x
      008CFE 4B 00            [ 1]  253 	push	#0x00
      008D00 90 89            [ 2]  254 	pushw	y
      008D02 CD 80 A8         [ 4]  255 	call	_assert_failed
      008D05 5B 06            [ 2]  256 	addw	sp, #6
      008D07                        257 00107$:
                                    258 ;	../src/stm8s_clk.c: 194: if (NewState != DISABLE)
      008D07 0D 03            [ 1]  259 	tnz	(0x03, sp)
      008D09 27 06            [ 1]  260 	jreq	00102$
                                    261 ;	../src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
      008D0B 72 10 50 C9      [ 1]  262 	bset	0x50c9, #0
      008D0F 20 04            [ 2]  263 	jra	00104$
      008D11                        264 00102$:
                                    265 ;	../src/stm8s_clk.c: 202: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOEN);
      008D11 72 11 50 C9      [ 1]  266 	bres	0x50c9, #0
      008D15                        267 00104$:
      008D15 81               [ 4]  268 	ret
                                    269 ;	../src/stm8s_clk.c: 213: void CLK_ClockSwitchCmd(FunctionalState NewState)
                                    270 ;	-----------------------------------------
                                    271 ;	 function CLK_ClockSwitchCmd
                                    272 ;	-----------------------------------------
      008D16                        273 _CLK_ClockSwitchCmd:
                                    274 ;	../src/stm8s_clk.c: 216: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008D16 0D 03            [ 1]  275 	tnz	(0x03, sp)
      008D18 27 17            [ 1]  276 	jreq	00107$
      008D1A 7B 03            [ 1]  277 	ld	a, (0x03, sp)
      008D1C A1 01            [ 1]  278 	cp	a, #0x01
      008D1E 27 11            [ 1]  279 	jreq	00107$
      008D20 90 AE 93 77      [ 2]  280 	ldw	y, #___str_0+0
      008D24 4B D8            [ 1]  281 	push	#0xd8
      008D26 5F               [ 1]  282 	clrw	x
      008D27 89               [ 2]  283 	pushw	x
      008D28 4B 00            [ 1]  284 	push	#0x00
      008D2A 90 89            [ 2]  285 	pushw	y
      008D2C CD 80 A8         [ 4]  286 	call	_assert_failed
      008D2F 5B 06            [ 2]  287 	addw	sp, #6
      008D31                        288 00107$:
                                    289 ;	../src/stm8s_clk.c: 218: if (NewState != DISABLE )
      008D31 0D 03            [ 1]  290 	tnz	(0x03, sp)
      008D33 27 09            [ 1]  291 	jreq	00102$
                                    292 ;	../src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
      008D35 AE 50 C5         [ 2]  293 	ldw	x, #0x50c5
      008D38 F6               [ 1]  294 	ld	a, (x)
      008D39 AA 02            [ 1]  295 	or	a, #0x02
      008D3B F7               [ 1]  296 	ld	(x), a
      008D3C 20 07            [ 2]  297 	jra	00104$
      008D3E                        298 00102$:
                                    299 ;	../src/stm8s_clk.c: 226: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWEN);
      008D3E AE 50 C5         [ 2]  300 	ldw	x, #0x50c5
      008D41 F6               [ 1]  301 	ld	a, (x)
      008D42 A4 FD            [ 1]  302 	and	a, #0xfd
      008D44 F7               [ 1]  303 	ld	(x), a
      008D45                        304 00104$:
      008D45 81               [ 4]  305 	ret
                                    306 ;	../src/stm8s_clk.c: 238: void CLK_SlowActiveHaltWakeUpCmd(FunctionalState NewState)
                                    307 ;	-----------------------------------------
                                    308 ;	 function CLK_SlowActiveHaltWakeUpCmd
                                    309 ;	-----------------------------------------
      008D46                        310 _CLK_SlowActiveHaltWakeUpCmd:
                                    311 ;	../src/stm8s_clk.c: 241: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008D46 0D 03            [ 1]  312 	tnz	(0x03, sp)
      008D48 27 17            [ 1]  313 	jreq	00107$
      008D4A 7B 03            [ 1]  314 	ld	a, (0x03, sp)
      008D4C A1 01            [ 1]  315 	cp	a, #0x01
      008D4E 27 11            [ 1]  316 	jreq	00107$
      008D50 90 AE 93 77      [ 2]  317 	ldw	y, #___str_0+0
      008D54 4B F1            [ 1]  318 	push	#0xf1
      008D56 5F               [ 1]  319 	clrw	x
      008D57 89               [ 2]  320 	pushw	x
      008D58 4B 00            [ 1]  321 	push	#0x00
      008D5A 90 89            [ 2]  322 	pushw	y
      008D5C CD 80 A8         [ 4]  323 	call	_assert_failed
      008D5F 5B 06            [ 2]  324 	addw	sp, #6
      008D61                        325 00107$:
                                    326 ;	../src/stm8s_clk.c: 243: if (NewState != DISABLE)
      008D61 0D 03            [ 1]  327 	tnz	(0x03, sp)
      008D63 27 09            [ 1]  328 	jreq	00102$
                                    329 ;	../src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
      008D65 AE 50 C0         [ 2]  330 	ldw	x, #0x50c0
      008D68 F6               [ 1]  331 	ld	a, (x)
      008D69 AA 20            [ 1]  332 	or	a, #0x20
      008D6B F7               [ 1]  333 	ld	(x), a
      008D6C 20 07            [ 2]  334 	jra	00104$
      008D6E                        335 00102$:
                                    336 ;	../src/stm8s_clk.c: 251: CLK->ICKR &= (uint8_t)(~CLK_ICKR_SWUAH);
      008D6E AE 50 C0         [ 2]  337 	ldw	x, #0x50c0
      008D71 F6               [ 1]  338 	ld	a, (x)
      008D72 A4 DF            [ 1]  339 	and	a, #0xdf
      008D74 F7               [ 1]  340 	ld	(x), a
      008D75                        341 00104$:
      008D75 81               [ 4]  342 	ret
                                    343 ;	../src/stm8s_clk.c: 263: void CLK_PeripheralClockConfig(CLK_Peripheral_TypeDef CLK_Peripheral, FunctionalState NewState)
                                    344 ;	-----------------------------------------
                                    345 ;	 function CLK_PeripheralClockConfig
                                    346 ;	-----------------------------------------
      008D76                        347 _CLK_PeripheralClockConfig:
      008D76 89               [ 2]  348 	pushw	x
                                    349 ;	../src/stm8s_clk.c: 266: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008D77 0D 06            [ 1]  350 	tnz	(0x06, sp)
      008D79 27 17            [ 1]  351 	jreq	00113$
      008D7B 7B 06            [ 1]  352 	ld	a, (0x06, sp)
      008D7D A1 01            [ 1]  353 	cp	a, #0x01
      008D7F 27 11            [ 1]  354 	jreq	00113$
      008D81 90 AE 93 77      [ 2]  355 	ldw	y, #___str_0+0
      008D85 4B 0A            [ 1]  356 	push	#0x0a
      008D87 4B 01            [ 1]  357 	push	#0x01
      008D89 5F               [ 1]  358 	clrw	x
      008D8A 89               [ 2]  359 	pushw	x
      008D8B 90 89            [ 2]  360 	pushw	y
      008D8D CD 80 A8         [ 4]  361 	call	_assert_failed
      008D90 5B 06            [ 2]  362 	addw	sp, #6
      008D92                        363 00113$:
                                    364 ;	../src/stm8s_clk.c: 267: assert_param(IS_CLK_PERIPHERAL_OK(CLK_Peripheral));
      008D92 0D 05            [ 1]  365 	tnz	(0x05, sp)
      008D94 27 6D            [ 1]  366 	jreq	00118$
      008D96 7B 05            [ 1]  367 	ld	a, (0x05, sp)
      008D98 A1 01            [ 1]  368 	cp	a, #0x01
      008D9A 27 67            [ 1]  369 	jreq	00118$
      008D9C 7B 05            [ 1]  370 	ld	a, (0x05, sp)
      008D9E A1 03            [ 1]  371 	cp	a, #0x03
      008DA0 26 03            [ 1]  372 	jrne	00243$
      008DA2 A6 01            [ 1]  373 	ld	a, #0x01
      008DA4 21                     374 	.byte 0x21
      008DA5                        375 00243$:
      008DA5 4F               [ 1]  376 	clr	a
      008DA6                        377 00244$:
      008DA6 4D               [ 1]  378 	tnz	a
      008DA7 26 5A            [ 1]  379 	jrne	00118$
      008DA9 4D               [ 1]  380 	tnz	a
      008DAA 26 57            [ 1]  381 	jrne	00118$
      008DAC 4D               [ 1]  382 	tnz	a
      008DAD 26 54            [ 1]  383 	jrne	00118$
      008DAF 7B 05            [ 1]  384 	ld	a, (0x05, sp)
      008DB1 A1 04            [ 1]  385 	cp	a, #0x04
      008DB3 26 05            [ 1]  386 	jrne	00249$
      008DB5 A6 01            [ 1]  387 	ld	a, #0x01
      008DB7 95               [ 1]  388 	ld	xh, a
      008DB8 20 02            [ 2]  389 	jra	00250$
      008DBA                        390 00249$:
      008DBA 4F               [ 1]  391 	clr	a
      008DBB 95               [ 1]  392 	ld	xh, a
      008DBC                        393 00250$:
      008DBC 9E               [ 1]  394 	ld	a, xh
      008DBD 4D               [ 1]  395 	tnz	a
      008DBE 26 43            [ 1]  396 	jrne	00118$
      008DC0 7B 05            [ 1]  397 	ld	a, (0x05, sp)
      008DC2 A1 05            [ 1]  398 	cp	a, #0x05
      008DC4 26 03            [ 1]  399 	jrne	00253$
      008DC6 A6 01            [ 1]  400 	ld	a, #0x01
      008DC8 21                     401 	.byte 0x21
      008DC9                        402 00253$:
      008DC9 4F               [ 1]  403 	clr	a
      008DCA                        404 00254$:
      008DCA 4D               [ 1]  405 	tnz	a
      008DCB 26 36            [ 1]  406 	jrne	00118$
      008DCD 4D               [ 1]  407 	tnz	a
      008DCE 26 33            [ 1]  408 	jrne	00118$
      008DD0 9E               [ 1]  409 	ld	a, xh
      008DD1 4D               [ 1]  410 	tnz	a
      008DD2 26 2F            [ 1]  411 	jrne	00118$
      008DD4 7B 05            [ 1]  412 	ld	a, (0x05, sp)
      008DD6 A1 06            [ 1]  413 	cp	a, #0x06
      008DD8 27 29            [ 1]  414 	jreq	00118$
      008DDA 7B 05            [ 1]  415 	ld	a, (0x05, sp)
      008DDC A1 07            [ 1]  416 	cp	a, #0x07
      008DDE 27 23            [ 1]  417 	jreq	00118$
      008DE0 7B 05            [ 1]  418 	ld	a, (0x05, sp)
      008DE2 A1 17            [ 1]  419 	cp	a, #0x17
      008DE4 27 1D            [ 1]  420 	jreq	00118$
      008DE6 7B 05            [ 1]  421 	ld	a, (0x05, sp)
      008DE8 A1 13            [ 1]  422 	cp	a, #0x13
      008DEA 27 17            [ 1]  423 	jreq	00118$
      008DEC 7B 05            [ 1]  424 	ld	a, (0x05, sp)
      008DEE A1 12            [ 1]  425 	cp	a, #0x12
      008DF0 27 11            [ 1]  426 	jreq	00118$
      008DF2 90 AE 93 77      [ 2]  427 	ldw	y, #___str_0+0
      008DF6 4B 0B            [ 1]  428 	push	#0x0b
      008DF8 4B 01            [ 1]  429 	push	#0x01
      008DFA 5F               [ 1]  430 	clrw	x
      008DFB 89               [ 2]  431 	pushw	x
      008DFC 90 89            [ 2]  432 	pushw	y
      008DFE CD 80 A8         [ 4]  433 	call	_assert_failed
      008E01 5B 06            [ 2]  434 	addw	sp, #6
      008E03                        435 00118$:
                                    436 ;	../src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008E03 7B 05            [ 1]  437 	ld	a, (0x05, sp)
      008E05 A4 0F            [ 1]  438 	and	a, #0x0f
      008E07 95               [ 1]  439 	ld	xh, a
      008E08 A6 01            [ 1]  440 	ld	a, #0x01
      008E0A 6B 01            [ 1]  441 	ld	(0x01, sp), a
      008E0C 9E               [ 1]  442 	ld	a, xh
      008E0D 4D               [ 1]  443 	tnz	a
      008E0E 27 05            [ 1]  444 	jreq	00274$
      008E10                        445 00273$:
      008E10 08 01            [ 1]  446 	sll	(0x01, sp)
      008E12 4A               [ 1]  447 	dec	a
      008E13 26 FB            [ 1]  448 	jrne	00273$
      008E15                        449 00274$:
                                    450 ;	../src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008E15 7B 01            [ 1]  451 	ld	a, (0x01, sp)
      008E17 43               [ 1]  452 	cpl	a
      008E18 6B 02            [ 1]  453 	ld	(0x02, sp), a
                                    454 ;	../src/stm8s_clk.c: 269: if (((uint8_t)CLK_Peripheral & (uint8_t)0x10) == 0x00)
      008E1A 7B 05            [ 1]  455 	ld	a, (0x05, sp)
      008E1C A5 10            [ 1]  456 	bcp	a, #0x10
      008E1E 26 1C            [ 1]  457 	jrne	00108$
                                    458 ;	../src/stm8s_clk.c: 271: if (NewState != DISABLE)
      008E20 0D 06            [ 1]  459 	tnz	(0x06, sp)
      008E22 27 0C            [ 1]  460 	jreq	00102$
                                    461 ;	../src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008E24 AE 50 C7         [ 2]  462 	ldw	x, #0x50c7
      008E27 F6               [ 1]  463 	ld	a, (x)
      008E28 1A 01            [ 1]  464 	or	a, (0x01, sp)
      008E2A AE 50 C7         [ 2]  465 	ldw	x, #0x50c7
      008E2D F7               [ 1]  466 	ld	(x), a
      008E2E 20 26            [ 2]  467 	jra	00110$
      008E30                        468 00102$:
                                    469 ;	../src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008E30 AE 50 C7         [ 2]  470 	ldw	x, #0x50c7
      008E33 F6               [ 1]  471 	ld	a, (x)
      008E34 14 02            [ 1]  472 	and	a, (0x02, sp)
      008E36 AE 50 C7         [ 2]  473 	ldw	x, #0x50c7
      008E39 F7               [ 1]  474 	ld	(x), a
      008E3A 20 1A            [ 2]  475 	jra	00110$
      008E3C                        476 00108$:
                                    477 ;	../src/stm8s_clk.c: 284: if (NewState != DISABLE)
      008E3C 0D 06            [ 1]  478 	tnz	(0x06, sp)
      008E3E 27 0C            [ 1]  479 	jreq	00105$
                                    480 ;	../src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008E40 AE 50 CA         [ 2]  481 	ldw	x, #0x50ca
      008E43 F6               [ 1]  482 	ld	a, (x)
      008E44 1A 01            [ 1]  483 	or	a, (0x01, sp)
      008E46 AE 50 CA         [ 2]  484 	ldw	x, #0x50ca
      008E49 F7               [ 1]  485 	ld	(x), a
      008E4A 20 0A            [ 2]  486 	jra	00110$
      008E4C                        487 00105$:
                                    488 ;	../src/stm8s_clk.c: 292: CLK->PCKENR2 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008E4C AE 50 CA         [ 2]  489 	ldw	x, #0x50ca
      008E4F F6               [ 1]  490 	ld	a, (x)
      008E50 14 02            [ 1]  491 	and	a, (0x02, sp)
      008E52 AE 50 CA         [ 2]  492 	ldw	x, #0x50ca
      008E55 F7               [ 1]  493 	ld	(x), a
      008E56                        494 00110$:
      008E56 85               [ 2]  495 	popw	x
      008E57 81               [ 4]  496 	ret
                                    497 ;	../src/stm8s_clk.c: 309: ErrorStatus CLK_ClockSwitchConfig(CLK_SwitchMode_TypeDef CLK_SwitchMode, CLK_Source_TypeDef CLK_NewClock, FunctionalState ITState, CLK_CurrentClockState_TypeDef CLK_CurrentClockState)
                                    498 ;	-----------------------------------------
                                    499 ;	 function CLK_ClockSwitchConfig
                                    500 ;	-----------------------------------------
      008E58                        501 _CLK_ClockSwitchConfig:
      008E58 52 03            [ 2]  502 	sub	sp, #3
                                    503 ;	../src/stm8s_clk.c: 316: assert_param(IS_CLK_SOURCE_OK(CLK_NewClock));
      008E5A 7B 07            [ 1]  504 	ld	a, (0x07, sp)
      008E5C A1 E1            [ 1]  505 	cp	a, #0xe1
      008E5E 27 1D            [ 1]  506 	jreq	00140$
      008E60 7B 07            [ 1]  507 	ld	a, (0x07, sp)
      008E62 A1 D2            [ 1]  508 	cp	a, #0xd2
      008E64 27 17            [ 1]  509 	jreq	00140$
      008E66 7B 07            [ 1]  510 	ld	a, (0x07, sp)
      008E68 A1 B4            [ 1]  511 	cp	a, #0xb4
      008E6A 27 11            [ 1]  512 	jreq	00140$
      008E6C 90 AE 93 77      [ 2]  513 	ldw	y, #___str_0+0
      008E70 4B 3C            [ 1]  514 	push	#0x3c
      008E72 4B 01            [ 1]  515 	push	#0x01
      008E74 5F               [ 1]  516 	clrw	x
      008E75 89               [ 2]  517 	pushw	x
      008E76 90 89            [ 2]  518 	pushw	y
      008E78 CD 80 A8         [ 4]  519 	call	_assert_failed
      008E7B 5B 06            [ 2]  520 	addw	sp, #6
      008E7D                        521 00140$:
                                    522 ;	../src/stm8s_clk.c: 317: assert_param(IS_CLK_SWITCHMODE_OK(CLK_SwitchMode));
      008E7D 7B 06            [ 1]  523 	ld	a, (0x06, sp)
      008E7F A1 01            [ 1]  524 	cp	a, #0x01
      008E81 26 06            [ 1]  525 	jrne	00282$
      008E83 A6 01            [ 1]  526 	ld	a, #0x01
      008E85 6B 03            [ 1]  527 	ld	(0x03, sp), a
      008E87 20 02            [ 2]  528 	jra	00283$
      008E89                        529 00282$:
      008E89 0F 03            [ 1]  530 	clr	(0x03, sp)
      008E8B                        531 00283$:
      008E8B 0D 06            [ 1]  532 	tnz	(0x06, sp)
      008E8D 27 15            [ 1]  533 	jreq	00148$
      008E8F 0D 03            [ 1]  534 	tnz	(0x03, sp)
      008E91 26 11            [ 1]  535 	jrne	00148$
      008E93 90 AE 93 77      [ 2]  536 	ldw	y, #___str_0+0
      008E97 4B 3D            [ 1]  537 	push	#0x3d
      008E99 4B 01            [ 1]  538 	push	#0x01
      008E9B 5F               [ 1]  539 	clrw	x
      008E9C 89               [ 2]  540 	pushw	x
      008E9D 90 89            [ 2]  541 	pushw	y
      008E9F CD 80 A8         [ 4]  542 	call	_assert_failed
      008EA2 5B 06            [ 2]  543 	addw	sp, #6
      008EA4                        544 00148$:
                                    545 ;	../src/stm8s_clk.c: 318: assert_param(IS_FUNCTIONALSTATE_OK(ITState));
      008EA4 0D 08            [ 1]  546 	tnz	(0x08, sp)
      008EA6 27 17            [ 1]  547 	jreq	00153$
      008EA8 7B 08            [ 1]  548 	ld	a, (0x08, sp)
      008EAA A1 01            [ 1]  549 	cp	a, #0x01
      008EAC 27 11            [ 1]  550 	jreq	00153$
      008EAE 90 AE 93 77      [ 2]  551 	ldw	y, #___str_0+0
      008EB2 4B 3E            [ 1]  552 	push	#0x3e
      008EB4 4B 01            [ 1]  553 	push	#0x01
      008EB6 5F               [ 1]  554 	clrw	x
      008EB7 89               [ 2]  555 	pushw	x
      008EB8 90 89            [ 2]  556 	pushw	y
      008EBA CD 80 A8         [ 4]  557 	call	_assert_failed
      008EBD 5B 06            [ 2]  558 	addw	sp, #6
      008EBF                        559 00153$:
                                    560 ;	../src/stm8s_clk.c: 319: assert_param(IS_CLK_CURRENTCLOCKSTATE_OK(CLK_CurrentClockState));
      008EBF 0D 09            [ 1]  561 	tnz	(0x09, sp)
      008EC1 27 17            [ 1]  562 	jreq	00158$
      008EC3 7B 09            [ 1]  563 	ld	a, (0x09, sp)
      008EC5 A1 01            [ 1]  564 	cp	a, #0x01
      008EC7 27 11            [ 1]  565 	jreq	00158$
      008EC9 90 AE 93 77      [ 2]  566 	ldw	y, #___str_0+0
      008ECD 4B 3F            [ 1]  567 	push	#0x3f
      008ECF 4B 01            [ 1]  568 	push	#0x01
      008ED1 5F               [ 1]  569 	clrw	x
      008ED2 89               [ 2]  570 	pushw	x
      008ED3 90 89            [ 2]  571 	pushw	y
      008ED5 CD 80 A8         [ 4]  572 	call	_assert_failed
      008ED8 5B 06            [ 2]  573 	addw	sp, #6
      008EDA                        574 00158$:
                                    575 ;	../src/stm8s_clk.c: 322: clock_master = (CLK_Source_TypeDef)CLK->CMSR;
      008EDA AE 50 C3         [ 2]  576 	ldw	x, #0x50c3
      008EDD F6               [ 1]  577 	ld	a, (x)
      008EDE 6B 01            [ 1]  578 	ld	(0x01, sp), a
                                    579 ;	../src/stm8s_clk.c: 325: if (CLK_SwitchMode == CLK_SWITCHMODE_AUTO)
      008EE0 0D 03            [ 1]  580 	tnz	(0x03, sp)
      008EE2 27 40            [ 1]  581 	jreq	00122$
                                    582 ;	../src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
      008EE4 AE 50 C5         [ 2]  583 	ldw	x, #0x50c5
      008EE7 F6               [ 1]  584 	ld	a, (x)
      008EE8 AA 02            [ 1]  585 	or	a, #0x02
      008EEA F7               [ 1]  586 	ld	(x), a
                                    587 ;	../src/stm8s_clk.c: 331: if (ITState != DISABLE)
      008EEB 0D 08            [ 1]  588 	tnz	(0x08, sp)
      008EED 27 09            [ 1]  589 	jreq	00102$
                                    590 ;	../src/stm8s_clk.c: 333: CLK->SWCR |= CLK_SWCR_SWIEN;
      008EEF AE 50 C5         [ 2]  591 	ldw	x, #0x50c5
      008EF2 F6               [ 1]  592 	ld	a, (x)
      008EF3 AA 04            [ 1]  593 	or	a, #0x04
      008EF5 F7               [ 1]  594 	ld	(x), a
      008EF6 20 07            [ 2]  595 	jra	00103$
      008EF8                        596 00102$:
                                    597 ;	../src/stm8s_clk.c: 337: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      008EF8 AE 50 C5         [ 2]  598 	ldw	x, #0x50c5
      008EFB F6               [ 1]  599 	ld	a, (x)
      008EFC A4 FB            [ 1]  600 	and	a, #0xfb
      008EFE F7               [ 1]  601 	ld	(x), a
      008EFF                        602 00103$:
                                    603 ;	../src/stm8s_clk.c: 341: CLK->SWR = (uint8_t)CLK_NewClock;
      008EFF AE 50 C4         [ 2]  604 	ldw	x, #0x50c4
      008F02 7B 07            [ 1]  605 	ld	a, (0x07, sp)
      008F04 F7               [ 1]  606 	ld	(x), a
                                    607 ;	../src/stm8s_clk.c: 344: while((((CLK->SWCR & CLK_SWCR_SWBSY) != 0 )&& (DownCounter != 0)))
      008F05 AE FF FF         [ 2]  608 	ldw	x, #0xffff
      008F08                        609 00105$:
      008F08 90 AE 50 C5      [ 2]  610 	ldw	y, #0x50c5
      008F0C 90 F6            [ 1]  611 	ld	a, (y)
      008F0E 44               [ 1]  612 	srl	a
      008F0F 24 06            [ 1]  613 	jrnc	00107$
      008F11 5D               [ 2]  614 	tnzw	x
      008F12 27 03            [ 1]  615 	jreq	00107$
                                    616 ;	../src/stm8s_clk.c: 346: DownCounter--;
      008F14 5A               [ 2]  617 	decw	x
      008F15 20 F1            [ 2]  618 	jra	00105$
      008F17                        619 00107$:
                                    620 ;	../src/stm8s_clk.c: 349: if(DownCounter != 0)
      008F17 5D               [ 2]  621 	tnzw	x
      008F18 27 06            [ 1]  622 	jreq	00109$
                                    623 ;	../src/stm8s_clk.c: 351: Swif = SUCCESS;
      008F1A A6 01            [ 1]  624 	ld	a, #0x01
      008F1C 6B 02            [ 1]  625 	ld	(0x02, sp), a
      008F1E 20 43            [ 2]  626 	jra	00123$
      008F20                        627 00109$:
                                    628 ;	../src/stm8s_clk.c: 355: Swif = ERROR;
      008F20 0F 02            [ 1]  629 	clr	(0x02, sp)
      008F22 20 3F            [ 2]  630 	jra	00123$
      008F24                        631 00122$:
                                    632 ;	../src/stm8s_clk.c: 361: if (ITState != DISABLE)
      008F24 0D 08            [ 1]  633 	tnz	(0x08, sp)
      008F26 27 09            [ 1]  634 	jreq	00112$
                                    635 ;	../src/stm8s_clk.c: 363: CLK->SWCR |= CLK_SWCR_SWIEN;
      008F28 AE 50 C5         [ 2]  636 	ldw	x, #0x50c5
      008F2B F6               [ 1]  637 	ld	a, (x)
      008F2C AA 04            [ 1]  638 	or	a, #0x04
      008F2E F7               [ 1]  639 	ld	(x), a
      008F2F 20 07            [ 2]  640 	jra	00113$
      008F31                        641 00112$:
                                    642 ;	../src/stm8s_clk.c: 367: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      008F31 AE 50 C5         [ 2]  643 	ldw	x, #0x50c5
      008F34 F6               [ 1]  644 	ld	a, (x)
      008F35 A4 FB            [ 1]  645 	and	a, #0xfb
      008F37 F7               [ 1]  646 	ld	(x), a
      008F38                        647 00113$:
                                    648 ;	../src/stm8s_clk.c: 371: CLK->SWR = (uint8_t)CLK_NewClock;
      008F38 AE 50 C4         [ 2]  649 	ldw	x, #0x50c4
      008F3B 7B 07            [ 1]  650 	ld	a, (0x07, sp)
      008F3D F7               [ 1]  651 	ld	(x), a
                                    652 ;	../src/stm8s_clk.c: 374: while((((CLK->SWCR & CLK_SWCR_SWIF) != 0 ) && (DownCounter != 0)))
      008F3E AE FF FF         [ 2]  653 	ldw	x, #0xffff
      008F41                        654 00115$:
      008F41 90 AE 50 C5      [ 2]  655 	ldw	y, #0x50c5
      008F45 90 F6            [ 1]  656 	ld	a, (y)
      008F47 A5 08            [ 1]  657 	bcp	a, #0x08
      008F49 27 06            [ 1]  658 	jreq	00117$
      008F4B 5D               [ 2]  659 	tnzw	x
      008F4C 27 03            [ 1]  660 	jreq	00117$
                                    661 ;	../src/stm8s_clk.c: 376: DownCounter--;
      008F4E 5A               [ 2]  662 	decw	x
      008F4F 20 F0            [ 2]  663 	jra	00115$
      008F51                        664 00117$:
                                    665 ;	../src/stm8s_clk.c: 379: if(DownCounter != 0)
      008F51 5D               [ 2]  666 	tnzw	x
      008F52 27 0D            [ 1]  667 	jreq	00119$
                                    668 ;	../src/stm8s_clk.c: 382: CLK->SWCR |= CLK_SWCR_SWEN;
      008F54 AE 50 C5         [ 2]  669 	ldw	x, #0x50c5
      008F57 F6               [ 1]  670 	ld	a, (x)
      008F58 AA 02            [ 1]  671 	or	a, #0x02
      008F5A F7               [ 1]  672 	ld	(x), a
                                    673 ;	../src/stm8s_clk.c: 383: Swif = SUCCESS;
      008F5B A6 01            [ 1]  674 	ld	a, #0x01
      008F5D 6B 02            [ 1]  675 	ld	(0x02, sp), a
      008F5F 20 02            [ 2]  676 	jra	00123$
      008F61                        677 00119$:
                                    678 ;	../src/stm8s_clk.c: 387: Swif = ERROR;
      008F61 0F 02            [ 1]  679 	clr	(0x02, sp)
      008F63                        680 00123$:
                                    681 ;	../src/stm8s_clk.c: 390: if(Swif != ERROR)
      008F63 0D 02            [ 1]  682 	tnz	(0x02, sp)
      008F65 27 37            [ 1]  683 	jreq	00136$
                                    684 ;	../src/stm8s_clk.c: 393: if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSI))
      008F67 0D 09            [ 1]  685 	tnz	(0x09, sp)
      008F69 26 0F            [ 1]  686 	jrne	00132$
      008F6B 7B 01            [ 1]  687 	ld	a, (0x01, sp)
      008F6D A1 E1            [ 1]  688 	cp	a, #0xe1
      008F6F 26 09            [ 1]  689 	jrne	00132$
                                    690 ;	../src/stm8s_clk.c: 395: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      008F71 AE 50 C0         [ 2]  691 	ldw	x, #0x50c0
      008F74 F6               [ 1]  692 	ld	a, (x)
      008F75 A4 FE            [ 1]  693 	and	a, #0xfe
      008F77 F7               [ 1]  694 	ld	(x), a
      008F78 20 24            [ 2]  695 	jra	00136$
      008F7A                        696 00132$:
                                    697 ;	../src/stm8s_clk.c: 397: else if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_LSI))
      008F7A 0D 09            [ 1]  698 	tnz	(0x09, sp)
      008F7C 26 0F            [ 1]  699 	jrne	00128$
      008F7E 7B 01            [ 1]  700 	ld	a, (0x01, sp)
      008F80 A1 D2            [ 1]  701 	cp	a, #0xd2
      008F82 26 09            [ 1]  702 	jrne	00128$
                                    703 ;	../src/stm8s_clk.c: 399: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      008F84 AE 50 C0         [ 2]  704 	ldw	x, #0x50c0
      008F87 F6               [ 1]  705 	ld	a, (x)
      008F88 A4 F7            [ 1]  706 	and	a, #0xf7
      008F8A F7               [ 1]  707 	ld	(x), a
      008F8B 20 11            [ 2]  708 	jra	00136$
      008F8D                        709 00128$:
                                    710 ;	../src/stm8s_clk.c: 401: else if ((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSE))
      008F8D 0D 09            [ 1]  711 	tnz	(0x09, sp)
      008F8F 26 0D            [ 1]  712 	jrne	00136$
      008F91 7B 01            [ 1]  713 	ld	a, (0x01, sp)
      008F93 A1 B4            [ 1]  714 	cp	a, #0xb4
      008F95 26 07            [ 1]  715 	jrne	00136$
                                    716 ;	../src/stm8s_clk.c: 403: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      008F97 AE 50 C1         [ 2]  717 	ldw	x, #0x50c1
      008F9A F6               [ 1]  718 	ld	a, (x)
      008F9B A4 FE            [ 1]  719 	and	a, #0xfe
      008F9D F7               [ 1]  720 	ld	(x), a
      008F9E                        721 00136$:
                                    722 ;	../src/stm8s_clk.c: 406: return(Swif);
      008F9E 7B 02            [ 1]  723 	ld	a, (0x02, sp)
      008FA0 5B 03            [ 2]  724 	addw	sp, #3
      008FA2 81               [ 4]  725 	ret
                                    726 ;	../src/stm8s_clk.c: 415: void CLK_HSIPrescalerConfig(CLK_Prescaler_TypeDef HSIPrescaler)
                                    727 ;	-----------------------------------------
                                    728 ;	 function CLK_HSIPrescalerConfig
                                    729 ;	-----------------------------------------
      008FA3                        730 _CLK_HSIPrescalerConfig:
                                    731 ;	../src/stm8s_clk.c: 418: assert_param(IS_CLK_HSIPRESCALER_OK(HSIPrescaler));
      008FA3 0D 03            [ 1]  732 	tnz	(0x03, sp)
      008FA5 27 23            [ 1]  733 	jreq	00104$
      008FA7 7B 03            [ 1]  734 	ld	a, (0x03, sp)
      008FA9 A1 08            [ 1]  735 	cp	a, #0x08
      008FAB 27 1D            [ 1]  736 	jreq	00104$
      008FAD 7B 03            [ 1]  737 	ld	a, (0x03, sp)
      008FAF A1 10            [ 1]  738 	cp	a, #0x10
      008FB1 27 17            [ 1]  739 	jreq	00104$
      008FB3 7B 03            [ 1]  740 	ld	a, (0x03, sp)
      008FB5 A1 18            [ 1]  741 	cp	a, #0x18
      008FB7 27 11            [ 1]  742 	jreq	00104$
      008FB9 90 AE 93 77      [ 2]  743 	ldw	y, #___str_0+0
      008FBD 4B A2            [ 1]  744 	push	#0xa2
      008FBF 4B 01            [ 1]  745 	push	#0x01
      008FC1 5F               [ 1]  746 	clrw	x
      008FC2 89               [ 2]  747 	pushw	x
      008FC3 90 89            [ 2]  748 	pushw	y
      008FC5 CD 80 A8         [ 4]  749 	call	_assert_failed
      008FC8 5B 06            [ 2]  750 	addw	sp, #6
      008FCA                        751 00104$:
                                    752 ;	../src/stm8s_clk.c: 421: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      008FCA AE 50 C6         [ 2]  753 	ldw	x, #0x50c6
      008FCD F6               [ 1]  754 	ld	a, (x)
      008FCE A4 E7            [ 1]  755 	and	a, #0xe7
      008FD0 F7               [ 1]  756 	ld	(x), a
                                    757 ;	../src/stm8s_clk.c: 424: CLK->CKDIVR |= (uint8_t)HSIPrescaler;
      008FD1 AE 50 C6         [ 2]  758 	ldw	x, #0x50c6
      008FD4 F6               [ 1]  759 	ld	a, (x)
      008FD5 1A 03            [ 1]  760 	or	a, (0x03, sp)
      008FD7 AE 50 C6         [ 2]  761 	ldw	x, #0x50c6
      008FDA F7               [ 1]  762 	ld	(x), a
      008FDB 81               [ 4]  763 	ret
                                    764 ;	../src/stm8s_clk.c: 436: void CLK_CCOConfig(CLK_Output_TypeDef CLK_CCO)
                                    765 ;	-----------------------------------------
                                    766 ;	 function CLK_CCOConfig
                                    767 ;	-----------------------------------------
      008FDC                        768 _CLK_CCOConfig:
                                    769 ;	../src/stm8s_clk.c: 439: assert_param(IS_CLK_OUTPUT_OK(CLK_CCO));
      008FDC 0D 03            [ 1]  770 	tnz	(0x03, sp)
      008FDE 27 59            [ 1]  771 	jreq	00104$
      008FE0 7B 03            [ 1]  772 	ld	a, (0x03, sp)
      008FE2 A1 04            [ 1]  773 	cp	a, #0x04
      008FE4 27 53            [ 1]  774 	jreq	00104$
      008FE6 7B 03            [ 1]  775 	ld	a, (0x03, sp)
      008FE8 A1 02            [ 1]  776 	cp	a, #0x02
      008FEA 27 4D            [ 1]  777 	jreq	00104$
      008FEC 7B 03            [ 1]  778 	ld	a, (0x03, sp)
      008FEE A1 08            [ 1]  779 	cp	a, #0x08
      008FF0 27 47            [ 1]  780 	jreq	00104$
      008FF2 7B 03            [ 1]  781 	ld	a, (0x03, sp)
      008FF4 A1 0A            [ 1]  782 	cp	a, #0x0a
      008FF6 27 41            [ 1]  783 	jreq	00104$
      008FF8 7B 03            [ 1]  784 	ld	a, (0x03, sp)
      008FFA A1 0C            [ 1]  785 	cp	a, #0x0c
      008FFC 27 3B            [ 1]  786 	jreq	00104$
      008FFE 7B 03            [ 1]  787 	ld	a, (0x03, sp)
      009000 A1 0E            [ 1]  788 	cp	a, #0x0e
      009002 27 35            [ 1]  789 	jreq	00104$
      009004 7B 03            [ 1]  790 	ld	a, (0x03, sp)
      009006 A1 10            [ 1]  791 	cp	a, #0x10
      009008 27 2F            [ 1]  792 	jreq	00104$
      00900A 7B 03            [ 1]  793 	ld	a, (0x03, sp)
      00900C A1 12            [ 1]  794 	cp	a, #0x12
      00900E 27 29            [ 1]  795 	jreq	00104$
      009010 7B 03            [ 1]  796 	ld	a, (0x03, sp)
      009012 A1 14            [ 1]  797 	cp	a, #0x14
      009014 27 23            [ 1]  798 	jreq	00104$
      009016 7B 03            [ 1]  799 	ld	a, (0x03, sp)
      009018 A1 16            [ 1]  800 	cp	a, #0x16
      00901A 27 1D            [ 1]  801 	jreq	00104$
      00901C 7B 03            [ 1]  802 	ld	a, (0x03, sp)
      00901E A1 18            [ 1]  803 	cp	a, #0x18
      009020 27 17            [ 1]  804 	jreq	00104$
      009022 7B 03            [ 1]  805 	ld	a, (0x03, sp)
      009024 A1 1A            [ 1]  806 	cp	a, #0x1a
      009026 27 11            [ 1]  807 	jreq	00104$
      009028 90 AE 93 77      [ 2]  808 	ldw	y, #___str_0+0
      00902C 4B B7            [ 1]  809 	push	#0xb7
      00902E 4B 01            [ 1]  810 	push	#0x01
      009030 5F               [ 1]  811 	clrw	x
      009031 89               [ 2]  812 	pushw	x
      009032 90 89            [ 2]  813 	pushw	y
      009034 CD 80 A8         [ 4]  814 	call	_assert_failed
      009037 5B 06            [ 2]  815 	addw	sp, #6
      009039                        816 00104$:
                                    817 ;	../src/stm8s_clk.c: 442: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOSEL);
      009039 AE 50 C9         [ 2]  818 	ldw	x, #0x50c9
      00903C F6               [ 1]  819 	ld	a, (x)
      00903D A4 E1            [ 1]  820 	and	a, #0xe1
      00903F F7               [ 1]  821 	ld	(x), a
                                    822 ;	../src/stm8s_clk.c: 445: CLK->CCOR |= (uint8_t)CLK_CCO;
      009040 AE 50 C9         [ 2]  823 	ldw	x, #0x50c9
      009043 F6               [ 1]  824 	ld	a, (x)
      009044 1A 03            [ 1]  825 	or	a, (0x03, sp)
      009046 AE 50 C9         [ 2]  826 	ldw	x, #0x50c9
      009049 F7               [ 1]  827 	ld	(x), a
                                    828 ;	../src/stm8s_clk.c: 448: CLK->CCOR |= CLK_CCOR_CCOEN;
      00904A 72 10 50 C9      [ 1]  829 	bset	0x50c9, #0
      00904E 81               [ 4]  830 	ret
                                    831 ;	../src/stm8s_clk.c: 459: void CLK_ITConfig(CLK_IT_TypeDef CLK_IT, FunctionalState NewState)
                                    832 ;	-----------------------------------------
                                    833 ;	 function CLK_ITConfig
                                    834 ;	-----------------------------------------
      00904F                        835 _CLK_ITConfig:
      00904F 89               [ 2]  836 	pushw	x
                                    837 ;	../src/stm8s_clk.c: 462: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      009050 0D 06            [ 1]  838 	tnz	(0x06, sp)
      009052 27 17            [ 1]  839 	jreq	00115$
      009054 7B 06            [ 1]  840 	ld	a, (0x06, sp)
      009056 A1 01            [ 1]  841 	cp	a, #0x01
      009058 27 11            [ 1]  842 	jreq	00115$
      00905A 90 AE 93 77      [ 2]  843 	ldw	y, #___str_0+0
      00905E 4B CE            [ 1]  844 	push	#0xce
      009060 4B 01            [ 1]  845 	push	#0x01
      009062 5F               [ 1]  846 	clrw	x
      009063 89               [ 2]  847 	pushw	x
      009064 90 89            [ 2]  848 	pushw	y
      009066 CD 80 A8         [ 4]  849 	call	_assert_failed
      009069 5B 06            [ 2]  850 	addw	sp, #6
      00906B                        851 00115$:
                                    852 ;	../src/stm8s_clk.c: 463: assert_param(IS_CLK_IT_OK(CLK_IT));
      00906B 7B 05            [ 1]  853 	ld	a, (0x05, sp)
      00906D A1 0C            [ 1]  854 	cp	a, #0x0c
      00906F 26 06            [ 1]  855 	jrne	00165$
      009071 A6 01            [ 1]  856 	ld	a, #0x01
      009073 6B 02            [ 1]  857 	ld	(0x02, sp), a
      009075 20 02            [ 2]  858 	jra	00166$
      009077                        859 00165$:
      009077 0F 02            [ 1]  860 	clr	(0x02, sp)
      009079                        861 00166$:
      009079 7B 05            [ 1]  862 	ld	a, (0x05, sp)
      00907B A1 1C            [ 1]  863 	cp	a, #0x1c
      00907D 26 06            [ 1]  864 	jrne	00168$
      00907F A6 01            [ 1]  865 	ld	a, #0x01
      009081 6B 01            [ 1]  866 	ld	(0x01, sp), a
      009083 20 02            [ 2]  867 	jra	00169$
      009085                        868 00168$:
      009085 0F 01            [ 1]  869 	clr	(0x01, sp)
      009087                        870 00169$:
      009087 0D 02            [ 1]  871 	tnz	(0x02, sp)
      009089 26 15            [ 1]  872 	jrne	00120$
      00908B 0D 01            [ 1]  873 	tnz	(0x01, sp)
      00908D 26 11            [ 1]  874 	jrne	00120$
      00908F 90 AE 93 77      [ 2]  875 	ldw	y, #___str_0+0
      009093 4B CF            [ 1]  876 	push	#0xcf
      009095 4B 01            [ 1]  877 	push	#0x01
      009097 5F               [ 1]  878 	clrw	x
      009098 89               [ 2]  879 	pushw	x
      009099 90 89            [ 2]  880 	pushw	y
      00909B CD 80 A8         [ 4]  881 	call	_assert_failed
      00909E 5B 06            [ 2]  882 	addw	sp, #6
      0090A0                        883 00120$:
                                    884 ;	../src/stm8s_clk.c: 465: if (NewState != DISABLE)
      0090A0 0D 06            [ 1]  885 	tnz	(0x06, sp)
      0090A2 27 1A            [ 1]  886 	jreq	00110$
                                    887 ;	../src/stm8s_clk.c: 467: switch (CLK_IT)
      0090A4 0D 02            [ 1]  888 	tnz	(0x02, sp)
      0090A6 26 0D            [ 1]  889 	jrne	00102$
      0090A8 0D 01            [ 1]  890 	tnz	(0x01, sp)
      0090AA 27 2A            [ 1]  891 	jreq	00112$
                                    892 ;	../src/stm8s_clk.c: 470: CLK->SWCR |= CLK_SWCR_SWIEN;
      0090AC AE 50 C5         [ 2]  893 	ldw	x, #0x50c5
      0090AF F6               [ 1]  894 	ld	a, (x)
      0090B0 AA 04            [ 1]  895 	or	a, #0x04
      0090B2 F7               [ 1]  896 	ld	(x), a
                                    897 ;	../src/stm8s_clk.c: 471: break;
      0090B3 20 21            [ 2]  898 	jra	00112$
                                    899 ;	../src/stm8s_clk.c: 472: case CLK_IT_CSSD: /* Enable the clock security system detection interrupt */
      0090B5                        900 00102$:
                                    901 ;	../src/stm8s_clk.c: 473: CLK->CSSR |= CLK_CSSR_CSSDIE;
      0090B5 AE 50 C8         [ 2]  902 	ldw	x, #0x50c8
      0090B8 F6               [ 1]  903 	ld	a, (x)
      0090B9 AA 04            [ 1]  904 	or	a, #0x04
      0090BB F7               [ 1]  905 	ld	(x), a
                                    906 ;	../src/stm8s_clk.c: 474: break;
      0090BC 20 18            [ 2]  907 	jra	00112$
                                    908 ;	../src/stm8s_clk.c: 477: }
      0090BE                        909 00110$:
                                    910 ;	../src/stm8s_clk.c: 481: switch (CLK_IT)
      0090BE 0D 02            [ 1]  911 	tnz	(0x02, sp)
      0090C0 26 0D            [ 1]  912 	jrne	00106$
      0090C2 0D 01            [ 1]  913 	tnz	(0x01, sp)
      0090C4 27 10            [ 1]  914 	jreq	00112$
                                    915 ;	../src/stm8s_clk.c: 484: CLK->SWCR  &= (uint8_t)(~CLK_SWCR_SWIEN);
      0090C6 AE 50 C5         [ 2]  916 	ldw	x, #0x50c5
      0090C9 F6               [ 1]  917 	ld	a, (x)
      0090CA A4 FB            [ 1]  918 	and	a, #0xfb
      0090CC F7               [ 1]  919 	ld	(x), a
                                    920 ;	../src/stm8s_clk.c: 485: break;
      0090CD 20 07            [ 2]  921 	jra	00112$
                                    922 ;	../src/stm8s_clk.c: 486: case CLK_IT_CSSD: /* Disable the clock security system detection interrupt */
      0090CF                        923 00106$:
                                    924 ;	../src/stm8s_clk.c: 487: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSDIE);
      0090CF AE 50 C8         [ 2]  925 	ldw	x, #0x50c8
      0090D2 F6               [ 1]  926 	ld	a, (x)
      0090D3 A4 FB            [ 1]  927 	and	a, #0xfb
      0090D5 F7               [ 1]  928 	ld	(x), a
                                    929 ;	../src/stm8s_clk.c: 491: }
      0090D6                        930 00112$:
      0090D6 85               [ 2]  931 	popw	x
      0090D7 81               [ 4]  932 	ret
                                    933 ;	../src/stm8s_clk.c: 500: void CLK_SYSCLKConfig(CLK_Prescaler_TypeDef CLK_Prescaler)
                                    934 ;	-----------------------------------------
                                    935 ;	 function CLK_SYSCLKConfig
                                    936 ;	-----------------------------------------
      0090D8                        937 _CLK_SYSCLKConfig:
      0090D8 89               [ 2]  938 	pushw	x
                                    939 ;	../src/stm8s_clk.c: 503: assert_param(IS_CLK_PRESCALER_OK(CLK_Prescaler));
      0090D9 0D 05            [ 1]  940 	tnz	(0x05, sp)
      0090DB 27 53            [ 1]  941 	jreq	00107$
      0090DD 7B 05            [ 1]  942 	ld	a, (0x05, sp)
      0090DF A1 08            [ 1]  943 	cp	a, #0x08
      0090E1 27 4D            [ 1]  944 	jreq	00107$
      0090E3 7B 05            [ 1]  945 	ld	a, (0x05, sp)
      0090E5 A1 10            [ 1]  946 	cp	a, #0x10
      0090E7 27 47            [ 1]  947 	jreq	00107$
      0090E9 7B 05            [ 1]  948 	ld	a, (0x05, sp)
      0090EB A1 18            [ 1]  949 	cp	a, #0x18
      0090ED 27 41            [ 1]  950 	jreq	00107$
      0090EF 7B 05            [ 1]  951 	ld	a, (0x05, sp)
      0090F1 A1 80            [ 1]  952 	cp	a, #0x80
      0090F3 27 3B            [ 1]  953 	jreq	00107$
      0090F5 7B 05            [ 1]  954 	ld	a, (0x05, sp)
      0090F7 A1 81            [ 1]  955 	cp	a, #0x81
      0090F9 27 35            [ 1]  956 	jreq	00107$
      0090FB 7B 05            [ 1]  957 	ld	a, (0x05, sp)
      0090FD A1 82            [ 1]  958 	cp	a, #0x82
      0090FF 27 2F            [ 1]  959 	jreq	00107$
      009101 7B 05            [ 1]  960 	ld	a, (0x05, sp)
      009103 A1 83            [ 1]  961 	cp	a, #0x83
      009105 27 29            [ 1]  962 	jreq	00107$
      009107 7B 05            [ 1]  963 	ld	a, (0x05, sp)
      009109 A1 84            [ 1]  964 	cp	a, #0x84
      00910B 27 23            [ 1]  965 	jreq	00107$
      00910D 7B 05            [ 1]  966 	ld	a, (0x05, sp)
      00910F A1 85            [ 1]  967 	cp	a, #0x85
      009111 27 1D            [ 1]  968 	jreq	00107$
      009113 7B 05            [ 1]  969 	ld	a, (0x05, sp)
      009115 A1 86            [ 1]  970 	cp	a, #0x86
      009117 27 17            [ 1]  971 	jreq	00107$
      009119 7B 05            [ 1]  972 	ld	a, (0x05, sp)
      00911B A1 87            [ 1]  973 	cp	a, #0x87
      00911D 27 11            [ 1]  974 	jreq	00107$
      00911F 90 AE 93 77      [ 2]  975 	ldw	y, #___str_0+0
      009123 4B F7            [ 1]  976 	push	#0xf7
      009125 4B 01            [ 1]  977 	push	#0x01
      009127 5F               [ 1]  978 	clrw	x
      009128 89               [ 2]  979 	pushw	x
      009129 90 89            [ 2]  980 	pushw	y
      00912B CD 80 A8         [ 4]  981 	call	_assert_failed
      00912E 5B 06            [ 2]  982 	addw	sp, #6
      009130                        983 00107$:
                                    984 ;	../src/stm8s_clk.c: 505: if (((uint8_t)CLK_Prescaler & (uint8_t)0x80) == 0x00) /* Bit7 = 0 means HSI divider */
      009130 0D 05            [ 1]  985 	tnz	(0x05, sp)
      009132 2B 19            [ 1]  986 	jrmi	00102$
                                    987 ;	../src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      009134 AE 50 C6         [ 2]  988 	ldw	x, #0x50c6
      009137 F6               [ 1]  989 	ld	a, (x)
      009138 A4 E7            [ 1]  990 	and	a, #0xe7
      00913A F7               [ 1]  991 	ld	(x), a
                                    992 ;	../src/stm8s_clk.c: 508: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_HSIDIV);
      00913B AE 50 C6         [ 2]  993 	ldw	x, #0x50c6
      00913E F6               [ 1]  994 	ld	a, (x)
      00913F 6B 01            [ 1]  995 	ld	(0x01, sp), a
      009141 7B 05            [ 1]  996 	ld	a, (0x05, sp)
      009143 A4 18            [ 1]  997 	and	a, #0x18
      009145 1A 01            [ 1]  998 	or	a, (0x01, sp)
      009147 AE 50 C6         [ 2]  999 	ldw	x, #0x50c6
      00914A F7               [ 1] 1000 	ld	(x), a
      00914B 20 17            [ 2] 1001 	jra	00104$
      00914D                       1002 00102$:
                                   1003 ;	../src/stm8s_clk.c: 512: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_CPUDIV);
      00914D AE 50 C6         [ 2] 1004 	ldw	x, #0x50c6
      009150 F6               [ 1] 1005 	ld	a, (x)
      009151 A4 F8            [ 1] 1006 	and	a, #0xf8
      009153 F7               [ 1] 1007 	ld	(x), a
                                   1008 ;	../src/stm8s_clk.c: 513: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_CPUDIV);
      009154 AE 50 C6         [ 2] 1009 	ldw	x, #0x50c6
      009157 F6               [ 1] 1010 	ld	a, (x)
      009158 6B 02            [ 1] 1011 	ld	(0x02, sp), a
      00915A 7B 05            [ 1] 1012 	ld	a, (0x05, sp)
      00915C A4 07            [ 1] 1013 	and	a, #0x07
      00915E 1A 02            [ 1] 1014 	or	a, (0x02, sp)
      009160 AE 50 C6         [ 2] 1015 	ldw	x, #0x50c6
      009163 F7               [ 1] 1016 	ld	(x), a
      009164                       1017 00104$:
      009164 85               [ 2] 1018 	popw	x
      009165 81               [ 4] 1019 	ret
                                   1020 ;	../src/stm8s_clk.c: 523: void CLK_SWIMConfig(CLK_SWIMDivider_TypeDef CLK_SWIMDivider)
                                   1021 ;	-----------------------------------------
                                   1022 ;	 function CLK_SWIMConfig
                                   1023 ;	-----------------------------------------
      009166                       1024 _CLK_SWIMConfig:
                                   1025 ;	../src/stm8s_clk.c: 526: assert_param(IS_CLK_SWIMDIVIDER_OK(CLK_SWIMDivider));
      009166 0D 03            [ 1] 1026 	tnz	(0x03, sp)
      009168 27 17            [ 1] 1027 	jreq	00107$
      00916A 7B 03            [ 1] 1028 	ld	a, (0x03, sp)
      00916C A1 01            [ 1] 1029 	cp	a, #0x01
      00916E 27 11            [ 1] 1030 	jreq	00107$
      009170 90 AE 93 77      [ 2] 1031 	ldw	y, #___str_0+0
      009174 4B 0E            [ 1] 1032 	push	#0x0e
      009176 4B 02            [ 1] 1033 	push	#0x02
      009178 5F               [ 1] 1034 	clrw	x
      009179 89               [ 2] 1035 	pushw	x
      00917A 90 89            [ 2] 1036 	pushw	y
      00917C CD 80 A8         [ 4] 1037 	call	_assert_failed
      00917F 5B 06            [ 2] 1038 	addw	sp, #6
      009181                       1039 00107$:
                                   1040 ;	../src/stm8s_clk.c: 528: if (CLK_SWIMDivider != CLK_SWIMDIVIDER_2)
      009181 0D 03            [ 1] 1041 	tnz	(0x03, sp)
      009183 27 06            [ 1] 1042 	jreq	00102$
                                   1043 ;	../src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
      009185 72 10 50 CD      [ 1] 1044 	bset	0x50cd, #0
      009189 20 04            [ 2] 1045 	jra	00104$
      00918B                       1046 00102$:
                                   1047 ;	../src/stm8s_clk.c: 536: CLK->SWIMCCR &= (uint8_t)(~CLK_SWIMCCR_SWIMDIV);
      00918B 72 11 50 CD      [ 1] 1048 	bres	0x50cd, #0
      00918F                       1049 00104$:
      00918F 81               [ 4] 1050 	ret
                                   1051 ;	../src/stm8s_clk.c: 547: void CLK_ClockSecuritySystemEnable(void)
                                   1052 ;	-----------------------------------------
                                   1053 ;	 function CLK_ClockSecuritySystemEnable
                                   1054 ;	-----------------------------------------
      009190                       1055 _CLK_ClockSecuritySystemEnable:
                                   1056 ;	../src/stm8s_clk.c: 550: CLK->CSSR |= CLK_CSSR_CSSEN;
      009190 72 10 50 C8      [ 1] 1057 	bset	0x50c8, #0
      009194 81               [ 4] 1058 	ret
                                   1059 ;	../src/stm8s_clk.c: 559: CLK_Source_TypeDef CLK_GetSYSCLKSource(void)
                                   1060 ;	-----------------------------------------
                                   1061 ;	 function CLK_GetSYSCLKSource
                                   1062 ;	-----------------------------------------
      009195                       1063 _CLK_GetSYSCLKSource:
                                   1064 ;	../src/stm8s_clk.c: 561: return((CLK_Source_TypeDef)CLK->CMSR);
      009195 AE 50 C3         [ 2] 1065 	ldw	x, #0x50c3
      009198 F6               [ 1] 1066 	ld	a, (x)
      009199 81               [ 4] 1067 	ret
                                   1068 ;	../src/stm8s_clk.c: 569: uint32_t CLK_GetClockFreq(void)
                                   1069 ;	-----------------------------------------
                                   1070 ;	 function CLK_GetClockFreq
                                   1071 ;	-----------------------------------------
      00919A                       1072 _CLK_GetClockFreq:
      00919A 52 07            [ 2] 1073 	sub	sp, #7
                                   1074 ;	../src/stm8s_clk.c: 576: clocksource = (CLK_Source_TypeDef)CLK->CMSR;
      00919C AE 50 C3         [ 2] 1075 	ldw	x, #0x50c3
      00919F F6               [ 1] 1076 	ld	a, (x)
      0091A0 6B 05            [ 1] 1077 	ld	(0x05, sp), a
                                   1078 ;	../src/stm8s_clk.c: 578: if (clocksource == CLK_SOURCE_HSI)
      0091A2 7B 05            [ 1] 1079 	ld	a, (0x05, sp)
      0091A4 A1 E1            [ 1] 1080 	cp	a, #0xe1
      0091A6 26 2A            [ 1] 1081 	jrne	00105$
                                   1082 ;	../src/stm8s_clk.c: 580: tmp = (uint8_t)(CLK->CKDIVR & CLK_CKDIVR_HSIDIV);
      0091A8 AE 50 C6         [ 2] 1083 	ldw	x, #0x50c6
      0091AB F6               [ 1] 1084 	ld	a, (x)
      0091AC A4 18            [ 1] 1085 	and	a, #0x18
                                   1086 ;	../src/stm8s_clk.c: 581: tmp = (uint8_t)(tmp >> 3);
      0091AE 44               [ 1] 1087 	srl	a
      0091AF 44               [ 1] 1088 	srl	a
      0091B0 44               [ 1] 1089 	srl	a
                                   1090 ;	../src/stm8s_clk.c: 582: clockfrequency = HSI_VALUE >> HSIDivExp[tmp];
      0091B1 AE 93 6B         [ 2] 1091 	ldw	x, #_HSIDivExp+0
      0091B4 1F 06            [ 2] 1092 	ldw	(0x06, sp), x
      0091B6 5F               [ 1] 1093 	clrw	x
      0091B7 97               [ 1] 1094 	ld	xl, a
      0091B8 72 FB 06         [ 2] 1095 	addw	x, (0x06, sp)
      0091BB F6               [ 1] 1096 	ld	a, (x)
      0091BC 90 AE 24 00      [ 2] 1097 	ldw	y, #0x2400
      0091C0 AE 00 F4         [ 2] 1098 	ldw	x, #0x00f4
      0091C3 4D               [ 1] 1099 	tnz	a
      0091C4 27 06            [ 1] 1100 	jreq	00121$
      0091C6                       1101 00120$:
      0091C6 54               [ 2] 1102 	srlw	x
      0091C7 90 56            [ 2] 1103 	rrcw	y
      0091C9 4A               [ 1] 1104 	dec	a
      0091CA 26 FA            [ 1] 1105 	jrne	00120$
      0091CC                       1106 00121$:
      0091CC 17 03            [ 2] 1107 	ldw	(0x03, sp), y
      0091CE 1F 01            [ 2] 1108 	ldw	(0x01, sp), x
      0091D0 20 1C            [ 2] 1109 	jra	00106$
      0091D2                       1110 00105$:
                                   1111 ;	../src/stm8s_clk.c: 584: else if ( clocksource == CLK_SOURCE_LSI)
      0091D2 7B 05            [ 1] 1112 	ld	a, (0x05, sp)
      0091D4 A1 D2            [ 1] 1113 	cp	a, #0xd2
      0091D6 26 0C            [ 1] 1114 	jrne	00102$
                                   1115 ;	../src/stm8s_clk.c: 586: clockfrequency = LSI_VALUE;
      0091D8 AE F4 00         [ 2] 1116 	ldw	x, #0xf400
      0091DB 1F 03            [ 2] 1117 	ldw	(0x03, sp), x
      0091DD AE 00 01         [ 2] 1118 	ldw	x, #0x0001
      0091E0 1F 01            [ 2] 1119 	ldw	(0x01, sp), x
      0091E2 20 0A            [ 2] 1120 	jra	00106$
      0091E4                       1121 00102$:
                                   1122 ;	../src/stm8s_clk.c: 590: clockfrequency = HSE_VALUE;
      0091E4 AE 24 00         [ 2] 1123 	ldw	x, #0x2400
      0091E7 1F 03            [ 2] 1124 	ldw	(0x03, sp), x
      0091E9 AE 00 F4         [ 2] 1125 	ldw	x, #0x00f4
      0091EC 1F 01            [ 2] 1126 	ldw	(0x01, sp), x
      0091EE                       1127 00106$:
                                   1128 ;	../src/stm8s_clk.c: 593: return((uint32_t)clockfrequency);
      0091EE 1E 03            [ 2] 1129 	ldw	x, (0x03, sp)
      0091F0 16 01            [ 2] 1130 	ldw	y, (0x01, sp)
      0091F2 5B 07            [ 2] 1131 	addw	sp, #7
      0091F4 81               [ 4] 1132 	ret
                                   1133 ;	../src/stm8s_clk.c: 603: void CLK_AdjustHSICalibrationValue(CLK_HSITrimValue_TypeDef CLK_HSICalibrationValue)
                                   1134 ;	-----------------------------------------
                                   1135 ;	 function CLK_AdjustHSICalibrationValue
                                   1136 ;	-----------------------------------------
      0091F5                       1137 _CLK_AdjustHSICalibrationValue:
                                   1138 ;	../src/stm8s_clk.c: 606: assert_param(IS_CLK_HSITRIMVALUE_OK(CLK_HSICalibrationValue));
      0091F5 0D 03            [ 1] 1139 	tnz	(0x03, sp)
      0091F7 27 3B            [ 1] 1140 	jreq	00104$
      0091F9 7B 03            [ 1] 1141 	ld	a, (0x03, sp)
      0091FB A1 01            [ 1] 1142 	cp	a, #0x01
      0091FD 27 35            [ 1] 1143 	jreq	00104$
      0091FF 7B 03            [ 1] 1144 	ld	a, (0x03, sp)
      009201 A1 02            [ 1] 1145 	cp	a, #0x02
      009203 27 2F            [ 1] 1146 	jreq	00104$
      009205 7B 03            [ 1] 1147 	ld	a, (0x03, sp)
      009207 A1 03            [ 1] 1148 	cp	a, #0x03
      009209 27 29            [ 1] 1149 	jreq	00104$
      00920B 7B 03            [ 1] 1150 	ld	a, (0x03, sp)
      00920D A1 04            [ 1] 1151 	cp	a, #0x04
      00920F 27 23            [ 1] 1152 	jreq	00104$
      009211 7B 03            [ 1] 1153 	ld	a, (0x03, sp)
      009213 A1 05            [ 1] 1154 	cp	a, #0x05
      009215 27 1D            [ 1] 1155 	jreq	00104$
      009217 7B 03            [ 1] 1156 	ld	a, (0x03, sp)
      009219 A1 06            [ 1] 1157 	cp	a, #0x06
      00921B 27 17            [ 1] 1158 	jreq	00104$
      00921D 7B 03            [ 1] 1159 	ld	a, (0x03, sp)
      00921F A1 07            [ 1] 1160 	cp	a, #0x07
      009221 27 11            [ 1] 1161 	jreq	00104$
      009223 90 AE 93 77      [ 2] 1162 	ldw	y, #___str_0+0
      009227 4B 5E            [ 1] 1163 	push	#0x5e
      009229 4B 02            [ 1] 1164 	push	#0x02
      00922B 5F               [ 1] 1165 	clrw	x
      00922C 89               [ 2] 1166 	pushw	x
      00922D 90 89            [ 2] 1167 	pushw	y
      00922F CD 80 A8         [ 4] 1168 	call	_assert_failed
      009232 5B 06            [ 2] 1169 	addw	sp, #6
      009234                       1170 00104$:
                                   1171 ;	../src/stm8s_clk.c: 609: CLK->HSITRIMR = (uint8_t)( (uint8_t)(CLK->HSITRIMR & (uint8_t)(~CLK_HSITRIMR_HSITRIM))|((uint8_t)CLK_HSICalibrationValue));
      009234 AE 50 CC         [ 2] 1172 	ldw	x, #0x50cc
      009237 F6               [ 1] 1173 	ld	a, (x)
      009238 A4 F8            [ 1] 1174 	and	a, #0xf8
      00923A 1A 03            [ 1] 1175 	or	a, (0x03, sp)
      00923C AE 50 CC         [ 2] 1176 	ldw	x, #0x50cc
      00923F F7               [ 1] 1177 	ld	(x), a
      009240 81               [ 4] 1178 	ret
                                   1179 ;	../src/stm8s_clk.c: 621: void CLK_SYSCLKEmergencyClear(void)
                                   1180 ;	-----------------------------------------
                                   1181 ;	 function CLK_SYSCLKEmergencyClear
                                   1182 ;	-----------------------------------------
      009241                       1183 _CLK_SYSCLKEmergencyClear:
                                   1184 ;	../src/stm8s_clk.c: 623: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWBSY);
      009241 72 11 50 C5      [ 1] 1185 	bres	0x50c5, #0
      009245 81               [ 4] 1186 	ret
                                   1187 ;	../src/stm8s_clk.c: 633: FlagStatus CLK_GetFlagStatus(CLK_Flag_TypeDef CLK_FLAG)
                                   1188 ;	-----------------------------------------
                                   1189 ;	 function CLK_GetFlagStatus
                                   1190 ;	-----------------------------------------
      009246                       1191 _CLK_GetFlagStatus:
                                   1192 ;	../src/stm8s_clk.c: 640: assert_param(IS_CLK_FLAG_OK(CLK_FLAG));
      009246 1E 03            [ 2] 1193 	ldw	x, (0x03, sp)
      009248 A3 01 10         [ 2] 1194 	cpw	x, #0x0110
      00924B 27 49            [ 1] 1195 	jreq	00119$
      00924D 1E 03            [ 2] 1196 	ldw	x, (0x03, sp)
      00924F A3 01 02         [ 2] 1197 	cpw	x, #0x0102
      009252 27 42            [ 1] 1198 	jreq	00119$
      009254 1E 03            [ 2] 1199 	ldw	x, (0x03, sp)
      009256 A3 02 02         [ 2] 1200 	cpw	x, #0x0202
      009259 27 3B            [ 1] 1201 	jreq	00119$
      00925B 1E 03            [ 2] 1202 	ldw	x, (0x03, sp)
      00925D A3 03 08         [ 2] 1203 	cpw	x, #0x0308
      009260 27 34            [ 1] 1204 	jreq	00119$
      009262 1E 03            [ 2] 1205 	ldw	x, (0x03, sp)
      009264 A3 03 01         [ 2] 1206 	cpw	x, #0x0301
      009267 27 2D            [ 1] 1207 	jreq	00119$
      009269 1E 03            [ 2] 1208 	ldw	x, (0x03, sp)
      00926B A3 04 08         [ 2] 1209 	cpw	x, #0x0408
      00926E 27 26            [ 1] 1210 	jreq	00119$
      009270 1E 03            [ 2] 1211 	ldw	x, (0x03, sp)
      009272 A3 04 02         [ 2] 1212 	cpw	x, #0x0402
      009275 27 1F            [ 1] 1213 	jreq	00119$
      009277 1E 03            [ 2] 1214 	ldw	x, (0x03, sp)
      009279 A3 05 04         [ 2] 1215 	cpw	x, #0x0504
      00927C 27 18            [ 1] 1216 	jreq	00119$
      00927E 1E 03            [ 2] 1217 	ldw	x, (0x03, sp)
      009280 A3 05 02         [ 2] 1218 	cpw	x, #0x0502
      009283 27 11            [ 1] 1219 	jreq	00119$
      009285 90 AE 93 77      [ 2] 1220 	ldw	y, #___str_0+0
      009289 4B 80            [ 1] 1221 	push	#0x80
      00928B 4B 02            [ 1] 1222 	push	#0x02
      00928D 5F               [ 1] 1223 	clrw	x
      00928E 89               [ 2] 1224 	pushw	x
      00928F 90 89            [ 2] 1225 	pushw	y
      009291 CD 80 A8         [ 4] 1226 	call	_assert_failed
      009294 5B 06            [ 2] 1227 	addw	sp, #6
      009296                       1228 00119$:
                                   1229 ;	../src/stm8s_clk.c: 643: statusreg = (uint16_t)((uint16_t)CLK_FLAG & (uint16_t)0xFF00);
      009296 4F               [ 1] 1230 	clr	a
      009297 97               [ 1] 1231 	ld	xl, a
      009298 7B 03            [ 1] 1232 	ld	a, (0x03, sp)
      00929A 95               [ 1] 1233 	ld	xh, a
                                   1234 ;	../src/stm8s_clk.c: 646: if (statusreg == 0x0100) /* The flag to check is in ICKRregister */
      00929B A3 01 00         [ 2] 1235 	cpw	x, #0x0100
      00929E 26 06            [ 1] 1236 	jrne	00111$
                                   1237 ;	../src/stm8s_clk.c: 648: tmpreg = CLK->ICKR;
      0092A0 AE 50 C0         [ 2] 1238 	ldw	x, #0x50c0
      0092A3 F6               [ 1] 1239 	ld	a, (x)
      0092A4 20 25            [ 2] 1240 	jra	00112$
      0092A6                       1241 00111$:
                                   1242 ;	../src/stm8s_clk.c: 650: else if (statusreg == 0x0200) /* The flag to check is in ECKRregister */
      0092A6 A3 02 00         [ 2] 1243 	cpw	x, #0x0200
      0092A9 26 06            [ 1] 1244 	jrne	00108$
                                   1245 ;	../src/stm8s_clk.c: 652: tmpreg = CLK->ECKR;
      0092AB AE 50 C1         [ 2] 1246 	ldw	x, #0x50c1
      0092AE F6               [ 1] 1247 	ld	a, (x)
      0092AF 20 1A            [ 2] 1248 	jra	00112$
      0092B1                       1249 00108$:
                                   1250 ;	../src/stm8s_clk.c: 654: else if (statusreg == 0x0300) /* The flag to check is in SWIC register */
      0092B1 A3 03 00         [ 2] 1251 	cpw	x, #0x0300
      0092B4 26 06            [ 1] 1252 	jrne	00105$
                                   1253 ;	../src/stm8s_clk.c: 656: tmpreg = CLK->SWCR;
      0092B6 AE 50 C5         [ 2] 1254 	ldw	x, #0x50c5
      0092B9 F6               [ 1] 1255 	ld	a, (x)
      0092BA 20 0F            [ 2] 1256 	jra	00112$
      0092BC                       1257 00105$:
                                   1258 ;	../src/stm8s_clk.c: 658: else if (statusreg == 0x0400) /* The flag to check is in CSS register */
      0092BC A3 04 00         [ 2] 1259 	cpw	x, #0x0400
      0092BF 26 06            [ 1] 1260 	jrne	00102$
                                   1261 ;	../src/stm8s_clk.c: 660: tmpreg = CLK->CSSR;
      0092C1 AE 50 C8         [ 2] 1262 	ldw	x, #0x50c8
      0092C4 F6               [ 1] 1263 	ld	a, (x)
      0092C5 20 04            [ 2] 1264 	jra	00112$
      0092C7                       1265 00102$:
                                   1266 ;	../src/stm8s_clk.c: 664: tmpreg = CLK->CCOR;
      0092C7 AE 50 C9         [ 2] 1267 	ldw	x, #0x50c9
      0092CA F6               [ 1] 1268 	ld	a, (x)
      0092CB                       1269 00112$:
                                   1270 ;	../src/stm8s_clk.c: 667: if ((tmpreg & (uint8_t)CLK_FLAG) != (uint8_t)RESET)
      0092CB 02               [ 1] 1271 	rlwa	x
      0092CC 7B 04            [ 1] 1272 	ld	a, (0x04, sp)
      0092CE 01               [ 1] 1273 	rrwa	x
      0092CF 89               [ 2] 1274 	pushw	x
      0092D0 14 01            [ 1] 1275 	and	a, (1, sp)
      0092D2 85               [ 2] 1276 	popw	x
      0092D3 4D               [ 1] 1277 	tnz	a
      0092D4 27 03            [ 1] 1278 	jreq	00114$
                                   1279 ;	../src/stm8s_clk.c: 669: bitstatus = SET;
      0092D6 A6 01            [ 1] 1280 	ld	a, #0x01
                                   1281 ;	../src/stm8s_clk.c: 673: bitstatus = RESET;
      0092D8 21                    1282 	.byte 0x21
      0092D9                       1283 00114$:
      0092D9 4F               [ 1] 1284 	clr	a
      0092DA                       1285 00115$:
                                   1286 ;	../src/stm8s_clk.c: 677: return((FlagStatus)bitstatus);
      0092DA 81               [ 4] 1287 	ret
                                   1288 ;	../src/stm8s_clk.c: 686: ITStatus CLK_GetITStatus(CLK_IT_TypeDef CLK_IT)
                                   1289 ;	-----------------------------------------
                                   1290 ;	 function CLK_GetITStatus
                                   1291 ;	-----------------------------------------
      0092DB                       1292 _CLK_GetITStatus:
      0092DB 88               [ 1] 1293 	push	a
                                   1294 ;	../src/stm8s_clk.c: 691: assert_param(IS_CLK_IT_OK(CLK_IT));
      0092DC 7B 04            [ 1] 1295 	ld	a, (0x04, sp)
      0092DE A1 1C            [ 1] 1296 	cp	a, #0x1c
      0092E0 26 06            [ 1] 1297 	jrne	00138$
      0092E2 A6 01            [ 1] 1298 	ld	a, #0x01
      0092E4 6B 01            [ 1] 1299 	ld	(0x01, sp), a
      0092E6 20 02            [ 2] 1300 	jra	00139$
      0092E8                       1301 00138$:
      0092E8 0F 01            [ 1] 1302 	clr	(0x01, sp)
      0092EA                       1303 00139$:
      0092EA 7B 04            [ 1] 1304 	ld	a, (0x04, sp)
      0092EC A1 0C            [ 1] 1305 	cp	a, #0x0c
      0092EE 27 15            [ 1] 1306 	jreq	00113$
      0092F0 0D 01            [ 1] 1307 	tnz	(0x01, sp)
      0092F2 26 11            [ 1] 1308 	jrne	00113$
      0092F4 90 AE 93 77      [ 2] 1309 	ldw	y, #___str_0+0
      0092F8 4B B3            [ 1] 1310 	push	#0xb3
      0092FA 4B 02            [ 1] 1311 	push	#0x02
      0092FC 5F               [ 1] 1312 	clrw	x
      0092FD 89               [ 2] 1313 	pushw	x
      0092FE 90 89            [ 2] 1314 	pushw	y
      009300 CD 80 A8         [ 4] 1315 	call	_assert_failed
      009303 5B 06            [ 2] 1316 	addw	sp, #6
      009305                       1317 00113$:
                                   1318 ;	../src/stm8s_clk.c: 693: if (CLK_IT == CLK_IT_SWIF)
      009305 0D 01            [ 1] 1319 	tnz	(0x01, sp)
      009307 27 11            [ 1] 1320 	jreq	00108$
                                   1321 ;	../src/stm8s_clk.c: 696: if ((CLK->SWCR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      009309 AE 50 C5         [ 2] 1322 	ldw	x, #0x50c5
      00930C F6               [ 1] 1323 	ld	a, (x)
      00930D 14 04            [ 1] 1324 	and	a, (0x04, sp)
      00930F A1 0C            [ 1] 1325 	cp	a, #0x0c
      009311 26 04            [ 1] 1326 	jrne	00102$
                                   1327 ;	../src/stm8s_clk.c: 698: bitstatus = SET;
      009313 A6 01            [ 1] 1328 	ld	a, #0x01
      009315 20 11            [ 2] 1329 	jra	00109$
      009317                       1330 00102$:
                                   1331 ;	../src/stm8s_clk.c: 702: bitstatus = RESET;
      009317 4F               [ 1] 1332 	clr	a
      009318 20 0E            [ 2] 1333 	jra	00109$
      00931A                       1334 00108$:
                                   1335 ;	../src/stm8s_clk.c: 708: if ((CLK->CSSR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      00931A AE 50 C8         [ 2] 1336 	ldw	x, #0x50c8
      00931D F6               [ 1] 1337 	ld	a, (x)
      00931E 14 04            [ 1] 1338 	and	a, (0x04, sp)
      009320 A1 0C            [ 1] 1339 	cp	a, #0x0c
      009322 26 03            [ 1] 1340 	jrne	00105$
                                   1341 ;	../src/stm8s_clk.c: 710: bitstatus = SET;
      009324 A6 01            [ 1] 1342 	ld	a, #0x01
                                   1343 ;	../src/stm8s_clk.c: 714: bitstatus = RESET;
      009326 21                    1344 	.byte 0x21
      009327                       1345 00105$:
      009327 4F               [ 1] 1346 	clr	a
      009328                       1347 00109$:
                                   1348 ;	../src/stm8s_clk.c: 719: return bitstatus;
      009328 5B 01            [ 2] 1349 	addw	sp, #1
      00932A 81               [ 4] 1350 	ret
                                   1351 ;	../src/stm8s_clk.c: 728: void CLK_ClearITPendingBit(CLK_IT_TypeDef CLK_IT)
                                   1352 ;	-----------------------------------------
                                   1353 ;	 function CLK_ClearITPendingBit
                                   1354 ;	-----------------------------------------
      00932B                       1355 _CLK_ClearITPendingBit:
      00932B 88               [ 1] 1356 	push	a
                                   1357 ;	../src/stm8s_clk.c: 731: assert_param(IS_CLK_IT_OK(CLK_IT));
      00932C 7B 04            [ 1] 1358 	ld	a, (0x04, sp)
      00932E A1 0C            [ 1] 1359 	cp	a, #0x0c
      009330 26 06            [ 1] 1360 	jrne	00124$
      009332 A6 01            [ 1] 1361 	ld	a, #0x01
      009334 6B 01            [ 1] 1362 	ld	(0x01, sp), a
      009336 20 02            [ 2] 1363 	jra	00125$
      009338                       1364 00124$:
      009338 0F 01            [ 1] 1365 	clr	(0x01, sp)
      00933A                       1366 00125$:
      00933A 0D 01            [ 1] 1367 	tnz	(0x01, sp)
      00933C 26 17            [ 1] 1368 	jrne	00107$
      00933E 7B 04            [ 1] 1369 	ld	a, (0x04, sp)
      009340 A1 1C            [ 1] 1370 	cp	a, #0x1c
      009342 27 11            [ 1] 1371 	jreq	00107$
      009344 90 AE 93 77      [ 2] 1372 	ldw	y, #___str_0+0
      009348 4B DB            [ 1] 1373 	push	#0xdb
      00934A 4B 02            [ 1] 1374 	push	#0x02
      00934C 5F               [ 1] 1375 	clrw	x
      00934D 89               [ 2] 1376 	pushw	x
      00934E 90 89            [ 2] 1377 	pushw	y
      009350 CD 80 A8         [ 4] 1378 	call	_assert_failed
      009353 5B 06            [ 2] 1379 	addw	sp, #6
      009355                       1380 00107$:
                                   1381 ;	../src/stm8s_clk.c: 733: if (CLK_IT == (uint8_t)CLK_IT_CSSD)
      009355 0D 01            [ 1] 1382 	tnz	(0x01, sp)
      009357 27 09            [ 1] 1383 	jreq	00102$
                                   1384 ;	../src/stm8s_clk.c: 736: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSD);
      009359 AE 50 C8         [ 2] 1385 	ldw	x, #0x50c8
      00935C F6               [ 1] 1386 	ld	a, (x)
      00935D A4 F7            [ 1] 1387 	and	a, #0xf7
      00935F F7               [ 1] 1388 	ld	(x), a
      009360 20 07            [ 2] 1389 	jra	00104$
      009362                       1390 00102$:
                                   1391 ;	../src/stm8s_clk.c: 741: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIF);
      009362 AE 50 C5         [ 2] 1392 	ldw	x, #0x50c5
      009365 F6               [ 1] 1393 	ld	a, (x)
      009366 A4 F7            [ 1] 1394 	and	a, #0xf7
      009368 F7               [ 1] 1395 	ld	(x), a
      009369                       1396 00104$:
      009369 84               [ 1] 1397 	pop	a
      00936A 81               [ 4] 1398 	ret
                                   1399 	.area CODE
      00936B                       1400 _HSIDivExp:
      00936B 00                    1401 	.db #0x00	; 0
      00936C 01                    1402 	.db #0x01	; 1
      00936D 02                    1403 	.db #0x02	; 2
      00936E 03                    1404 	.db #0x03	; 3
      00936F                       1405 _CLKPrescTable:
      00936F 01                    1406 	.db #0x01	; 1
      009370 02                    1407 	.db #0x02	; 2
      009371 04                    1408 	.db #0x04	; 4
      009372 08                    1409 	.db #0x08	; 8
      009373 0A                    1410 	.db #0x0A	; 10
      009374 10                    1411 	.db #0x10	; 16
      009375 14                    1412 	.db #0x14	; 20
      009376 28                    1413 	.db #0x28	; 40
      009377                       1414 ___str_0:
      009377 2E 2E 2F 73 72 63 2F  1415 	.ascii "../src/stm8s_clk.c"
             73 74 6D 38 73 5F 63
             6C 6B 2E 63
      009389 00                    1416 	.db 0x00
                                   1417 	.area INITIALIZER
                                   1418 	.area CABS (ABS)
