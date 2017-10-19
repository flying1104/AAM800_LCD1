#include "types.h"
#include "stm32f4xx.h"
#include "sys_delay.h"
#include "dev_pin_conf.h"
#include "dev_lcd_st7789.h"

/*
//写寄存器函数
//regval:寄存器值
void LCD_WR_REG(vu16 regval)
{   
	regval=regval;		//使用-O2优化的时候,必须插入的延时
	LCD->LCD_REG=regval;//写入要写的寄存器序号	 
}
//写LCD数据
//data:要写入的值
void LCD_WR_DATA(vu16 data)
{	  
	data=data;			//使用-O2优化的时候,必须插入的延时
	LCD->LCD_RAM=data;		 
}
//读LCD数据
//返回值:读到的值
u16 LCD_RD_DATA(void)
{
	vu16 ram;			//防止被优化
	ram=LCD->LCD_RAM;	
	return ram;	 
}	
*/

void Lcd_Init(void)
{
	vu32 i=0;
	
  GPIO_InitTypeDef  GPIO_InitStructure;
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
//  FSMC_NORSRAMTimingInitTypeDef  readWriteTiming; 
//	FSMC_NORSRAMTimingInitTypeDef  writeTiming;
	FSMC_NORSRAMTimingInitTypeDef p; 
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);//使能PD,PE,PF,PG时钟  
  RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC,ENABLE);//使能FSMC时钟  
		
  GPIO_InitStructure.GPIO_Pin = LCD_FSMCD_PIN;//PD0,1,4,5,8,9,10,14,15 AF OUT
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用输出
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化  
	
  GPIO_InitStructure.GPIO_Pin = LCD_FSMCE_PIN;//PE7~15,AF OUT
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用输出
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化  
			
	GPIO_InitStructure.GPIO_Pin = LCD_RST_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(LCD_RST_GPIO, &GPIO_InitStructure);

  GPIO_PinAFConfig(GPIOD,GPIO_PinSource0,GPIO_AF_FSMC);//PD0,AF12
  GPIO_PinAFConfig(GPIOD,GPIO_PinSource1,GPIO_AF_FSMC);//PD1,AF12
  GPIO_PinAFConfig(GPIOD,GPIO_PinSource4,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOD,GPIO_PinSource5,GPIO_AF_FSMC); 
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource7,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOD,GPIO_PinSource8,GPIO_AF_FSMC); 
  GPIO_PinAFConfig(GPIOD,GPIO_PinSource9,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOD,GPIO_PinSource10,GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource11,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOD,GPIO_PinSource14,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOD,GPIO_PinSource15,GPIO_AF_FSMC);//PD15,AF12
 
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource7,GPIO_AF_FSMC);//PE7,AF12
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource8,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource9,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource10,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource11,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource12,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource13,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource14,GPIO_AF_FSMC);
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource15,GPIO_AF_FSMC);//PE15,AF12

/*
  readWriteTiming.FSMC_AddressSetupTime = 0XF;	 //地址建立时间（ADDSET）为16个HCLK 1/168M=6ns*16=96ns	
  readWriteTiming.FSMC_AddressHoldTime = 0x00;	 //地址保持时间（ADDHLD）模式A未用到	
  readWriteTiming.FSMC_DataSetupTime = 60;			//数据保存时间为60个HCLK	=6*60=360ns
  readWriteTiming.FSMC_BusTurnAroundDuration = 0x00;
  readWriteTiming.FSMC_CLKDivision = 0x00;
  readWriteTiming.FSMC_DataLatency = 0x00;
  readWriteTiming.FSMC_AccessMode = FSMC_AccessMode_A;	 //模式A 
    

	writeTiming.FSMC_AddressSetupTime =9;	      //地址建立时间（ADDSET）为9个HCLK =54ns 
  writeTiming.FSMC_AddressHoldTime = 0x00;	 //地址保持时间（A		
  writeTiming.FSMC_DataSetupTime = 8;		 //数据保存时间为6ns*9个HCLK=54ns
  writeTiming.FSMC_BusTurnAroundDuration = 0x00;
  writeTiming.FSMC_CLKDivision = 0x00;
  writeTiming.FSMC_DataLatency = 0x00;
  writeTiming.FSMC_AccessMode = FSMC_AccessMode_A;	 //模式A 
*/

  p.FSMC_AddressSetupTime = 0x02;
  p.FSMC_AddressHoldTime = 0x00;
  p.FSMC_DataSetupTime = 0x05; 
  p.FSMC_BusTurnAroundDuration = 0x00;
  p.FSMC_CLKDivision = 0x00;
  p.FSMC_DataLatency = 0x00;
  p.FSMC_AccessMode = FSMC_AccessMode_B; 
