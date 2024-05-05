/*
 * LCD_FUNCTION.h
 *
 * Created: 2/8/2024 10:39:58 PM
 *  Author: Mohamed
 */ 


#ifndef LCD_FUNCTION_H_
#define LCD_FUNCTION_H_
#include "STD_TYPEDEF.h"
//TO CHOOSE THE MODE 
#define LCD_MODE 4

#if LCD_MODE ==4

#define LCD_PIN4 DIO_PINA4
#define LCD_PIN5 DIO_PINA5
#define LCD_PIN6 DIO_PINA6
#define LCD_PIN7 DIO_PINA7
//  DIO_SIT_BIT_DIRICTION (DIO_PINC0,OUTPUT);
//  DIO_SIT_BIT_VALUO (DIO_PINC0,HIGH);
#elif LCD_MODE ==8

#define LCD_PIN0 DIO_PINA0
#define LCD_PIN1 DIO_PINA1
#define LCD_PIN2 DIO_PINA2
#define LCD_PIN3 DIO_PINA3
#define LCD_PIN4 DIO_PINA4
#define LCD_PIN5 DIO_PINA5
#define LCD_PIN6 DIO_PINA6
#define LCD_PIN7 DIO_PINA7

#endif
 
#define LCD_RS  DIO_PINB0
#define LCD_RW  DIO_PINB1
#define LCD_E  DIO_PINB3

void LCD_INIT(void);
void LCD_SEND_DATA(u8 DATA);
void LCD_WRITE_COMAND(u8);
void LCD_WRITE_CHAR(u8);
void LCD_WRITE_STRING(u8 * DATA);
void LCD_WRITE_NUMBER(u32 DATA);
void LCD_CLEAR(void);
void LCD_GOTO(u8 x, u8 y);
#endif /* LCD_FUNCTION_H_ */