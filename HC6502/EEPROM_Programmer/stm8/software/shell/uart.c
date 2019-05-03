/**
 * EEPROM_Programmer V1.0
 * author: wuxx
 *
 **/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "stm8s.h"
#include "uart.h"


#define __delay() {\
    uint32_t i;\
    for(i = 0; i < 4000000; i++) \
        __asm nop __endasm;\
}

char sys_banner[];

void udelay(unsigned int us)
{
    for(; us > 0; us--) 
    { 
        __asm nop __endasm;
        __asm nop __endasm;
        __asm nop __endasm;
        __asm nop __endasm;
    }
}

void mdelay(unsigned int ms)
{
    int i, x;
    for(i = 0; i < ms; i++) {
        for(x = 0; x < 100; x++);
    }
}

/*
 * All unused pins are output in push-pull configuration,
 * low, interrupts disabled, speed slow (<= 2MHz)
 */
inline void port_init() 
{
    PA_ODR = 0x00;
    PA_DDR = 0xFF;
    PA_CR1 = 0xFF;
    PA_CR2 = 0x00;

    PB_ODR = 0x00;
    PB_DDR = 0xFF;
    PB_CR1 = 0xFF;
    PB_CR2 = 0x00;

    PC_ODR = 0x00;
    PC_DDR = 0xFF;
    PC_CR1 = 0xFF;
    PC_CR2 = 0x00;

    PD_ODR = 0x00;
    PD_DDR = 0xFF;
    PD_CR1 = 0xFF;
    PD_CR2 = 0x00;
}

/**
 * Reconfigure System clock, use high speed internal oscillator,
 * disable prescaler.
 */
void system_clock_init()
{
    nointerrupts();
    CLK_ICKR = 0;
    CLK_ICKR |= CLK_ICKR_HSIEN;
    CLK_ECKR = 0;
    CLK_SWR = CLK_SWR_HSI;
    while (0 == (CLK_ICKR & CLK_ICKR_HSIRDY));
    CLK_CKDIVR = 0;
    CLK_PCKENR1 = 0xFF;
    CLK_PCKENR2 = 0xFF;
    CLK_CCOR = 0;
    CLK_HSITRIMR = 0;
    CLK_SWIMCCR = 0;

    CLK_SWCR = 0;
    CLK_SWCR |= CLK_SWCR_SWEN;
    while (0 != (CLK_SWCR & CLK_SWCR_SWBSY));
    interrupts();
}

int putchar(int c)
{
    while(!(UART1_SR & UART_SR_TXE));

    UART1_DR = c;

    return(c);
}


uint8_t uart_get() 
{
    while(!(UART1_SR & UART_SR_RXNE)); /* wait the input un-empty */
    return UART1_DR;
}

void uart_putc(const char c) 
{
    while(!(UART1_SR & UART_SR_TXE)); /* wait we can output */
    UART1_DR = c;

}

/**
 * Write string to uart.
 * @param
 *
 * @return bytes written.
 */
int uart_puts(const char *s) 
{
    uint8_t i;
    for(i = 0; i < strlen(s); i++) {
        while(!(UART1_SR & UART_SR_TXE));
        UART1_DR = s[i];
    }

    return(i);
}

/**
 * Initialize UART with fixed settings: 115200 8N1
 */
void uart_init() 
{
    /* Configure RX and TX pins */
    PD_DDR = 0xBF;
    PD_CR1 = 0xFF;

    /* Enable TX & RX */
    UART1_CR2 = UART_CR2_TEN | UART_CR2_REN;
    /* 1 stop bit */
    UART1_CR3 &= ~(UART_CR3_STOP1 | UART_CR3_STOP0);

    /* 115200 baud, 16MHz, Error:0.08%   */
    UART1_BRR2 = 0x0B;
    UART1_BRR1 = 0x08;

    /* 9600 baud, 16MHz, Error:0.02%   */
    //UART1_BRR2 = 0x03;
    //UART1_BRR1 = 0x68;
}

