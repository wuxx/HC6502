#ifndef __STM8S_H
#define __STM8S_H

#include <stdint.h>

/**
 * TODO complete register bitmasks
 */

/* GPIO */
#define PA_ODR *(volatile uint8_t*)0x5000
#define PA_IDR *(volatile uint8_t*)0x5001
#define PA_DDR *(volatile uint8_t*)0x5002
#define PA_CR1 *(volatile uint8_t*)0x5003
#define PA_CR2 *(volatile uint8_t*)0x5004

#define PB_ODR *(volatile uint8_t*)0x5005
#define PB_IDR *(volatile uint8_t*)0x5006
#define PB_DDR *(volatile uint8_t*)0x5007
#define PB_CR1 *(volatile uint8_t*)0x5008
#define PB_CR2 *(volatile uint8_t*)0x5009

#define PC_ODR *(volatile uint8_t*)0x500A
#define PC_IDR *(volatile uint8_t*)0x500B
#define PC_DDR *(volatile uint8_t*)0x500C
#define PC_CR1 *(volatile uint8_t*)0x500D
#define PC_CR2 *(volatile uint8_t*)0x500E

#define PD_ODR *(volatile uint8_t*)0x500F
#define PD_IDR *(volatile uint8_t*)0x5010
#define PD_DDR *(volatile uint8_t*)0x5011
#define PD_CR1 *(volatile uint8_t*)0x5012
#define PD_CR2 *(volatile uint8_t*)0x5013

#define PE_ODR *(volatile uint8_t*)0x5014
#define PE_IDR *(volatile uint8_t*)0x5015
#define PE_DDR *(volatile uint8_t*)0x5016
#define PE_CR1 *(volatile uint8_t*)0x5017
#define PE_CR2 *(volatile uint8_t*)0x5018

#define PF_ODR *(volatile uint8_t*)0x5019
#define PF_IDR *(volatile uint8_t*)0x501A
#define PF_DDR *(volatile uint8_t*)0x501B
#define PF_CR1 *(volatile uint8_t*)0x501C
#define PF_CR2 *(volatile uint8_t*)0x501D

/* Flash */
#define FLASH_CR1 *(volatile uint8_t*)0x505A
#define FLASH_CR2 *(volatile uint8_t*)0x505B
#define FLASH_NCR2 *(volatile uint8_t*)0x505C
#define FLASH_FPR *(volatile uint8_t*)0x505D
#define FLASH_NFPR *(volatile uint8_t*)0x505E
#define FLASH_IAPRS *(volatile uint8_t*)0x505F
#define FLASH_PUKR *(volatile uint8_t*)0x5062
#define FLASH_DUKR *(volatile uint8_t*)0x5064

/* Interrupt control */
#define EXTI_CR1 *(volatile uint8_t*)0x50A0
#define EXTI_CR2 *(volatile uint8_t*)0x50A1

/* Reset Status */
#define RST_SR *(volatile uint8_t*)0x50B3

/* Clock Registers */
#define CLK_ICKR *(volatile uint8_t*)0x50C0
#define CLK_ECKR *(volatile uint8_t*)0x50C1
#define CLK_CMSR *(volatile uint8_t*)0x50C3
#define CLK_SWR *(volatile uint8_t*)0x50C4
#define CLK_SWCR *(volatile uint8_t*)0x50C5
#define CLK_CKDIVR *(volatile uint8_t*)0x50C6
#define CLK_PCKENR1 *(volatile uint8_t*)0x50C7
#define CLK_CSSR *(volatile uint8_t*)0x50C8
#define CLK_CCOR *(volatile uint8_t*)0x50C9
#define CLK_PCKENR2 *(volatile uint8_t*)0x50CA
#define CLK_HSITRIMR *(volatile uint8_t*)0x50CC
#define CLK_SWIMCCR *(volatile uint8_t*)0x50CD

/* Clock bitmasks */
#define CLK_ICKR_REGAH (1 << 5)
#define CLK_ICKR_LSIRDY (1 << 4)
#define CLK_ICKR_LSIEN (1 << 3)
#define CLK_ICKR_FHW (1 << 2)
#define CLK_ICKR_HSIRDY (1 << 1)
#define CLK_ICKR_HSIEN (1 << 0)

#define CLK_ECKR_HSERDY (1 << 1)
#define CLK_ECKR_HSEEN (1 << 0)

#define CLK_SWR_HSI 0xE1
#define CLK_SWR_LSI 0xD2
#define CLK_SWR_HSE 0xB4

