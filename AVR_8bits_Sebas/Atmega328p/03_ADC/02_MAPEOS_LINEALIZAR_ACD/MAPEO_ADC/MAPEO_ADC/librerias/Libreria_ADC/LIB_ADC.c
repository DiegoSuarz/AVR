/*
 * LIB_ADC.c
 *
 * Created: 5/02/2022 11:05:06
 *  Author: Diego
 */ 

#include "LIB_ADC.h"

void ADC_Init(void){
	/************************************************************************/
	/*						 Configuration del ADC                                                                     */
	/************************************************************************/
	ADMUX &= ~(1<<ADLAR);   //justificacion a la derecha de los registros ADLH
	
	ADCSRA &= ~(1<<ADATE);	//Deshabilitar el autodisparo de conversion del ADC
	
	ADMUX &= ~(1<<REFS1);	//Seleccionanda el voltaje de referencia ( VREF=AVCC)
	ADMUX |= (1<<REFS0);
	
	ADCSRA &=(1<<ADEN);  //Deshabilitando conversor el ADC
	
	ADCSRA = ADCSRA & 0xF8; //Ajustando el presescaldor (se debe escoje entre el rango de 50 a 200 khz) 16M/128 = 125khz -> cumple con el rango
	ADCSRA = ADCSRA | _DIV_FREQ128;
	 
	DIDR0 |= 0xFF; //configurar todos los pines como analogicas
		
}


uint16_t ADC_Read(uint8_t chanel){
	
	//Seleccionar el canal a convertir
	ADMUX = (ADMUX & 0xF0);  //limpiamos el nibble LSB del registro ADMUX
	ADMUX |= chanel;			//seleccionamos el canal 0
	
	//habilitar el adc y start
	ADCSRA |= (1<<ADEN) | (1<<ADSC);
	
	//Esperar a que la conversion termine
	while((ADCSRA & (1<< ADSC))!= 0); //esperar a que el adsc se ponga en 0
	
	//Deshabilitar conversor
	ADCSRA &= ~(1<<ADEN);
	
	return ADC; //retornamos el valor del registro ADC
	
}