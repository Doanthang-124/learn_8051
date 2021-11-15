#include <REGX52.H>
#include"..\lib\delay.h"

#define LED  P0
#define LED1 P2_0
#define LED2 P2_1
#define LED3 P2_2
#define LED4 P2_3
#define LED5 P2_4

unsigned char code Code7Seg[]={ 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void Display(unsigned int digit)
{
	  // Chuc nghin
	  LED = Code7Seg[digit/10000] ;
	  LED1 = 0;
	  Delay_ms(1);
	  LED1 = 1;
	  digit %=10000; 
	  // nghin
	  LED  = Code7Seg[digit/1000] ;
	  LED2 = 0;
	  Delay_ms(1);
	  LED2 = 1;
	  digit %=1000;
	  // tram
	  LED  = Code7Seg[digit/100] ;
	  LED3 = 0;
	  Delay_ms(1);
	  LED3 = 1;
	   digit %=100;
	  // chuc
	  LED  = Code7Seg[digit/10] ;
	  LED4 = 0;
	  Delay_ms(1);
	  LED4 = 1;
	  // dvi
	  LED  = Code7Seg[digit%10] ;
	  LED5 = 0;
	  Delay_ms(1);
	  LED5 = 1;

}
void main()
{
	 unsigned char high , low;
	 unsigned int number;
	 TMOD &= 0xF0;	 // chon set timer 0, dem xung
	 TMOD |= 0x05;  
	 TR0   = 1;

	while(1)
	{
		high = TH0;
		low  = TL0;
		number = high;
		number <<= 8 ;
		number |= low ;
	 	Display(number);	
	}
}