#define CLK_SWCR_SWIF (1 << 3)
#define CLK_SWCR_SWIEN (1 << 2)
#define CLK_SWCR_SWEN (1 << 1)
#define CLK_SWCR_SWBSY (1 << 0)

#define CLK_CKDIVR_HSIDIV1 (1 << 4)
#define CLK_CKDIVR_HSIDIV0 (1 << 3)
#define CLK_CKDIVR_CPUDIV2 (1 << 2)
#define CLK_CKDIVR_CPUDIV1 (1 << 1)
#define CLK_CKDIVR_CPUDIV0 (1 << 0)

/* Watchdog */
#define WWDG_CR *(volatile uint8_t*)0x50D1
#define WWDG_WR *(volatile uint8_t*)0x50D2
#define IWDG_KR *(volatile uint8_t*)0x50E0
#define IWDG_PR *(volatile uint8_t*)0x50E1
#define IWDG_RLR *(volatile uint8_t*)0x50E2
#define AWU_CSR1 *(volatile uint8_t*)0x50F0
#define AWU_APR *(volatile uint8_t*)0x50F1
#define AWU_TBR *(volatile uint8_t*)0x50F2

/* Beep */
#define BEEP_CSR *(volatile uint8_t*)0x50F3

/* SPI */
#define SPI_CR1 *(volatile uint8_t*)0x5200
#define SPI_CR2 *(volatile uint8_t*)0x5201
#define SPI_ICR *(volatile uint8_t*)0x5202
#define SPI_SR *(volatile uint8_t*)0x5203
#define SPI_DR *(volatile uint8_t*)0x5204
#define SPI_CRCPR *(volatile uint8_t*)0x5205
#define SPI_RXCRCR *(volatile uint8_t*)0x5206
#define SPI_TXCRCR *(volatile uint8_t*)0x5207

/* I2C */
#define I2C_CR1 *(volatile uint8_t*)0x5210
#define I2C_CR2 *(volatile uint8_t*)0x5211
#define I2C_FREQR *(volatile uint8_t*)0x5212
#define I2C_OARL *(volatile uint8_t*)0x5213
#define I2C_OARH *(volatile uint8_t*)0x5214
#define I2C_DR *(volatile uint8_t*)0x5216
#define I2C_SR1 *(volatile uint8_t*)0x5217
#define I2C_SR2 *(volatile uint8_t*)0x5218
#define I2C_SR3 *(volatile uint8_t*)0x5219
#define I2C_ITR *(volatile uint8_t*)0x521A
#define I2C_CCRL *(volatile uint8_t*)0x521B
#define I2C_CCRH *(volatile uint8_t*)0x521C
#define I2C_TRISER *(volatile uint8_t*)0x521D
#define I2C_PECR *(volatile uint8_t*)0x521E

#define I2C_CR1_NOSTRETCH (1 << 7)
#define I2C_CR1_ENGC (1 << 6)
#define I2C_CR1_PE (1 << 0)

#define I2C_CR2_SWRST (1 << 7)
#define I2C_CR2_POS (1 << 3)
#define I2C_CR2_ACK (1 << 2)
#define I2C_CR2_STOP (1 << 1)
#define I2C_CR2_START (1 << 0)

#define I2C_OARL_ADD0 (1 << 0)

#define I2C_OAR_ADDR_7BIT ((I2C_OARL & 0xFE) >> 1)
#define I2C_OAR_ADDR_10BIT (((I2C_OARH & 0x06) << 9) | (I2C_OARL & 0xFF))

#define I2C_OARH_ADDMODE (1 << 7)
#define I2C_OARH_ADDCONF (1 << 6)
#define I2C_OARH_ADD9 (1 << 2)
#define I2C_OARH_ADD8 (1 << 1)

#define I2C_SR1_TXE (1 << 7)
#define I2C_SR1_RXNE (1 << 6)
#define I2C_SR1_STOPF (1 << 4)
#define I2C_SR1_ADD10 (1 << 3)
#define I2C_SR1_BTF (1 << 2)
#define I2C_SR1_ADDR (1 << 1)
#define I2C_SR1_SB (1 << 0)

#define I2C_SR2_WUFH (1 << 5)
#define I2C_SR2_OVR (1 << 3)
#define I2C_SR2_AF (1 << 2)
#define I2C_SR2_ARLO (1 << 1)
#define I2C_SR2_BERR (1 << 0)

