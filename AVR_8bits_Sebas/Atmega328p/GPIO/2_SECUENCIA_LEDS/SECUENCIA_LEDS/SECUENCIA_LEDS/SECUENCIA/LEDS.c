#include "LEDS.h"

const int tiempo=200;
extern uint8_t modo,sec,seleccion;
 

void secuenciaA(void){
	
	PORTD=0x0F;
	if(readpinD0 != 0){
		return;
	}
	estado();
	retardo_ms(tiempo);				
	PORTD=0xF0;
	retardo_ms(tiempo);
	estado();
}
void secuenciaB(void){
	PORTD=0b10101010;
	estado();
	if(readpinD0 != 0){
		return;
	}
	_delay_ms(tiempo);
	
	PORTD=0b01010101;
	estado();
	if(readpinD0 != 0){
		return;
	}
	retardo_ms(tiempo);
	
}

void secuenciaC(void){
	
	for(char i=0;i<=3;i++){
		PORTD|=((1<<i)|(1<<(7-i)));
		estado();
		if(readpinD0 != 0){
			return;
		}
		
	retardo_ms(tiempo);
	}
	
	for(char i=0;i<=3;i++){
		PORTD &=~((1<<(3-i))|(1<<(4+i)));
		estado();
		if(readpinD0 != 0){
			return;
		}
		retardo_ms(tiempo);
	}
	
}


void retardo_ms(uint8_t tiempo){
	for(uint8_t i=0;i<=tiempo;i++){
		estado();
		_delay_ms(1);
		if(readpinD0 != 0){
			return;
		}
	}
}

void estado(void){
	uint8_t a;
	if(readpinD1 == 0){
		a=sec;
		while(readpinD1 == 0); 
		seleccion++;
		if(seleccion==1){
			modo=AUTOMATICO;
			sec=a;
		}else{
			modo=MANUAL;
			sec=a;
		}
		if(seleccion>1)seleccion=0;
		return;
	}
	
}