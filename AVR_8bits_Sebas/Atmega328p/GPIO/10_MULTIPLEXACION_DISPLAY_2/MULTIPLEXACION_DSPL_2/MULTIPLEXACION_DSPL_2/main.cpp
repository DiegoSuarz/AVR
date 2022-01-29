/*
 * MULTIPLEXACION_DSPL_2.cpp
 *
 * Created: 14/01/2022 11:41:28
 * Author : Diego
 */ 

#define F_CPU 16000000UL //definir la frecuencia de operación
#include <avr/io.h>		//incluir los registros de uC y el manejo de pines IO
#include <util/delay.h> //incluir la libreria para manejar los retardos
#include <stdint.h>

#define		getStatusB4() (PINB & (1<<PINB4))  //macro para detectar el valor logico en el pin b0
#define		getStatusB5() (PINB & (1<<PINB5))

#define		setTrasn1()		PORTB = 1<<0
#define		setTrasn2()		PORTB = 1<<1
#define		setTrasn3()		PORTB = 1<<2
#define		setTrasn4()		PORTB = 1<<3


unsigned char deco_ac[10]={192,249,164,176,153,146,130,248,128,152}; //comun 5v, se activan con '0'
signed char contador=0,unidades=0,decenas=0,residuo,aux;
const unsigned char tiempo= 5;
int valor_tiempo = 50;

void multiplexar();
void repetir_inc(uint32_t valor);
void repetir_dec(uint32_t valor);

int main(void)
{
	/* Replace with your application code */
	DDRD = 0XFF; //Todo el puerto D como salida digital
	DDRB |= (1<<PINB0)|(1<<PINB1)|(1<<PINB2)|(1<<PINB3); //Pines B0,B1,B2,B3 como salida
	DDRB &= ~((1<<PINB4)|(1<<PINB5));  //PINES B4,B5 como entrada digital
	
	
	while (1)
	{
		
		if(getStatusB4() !=0){
			while(getStatusB4()!=0){
				repetir_inc(valor_tiempo);
				valor_tiempo -= 5;
				if(valor_tiempo<15) valor_tiempo=15;
				contador++;
			}
			valor_tiempo=50;
			
			if(contador>99){
				contador=0;
			}
		}
		
		if(getStatusB5() !=0){
			while(getStatusB5()!=0) {
				repetir_dec(valor_tiempo);
				valor_tiempo -= 5;
				if(valor_tiempo<15) valor_tiempo=15;
				contador--;	
				
			}
			valor_tiempo=50;	
			
			if(contador<0){
				contador=99;
			}
		}
		
		
		multiplexar();
	}
}

void multiplexar(){
	
	decenas = contador/10;
	residuo=contador%10;
	unidades = residuo;
	
	setTrasn1();
	PORTD = deco_ac[unidades];
	_delay_ms(tiempo);
	
	setTrasn2();
	PORTD=deco_ac[decenas];
	_delay_ms(tiempo);
}

void repetir_inc(uint32_t valor){
	
	char i;
	for(i=0;i<valor;i++){
		multiplexar();
		if(getStatusB4() ==0) break;
		
	}
	return;
}

void repetir_dec(uint32_t valor){
	char i;
	for(i=0;i<valor;i++){
		multiplexar();
		if(getStatusB5() ==0) break;
	}
	return;
	
}