/********************************* SHELL START *********************************/
#define readl(addr)         (*( ( volatile uint32_t * )(addr)) )
#define writel(addr, data)  (*( ( volatile uint32_t * )(addr)) = data)

#define SHELL_ARGS_MAX  (6)

typedef int32_t (*func_0)();
typedef int32_t (*func_4)(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4);

struct shell_cmd_info {
    char *name;
    func_0 func;
    char *desc;
};

volatile char * volatile shell_cmd = NULL;

uint8_t argc;
char *argv[SHELL_ARGS_MAX] = {NULL};
uint8_t debug = 0;

static int32_t cmd_read(void);
static int32_t cmd_write(void);
static int32_t cmd_exec(void);
static int32_t cmd_dumpw(void);
static int32_t cmd_dumpb(void);
static int32_t cmd_gpio(void);
static int32_t cmd_at28(void);
static int32_t cmd_help(void);

struct shell_cmd_info ci[] = {
    {"r",       cmd_read,    ""/*"r     [addr]                          read    any addr"*/},
    {"w",       cmd_write,   ""/*"w     [addr] [data]                   write   any addr"*/},
#if 0
    {"x",       cmd_exec,    ""/*"x     [addr]                          execute any addr"*/},
#endif
    {"dumpw",   cmd_dumpw,   ""/*"dumpw [addr] [word_num]               dump    any addr"*/},
    {"dumpb",   cmd_dumpb,   ""/*"dumpb [addr] [byte_num]               dump    any addr"*/},
    {"gpio",    cmd_gpio,    ""/*"gpio  init|read|write [PA0...]        ctrl any gpio"*/ },
    {"at28",    cmd_at28,    ""/*"at28  read|write|dump [addr] [data|byte_num] at28c256 operation"*/},
    {"debug",   cmd_debug,   ""},
    {"help",    cmd_help,    ""/*"help                                  print cmd info"*/  },
};

static int32_t cmd_debug()
{
    debug = 1;
    return 0;
}

static int32_t cmd_read()
{
	uint32_t addr;
	uint32_t data;

	addr = strtoul(argv[1], NULL, 0);
	printf("[0x%x]: ", addr);
	data = readl(addr);
	printf("0x%x\n", data);
	return 0;
}

static int32_t cmd_write()
{
	uint16_t i;
	uint16_t addr;
	uint16_t word_num;
	uint32_t data;

	if (argc <= 2) {
		return -1;
	}

	word_num = argc - 2;

	word_num = word_num <= 16 ? word_num : 16;
	addr = strtoul(argv[1], NULL, 0);

	for(i = 0; i < word_num; i++) {
		data = strtoul(argv[2 + i], NULL, 0);

		writel(addr + i * 4, data);
		printf("[0x%x] <- (0x%lx)\r\n", addr + i * 4, data);
	}

	return 0;
}

static int32_t cmd_exec()
{
#if 0
	int32_t ret;
	uint32_t addr, para1, para2, para3, para4;
	func_4 func;

	addr  = strtoul(argv[1], NULL, 0);

	para1 = strtoul(argv[2], NULL, 0);
	para2 = strtoul(argv[3], NULL, 0);
	para3 = strtoul(argv[4], NULL, 0);
	para4 = strtoul(argv[5], NULL, 0);

	func = (func_4)(addr | 0x1); /* thumb-2 instruction */

	ret = func(para1, para2, para3, para4);
	printf("exec 0x%x (0x%x 0x%x 0x%x 0x%x) return 0x%x\r\n", addr, para1, para2, para3, para4, ret);
	return ret;
#endif
    return 0;
}

static int32_t cmd_dumpw()
{
	uint32_t i;
	uint32_t *p;
	uint32_t addr, word_nr;

	addr    = strtoul(argv[1], NULL, 0);
	word_nr = strtoul(argv[2], NULL, 0);
	p       = (uint32_t*)addr;

	printf("[0x%08lx]: ", &p[0]);
	for(i = 0; i < word_nr;) {
		printf("0x%08lx ", p[i++]);
		if ((i > 0) && (i % 4 == 0)) {
			printf("\r\n[0x%08lx]: ", &p[i]);
		}
	}

	printf("\r\n");

	return 0;
}

