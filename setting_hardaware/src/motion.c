#include "../include/motion.h"

void Stand() {
    // Right front leg
    UART_ServoControl(1, -60, 100);
    UART_ServoControl(5, 50, 100);
    UART_ServoControl(9, -50, 100);
    __delay_ms(1000);
    // Right back leg
    UART_ServoControl(3, -40, 100);
    UART_ServoControl(7, -48, 100);
    UART_ServoControl(11, -2, 100);
    __delay_ms(1000);
    // Left front leg
    UART_ServoControl(32, -40, 100);
    UART_ServoControl(28, -64, 100);
    UART_ServoControl(24, -18, 100);
    __delay_ms(1000);
    // Left back leg
    UART_ServoControl(30, -50, 100);
    UART_ServoControl(26, -4, 100);
    UART_ServoControl(22, -28, 100);
    __delay_ms(1000);
}
