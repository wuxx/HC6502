#ifndef __UART_H__
#define __UART_H__

int uart_init();
char uart_getc();
void uart_putc(char c);
void uart_puts(char *s);

int uart_printf(const char *format, ...);

void uart_handler();

#endif /* __UART_H__ */
