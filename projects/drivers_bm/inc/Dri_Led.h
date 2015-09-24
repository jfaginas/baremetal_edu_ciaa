/*
 * Dri_Led.h
 *
 * Creado en: 22/9/2015
 * Autor: JF
 */

#ifndef LED_H_
#define LED_H_

#include "chip.h"

#define LED0R 1
#define LED0G 2
#define LED0B 3
#define LED1 4
#define LED2 5
#define LED3 6

void InicializarLeds(void);
void PrenderLed(uint8_t);
void ApagaLed(uint8_t);
void ToogleLed(uint8_t);

#endif /* LED_H_ */
