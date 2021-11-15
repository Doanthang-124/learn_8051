#include <REGX51.H>
#include"..\lib\delay.h"

void Uart_Mode0(unsigned char cmd)
{
	 SBUF = cmd;

	while(TI == 0);
	TI = 0;

	P3_2 = 0;
	P3_2 = 1;
}
void main()
{	
	unsigned char i;	   
	SM0 = SM1 = 0; // Uart_Mode 0	
	while(1)
	{
	for(i = 0; i<10 ; i++)
	{
		Uart_Mode0(0x00);
		Delay_ms(1000);
		Uart_Mode0(0xff);
		Delay_ms(500);
	}	
	}
}