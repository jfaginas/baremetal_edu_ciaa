#ifndef EJ3_SecXIntTMR_H
#define EJ3_SecXIntTMR_H

#include "stdint.h"

extern void ResetISR(void);
extern void _vStackTop(void);
//static void RITimerISR(void);
void MyRITimerISR(void);
#endif