#define I2C_SR3_DUALF (1 << 7)
#define I2C_SR3_GENCALL (1 << 4)
#define I2C_SR3_TRA (1 << 2)
#define I2C_SR3_BUSY (1 << 1)
#define I2C_SR3_MSL (1 << 0)

#define I2C_ITR_ITBUFEN (1 << 2)
#define I2C_ITR_ITEVTEN (1 << 1)
#define I2C_ITR_ITERREN (1 << 0)

/* Precalculated values, all in KHz */
#define I2C_CCRH_16MHZ_FAST_400 0x80
#define I2C_CCRL_16MHZ_FAST_400 0x0D
/*
 * Fast I2C mode max rise time = 300ns
 * I2C_FREQR = 16 (MHz) => tMASTER = 1/16 = 62.5 ns
 * TRISER = (300/62.5) + 1 = floor(4.8) + 1 = 5.
 */
#define I2C_TRISER_16MHZ_FAST_400 0x05;

#define I2C_CCRH_16MHZ_FAST_320 0xC0
#define I2C_CCRL_16MHZ_FAST_320 0x02
#define I2C_TRISER_16MHZ_FAST_320 0x05;

#define I2C_CCRH_16MHZ_FAST_200 0x80
#define I2C_CCRL_16MHZ_FAST_200 0x1A
#define I2C_TRISER_16MHZ_FAST_200 0x05;

#define I2C_CCRH_16MHZ_STD_100 0x00
#define I2C_CCRL_16MHZ_STD_100 0x50
/*
 * Standard I2C mode max rise time = 1000ns
 * I2C_FREQR = 16 (MHz) => tMASTER = 1/16 = 62.5 ns
 * TRISER = (1000/62.5) + 1 = floor(16) + 1 = 17.
 */
#define I2C_TRISER_16MHZ_STD_100 0x11;

#define I2C_CCRH_16MHZ_STD_50 0x00
#define I2C_CCRL_16MHZ_STD_50 0xA0
#define I2C_TRISER_16MHZ_STD_50 0x11;

#define I2C_CCRH_16MHZ_STD_20 0x01
#define I2C_CCRL_16MHZ_STD_20 0x90
#define I2C_TRISER_16MHZ_STD_20 0x11;

#define I2C_READ 1
#define I2C_WRITE 0

/* UART */
#define UART1_SR *(volatile uint8_t*)0x5230
#define UART1_DR *(volatile uint8_t*)0x5231
#define UART1_BRR1 *(volatile uint8_t*)0x5232
#define UART1_BRR2 *(volatile uint8_t*)0x5233
#define UART1_CR1 *(volatile uint8_t*)0x5234
#define UART1_CR2 *(volatile uint8_t*)0x5235
#define UART1_CR3 *(volatile uint8_t*)0x5236
#define UART1_CR4 *(volatile uint8_t*)0x5237
#define UART1_CR5 *(volatile uint8_t*)0x5238
#define UART1_GTR *(volatile uint8_t*)0x5239
#define UART1_PSCR *(volatile uint8_t*)0x523A

/* UART Status Register bits */
#define UART_SR_TXE (1 << 7)
#define UART_SR_TC (1 << 6)
#define UART_SR_RXNE (1 << 5)
#define UART_SR_IDLE (1 << 4)
#define UART_SR_OR (1 << 3)
#define UART_SR_NF (1 << 2)
#define UART_SR_FE (1 << 1)
#define UART_SR_PE (1 << 0)

/* Uart Control Register bits */
#define UART_CR1_R8 (1 << 7)
#define UART_CR1_T8 (1 << 6)
#define UART_CR1_UARTD (1 << 5)
#define UART_CR1_M (1 << 4)
#define UART_CR1_WAKE (1 << 3)
#define UART_CR1_PCEN (1 << 2)
#define UART_CR1_PS (1 << 1)
#define UART_CR1_PIEN (1 << 0)

#define UART_CR2_TIEN (1 << 7)
#define UART_CR2_TCIEN (1 << 6)
#define UART_CR2_RIEN (1 << 5)
#define UART_CR2_ILIEN (1 << 4)
#define UART_CR2_TEN (1 << 3)
#define UART_CR2_REN (1 << 2)
#define UART_CR2_RWU (1 << 1)
#define UART_CR2_SBK (1 << 0)

#define UART_CR3_LINEN (1 << 6)
#define UART_CR3_STOP1 (1 << 5)
#define UART_CR3_STOP0 (1 << 4)
#define UART_CR3_CLKEN (1 << 3)
#define UART_CR3_CPOL (1 << 2)
#define UART_CR3_CPHA (1 << 1)
#define UART_CR3_LBCL (1 << 0)

