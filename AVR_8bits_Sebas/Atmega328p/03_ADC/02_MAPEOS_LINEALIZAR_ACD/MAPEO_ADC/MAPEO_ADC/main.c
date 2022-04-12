/*
 * MAPEO_ADC.c
 *
 * Created: 12/04/2022 17:44:00
 * Author : Diego
 */ 

#define F_CPU 16000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include "librerias/LCD_LIB.h"
#include "librerias/LIB_ADC.h"

float LM35,	potenciometro;
int convert;

float mapeo(int conv,float x1, float x2, float y1, float y2);

int main(void)
{
	lcd_init();
	lcd_disable_blink();
	lcd_disable_cursor();
		
	lcd_set_cursor(1,1);
	lcd_puts("CANAL AVR-MAPEO");
		
	ADC_Init();
    /* Replace with your application code */
    while (1) 
    {
		convert = ADC_Read(ADC0);
		LM35 = mapeo(convert,0,307.2,0,150); //valor del adc,0->(empieza en 0°C,307.2 -> 150 °C
		
		convert = ADC_Read(ADC1);
		potenciometro = mapeo(convert,0,1023,0,5);
		
		lcd_set_cursor(2,1);
		lcd_printf("LM35: %6.1f",LM35);
		
		lcd_set_cursor(3,1);
		lcd_printf("POT: %6.1f",potenciometro);
		
    }
}

float mapeo(int conversion,float x1, float x2, float y1, float y2){
	
	
	/* el mapeo consiste en hayar la ecuacion de la recta, solo si el sensor tiene
	una respuesta lineal, en este caso el sensor LM35 tiene dicha respuesta, con lo cual
	se debe usar la siguiente formula:
	y1-y2 = m(x1 - x2) 
	y1 = mx1 -mx2 + y2
	
	m = pendiente, x1 = conversion*/
	
	float pendiente, distancia, recorrido;
	
	distancia = y2 -y1;
	recorrido = x2 -x1;
	pendiente = distancia/recorrido;
	
	return (pendiente * conversion - pendiente * x1 + y1);
}