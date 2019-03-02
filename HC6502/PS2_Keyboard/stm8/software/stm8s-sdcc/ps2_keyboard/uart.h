#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>

void uart_init();
void uart_putc(uint8_t c);

#endif /* __UART_H__ */
