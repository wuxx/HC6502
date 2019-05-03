#include "stm32f10x.h"
#include "ctype.h"
#include "string.h"
#include "video.h"
#include "gdi.h"
#include "zqueue.h"
#include "hc6502_display.h"

static void GPIO_Configuration(void);
static void EXTI_Configuration(void);
static void TIM4_Configuration(void);
static void reset_state(void);
static void buff_fill(uint8_t ch);
static void tabs(void);
static void line_feed(void);
static void refresh(void);
static void exec_clear(uint8_t x);
static void exec_fill(uint8_t x);
static void set_cursor(uint8_t x);

uint8_t char_buf[CHAR_ROW][CHAR_COL + 1];
uint16_t first_line;
uint16_t cursor_row, cursor_col;
void (*requ_para_func)(uint8_t);
uint8_t para_cnt;
uint8_t para_buf[8];
bool refresh_flag;
zqueue message;

void hc6502_display_init()
{
	zq_init(&message);
	GPIO_Configuration();
	EXTI_Configuration();
	vidInit();
	reset_state();
	buff_fill(' ');
	TIM4_Configuration();
}

void hc6502_display_routine(void)
{
	//按道理这里要关EXTI中断，但实际分析下来风险不大
	while(!zq_empty(&message)){
		uint8_t ch = zq_dequeue(&message);
		if(requ_para_func == NULL){
			if(isprint(ch)){
				if(cursor_col >= CHAR_COL)
					line_feed();
				char_buf[cursor_row][cursor_col] = ch;
				++cursor_col;
			}
			else{
				switch(ch){
					case '\t':
						tabs();
						break;
					case '\n':
						line_feed();
						break;
					case CMD_CLEAR:
						exec_clear(ch);
						break;
					case CMD_FILL:
						exec_fill(ch);
						break;
					case CMD_SETCUR:
						set_cursor(ch);
						break;
					default:
						//Illegal instruction
						break;
				}
			}
		}
		else{
			(*requ_para_func)(ch);
		}
	}
	if(refresh_flag){
		refresh();
		refresh_flag = false;
	}
}

void hc6502_display_debug(void)
{
	static uint8_t i = 0;
	uint8_t mask = 0x80;
	while(!zq_empty(&message)){
		uint8_t ch = zq_dequeue(&message);
		char_buf[cursor_row][0] = (i / 100) + '0';
		char_buf[cursor_row][1] = (i / 10 % 10) + '0';
		char_buf[cursor_row][2] = (i % 10) + '0';
		char_buf[cursor_row][3] = ':';
		for(uint16_t i = 0; i < 8; i++){
				char_buf[cursor_row][i + 8] = ch & mask ? '1' : '0';
				mask >>= 1;
		}
		line_feed();
		++i;
	}
	if(refresh_flag){
		refresh();
		refresh_flag = false;
	}
}

void refresh(void)
{
	for(uint16_t i = 0; i < CHAR_ROW; ++i){
		uint16_t j = (first_line + i) % CHAR_ROW;
		gdiDrawTextEx(0, PIXEL_PER_ROW * i, char_buf[j], GDI_ROP_COPY);
	}
}

void exec_clear(uint8_t x)
{
	reset_state();
	buff_fill(' ');
}

void exec_fill(uint8_t x)
{
	if(para_cnt < 1){
		para_buf[para_cnt] = x;
		++para_cnt;
		requ_para_func = exec_fill;
	}
	else{
		reset_state();
		buff_fill(x & 0x7F);
		para_cnt = 0;
		requ_para_func = NULL;
	}
}

void set_cursor(uint8_t x)
{
	if(para_cnt < 2){
		para_buf[para_cnt] = x;
		++para_cnt;
		requ_para_func = set_cursor;
	}
	else{
		cursor_col = para_buf[1] % CHAR_COL;
		cursor_row = (first_line + x) % CHAR_ROW;
		para_cnt = 0;
		requ_para_func = NULL;
	}
}

void tabs(void)
{
	uint16_t space = TAB_LEN - cursor_col % TAB_LEN;
	for(uint16_t i = 0; i < space; ++i){
		if(cursor_col >= CHAR_COL){
			line_feed();
			break;
		}
		char_buf[cursor_row][cursor_col] = ' ';
		++cursor_col;
	}
}

void line_feed(void)
{
	cursor_col = 0;
	cursor_row = (cursor_row + 1) % CHAR_ROW;
	if(cursor_row == first_line){
		memset(char_buf + cursor_row, ' ', CHAR_COL);
		char_buf[cursor_row][CHAR_COL] = '\0';
		first_line = (first_line + 1) % CHAR_ROW;
	}
}

void reset_state(void)
{
	first_line = 0;
	cursor_row = 0;
	cursor_col = 0;
	para_cnt = 0;
	requ_para_func = NULL;
}

void buff_fill(uint8_t ch)
{
	for(uint16_t i = 0; i < CHAR_ROW; ++i){
		memset(char_buf + i, ch, CHAR_COL);
		char_buf[i][CHAR_COL] = '\0';
	}
}

void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_SET);
}

void EXTI_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
  //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;		//GPIO_Mode_IN_FLOATING
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6); 
	
  EXTI_InitStructure.EXTI_Line = EXTI_Line6;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;	//EXTI_Trigger_Rising_Falling
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
}

void TIM4_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
  NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	TIM_DeInit(TIM4);
	//100ms中断一次
  TIM_TimeBaseStructure.TIM_Period = 200;
  TIM_TimeBaseStructure.TIM_Prescaler = (36000 - 1);
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
  
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM4, ENABLE);
}


void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line6) != RESET)
	{
			GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_RESET);
			if(!zq_full(&message)){
				uint8_t data = 0;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3);
				zq_enqueue(&message, data);
			}
			else{
				//Queue is full!!!
				GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_SET);
			}
			GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_SET);
			EXTI_ClearITPendingBit(EXTI_Line6);
  }
}

void TIM4_IRQHandler(void)
{
	static bool flag;
	//检查TIM4更新中断发生与否
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET){
		flag = !flag;
		if(flag)
			GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET);
		else
			GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_RESET);
		refresh_flag = true;
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);		//清除TIMx更新中断标志
	}
}

/*
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line6) != RESET)
	{
    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)){
			if(!zq_full(&message)){
				uint8_t data = 0;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);
				data <<= 1;
				data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3);
				zq_enqueue(&message, data);
			}
			else{
				//Queue is full!!!
				GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_SET);
			}
			GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_SET);
		}
		else
			GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_RESET);
    EXTI_ClearITPendingBit(EXTI_Line6);
  }
}
*/
