/*------------------------------------------------------------------------------------------*/
/* EJ3_SecxIntTMR.c                                                                         */
/* Diseñe e implemente un firmware sobre la EDU-CIAA que encienda de a un led por vez y     */
/* de manera secuencial. El tiempo de encendido de cada led ser 250ms. Se deberá temporizar */
/* mediante interrupciones sin usar funciones de retardo por software.                      */
/*------------------------------------------------------------------------------------------*/
#include "EJ3_SecxIntTMR.h"      
#include "Dri_Led.h"
#include "Dri_Timer.h"

//- Variables ----------------------------------------------------------------------
uint8_t f_timer_ovf;

//----------------------------------------------------------------------------------
void MyRITimerISR(void) {

    // Limpio el flag de interrupción
	Chip_RIT_ClearInt(LPC_RITIMER);
	//ToogleLed(LED0G);
	// Flag de aviso al pgm ppal..
	f_timer_ovf=1;
}


//----------------------------------------------------------------------------------
int main(void) {
	uint8_t contador;

	Chip_SetupCoreClock(CLKIN_IRC,MAX_CLOCK_FREQ/4,1);
	InicializarLeds();
	InicializarTimer();

//	PrenderLed(LED1);

	while(1){
		if (f_timer_ovf == 1){
			// Borro el flag
			f_timer_ovf = 0;

			// Selecciono que debo hacer con la salida de leds
			switch(contador) {
				case (0):
						PrenderLed(LED0B);
				        ApagaLed(LED1);
				        ApagaLed(LED2);
				        ApagaLed(LED3);
						break;
				case (1):
						PrenderLed(LED1);
						ApagaLed(LED0B);
				        ApagaLed(LED2);
				        ApagaLed(LED3);
						break;
				case (2):
						PrenderLed(LED2);
				        ApagaLed(LED0B);
				        ApagaLed(LED1);
				        ApagaLed(LED3);
						break;
				case (3):
						PrenderLed(LED3);
				        ApagaLed(LED0B);
				        ApagaLed(LED1);
				        ApagaLed(LED2);
						break;
				default:
					    contador = 0;
			}
			// Contador avanza para realizar la secuencia
			contador++;

			if(contador >= 4) {
				contador = 0;
			}
		}

	}

	return 0;
}
//----------------------------------------------------------------------------------
