C_SOURCES = main.c uart.c gpio.c shell.c ps2.c vga.c
ASM_SOURCES = zeropage.s65 interrupt.s65 startup.s65 utils.s65 acia.s65 led.s65 

# Compilation of C files
%.o: %.c
	cc65 --cpu 6502 --all-cdecl -O -t none -o $(@:.o=.s) $<
	ca65 --cpu 6502 -o $@ -l $(@:.o=.lst) $(<:.c=.s)

# Compilation of assembler files
%.o: %.s65
	ca65 --cpu 6502 -o $@ -l $(@:.o=.lst) $<

# Default target
all: firmware

# Build the firmware binary
firmware: $(ASM_SOURCES:.s65=.o) $(C_SOURCES:.c=.o)
	cl65 -C firmware.cfg -m firmware.map -o $@ $^ cc65.lib

# Remove all generated files
clean:
	rm -f firmware *.s *.o *.lst *.map

gen:
	../../../../EEPROM_Programmer/linux/at28_program/main -g 256 -n -i firmware

write:
	../../../../EEPROM_Programmer/linux/at28_program/main -i firmware

scp:

# Rebuild the firmware and use minpro to burn the EEPROM
# check the programmer shell with $minicom -D /dev/ttyS0 -b 115200
flash: clean all
	@#minipro -p at28c256 -w firmware
	@#../../../../EEPROM_Programmer/linux/at28_program/main -c 44 -d /dev/ttyUSB0 -g 256 -i firmware -n
	#scp root@123.56.12.242:/home/share/oss/HC6502/HC6502/Mother_Board/software/c/hcos/firmware .
	../../../EEPROM_Programmer/host/linux/at28_programmer -c 52 -d /dev/ttyS0 -g 256 -i firmware  -n
