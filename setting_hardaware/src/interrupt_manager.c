#include "../include/interrupt_manager.h"

#include <stdio.h>
#include <xc.h>

void INTERRUPT_Initialize(void) {
     // INT0
     TRISBbits.RB0 = 1;
     INTCONbits.INT0IE = 1;
     INTCONbits.INT0IF = 0;

    // Global
    RCONbits.IPEN = 1;    // enable Interrupt Priority mode
    INTCONbits.GIEH = 1;  // enable high priority interrupt
    INTCONbits.GIEL = 1;  // disable low priority interrupt
}

void __interrupt(high_priority) Hi_ISR(void) {
    if (INTCONbits.INT0IF) {
        isWalk = !isWalk; 
        
        __delay_ms(500);
        INTCONbits.INT0IF = 0;
    } 
}

void __interrupt(low_priority) Low_ISR(void) {
    if (PIR1bits.ADIF) {
        int value = ADRESH;  // left justified
        int result = (value * 180) / 255 - 90;

        int servoId = ADC_FindServoId(ADCON0bits.CHS);
        if (servoId != 0) {
            UART_ServoControl(servoId, result, 100);
            __delay_ms(100);
        }

        // You need to have a minimum wait of 2 T_AD before next acquisition start,
        // then go back to step 3.
        __delay_us(2);
        ADC_NextChannel();
        PIR1bits.ADIF = 0;
    }
}
