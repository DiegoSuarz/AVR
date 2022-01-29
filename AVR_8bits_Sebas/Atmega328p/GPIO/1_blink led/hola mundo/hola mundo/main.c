/*
 * hola mundo.c
 *
 * Created: 25/07/2021 20:12:33
 * Author : Diego
 */ 

#define  F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h> //contiene informacion de todos los registros, la ubicacion de memoria etc

char regA=0b11100111;
char regB=0b00011000;
int main(void)
{
	//DDRx --> escribir,puerto de salida = 0 , leer, puerto de entrada = 1
	//PORTx --> establecer una valor de salida en el puerto x
	//Pinx --> Se utiliza para leer datos de un puerto
    
	DDRD = 0b11111111; //todos los puertos son de salida, DDRD=255(decimal), DDRD=0xFF(hexadecimal), DDRD=0377(octal), DDRD = 0b11111111(binario)
	PORTD = 0b11001111; //PORTD sirve para escribir en un puerto
    while (1) 
    {
		//PORTD=0b10000000;
		//_delay_ms(500);
		//PORTD=0b00000001;
		//_delay_ms(500);
		
		PORTD |= (1<<0);
		_delay_ms(1000);
		PORTD &= ~(1<<0);
		_delay_ms(1000);
		
		//PORTD &= ~(1<<2); //apagando el bit 2
		//_delay_ms(500);
		//PORTD=0b00000000;
		//_delay_ms(500);
		//PORTD |= (1<<3);	//encendiendo el bit 3
		//_delay_ms(500);
    }
}

