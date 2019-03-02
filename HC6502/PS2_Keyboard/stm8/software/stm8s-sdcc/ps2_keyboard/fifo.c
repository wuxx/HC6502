#include "fifo.h"

void FIFO_Clear(FIFO *Queue)
{
	Queue->Head = Queue->Tail = 0;
}

uint8_t FIFO_WriteAvail(FIFO *Queue)
{
  return(FIFO_INC(Queue->Head,Queue->SizeMask)!=Queue->Tail);
}

uint8_t FIFO_Write(FIFO *Queue, FIFO_Data_t data)
{
	if(FIFO_WriteAvail(Queue))
	{
		Queue->Head = FIFO_INC(Queue->Head,Queue->SizeMask);
		FIFO_BUF(Queue)[Queue->Head] = data;
		return 1;	
	}
	return 0;
}

uint8_t FIFO_ReadAvail(FIFO *Queue)
{
	return(Queue->Head != Queue->Tail);
}

uint8_t FIFO_Read(FIFO *Queue, FIFO_Data_t *data)
{
	if (FIFO_ReadAvail(Queue))
	{
		Queue->Tail = FIFO_INC(Queue->Tail,Queue->SizeMask);	
		*data = FIFO_BUF(Queue)[Queue->Tail];
		return 1;
	}
	return 0;	
}

uint8_t Getc(FIFO *Queue)
{
	uint8_t ch;
	
	while(!FIFO_Read(Queue,&ch))
	  /* busy wait */;
	
	return ch;
}

#if 0
uint8_t Getc_Timeout(FIFO *Queue, FIFO_Data_t *data, uint16_t Timeout)
{
	MicroTimer0=Timeout;
	
	while(!FIFO_Read(Queue,data))
	{
		if((Timeout!= TIME_INFINITE)&& !MicroTimer0)
			return 0;
	}

	return 1;
}

#endif
