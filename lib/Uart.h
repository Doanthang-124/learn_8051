#ifndef _UART_H_
#define _UART_H_

#include <REG51.H>
void Uart_Init();
void Uart_Write_Mode1(char c);
void Uart_Write_Text(char *str);
bit  Uart_Ready();
char Uart_Read_Mode1();

#endif
