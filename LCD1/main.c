
#include"..\lib\delay.h"
#include"..\lib\LCD_8bit.h"




void main()
{

		LCD_Init_8bit();
		LCD_char_CP(0xE0);
		LCD_char_str(2,2,"I LOVE YOU");
		

	//	LCD_cmd(0x1C);   // dich sang phai
	//	LCD_cmd(0x02); // return lai vi tri ban dau
	
	
		
	while(1)
	{
	
	}
}