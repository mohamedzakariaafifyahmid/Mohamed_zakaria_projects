/*
 * ASG_1_DIO.c
 *
 * Created: 2/3/2024 9:36:47 AM
 * Author : Mohamed
 */ 

#define F_CPU 16000000
//#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPEDEF.h"
#include "IO_ADDRESSES1.h"
#include "STD_DIO.h"
#include "DIO_FINCTION.h"
#include "SEVEN_SEGMENT.h"
#include "LCD_FUNCTION.h"
#include "KEYPAD_FUNCTION.h"
#include "EXTERNAL_ENTERRAPT_FUNCTIONS.h"
#include "INTERRUPT_ADRESSES.h"
#include "GENERAL_INTERRAPT.h"
#include "ADC_ADDRESSES.h"
#include "ADC_FUNCTION.h"
#include "TIMER_COUNTER_ADDRESES.h"
#include "TIMER0.h"
#include "TIMER1FUNCTION.h"
#include "TIMER2_FUNCTION.h"
#include "PROJECT_FUNCTION_HEADERS.h"
#include "PROJECT_PINS.h"
#include "EEPROM_INIT.h"
int main(void)
{
	PROJECT_INIT();
	/*EEPROM_write(0x10,40);*/
        while (1) 
       {
		   MAIN_APP();
		   LCD_WRITE_STRING("TEMP NEEDED");
		   LCD_WRITE_NUMBER(EEPROM_read(0x10));
		   LCD_CLEAR();
  	   }
}
void PROJECT_EEPROM_INC(void)
{
	int y=EEPROM_read(0x10);
	y++;
	EEPROM_write(0x10,y);
}
void PROJECT_EEPROM_DEC(void)
{
	int y=EEPROM_read(0x10);
	y--;
	EEPROM_write(0x10,y);
}