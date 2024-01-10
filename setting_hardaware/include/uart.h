#ifndef _UART_H
#define _UART_H

#include "config.h"

void UART_Initialize(void);

char* UART_GetString();

void UART_Write(unsigned char data);

void UART_Write_Text(char* text);

void UART_ClearBuffer();

void UART_Read();

void UART_ServoControl(int legid, int servoid, int degree, int speed);

void uart_servoControl(int id, int degree, int speed);

#endif