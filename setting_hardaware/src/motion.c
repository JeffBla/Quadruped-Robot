#include "../include/motion.h"

void Motion_Init() {
    // Right front leg
    UART_ServoControl(RFLEG, UPSER, -90, 100);
    UART_ServoControl(RFLEG, MIDSER, -90, 100);
    UART_ServoControl(RFLEG, DOWNSER, -90, 100);
    __delay_ms(delaytime);
    // Right back leg
    UART_ServoControl(RBLEG, UPSER, -30, 100);
    UART_ServoControl(RBLEG, MIDSER, -90, 100);
    UART_ServoControl(RBLEG, DOWNSER, -90, 100);
    __delay_ms(delaytime);
    // Left front leg
    UART_ServoControl(LFLEG, UPSER, -30, 100);
    UART_ServoControl(LFLEG, MIDSER, -90, 100);
    UART_ServoControl(LFLEG, DOWNSER, -90, 100);
    __delay_ms(delaytime);
    // Left back leg
    UART_ServoControl(LBLEG, UPSER, -90, 100);
    UART_ServoControl(LBLEG, MIDSER, -90, 100);
    UART_ServoControl(LBLEG, DOWNSER, -90, 100);
    __delay_ms(delaytime);
}

void Motion_Stand() {
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            UART_ServoControl(i, j, 45, 100);
        }
        __delay_ms(delaytime);
    }
}


void Leg_Enlong(int legId){
    UART_ServoControl(legId, MIDSER, angle_mid_long, 100);
    UART_ServoControl(legId, DOWNSER, angle_down_long, 100);
}

void Leg_Shorten(int legId){
    UART_ServoControl(legId, MIDSER, angle_mid_short, 100);
    UART_ServoControl(legId, DOWNSER, angle_down_short, 100);
}

void Leg_EnlongLift(int legId){
    UART_ServoControl(legId, MIDSER, angle_mid_long_lift, 100);
    UART_ServoControl(legId, DOWNSER, angle_down_long_lift, 100); 
}

void Leg_ShortenLift(int legId){
    UART_ServoControl(legId, MIDSER, angle_mid_short_lift, 100);
    UART_ServoControl(legId, DOWNSER, angle_down_short_lift, 100);
}

void Motion_WalkInit(){
    UART_ServoControl(RFLEG, UPSER, angle_up_small, 100);
    UART_ServoControl(RBLEG, UPSER, angle_up_small, 100);
    UART_ServoControl(LFLEG, UPSER, angle_up_big, 100);
    UART_ServoControl(LBLEG, UPSER, angle_up_big, 100);

    Leg_Shorten(RFLEG);
    Leg_Shorten(RBLEG);
    Leg_Shorten(LFLEG);
    Leg_Shorten(LBLEG);
    __delay_ms(delaytime);
}

void Motion_Walk(int state) {
    switch(state)
    {
        case 0:
        {
            // lift
            Leg_EnlongLift(RBLEG);
            __delay_ms(delaytime);
            UART_ServoControl(RBLEG, UPSER, angle_up_small, 100);
            __delay_ms(delaytime);
            Leg_Shorten(RBLEG);
            __delay_ms(delaytime);
        }
        break;
        case 1:
        {
            // lift
            Leg_ShortenLift(RFLEG);
            __delay_ms(delaytime);
            // down
            UART_ServoControl(RFLEG, UPSER, angle_up_big, 100);

            Leg_EnlongLift(RFLEG);
            __delay_ms(delaytime);

            Leg_Enlong(RFLEG);
            __delay_ms(delaytime);
        }
        break;
        case 2:
        {
            // pull
            Leg_Shorten(RFLEG);

            UART_ServoControl(RBLEG, UPSER, angle_up_big, 100);

            UART_ServoControl(LFLEG, UPSER, angle_up_small, 100);

            // push
            Leg_Enlong(LBLEG);

            __delay_ms(delaytime);
        }
        break;
        case 3:
        {
            // lift
            Leg_EnlongLift(LBLEG);
            __delay_ms(delaytime);
            UART_ServoControl(LBLEG, UPSER, angle_up_small, 100);
            __delay_ms(delaytime);
            Leg_Shorten(LBLEG);
            __delay_ms(delaytime);
        }
        break;
        case 4:
        {
            // lift
            Leg_ShortenLift(LFLEG);
            __delay_ms(delaytime);
            // down
            UART_ServoControl(LFLEG, UPSER, angle_up_big, 100);

            Leg_EnlongLift(LFLEG);
            __delay_ms(delaytime);

            Leg_Enlong(LFLEG);
            __delay_ms(delaytime);
        }
        break;
        case 5:
        {
            // pull
            Leg_Shorten(LFLEG);

            UART_ServoControl(RFLEG, UPSER, angle_up_small, 100);

            UART_ServoControl(LBLEG, UPSER, angle_up_big, 100);

            // push
            Leg_Enlong(RBLEG);

            __delay_ms(delaytime);
        }
        break;
    }
}



