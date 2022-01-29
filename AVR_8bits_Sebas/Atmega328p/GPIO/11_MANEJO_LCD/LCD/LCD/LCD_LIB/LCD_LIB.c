/*
 * LCD_LIB.c
 *
 * Created: 16/01/2022 12:01:40
 *  Author: Diego
 */ 

#include "LCD_LIB.h"

//void lcd_init(void);
//void _write_nibble(uint8_t nibble);
//void _send_byte(uint8_t value, uint8_t mode);
//void lcd_write(uint8_t letra);
//void lcd_command(uint8_t cmd);


void _write_nibble(uint8_t nibble){
	
	if((nibble & 1)==0) _LCD_PORT &=~(1<<_LCD_D4); else _LCD_PORT |= (1<<_LCD_D4);
	if((nibble & 2)==0) _LCD_PORT &=~(1<<_LCD_D5); else _LCD_PORT |= (1<<_LCD_D5);
	if((nibble & 4)==0) _LCD_PORT &=~(1<<_LCD_D6); else _LCD_PORT |= (1<<_LCD_D6);
	if((nibble & 8)==0) _LCD_PORT &=~(1<<_LCD_D7); else _LCD_PORT |= (1<<_LCD_D7);
	
	_LCD_PORT &= ~(1<<_LCD_EN);
	_LCD_PORT |= (1<<_LCD_EN);
	_LCD_PORT &= ~(1<<_LCD_EN);
	
	_delay_us(300);
}

void _send_byte(uint8_t value, uint8_t mode){
	
	switch(mode){
		
		case 0: _LCD_PORT &= ~(1<<_LCD_RS);break; //RS = 0  -> comando
		case 1: _LCD_PORT |= (1<<_LCD_RS);break;  //RS = 1  -> dato
		
	}
	
	_write_nibble(value>>4);
	_write_nibble(value & 0x0F);
		
}

void lcd_write(uint8_t letra){
	
	_send_byte(letra,_DATA);
}

void lcd_command(uint8_t cmd){
	
	_send_byte(cmd,_COMANDO);
}

void lcd_init(void){
	
	//incializar la lcd
	_LCD_DDR |= (1<<_LCD_RS)|(1<<_LCD_EN)|(1<<_LCD_D4)|(1<<_LCD_D5)|(1<<_LCD_D6)|(1<<_LCD_D7);
	_LCD_PORT &= ~((1<<_LCD_RS)|(1<<_LCD_EN)|(1<<_LCD_D4)|(1<<_LCD_D5)|(1<<_LCD_D6)|(1<<_LCD_D7));
	_delay_ms(15);
	_write_nibble(0x03);
	_delay_ms(4.1);
	_write_nibble(0x03);
	_delay_us(100);
	_write_nibble(0x03);
	_write_nibble(0x02);
	
	//configurar la lcd
	lcd_command(_LCD_funcionSet | _LCD_4BitMode | _LCD_2Line | _LCD_5X8);
	lcd_command(_LCD_displayControl | _LCD_displayON | _LCD_cursorOn | _LCD_blinkOn);
}