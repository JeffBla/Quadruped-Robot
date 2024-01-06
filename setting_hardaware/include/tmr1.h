#ifndef TMR1_H
#define TMR1_H

#include <stdbool.h>
#include <xc.h>

void TMR1_Init(bool isINT);

void TMR1_Run(int high_byte, int low_byte);

#endif /* TMR1_H */
