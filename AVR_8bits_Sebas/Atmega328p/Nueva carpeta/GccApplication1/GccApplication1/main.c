/*
 * GccApplication1.c
 *
 * Created: 24/01/2022 12:50:51
 * Author : Diego
 */ 

#include <avr/io.h>
#include "librerias/UART.h"


int main(void)
{
	DDRB |=((1<<4)|(1<<3)|(1<<2));
	
	UART_init();
	
	UART_write_txt("Digite 1 3 5 para encender led\n\r");
	UART_write_txt("Digite 2 4 6 para apagar leds\n\r");
	uint8_t dato=0;
    /* Replace with your application code */
    while (1) 
    {
		dato = UART_read();
		if(dato !=0)
		{
			switch(dato)
			{
				case '1':
					UART_write_txt("LED1 encendido\n\r");
					PORTB |=(1<<2);
				break;
				
				case '2':
					UART_write_txt("LED1 apagado\n\r");
					PORTB &= ~(1<<2);
				break;
				
				case '3':
					UART_write_txt("LED2 encendido\n\r");
					PORTB |=(1<<3);
				break;
				
				case '4':
					UART_write_txt("LED2 apagado\n\r");
					PORTB &= ~(1<<3);
				break;
				
				case '5':
					UART_write_txt("LED3 encendido\n\r");
					PORTB |=(1<<4);
				break;
				
				case '6':
					UART_write_txt("LED3 apagado\n\r");
					PORTB &= ~(1<<4);
				break;
			}
		}
				
    }
}

