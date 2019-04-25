#ifndef __MEMORY_MAP_H__
#define __MEMORY_MAP_H__

#define F_CPU   1000000

/* ACIA registers */

#define ACIA_BASE       (0x7f00)
#define ACIA_DATA       (ACIA_BASE)
#define ACIA_STATUS     (ACIA_BASE + 1)
#define ACIA_COMMAND    (ACIA_BASE + 2)
#define ACIA_CONTROL    (ACIA_BASE + 3)

/* ACIA control register bit values */

#define ACIA_STOP_BITS_1  0x00
#define ACIA_STOP_BITS_2  0x80
#define ACIA_DATA_BITS_8  0x00
#define ACIA_DATA_BITS_7  0x20
#define ACIA_DATA_BITS_6  0x40
#define ACIA_DATA_BITS_5  0x60
#define ACIA_CLOCK_EXT    0x00
#define ACIA_CLOCK_INT    0x10
#define ACIA_BAUD_16XEXT  0x00
#define ACIA_BAUD_50      0x01
#define ACIA_BAUD_75      0x02
#define ACIA_BAUD_109     0x03
#define ACIA_BAUD_134     0x04
#define ACIA_BAUD_150     0x05
#define ACIA_BAUD_300     0x06
#define ACIA_BAUD_600     0x07
#define ACIA_BAUD_1200    0x08
#define ACIA_BAUD_1800    0x09
#define ACIA_BAUD_2400    0x0a
#define ACIA_BAUD_3600    0x0b
#define ACIA_BAUD_4800    0x0c
#define ACIA_BAUD_7200    0x0d
#define ACIA_BAUD_9600    0x0e
#define ACIA_BAUD_19200   0x0f

/* ACIA command register bit values */

#define ACIA_PARITY_ODD               0x00
#define ACIA_PARITY_EVEN              0x40
#define ACIA_PARITY_MARK              0x80
#define ACIA_PARITY_SPACE             0xc0
#define ACIA_PARITY_DISABLE           0x00
#define ACIA_PARITY_ENABLE            0x20
#define ACIA_ECHO_DISABLE             0x00
#define ACIA_ECHO_ENABLE              0x10
#define ACIA_TX_INT_DISABLE_RTS_HIGH  0x00
#define ACIA_TX_INT_ENABLE_RTS_LOW    0x04
#define ACIA_TX_INT_DISABLE_RTS_LOW   0x08
#define ACIA_TX_INT_DISABLE_BREAK     0x0c
#define ACIA_RX_INT_ENABLE            0x00
#define ACIA_RX_INT_DISABLE           0x02
#define ACIA_DTR_HIGH                 0x00
#define ACIA_DTR_LOW                  0x01

/* ACIA status register bit masks */

#define ACIA_STATUS_IRQ        (1 << 7)
#define ACIA_STATUS_DSR        (1 << 6)
#define ACIA_STATUS_DCD        (1 << 5)
#define ACIA_STATUS_TX_EMPTY   (1 << 4)
#define ACIA_STATUS_RX_FULL    (1 << 3)
#define ACIA_STATUS_OVERRUN    (1 << 2)
#define ACIA_STATUS_FRAME_ERR  (1 << 1)
#define ACIA_STATUS_PARITY_ERR (1 << 0)

/* VIA registers */

#define VIA1_BASE   0x7f20UL
#define VIA1_ORB    (VIA1_BASE)
#define VIA1_IRB    (VIA1_BASE)
#define VIA1_ORA    (VIA1_BASE + 1)
#define VIA1_IRA    (VIA1_BASE + 1)
#define VIA1_DDRB   (VIA1_BASE + 2)
#define VIA1_DDRA   (VIA1_BASE + 3)
#define VIA1_T1C_L  (VIA1_BASE + 4)
#define VIA1_T1C_H  (VIA1_BASE + 5)
#define VIA1_T1L_L  (VIA1_BASE + 6)
#define VIA1_T1L_H  (VIA1_BASE + 7)
#define VIA1_T2C_L  (VIA1_BASE + 8)
#define VIA1_T2C_H  (VIA1_BASE + 9)
#define VIA1_SR     (VIA1_BASE + 10)
#define VIA1_ACR    (VIA1_BASE + 11)
#define VIA1_PCR    (VIA1_BASE + 12)
#define VIA1_IFR    (VIA1_BASE + 13)
#define VIA1_IER    (VIA1_BASE + 14)
#define VIA1_ORA_NH (VIA1_BASE + 15)
#define VIA1_IRA_NH (VIA1_BASE + 15)

#define VIA2_BASE   (0x7f40UL)
#define VIA2_ORB    (VIA2_BASE)
#define VIA2_IRB    (VIA2_BASE)
#define VIA2_ORA    (VIA2_BASE + 1)
#define VIA2_IRA    (VIA2_BASE + 1)
#define VIA2_DDRB   (VIA2_BASE + 2)
#define VIA2_DDRA   (VIA2_BASE + 3)
#define VIA2_T1C_L  (VIA2_BASE + 4)
#define VIA2_T1C_H  (VIA2_BASE + 5)
#define VIA2_T1L_L  (VIA2_BASE + 6)
#define VIA2_T1L_H  (VIA2_BASE + 7)
#define VIA2_T2C_L  (VIA2_BASE + 8)
#define VIA2_T2C_H  (VIA2_BASE + 9)
#define VIA2_SR     (VIA2_BASE + 10)
#define VIA2_ACR    (VIA2_BASE + 11)
#define VIA2_PCR    (VIA2_BASE + 12)
#define VIA2_IFR    (VIA2_BASE + 13)
#define VIA2_IER    (VIA2_BASE + 14)
#define VIA2_ORA_NH (VIA2_BASE + 15)
#define VIA2_IRA_NH (VIA2_BASE + 15)

/* Port bits */

#define VIA_PA0  (1 << 0)
#define VIA_PA1  (1 << 1)
#define VIA_PA2  (1 << 2)
#define VIA_PA3  (1 << 3)
#define VIA_PA4  (1 << 4)
#define VIA_PA5  (1 << 5)
#define VIA_PA6  (1 << 6)
#define VIA_PA7  (1 << 7)

/* Port bits */

#define VIA_PB0  (1 << 0)
#define VIA_PB1  (1 << 1)
#define VIA_PB2  (1 << 2)
#define VIA_PB3  (1 << 3)
#define VIA_PB4  (1 << 4)
#define VIA_PB5  (1 << 5)
#define VIA_PB6  (1 << 6)
#define VIA_PB7  (1 << 7)

/* LED */

#define LED_DDR VIA1_DDRA
#define LED_OUT VIA1_ORA
#define LED     VIA_PA7

#define readb(addr)  (*((unsigned char *)(addr)))
#define writeb(addr, data) (*((volatile unsigned char*)(addr)) = data)


#endif /* __MEMORY_MAP_H__ */
