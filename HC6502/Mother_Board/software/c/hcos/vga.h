#ifndef __VGA_H__
#define __VGA_H__

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "type.h"
#include "memory_map.h"
#include "uart.h"
#include "gpio.h"

#define X_MAX   (63)
#define Y_MAX   (20)

enum VGA_CMD_E {
    VC_CLEAR = 0x80,
    VC_FILL,
    VC_SET_X,
    VC_SET_Y,
    VC_SCROLL_UP,
    VC_SCROLL_DOWN,
};

enum VGA_CMD_REQ_STATUS_E {
    VC_REQ_BUSY = 0,
    VC_REQ_READY,
};

enum VGA_CMD_RSP_STATUS_E {
    VC_RSP_BUSY = 0,
    VC_RSP_READY,
};


struct vga_info {
    u32 cmd_status; /* 0: busy; 1: ready */
    u32 rsp_status; /* 0: busy; 1: ready */
    u32 cd[8];  /* CMD & DATA */
};

extern void mdelay(int ms);

s32 vga_ctrl(u32 cmd, ...);
void vga_init();

#endif /* __VGA_H__ */
