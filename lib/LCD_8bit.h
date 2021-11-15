#ifndef _LCD_8BIT_H_
#define _LCD_8BIT_H_
#include <REGX51.H>
#define RS P2_0
#define E P2_1
#define LCD P3

void LCD_char_c(unsigned char row, unsigned char col,unsigned char c);
void LCD_cmd(unsigned char cmd);
void LCD_Init_8bit();
void LCD_Init_4bit();
void LCD_char_CP( char Data);
void LCD_char(char *str);
void LCD_char_str(unsigned char row, unsigned char col, char *str);
#endif