uint8_t cook(uint8_t c)
{
	/* please check the ascii code table */
	if (c >= 0x20 && c <= 0x7E) {
		return c;
	} else {
		return '.';
	}
}

static int32_t cmd_dumpb()
{
	uint32_t i, x;
	uint8_t *p;
	uint8_t buf[16];
	uint32_t addr, byte_nr;
	uint32_t count, left;

	addr    = strtoul(argv[1], NULL, 0);
	byte_nr = strtoul(argv[2], NULL, 0);
	p       = (uint8_t*)addr;

	count = byte_nr / 16;
	left  = byte_nr % 16;

	printf("[0x%08x]: ", &p[0]);
	for(i = 0; i < count; i++) {
		for(x = 0; x < 16; x++) {
			buf[x] = p[i * 16 + x];
			printf("%02x ", buf[x]);
		}
		printf("  ");
		for(x = 0; x < 16; x++) {
			printf("%c", cook(buf[x]));
		}

		printf("\r\n[0x%08x]: ", &p[(i + 1) * 16]);
	}

	if (left != 0) {
		for(x = 0; x < 16; x++) {
			if (x < left) {
				buf[x] = p[i * 16 + x];
				printf("%02x ", buf[x]);
			} else {
				buf[x] = ' ';
				printf("   ");
			}
		}
		printf("  ");
		for(x = 0; x < 16; x++) {
			printf("%c", cook(buf[x]));
		}

	}

	printf("\r\n");

	return 0;
}

struct gpio_info {
    char name[4];
    uint8_t index;
    uint16_t base_addr;
};

struct gpio_reg {
    uint8_t odr;
    uint8_t idr;
    uint8_t ddr;
    uint8_t cr1;
    uint8_t cr2;
};

struct gpio_info gi[] =
{
#if 0
    {"PA0", 0x0, 0x5000},
#endif

    {"PA1", 0x1, 0x5000},
    {"PA2", 0x2, 0x5000},
    {"PA3", 0x3, 0x5000},
#if 0
    {"PA4", 0x4, 0x5000},
    {"PA5", 0x5, 0x5000},
    {"PA6", 0x6, 0x5000},
    {"PA7", 0x7, 0x5000},

    {"PB0", 0x0, 0x5005},
    {"PB1", 0x1, 0x5005},
    {"PB2", 0x2, 0x5005},
    {"PB3", 0x3, 0x5005},
#endif
    {"PB4", 0x4, 0x5005},
    {"PB5", 0x5, 0x5005},
#if 0
    {"PB6", 0x6, 0x5005},
    {"PB7", 0x7, 0x5005},

    {"PC0", 0x0, 0x500A},
    {"PC1", 0x1, 0x500A},
    {"PC2", 0x2, 0x500A},
#endif
    {"PC3", 0x3, 0x500A},
    {"PC4", 0x4, 0x500A},
    {"PC5", 0x5, 0x500A},
    {"PC6", 0x6, 0x500A},
    {"PC7", 0x7, 0x500A},

#if 0
    {"PD0", 0x0, 0x500F},
#endif

    {"PD1", 0x1, 0x500F},
    {"PD2", 0x2, 0x500F},
    {"PD3", 0x3, 0x500F},
    {"PD4", 0x4, 0x500F},
    {"PD5", 0x5, 0x500F},
    {"PD6", 0x6, 0x500F},
#if 0
    {"PD7", 0x7, 0x500F},
#endif

};

struct gpio_info * gi_get(char *name)
{
        int i;

        if (name == NULL) {
                return NULL;
        }

        for(i = 0; i < sizeof(gi) / sizeof(gi[0]); i++) {
                if (strcmp(gi[i].name, name) == 0) {
                        return &gi[i];
                }
        }

        return NULL;

}

