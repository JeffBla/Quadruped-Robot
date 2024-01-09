#ifndef SETTING_H
#define SETTING_H

#include <pic18f4520.h>
#include <xc.h>

#include "adc.h"
#include "interrupt_manager.h"
#include "pin_manager.h"
#include "tmr1.h"
#include "uart.h"
#include "motion.h"

#define _XTAL_FREQ 8000000
#define NUM_LEG 4

bool isWalk = false;

int nLeg = NUM_LEG;
int ServoId[NUM_LEG][3] = {{1, 5, 9}, {3, 7, 11}, {32, 28, 24}, {30, 26, 22}};

void SYSTEM_Initialize(void);

void OSCILLATOR_Initialize(void);

void Servo_Init(void);

#endif