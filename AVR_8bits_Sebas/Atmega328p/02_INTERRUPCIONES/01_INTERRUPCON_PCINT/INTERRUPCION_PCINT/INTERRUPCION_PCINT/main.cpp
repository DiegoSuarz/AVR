/*
 * INTERRUPCION_PCINT.cpp
 *
 * Created: 15/01/2022 17:29:26
 * Author : Diego
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int contador;

int main(void)
{
    /* Replace with your application code */
	DDRD |= ((1<<PIND0)|(1<<PIND1)|(1<<PIND2)|(1<<PIND3));
	PORTD =0;
	DDRB &= ~(1<<PINB0);
	
	//configuracion de interrupciones PCINT
	PCICR |= ((1<<PCIE0)|(1<<PCIE1)); //habilitar interrupcones INT0 y INT1 bloques del puerto B,C
	
	PCMSK0 |= (1<<PCINT0); //habilitamos la interrupcion PCINT0 (pinB0)
	PCMSK0 |= (1<<PCINT1); //habilitamos la interrupcion PCINT0 (pinB0)
	PCMSK1 |= (1<<PCINT8); //habilitamos la interrupcion PCINT1 (pinC0)
	
	sei(); //habilitamos las interrupcones globales
	 
    while (1) 
    {
		if(contador>15) contador=0;
		if(contador<0) contador=15;
		
		PORTD = contador;
		
    }
}

ISR(PCINT0_vect){ //para PCINT0 puerto B  (B0)
	
	if((PINB&(1<<PINB0))==0){  //la interrupcion se activa 2 veces cada ves que presionamos el pulsador(flanco de subida y flanco de bajada), se crea rutina por software para solo aumentar 1 vez el contador 
		contador++;
	}
	if((PINB&(1<<PINB1))==0){  
		contador--;
	}
	
}

ISR(PCINT1_vect){ //para PCINT1 puerto C (C0)
	if((PINC&(1<<PINC0))==0){
		contador--;
	}
}