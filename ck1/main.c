#include <REGX51.H>
int i, a;
sbit LED = P2^0;
sbit START = P1^0; 

void Delay_ms(unsigned int t)
{
	unsigned int x,y;
	for(x = 0; x <t; x++)
	{
	 for(y = 0; y < 123; y++);
	}
}

void main(void)
{ 
	int i;
	while (1) 
	{ 
	START = 1;
	if (START == 0)
	{ 
		
		LED = 0;
		for( i = 0; i < 6; i++)
		{
		LED = ~LED;
		Delay_ms(500);
		}
	}
	else
	{
		LED = 0;
	}
	}
}

//void main(void)
//{ 
//	while (1) 
//	{ 
//	START = 1;
//	a = START;
//	if (START == 0)
//	{ 
//		LED = 1;
//		Delay_ms(200);
//	}
//	else
//	{
//		LED = 0;
//		Delay_ms(200);
//	}
//	}
//}
