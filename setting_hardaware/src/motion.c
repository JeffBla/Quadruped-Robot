#include "../include/motion.h"

void Motion_Init() {
    // Right front leg
    UART_ServoControl(1, -90, 100);
    UART_ServoControl(5, 90, 100);
    UART_ServoControl(9, -90, 100);
    __delay_ms(1000);
    // Right back leg
    UART_ServoControl(3, 30, 100);
    UART_ServoControl(7, -90, 100);
    UART_ServoControl(11, 90, 100);
    __delay_ms(1000);
    // Left front leg
    UART_ServoControl(32, 30, 100);
    UART_ServoControl(28, -90, 100);
    UART_ServoControl(24, 90, 100);
    __delay_ms(1000);
    // Left back leg
    UART_ServoControl(30, -90, 100);
    UART_ServoControl(26, 90, 100);
    UART_ServoControl(22, -90, 100);
    __delay_ms(1000);
}

void Motion_Stand() {
    // Right front leg
    UART_ServoControl(1, -60, 100);
    UART_ServoControl(5, 45, 100);
    UART_ServoControl(9, -55, 100);
    __delay_ms(1000);
    // Right back leg
    UART_ServoControl(3, -40, 100);
    UART_ServoControl(7, -55, 100);
    UART_ServoControl(11, 75, 100);
    __delay_ms(1000);
    // Left front leg
    UART_ServoControl(32, -40, 100);
    UART_ServoControl(28, -60, 100);
    UART_ServoControl(24, 50, 100);
    __delay_ms(1000);
    // Left back leg
    UART_ServoControl(30, -60, 100);
    UART_ServoControl(26, 35, 100);
    UART_ServoControl(22, -55, 100);
    __delay_ms(1000);
}

void Motion_Walk(int walk_state) {
    if (walk_state == 0) {
        Leg_WalkForwardup(1);
        Leg_WalkForwardDown(1);
        __delay_ms(1000);
        Leg_WalkForwardup(2);
        Leg_WalkForwardDown(2);
        __delay_ms(1000);
    } else if (walk_state == 1) {
        Leg_WalkBackwardDown(1);
        Leg_WalkBackwardDown(4);
        __delay_ms(1000);
    } else if (walk_state == 2) {
        Leg_WalkForwardup(3);
        Leg_WalkForwardDown(3);
        __delay_ms(1000);
        Leg_WalkForwardup(4);
        Leg_WalkForwardDown(4);
        __delay_ms(1000);
    } else if (walk_state == 3) {
        Leg_WalkBackwardDown(3);
        Leg_WalkBackwardDown(2);
        __delay_ms(1000);
    }
}

void Motion_Test() {
}

void Leg_WalkForwardup(int legId) {
    switch (legId) {
        case 1:
            // Right front leg
            UART_ServoControl(1, -30, 100);
            UART_ServoControl(5, 25, 100);
            UART_ServoControl(9, -55, 100);
            break;
        case 2:
            // Right back leg
            UART_ServoControl(3, -10, 100);
            UART_ServoControl(7, -35, 100);
            UART_ServoControl(11, 75, 100);
            break;
        case 3:
            // Left front leg
            UART_ServoControl(32, -70, 100);
            UART_ServoControl(28, -40, 100);
            UART_ServoControl(24, 50, 100);
            break;
        case 4:
            // Left back leg
            UART_ServoControl(30, -90, 100);
            UART_ServoControl(26, 15, 100);
            UART_ServoControl(22, -55, 100);
            break;

        default:
            break;
    }
    __delay_ms(200);
}

void Leg_WalkForwardDown(int legId) {
    switch (legId) {
        case 1:
            // Right front leg
            UART_ServoControl(1, -30, 100);
            UART_ServoControl(5, 45, 100);
            UART_ServoControl(9, -55, 100);
            break;
        case 2:
            // Right back leg
            UART_ServoControl(3, -10, 100);
            UART_ServoControl(7, -55, 100);
            UART_ServoControl(11, 75, 100);
            break;
        case 3:
            // Left front leg
            UART_ServoControl(32, -70, 100);
            UART_ServoControl(28, -60, 100);
            UART_ServoControl(24, 50, 100);
            break;
        case 4:
            // Left back leg
            UART_ServoControl(30, -90, 100);
            UART_ServoControl(26, 35, 100);
            UART_ServoControl(22, -55, 100);
            break;

        default:
            break;
    }
    __delay_ms(200);
}

void Leg_WalkBackwardDown(int legId) {
    switch (legId) {
        case 1:
            // Right front leg
            UART_ServoControl(1, -90, 100);
            UART_ServoControl(5, 45, 100);
            UART_ServoControl(9, -55, 100);
            break;
        case 2:
            // Right back leg
            UART_ServoControl(3, -70, 100);
            UART_ServoControl(7, -55, 100);
            UART_ServoControl(11, 75, 100);
            break;
        case 3:
            // Left front leg
            UART_ServoControl(32, -10, 100);
            UART_ServoControl(28, -60, 100);
            UART_ServoControl(24, 50, 100);
            break;
        case 4:
            // Left back leg
            UART_ServoControl(30, -30, 100);
            UART_ServoControl(26, 35, 100);
            UART_ServoControl(22, -55, 100);
            break;

        default:
            break;
    }
    __delay_ms(200);
}