int8_t gpio_init(uint32_t base_addr, uint8_t index, uint8_t mode) /* 0: input; 1: output; */
{
    struct gpio_reg *pgr;

    pgr = (struct gpio_reg *)base_addr;

    switch (mode) {
        case (0): /* input */
            pgr->ddr &= (~(0x1 << index));
            break;
        case (1): /* output */
            pgr->ddr |= (0x1 << index);
            break;
        default: /* output */
            pgr->ddr |= (0x1 << index);
            break;
    }

    return 0;
}


uint8_t gpio_read(uint32_t base_addr, uint8_t index)
{
    struct gpio_reg *pgr;

    pgr = (struct gpio_reg *)base_addr;

    return ((pgr->idr >> index)) & 0x1;
}

int8_t gpio_write(uint32_t base_addr, uint8_t index, uint8_t b)
{
    struct gpio_reg *pgr;
    pgr = (struct gpio_reg *)base_addr;


    pgr->cr1 |= (0x1 << index); /* push-pull mode */

    if (b) {
        /* output 1 */
        pgr->odr |= (0x1 << index);
    } else {
        pgr->odr &= (~(0x1 << index));
    }

    return 0;
}

static int32_t cmd_gpio()
{
	struct gpio_info *pgi;
    struct gpio_reg *pgr;
	uint8_t b;

	pgi = gi_get(argv[2]);
	if (pgi == NULL) {
		printf("unknown gpio num [%s]\r\n", argv[2]);
		return -1;
	}

    pgr = (struct gpio_reg *)(pgi->base_addr);

	if (strcmp(argv[1], "init") == 0) {
		if (argv[3] == NULL) {
			printf("gpio init [gpio_num] [in|out]\r\n");
			return -1;
		}
		if (strcmp(argv[3], "in") == 0) {
			gpio_init(pgi->base_addr, pgi->index, 0);
		} else if (strcmp(argv[3], "out") == 0) {
			gpio_init(pgi->base_addr, pgi->index, 1);
		} else {
			printf("unknown mode [%s]\r\n", argv[3]);
			return -1;
		}

	} else if (strcmp(argv[1], "read") == 0) {
		b = gpio_read(pgi->base_addr, pgi->index);
		printf("gpio read return %d\r\n", b);
	} else if (strcmp(argv[1], "write") == 0) {

        gpio_init(pgi->base_addr, pgi->index, 1); /* output */

		if (strcmp(argv[3], "0") == 0) {
			gpio_write(pgi->base_addr, pgi->index, 0);
		} else {
			gpio_write(pgi->base_addr, pgi->index, 1);
		}
	}

	printf("\n");

	return 0;
}

#define AT28C256_BASE   (0x0)
#define AT28C256_SIZE   (0x8000)

uint8_t at28_read(uint16_t addr);
void at28_write(uint16_t addr, uint8_t data);
void at28_dump(uint16_t addr, uint16_t byte_num);
uint16_t at28_cksum(uint16_t addr, uint16_t byte_num);

