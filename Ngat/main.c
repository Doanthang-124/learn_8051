#include <REGX51.H>
#include"..\lib\delay.h"
#include"port.h"




void main()
{
	IT1 = 1; // cho phep ngat  canh xuong
	EX1 = 1; // cho phep ngat ngoai 1
	EA = 1; // cho phep ngat toan cuc

	LED1 = LED2 = LED3 = LED4 = 0;
	while(1)
	{
	 	 PCON |= 0x01; // dua vdk vao trang thai nghi
	}
}
void EX1_IR(void) interrupt	2
{
 	Delay_ms(20); // chong doi phim
	if(!BTN1)
	{
		LED1 = !LED1;
		while(!BTN1);
	}
	if(!BTN2)
	{
		LED2 = !LED2;
		while(!BTN2);
	}
	if(!BTN3)
	{
		LED3 = !LED3;
		while(!BTN3);
	}
	if(!BTN4)
	{
		LED4 = !LED4;
		while(!BTN4);
	}

}							 