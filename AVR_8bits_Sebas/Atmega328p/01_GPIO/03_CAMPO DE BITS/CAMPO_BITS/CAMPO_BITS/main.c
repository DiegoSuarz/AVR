/*
 * CAMPO_BITS.c
 *
 * Created: 27/07/2021 11:53:37
 * Author : Diego
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LIBRERIAS/CAMPO_BITS.h"

uint8_t cont=0;

int main(void)
{
	DDRBbits.DDRB0=1; //DDR0 COMO ENTRADA DIGITAL
	DDRDbits.DDRD0=0; //DDR0 COMO SALIDA DIGITAL
	DDRDbits.DDRD1=0;
	PORTDbits.PD0_=1;
    while (1) 
    {
		if(PINBbits.PINB0_==1){
			while(PINBbits.PINB0_==1);
			cont++;
			if(cont>1)
			cont=0;
		if(cont==1){
			PORTDbits.PD1_=1;
		}else{
			PORTDbits.PD1_=0;
		}		
		}
    }
}