#define UART_CR4_LBDIEN (1 << 6)
#define UART_CR4_LBDL (1 << 5)
#define UART_CR4_LBDF (1 << 4)
#define UART_CR4_ADD3 (1 << 3)
#define UART_CR4_ADD2 (1 << 2)
#define UART_CR4_ADD1 (1 << 1)
#define UART_CR4_ADD0 (1 << 0)

#define UART_CR5_SCEN (1 << 5)
#define UART_CR5_NACK (1 << 4)
#define UART_CR5_HDSEL (1 << 3)
#define UART_CR5_IRLP (1 << 2)
#define UART_CR5_IREN (1 << 1)

/* TIMERS */
/* Timer 1 - 16-bit timer with complementary PWM outputs */
#define TIM1_CR1 *(volatile uint8_t*)0x5250
#define TIM1_CR2 *(volatile uint8_t*)0x5251
#define TIM1_SMCR *(volatile uint8_t*)0x5252
#define TIM1_ETR *(volatile uint8_t*)0x5253
#define TIM1_IER *(volatile uint8_t*)0x5254
#define TIM1_SR1 *(volatile uint8_t*)0x5255
#define TIM1_SR2 *(volatile uint8_t*)0x5256
#define TIM1_EGR *(volatile uint8_t*)0x5257
#define TIM1_CCMR1 *(volatile uint8_t*)0x5258
#define TIM1_CCMR2 *(volatile uint8_t*)0x5259
#define TIM1_CCMR3 *(volatile uint8_t*)0x525A
#define TIM1_CCMR4 *(volatile uint8_t*)0x525B
#define TIM1_CCER1 *(volatile uint8_t*)0x525C
#define TIM1_CCER2 *(volatile uint8_t*)0x525D
#define TIM1_CNTRH *(volatile uint8_t*)0x525E
#define TIM1_CNTRL *(volatile uint8_t*)0x525F
#define TIM1_PSCRH *(volatile uint8_t*)0x5260
#define TIM1_PSCRL *(volatile uint8_t*)0x5261
#define TIM1_ARRH *(volatile uint8_t*)0x5262
#define TIM1_ARRL *(volatile uint8_t*)0x5263
#define TIM1_RCR *(volatile uint8_t*)0x5264
#define TIM1_CCR1H *(volatile uint8_t*)0x5265
#define TIM1_CCR1L *(volatile uint8_t*)0x5266
#define TIM1_CCR2H *(volatile uint8_t*)0x5267
#define TIM1_CCR2L *(volatile uint8_t*)0x5268
#define TIM1_CCR3H *(volatile uint8_t*)0x5269
#define TIM1_CCR3L *(volatile uint8_t*)0x526A
#define TIM1_CCR4H *(volatile uint8_t*)0x526B
#define TIM1_CCR4L *(volatile uint8_t*)0x526C
#define TIM1_BKR *(volatile uint8_t*)0x526D
#define TIM1_DTR *(volatile uint8_t*)0x526E
#define TIM1_OISR *(volatile uint8_t*)0x526F

/* Timer Control Register bits */
#define TIM_CR1_ARPE (1 << 7)
#define TIM_CR1_CMSH (1 << 6)
#define TIM_CR1_CMSL (1 << 5)
#define TIM_CR1_DIR (1 << 4)
#define TIM_CR1_OPM (1 << 3)
#define TIM_CR1_URS (1 << 2)
#define TIM_CR1_UDIS (1 << 1)
#define TIM_CR1_CEN (1 << 0)

#define TIM1_CR2_MMS2 (1 << 6)
#define TIM1_CR2_MMS1 (1 << 5)
#define TIM1_CR2_MMS0 (1 << 4)
#define TIM1_CR2_COMS (1 << 2)
#define TIM1_CR2_CCPC (1 << 0)

/* Timer Slave Mode Control bits */
#define TIM1_SMCR_MSM (1 << 7)
#define TIM1_SMCR_TS2 (1 << 6)
#define TIM1_SMCR_TS1 (1 << 5)
#define TIM1_SMCR_TS0 (1 << 4)
#define TIM1_SMCR_SMS2 (1 << 2)
#define TIM1_SMCR_SMS1 (1 << 1)
#define TIM1_SMCR_SMS0 (1 << 0)

