#include <stdlib.h>
#include <string.h>
#include "utils.h"

#include "type.h"
#include "memory_map.h"
#include "uart.h"
#include "gpio.h"
#include "ps2.h"
#include "vga.h"


#define SHELL_ARGS_MAX  (6)

typedef s32 (*func_0)();
typedef s32 (*func_4)(u16 arg1, u16 arg2, u16 arg3, u16 arg4);

struct shell_cmd_info {
    char *name;
    func_0 func;
    char *desc;
};

volatile char * volatile shell_cmd = 0;

u8 argc;
char *argv[SHELL_ARGS_MAX] = {0};

static s32 cmd_read(void);
static s32 cmd_write(void);
static s32 cmd_exec(void);
static s32 cmd_dumpw(void);
static s32 cmd_dumpb(void);
static s32 cmd_gpio(void);
static s32 cmd_ps2(void);
static s32 cmd_vga(void);
static s32 cmd_uptime(void);
static s32 cmd_help(void);

struct shell_cmd_info ci[] = {
    {"r",       cmd_read,    "r     [addr]                          read    any addr"},
    {"w",       cmd_write,   "w     [addr] [data]                   write   any addr"},
    {"x",       cmd_exec,    "x     [addr]                          execute any addr"},
    {"dumpw",   cmd_dumpw,   "dumpw [addr] [word_num]               dump    any addr"},
    {"dumpb",   cmd_dumpb,   "dumpb [addr] [byte_num]               dump    any addr"},
    {"gpio",    cmd_gpio,    "gpio  init|read|write [VIA1_PA0...]   ctrl any gpio"   },
    {"ps2",     cmd_ps2,     "ps2                                   read ps2 input"  },
    {"vga",     cmd_vga,     "vga   cmd args...                     vga ctrl"        },
    {"uptime",  cmd_uptime,  "uptime                                print current time"},
    {"help",    cmd_help,    "help                                  print cmd info"  },
};

static s32 cmd_read()
{
	u16 addr;
	u8 data;

	addr = strtoul(argv[1], 0, 0);
	uart_printf("[0x%x]: ", addr);
	data = readb(addr);
	uart_printf("0x%x\r\n", data);
	return 0;
}

static s32 cmd_write()
{
	u16 i;
	u16 addr;
	u16 byte_num;
	u8 data;

	if (argc <= 2) {
		return -1;
	}

	byte_num = argc - 2;

	byte_num = byte_num <= 16 ? byte_num : 16;
	addr = strtoul(argv[1], 0, 0);

	for(i = 0; i < byte_num; i++) {
		data = strtoul(argv[2 + i], 0, 0);

		writeb(addr + i, data);
		uart_printf("[0x%x] <- (0x%x)\r\n", addr + i, data);
	}

	return 0;
}

static s32 cmd_exec()
{

	s32 ret;
	u16 addr, para1, para2, para3, para4;
	func_4 func;

	addr  = strtoul(argv[1], 0, 0);

	para1 = strtoul(argv[2], 0, 0);
	para2 = strtoul(argv[3], 0, 0);
	para3 = strtoul(argv[4], 0, 0);
	para4 = strtoul(argv[5], 0, 0);

	func = (func_4)(addr);

	ret = func(para1, para2, para3, para4);
	uart_printf("exec 0x%x (0x%x 0x%x 0x%x 0x%x) return 0x%x\r\n", addr, para1, para2, para3, para4, ret);
	return ret;

    return 0;
}

static s32 cmd_dumpw()
{
	u32 i;
	u16 *p;
	u16 addr, word_nr; /* 1 word = 2 byte */

	addr    = strtoul(argv[1], 0, 0);
	word_nr = strtoul(argv[2], 0, 0);
	p       = (u16*)addr;

	uart_printf("[0x%04x]: ", &p[0]);
	for(i = 0; i < word_nr;) {
		uart_printf("0x%04x ", p[i++]);
		if ((i > 0) && (i % 4 == 0)) {
			uart_printf("\r\n[0x%04x]: ", &p[i]);
		}
	}

	uart_printf("\r\n");

	return 0;
}

u8 cook(u8 c)
{
	/* please check the ascii code table */
	if (c >= 0x20 && c <= 0x7E) {
		return c;
	} else {
		return '.';
	}
}

