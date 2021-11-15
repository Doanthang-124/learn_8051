
#include <REGX51.H>
#include"..\lib\delay.h"

#define On P1_0
#define Off P1_1
#define Led P0

void main()
{
	Led = 0x00;
	On = 1;
	while(1)
	{
		if(On == 0)
		{
		 	Delay_ms(20); // chong doi phim
			if(On == 0)	 // kiem tra lai mot lan nua
			{
			Led = ~ Led;
			while(On == 0);	// dung cho toi khi nut nhan duoc nha ra
			}
		} 
	}
}