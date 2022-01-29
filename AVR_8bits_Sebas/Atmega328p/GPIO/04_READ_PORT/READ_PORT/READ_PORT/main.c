/*
 * READ_PORT.c
 *
 * Created: 26/07/2021 21:55:00
 * Author : Diego
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define readpinD0 (PINB & (1<<PINB0))
#define readpinD1 (PINB & (1<<PINB1))


int main(void)
{
	DDRD |=((1<<PIND0)|(1<<PIND1)); //pind0,pind1 configurados como salidas digitales
	DDRD &= ~((1<<PINB0)|(1<<PINB1)); //pinb0, pinb2 configurados como entradas digitales
	
	PORTD=0x00; //limpiamos el puerto
    while (1) 
    {
		if(readpinD0==0){  //si el pinb0 es igual a 0??
			PORTD &=~(1<<PIND0);	//apagar el pind0
				
		}else{
			PORTD |=(1<<PIND0);     //encender el pind0
		
		}
				
		if(!readpinD1==0){  //si el pinb0(negado) es igual a 0??
			PORTD &=~(1<<PIND1);	//apagar el pind0
			
			}else{
			PORTD |=(1<<PIND1);     //encender el pind0
			
		}
    }
}

