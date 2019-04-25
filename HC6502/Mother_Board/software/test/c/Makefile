.PHONY: all clean

all: 
	cl65 -C test.cfg -t none -m main.map -o main startup.s main.c
	da65 main > main.asm

all1: 
	cc65 -t none main.c -o main.s
	ca65 -t none main.s -o main.o
	ca65 -t none startup.s -o startup.o
	ld65 -C test.cfg -o main startup.o main.o 

gen:
	../../EEPROM_Programmer/linux/at28_program/main -n -i test

clean:	
	-rm -f *.o
