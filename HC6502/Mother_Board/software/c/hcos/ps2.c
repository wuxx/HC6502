#include "ps2.h"

struct ps2_info pi = {
    VIA1_PB0,
    VIA1_PB1,
    {
        VIA2_PB0,
        VIA2_PB1,
        VIA2_PB2,
        VIA2_PB3,
        VIA2_PB4,
        VIA2_PB5,
        VIA2_PB6,
        VIA2_PB7,
    },

};

u8 ps2_read()
{
    u8 i;
    u8 data = 0;

    gpio_write(pi.ctrl, PC_READ);

    mdelay(100);

    while(1) {
        if (gpio_read(pi.status) == PC_IDLE) {
            break;
        }
    }

    for(i = 0; i < 8; i++) {
        data |= (gpio_read(pi.data[i]) << i);
    }

    gpio_write(pi.ctrl, PC_IDLE);

    return data;
    
}

void ps2_process()
{
    u8 ch;

    while (1) {
        ch = ps2_read();

        if (ch == 0xff) {
            uart_printf("get 0xff\r\n");
        } else {
            uart_printf("get [%c] [%x]\r\n", ch, ch);
        }
    }

}

void ps2_init()
{
    u8 i;

    gpio_init(pi.ctrl, 1);
    gpio_init(pi.status, 0);

    for(i = 0; i < 8; i++) {
        gpio_init(pi.data[i], 0);
    }

    gpio_write(pi.ctrl, PC_IDLE);
}
