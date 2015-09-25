/*------------------------------------------------------------------------------------------*/
/* EVALUACION.c                                                                             */
/* Dise�e e implemente un firmware sobre la EDU-CIAA que genera permita adquirir una se�al  */
/* anal�gica de excursi�n entre 0 y 3.3V a una frecuencia de muestreo de 10 Hz.             */
/* La se�al deber� reproducirse por el conversor D-A.                                       */
/* Interfaz con el usuario:                                                                 */
/* Tec 1: Aumenta el valor de amplitud de la se�al.                                         */
/* Tec 2: Disminuye la amplitud de la se�al.                                                */
/* Tec 3: Lleva la se�al de salida a 0 (independientemente de la entrada).                  */
/* Funcionalidad reservada al usuario.                                                      */
/*                                                                                          */
/* El led 1 deber�a invertir su estado cada vez que se realiza una conversi�n.              */
/* Adicionalemente cada vez que se presiona una tecla el sistema deber� enviar por el puerto*/
/* serie la siguiente informaci�n:                                                          */
/* Tec 1: "Aumento la ganacia"                                                              */
/* Tec 2: "Disminuyo la ganancia"                                                           */
/* Tec 3: "MUTE"                                                                            */
/* Tec 4: "..."                                                                             */
/* El dise�o del firmware para la aplicaci�n deber� basarse en drivers para los dispositivos*/
/* y perif�ricos, evitando hacer llamadas a la LPCOpen desde la capa de aplicaci�n.         */
/*------------------------------------------------------------------------------------------*/

#include "EVALUACION.h"
#include "Dri_Led.h"
#include "Dri_Timer.h"
#include "Dri_ConvDAC.h"
#include "Dri_ConvAD.h"

#define K 10        // Factor de aumento o disminuci�n de la se�al
#define MUTE 0      // Constante que lleva a cero la salida DAC
#define TEST 512    // Valor de testeo a la salida del DAC (aprox 1.15V)
#define MAXVAL 1000 // Valor m�ximo de salida del DAC (aprox 3.3V)
#define MINVAL 10   // Valor m�nimo de salida del DAC (aprox 0V)

//- Variables ----------------------------------------------------------------------
uint8_t f_timer_ovf;

//- Servicio de interrupci�n -------------------------------------------------------
void MyRITimerISR(void) {

    // Limpio el flag de interrupci�n
	Chip_RIT_ClearInt(LPC_RITIMER);
	// Con este flag "aviso" al pgm ppal que realice la conversi�n
	f_timer_ovf = 1;
}


//- Programa Principal ------------------------------------------------------------
int main(void) {
	uint16_t lecturaAD, nuevovalor_AD;

	Chip_SetupCoreClock(CLKIN_IRC,MAX_CLOCK_FREQ/4,1);

	InicializarLeds();
	InicializarTeclas();
	InicializarTimer();
	InicializarDAC();
	InicializarAD();

    // Chequeo si el sistema arranca OK

	while(TRUE){
		if (f_timer_ovf) {
			// Apago al flag para realizar la conversi�n
			f_timer_ovf = 0;
			// Indico que se realiza la conversi�n
			ToggleLed(LED0G);
			// Leo el valor AD
			lecturaAD= ReadAD();
			//
			switch (LeerTeclas()){
				case (1):
						nuevovalor_AD = nuevovalor_AD + K;
						if(nuevovalor_AD>MAXVAL){
							nuevovalor_AD = 1000;
						}
						Out_DAC(nuevovalor_AD);
						// Print "Aumento la ganancia"
						break;
				case (2):
						nuevovalor_AD = nuevovalor_AD - K;
						if(nuevovalor_AD<MINVAL){
							nuevovalor_AD = 0;
						}
						Out_DAC(nuevovalor_AD);
				        // Print "Aumento la ganancia"
						break;
				case (4):
						Out_DAC(MUTE);
				        // Print "Aumento la ganancia"
						break;
				case (8):
						Out_DAC(TEST);
						// Print "Aumento la ganancia"
						break;

				default:
						Out_DAC(lecturaAD);
						break;
			}

		}
	}
	return 0;
}
//----------------------------------------------------------------------------------
