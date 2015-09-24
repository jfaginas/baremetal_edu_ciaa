/*------------------------------------------------------------------------------------------*/
/* EJ2_LecturaTeclas.c
/* Lectura de Teclas:
/* Diseñe e implemente un firmware sobre la EDU-CIAA que haga parpadear un led con un periodo
/* que permita visualizar el proceso. Mediante las cuatro teclas disponibles se debe poder 
/* seleccionar el led activo. Emplear retardo por software.
/*------------------------------------------------------------------------------------------*/
#include "EJ2_LecturaTeclas.h"       
#include "chip.h"
#include "Dri_Led.h"
#include "Dri_Teclas.h"

#define TIEMPO 1000000
/*------------------------------------------------------------------------------------------*/
int main(void){
   uint32_t i = 0;
	uint8_t ;

	InicializarLeds();
	InicializarTeclas();

	while(1){
		if (LeerTeclas() == TECLA1) {
			for(i = 0 ; i < TIEMPO ; i++);
			ToogleLed(LED0B);
		}
		if (LeerTeclas() == TECLA2) {
			for(i = 0; i < TIEMPO ; i++);
			ToogleLed(LED1);
		}
		if (LeerTeclas() == TECLA3) {
			for(i = 0; i < TIEMPO ; i++);
			ToogleLed(LED2);
		}		
		if (LeerTeclas() == TECLA4) {
			for(i = 0; i < TIEMPO ; i++);
			ToogleLed(LED3);
		}		
	}
   return 0;
}
/*------------------------------------------------------------------------------------------*/

