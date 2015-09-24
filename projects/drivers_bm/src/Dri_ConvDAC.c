/* ------------------------------------------------------------------------------------------*/
/* Dri_ConvDAC.c                                                                             */
/*                                                                                           */
/* Creado en: 24/9/2015                                                           Autor: JF  */
/* ------------------------------------------------------------------------------------------*/
#include "Dri_ConvDAC.h"
#include "chip.h"

/*-------------------------------------------------------------------------------------------*/
/* En este trabajo, adem�s de todas las funciones empleadas hasta este                       */
/* momento de GPIO, RITimer e IRQ, vamos a incorporar las funciones de uso del               */
/* conversor Digital a Anal�gico (pag 1350 del User Manual).                                 */
/* Primero hay que configurar la System Control Unit(SCU): Algunos pines                     */
/* soportan el multiplexado de funciones digitales y anal�gicas, sin embargo,                */
/* todas las entradas y salidas anal�gicas del ADC y DAC est�n adem�s ruteadas               */
/* a pines de funci�n anal�gica sin necesidad de multiplexado.                               */
/* Lo que si es necesario, es indicarle que vamos a utilizar el conversor DA                 */
/* mediante la funci�n:                                                                      */
/* Chip_SCU_DAC_Analog_Config();                                                             */
/* Para despu�s de eso, utilizar las funciones de LPOpen para el manejo del                  */
/* conversor DA, incorporadas en �dac_18xx_43xx.h�:                                          */
/* Chip_DAC_Init(LPC_DAC_T *pDAC);                                                           */
/* Chip_DAC_UpdateValue((LPC_DAC_T *pDAC, uint32_t dac_value);                               */
/*-------------------------------------------------------------------------------------------*/

void InicializarDAC(void) {
	Chip_SCU_DAC_Analog_Config();
	Chip_DAC_Init(LPC_DAC);
	Chip_DAC_UpdateValue(LPC_DAC, 0);
	Chip_DAC_ConfigDAConverterControl(LPC_DAC, DAC_DMA_ENA);
}

void Out_DAC(uint32_t salida){
	Chip_DAC_UpdateValue(LPC_DAC, salida);
}
