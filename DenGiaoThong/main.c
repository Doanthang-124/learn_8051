#include <REGX51.H>
#include <stdio.h>
#include <stdlib.h>


#define LED P3
#define LED1 P2_0
#define LED2 P2_1
#define LED3 P2_2
#define LED4 P2_3

#define btn_up P1_0
#define btn_down P1_1
#define btn_random	P1_2


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

unsigned int random()
{
		return rand()%10000;
}

void main()			  	
{
	unsigned int i=0,j=0;
	unsigned char status = 1;
	
	while(1	)
	{	
		for(j=0 ;j<80;j++)
		{				
		Display(i);
		}
		if(btn_up == 0)
		 { Delay_ms(20);
		  if(btn_up == 0)
		  {
		    status = 1;
			while(btn_up==0);
		   }
		  }
		if(btn_down == 0)
		 { Delay_ms(20);
		  if(btn_down == 0)
		  {
		    status = 0;
			while(btn_down ==0);
		   }
		  }
		 if(btn_random == 0)
		 { Delay_ms(20);
		  if(btn_random == 0)
		  {
		    status = 3;
			while(btn_random ==0);
		   }
		  }
		if(status == 1)
		 i++;
		else if(status == 0)
		 i--;
		else 
		  i = random();
		if(i < 0 ||i > 1000)
		 i == 0;

	}
}