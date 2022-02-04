/*
 * ADC.c
 *
 * Created: 4/02/2022 11:28:07
 * Author : Diego
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Librerias/LCD_LIB.h"

int conv1, conv2;
int main(void)
{
    lcd_init();
	lcd_disable_blink();
	lcd_disable_cursor();
	
	/************************************************************************/
	/*						 Configuration del ADC                                                                     */
	/************************************************************************/
	ADMUX &= ~(1<<ADLAR);   //justificacion a la derecha de los registros ADLH
	
	ADMUX &= ~(1<<REFS1);	//Seleccionanda el voltaje de referencia ( VREF=AVCC)
	ADMUX |= (1<<REFS0);
	
	ADCSRA &=(1<<ADEN);  //Deshabilitando conversor el ADC
	
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //ajustando el presescaldor (se debe escoje entre el rango de 50 a 200 khz) 16M/128 = 125khz -> cumple con el rango
	 
	DIDR0 |= (1<<ADC0D) | (1<<ADC1D); //configurar pines d0 y d1 como analogicas
	
	//pasos para realizar una captura del adc
	/*
		1) seleccionar el conversor
		2) habilitar la conversion, empezar conversion
		3) Esperar a que termine la conversion 
		4) Deshabilitar la conversion (para que quede libre y otra canal lo pueda utilizar)
		5) Leer los valores
		*/
	
	
    while (1) 
    {
		//Seleccionar el canal a convertir
		ADMUX = (ADMUX & 0xF0);  //limpiamos el nibble LSB del registro ADMUX
		ADMUX |= 0;			//seleccionamos el canal 0
		
		//habilitar el adc y start
		ADCSRA |= (1<<ADEN) | (1<<ADSC);
		
		//Esperar a que la conversion termine
		while((ADCSRA & (1<< ADSC))!= 0); //esperar a que el adsc se ponga en 0
		
		//Deshabilitar conversor
		ADCSRA &= ~(1<<ADEN);
		
		//Leer la conversion
		conv1 = ADC;
		
		
		/*****************************************************************************************************/
		
		//Seleccionar el canal a convertir
		ADMUX = (ADMUX & 0xF0);  //limpiamos el nibble LSB del registro ADMUX
		ADMUX |= 1;			//seleccionamos el canal 1
		
		//habilitar el adc y start
		ADCSRA |= (1<<ADEN) | (1<<ADSC);
		
		//Esperar a que la conversion termine
		while((ADCSRA & (1<< ADSC))!= 0); //esperar a que el adsc se ponga en 0
		
		//Deshabilitar conversor
		ADCSRA &= ~(1<<ADEN);
		
		//Leer la conversion
		conv2 = ADC;
		
		lcd_set_cursor(1,1);
		lcd_printf("ADC0: %4d",conv1);
    
		lcd_set_cursor(2,1);
		lcd_printf("ADC1: %4d",conv2);
		
		_delay_ms(200);
	}
}

