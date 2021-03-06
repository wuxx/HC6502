;
; File generated by cc65 v 2.17 - Git 180bb082
;
	.fopt		compiler,"cc65 v 2.17 - Git 180bb082"
	.setcpu		"6502"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.export		_gpio_init
	.export		_gpio_write
	.export		_gpio_read

; ---------------------------------------------------------------
; signed char __near__ gpio_init (unsigned long, unsigned char)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_gpio_init: near

.segment	"CODE"

	ldy     #$0A
	jsr     subysp
	ldy     #$0E
	jsr     ldeaxysp
	ldx     sreg+1
	lda     sreg
	ldy     #$08
	jsr     staxysp
	ldy     #$0E
	jsr     ldeaxysp
	jsr     pusheax
	ldx     #$FF
	txa
	jsr     tosand0ax
	ldy     #$06
	jsr     staxysp
	and     #$0F
	ldy     #$05
	sta     (sp),y
	iny
	lda     (sp),y
	and     #$F0
	cmp     #$A0
	bne     L000B
	ldy     #$09
	jsr     ldaxysp
	jsr     incax1
	ldy     #$03
	jsr     staxysp
	ldy     #$09
	jsr     ldaxysp
	jsr     incax3
	jmp     L0099
L000B:	ldy     #$09
	jsr     ldaxysp
	ldy     #$03
	jsr     staxysp
	ldy     #$09
	jsr     ldaxysp
	jsr     incax2
L0099:	ldy     #$01
	jsr     staxysp
	ldy     #$0A
	lda     (sp),y
	bne     L0018
	ldy     #$02
	jsr     ldaxysp
	sta     ptr1
	stx     ptr1+1
	ldy     #$00
	lda     (ptr1),y
	sta     (sp),y
	ldy     #$05
	lda     (sp),y
	tay
	lda     #$01
	ldx     #$00
	jsr     aslaxy
	eor     #$FF
	ldy     #$00
	and     (sp),y
	sta     (sp),y
	ldy     #$02
	jmp     L009E
L0018:	ldy     #$02
	jsr     ldaxysp
	sta     ptr1
	stx     ptr1+1
	ldy     #$00
	lda     (ptr1),y
	sta     (sp),y
	ldy     #$05
	lda     (sp),y
	tay
	lda     #$01
	ldx     #$00
	jsr     aslaxy
	ldy     #$00
	ora     (sp),y
	sta     (sp),y
	ldy     #$02
	jsr     ldaxysp
	sta     ptr1
	stx     ptr1+1
	ldy     #$00
	lda     (sp),y
	sta     (ptr1),y
	ldy     #$04
	jsr     ldaxysp
	sta     ptr1
	stx     ptr1+1
	ldy     #$00
	lda     (ptr1),y
	sta     (sp),y
	ldy     #$05
	lda     (sp),y
	tay
	lda     #$01
	ldx     #$00
	jsr     aslaxy
	eor     #$FF
	ldy     #$00
	and     (sp),y
	sta     (sp),y
	ldy     #$04
L009E:	jsr     ldaxysp
	sta     ptr1
	stx     ptr1+1
	ldy     #$00
	lda     (sp),y
	sta     (ptr1),y
	ldx     #$00
	txa
	ldy     #$0F
	jmp     addysp

.endproc

; ---------------------------------------------------------------
; void __near__ gpio_write (unsigned long, unsigned char)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_gpio_write: near

.segment	"CODE"

	ldy     #$0A
	jsr     subysp
	ldy     #$0E
	jsr     ldeaxysp
	ldx     sreg+1
	lda     sreg
	ldy     #$08
	jsr     staxysp
	ldy     #$0E
	jsr     ldeaxysp
	jsr     pusheax
	ldx     #$FF
	txa
	jsr     tosand0ax
	ldy     #$06
	jsr     staxysp
	and     #$0F
	ldy     #$05
	sta     (sp),y
	iny
	lda     (sp),y
	and     #$F0
	cmp     #$A0
	bne     L004C
	ldy     #$09
	jsr     ldaxysp
	jsr     incax1
	ldy     #$03
	jsr     staxysp
	ldy     #$09
	jsr     ldaxysp
	jsr     incax3
	jmp     L00A1
L004C:	ldy     #$09
	jsr     ldaxysp
	ldy     #$03
	jsr     staxysp
	ldy     #$09
	jsr     ldaxysp
	jsr     incax2
L00A1:	ldy     #$01
	jsr     staxysp
	ldy     #$0A
	lda     (sp),y
	beq     L0059
	ldy     #$04
	jsr     ldaxysp
	sta     ptr1
	stx     ptr1+1
	ldy     #$00
	lda     (ptr1),y
	sta     (sp),y
	ldy     #$05
	lda     (sp),y
	tay
	lda     #$01
	ldx     #$00
	jsr     aslaxy
	ldy     #$00
	ora     (sp),y
	jmp     L00A8
L0059:	ldy     #$04
	jsr     ldaxysp
	sta     ptr1
	stx     ptr1+1
	ldy     #$00
	lda     (ptr1),y
	sta     (sp),y
	ldy     #$05
	lda     (sp),y
	tay
	lda     #$01
	ldx     #$00
	jsr     aslaxy
	eor     #$FF
	ldy     #$00
	and     (sp),y
L00A8:	sta     (sp),y
	ldy     #$04
	jsr     ldaxysp
	sta     ptr1
	stx     ptr1+1
	ldy     #$00
	lda     (sp),y
	sta     (ptr1),y
	ldy     #$0F
	jmp     addysp

.endproc

; ---------------------------------------------------------------
; unsigned char __near__ gpio_read (unsigned long)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_gpio_read: near

.segment	"CODE"

	ldy     #$0A
	jsr     subysp
	ldy     #$0D
	jsr     ldeaxysp
	ldx     sreg+1
	lda     sreg
	ldy     #$08
	jsr     staxysp
	ldy     #$0D
	jsr     ldeaxysp
	jsr     pusheax
	ldx     #$FF
	txa
	jsr     tosand0ax
	ldy     #$06
	jsr     staxysp
	and     #$0F
	ldy     #$05
	sta     (sp),y
	iny
	lda     (sp),y
	and     #$F0
	cmp     #$A0
	bne     L007F
	ldy     #$09
	jsr     ldaxysp
	jsr     incax1
	ldy     #$03
	jsr     staxysp
	ldy     #$09
	jsr     ldaxysp
	jsr     incax3
	jmp     L00AB
L007F:	ldy     #$09
	jsr     ldaxysp
	ldy     #$03
	jsr     staxysp
	ldy     #$09
	jsr     ldaxysp
	jsr     incax2
L00AB:	ldy     #$01
	jsr     staxysp
	ldy     #$04
	jsr     ldaxysp
	sta     ptr1
	stx     ptr1+1
	ldy     #$00
	lda     (ptr1),y
	sta     (sp),y
	ldy     #$05
	lda     (sp),y
	tay
	lda     #$01
	ldx     #$00
	jsr     aslaxy
	ldy     #$00
	and     (sp),y
	pha
	ldx     #$00
	pla
	beq     L0095
	lda     #$01
L0095:	ldy     #$0E
	jmp     addysp

.endproc

