#include <pic18f4520.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>

#include "setting_hardaware/include/motion.h"
#include "setting_hardaware/include/setting.h"

// command example: #21P2500T5000\r\n

void main() {
    SYSTEM_Initialize();

    Stand();
    
    //    UART_ServoControl(1, -90, 100);
    //    UART_ServoControl(5, 50, 100);
    //    UART_ServoControl(9, -50, 100);
    //    __delay_ms(2000);
    //    UART_ServoControl(1, 75, 100);

    while (1)
        ;
    return;
}
