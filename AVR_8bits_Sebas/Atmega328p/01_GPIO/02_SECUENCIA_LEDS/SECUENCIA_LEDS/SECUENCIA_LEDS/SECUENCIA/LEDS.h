/*
 * LEDS.h
 *
 * Created: 26/07/2021 22:28:40
 *  Author: Diego
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define readpinD0 (PINB & (1<<PINB0))
#define readpinD1 (PINB & (1<<PINB1))

#define MANUAL 0
#define AUTOMATICO 1

void secuenciaA(void);
void secuenciaB(void);
void secuenciaC(void);

void retardo_ms(uint8_t tiempo);

void estado(void);


#endif /* LEDS_H_ */