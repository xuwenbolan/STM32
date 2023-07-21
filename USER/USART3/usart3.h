#ifndef __USART3_H__
#define __USART3_H__

#include "main.h"

#define USART_REC_LEN2  			200

void MX_USART6_UART_Init(void);
extern u8  USART_RX_BUF2[USART_REC_LEN2]; 
extern u16 USART_RX_STA2; 
extern u8 count_with_fl;

extern char USART_DATA_REC_x[5];
extern char USART_DATA_REC_y[5];
extern char USART_DATA_REC_z[5];
extern char USART_DATA_REC_cmd[5];
extern u8 break_flag;
extern int task_check_flag2;
#endif







