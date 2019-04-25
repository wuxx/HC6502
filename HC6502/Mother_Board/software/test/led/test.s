          .setcpu "6502"

            VIA_ORA  = $7f21
            VIA_DDRA = $7f23

            .segment "VECTORS"

            .word   nmi
            .word   reset
            .word   irq

            .code

reset:      jmp main

nmi:        rti

irq:        rti

main:       lda #$ff
            sta VIA_DDRA
loop:       lda #$00
            sta VIA_ORA
            jsr delay
            lda #$ff
            sta VIA_ORA
            jsr delay
            jmp loop

delay:      ldx #200
@delay2:    ldy #0
@delay1:    dey
            bne @delay1
            dex
            bne @delay2
            rts
