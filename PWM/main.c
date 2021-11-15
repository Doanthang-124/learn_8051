#include <REGX52.H>

#define PWM_PIN  P2_0
unsigned int Ton, Toff, T;
unsigned char Ton_h_reload, Ton_l_reload, Toff_h_reload, Toff_l_reload;

void PWM_Init(unsigned int ck, unsigned duty)
{
	if( duty == 0)
	{
	 TR0 = 0;
	 PWM_PIN = 0;
	}
	else if( duty == 100)
	{
	TR0 = 0;
	PWM_PIN = 1;
	}
	else{
	PWM_PIN  = 1;
	
	TMOD &= 0x80; // timer 0 mode 1
	TMOD |= 0x01;

	ET0 = 1;
	EA = 1;

	T = ck;
	Ton = ((unsigned long)T) * duty/100;
	Toff = T - Ton;
	Ton_h_reload = (65536 - Ton)>>8;
	Ton_l_reload = 	(65536 - Ton)&0x00FF;
	Toff_h_reload = (65536 - Toff)>>8;
	Toff_l_reload =  (65536 - Toff)&0x00FF;


	TH0 = Ton_h_reload  ;
	TL0 = Ton_l_reload ;
	}
}
void PWM_Start()
{
	TR0 = 1;
}
void PWM_Stop()
{
	TR0 = 0;
}

void main()
{
	unsigned char i;
 	while(1)
 	{	 
 	   for( i = 0; i<= 100; i++)
	   	{
			PWM_Init(10000,i);
			PWM_Start();
		}
	}
}
void NgatOverloop(void) interrupt 1
{
	P2_0 = !P2_0;
	if(P2_0 == 0)
	 {
	 	TH0 = Toff_h_reload;
		TL0 = Toff_l_reload;
	 }
	else
	{
		TH0 =  Ton_h_reload;
		TL0 =  Ton_l_reload ;
	}
}