/* 
  FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM4;//  这里我们使用NE4 ，也就对应BTCR[6],[7]。
  FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable; // 不复用数据地址
  FSMC_NORSRAMInitStructure.FSMC_MemoryType =FSMC_MemoryType_SRAM;// FSMC_MemoryType_SRAM;  //SRAM   
  FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;//存储器数据宽度为16bit   
  FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode =FSMC_BurstAccessMode_Disable;// FSMC_BurstAccessMode_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;   
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;  
  FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;	//  存储器写使能
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;   
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable; // 读写使用不同的时序
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &readWriteTiming; //读写时序
  FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &writeTiming;  //写时序
*/
  FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM4;
	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
  FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait= FSMC_AsynchronousWait_Disable; 
  FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode= FSMC_ExtendedMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct =&p;
	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p; 

  FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  //初始化FSMC配置

  FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM4, ENABLE);  // 使能BANK1 
	
	Lcd_Base_Config(LCD_OFF);
	Delay_Ms(100);
	Lcd_Base_Config(LCD_ON);
	Delay_Ms(100);
	
	LCD_WR_REG(0x11);
  Delay_Ms(120);
  //横屏
	LCD_WR_REG(0x36);
  LCD_WR_DATA(0x68);
	//16bit
	LCD_WR_REG(0x3A);
  LCD_WR_DATA(0x05);
	
	LCD_WR_REG(0xB2);    //Porch Setting
	LCD_WR_DATA(0x0C);   //Normal BP
	LCD_WR_DATA(0x0C);   //Normal FP
	LCD_WR_DATA(0x00);   //Enable Seperate
	LCD_WR_DATA(0x33);   //idle, BP[7:4], FP[3:0]
	LCD_WR_DATA(0x33);   //partial, BP[7:4], FP[3:0]
	
	LCD_WR_REG(0xB7);     //Gate Control
	LCD_WR_DATA(0x35);   

	LCD_WR_REG(0xBB);     //VCOMS Setting
	LCD_WR_DATA(0x2B);   //37

	LCD_WR_REG(0xC0);     
	LCD_WR_DATA(0x2C);   

	LCD_WR_REG(0xC2);     
	LCD_WR_DATA(0x01);   

	LCD_WR_REG(0xC3);     //VRH Set
	LCD_WR_DATA(0x20);   //21

	LCD_WR_REG(0xC4);     
	LCD_WR_DATA(0x20);   

	LCD_WR_REG(0xC6);     //Frame Rate Control in Normal Mode
	LCD_WR_DATA(0x0F);   
	
  LCD_WR_REG(0xD0);
  LCD_WR_DATA(0xA4);
  LCD_WR_DATA(0x81);  
  
//  LCD_WR_REG(0xBB);
//  LCD_WR_DATA(0x35);
  
  LCD_WR_REG(0xE0);
