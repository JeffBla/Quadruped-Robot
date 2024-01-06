#ifndef SETTING_H
#define SETTING_H

#include <pic18f4520.h>
#include <xc.h>

#include "interrupt_manager.h"
#include "pin_manager.h"
#include "tmr1.h"
#include "uart.h"

void SYSTEM_Initialize(void);

void OSCILLATOR_Initialize(void);

#endif