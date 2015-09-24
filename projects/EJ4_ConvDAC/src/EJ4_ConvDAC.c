/*------------------------------------------------------------------------------------------*/
/* EJ4_ConvDA.c                                                                             */
/* Diseñe e implemente un firmware sobre la EDU-CIAA que genera una señal tipo diente de    */
/* sierra de periodo 100 ms y excursión de 0 a 3V                                           */
/*------------------------------------------------------------------------------------------*/

#include "EJ4_ConvDAC.h"
#include "Dri_Led.h"
#include "Dri_Timer.h"
#include "Dri_ConvDA.h"

#define TRUE 1
#define VAL_MAX 930    /* valor = (3V/3.3V)*1023 */
#define STEP 10        /* Ajuste del paso
//- Variables ----------------------------------------------------------------------
uint8_t f_timer_ovf;

//----------------------------------------------------------------------------------
void MyRITimerISR(void) {

    // Limpio el flag de interrupción
	Chip_RIT_ClearInt(LPC_RITIMER);
	f_timer_ovf=1;
}


//----------------------------------------------------------------------------------
int main(void) {
	uint32_t contador;

	Chip_SetupCoreClock(CLKIN_IRC,MAX_CLOCK_FREQ/4,1);
	InicializarLeds();
	InicializarTimer();
	InicializarDAC();

//	PrenderLed(LED1);

	while(TRUE){
		if (f_timer_ovf) {
			f_timer_ovf = 0;
			if(contador >= VAL_MAX) {
				contador = 0;
				ToogleLed(LED0G);
			}
			Out_DAC(contador);
			contador = contador + STEP;
		}
	}
	return 0;
}
//----------------------------------------------------------------------------------
