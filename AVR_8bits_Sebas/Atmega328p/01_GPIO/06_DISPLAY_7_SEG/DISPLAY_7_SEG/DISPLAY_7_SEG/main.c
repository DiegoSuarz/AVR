/*
 * DISPLAY_7_SEG.c
 *
 * Created: 28/07/2021 20:43:20
 * Author : Diego
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define  getstatusb0()	(PINB & (1<<PINB0))
#define  getstatusb1()	(PINB & (1<<PINB1))

const uint8_t  deco_ac[10]={192,249,164,176,153,146,130,248,128,152};//enciende con ceros
uint8_t contador=0,status=0;
const uint8_t i;

void cambio(void);
void retardo_ms(void);

int main(void)
{
    DDRD= 0xff; //puerto D salida
	DDRB &= ~(1<<PINB0); //pin B0 entrada 
	PORTD=deco_ac[contador];
    while (1) 
    {
		
		if(status==0){
			if(getstatusb0() != 0){
				while(getstatusb0()!=0);
				cambio();
				contador++;
				if(contador>9)contador=0;
				PORTD=deco_ac[contador];
				}
		}
		while(status==1){
			cambio();
			contador++;
			PORTD=deco_ac[contador];
			retardo_ms();
			if(contador>9)contador=0;
		}
		cambio();	
		
	}
}

void cambio(void){
	if(getstatusb1() == 0){
		while(getstatusb1()==0);
		status++;
		if(status>1){status=0;}
		return;
	}
	
}

//rutina de retardo
void retardo_ms(void){
	for(int i=0;i<=500;i++){
		cambio();
		_delay_ms(1);
	}
	
}