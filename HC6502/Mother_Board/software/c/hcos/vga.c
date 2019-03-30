#include "vga.h"

struct vga_info vi = {
    VIA1_PB2,
    VIA1_PB3,
    {
        VIA2_PA0,
        VIA2_PA1,
        VIA2_PA2,
        VIA2_PA3,
        VIA2_PA4,
        VIA2_PA5,
        VIA2_PA6,
        VIA2_PA7,
    },
};

u8 vga_write(u8 data)
{
    u8 i;

    gpio_write(vi.cmd_status, VC_REQ_BUSY);

    mdelay(100);

    uart_printf("wait rsp ready...\n");

    while(1) {
        if (gpio_read(vi.rsp_status) == VC_RSP_READY) {
            break;
        }
    }
    uart_printf("ok.\n");

    for(i = 0; i < 8; i++) {
        if (data & (1 << i)) {
            gpio_write(vi.cd[i], 1);
        } else {
            gpio_write(vi.cd[i], 0);
        }
    }

    gpio_write(vi.cmd_status, VC_REQ_READY);
    uart_printf("wait rsp ready...\n");

    while(1) {
        if (gpio_read(vi.rsp_status) == VC_RSP_READY) {
            break;
        }
    }

    uart_printf("ok");
    gpio_write(vi.cmd_status, VC_REQ_BUSY);

    return data;
}


s32 vga_ctrl(u32 cmd, ...)
{
    u8 pos;
    va_list args;

    uart_printf("enter %s \n", __func__);

    va_start(args, cmd);

    switch (cmd) {
        case (VC_CLEAR):
        case (VC_FILL):
        case (VC_SCROLL_UP):
        case (VC_SCROLL_DOWN):
            vga_write(cmd);
            break;
        case (VC_SET_X):
        case (VC_SET_Y):
            vga_write(cmd);
            pos = va_arg(args, u8);
            uart_printf("pos: %d\n", pos);
            vga_write(pos);
            break;
        default:
            break;
    }

    va_end(args);

    uart_printf("exit %s \n", __func__);

    return 0;
}

void vga_init()
{
    u8 i;

    gpio_init(vi.cmd_status, 1);
    gpio_init(vi.rsp_status, 0);

    for(i = 0; i < 8; i++) {
        gpio_init(vi.cd[i], 0);
    }

    gpio_write(vi.cmd_status, VC_REQ_BUSY);
}