static int32_t cmd_at28()
{
    static uint8_t prog_count = 0;
    uint8_t data = 0;
    uint16_t addr;
    uint16_t i, len = 0;
    uint16_t byte_num;
    uint16_t cksum, sum_trans = 0, sum_prog = 0;
    char *s = NULL;
    char hex[5];
    hex[0] = '0';
    hex[1] = 'x';
    hex[4] = '\0';

	addr = strtoul(argv[2], NULL, 0);

    if (addr >= AT28C256_SIZE) {
        printf("invalid addr [0x%x]\r\n", addr);
        return 1;
    }

	if (strcmp(argv[1], "read") == 0) {
        printf("0x%x: [0x%x]\r\n", addr, at28_read(addr));
	} else if (strcmp(argv[1], "write") == 0) {
        data = strtoul(argv[3], NULL, 0);
        at28_write(addr, data);
	} else if (strcmp(argv[1], "dump") == 0) {
        byte_num = strtoul(argv[3], NULL, 0);
        at28_dump(addr, byte_num);
	} else if (strcmp(argv[1], "prog") == 0) { 
        /* program format: at28 prog addr(2byte) len(2byte) data(x byte) checksum(2byte) */
        addr  = strtoul(argv[2], NULL, 0);
        len   = strtoul(argv[3], NULL, 0);
        cksum = strtoul(argv[5], NULL, 0);
        
        if ((prog_count % 2) == 0) {
            addr = addr | (1 << 15); /* the led is connect on the A15 */
        }

        s = argv[4];
        for(i = 0; s[i] != NULL; i = i + 2) {
            hex[2] = s[i];
            hex[3] = s[i + 1];

            data = strtoul(hex, NULL, 0);
            at28_write(addr + (i / 2), data);
            sum_trans += data;
            if (debug) {
                printf("write %x %x\r\n", addr + (i / 2), data);
            }
        }

        sum_prog = at28_cksum(addr, len);

        if ((cksum == sum_trans) && (cksum == sum_prog)) {
            printf("prog succ!\r\n");
        } else {
            printf("cksum fail! (%x %x %x)\r\n", cksum, sum_trans, sum_prog);
        }

        prog_count++;
	} else if (strcmp(argv[1], "test") == 0) {
        data = strtoul(argv[2], NULL, 0);
        printf("writing...\r\n");
        for(addr = 0; addr < (AT28C256_SIZE); addr++) {
            //printf("0x%x\r\n", addr);
            at28_write(addr, addr % (10 + data));
            if ((addr % 256) == 0) {
                printf(".");
            }
        }

        printf("\r\nreading...\r\n");
        for(addr = 0; addr < (AT28C256_SIZE); addr++) {
            printf("%x:[%x]\r\n", addr, at28_read(addr));
        }

    }

	return 0;
}

static int32_t cmd_help()
{
	uint32_t i;
    /* sys_banner is at last place of ram, 
       print here to test if the stack overflow.
       (stack at addr 1k grow to low addr.) */
    printf("\r\n%s\r\n", sys_banner); 
	for(i = 0; i<(sizeof(ci)/sizeof(ci[0])); i++) {
		printf("%s:\t\t%s\r\n", ci[i].name, ci[i].desc);
	}
	return 0;
}

