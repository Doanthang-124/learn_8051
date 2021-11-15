#include"Uart.h"

void Uart_Init()
{
	SM0 = 0; // set mode 1 UART
	SM1 = 1; //	 set mode 1 UART
	TMOD &= 0x0F;
	TMOD |= 0x20; // thiet lap che do 8 bit tu dong nap lai
	
	TH1 = 0xFA; // Thiet lap toc do baund 9600
	TR1 = 1; // cho phep dem xung
	TI = 1;	// san sang nhan du lieu
	REN = 1; // cho phep nhan du lieu
}
void Uart_Write_Mode1(char c)
{
	while( TI == 0);
	TI = 0;
	SBUF = c;
}
void Uart_Write_Text(char *str)
{
	 char i;
	while(str[i]!= 0)
	{
		Uart_Write_Mode1(str[i]);
		i++;
	}
}
bit Uart_Ready()
{
	return RI;
}
char Uart_Read_Mode1()
{
	RI = 0;
	return SBUF;
}