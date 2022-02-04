/*
 * LCD.c
 *
 * Created: 16/01/2022 19:42:24
 * Author : Diego
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD/LCD_LIB.h"


int main(void)
{
	DDRD = 0xFF;
	lcd_init();
	//lcd_string("12345678");
	//lcd_set_cursor(2,5);
	//lcd_string("Hola mundo");
	//lcd_set_cursor(3,1);
	//lcd_printf("temp: %d  hum=%d",25,24);
	lcd_string("hola a todos");
	_delay_ms(2000);
	//lcd_clear();
	//lcd_return_home();
	
	lcd_disable_cursor();
	_delay_ms(1000);
	lcd_enable_cursor();
	while (1)
	{
		
	}
}
