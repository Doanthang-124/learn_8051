#include <REGX51.H>
#include "../lib/delay.h"

unsigned char code M[10][7]={{0x0E,0x11,0x13,0x15,0x19,0x11,0x0E}, // Font cua so 0
   {0x1F, 0x04, 0x04, 0x04, 0x14, 0x0C, 0x04}, // Font cua so 1
   {0x1F, 0x08, 0x04, 0x02, 0x01, 0x11, 0x0E},
   {0x0E, 0x11, 0x01, 0x06, 0x01, 0x11, 0x0E},
   {0x02, 0x1F, 0x12, 0x08, 0x04, 0x02, 0x01},
   {0x1E, 0x01, 0x01, 0x01, 0x1E, 0x10, 0x1F},
   {0x0E, 0x11, 0x11, 0x1E, 0x10, 0x11, 0x0E},
   {0x04, 0x04, 0x04, 0x02, 0x01, 0x01, 0x1F},
   {0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E},
   {0x0E, 0x01, 0x01, 0x0F, 0x11, 0x11, 0x0E}};

void main()
{
	unsigned char i,n, dem;

	
	while(1)
	{
	for( dem = 0; dem < 10; dem++)
		for(n = 0; n < 142; n++)
				for(i = 0; i < 7; i++)
				{
					P0 = M[dem][i];
					P3 = (0x01)<<i;
					Delay_ms(1);
					P3 = 0x00;
				}	

	}
}