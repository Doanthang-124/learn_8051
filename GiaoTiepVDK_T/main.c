
#include"..\lib\Uart.h"
#include"..\lib\delay.h"
sbit TI1=0xC0;

#define SW P1_0
char *str1 = "Normal Speed";

void Uart_Write_Text1( char *str)
{
unsigned char i;
while(str[i]!=0)
{
	 while(TI == 0);
	 TI = 0;
	 SBUF = str[i];
	 i++;
}
}

void main()
{
	unsigned char i;

	//SM0 = 0; // set mode 1 UART
	//SM1 = 1; //	 set mode 1 UART
	TMOD &= 0x0F;
	TMOD |= 0x20; // thiet lap che do 8 bit tu dong nap la
	//PCON |=0x80;
	//TI = 1;	// san sang nhan du lieu
		TH1 = 0xFA;
	SCON = 0x50; 
	TI = 1;

	TR1 = 1;
	
	   while(1)
	   {

		for( i = 0; i<12; i++)
		{
		SBUF = str1[i];
		while(TI == 0);
		TI =0;
		}
		}



}