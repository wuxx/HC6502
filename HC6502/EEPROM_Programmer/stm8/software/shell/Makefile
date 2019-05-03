SDCC=sdcc
SDLD=sdld
FLASH=stm8flash
OBJECT= uart.ihx
BOARD=stm8s103f3
PROGRAMMER=stlinkv2

.PHONY: all clean flash

all: $(OBJECT)

clean:
	rm -f $(OBJECT)

flash:
	$(FLASH) -c $(PROGRAMMER) -p $(BOARD) -w $(OBJECT)

scp:
	scp root@123.56.12.242:/home/share/private/6502/HC6502/EEPROM_Programmer/stm8/software/shell/uart.ihx .

%.ihx: %.c
	$(SDCC) --std-c99 -lstm8 -mstm8 --out-fmt-ihx $(CFLAGS) $(LDFLAGS) $<

%.elf: %.c
	$(SDCC) -lstm8 -mstm8 --out-fmt-elf $(CFLAGS) $(LDFLAGS) $<

%.bin: %.elf
	@#sdobjcopy -O binary $< $@
	@echo "gen bin"