/* Timer External Trigger Enable bits */
#define TIM1_ETR_ETP (1 << 7)
#define TIM1_ETR_ECE (1 << 6)
#define TIM1_ETR_ETPS1 (1 << 5)
#define TIM1_ETR_ETPS0 (1 << 4)
#define TIM1_ETR_ETF3 (1 << 3)
#define TIM1_ETR_ETF2 (1 << 2)
#define TIM1_ETR_ETF1 (1 << 1)
#define TIM1_ETR_ETF0 (1 << 0)

/* Timer Interrupt Enable bits */
#define TIM1_IER_BIE (1 << 7)
#define TIM1_IER_TIE (1 << 6)
#define TIM1_IER_COMIE (1 << 5)
#define TIM1_IER_CC4IE (1 << 4)
#define TIM1_IER_CC3IE (1 << 3)
#define TIM1_IER_CC2IE (1 << 2)
#define TIM1_IER_CC1IE (1 << 1)
#define TIM1_IER_UIE (1 << 0)

/* Timer Status Register bits */
#define TIM1_SR1_BIF (1 << 7)
#define TIM1_SR1_TIF (1 << 6)
#define TIM1_SR1_COMIF (1 << 5)
#define TIM1_SR1_CC4IF (1 << 4)
#define TIM1_SR1_CC3IF (1 << 3)
#define TIM1_SR1_CC2IF (1 << 2)
#define TIM1_SR1_CC1IF (1 << 1)
#define TIM1_SR1_UIF (1 << 0)

#define TIM1_SR2_CC4OF (1 << 4)
#define TIM1_SR2_CC3OF (1 << 3)
#define TIM1_SR2_CC2OF (1 << 2)
#define TIM1_SR2_CC1OF (1 << 1)

/* Timer Event Generation Register bits */
#define TIM1_EGR_BG (1 << 7)
#define TIM1_EGR_TG (1 << 6)
#define TIM1_EGR_COMG ( 1 << 5)
#define TIM1_EGR_CC4G (1 << 4)
#define TIM1_EGR_CC3G (1 << 3)
#define TIM1_EGR_CC2G (1 << 2)
#define TIM1_EGR_CC1G (1 << 1)
#define TIM1_EGR_UG (1 << 0)

/* Capture/Compare Mode Register 1 - channel configured in output */
#define TIM1_CCMR1_OC1CE (1 << 7)
#define TIM1_CCMR1_OC1M2 (1 << 6)
#define TIM1_CCMR1_OC1M1 (1 << 5)
#define TIM1_CCMR1_OC1M0 (1 << 4)
#define TIM1_CCMR1_OC1PE (1 << 3)
#define TIM1_CCMR1_OC1FE (1 << 2)
#define TIM1_CCMR1_CC1S1 (1 << 1)
#define TIM1_CCMR1_CC1S0 (1 << 0)

/* Capture/Compare Mode Register 1 - channel configured in input */
#define TIM1_CCMR1_IC1F3 (1 << 7)
#define TIM1_CCMR1_IC1F2 (1 << 6)
#define TIM1_CCMR1_IC1F1 (1 << 5)
#define TIM1_CCMR1_IC1F0 (1 << 4)
#define TIM1_CCMR1_IC1PSC1 (1 << 3)
#define TIM1_CCMR1_IC1PSC0 (1 << 2)
/* #define TIM1_CCMR1_CC1S1 (1 << 1)
#define TIM1_CCMR1_CC1S0 (1 << 0) */

/* Capture/Compare Mode Register 2 - channel configured in output */
#define TIM1_CCMR2_OC2CE (1 << 7)
#define TIM1_CCMR2_OC2M2 (1 << 6)
#define TIM1_CCMR2_OC2M1 (1 << 5)
#define TIM1_CCMR2_OC2M0 (1 << 4)
#define TIM1_CCMR2_OC2PE (1 << 3)
#define TIM1_CCMR2_OC2FE (1 << 2)
#define TIM1_CCMR2_CC2S1 (1 << 1)
#define TIM1_CCMR2_CC2S0 (1 << 0)

/* Capture/Compare Mode Register 2 - channel configured in input */
#define TIM1_CCMR2_IC2F3 (1 << 7)
#define TIM1_CCMR2_IC2F2 (1 << 6)
#define TIM1_CCMR2_IC2F1 (1 << 5)
#define TIM1_CCMR2_IC2F0 (1 << 4)
#define TIM1_CCMR2_IC2PSC1 (1 << 3)
#define TIM1_CCMR2_IC2PSC0 (1 << 2)
/* #define TIM1_CCMR2_CC2S1 (1 << 1)
#define TIM1_CCMR2_CC2S0 (1 << 0) */

