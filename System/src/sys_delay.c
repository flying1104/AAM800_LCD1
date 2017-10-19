#include "types.h"
#include "stm32f4xx.h"
#include "sys_delay.h"

static uchar fac_us = 0;
static ushort fac_ms = 0;

void Delay_Init(uchar sysclk){
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	
	fac_us = sysclk / 8;
	fac_ms = fac_us * 1000;
}

//nms <= 0xffffff * 8 * 1000 / sysclk
//120MHZ nms <= 1118ms = 1.118s
void Delay_Us(uint nus){
	uint tmp;
	SysTick->LOAD = nus * fac_us;
	SysTick->VAL	= 0x00;
	SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
	do{
			tmp = SysTick->CTRL;
	}while((tmp & 0x01) && !(tmp & (1 << 16)));
	SysTick->CTRL = ~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL 	= 0x00;
}

void Delay_Xms(ushort nms)
{
	uint temp;		   
	SysTick->LOAD = (uint) nms * fac_ms;			//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL = 0x00;           			//��ռ�����
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;          //��ʼ���� 
	do
	{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));	//�ȴ�ʱ�䵽��   
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;       //�رռ�����
	SysTick->VAL = 0x00;     		  		//��ռ�����	  
}

void Delay_Ms(ushort nms)
{
	uchar repeat=nms / 540;						//������540,�ǿ��ǵ�ĳЩ�ͻ����ܳ�Ƶʹ��,
											//���糬Ƶ��248M��ʱ��,delay_xms���ֻ����ʱ541ms������
	ushort remain = nms % 540;
	while(repeat)
	{
		Delay_Xms(540);
		repeat--;
	}
	if(remain)Delay_Xms(remain);
}





