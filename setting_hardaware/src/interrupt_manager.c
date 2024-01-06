#include <stdio.h>
#include <xc.h>

#define _XTAL_FREQ 8000000

void INTERRUPT_Initialize(void) {
    // INT0
    // TRISBbits.RB0 = 1;
    // INTCONbits.INT0IE = 1;
    // INTCONbits.INT0IF = 0;

    // Global
    RCONbits.IPEN = 1;    // enable Interrupt Priority mode
    INTCONbits.GIEH = 1;  // enable high priority interrupt
    INTCONbits.GIEL = 1;  // disable low priority interrupt
}

void __interrupt(high_priority) Hi_ISR(void) {
    if (INTCONbits.INT0IF) {
        __delay_ms(500);
        INTCONbits.INT0IF = 0;
    } else if (PIR1bits.TMR1IF) {
        TMR1Run(0x00, 0x00);
        PIR1bits.TMR1IF = 0;
    }
}

void __interrupt(low_priority) Low_ISR(void) {
    if (PIR1bits.ADIF) {
        int value = ADRESH;  // left justified
        value = (value * 180) / 255 - 90;

        int servoId = AdcFindServoId(ADCON0bits.CHS);
        servoControl(servoId, value, 3000);

        // You need to have a minimum wait of 2 T_AD before next acquisition start,
        // then go back to step 3.
        __delay_us(2);
        NextChannel();
        PIR1bits.ADIF = 0;
    }
}
