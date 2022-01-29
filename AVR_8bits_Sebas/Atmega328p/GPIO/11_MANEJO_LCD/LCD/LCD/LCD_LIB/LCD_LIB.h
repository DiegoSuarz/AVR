#pragma once //si algo ya esta definido, no lo define nuevamente

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define _COMANDO	0
#define _DATA		1

//DEFINIR EL PUERTO DONDE SE VA A CONECTAR LA LCD

#define	_LCD_DDR	DDRD
#define	_LCD_PORT	PORTD

#define _LCD_RS		0
#define _LCD_EN		1

#define _LCD_D4		2
#define _LCD_D5		3
#define _LCD_D6		4
#define	_LCD_D7		5

#if (!defined _LCD_DDR || !defined _LCD_PORT ) //Si el usuario no ha definido los puerto se mostrara un mensaje en consola avisandole que se usara los puertos por defecto
	#warning "Puerto de la LCD asignado por defecto"
	#define _LCD_DDR	DDRB
	#define _LCD_PORT	PORTB
#endif

#ifndef	_LCD_RS
	#warning "Se asignan pines por defecto"
	#define _LCD_RS		0
	#define _LCD_EN		1
	#define _LCD_D4		2
	#define _LCD_D5		3
	#define _LCD_D6		4
	#define	_LCD_D7		5		
#endif

#define  _LCD_numCOLUM	20
#define _LCD_numFILAS	4

//MODO CLEAR DISPLAY:
#define _LCD_clearDisplay	0x01

//MODO CLEAR RETURN HOME:
#define	_LCD_returnHome	0x02

//MODO SET
#define	_LCD_entryModeSet	0x04
#define _LCD_increment		0x02
#define _LCD_decrement		0x00
#define _LCD_shiftOn		0x01
#define _LCD_shiftOff		0x00


//MODO CONTROL DISPLAY
#define _LCD_displayControl	0x08
#define _LCD_displayON		0x04
#define _LCD_displayOFF		0x00
#define _LCD_cursorOn		0x02
#define _LCD_cursorOff		0x00
#define _LCD_blinkOn		0x01
#define _LCD_blinkOff		0x00

//MODO DESPLAZAMIENTO DEL CURSOR:

#define _LCD_cursorDisplayShift	0x10
#define _LCD_shift			0x08
#define _LCD_cursorShift	0x00
#define _LCD_shiftRight		0x04
#define _LCD_shiftLeft		0x00

//MODO FUNCION SET:

#define	_LCD_funcionSet		0x20
#define _LCD_8BitMode		0x10
#define _LCD_4BitMode		0x00
#define _LCD_2Line			0x08
#define _LCD_1Line			0x00
#define _LCD_5X10			0x04
#define _LCD_5X8			0x00

//MODO CGRAM:
#define _LCD_set_CGRAM_ADDR 0x40

//MODO DDRAM
#define _LCD_set_DDRAM_ADDR	0x80

//void lcd_init(void);
//void lcd_write(uint8_t letra);
//void lcd_command(uint8_t cmd);
//void _write_nibble(uint8_t nibble);
//void _send_byte(uint8_t value, uint8_t mode);
