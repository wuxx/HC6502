SOURCES = acia.s65 string.s65 main.s65

%.o: %.s65
	ca65 -o $@ -l $(@:.o=.lst) $<

all: firmware

firmware: $(SOURCES:.s65=.o)
	cl65 -C firmware.cfg -t none -o $@ $^

gen:
	../../EEPROM_Programmer/linux/at28_program/main -n -i firmware
clean:
	rm -f firmware *.o *.lst
