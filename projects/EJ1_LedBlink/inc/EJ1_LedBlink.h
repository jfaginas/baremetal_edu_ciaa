#ifndef EJ1_LedBlink_H
#define EJ1_LedBlink_H

#include "stdint.h"

extern void ResetISR(void);
extern void _vStackTop(void);
void RIT_IRQHandler(void);

#endif
