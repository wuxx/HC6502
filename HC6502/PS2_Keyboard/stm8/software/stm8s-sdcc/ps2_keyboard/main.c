#include "stdio.h"
#include "stm8s.h"
#include "stm8s_gpio.h"
#include "stm8s_clk.h"
#include "stm8s_exti.h"
#include "stm8s_uart1.h"
#include "fifo.h"

#define LED_PORT GPIOB
#define LED GPIO_PIN_5

#define BTN_PORT GPIOD
#define BTN GPIO_PIN_2

#define PS2_PORT GPIOB

#define PS2_CLK_PIN   GPIO_PIN_5
#define PS2_DATA_PIN  GPIO_PIN_4




volatile uint16_t int_count = 0;
void uart_putc(uint8_t c);

int putchar(int c)
{
	uart_putc((uint8_t)c);
    return 0;
}

void assert_failed(u8* file, u32 line)
{ 
    /* User can add his own implementation to report the file name and line number,
ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* Infinite loop */
    printf("Wrong %s %d\r\n", file, line);
    while (1) {
    }
}

static void delay(uint32_t t)
{
    while(t--);
}

uint16_t frame = 0;
uint16_t bindex = 0;

#define FRAME_BIT_COUNT (11)

#define FRAME_START_BIT  (1 << 0)
#define FRAME_PARITY_BIT (1 << 9)
#define FRAME_STOP_BIT   (1 << 10)

#define PS2_FIFO_SIZE 16
FIFO_DECL(ps2_buf,PS2_FIFO_SIZE);

uint8_t frame_ok(uint16_t frame)
{
    uint8_t count = 0;

    if ((frame & FRAME_START_BIT) == 0 &&
        (frame & FRAME_STOP_BIT)  != 1) {

        /* START and STOP OK, now check the parity */
        while(frame) {
            count++;
            frame &= (frame - 1);
        }

        /* START + DATA + PARITY + STOP must be devide by 2 with no remainder */
        if (count % 2 == 0) {
            return 1;
        }
    }

    return 0;
}

#define MAX_KEYTBL		0x83

#define KEY_MODIFERS	0x80
#define KEY_FN_KEYS		0x90
#define KEY_CURSORS		0xa0
#define KEY_OTHERS		0xb0

#define KEY_TYPE(X)		((X)&0xf0)
#define KEY_FN(X)			((X)+KEY_FN_KEYS)

#define MODIFIER(X)		(1<<((X)&0x07))

// Use same mapping as LED

enum ModifierKeys
{
	KEY_SCROLL 	= KEY_MODIFERS,
	KEY_NUMLOCK,
	KEY_CAP,
  KEY_SHIFT,
  KEY_CTRL,
  KEY_ALT
};

enum CursorKeys
{
  KEY_HOME = KEY_CURSORS,
	KEY_END,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_DOWN,
	KEY_PGDN,
	KEY_PGUP,
	KEY_INS,
	KEY_NUM_5,
	KEY_CURSOR_LAST
};


enum OtherKeys
{ 
	KEY_BACKSPACE = 0x08,
  KEY_TAB	=	0x09,	
	KEY_ENTER = 0x0d,
	KEY_ESC = 0x1b,
	KEY_DEL = 0x7f,
	//-----------------------
	KEY_GUI_LEFT = KEY_OTHERS,
	KEY_GUI_RIGHT,
	KEY_GUI_APPS,
	KEY_ACPI_POWER,
	KEY_ACPI_WAKE,
	KEY_ACPI_SLEEP,
};

