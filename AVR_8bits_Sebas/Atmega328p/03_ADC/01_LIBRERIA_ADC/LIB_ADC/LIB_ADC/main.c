/*
 * LIB_ADC.c
 *
 * Created: 5/02/2022 11:01:09
 * Author : Diego
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Libreria_LCD/LCD_LIB.h"
#include "Libreria_ADC/LIB_ADC.h"

int valor1=0, valor2=0;

int main(void)
{
	ADC_Init();
	lcd_init();
	lcd_disable_blink();
	lcd_disable_cursor();
    /* Replace with your application code */
    while (1) 
    {
		valor1 = ADC_Read(ADC0);
		valor2 = ADC_Read(ADC1);		
		lcd_set_cursor(1,1);
		lcd_printf("ADC0: %4d",valor1);
				
		lcd_set_cursor(2,1);
		lcd_printf("ADC1: %4d",valor2);
				
		_delay_ms(200);
    }
}