/*
  LCD_WR_DATA(0xD0);
  LCD_WR_DATA(0x00);
  LCD_WR_DATA(0x02);
  LCD_WR_DATA(0x07);
  LCD_WR_DATA(0x0B);
  LCD_WR_DATA(0x1A);
  LCD_WR_DATA(0x31);
  LCD_WR_DATA(0x54);
  LCD_WR_DATA(0x40);
  LCD_WR_DATA(0x29);
  LCD_WR_DATA(0x12);
  LCD_WR_DATA(0x12);
  LCD_WR_DATA(0x12);
  LCD_WR_DATA(0x17);
*/
	LCD_WR_DATA(0xD0);
	LCD_WR_DATA(0xCA);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x09);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x2D);
	LCD_WR_DATA(0x3B);
	LCD_WR_DATA(0x3D);
	LCD_WR_DATA(0x34);
	LCD_WR_DATA(0x0A);
	LCD_WR_DATA(0x0A);
	LCD_WR_DATA(0x1B);
	LCD_WR_DATA(0x28);

  LCD_WR_REG(0xE1);
	/*
  LCD_WR_DATA(0xD0);
  LCD_WR_DATA(0x00);
  LCD_WR_DATA(0x02);
  LCD_WR_DATA(0x07);
  LCD_WR_DATA(0x05);
  LCD_WR_DATA(0x25);
  LCD_WR_DATA(0x2D);
  LCD_WR_DATA(0x44);
  LCD_WR_DATA(0x45);
  LCD_WR_DATA(0x1C);
  LCD_WR_DATA(0x18);
  LCD_WR_DATA(0x16);
  LCD_WR_DATA(0x1C);
  LCD_WR_DATA(0x1D);
	*/
	LCD_WR_DATA(0xD0);
	LCD_WR_DATA(0xCA);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x2E);
	LCD_WR_DATA(0x5C);
	LCD_WR_DATA(0x40);
	LCD_WR_DATA(0x34);
	LCD_WR_DATA(0x09);
	LCD_WR_DATA(0x0B);
	LCD_WR_DATA(0x1B);
	LCD_WR_DATA(0x28);
  
	LCD_WR_REG(0x21); 

  LCD_WR_REG(0x2A);
  LCD_WR_DATA(0); 
  LCD_WR_DATA(0);       
  LCD_WR_DATA(0x01);  
  LCD_WR_DATA(0x3F) ;
 
  LCD_WR_REG(0x2B);    
  LCD_WR_DATA(0);
  LCD_WR_DATA(0);
  LCD_WR_DATA(0); 
  LCD_WR_DATA(0xEF);
  
	
  LCD_WR_REG(0x29);
	Delay_Ms(50); 
	LCD_WR_REG(0x2c);

/*
	LCD_WR_REG(0x11); 
	Delay_Ms(120);      //Delay 120ms 

	LCD_WR_REG(0x36);     //Memory Data Access Control
	LCD_WR_DATA(0x00);   //MY:0x80

	LCD_WR_REG(0x3A);   //Interface Pixel Format
	LCD_WR_DATA(0x05);   //MCU-16bit

	LCD_WR_REG(0xB2);     //Porch Setting
	LCD_WR_DATA(0x0C);   //Normal BP
	LCD_WR_DATA(0x0C);   //Normal FP
	LCD_WR_DATA(0x00);   //Enable Seperate
	LCD_WR_DATA(0x33);   //idle, BP[7:4], FP[3:0]
	LCD_WR_DATA(0x33);   //partial, BP[7:4], FP[3:0]

	LCD_WR_REG(0xB7);     //Gate Control
	LCD_WR_DATA(0x35);   

	LCD_WR_REG(0xBB);     //VCOMS Setting
	LCD_WR_DATA(0x2B);   //37

	LCD_WR_REG(0xC0);     
	LCD_WR_DATA(0x2C);   

	LCD_WR_REG(0xC2);     
	LCD_WR_DATA(0x01);   

	LCD_WR_REG(0xC3);     //VRH Set
	LCD_WR_DATA(0x20);   //21

	LCD_WR_REG(0xC4);     
	LCD_WR_DATA(0x20);   

	LCD_WR_REG(0xC6);     //Frame Rate Control in Normal Mode
	LCD_WR_DATA(0x0F);   

	LCD_WR_REG(0xD0);     //Power Control 1
	LCD_WR_DATA(0xA4);   //
	LCD_WR_DATA(0xA1);   //AVDD=6.8V, AVCL=-4.8V, VDS=2.3V

	LCD_WR_REG(0xE0);     
	LCD_WR_DATA(0xD0);
	LCD_WR_DATA(0xCA);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x09);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x2D);
	LCD_WR_DATA(0x3B);
	LCD_WR_DATA(0x3D);
	LCD_WR_DATA(0x34);
	LCD_WR_DATA(0x0A);
	LCD_WR_DATA(0x0A);
	LCD_WR_DATA(0x1B);
	LCD_WR_DATA(0x28);

	LCD_WR_REG(0xE1);     
	LCD_WR_DATA(0xD0);
	LCD_WR_DATA(0xCA);
	LCD_WR_DATA(0x0F);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x08);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x2E);
	LCD_WR_DATA(0x5C);
	LCD_WR_DATA(0x40);
	LCD_WR_DATA(0x34);
	LCD_WR_DATA(0x09);
	LCD_WR_DATA(0x0B);
	LCD_WR_DATA(0x1B);
	LCD_WR_DATA(0x28);
	 
	LCD_WR_REG(0x21); 

	LCD_WR_REG(0x2A); //Frame rate control
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0xEF);

	LCD_WR_REG(0x2B); //Display function control
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x01);
	LCD_WR_DATA(0x3F);
	
	LCD_WR_REG(0x29); //display on
	Delay_Ms(50); 
	LCD_WR_REG(0x2c);*/
}

