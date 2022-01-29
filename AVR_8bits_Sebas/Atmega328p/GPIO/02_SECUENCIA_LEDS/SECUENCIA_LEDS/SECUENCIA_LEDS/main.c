/*
 * READ_PORT.c
 *
 * Created: 26/07/2021 21:55:00
 * Author : Diego
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SECUENCIA/LEDS.h"

#define readpinD0 (PINB & (1<<PINB0))
#define readpinD1 (PINB & (1<<PINB1))

#define MANUAL 0
#define AUTOMATICO 1


uint8_t sec=0,modo=MANUAL, seleccion=0;
int main(void)
{
	DDRD |=((1<<PIND0)|(1<<PIND1)); //pind0,pind1 configurados como salidas digitales
	DDRB &= ~((1<<PINB0)|(1<<PINB1)); //pinb0, pinb2 configurados como entradas digitales
	
	PORTD=0x00; //limpiamos el puerto
    while (1) 
    {
		if(modo==MANUAL){
			switch(sec){
				case 0: secuenciaA();break;
				case 1: secuenciaB();break;
				case 2: secuenciaC();break;
			}
			if(readpinD0 != 0){
				while(readpinD0 !=0); //esperar mientras esta presionado el pulsador
				sec++;
				if(sec>2)
					sec=0;
			}
		
		while(modo==AUTOMATICO){
				switch(sec++){
					case 0: secuenciaA();break;
					case 1: secuenciaB();break;
					case 2: secuenciaC();break;
				}
				if(sec>2)sec=0;	
						
			}
		}
		
	}
}

