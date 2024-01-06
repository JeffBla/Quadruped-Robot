#ifndef _UART_H
#define _UART_H

void UART_Initialize(void);

char* UART_GetString();

void UART_Write(unsigned char data);

void UART_Write_Text(char* text);

void UART_ClearBuffer();

void UART_Read();

void UART_ServoControl(int id, int degree, int speed);

#endif