/* Capture/Compare Mode Register 3 - channel configured in output */
#define TIM1_CCMR3_OC3CE (1 << 7)
#define TIM1_CCMR3_OC3M2 (1 << 6)
#define TIM1_CCMR3_OC3M1 (1 << 5)
#define TIM1_CCMR3_OC3M0 (1 << 4)
#define TIM1_CCMR3_OC3PE (1 << 3)
#define TIM1_CCMR3_OC3FE (1 << 2)
#define TIM1_CCMR3_CC3S1 (1 << 1)
#define TIM1_CCMR3_CC3S0 (1 << 0)

/* Capture/Compare Mode Register 3 - channel configured in input */
#define TIM1_CCMR3_IC3F3 (1 << 7)
#define TIM1_CCMR3_IC3F2 (1 << 6)
#define TIM1_CCMR3_IC3F1 (1 << 5)
#define TIM1_CCMR3_IC3F0 (1 << 4)
#define TIM1_CCMR3_IC3PSC1 (1 << 3)
#define TIM1_CCMR3_IC3PSC0 (1 << 2)
/* #define TIM1_CCMR3_CC3S1 (1 << 1)
#define TIM1_CCMR3_CC3S0 (1 << 0) */

/* Capture/Compare Mode Register 4 - channel configured in output */
#define TIM1_CCMR4_OC4CE (1 << 7)
#define TIM1_CCMR4_OC4M2 (1 << 6)
#define TIM1_CCMR4_OC4M1 (1 << 5)
#define TIM1_CCMR4_OC4M0 (1 << 4)
#define TIM1_CCMR4_OC4PE (1 << 3)
#define TIM1_CCMR4_OC4FE (1 << 2)
#define TIM1_CCMR4_CC4S1 (1 << 1)
#define TIM1_CCMR4_CC4S0 (1 << 0)

/* Capture/Compare Mode Register 4 - channel configured in input */
#define TIM1_CCMR4_IC4F3 (1 << 7)
#define TIM1_CCMR4_IC4F2 (1 << 6)
#define TIM1_CCMR4_IC4F1 (1 << 5)
#define TIM1_CCMR4_IC4F0 (1 << 4)
#define TIM1_CCMR4_IC4PSC1 (1 << 3)
#define TIM1_CCMR4_IC4PSC0 (1 << 2)
/* #define TIM1_CCMR4_CC4S1 (1 << 1)
#define TIM1_CCMR4_CC4S0 (1 << 0) */

/* Timer 2 - 16-bit timer */
#define TIM2_CR1 *(volatile uint8_t*)0x5300
#define TIM2_IER *(volatile uint8_t*)0x5303
#define TIM2_SR1 *(volatile uint8_t*)0x5304
#define TIM2_SR2 *(volatile uint8_t*)0x5305
#define TIM2_EGR *(volatile uint8_t*)0x5306
#define TIM2_CCMR1 *(volatile uint8_t*)0x5307
#define TIM2_CCMR2 *(volatile uint8_t*)0x5308
#define TIM2_CCMR3 *(volatile uint8_t*)0x5309
#define TIM2_CCER1 *(volatile uint8_t*)0x530A
#define TIM2_CCER2 *(volatile uint8_t*)0x530B
#define TIM2_CNTRH *(volatile uint8_t*)0x530C
#define TIM2_CNTRL *(volatile uint8_t*)0x530D
#define TIM2_PSCR *(volatile uint8_t*)0x530E
#define TIM2_ARRH *(volatile uint8_t*)0x530F
#define TIM2_ARRL *(volatile uint8_t*)0x5310
#define TIM2_CCR1H *(volatile uint8_t*)0x5311
#define TIM2_CCR1L *(volatile uint8_t*)0x5312
#define TIM2_CCR2H *(volatile uint8_t*)0x5313
#define TIM2_CCR2L *(volatile uint8_t*)0x5314
#define TIM2_CCR3H *(volatile uint8_t*)0x5315
#define TIM2_CCR3L *(volatile uint8_t*)0x5316

/* Timer 4 */
#define TIM4_CR1 *(volatile uint8_t*)0x5340
#define TIM4_IER *(volatile uint8_t*)0x5343
#define TIM4_SR *(volatile uint8_t*)0x5344
#define TIM4_EGR *(volatile uint8_t*)0x5345
#define TIM4_CNTR *(volatile uint8_t*)0x5346
#define TIM4_PSCR *(volatile uint8_t*)0x5347
#define TIM4_ARR *(volatile uint8_t*)0x5348

