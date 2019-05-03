#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "vga.h"


//#define debug uart_printf
#define debug(...)

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

    debug("wait rsp ready1...\r\n");

    while(1) {
        if (gpio_read(vi.rsp_status) == VC_RSP_READY) {
            break;
        }
    }
    debug("ok.\r\n");

    for(i = 0; i < 8; i++) {
        if (data & (1 << i)) {
            gpio_write(vi.cd[i], 1);
        } else {
            gpio_write(vi.cd[i], 0);
        }
    }

    gpio_write(vi.cmd_status, VC_REQ_READY);
    debug("wait rsp ready2...\r\n");

    while(1) {
        if (gpio_read(vi.rsp_status) == VC_RSP_READY) {
            break;
        }
    }

    debug("ok.\r\n");
    gpio_write(vi.cmd_status, VC_REQ_BUSY);

    return data;
}


s32 vga_ctrl(u32 cmd, ...)
{
    u32 pos_x, pos_y;
    u8 ch;
    va_list args;

    debug("enter %s cmd: %d\r\n", __func__, cmd);

    va_start(args, cmd);

    switch (cmd) {
        case (VC_CLEAR):
        case (VC_SCROLL_UP):
        case (VC_SCROLL_DOWN):
            vga_write(cmd);
            break;
        case (VC_FILL):
            ch = va_arg(args, u8);
            debug("fill: (%x)(%c)\r\n", ch, ch);
            vga_write(cmd);
            vga_write(ch);
            break;
        case (VC_SET_CH):
            vga_write(cmd);
            pos_x = va_arg(args, u32);
            pos_y = va_arg(args, u32);
            ch    = va_arg(args, u8);
            debug("pos_x: %d\r\n", pos_x);
            debug("pos_y: %d\r\n", pos_y);
            debug("ch:    %c\r\n", ch);
            vga_write(pos_x);
            vga_write(pos_y);
            vga_write(ch);
            break;
        default:
            break;
    }

    va_end(args);

    debug("exit %s \n", __func__);

    return 0;
}

void vga_putc(char ch)
{
    static u32 x = 0, y = 0;


    if (ch == '\r') {
        x = 0;
        y++;

        if (y == Y_MAX) {
            y = 0;
        }
        return;
    }

    if (ch == '\n') {
        return;
    }


    vga_ctrl(VC_SET_CH, x, y, ch);
    x++;
}

void vga_puts(char *s)
{
    int i;

    for(i = 0; s[i]; i++) {
        vga_putc(s[i]);
    }
}

int vga_printf(const char *format, ...)
{

    u32 len;
    va_list args;
    static char format_buf[128] = {0};

    va_start(args, format);
    len = vsnprintf(format_buf, sizeof(format_buf), format, args);
    va_end(args);

    vga_puts(format_buf);

    return len;

}

void vga_init()
{
    u8 i;

    gpio_init(vi.cmd_status, 1);
    gpio_init(vi.rsp_status, 0);

    for(i = 0; i < 8; i++) {
        gpio_init(vi.cd[i], 1);
    }

    gpio_write(vi.cmd_status, VC_REQ_BUSY);
}

