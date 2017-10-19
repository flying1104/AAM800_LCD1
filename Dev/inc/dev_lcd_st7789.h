#ifndef __DEV_LCD_ST7789
#define __DEV_LCD_ST7789

#include "dev_io.h"


//LCD地址结构体
/*
typedef struct
{
	vu16 LCD_REG;
	vu16 LCD_RAM;
} LCD_TypeDef;
//使用NOR/SRAM的 Bank1.sector4,地址位HADDR[27,26]=11 A6作为数据命令区分线 
//注意设置时STM32内部会右移一位对其! 111 1110=0X7E  1 1111 1111 1111 1110 = 0x1FFFE
#define LCD_BASE        ((u32)(0x6C000000 | 0x0001FFFE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)
*/

#define Bank1_LCD_C   ((u32)0x60000000)   //Disp RegADDR
#define Bank1_LCD_D   ((u32)0x60020000)    //Disp Data ADDR      // A16 PD11
//#define Bank1_LCD_D   	((u32)0x6001FFFE)    //Disp Data ADDR      // A16 PD11

#define LCD_WR_REG(index)   ((*(__IO u16 *) (Bank1_LCD_C)) =((u16)index))
#define LCD_WR_DATA(val)    ((*(__IO u16 *) (Bank1_LCD_D)) = ((u16)(val)))

#define LCD_BASE_POUT			PEout(2)

#define LCD_ON	1
#define LCD_OFF	0

#define ROW 320		
#define COL 240 

//void LCD_WR_REG(vu16 regval);
//void LCD_WR_DATA(vu16 data);
u16 LCD_RD_DATA(void);
void Lcd_Init(void);
void Lcd_Base_Config(uchar config);
void Lcd_Clear(ushort color);
void Frame(void);
void Display_Rgb(ushort color);
void Display_Gray(void);

#endif


