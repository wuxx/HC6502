                  .setcpu "6502"

                  .import _main

                  .segment "VECTORS"

                  .word   nmi
                  .word   reset
                  .word   irq

                  .segment "CODE"

reset:            jmp __main

nmi:              rti

irq:              rti

__main:
    jmp _main

