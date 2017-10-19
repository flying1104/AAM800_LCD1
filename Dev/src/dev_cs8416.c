#include "types.h"
#include "sys_delay.h"
#include "dev_i2c.h"
#include "dev_cs8416.h"

static uchar cs8416_inittab[]={
    // reg mask val
	0x00,0xff,0x00,
	0x01,0xff,0x84,
	0x02,0xff,0x00,
	0x03,0xff,0x00,
//	0x04,0xff,0x40,
	0x05,0xff,0x05,
//	0x06,0xff,0x00,
//	0x07,0xff,0x00,
//	0x08,0xff,0x00,
//  0x09,0xff,0x00,
  0x04,0xff,0x80,
	0xff,0xff,0xff
};

void Cs8416_Init(void)
{
//	IIC_Write(CS8416_ADDR, 0x07, 0x03);
//	Delay_Ms(10);
	IIC_Module_Init(cs8416_inittab, CS8416_ADDR);
}

uchar Cs8416_Rd(uchar addr)
{
	uchar data;
	data = IIC_Read(CS8416_ADDR, addr);  
	return (data);
}

void Cs8416_Wr(uchar addr, uchar data)
{
	IIC_Write(CS8416_ADDR, addr, data);
}







