#include <REGX51.H>

#define X1 P2_0
#define V1 P2_1
#define D1 P2_2
#define X2 P2_3
#define V2 P2_4
#define D2 P2_5

void Delay_ms(unsigned int t)
{
	unsigned int x,y;
	for(x = 0; x  <t; x++)
	{
	 for(y = 0; y < 123; y++);
	}
}
void main()
{

	P2 = 0x00;

	while(1)
	{
		X1 = 1;
		D2 = 1;
		V1 = D1 = V2 = X2 = 0;
		Delay_ms(25000);

		V1 = 1;
		X1 = 0;
		Delay_ms(5000);

		D1 = 1;
		V2 = 1;
		V1 = 0;
		D2 = 0;
		Delay_ms(5000);

		X2 = 1;
		V2 = 0;
		Delay_ms(25000);

	}
}
