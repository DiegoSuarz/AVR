/*
 * PLACE HOLDER.c
 *
 * Created: 31/01/2022 16:36:51
 * Author : Diego
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Librerias/LCD_LIB.h"

int contador=0;
float temp = 3.5;


int main(void)
{
    /* Replace with your application code */
	lcd_init();
	lcd_disable_blink();
	lcd_disable_cursor();
	
	lcd_printf("mi temp: %0.2f",temp);

	while (1) 
    {
		for(contador=0;contador<=25;contador++){
			lcd_set_cursor(2,1);
			lcd_printf("contador: %02d",contador);
			_delay_ms(100);
		}
    }
}

