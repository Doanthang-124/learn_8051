#include <REGX51.H>
#define LED P2

void Delay_ms(unsigned int t)
{
	unsigned int x,y;
	for(x = 0; x <t; x++)
	{
	 for(y = 0; y < 123; y++);
	}
}

void main()
{																																																																																																																																																
 	unsigned char i;
	// dich bit sang phai
     char b = 0x80;
	
	while(1)
	{
	// dao trang thai port
	LED = 0xff;
	for(i = 0; i<5; i++)
	{
		LED = ~ LED;
	 	Delay_ms(500);	
	}
	// dich bit sang trai
	LED = 0x01;
    Delay_ms(500);
	for(i = 0 ; i<7; i++)
	{
		LED = LED << 1;
	 	Delay_ms(500);	
	}
	// dich bit sang phai
	for(i = 0 ; i<7; i++)
	{
		LED = LED >> 1;
	 	Delay_ms(500);	
	}
	for(i = 0 ; i<7; i++)
	{
		b = b >> 1;
		Delay_ms(500);
		LED = b;
	 	Delay_ms(500);	
	}  
	LED = 0x01;
	Delay_ms(500);
	// set 1 bit bang phep or
	for(i = 0 ; i<7; i++)
	{
	 	LED = (LED<<1)|(0x01);
		Delay_ms(500);
	}	
	 
	}
}				   	