/*
 * PULL_UP.c
 *
 * Created: 1/02/2022 20:40:32
 * Author : Diego
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "librerias/LCD_LIB.h"

#define get_button_up() (PINB &(1<<PINB0))
#define get_button_down() (PINB &(1<<PINB1))

int contador;

int main(void)
{
	//configuracion para habilitar las resistencias pull up
	/*
	Para habilitar las resistencias de pull up se necesita 
	colocar el registro DDxn =0, PORTxn =1, y el bit(4) PUD del 
	registro MCUCR =0
	*/
    DDRB &= ~((1<<PINB0)|(1<<PINB1)); //poniento pines como entrada
	PORTB |=  ((1<<PORTB0)|(1<<PORTB1));	//estableciendo 1 logico en los pines
	MCUCR &= ~(1<<PUD);
	
	lcd_init();
	lcd_disable_cursor();
	lcd_disable_blink();
	
    while (1) 
    {
		if(!get_button_up() ){
			while(!get_button_up());
			contador++;
			if(contador>15)contador=15;
		}
		
		if(get_button_down()==0){
			while(get_button_down()==0);
			contador--;
			if(contador<0)contador=0;
		}
		lcd_set_cursor(1,1);
		lcd_printf("contador: %0.2d",contador);	
    }
}

