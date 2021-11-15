#include <REGX51.H>

#define LED P3

#define LED1 P2_0
#define LED2 P2_1
#define LED3 P2_2
#define LED4 P2_3

unsigned char code Code7Seg[]={ 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void Delay_ms (unsigned int t) {
	
	unsigned int x, y;
	
	for (x = 0; x < t; x++)
	{
		for (y = 0; y < 123; y++);
	}
	
}

void Display(unsigned int digit)
{
	  // nghin
	  LED  = Code7Seg[digit/1000] ;
	  LED1 = 0;
	  Delay_ms(1);
	  LED1 = 1;
	  digit %=1000;
	  // tram
	  LED  = Code7Seg[digit/100] ;
	  LED2 = 0;
	  Delay_ms(1);
	  LED2 = 1;
	   digit %=100;
	  // chuc
	  LED  = Code7Seg[digit/10] ;
	  LED3 = 0;
	  Delay_ms(1);
	  LED3 = 1;
	  // dvi
	  LED  = Code7Seg[digit%10] ;
	  LED4 = 0;
	  Delay_ms(1);
	  LED4 = 1;

}

void main()			  	
{
	unsigned int i=0,j=0;
	

	  for(i = 0; i <147; i++)
       {
		for(j=0 ;j<1;j++)
		{				
		Display(i);
		if(i==146)
		 while(1)
		 {
		 		Display(i);
		 }
		}
	  }


}