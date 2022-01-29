/*
 * INTERRUPCION.cpp
 *
 * Created: 14/01/2022 12:49:03
 * Author : Diego
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
	DDRB |= ((1<<PINB0)|(1<<PINB1)|(1<<PINB2)); //pines salida
	DDRD |= (1<<PINB0); // pin salida
	DDRD &= ~(1<<PINB2);
	
	EICRA |= (1<< ISC01); //permite controlar la sensibilidad (si la interrupcion externa es flanco de subida o de bajada) (flancos de bajada en este caso)
	EICRA &= ~(1<< ISC00); 
	
	EIMSK |= (1<<INT0); // habilitar la interrupcion externa 0
	
	sei();  //funcion para habilitar las interrupciones globales
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (1<<PINB0);
		_delay_ms(500);
		PORTB |= (1<<PINB1);
		_delay_ms(500);
		PORTB |= (1<<PINB2);
		_delay_ms(500);
		
		PORTB &= ~(1<<PINB0);
		_delay_ms(500);
		PORTB &= ~(1<<PINB1);
		_delay_ms(500);
		PORTB &= ~(1<<PINB2);
		_delay_ms(500);
		
	}
}

ISR(INT0_vect){
	PORTD ^= (1<<PIND0);
	
}