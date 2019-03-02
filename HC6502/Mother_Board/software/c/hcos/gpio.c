#include "memory_map.h"
#include "type.h"
#include "gpio.h"

s8 gpio_init(u32 gpio, u8 mode)
{
    u16 base, group;
    u8 index;
    u16 orirx, ddrx;

    u8 data;

    base  = (u16)(gpio >> 16);
    group = (u16)(gpio & 0xFFFF);
    index = (u8)(group & 0xF);

    if ((group & 0x00F0) == 0x00A0) { /* GPIO_A */
        orirx = base + 1;
        ddrx  = base + 3;
    } else { /* GPIO_B */
        orirx = base + 0;
        ddrx  = base + 2;
    }

    if (mode == 0) { /* input */
        data = readb(ddrx);
        data &= ~(1 << index);
        writeb(ddrx, data);

    } else { /* output */
        data = readb(ddrx);
        data |= 1 << index;
        writeb(ddrx, data);

        /* init 0 */
        data = readb(orirx);
        data &= ~(1 << index);
        writeb(orirx, data);

    }

    return 0;
}

void gpio_write(u32 gpio, u8 b)
{
    u16 base, group;
    u8 index;
    u16 orirx, ddrx;

    u8 data;

    base  = (u16)(gpio >> 16);
    group = (u16)(gpio & 0xFFFF);
    index = (u8)(group & 0xF);

    if ((group & 0x00F0) == 0x00A0) { /* GPIO_A */
        orirx = base + 1;
        ddrx  = base + 3;
    } else { /* GPIO_B */
        orirx = base + 0;
        ddrx  = base + 2;
    }

    if (b) {
        data = readb(orirx);
        data |= 1 << index;
        writeb(orirx, data);
    } else {
        data = readb(orirx);
        data &= ~(1 << index);
        writeb(orirx, data);
    }

}

u8 gpio_read(u32 gpio)
{
    u16 base, group;
    u8 index;
    u16 orirx, ddrx;

    u8 data;

    base  = (u16)(gpio >> 16);
    group = (u16)(gpio & 0xFFFF);
    index = (u8)(group & 0xF);

    if ((group & 0x00F0) == 0x00A0) { /* GPIO_A */
        orirx = base + 1;
        ddrx  = base + 3;
    } else { /* GPIO_B */
        orirx = base + 0;
        ddrx  = base + 2;
    }

    data = readb(orirx);
    if (data & (1 << index)) {
        return 1;
    } else {
        return 0;
    }

}
