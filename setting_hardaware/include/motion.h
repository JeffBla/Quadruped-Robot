#ifndef MOTION_H
#define MOTION_H

#include <xc.h>

#include "setting.h"

void Motion_Init();

void Motion_Stand();

void Motion_Walk();

void Motion_Test();

void Leg_WalkForwardup(int legId);

void Leg_WalkForwardDown(int legId);

void Leg_WalkBackwardDown(int legId);

#endif  // MOTION_H
