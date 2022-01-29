/*
 * PRIORIDAD_INTERRUPCIONES.cpp
 *
 * Created: 15/01/2022 19:47:44
 * Author : Diego
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    DDRB|=((1<<PINB0)|(1<<PINB1)|(1<<PINB2)); //pines B0,B1,B2 como salida
	PORTB = 0x00; //limpiando el puerto B
	
	//interrupciones externas INTx	
	EICRA |= ((1<<ISC00)|(1<<ISC01)|(1<<ISC10)|(1<<ISC11)); //sensibilidad INT0 e INT1 por flancos de bajada
    EIMSK |= ((1<<INT0)|(1<<INT1)); //habilitando la mascara de interrupciones INT0 e INT1
	
	//interrupciones por cambio de estado PCINTx
	PCICR |= (1<<PCIE2); //habilitando las interrupciones PCINT del puerto B
	PCMSK2 |= (1<<PCINT16); //habilitando la mascara de la int. PCINT16
	
	sei(); //habilitando interrupciones globales
	
	while (1) 
    {
		
    }
}

//funciones para rutinas de servicio de interrupcion
ISR(INT0_vect){ //vector de interrupcion para la interrupcion externa 0
	sei();			//anidar interrupciones
	for(char i=0;i<=5;i++){
		PORTB ^= (1<<PORTB0);
		_delay_ms(1000);
	}
}

ISR(INT1_vect){ //vector de interrupcion para la interrupcion externa 1
	sei();			//anidar interrupciones
	for(char i=0;i<=5;i++){
		PORTB ^= (1<<PORTB1);
		_delay_ms(1000);
	}
}

ISR(PCINT2_vect){ //vector de interrupcion para PCINT16
		sei();			//anidar interrupciones
		PORTB ^= (1<<PORTB2);	
	
}

//prioridades de las interrupciones, existe una tabla en el capitulo 15.1
// el reset tiene la maxima prioridad
// INT0 < INT1 < PCINT2