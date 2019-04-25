.PHONY: all clean

all: 
	cl65 -C test.cfg test.s

gen:
	../../EEPROM_Programmer/linux/at28_program/main -n -i test

clean:	
	-rm -f test.o test