void Motion_Walk_Old(int walk_state) {
    if (walk_state == 0) {
        Leg_WalkForwardup(1);
        Leg_WalkForwardDown(1);
        __delay_ms(delaytime);
        Leg_WalkForwardup(2);
        Leg_WalkForwardDown(2);
        __delay_ms(delaytime);
    } else if (walk_state == 1) {
        Leg_WalkBackwardDown(1);
        Leg_WalkBackwardDown(4);
        __delay_ms(delaytime);
    } else if (walk_state == 2) {
        Leg_WalkForwardup(3);
        Leg_WalkForwardDown(3);
        __delay_ms(delaytime);
        Leg_WalkForwardup(4);
        Leg_WalkForwardDown(4);
        __delay_ms(delaytime);
    } else if (walk_state == 3) {
        Leg_WalkBackwardDown(3);
        Leg_WalkBackwardDown(2);
        __delay_ms(delaytime);
    }
}

void Motion_Test() {
}

void Leg_WalkForwardup(int legId) {
    switch (legId) {
        case 1:
            // Right front leg
            UART_ServoControl(RFLEG, UPSER, -30, 100);
            UART_ServoControl(RFLEG, MIDSER, 20, 100);
            UART_ServoControl(RFLEG, DOWNSER, -55, 100);
            break;
        case 2:
            // Right back leg
            UART_ServoControl(RBLEG, UPSER, -10, 100);
            UART_ServoControl(RBLEG, MIDSER, -30, 100);
            UART_ServoControl(RBLEG, DOWNSER, 75, 100);
            break;
        case 3:
            // Left front leg
            UART_ServoControl(LFLEG, UPSER, -70, 100);
            UART_ServoControl(LFLEG, MIDSER, -35, 100);
            UART_ServoControl(LFLEG, DOWNSER, 50, 100);
            break;
        case 4:
            // Left back leg
            UART_ServoControl(LBLEG, UPSER, -90, 100);
            UART_ServoControl(LBLEG, MIDSER, 10, 100);
            UART_ServoControl(LBLEG, DOWNSER, -55, 100);
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
            UART_ServoControl(RFLEG, UPSER, -30, 100);
            UART_ServoControl(RFLEG, MIDSER, 45, 100);
            UART_ServoControl(RFLEG, DOWNSER, -55, 100);
            break;
        case 2:
            // Right back leg
            UART_ServoControl(RBLEG, UPSER, -10, 100);
            UART_ServoControl(RBLEG, MIDSER, -55, 100);
            UART_ServoControl(RBLEG, DOWNSER, 75, 100);
            break;
        case 3:
            // Left front leg
            UART_ServoControl(LFLEG, UPSER, -70, 100);
            UART_ServoControl(LFLEG, MIDSER, -60, 100);
            UART_ServoControl(LFLEG, DOWNSER, 50, 100);
            break;
        case 4:
            // Left back leg
            UART_ServoControl(LBLEG, UPSER, -90, 100);
            UART_ServoControl(LBLEG, MIDSER, 35, 100);
            UART_ServoControl(LBLEG, DOWNSER, -55, 100);
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
            UART_ServoControl(RFLEG, UPSER, -90, 100);
            UART_ServoControl(RFLEG, MIDSER, 45, 100);
            UART_ServoControl(RFLEG, DOWNSER, -55, 100);
            break;
        case 2:
            // Right back leg
            UART_ServoControl(RBLEG, UPSER, -70, 100);
            UART_ServoControl(RBLEG, MIDSER, -55, 100);
            UART_ServoControl(RBLEG, DOWNSER, 75, 100);
            break;
        case 3:
            // Left front leg
            UART_ServoControl(LFLEG, UPSER, -10, 100);
            UART_ServoControl(LFLEG, MIDSER, -60, 100);
            UART_ServoControl(LFLEG, DOWNSER, 50, 100);
            break;
        case 4:
            // Left back leg
            UART_ServoControl(LBLEG, UPSER, -30, 100);
            UART_ServoControl(LBLEG, MIDSER, 35, 100);
            UART_ServoControl(LBLEG, DOWNSER, -55, 100);
            break;

        default:
            break;
    }
    __delay_ms(200);
}
