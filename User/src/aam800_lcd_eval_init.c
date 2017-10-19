/*=================================================================*\
Filename				:	aes_play_eval_init.c
Author				:	Wisely
Description			:	
Revision	History	:	2017-08-16
							V1.0
Company				:
Email					:
Copyright(c) ,DreamFly Technology Inc,All right reserved
\*=================================================================*/
#include "types.h"
#include "sys_delay.h"
#include "sys_base.h"
#include "sys_uart.h"
#include "stm32f4xx.h"
#include "dev_hmilcd.h"
#include "aam800_lcd_eval_init.h"
#include "dev_lcd_st7789.h"
#include <stdio.h>

void Eval_Base_Init(void)
{
	Delay_Init(168);
	System_Rst_Init();
	Led_Base_Init();
	Usart_Init(9600);
	Uart2_Init(9600);
//	Adc_Init();
//	System_Rst_Config(SYSTEM_RST_OFF);
	Delay_Ms(50);
}

void Eval_Dev_Init(void)
{
	Lcd_Init();
}


void Board_Version(void)
{
	printf("Board:\t%s\n",BOARD);
	printf("Ver:\t%s\n", VERSION);
}