/* Timer 4 bitmasks */

#define TIM4_CR1_ARPE (1 << 7)
#define TIM4_CR1_OPM (1 << 3)
#define TIM4_CR1_URS (1 << 2)
#define TIM4_CR1_UDIS (1 << 1)
#define TIM4_CR1_CEN (1 << 0)

#define TIM4_IER_UIE (1 << 0)

#define TIM4_SR_UIF (1 << 0)

#define TIM4_EGR_UG (1 << 0)

#define TIM4_PSCR_PSC2 (1 << 2)
#define TIM4_PSCR_PSC1 (1 << 1)
#define TIM4_PSCR_PSC0 (1 << 0)

#define TIM4_PSCR_1 0
#define TIM4_PSCR_2 1
#define TIM4_PSCR_4 2
#define TIM4_PSCR_8 3
#define TIM4_PSCR_16 4
#define TIM4_PSCR_32 5
#define TIM4_PSCR_64 6
#define TIM4_PSCR_128 7

/* ADC 1 */
#define ADC_DB0RH *(volatile uint8_t*)0x53E0
#define ADC_DB0RL *(volatile uint8_t*)0x53E1
#define ADC_DB1RH *(volatile uint8_t*)0x53E2
#define ADC_DB1RL *(volatile uint8_t*)0x53E3
#define ADC_DB2RH *(volatile uint8_t*)0x53E4
#define ADC_DB2RL *(volatile uint8_t*)0x53E5
#define ADC_DB3RH *(volatile uint8_t*)0x53E6
#define ADC_DB3RL *(volatile uint8_t*)0x53E7
#define ADC_DB4RH *(volatile uint8_t*)0x53E8
#define ADC_DB4RL *(volatile uint8_t*)0x53E9
#define ADC_DB5RH *(volatile uint8_t*)0x53EA
#define ADC_DB5RL *(volatile uint8_t*)0x53EB
#define ADC_DB6RH *(volatile uint8_t*)0x53EC
#define ADC_DB6RL *(volatile uint8_t*)0x53ED
#define ADC_DB7RH *(volatile uint8_t*)0x53EE
#define ADC_DB7RL *(volatile uint8_t*)0x53EF
#define ADC_DB8RH *(volatile uint8_t*)0x53F0
#define ADC_DB8RL *(volatile uint8_t*)0x53F1
#define ADC_DB9RH *(volatile uint8_t*)0x53F2
#define ADC_DB9RL *(volatile uint8_t*)0x53F3

#define ADC_CSR *(volatile uint8_t*)5400
#define ADC_CR1 *(volatile uint8_t*)5401
#define ADC_CR2 *(volatile uint8_t*)5402
#define ADC_CR3 *(volatile uint8_t*)5403
#define ADC_DRH *(volatile uint8_t*)5404
#define ADC_DRL *(volatile uint8_t*)5405
#define ADC_TDRH *(volatile uint8_t*)5406
#define ADC_TDRL *(volatile uint8_t*)5407
#define ADC_HTRH *(volatile uint8_t*)5408
#define ADC_HTRL *(volatile uint8_t*)5409
#define ADC_LTRH *(volatile uint8_t*)540A
#define ADC_LTRL *(volatile uint8_t*)540B
#define ADC_AWSRH *(volatile uint8_t*)540C
#define ADC_AWSRL *(volatile uint8_t*)540D
#define ADC_AWCRH *(volatile uint8_t*)540E
#define ADC_AWCRL *(volatile uint8_t*)540F

/* ADC bitmasks */

#define ADC_CSR_EOC (1 << 7)
#define ADC_CSR_AWD (1 << 6)
#define ADC_CSR_EOCIE (1 << 5)
#define ADC_CSR_AWDIE (1 << 4)
#define ADC_CSR_CH3 (1 << 3)
#define ADC_CSR_CH2 (1 << 2)
#define ADC_CSR_CH1 (1 << 1)
#define ADC_CSR_CH0 (1 << 0)

#define ADC_CR1_SPSEL2 (1 << 6)
#define ADC_CR1_SPSEL1 (1 << 5)
#define ADC_CR1_SPSEL0 (1 << 4)
#define ADC_CR1_CONT (1 << 1)
#define ADC_CR1_ADON (1 << 0)

