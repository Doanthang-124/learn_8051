#include"..\lib\Uart.h"
#include"..\lib\delay.h"
#include <REGX52.H>




void main()
{
	char Data;
	//unsigned char i;
	Uart_Init();


	while(1)
	{
	  	Uart_Write_Text("Ki tu thuong nhap vao: ");
		while(Uart_Ready()==0);
		Data = Uart_Read_Mode1();
		Data = Data + 96;
		Uart_Write_Text("Ki tu thuong nhap vao: ");
		Uart_Write_Mode1(Data);
		
	}
}