#include <REGX51.H>


#define LED_GIO P0
#define LED_PHUT P1
#define LED_GIAY P3

#define LED1_PIN P2_0
#define LED2_PIN P2_1
#define LED3_PIN P2_2
#define LED4_PIN P2_3
#define LED5_PIN P2_4
#define LED6_PIN P2_5

unsigned char code Code7Seg[]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void Delay_ms (unsigned int t) {
	
	unsigned int x, y;
	
	for (x = 0; x < t; x++)
	{
		for (y = 0; y < 123; y++);
	}
	
}

void main()
{
	unsigned long GIO,PHUT,GIAY,i;
	GIO  = 0;
	PHUT = 0;
	GIAY = 0;
	while(1)
	{
     	//GIO
		for(i = 0; i< 166; i++)
		{
			 LED_GIO =  Code7Seg[GIO/10];
			 LED1_PIN = 0;
			 Delay_ms(1);
			 LED1_PIN = 1;
	
			 LED_GIO =  Code7Seg[GIO%10];
			 LED2_PIN = 0;
			 Delay_ms(1);
			 LED2_PIN = 1;
			 //PHUT
			 LED_PHUT =  Code7Seg[PHUT/10];
			 LED3_PIN = 0;
			 Delay_ms(1);
			 LED3_PIN = 1;
		 

			 LED_PHUT =  Code7Seg[PHUT%10];
			 LED4_PIN = 0;
			 Delay_ms(1);
			 LED4_PIN = 1;
		 //GIAY
			 LED_GIAY =  Code7Seg[GIAY/10];
			 LED5_PIN = 0;
			 Delay_ms(1);
			 LED5_PIN = 1;
	
			 LED_GIAY =  Code7Seg[GIAY%10];
			 LED6_PIN = 0;
			 Delay_ms(1);
			 LED6_PIN = 1;
		}		
		 GIAY++;
		 if(GIAY == 60)
		 {
		  	PHUT++;
			GIAY = 0;
		 }
		 if(PHUT == 60)
		 {
		   	GIO++;
			PHUT = 0;
		 }

	}
}