const uint8_t kbd_code[]=
{ 
	// Unshifted	Shift
	0, 0,							// 00
	KEY_FN(9),KEY_FN(9),			// 01  F9
	0, 0,							// 02
	KEY_FN(5),KEY_FN(5), 			// 03  F5
	KEY_FN(3),KEY_FN(3), 			// 04  F3
	KEY_FN(1),KEY_FN(1), 			// 05  F1
	KEY_FN(2),KEY_FN(2), 			// 06  F2
	KEY_FN(12),KEY_FN(12),			// 07  F12
	0, 0,							// 08
	KEY_FN(10),KEY_FN(10), 			// 09  F10
	KEY_FN(8),KEY_FN(8), 			// 0A  F8
	KEY_FN(6),KEY_FN(6),			// 0B  F6
	KEY_FN(4),KEY_FN(4), 			// 0C  F4
	KEY_TAB,KEY_TAB, 				// 0D  TAB
	'`','~', 						// 0E  ` or ~
	0, 0,							// 0F
	0, 0,							// 10
	KEY_ALT,KEY_ALT, 				// 11  Left ALT
	KEY_SHIFT,KEY_SHIFT, 			// 12  Left SHIFT
	0, 0,							// 13
	KEY_CTRL,KEY_CTRL,	 			// 14  Left Ctrl
	'q','Q', 						// 15  Q
	'1','!',						// 16  1 or !
	0, 0,							// 17
	0, 0,							// 18
	0, 0,							// 19
	'z','Z',						// 1A  Z
	's','S',						// 1B  S
	'a','A',						// 1C  A
	'w','W',						// 1D  W
	'2','@',						// 1E  2 or @
	KEY_GUI_LEFT,KEY_GUI_LEFT,		// 1F
	0, 0,							// 20
	'c','C',						// 21  C
	'x','X',						// 22  X
	'd','D',						// 23  D
	'e','E',						// 24  E
	'4','$',						// 25  4 or $
	'3','#',						// 26  3 or #
	KEY_GUI_RIGHT,KEY_GUI_RIGHT,	// 27
	0, 0,							// 28
	' ',' ',						// 29  Space
	'v','V',						// 2A  V
	'f','F',						// 2B  F
	't','T',						// 2C  T
	'r','R',						// 2D  R
	'5','%',						// 2E  5 or %
	KEY_GUI_APPS,KEY_GUI_APPS,		// 2F
	0, 0,							// 30
	'n','N',						// 31  N
	'b','B',						// 32  B
	'h','H',						// 33  H
	'g','G',						// 34  G
	'y','Y',						// 35  Y
	'6','^',						// 36  6 or ^
	KEY_ACPI_POWER,KEY_ACPI_POWER,	// 37
	0, 0,							// 38
	0, 0,							// 39
	'm','M',						// 3A  M
	'j','J',						// 3B  J
	'u','U',						// 3C  U
	'7','&',						// 3D  7 or &
	'8','*',						// 3E  8 or *
	KEY_ACPI_SLEEP,KEY_ACPI_SLEEP,	// 3F
	0, 0,							// 40
	',','<',						// 41  , or <
	'k','K',						// 42  K
	'i','I',						// 43  I
	'o','O',						// 44  O
	'0',')',						// 45  0 or )
	'9','(',						// 46  9 or (
	0, 0,							// 47
	0, 0,							// 48
	'.','>',						// 49  . or >
	'/','?',						// 4A  / or ?
	'l','L',						// 4B  L
	';',':',						// 4C  // or :
	'p','P',						// 4D  P
	'-','_',						// 4E  - or _
	0, 0,							// 4F
	0, 0,							// 50
	0, 0,							// 51
	'\'','"',						// 52  ' or "
    0, 0,							// 53
	'[','{',						// 54  [ or {
	'=','+',						// 55  = OR +
	0, 0,							// 56
	0, 0,							// 57
	KEY_CAP,KEY_CAP,		 		// 58  Caps Lock
	KEY_SHIFT,KEY_SHIFT,			// 59  Right Shift
	KEY_ENTER,KEY_ENTER,			// 5A  Enter
	']','}',						// 5B  ] or }
	0, 0,							// 5C	
	'\\','|',						// 5D  \ or |
	KEY_ACPI_WAKE,KEY_ACPI_WAKE,	// 5E
	0, 0,							// 5F
	0, 0,							// 60
	0, 0,							// 61
	0, 0,							// 62
	0, 0,							// 63
	0, 0,							// 64
	0, 0,							// 65
	KEY_BACKSPACE,KEY_BACKSPACE, 	// 66  Backspace
	0, 0,							// 67
	0, 0,							// 68
	KEY_END,'1',					// 69  NUM - 1 or END
	0, 0,							// 6A
	KEY_LEFT,'4',					// 6B  NUM - 4 or LEFT
	KEY_HOME,'7',					// 6C  NUM - 7 or HOME
	0, 0,							// 6D
	0, 0,							// 6E
	0, 0,							// 6F
	KEY_INS,'0',     				// 70  NUM - 0 or INS
	KEY_DEL,'.',     				// 71  NUM - . or DEL
	KEY_DOWN,'2',     				// 72  NUM - 2 or DOWN
	KEY_NUM_5,'5',     				// 73  NUM - 5
	KEY_RIGHT,'6',     				// 74  NUM - 6 or RIGHT
	KEY_UP,'8',     				// 75  NUM - 8 or UP
	KEY_ESC,KEY_ESC,				// 76  ESC
	KEY_NUMLOCK,KEY_NUMLOCK,		// 77  NUM LOCK
	KEY_FN(11), KEY_FN(11),			// 78  F11
	'+', '+',						// 79  NUM - + (Plus)
	KEY_PGDN,'3',     				// 7A  NUM 3 or PAGE DOWN
	'-','-',     					// 7B  NUM - - (Minus)
	'*','*',						// 7C  NUM - *
	KEY_PGUP,'9',     				// 7D  NUM - 9 or PAGE UP
	KEY_SCROLL,KEY_SCROLL,			// 7E  SCROLL LOCK
	0, 0,  							// 7F	
	0, 0,  							// 80
	0, 0,  							// 81
	0, 0,  							// 82
	KEY_FN(7),   					// 83  F7
};