void Lcd_Base_Config(uchar config) {
	if(config == LCD_ON)	LCD_BASE_POUT = LCD_ON;
	else 									LCD_BASE_POUT = LCD_OFF;
}

void Lcd_Clear(ushort color)
{
	int i;
	
	LCD_WR_REG(0x2A);
  LCD_WR_DATA(0); 
  LCD_WR_DATA(0);       
  LCD_WR_DATA(0x01);  
  LCD_WR_DATA(0x3F) ;
 
  LCD_WR_REG(0x2B);    
  LCD_WR_DATA(0);
  LCD_WR_DATA(0);
  LCD_WR_DATA(0); 
  LCD_WR_DATA(0xEF);
 
  LCD_WR_REG(0x2c);
	
	for( i=0; i < 320*240; i++ )
  {
    LCD_WR_DATA(color);
  }
}

void Frame(void)
{
	int  i,j;

  LCD_WR_REG(0x2c);
	
	for(j = 0; j < ROW; j++)
	{
		LCD_WR_DATA(0XFFFF);	
	}

	for(i=0;i<(COL-2);i++)
	{
		LCD_WR_DATA(0XFFFF);	
		for(j=0;j<(ROW-2);j++)
		{
			LCD_WR_DATA(0X0000);		
		}

		LCD_WR_DATA(0XFFFF);		     
	}

	for(j=0;j<ROW;j++)
	{
		LCD_WR_DATA(0XFFFF);	
	}
}

void Display_Rgb(ushort color)
{
   ushort i,j;
   LCD_WR_REG(0x2C);
   for(i=0;i<COL;i++)
   for(j=0;j<ROW;j++)
     {
        LCD_WR_DATA(color);
     }
}

void Display_Gray(void)	 //显示灰阶函数
{
	uchar i, j, k, red, green, blue, data1, data2;
	ushort color;
	unsigned int g;
	g = COL/16;
	red = 0x00;
	green = 0x00;
	blue = 0x00;
	data1 = 0x00;
	data2 = 0x00;
	color = 0x0000;
	LCD_WR_REG(0x2C);
	
	for(i = 0; i < 16; i++)
	{
		for(j = 0; j < g; j++)
		for(k = 0; k < 240; k++)
		{
			LCD_WR_DATA(color);
		}
		red++;
		red++;
		green++;
		green++;
		green++;
		green++;
		blue++;
		blue++;

		data1 = (red<<3)|((green&0x38)>>3);
		data2 = ((green&0x07) << 5) | blue;
		color = (data1 << 8) | data2;
	}
}


