#include <stdio.h>
#include <stdarg.h>

#include "type.h"
#include "memory_map.h"
#include "uart.h"
#include "shell.h"

int uart_init()
{
    u8 data;
    data = ACIA_PARITY_DISABLE | ACIA_ECHO_DISABLE | ACIA_TX_INT_DISABLE_RTS_LOW | ACIA_RX_INT_DISABLE | ACIA_DTR_LOW;
    writeb(ACIA_COMMAND, data);

    data = ACIA_STOP_BITS_1 | ACIA_DATA_BITS_8 | ACIA_CLOCK_INT | ACIA_BAUD_9600;
    writeb(ACIA_CONTROL, data);
    return 0;
}

char uart_getc()
{
    char c;
    u8 status;

    /* wait rx full */
    while(1) {
        status = readb(ACIA_STATUS);
        if (status & ACIA_STATUS_RX_FULL) {
            break;
        }
    }

    c = readb(ACIA_DATA);

    return c;

}

void uart_putc(char c)
{
    u8 status;

    /* wait tx empty */
    while(1) {
        status = readb(ACIA_STATUS);
        if (status & ACIA_STATUS_TX_EMPTY) {
            break;
        }
    }

    writeb(ACIA_DATA, c);

}

void uart_puts(char *s)
{
    int i;

    for(i = 0; s[i]; i++) {
        uart_putc(s[i]);
    }
}


#define FORMAT_BUF_SIZE (256)

int uart_printf(const char *format, ...)
{

    u32 len;
    va_list args;
    static char format_buf[FORMAT_BUF_SIZE] = {0};

    va_start(args, format);
    len = vsnprintf(format_buf, sizeof(format_buf), format, args);
    va_end(args);

    uart_puts(format_buf);

    return len;

}

#define UART_IO_SIZE    (512)

int  urb_index;
char uart_recv_buf[UART_IO_SIZE];

void uart_handler()
{
	u8 ch;

	ch = uart_getc();   

    //uart_printf("get %x [%c]\r\n", ch, ch);

	if (ch == '\n') {   /* sscom will send '\r\n' we ignore the '\n' */
		return;
	}

	if (urb_index == (UART_IO_SIZE - 1) && ch != '\r') {
		uart_puts("cmd too long!\n");
		urb_index = 0;
		return;
	}

	if (ch == '\r') {
		uart_recv_buf[urb_index] = '\0';  /* terminate the string. */
		shell(uart_recv_buf);
		urb_index = 0;
		return;
	} else {
		uart_recv_buf[urb_index] = ch;
		urb_index++;
	}

	/* echo */
	uart_putc(ch);

}