static int32_t parse_cmd(char *cmd)
{
	uint32_t i, x;

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

static int32_t get_cmd_index(char *cmd)
{
    uint32_t i;
    for(i=0; i<(sizeof(ci)/sizeof(ci[0])); i++) {
        if (strcmp(ci[i].name, cmd) == 0) {
            return i;
        }
    }
    return -1;
}

int32_t shell(char *cmd)
{
    int32_t i;
    uint32_t len;
    int32_t ret = 0;

    len = strlen(cmd);

    if (len == 0) {
        ret = 0;
        goto exit;
    }

    printf("\r\n");
    parse_cmd(cmd);

#if 0
    for(i = 0; i < len; i++) {
        printf("[0x%x]: %x [%c]\n", &cmd[i], cmd[i], cmd[i]);
    }
    for(i = 0; i < SHELL_ARGS_MAX; i++) {
        printf("argv[%d]: 0x%x [%s]\n", i, argv[i], argv[i]);
    }
                printf("[%s]\n", cmd);
#endif

    if ((i = get_cmd_index(argv[0])) == -1) {
        printf("illegal cmd [%s] \r\n", argv[0]);
        ret = -1;
        goto exit;
    }

    ret = ci[i].func();
    printf("return 0x%x\r\n", ret);

exit:
    printf("\r\npos#");
    return ret;
}

/********************************* SHELL END   *********************************/
#define POS_REV "v1.0"
char sys_banner[] = {"EEPROM programmer system buildtime [" __TIME__ " " __DATE__ "] " "rev " POS_REV};

#define UART_IO_SIZE    (550)

short urb_index;
char uart_recv_buf[UART_IO_SIZE];

void uart_handler()
{
	uint8_t ch;

	ch = uart_get();   

	if (ch == '\n') {   /* sscom will send '\r\n' we ignore the '\n' */
		return;
	}

	if (urb_index == (UART_IO_SIZE - 1) && ch != '\r') {
		uart_puts("cmd too long!\n");
		urb_index = 0;
		return;
	}

	if (ch == '\r') {
		uart_recv_buf[urb_index] = '\0';  /* terminate the string. */
		shell(uart_recv_buf);
		urb_index = 0;
		return;
	} else {
		uart_recv_buf[urb_index] = ch;
		urb_index++;
	}

	/* echo */
	uart_putc(ch);

}

/* 74HC595 */

struct gpio_info *pgi_hc595_rclk;
struct gpio_info *pgi_hc595_clk;
struct gpio_info *pgi_hc595_ser;

void hc595_set_rclk(uint8_t b)
{
    gpio_write(pgi_hc595_rclk->base_addr, pgi_hc595_rclk->index, b);
}

void hc595_set_clk(uint8_t b)
{
    gpio_write(pgi_hc595_clk->base_addr, pgi_hc595_clk->index, b);
}

void hc595_set_ser(uint8_t b)
{
    gpio_write(pgi_hc595_ser->base_addr, pgi_hc595_ser->index, b);
}

int8_t hc595_init()
{
    pgi_hc595_rclk = gi_get("PA1");
    pgi_hc595_clk  = gi_get("PA2");
    pgi_hc595_ser  = gi_get("PA3");

    if (pgi_hc595_rclk == NULL || 
        pgi_hc595_clk == NULL || pgi_hc595_ser == NULL) {
        printf("%s fail! (%x %x %x)\n", __func__, 
                pgi_hc595_rclk, pgi_hc595_clk, pgi_hc595_ser);
        return 1;
    }

    gpio_init(pgi_hc595_rclk->base_addr, pgi_hc595_rclk->index, 1);
    gpio_init(pgi_hc595_clk->base_addr, pgi_hc595_clk->index, 1);
    gpio_init(pgi_hc595_ser->base_addr, pgi_hc595_ser->index, 1);

    hc595_set_rclk(0);
    hc595_set_clk(0);
    hc595_set_ser(0);

    return 0;
}

struct gpio_info *pgi_at28_ce;
struct gpio_info *pgi_at28_oe;
struct gpio_info *pgi_at28_we;

struct gpio_info *pgi_at28_io[8];

void at28_set_ce(uint8_t b)
{
    gpio_write(pgi_at28_ce->base_addr, pgi_at28_ce->index, b);
}

void at28_set_oe(uint8_t b)
{
    gpio_write(pgi_at28_oe->base_addr, pgi_at28_oe->index, b);
}

void at28_set_we(uint8_t b)
{
    gpio_write(pgi_at28_we->base_addr, pgi_at28_we->index, b);
}

int8_t at28_init()
{
    uint8_t i;
    uint8_t data0, data1;

    pgi_at28_ce = gi_get("PD4");
    pgi_at28_oe = gi_get("PB5");
    pgi_at28_we = gi_get("PB4");
    
    pgi_at28_io[0] = gi_get("PD3");
    pgi_at28_io[1] = gi_get("PD2");
    pgi_at28_io[2] = gi_get("PD1");
    pgi_at28_io[3] = gi_get("PC7");
    pgi_at28_io[4] = gi_get("PC6");
    pgi_at28_io[5] = gi_get("PC5");
    pgi_at28_io[6] = gi_get("PC4");
    pgi_at28_io[7] = gi_get("PC3");

    if (pgi_at28_ce == NULL || pgi_at28_oe == NULL || pgi_at28_we == NULL) {
        printf("%s oe we fail!\r\n", __func__);
        return 1;
    }

    for(i = 0; i < 8; i++) {
        if (pgi_at28_io[i] == NULL) {
            printf("%s io fail!\n", __func__);
            return 1;
        } else {
            gpio_init(pgi_at28_io[i]->base_addr, pgi_at28_io[i]->index, 0);
        }
    }

    gpio_init(pgi_at28_ce->base_addr, pgi_at28_ce->index, 1);
    gpio_init(pgi_at28_oe->base_addr, pgi_at28_oe->index, 1);
    gpio_init(pgi_at28_we->base_addr, pgi_at28_we->index, 1);

    at28_set_ce(0);
    at28_set_oe(0);
    at28_set_we(1);

    data0 = at28_read(0);
    data1 = ~data0;
    at28_write(0, data1);
    data0 = at28_read(0);
    if (data0 == data1) {
        printf("at28 probe ok!\r\n");
        data0 = ~data1;
        at28_write(0, data0);
    } else {
        printf("at28 probe fail!\r\n");
    }

    return 0;
}

/* AT28C256 */
void at28_set_addr(uint16_t addr)
{
    uint8_t b;
    int8_t i;

    hc595_set_rclk(0);

    for(i = 15; i >= 0; i--) {
        if (addr & (0x1 << i)) {
            b = 1;
        } else {
            b = 0;
        }

        //printf("%d\n", b);

        hc595_set_clk(0);
        hc595_set_ser(b);
        mdelay(3);
        hc595_set_clk(1);
        mdelay(3);
    }

    mdelay(2);
    hc595_set_rclk(1);

}

uint8_t at28_read(uint16_t addr)
{
    int8_t i;
    uint8_t data = 0;

    at28_set_ce(0);
    at28_set_oe(0);
    mdelay(1);

    at28_set_addr(addr);
    mdelay(1);

    for(i = 7; i >= 0; i--) {
        data = data << 1;
        data |= gpio_read(pgi_at28_io[i]->base_addr, pgi_at28_io[i]->index);
    }

    at28_set_ce(1);
    at28_set_oe(1);

    return data;
}

void at28_write(uint16_t addr, uint8_t data)
{
    uint8_t i;

    at28_set_addr(addr);

    for(i = 0; i < 8; i++) {

        gpio_init(pgi_at28_io[i]->base_addr, pgi_at28_io[i]->index, 1); /* output */

        if (data & (0x1 << i)) {
            gpio_write(pgi_at28_io[i]->base_addr, pgi_at28_io[i]->index, 1);
        } else {
            gpio_write(pgi_at28_io[i]->base_addr, pgi_at28_io[i]->index, 0);
        }
    }

    mdelay(1);

    at28_set_oe(1); /* output high-Z */
    at28_set_ce(0);
    at28_set_we(0);

    /* write */
    mdelay(4);

    at28_set_ce(0);
    at28_set_we(1);

    /* write finish. */

    /* restore to default (read state) */
    for(i = 0; i < 8; i++) {
        gpio_init(pgi_at28_io[i]->base_addr, pgi_at28_io[i]->index, 0);
    }
}

void at28_dump(uint16_t addr, uint16_t byte_num)
{
    uint16_t i;
    uint8_t data;
    uint16_t cksum = 0;

	printf("[0x%04x]: ", addr);

    for(i = 0; i < byte_num; i++) {

		if ((i > 0) && (i % 8 == 0)) {
			printf("\r\n[0x%04x]: ", addr + i);
		}

        data = at28_read(addr + i);
		printf("0x%02x ", data);

        cksum += data;

	}

    printf("\r\ncksum: 0x%04x\n", cksum);

}

uint16_t at28_cksum(uint16_t addr, uint16_t byte_num)
{
    uint16_t i;
    uint8_t data;
    uint16_t cksum = 0;


    for(i = 0; i < byte_num; i++) {
        data = at28_read(addr + i);
        cksum += data;
	}

    return cksum;

}

struct gpio_info *pgi_test_gpio;

int main() {

    port_init();
    system_clock_init();

    uart_init();

    hc595_init();
    at28_init();

    printf("\r\n%s\r\n", sys_banner);

#if 0
    pgi_test_gpio = gi_get("PA3");
    gpio_init(pgi_test_gpio->base_addr, pgi_test_gpio->index, 1);

    while(1) {
        gpio_write(pgi_test_gpio->base_addr, pgi_test_gpio->index, 1);
        mdelay(10);
        gpio_write(pgi_test_gpio->base_addr, pgi_test_gpio->index, 0);
        mdelay(10);
    }
#endif

    printf("pos#");
    while(1) {
        uart_handler();
    }
}
