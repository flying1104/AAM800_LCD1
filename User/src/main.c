/*=================================================================*\
Filename				:	main.c
Author				:	Wisely
Description			:	
Revision	History	:	2017-08-16
							V1.0
Company				:
Email					:
Copyright(c) ,DreamFly Technology Inc,All right reserved
\*=================================================================*/
#include "types.h"
#include "stm32f4xx.h"
#include "sys_delay.h"
#include "aam800_lcd_eval_init.h"
#include "dev_hmilcd.h"
#include "dev_lcd_st7789.h"
#include "main.h"
#include <stdio.h>

int main(void)
{
	ushort tmp;
	
	Eval_Base_Init();
	
	Eval_Dev_Init();
	
	Board_Version();
	
//	Lcd_Clear(0Xffff);

	while(1)
	{
		Frame();
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Display_Rgb(0x0000);//ºÚ
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Display_Rgb(0xFFFF);//°×
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Display_Gray();//»Ò½×
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Display_Rgb(0xF800);//À¶
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Display_Rgb(0x07e0);//Çà
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Display_Rgb(0x001f);//ºì
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
		Delay_Ms(1000);
	}
}




