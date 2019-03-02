#ifndef __GPIO_H__
#define __GPIO_H__
#include "type.h"
#include "memory_map.h"

struct via_struct
{
	u8 base;
	u8 orb;
	u8 irb;
	u8 ora;
	u8 ira;
	u8 ddrb;
	u8 ddra;
	u8 t1c_l;
	u8 t1c_h;
	u8 t1l_l;
	u8 t1l_h;
	u8 t2c_l;
	u8 t2c_h;
	u8 sr;
	u8 acr;
	u8 pcr;
	u8 ifr;
	u8 ier;
	u8 ora_nh;
	u8 ira_nh;
};

#if 0
enum GPIO_E
{
    VIA1_PA0 = (VIA1_BASE << 16 | 0xA0),
    VIA1_PA1 = (VIA1_BASE << 16 | 0xA1),
    VIA1_PA2 = (VIA1_BASE << 16 | 0xA2),
    VIA1_PA3 = (VIA1_BASE << 16 | 0xA3),
    VIA1_PA4 = (VIA1_BASE << 16 | 0xA4),
    VIA1_PA5 = (VIA1_BASE << 16 | 0xA5),
    VIA1_PA6 = (VIA1_BASE << 16 | 0xA6),
    VIA1_PA7 = (VIA1_BASE << 16 | 0xA7),

    VIA1_PB0 = (VIA1_BASE << 16 | 0xB0),
    VIA1_PB1 = (VIA1_BASE << 16 | 0xB1),
    VIA1_PB2 = (VIA1_BASE << 16 | 0xB2),
    VIA1_PB3 = (VIA1_BASE << 16 | 0xB3),
    VIA1_PB4 = (VIA1_BASE << 16 | 0xB4),
    VIA1_PB5 = (VIA1_BASE << 16 | 0xB5),
    VIA1_PB6 = (VIA1_BASE << 16 | 0xB6),
    VIA1_PB7 = (VIA1_BASE << 16 | 0xB7),

    VIA2_PA0 = (VIA2_BASE << 16 | 0xA0),
    VIA2_PA1 = (VIA2_BASE << 16 | 0xA1),
    VIA2_PA2 = (VIA2_BASE << 16 | 0xA2),
    VIA2_PA3 = (VIA2_BASE << 16 | 0xA3),
    VIA2_PA4 = (VIA2_BASE << 16 | 0xA4),
    VIA2_PA5 = (VIA2_BASE << 16 | 0xA5),
    VIA2_PA6 = (VIA2_BASE << 16 | 0xA6),
    VIA2_PA7 = (VIA2_BASE << 16 | 0xA7),

    VIA2_PB0 = (VIA2_BASE << 16 | 0xB0),
    VIA2_PB1 = (VIA2_BASE << 16 | 0xB1),
    VIA2_PB2 = (VIA2_BASE << 16 | 0xB2),
    VIA2_PB3 = (VIA2_BASE << 16 | 0xB3),
    VIA2_PB4 = (VIA2_BASE << 16 | 0xB4),
    VIA2_PB5 = (VIA2_BASE << 16 | 0xB5),
    VIA2_PB6 = (VIA2_BASE << 16 | 0xB6),
    VIA2_PB7 = (VIA2_BASE << 16 | 0xB7),
};
#endif

#define VIA1_PA0  (((VIA1_BASE << 16) | 0xA0))
#define VIA1_PA1  (((VIA1_BASE << 16) | 0xA1))
#define VIA1_PA2  (((VIA1_BASE << 16) | 0xA2))
#define VIA1_PA3  (((VIA1_BASE << 16) | 0xA3))
#define VIA1_PA4  (((VIA1_BASE << 16) | 0xA4))
#define VIA1_PA5  (((VIA1_BASE << 16) | 0xA5))
#define VIA1_PA6  (((VIA1_BASE << 16) | 0xA6))
#define VIA1_PA7  (((VIA1_BASE << 16) | 0xA7))

#define VIA1_PB0  (((VIA1_BASE << 16) | 0xB0))
#define VIA1_PB1  (((VIA1_BASE << 16) | 0xB1))
#define VIA1_PB2  (((VIA1_BASE << 16) | 0xB2))
#define VIA1_PB3  (((VIA1_BASE << 16) | 0xB3))
#define VIA1_PB4  (((VIA1_BASE << 16) | 0xB4))
#define VIA1_PB5  (((VIA1_BASE << 16) | 0xB5))
#define VIA1_PB6  (((VIA1_BASE << 16) | 0xB6))
#define VIA1_PB7  (((VIA1_BASE << 16) | 0xB7))

#define VIA2_PA0  (((VIA2_BASE << 16) | 0xA0))
#define VIA2_PA1  (((VIA2_BASE << 16) | 0xA1))
#define VIA2_PA2  (((VIA2_BASE << 16) | 0xA2))
#define VIA2_PA3  (((VIA2_BASE << 16) | 0xA3))
#define VIA2_PA4  (((VIA2_BASE << 16) | 0xA4))
#define VIA2_PA5  (((VIA2_BASE << 16) | 0xA5))
#define VIA2_PA6  (((VIA2_BASE << 16) | 0xA6))
#define VIA2_PA7  (((VIA2_BASE << 16) | 0xA7))

#define VIA2_PB0  (((VIA2_BASE << 16) | 0xB0))
#define VIA2_PB1  (((VIA2_BASE << 16) | 0xB1))
#define VIA2_PB2  (((VIA2_BASE << 16) | 0xB2))
#define VIA2_PB3  (((VIA2_BASE << 16) | 0xB3))
#define VIA2_PB4  (((VIA2_BASE << 16) | 0xB4))
#define VIA2_PB5  (((VIA2_BASE << 16) | 0xB5))
#define VIA2_PB6  (((VIA2_BASE << 16) | 0xB6))
#define VIA2_PB7  (((VIA2_BASE << 16) | 0xB7))

s8 gpio_init(u32 gpio, u8 mode);
void gpio_write(u32 gpio, u8 b);
u8 gpio_read(u32 gpio);

#endif /* __GPIO_H__ */
