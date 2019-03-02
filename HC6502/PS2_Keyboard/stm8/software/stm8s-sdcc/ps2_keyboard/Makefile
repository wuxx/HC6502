## Select one of these
#DEVICE=stm8s003f3
DEVICE=stm8s103f3

## A directory for common include files
COMMONDIR = ../inc/

## Get program name from enclosing directory name
PROGRAM = main

SOURCES= main.c fifo.c ../src/stm8s_uart1.c ../src/stm8s_gpio.c  ../src/stm8s_clk.c ../src/stm8s_exti.c

OBJECTS=$(SOURCES:.c=.rel)
HEADERS=$(wildcard *.h $(COMMONDIR)/*.h)

CC = sdcc
PROGRAMMER = stlinkv2


DEFINES=
## Set MCU-type DEFINE
ifeq ($(DEVICE),stm8s003f3)
    DEFINES += -DSTM8S003
endif
ifeq ($(DEVICE),stm8s103f3)
    DEFINES += -DSTM8S103
endif

CPPFLAGS = -I$(COMMONDIR) -I.
#--Werror
CFLAGS  = --opt-code-size  --std-sdcc99 -mstm8 $(DEFINES) 
LDFLAGS = --opt-code-size -lstm8 -mstm8 --out-fmt-ihx

.PHONY: all clean flash

$(PROGRAM).ihx: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.rel : %.c $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

CCOMPILEDFILES=$(SOURCES:.c=.asm) $(SOURCES:.c=.lst) $(SOURCES:.c=.rel) \
               $(SOURCES:.c=.rst) $(SOURCES:.c=.sym)
clean:
	rm -f $(PROGRAM).ihx $(PROGRAM).cdb $(PROGRAM).lk $(PROGRAM).map $(CCOMPILEDFILES)

flash: $(PROGRAM).ihx
	stm8flash -c $(PROGRAMMER) -p $(DEVICE) -w $(PROGRAM).ihx

allabc:
	echo "hello"
	$(CC) $(CFLAGS) -I../inc -c -o main.rel main.c
	$(CC) $(CFLAGS) -I../inc -c -o stm8s_uart1.rel ../src/stm8s_uart1.c
	$(CC) $(CFLAGS) -I../inc -c -o stm8s_gpio.rel ../src/stm8s_gpio.c
	$(CC) $(CFLAGS) -I../inc -c -o stm8s_clk.rel  ../src/stm8s_clk.c
	$(CC) $(CFLAGS) -I../inc -c -o stm8s_exti.rel ../src/stm8s_exti.c
	$(CC) $(LDFLAGS) stm8s_uart1.rel stm8s_gpio.rel stm8s_clk.rel stm8s_exti.rel main.rel -o main.ihx
