/*
 * Dri_Timer.h
 *
 * Creado en: 22/9/2015
 * Autor: JF
 */

#ifndef Dri_Teclas_H_
#define Dri_Teclas_H_

#include "chip.h"

#define TECLA1 1
#define TECLA2 2
#define TECLA3 4
#define TECLA4 8

void InicializarTeclas(void);
uint8_t LeerTecla(uint8_t);
uint8_t LeerTeclas(void);

#endif /* Dri_Teclas_H_ */
