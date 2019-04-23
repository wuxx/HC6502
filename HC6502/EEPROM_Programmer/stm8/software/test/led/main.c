#include "stm8s.h"

#if  0
#define __nop() __asm nop __endasm

void delay()
{
    unsigned int a, b;

    for(a=1000; a > 0; a--) {
        for(b=200; b>=0; b--) {
            __nop();
        }
    }
}

#endif

void mdelay(unsigned int ms)
{
    int i, x;
    for(i = 0; i < ms; i++) {
        for(x = 0; x < 100; x++);
    }
}

void main()
{
	int i, j;

	PB_DDR |= 0x20;
	PB_CR1 |= 0x20;
	PB_CR2 |= 0x00;

	while (1) {
		PB_ODR ^= 0x00;

        mdelay(1000);

		PB_ODR ^= 0xf0;

        mdelay(1000);
#if 0
		PB_ODR ^= 0x00;

		for(i = 0; i < 100; i++)
			for(j = 0; j < 200; j++);

		PB_ODR ^= 0xf0;

		for(i = 0; i < 100; i++)
			for(j = 0; j < 200; j++);
#endif
	}

#if 0
	PD_DDR = 0x02; /* D1 mode OUTPUT */
	PD_CR1 = 0x02; /* OUTPUT push-pull mode */

	while (1) {

		PD_ODR ^= 0x02; /* OUTPUT value */
		delay();
	}
#endif

}
