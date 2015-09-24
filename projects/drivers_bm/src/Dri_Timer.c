/* ------------------------------------------------------------------------------------------*/
/* Dri_Timer.c                                                                               */
/*                                                                                           */
/* Creado en: 22/9/2015                                                           Autor: JF  */
/* ------------------------------------------------------------------------------------------*/
#include "Dri_Timer.h"

#define INTERVALO_EJ3  250
#define INTERVALO_EJ4  1

uint32_t contadorRIT;

/*------------------------------------------------------------------------------------------*/
void InicializarTimer(void) {
	Chip_RIT_Init(LPC_RITIMER);
	Chip_RIT_SetTimerInterval (LPC_RITIMER, INTERVALO_EJ4);
/*	NVIC_ClearPendingIRQ(RITIMER_IRQn); */
	NVIC_EnableIRQ(11);
}

/*------------------------------------------------------------------------------------------*/
void ClearTimer(void) {
	contadorRIT = 0;
}

/*------------------------------------------------------------------------------------------*/
uint32_t GetTimer(void) {
	return contadorRIT;
}

/*------------------------------------------------------------------------------------------*/
