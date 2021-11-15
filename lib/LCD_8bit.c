#include "LCD_8bit.h"
#include "delay.h"

void LCD_char_c(unsigned char row, unsigned char col,unsigned char c)
{
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	LCD_cmd(cmd);

	LCD_char_CP(c);
}
void LCD_cmd(unsigned char cmd)
{
	RS = 0;		// gui lenh
	LCD = cmd;
	E = 0;
	E = 1;
	if( cmd <= 0x02)
	{
		Delay_ms(2);
	} 
	else
	{
		Delay_ms(1);
	}
}
void LCD_Init_8bit()
{
	LCD_cmd(0x30);
	Delay_ms(5);
	LCD_cmd(0x30);
	Delay_ms(1);
	LCD_cmd(0x30);

	LCD_cmd(0x38);	 // chon so dong hien thi , font hien thi
	LCD_cmd(0x01);	  // xoa noi dung hien thi
	LCD_cmd(0x0C); 	  // bat hien thi va tat con tro

}

void LCD_Init_4bit()
{
	LCD_cmd(0x30);
	Delay_ms(5);
	LCD_cmd(0x30);
	Delay_ms(1);
	Delay_ms(0x30);

	LCD_cmd(0x30);
	LCD_cmd(0x30);
	LCD_cmd(0xf0);
	LCD_cmd(0x00);
	LCD_cmd(0x80);
	LCD_cmd(0x00);
	LCD_cmd(0x10);


}
void LCD_char_CP( char Data)
{
	RS = 1;		// gui du lieu
	LCD = Data;
	E = 0;
	E = 1;
	Delay_ms(1);
}
void LCD_char(char *str)
{
	unsigned char i = 0;
	while(str[i]!= 0)
	{
		LCD_char_CP(str[i]);
		i++;
	}
}
void LCD_char_str(unsigned char row, unsigned char col, char *str)
{
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	LCD_cmd(cmd);

	LCD_char(str);
}
