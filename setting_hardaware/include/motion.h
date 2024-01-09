#ifndef MOTION_H
#define MOTION_H

#include <xc.h>

#include "setting.h"
#include "config.h"


void Motion_Init();

void Motion_Stand();

void Leg_Enlong(int legId);

void Leg_Shorten(int legId);

void Leg_EnlongLift(int legId);

void Leg_ShortenLift(int legId);

void Motion_WalkInit();

void Motion_TranState1();

void Motion_TranState2();

void Motion_TranState3();

void Motion_TranState4();

void Motion_TranState5();

void Motion_TranState6();

void Motion_Walk(int state);

void Motion_Walk_Old();

void Motion_Test();

void Leg_WalkForwardup(int legId);

void Leg_WalkForwardDown(int legId);

void Leg_WalkBackwardDown(int legId);


#endif  // MOTION_H
