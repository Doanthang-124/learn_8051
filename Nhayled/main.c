#include <REGX51.H>
#include"..\lib\delay.h"

#define Led P0


void main()
{	
	unsigned char i;
	// dich bit sang phai
     char b = 0x80;
	
	while(1)
	{
	// dao trang thai port
	Led = 0xff;
	for(i = 0; i<5; i++)
	{
		Led = ~ Led;
	 	Delay_ms(500);	
	}
	// dich bit sang trai
	Led = 0x01;
	Delay_ms(500);
	for(i = 0 ; i<7; i++)
	{
		P0 = P0 << 1;
	 	Delay_ms(500);	
	}
	// dich bit sang phai
	for(i = 0 ; i<7; i++)
	{
		P0 = P0 >> 1;
	 	Delay_ms(500);	
	}
	for(i = 0 ; i<7; i++)
	{
		b = b >> 1;
		Delay_ms(500);
		Led = b;
	 	Delay_ms(500);	
	}  
	Led = 0x01;
	Delay_ms(500);
	// set 1 bit bang phep or
	for(i = 0 ; i<7; i++)
	{
	 	Led = (Led<<1)|(0x01);
		Delay_ms(500);
	}
	
	 
	}
}