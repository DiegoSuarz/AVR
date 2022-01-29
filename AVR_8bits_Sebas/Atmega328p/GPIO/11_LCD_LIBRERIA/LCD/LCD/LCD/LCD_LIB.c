/*
 * LCD_LIB.c
 *
 * Created: 16/01/2022 12:01:40
 *  Author: Diego
 */ 

#include "LCD_LIB.h"

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
	lcd_command(_LCD_displayControl | _LCD_displayON | _LCD_cursorOn | _LCD_blinkOff);
}

void lcd_string(char *str){
	
	while(*str != NULL){
		lcd_write(*str);
		str++;
	}
}

void lcd_set_cursor(uint8_t fila,uint8_t columna){
	static uint8_t local_mem[4]={0x00,0x40,0x14,0x54};
	lcd_command(_LCD_set_DDRAM_ADDR | (local_mem[fila-1]+(columna-1)));
	
}

void lcd_printf(char *str,...){
	
	va_list args;
	va_start(args,str);
	vsnprintf(_lcd_buffer_, _LCD_numCOLUM+1, str, args);
	va_end(args);
	lcd_string(_lcd_buffer_);
	
}

void lcd_clear(void){
	lcd_command(_LCD_clearDisplay);
	_delay_ms(2);
}


void lcd_return_home(void){
	lcd_command(_LCD_returnHome);
	_delay_ms(2);
	
}

void lcd_on(void){
	
	lcd_command(_LCD_displayControl|_LCD_displayON);
	_delay_us(40);
}

void lcd_off(void){
	
	lcd_command(_LCD_displayControl|_LCD_displayOFF);
	_delay_us(40);
}

void lcd_enable_blink(void){
	lcd_command(_LCD_displayControl |_LCD_blinkOn);
	_delay_us(40);
}


void lcd_disable_blink(void){
	lcd_command(_LCD_displayControl |_LCD_blinkOff);
	_delay_us(40);
}


void lcd_enable_cursor(void){
	_lcd_params |= _LCD_cursorOn;
	lcd_command(_LCD_displayControl |_lcd_params);
	_delay_us(40);
}
void lcd_disable_cursor(void){
	_lcd_params &= ~_LCD_cursorOn;
	lcd_command(_LCD_displayControl |_LCD_cursorOff);
	_delay_us(40);
}

void lcd_scroll_left(void){
	
	
}
void lcd_scroll_right(void);

void lcd_custom_char(uint8_t men, uint8_t *charmap);