#define ADC_CR2_EXTTRIG (1 << 6)
#define ADC_CR2_EXTSEL1 (1 << 5)
#define ADC_CR2_EXTSEL0 (1 << 4)
#define ADC_CR2_ALIGN (1 << 3)
#define ADC_CR2_SCAN (1 << 1)

#define ADC_CR3_DBUF (1 << 7)
#define ADC_CR3_DRH (1 << 6)

/* CPU */
#define A *(volatile uint8_t*)7F00
#define PCE *(volatile uint8_t*)7F01
#define PCH *(volatile uint8_t*)7F02
#define PCL *(volatile uint8_t*)7F03
#define XH *(volatile uint8_t*)7F04
#define XL *(volatile uint8_t*)7F05
#define YH *(volatile uint8_t*)7F06
#define YL *(volatile uint8_t*)7F07
#define SPH *(volatile uint8_t*)7F08
#define SPL  *(volatile uint8_t*)7F09
#define CCR  *(volatile uint8_t*)7F0A
#define CFG_CCR  *(volatile uint8_t*)7F60
#define ITC_SPR1  *(volatile uint8_t*)7F70
#define ITC_SPR2  *(volatile uint8_t*)7F71
#define ITC_SPR3  *(volatile uint8_t*)7F72
#define ITC_SPR4  *(volatile uint8_t*)7F73
#define ITC_SPR5  *(volatile uint8_t*)7F74
#define ITC_SPR6  *(volatile uint8_t*)7F75
#define ITC_SPR7  *(volatile uint8_t*)7F76
#define ITC_SPR8  *(volatile uint8_t*)7F77

/* SWIM, Debug */
#define SWIM_CSR  *(volatile uint8_t*)7F80
#define DM_BK1RE  *(volatile uint8_t*)7F90
#define DM_BK1RH  *(volatile uint8_t*)7F91
#define DM_BK1RL  *(volatile uint8_t*)7F92
#define DM_BK2RE  *(volatile uint8_t*)7F93
#define DM_BK2RH  *(volatile uint8_t*)7F94
#define DM_BK2RL  *(volatile uint8_t*)7F95
#define DM_CR1  *(volatile uint8_t*)7F96
#define DM_CR2  *(volatile uint8_t*)7F97
#define DM_CSR1  *(volatile uint8_t*)7F98
#define DM_CSR2  *(volatile uint8_t*)7F99
#define DM_ENFCTR  *(volatile uint8_t*)7F9A

/* Interrupt Numbers */
#define INT_TLI 0
#define INT_AWU 1
#define INT_CLK 2
#define INT_EXTI0 3
#define INT_EXTI1 4
#define INT_EXTI2 5
#define INT_EXTI3 6
#define INT_EXTI4 7
#define INT_SPI 10
#define INT_TIM1 11
#define INT_TIM1_CCM 12
#define INT_TIM2 13
#define INT_TIM2_CCM 14
#define INT_UART1_TX_COMPLETE 17
#define INT_UART1_DATA_FULL 18
#define INT_I2C 19
#define INT_ADC1 22
#define INT_TIM4 23
#define INT_FLASH 24

/* Interrupt Vectors */
#define INT_VECTOR_RESET 0x8000
#define INT_VECTOR_TRAP 0x8004
#define INT_VECTOR_TLI 0x8008
#define INT_VECTOR_AWU 0x800C
#define INT_VECTOR_CLK 0x8010
#define INT_VECTOR_EXTI0 0x8014
#define INT_VECTOR_EXTI1 0x8018
#define INT_VECTOR_EXTI2 0x801C
#define INT_VECTOR_EXTI3 0x8020
#define INT_VECTOR_EXTI4 0x8024
#define INT_VECTOR_SPI 0x8030
#define INT_VECTOR_TIM1 0x8034
#define INT_VECTOR_TIM1_CCM 0x8038
#define INT_VECTOR_TIM2 0x803C
#define INT_VECTOR_TIM2_CCM 0x8040
#define INT_VECTOR_UART1_TX_COMPLETE 0x804C
#define INT_VECTOR_UART1_DATA_FULL 0x8050
#define INT_VECTOR_I2C 0x8054
#define INT_VECTOR_ADC1 0x8060
#define INT_VECTOR_TIM4 0x8064
#define INT_VECTOR_FLASH 0x8068

#define nointerrupts() {__asm sim __endasm;}
#define interrupts() {__asm rim __endasm;}
#define wait_for_interrupt() {\
    __asm \
    wfi\
    nop\
    nop\
 __endasm;}

#endif /*__STM8S_H */
