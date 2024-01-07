#include "../include/adc.h"

#include <xc.h>

int nChannel = 3;

void ADC_Initialize(bool isINT) {
    TRISA = 0xff;             // Set as input port
    ADCON1 = 0x0d;            // Ref vtg is VDD & Configure pin as analog pin
    ADCON2bits.ADFM = 0;      // Left Justifie
    ADCON2bits.ADCS = 1;      // Clock conversion FOSC/8 T_AD = 1 us
    ADCON2bits.ACQT = 0b010;  // Acquition time 4 TAD
    ADRESH = 0;               // Flush ADC output Register
    ADRESL = 0;

    if (isINT) {
        PIR1bits.ADIF = 0;  // Clear ADC Interrupt flag
        IPR1bits.ADIP = 0;  // Enable ADC interrupt in low priority
        PIE1bits.ADIE = 1;  // Enable ADC Interrupt
    }
}

int ADC_Read(int channel) {
    int digital;

    ADCON0bits.CHS = channel;  // Select Channel
    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;

    while (ADCON0bits.GO_nDONE == 1)
        ;

    digital = ADRESH;
    return (digital);
}

/**
 * @brief use this function to start ADC conversion with INT
 *
 * @param channel
 */
void ADC_GO(int channel) {
    ADCON0bits.CHS = channel;  // Select Channe0
    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;
}

int ADC_FindServoId(int channel) {
    switch (channel) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 9;
        default:
            return 0;
    }
}

void ADC_NextChannel() {
    ADCON0bits.CHS = (ADCON0bits.CHS + 1) % nChannel;
    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;
}