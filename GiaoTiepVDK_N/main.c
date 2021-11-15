#include"..\lib\Uart.h"

void main()
{

	Uart_Init();
	
	while(1)
	{
		if(Uart_Ready() == 1)
		{
		 P1 = Uart_Read_Mode1();
		}	
	}
}