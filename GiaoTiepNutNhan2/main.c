#include <REGX51.H>
#include"..\lib\delay.h"

#define START_BTN P1_0
#define STOP_BTN P1_1
#define LED P0
unsigned char KiemTraVaQuetPhim()
{
	unsigned char i;
	for(i = 0; i < 100 ; i++)
	{
		Delay_ms(10);
		if(STOP_BTN == 0)
		{
		 LED = 0x00;
		 return 1;
		}
	}
	return 0;
}
void main()
{	

	LED = 0x00;
	while(1)
	{
		if(START_BTN == 0)
		{
			while(1)
			{
				LED = ~LED;
				if(KiemTraVaQuetPhim())
				 break;

			}
		}
	}
}