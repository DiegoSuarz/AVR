/*
 * DISPLAY_7SEG.c
 *
 * Created: 8/08/2021 22:32:41
 * Author : Diego
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//pulsadores
#define  getStatusB4()	(PINB &(1<<PINB4))
#define  getStatusB5()	(PINB &(1<<PINB5))

//encender displays
#define setD1()	PORTB = 1<<0
#define setD2()	PORTB = 1<<1
#define setD3()	PORTB = 1<<2
#define setD4()	PORTB = 1<<3

const uint8_t  deco_ac[10]={192,249,164,176,153,146,130,248,128,152};//enciende con ceros
const uint8_t tiempo=20;

uint16_t miles, centenas, decenas, unidades;
uint16_t residuo,contador=8453;

void multiplexar();

int main(void)
{
    DDRD=0xff;
	DDRB |=(1<<PINB0)|(1<<PINB1)|(1<<PINB2)|(1<<PINB3);
    DDRB &=~((1<<PINB4)|(1<<PINB5));
	
	
	while (1) 
    {
		if(getStatusB4() == 0){
			while(getStatusB4() !=0) multiplexar();	
			contador++;
			if(contador>9999)contador=0;
			multiplexar();
		}
		
		if(getStatusB5() == 0){
			while(getStatusB5() !=0) multiplexar();
			contador--;
			if(contador<0)contador=9999;
			multiplexar();
		}
		miles=contador/1000;
		residuo=contador%1000;
		centenas=residuo/100;
		residuo=residuo%100;
		decenas=residuo/10;
		unidades=residuo%10;
		multiplexar();	
	}
}

void multiplexar(){
	
	setD1();
	PORTD=deco_ac[miles];
	_delay_ms(tiempo);
	
	setD2();
	PORTD=deco_ac[centenas];
	_delay_ms(tiempo);
	
	setD3();
	PORTD=deco_ac[decenas];
	_delay_ms(tiempo);
	
	
	setD4();
	PORTD=deco_ac[unidades];
	_delay_ms(tiempo);
	
}