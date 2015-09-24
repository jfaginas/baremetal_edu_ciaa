/*------------------------------------------------------------------------------------------*/
/* EJ1_LedBlink.c
/* Blink de Led:
/* Diseñe e implemente un firmware sobre la EDU-CIAA que haga parpadear el led amarillo con
/* un periodo que permita visualizar el proceso. Emplear retardo por software.
/*------------------------------------------------------------------------------------------*/
#include "EJ1_LedBlink.h"
#include "Dri_Led.h"

#define TIEMPO 5000000
/*------------------------------------------------------------------------------------------*/
int main(void) {
   uint32_t i = 0;
	
	InicializarLeds();
	while(1){
		for(i = 0 ; i < 5000000 ; i++);
		ToogleLed(LED1);
	}
   return 0;
}
/*------------------------------------------------------------------------------------------*/
