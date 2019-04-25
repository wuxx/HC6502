.PHONY: all clean

all: 
	ca65 test.s
	cl65 -C test.cfg -o test test.o

gen:
	../../EEPROM_Programmer/linux/at28_program/main -n -i test

clean:	
	-rm -f test.o test
