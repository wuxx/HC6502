#ifndef __GPIO_H__
#define __GPIO_H__

#include "stm32f10x.h"

enum GPIO_GROUP
{
        GROUPA = 0xA,
        GROUPB = 0xB,
        GROUPC = 0xC,
        GROUPD = 0xD,
        GROUPE = 0xE,
        GROUPF = 0xF,
        GROUPG = 0xF + 1,
};

int32_t gpio_write(uint32_t group, uint32_t index, uint32_t bit);
int32_t gpio_read(uint32_t group, uint32_t index);
int32_t gpio_init(uint32_t group, uint32_t index, uint32_t mode);

#endif /* __GPIO_H__ */