static s32 cmd_dumpb()
{
	u32 i, x;
	u8 *p;
	u8 buf[16];
	u16 addr, byte_nr;
	u16 count, left;

	addr    = strtoul(argv[1], 0, 0);
	byte_nr = strtoul(argv[2], 0, 0);
	p       = (u8*)addr;

	count = byte_nr / 16;
	left  = byte_nr % 16;

	uart_printf("[0x%04x]: ", &p[0]);
	for(i = 0; i < count; i++) {
		for(x = 0; x < 16; x++) {
			buf[x] = p[i * 16 + x];
			uart_printf("%02x ", buf[x]);
		}
		uart_printf("  ");
		for(x = 0; x < 16; x++) {
			uart_printf("%c", cook(buf[x]));
		}

		uart_printf("\r\n[0x%04x]: ", &p[(i + 1) * 16]);
	}

	if (left != 0) {
		for(x = 0; x < 16; x++) {
			if (x < left) {
				buf[x] = p[i * 16 + x];
				uart_printf("%02x ", buf[x]);
			} else {
				buf[x] = ' ';
				uart_printf("   ");
			}
		}
		uart_printf("  ");
		for(x = 0; x < 16; x++) {
			uart_printf("%c", cook(buf[x]));
		}

	}

	uart_printf("\r\n");

	return 0;
}

struct gpio_info {
    char name[16];
    u32 gpio;
};

struct gpio_info gi[] =
{
    {"VIA1_PA0", VIA1_PA0},
    {"VIA1_PA1", VIA1_PA1},
    {"VIA1_PA2", VIA1_PA2},
    {"VIA1_PA3", VIA1_PA3},
    {"VIA1_PA4", VIA1_PA4},
    {"VIA1_PA5", VIA1_PA5},
    {"VIA1_PA6", VIA1_PA6},
    {"VIA1_PA7", VIA1_PA7},

    {"VIA1_PB0", VIA1_PB0},
    {"VIA1_PB1", VIA1_PB1},
    {"VIA1_PB2", VIA1_PB2},
    {"VIA1_PB3", VIA1_PB3},
    {"VIA1_PB4", VIA1_PB4},
    {"VIA1_PB5", VIA1_PB5},
    {"VIA1_PB6", VIA1_PB6},
    {"VIA1_PB7", VIA1_PB7},

    {"VIA2_PA0", VIA2_PA0},
    {"VIA2_PA1", VIA2_PA1},
    {"VIA2_PA2", VIA2_PA2},
    {"VIA2_PA3", VIA2_PA3},
    {"VIA2_PA4", VIA2_PA4},
    {"VIA2_PA5", VIA2_PA5},
    {"VIA2_PA6", VIA2_PA6},
    {"VIA2_PA7", VIA2_PA7},

    {"VIA2_PB0", VIA2_PB0},
    {"VIA2_PB1", VIA2_PB1},
    {"VIA2_PB2", VIA2_PB2},
    {"VIA2_PB3", VIA2_PB3},
    {"VIA2_PB4", VIA2_PB4},
    {"VIA2_PB5", VIA2_PB5},
    {"VIA2_PB6", VIA2_PB6},
    {"VIA2_PB7", VIA2_PB7},
};

struct gpio_info * gi_get(char *name)
{
        int i;

        if (name == 0) {
                return 0;
        }

        for(i = 0; i < sizeof(gi) / sizeof(gi[0]); i++) {
                if (strcmp(gi[i].name, name) == 0) {
                        return &gi[i];
                }
        }

        return 0;

}

static s32 cmd_gpio()
{
	struct gpio_info *pgi;
	u8 b;

	pgi = gi_get(argv[2]);
	if (pgi == 0) {
		uart_printf("unknown gpio num [%s]\r\n", argv[2]);
		return -1;
	}

	if (strcmp(argv[1], "init") == 0) {
		if (argv[3] == 0) {
			uart_printf("gpio init [gpio_num] [in|out]\r\n");
			return -1;
		}
		if (strcmp(argv[3], "in") == 0) {
			gpio_init(pgi->gpio, 0);
		} else if (strcmp(argv[3], "out") == 0) {
			gpio_init(pgi->gpio, 1);
		} else {
			uart_printf("unknown mode [%s]\r\n", argv[3]);
			return -1;
		}

	} else if (strcmp(argv[1], "read") == 0) {
		b = gpio_read(pgi->gpio);
		uart_printf("gpio read return %d\r\n", b);
	} else if (strcmp(argv[1], "write") == 0) {

        gpio_init(pgi->gpio, 1); /* output */

		if (strcmp(argv[3], "0") == 0) {
			gpio_write(pgi->gpio, 0);
		} else {
			gpio_write(pgi->gpio, 1);
		}
	}

	uart_printf("\r\n");

	return 0;
}

