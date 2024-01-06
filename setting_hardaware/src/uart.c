#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
// setting TX/RX

char mystring[20];
int lenStr = 0;

void UART_Initialize() {
    /*       TODObasic
           Serial Setting
        1.   Setting Baud rate
        2.   choose sync/async mode
        3.   enable Serial port (configures RX/DT and TX/CK pins as serial port pins)
        3.5  enable Tx, Rx Interrupt(optional)
        4.   Enable Tx & RX
    */

    // UART ??
    TRISCbits.TRISC6 = 1;
    TRISCbits.TRISC7 = 1;

    //  Setting baud rate
    TXSTAbits.SYNC = 0;  //(TXSTA<4>):EUSART Mode Select bit, 0 -> async mode

    /* BRG16 -> (BAUDCON<3>): choose 16-bit or 8-bit baud rate register
     a. 16-bit: SPBRGH and SPBRG
     b. 8-bit: SPBRG only
     SPBRGH:SPBRG: control the period of a free-running timer
    */
    BAUDCONbits.BRG16 = 0;
    TXSTAbits.BRGH = 1;  //(TXSTA<2>):High Baud Rate Select bit
    SPBRG = 51;

    //   Serial enable
    // TRMT -> (TXSTA<7>): Read only, which is set when the TSR register is empty
    // TSR register: ???????
    // RSR register: ?????????
    // TXREG register: ?????????
    // RCREG register: ?????????
    RCSTAbits.SPEN = 1;  //(RCSTA<7>:Enable asynchronous port
    PIR1bits.TXIF = 0;   //(PIR1<4>):Set when TXREG is empty -> TXPEG ??????????
    PIR1bits.RCIF = 1;   //(RIR1<5>):will set when reception is complete
    TXSTAbits.TXEN = 1;  //(TXSTA<5>):enable transmission
    RCSTAbits.CREN = 1;  // continuous receive enable bit,will be cleared when error occurred
    PIE1bits.TXIE = 0;   //(PIE4):enable interrupt
    IPR1bits.TXIP = 1;
    PIE1bits.RCIE = 0;
    // IPR1bits.RCIP = 0;
}

void UART_Write(unsigned char data)  // Output on Terminal
{
    while (!TXSTAbits.TRMT)
        ;
    TXREG = data;  // write to TXREG will send data
}

void UART_Write_Text(char* text) {  // Output on Terminal, limit:10 chars
    for (int i = 0; text[i] != '\0'; i++)
        UART_Write(text[i]);
}

void ClearBuffer() {
    for (int i = 0; i < 10; i++)
        mystring[i] = '\0';
    lenStr = 0;
}

void UART_Read() {
    /* TODObasic: try to use UART_Write to finish this function */
    if (RCREG == '\r') {
        UART_Write('\n');
    } else {
        UART_Write(RCREG);
    }
    return;
}

char* UART_GetString() {
    return mystring;
}

void UART_ServoControl(int id, int degree, int speed) {
    char command[50];

    // mapping degree to pulse width
    //-90 ~ 90 degree -> 500 ~ 2500 us
    degree = 11 * degree + 1500;

    sprintf(command, "#%dP%dT%d\r\n", id, degree, speed);

    // sending command from pic to servo controller
    UART_Write_Text(command);
    return;
}
