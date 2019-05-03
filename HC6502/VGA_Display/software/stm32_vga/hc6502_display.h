#ifndef HC6502_DISPLAY_H_
#define HC6502_DISPLAY_H_

#define CHAR_ROW 20
#define CHAR_COL 63
#define PIXEL_PER_ROW 10

#define TAB_LEN		4
#define CMD_CLEAR	0x80
#define CMD_FILL	0x81
#define CMD_SETCUR	0x82

void hc6502_display_init(void);
void hc6502_display_routine(void);
void hc6502_display_debug(void);
#endif