static s32 cmd_ps2()
{
    ps2_process();
    return 0;
}

static s32 cmd_vga()
{
    u32 x, y;
    u8 ch;

	if (strcmp(argv[1], "clear") == 0) {
		uart_printf("vga clear start\r\n");
        vga_ctrl(VC_CLEAR);
		uart_printf("vga clear end  \r\n");
    } else if (strcmp(argv[1], "fill") == 0) {
        ch = strtoul(argv[2], 0, 0);
        vga_ctrl(VC_FILL, ch);
    } else if (strcmp(argv[1], "set") == 0) {
        x  = strtoul(argv[2], 0, 0);
        y  = strtoul(argv[3], 0, 0);
        ch = strtoul(argv[4], 0, 0);
        vga_ctrl(VC_SET_CH, x, y, ch);
    } else if (strcmp(argv[1], "shell") == 0) {
        x = 0;
        y = 0;
        while(1) {
            ch = ps2_getc();

            if (ch == '\r') {
                x = 0;
                y++;

                if (y == Y_MAX) {
                    y = 0;
                }

                continue;
            }


            vga_ctrl(VC_SET_CH, x, y, ch);
            x++;

            if (x == X_MAX) {
                x = 0;
                y++;
            }

            if (y == Y_MAX) {
                y = 0;
            }

        }

        vga_ctrl(VC_SET_CH, x, y, ch);
    } else if (strcmp(argv[1], "printf") == 0) {
        uart_printf("vga_printf [%s]\r\n", argv[2]);
        vga_printf("%s\n", argv[2]);
    }

    return 0;
}

static s32 cmd_uptime()
{
    uart_printf("%d:%d:%d\r\n", hours, minutes, seconds);
    return 0;
}

static s32 cmd_help()
{
	u32 i;

	for(i = 0; i<(sizeof(ci)/sizeof(ci[0])); i++) {
		uart_printf("%s:\t\t%s\r\n", ci[i].name, ci[i].desc);
	}

	return 0;
}

static s32 parse_cmd(char *cmd)
{
	u32 i, x;

	memset(argv, 0, SHELL_ARGS_MAX*sizeof(argv[0]));

	/* first, set the argv */
	x = 0;
	for(i = 0; cmd[i] != '\0';) {

		while(cmd[i] == ' ') {
			i++;
		}

		argv[x++] = &cmd[i];

		if (x == SHELL_ARGS_MAX) {
			break;  /* not gonna to process the left args */
		}

		/* walk though this arg */
		while(cmd[i] != ' ' && cmd[i] != '\0') {
			i++;
		}

	}

	argc = x;

	/* replace all ' ' to '\0' */
	for(i = 0; cmd[i] != '\0'; i++) {
		if (cmd[i] == ' ') {
			cmd[i] = '\0';
		}
	}
	return 0;
}

static s32 get_cmd_index(char *cmd)
{
    u32 i;
    for(i=0; i<(sizeof(ci)/sizeof(ci[0])); i++) {
        if (strcmp(ci[i].name, cmd) == 0) {
            return i;
        }
    }
    return -1;
}

s32 uart_shell(char *cmd)
{
    s32 i;
    u32 len;
    s32 ret = 0;

    len = strlen(cmd);

    if (len == 0) {
        ret = 0;
        goto exit;
    }

    uart_printf("\r\n");
    parse_cmd(cmd);

#if 0
    for(i = 0; i < len; i++) {
        uart_printf("[0x%x]: %x [%c]\n", &cmd[i], cmd[i], cmd[i]);
    }
    for(i = 0; i < SHELL_ARGS_MAX; i++) {
        uart_printf("argv[%d]: 0x%x [%s]\n", i, argv[i], argv[i]);
    }
                uart_printf("[%s]\n", cmd);
#endif

    if ((i = get_cmd_index(argv[0])) == -1) {
        uart_printf("illegal cmd [%s] \r\n", argv[0]);
        ret = -1;
        goto exit;
    }

    ret = ci[i].func();
    uart_printf("return 0x%x", ret);

exit:
    uart_printf("\r\nhcos#");
    return ret;
}
