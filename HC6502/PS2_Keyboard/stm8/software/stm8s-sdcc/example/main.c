#include "stdio.h"
#include "stm8s.h"
#include "stm8s_gpio.h"
#include "stm8s_clk.h"
#include "stm8s_exti.h"

#define LED_PORT GPIOB
#define LED GPIO_PIN_5

#define BTN_PORT GPIOD
#define BTN GPIO_PIN_2

void putchar(char c)
{
    while(c--);
    return;
}

void assert_failed(u8* file, u32 line)
{ 
    /* User can add his own implementation to report the file name and line number,
ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* Infinite loop */
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);
    while (1)
    {
    }
}
static void delay(uint32_t t)
{
    while(t--);
}

uint8_t i, press;


INTERRUPT_HANDLER(IRQ_Handler_EXTI_PORT_D, 6)
{

    delay(10000);
}

#if 0
int uart_puts(const char *s) {
    uint8_t i;
    for(i = 0; s[i]; i++) {
        while(!(UART1_SR & UART_SR_TXE));
        UART1_DR = s[i];
    }

    return(i);
}

void uart_init() {
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
}


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

#endif

int main( void )
{

    //system_clock_init();
    //uart_init();
    //uart_puts("enter main\r\n");

    // ----------- GPIO CONFIG -------------------
    GPIO_DeInit(LED_PORT);
    GPIO_Init(LED_PORT, LED, GPIO_MODE_OUT_PP_LOW_FAST);

    GPIO_DeInit(BTN_PORT);
    GPIO_Init(BTN_PORT, BTN, GPIO_MODE_IN_FL_IT); // Input floating, with interrupt


    // ----------- EXTI CONFIG ---------------------
    EXTI_DeInit();
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_FALL_ONLY);

    // ---------- CLK CONFIG -----------------------
    CLK_DeInit();

    CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
    CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1); // set 16 MHz for CPU

    enableInterrupts();

    i=0; press=0;
    for(;;)
    {
            delay(1000); i++;

        if (i > 50)
        {
            GPIO_WriteReverse(LED_PORT, LED);
            i=0;

        }
    }
}
