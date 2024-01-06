#include <pic18f4520.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>

#include "setting_hardaware/include/setting.h"
#define _XTAL_FREQ 8000000

// command example: #21P2500T5000\r\n
int degree = -90;

void main() {
    SYSTEM_Initialize();

    servoControl(5, 50, 3000);
    servoControl(9, 50, 3000);
    __delay_ms(3000);
    servoControl(1, 75, 3000);

    while (1)
        ;
    return;
}
