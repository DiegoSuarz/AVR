/*
 * LCD.cpp
 *
 * Created: 16/01/2022 11:54:37
 * Author : Diego
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_LIB/LCD_LIB.h"



int main(void)
{
	DDRD = 0xFF;
	_send_byte(40,0);
	//lcd_init();
    while (1) 
    {
		
    }
}

