#include <REGX51.H>
#include"..\lib\delay.h"

#define BTN P1_0
#define LED P2

void KT()
{
	unsigned char i;
	for(i = 0; i< 50; i++)
	{
		Delay_ms(10);
		if( BTN == 0)
		{
		 Delay_ms(20);
		 if(BTN == 0)
		  { break;
		   while(BTN == 0);
		  }
		}

	}
}

void main()
{
 unsigned char i;
 LED = 0x00;
 while(1)
 {
 	for(i = 0; i < 8 ; i++)
	{
		LED = ~LED;
	    KT();
	}
	LED = 0x01;	
	for(i = 0; i < 8; i++)
	{
	 	LED = LED << 1;
		KT();
	}
	for(i = 0; i < 8; i++)
	{
	 	LED = (LED >> 1)|(0x80);
		KT();
	}
 }
}