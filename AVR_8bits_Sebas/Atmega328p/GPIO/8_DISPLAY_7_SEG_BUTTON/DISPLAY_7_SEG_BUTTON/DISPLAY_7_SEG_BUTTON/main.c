/*
 * DISPLAY_7_SEG_BUTTON.c
 *
 * Created: 13/01/2022 17:27:16
 * Author : Diego
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define  getStatusB0() (PINB & (1<<PINB0))  //macro para detectar el valor logico en el pin b0

unsigned char deco_ac[10]={192,249,164,176,153,146,130,248,128,152}; //comun 5v, se activan con '0'
unsigned char contador=0;
int main(void)
{
	/* Replace with your application code */
	DDRD = 0XFF; //Todo el puerto D como salida digital
	DDRB &= ~(1<<PINB0); // El PINB0 como salida digital
	
		
	while (1)
	{
		if(getStatusB0() !=0){
			while(getStatusB0() !=0);
			contador++;
			if(contador>9) contador=0;
		}
		PORTD = deco_ac[contador];
		_delay_ms(10);
	}
}
