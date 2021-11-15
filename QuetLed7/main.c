#include <REGX51.H>
#include"..\lib\delay.h"

#define Led P3
#define Led1_PIN P2_0
#define Led2_PIN P2_1

unsigned char code Code7Seg[]={ 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void main()
{
	unsigned int i,j;
	while(1)
	{
		for(i = 0; i<100; i++)
		{
			for(j = 0; j < 500; j++)
			{
				Led =  Code7Seg[i/10];
				Led1_PIN = 0;
				Delay_ms(1);
				Led1_PIN = 1;
	
				Led = Code7Seg[i%10];
				Led2_PIN = 0;
				Delay_ms(1);
				Led2_PIN = 1;
			}
		}	
	}
}