uint8_t skip = 0;

INTERRUPT_HANDLER(IRQ_Handler_EXTI_PORT_B, 4)
{
    uint8_t b;
    uint8_t ch_code;
    uint8_t ch;

    //printf("enter interrupt!\r\n");
    //delay(10000);
    int_count++;

    b = GPIO_ReadInputPin(PS2_PORT, PS2_DATA_PIN);

    if (b) {
        frame |= (1 << bindex);
    }

    bindex++;

    if (bindex == FRAME_BIT_COUNT) {

        /**/
        if (frame_ok(frame)) {

            ch_code = (frame >> 1) & 0xff;

            if (skip) {
                skip = 0;
            } else {

                /* skip break code */
                if (ch_code == 0xF0) {
                    skip = 1;
                } else {
                    //printf("frame: %x\r\n", ch_code);

                    ch = kbd_code[ch_code * 2];
                    printf("fifo write ch: [%x] [%c]\r\n", ch, ch);

                    FIFO_Write((FIFO*)ps2_buf, ch);
                }

            }

        }

        bindex = 0;
        frame = 0;
    }

    //printf("i%d\r\n", int_count);
}

void uart_init() 
{
    UART1_DeInit();
    UART1_Init(115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, \
                UART1_PARITY_NO , UART1_SYNCMODE_CLOCK_DISABLE , UART1_MODE_TXRX_ENABLE);
          
    UART1_Cmd(ENABLE);
}

void uart_putc(uint8_t c)
{
	UART1_SendData8(c);
	while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
}


enum PS2_BRIDGE_OUT_STATUS_E
{
    BS_BUSY = 0,
    BS_IDLE = 1,
};

enum PS2_BRIDGE_IN_CTRL_E
{
    BC_READ = 0,
    BC_IDLE = 1,
};

struct gpio_info {
    GPIO_TypeDef*    port;
    GPIO_Pin_TypeDef pin;
};

struct ps2_bridge_signal_info
{
    struct gpio_info ctrl;
    struct gpio_info status;
    struct gpio_info data[8];
    struct gpio_info reserved;
};

struct ps2_bridge_signal_info pbsi = {
    {GPIOD, GPIO_PIN_4},
    {GPIOA, GPIO_PIN_1},

    {
        {GPIOA, GPIO_PIN_3},
        {GPIOD, GPIO_PIN_2},
        {GPIOC, GPIO_PIN_6},
        {GPIOC, GPIO_PIN_4},
        {GPIOA, GPIO_PIN_2},
        {GPIOD, GPIO_PIN_3},
        {GPIOC, GPIO_PIN_7},
        {GPIOC, GPIO_PIN_5},
    },

    {GPIOC, GPIO_PIN_3},
};

