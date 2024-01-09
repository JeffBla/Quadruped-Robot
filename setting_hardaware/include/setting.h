#ifndef SETTING_H
#define SETTING_H

#include <pic18f4520.h>
#include <xc.h>

#include "adc.h"
#include "interrupt_manager.h"
#include "pin_manager.h"
#include "uart.h"
#include "motion.h"

#define _XTAL_FREQ 8000000

bool isWalk = false;

void SYSTEM_Initialize(void);

void OSCILLATOR_Initialize(void);

void Servo_Init(void);

#endif