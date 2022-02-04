/*
 * libreria_gpio.c
 *
 * Created: 26/07/2021 21:31:25
 * Author : Diego
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LIBRERIA/GPIO.h"

int main(void)
{
    DDRD=0xFF; //puerto d como salida digital
	PORTD=0x00; //escribir 0x00 en el puerto D
    while (1) 
    {
	//	secuenciaA();
    secuenciaB();
	}
}

