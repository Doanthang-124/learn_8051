
#include"..\lib\Uart.h"
#include"..\lib\delay.h"





void main()
{
    Uart_Init();

	while(1)
	{
	  Uart_Write_Mode1('A');
	}
}