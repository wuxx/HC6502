#ifndef __UART_H
#define __UART_H

/**
 * Initialize UART with fixed settings: 115200 8N1
 */
void uart_init();

uint8_t uart_get();

/**
 * Write string to uart.
 * @param
 *
 * @return bytes written.
 */
int uart_puts(const char *s);


#endif /* __UART_H */
