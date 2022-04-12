/*
 * LIB_ADC.h
 *
 * Created: 5/02/2022 11:05:28
 *  Author: Diego
 */ 


#ifndef LIB_ADC_H_
#define LIB_ADC_H_

#include <avr/io.h>
#include <stdint.h>

//Seleccionar el canal
#define  ADC0	0
#define  ADC1	1
#define  ADC2	2
#define  ADC3	3
#define  ADC4	4
#define  ADC5	5
#define  ADC6	6
#define  ADC7	7
#define  _TEMP_CH	8 //sensor de temperatura del atmega328pb

//factor de division de fre Oscilacion de ADC (16M/x)
#define  _DIV_FREQ2A	0
#define  _DIV_FREQ2B	1
#define  _DIV_FREQ4		2
#define  _DIV_FREQ8		3
#define  _DIV_FREQ16	4
#define  _DIV_FREQ32	5
#define  _DIV_FREQ64	6
#define  _DIV_FREQ128	7

//RESOLUCION DEL ADC
#define  _RESOL_BITS	1023.0

//definir el voltaje de referencia
#define		_AREF	5.0	

/************************************************************************/
/* FUNCIONES DE LA LIBRERIA                                                                     */
/************************************************************************/

void ADC_Init(void);
uint16_t ADC_Read(uint8_t chanel);


//Pasos para realizar una captura del adc
	/*
		1) seleccionar el conversor
		2) habilitar la conversion, empezar conversion
		3) Esperar a que termine la conversion 
		4) Deshabilitar la conversion (para que quede libre y otra canal lo pueda utilizar)
		5) Leer los valores
	*/


#endif /* LIB_ADC_H_ */