#include <xc.h>
#include <string.h>
#include <pic18f4520.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "setting_hardaware/setting.h"
#define _XTAL_FREQ 1000000

char command[] = "#21P2500T5000\r\n";
char response[50];
int degree = -90;

void main() {
    

    SYSTEM_Initialize();

    //UART_Write_Text(command);

    INTCONbits.INT0IF = 0;
    INTCONbits.INT0IE = 1;
    INTCONbits.GIE = 1;
    
    TRISBbits.RB0 = 1;
    PORTB = 0;
    LATA = 0;
    TRISA = 0;
    ADCON1 = 15;
    
    while(1);
    return;
}

void __interrupt(high_priority) Hi_ISR(void)
{
    servoControl(1,-90,3000);
    servoControl(3,90,3000);
    __delay_ms(20000);
    servoControl(1,90,3000);
    //servoControl(3,90,3000);
    
    //degree+=10;
    LATA += 1;
    __delay_ms(500);
    INTCONbits.INT0IF = 0; 
}
