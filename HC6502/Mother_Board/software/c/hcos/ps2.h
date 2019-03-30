#ifndef __PS2_H__
#define __PS2_H__

#include <stdlib.h>
#include <string.h>

#include "type.h"
#include "memory_map.h"
#include "uart.h"
#include "gpio.h"

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

void ps2_process();
void ps2_init();

#endif /* __PS2_H__ */
