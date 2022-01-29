#include "GPIO.h"

const int tiempo=200;

void secuenciaA(){
	PORTD=0b10101010;
	_delay_ms(tiempo);
	PORTD=0b01010101;
	_delay_ms(tiempo);
	
}

void secuenciaB(){
	PORTD=0x0F;
	_delay_ms(tiempo);
	PORTD=0xF0;
	_delay_ms(tiempo);
	
		
}