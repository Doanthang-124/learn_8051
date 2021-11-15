#include <REGX51.H>
#include"..\lib\delay.h"

#define LED P2
// code co y nghia de luu ma trong bo nho chuong trinh (ROM) cua vdk vi bo nho du lieu Ram rat it
unsigned char code Code7Seg[]={ 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


void main()
{
	unsigned char i;
	while(1)
	{
	 for(i = 0; i < 10; i++)
	  {
	  	LED = Code7Seg[i];
		Delay_ms(500);
	  }
		
	}
}