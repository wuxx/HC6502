#ifndef __FIFO_H__
#define __FIFO_H__

#include <stdint.h>

typedef uint8_t FIFO_Data_t;
typedef uint8_t FIFO_Index_t;

typedef struct
{
    FIFO_Index_t SizeMask;   
    volatile FIFO_Index_t Head;
    volatile FIFO_Index_t Tail;
} FIFO;

#define FIFO_DECL(Name,Size)    FIFO_Data_t Name[Size+sizeof(FIFO)] = { Size-1 }
#define FIFO_BUF(X)             ((FIFO_Data_t *)&X[1])
#define FIFO_INC(INDEX,MOD1)    ((INDEX+1)&(MOD1))

void    FIFO_Clear(FIFO *Queue);
uint8_t FIFO_Write(FIFO *Queue, FIFO_Data_t data);
uint8_t FIFO_WriteAvail(FIFO *Queue);
uint8_t FIFO_Read(FIFO *Queue, FIFO_Data_t *data);
uint8_t FIFO_ReadAvail(FIFO *Queue);
uint8_t Getc(FIFO *Queue);
uint8_t Getc_Timeout(FIFO *Queue, FIFO_Data_t *data, uint16_t Timeout);

#define TIME_INFINITE 0

#endif /* __FIFO_H__ */
