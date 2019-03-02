#include <stdlib.h>
#include <string.h>

#include "type.h"
#include "memory_map.h"
#include "uart.h"
#include "gpio.h"

#include "ps2.h"

extern void mdelay(int ms);

enum PS2_IN_STATUS_E
{
    PS_BUSY = 0,
    PS_IDLE = 1,
};

enum PS2_OUT_CTRL_E
{
    PC_READ = 0,
    PC_IDLE = 1,
};

struct ps2_info
{
    u32 ctrl;
    u32 status;
    u32 data[8];
};

struct ps2_info pi = {
    VIA2_PA0,
    VIA2_PA1,
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
