#ifndef __SERIAL_H__
#define __SERIAL_H__
#include <stdint.h> 

int32_t serial_send(uint8_t *buf, uint32_t size);
int32_t serial_recv(uint8_t *buf, uint32_t size);

int32_t serial_init();

#endif /* __SERIAL_H__ */
