#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"
#include "Timer0.h"

unsigned char code Animition[] = {
	0x00,0x0E,0x1B,0x7F,0x7F,0x1B,0x0E,0x00,
	0x00,0x04,0x0C,0x18,0x7F,0x7F,0x1B,0x0E,
	0x00,0x08,0x0C,0x05,0x7F,0x7F,0x1E,0x0C,
	0xC0,0x00,0x41,0x22,0x1A,0x7C,0x7D,0x1A,
	0x00,0x60,0x61,0x12,0x0A,0x7E,0x7F,0x08,
	0x00,0x06,0x0E,0x08,0x0B,0x3E,0x3E,0x0B,
	0x00,0x03,0x0B,0x08,0x0B,0x3E,0x3E,0x0B,
	0x00,0x06,0x0E,0x08,0x09,0x3F,0x3E,0x0B,
	0x00,0x0E,0x13,0x7E,0x7E,0x1F,0x0E,0x00,
	0x08,0x13,0x7E,0x7E,0x12,0x1D,0x0C,0x00,
	0x09,0x12,0x7E,0x7F,0x10,0x13,0x03,0x00,
	0x09,0x12,0x7E,0x7F,0x10,0x1C,0x0C,0x00,
	0x00,0x0C,0x15,0x7E,0x7E,0x17,0x0E,0x00,
	0x00,0x30,0x38,0x0D,0x7E,0x7F,0x1D,0x08,
	0xC0,0xC0,0x30,0x1B,0x7C,0x7F,0x08,0x00,
	0x00,0x00,0x37,0xF8,0xFA,0x34,0x00,0x00,
	0x00,0x00,0x1B,0x7C,0x7C,0x1A,0x01,0x00,
	0x00,0x00,0x09,0x1E,0x7C,0x7F,0x18,0x00,
	0x00,0x00,0x1B,0x7C,0x7C,0x1B,0x00,0x00,
	0x00,0x00,0x09,0x1E,0x7C,0x7F,0x18,0x00,
	0x00,0x00,0x1B,0x7C,0x7C,0x1B,0x00,0x00,
	0x08,0x10,0x16,0x7C,0x7F,0x10,0x08,0x00,
	0x00,0x10,0x13,0x7C,0x7E,0x18,0x00,0x00,
	0x00,0x08,0x13,0x7C,0x7F,0x10,0x10,0x00,
	0x00,0x08,0x12,0xFC,0xFD,0x3A,0x00,0x00,
	0x00,0x08,0x12,0xFC,0xFC,0x22,0x10,0x00,
	0x00,0x00,0x61,0x12,0x7C,0x7F,0x10,0x60,
	0x00,0x00,0x20,0x11,0x12,0x7C,0x7E,0x19,
	0x00,0x00,0x00,0x31,0x0A,0x7C,0x7E,0x0D,
	0x00,0x00,0x20,0x11,0x12,0x7C,0x7E,0x19,
	0x00,0x00,0x00,0x31,0x0A,0x7C,0x7E,0x0D,
	0x00,0x00,0x20,0x11,0x12,0x7C,0x7E,0x19,
	0x00,0x00,0x00,0x31,0x0A,0x7C,0x7E,0x0D,
	0x00,0x00,0x20,0x11,0x12,0x7C,0x7E,0x19,
	0x00,0x00,0x00,0x31,0x0A,0x7C,0x7E,0x0D, 
	0x00,0x00,0x37,0x78,0xF8,0xB6,0x00,0x00,
	0x00,0x20,0x7f,0xf8,0xb4,0x02,0x01,0x00,
	0x00,0x00,0x19,0x3e,0x7c,0x54,0x03,0x00,
	0x00,0x00,0x01,0x02,0x1c,0x3c,0x7b,0x58,
	0x00,0x00,0x19,0x3e,0x7c,0x54,0x03,0x00,
	0x00,0x20,0x7f,0xf8,0xb4,0x02,0x01,0x00,
	0x00,0x00,0x23,0x7c,0xf8,0xb6,0x01,0x00,
	0x00,0x00,0x01,0x02,0x24,0x78,0xff,0xb0,
	0x00,0x20,0x7f,0xf8,0xb4,0x02,0x01,0x00,
	0x00,0x00,0x19,0x3e,0x7c,0x54,0x03,0x00,
	0x00,0x00,0x01,0x02,0x1c,0x3c,0x7b,0x58,
	0x00,0x00,0x19,0x3e,0x7c,0x54,0x03,0x00,
	0x00,0x20,0x7f,0xf8,0xb4,0x02,0x01,0x00,
	0x00,0x00,0x23,0x7c,0xf8,0xb6,0x01,0x00,
	0x00,0x00,0x01,0x02,0x24,0x78,0xff,0xb0,
	0x00,0x20,0x7f,0xf8,0xb4,0x02,0x01,0x00,
	0x00,0x00,0x19,0x3e,0x7c,0x54,0x03,0x00,
	0x00,0x00,0x01,0x02,0x1c,0x3c,0x7b,0x58,
	0x00,0x00,0x19,0x3e,0x7c,0x54,0x03,0x00,
	0x00,0x20,0x7f,0xf8,0xb4,0x02,0x01,0x00,
	0x00,0x00,0x23,0x7c,0xf8,0xb6,0x01,0x00,
	0x00,0x00,0x01,0x02,0x24,0x78,0xff,0xb0
};
unsigned int Offset;


void main ()
{
	unsigned char i;
	MatrixLED_Init();
	Timer0_Init();
	while(1)
	{
		for(i = 0;i < 8;i++)
		{	
			MatrixLED_ShowColumn(i, Animition[i + Offset]);	//0 0 1 1 1 1 0 0
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count >= 100)
	{
		T0Count = 0;
		if(Offset >= 456) 
		{	
			Offset = 0;
		}
		else
		{
			Offset = Offset + 8 ;
		}
	}
}