uint8_t ps2_get_ctrl()
{

    uint8_t b;

    b = GPIO_ReadInputPin(pbsi.ctrl.port, pbsi.ctrl.pin);

    if (b) {
        return 1;
    } else {
        return 0;
    }

}

void ps2_set_data(uint8_t data)
{
    uint8_t i;

    for(i = 0; i < 8; i++) {
        if (data & (1 << i)) {
            GPIO_WriteHigh(pbsi.data[i].port, pbsi.data[i].pin);
        } else {
            GPIO_WriteLow(pbsi.data[i].port, pbsi.data[i].pin);
        }

    }
}

void ps2_set_status(uint8_t status)
{
    if (status) {
        GPIO_WriteHigh(pbsi.status.port, pbsi.status.pin);
    } else {
        GPIO_WriteLow(pbsi.status.port, pbsi.status.pin);
    }
}

void ps2_bridge_init()
{
    uint8_t i;

    GPIO_Init(pbsi.ctrl.port, pbsi.ctrl.pin, GPIO_MODE_IN_PU_NO_IT);

    GPIO_Init(pbsi.status.port, pbsi.status.pin, GPIO_MODE_OUT_PP_HIGH_FAST);

    for(i = 0; i < 8; i++) {
        GPIO_Init(pbsi.data[i].port, pbsi.data[i].pin, GPIO_MODE_OUT_PP_LOW_FAST);
    }

    ps2_set_status(BS_IDLE);
    ps2_set_data(0xff);

}

void ps2_bridge_process()
{
    uint8_t ch;

    if (ps2_get_ctrl() == BC_READ) {

        printf("get read request \r\n");

        ps2_set_status(BS_BUSY);
        if (FIFO_ReadAvail((FIFO*)ps2_buf)) {
            disableInterrupts();

            ch = Getc((FIFO*)ps2_buf);
            enableInterrupts();

            printf("ps2 bridge get [%c] [%x]\r\n", ch, ch);

            ps2_set_data(ch);

        } else {
            printf("ps2 bridge get default 0xff\r\n");
            ps2_set_data(0xff);
        }
    }

    ps2_set_status(BS_IDLE);

    while(1) {
        if(ps2_get_ctrl() == BC_IDLE) {
            ps2_set_data(0xff);
            break;
        }
        printf("wait ctrl idle\r\n");
    }

}


char sys_banner[] = {"ps2 bridge system buildtime [" __TIME__ " " __DATE__ "] "};

int main( void )
{
    uint8_t i;
    uint8_t ch;

    uart_init();
    printf("\r\nenter main %s \r\n", sys_banner);


    // ----------- GPIO CONFIG -------------------
    GPIO_DeInit(PS2_PORT);
    GPIO_Init(PS2_PORT, PS2_CLK_PIN,  GPIO_MODE_IN_FL_IT); // Input floating, with interrupt
    GPIO_Init(PS2_PORT, PS2_DATA_PIN, GPIO_MODE_IN_FL_NO_IT);


    // ----------- EXTI CONFIG ---------------------
    EXTI_DeInit();
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOB, EXTI_SENSITIVITY_FALL_ONLY);


    // ---------- CLK CONFIG -----------------------
#if 0
    CLK_DeInit();

    printf("%s %d\r\n", __func__, __LINE__);

    CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
    CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1); // set 16 MHz for CPU
#endif

    printf("%s %d\r\n", __func__, __LINE__);

    ps2_bridge_init();

    enableInterrupts();

    printf("en int\r\n");

    i = 0;
    for(;;)
    {
        ps2_bridge_process();

#if 0
        if(FIFO_ReadAvail((FIFO*)ps2_buf)) {
            disableInterrupts();
            ch = Getc((FIFO*)ps2_buf);
            enableInterrupts();
            printf("get [%c] [%x]\r\n", ch, ch);
        }
#endif

#if 0
        printf("\r\n");
        for(i = 0; i < sizeof(bit); i++) {
            if ((i != 0) && ((i % 16) == 0)) {
                printf("\r\n");
            }

            printf("%d ", bit[i]);
        }

        printf("\r\n");
#endif

#if 0
        delay(1000); i++;

        if (i > 50)
        {
            GPIO_WriteReverse(LED_PORT, LED);
            i=0;

        }
#endif
    }
}
