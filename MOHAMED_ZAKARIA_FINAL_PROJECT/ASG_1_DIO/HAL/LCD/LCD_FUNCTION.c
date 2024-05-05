/*
 * LCD_FUNCTION.c
 *
 * Created: 2/8/2024 10:40:29 PM
 *  Author: Mohamed
 */ 
#define F_CPU 16000000
#include <util/delay.h>
#include "LCD_FUNCTION.h"
#include "BIT_MATH.h"
#include "STD_DIO.h"
#include "DIO_FINCTION.h"
#include "IO_ADDRESSES1.h"
void LCD_INIT(void)
{
   #if LCD_MODE ==4
   DIO_SIT_BIT_DIRICTION(LCD_PIN4,OUTPUT);
   DIO_SIT_BIT_DIRICTION(LCD_PIN5,OUTPUT);
   DIO_SIT_BIT_DIRICTION(LCD_PIN6,OUTPUT);
   DIO_SIT_BIT_DIRICTION(LCD_PIN7,OUTPUT);
   //LCD ORDERS PINS
   DIO_SIT_BIT_DIRICTION(LCD_RS,OUTPUT);
   DIO_SIT_BIT_DIRICTION(LCD_RW,OUTPUT);
   DIO_SIT_BIT_DIRICTION(LCD_E,OUTPUT);
   //for 4 bit
   LCD_WRITE_COMAND(0b00000010);
   _delay_ms(50);
   //function set
   LCD_WRITE_COMAND(0b00101000);
   _delay_ms(1);
   //Display on/off
   LCD_WRITE_COMAND(0b00001110);
   _delay_ms(1);
   //clear
   LCD_CLEAR();
   _delay_ms(5);
   //Entry mode set
   LCD_WRITE_COMAND(0b00000110);
   
   #elif LCD_MODE ==8
   //LCD DATA PINS
   DIO_SIT_BYTE_DIRICTION(DDRA,OUTPUT);
   //LCD ORDERS PINS
   DIO_SIT_BIT_DIRICTION(LCD_RS,OUTPUT);
   DIO_SIT_BIT_DIRICTION(LCD_RW,OUTPUT);
   DIO_SIT_BIT_DIRICTION(LCD_E,OUTPUT);
   
   _delay_ms(50);
   //function set
   LCD_WRITE_COMAND(0b00111000);
   //Display on/off
   _delay_ms(1);
   LCD_WRITE_COMAND(0b00001110);
   _delay_ms(1);
   //clear
   LCD_CLEAR();
   _delay_ms(5);
   LCD_WRITE_COMAND(0b00000110);
   #endif
}
void LCD_SEND_DATA(u8 DATA)
{
	#if LCD_MODE ==4
	DIO_SIT_BIT_VALUO(LCD_PIN4,GET_BIT(DATA,4));
	DIO_SIT_BIT_VALUO(LCD_PIN5,GET_BIT(DATA,5));
	DIO_SIT_BIT_VALUO(LCD_PIN6,GET_BIT(DATA,6));
	DIO_SIT_BIT_VALUO(LCD_PIN7,GET_BIT(DATA,7));
	//the 
	DIO_SIT_BIT_VALUO(LCD_E,HIGH);
	_delay_ms(1);
	DIO_SIT_BIT_VALUO(LCD_E,LOW);
	_delay_ms(1);
	DIO_SIT_BIT_VALUO(LCD_PIN4,GET_BIT(DATA,0));
	DIO_SIT_BIT_VALUO(LCD_PIN5,GET_BIT(DATA,1));
	DIO_SIT_BIT_VALUO(LCD_PIN6,GET_BIT(DATA,2));
	DIO_SIT_BIT_VALUO(LCD_PIN7,GET_BIT(DATA,3));
	//the
	DIO_SIT_BIT_VALUO(LCD_E,HIGH);
	_delay_ms(1);
	DIO_SIT_BIT_VALUO(LCD_E,LOW);
	_delay_ms(1);
	#elif LCD_MODE ==8
	DIO_SIT_BIT_VALUO(LCD_PIN0,(GET_BIT(DATA,0)));
	DIO_SIT_BIT_VALUO(LCD_PIN1,(GET_BIT(DATA,1)));
	DIO_SIT_BIT_VALUO(LCD_PIN2,(GET_BIT(DATA,2)));
	DIO_SIT_BIT_VALUO(LCD_PIN3,(GET_BIT(DATA,3)));
	DIO_SIT_BIT_VALUO(LCD_PIN4,(GET_BIT(DATA,4)));
	DIO_SIT_BIT_VALUO(LCD_PIN5,(GET_BIT(DATA,5)));
	DIO_SIT_BIT_VALUO(LCD_PIN6,(GET_BIT(DATA,6)));
	DIO_SIT_BIT_VALUO(LCD_PIN7,(GET_BIT(DATA,7)));
	//the bualce
	DIO_SIT_BIT_VALUO(LCD_E,HIGH);
	_delay_ms(1);
	DIO_SIT_BIT_VALUO(LCD_E,LOW);
	_delay_ms(1);
	#endif
}
void LCD_CLEAR(void)
{
	LCD_WRITE_COMAND(0b00000001);
}
void LCD_WRITE_COMAND(u8 DATA)
{
	DIO_SIT_BIT_VALUO(LCD_RS,LOW);
	DIO_SIT_BIT_VALUO(LCD_RW,LOW);
	LCD_SEND_DATA(DATA);
}
void LCD_WRITE_CHAR(u8 DATA)
{
	DIO_SIT_BIT_VALUO(LCD_RS,HIGH);
	DIO_SIT_BIT_VALUO(LCD_RW,LOW);
	LCD_SEND_DATA(DATA);
} 
void LCD_WRITE_STRING(u8 * DATA)
{
	u8 i=0;
	while(DATA[i] != '\0')
	{
		LCD_WRITE_CHAR(DATA[i]);
		i++;
	}
}
void LCD_WRITE_NUMBER(u32 num)
{
	if(num < 0)
	{
		LCD_WRITE_CHAR('-');
		num = num * -1;
	}
	if (num==0)
	{
		LCD_WRITE_CHAR(48);
	}
	else
	{
		u8 i =0;
		u8 arr[16];
		while(num != 0)
		{
			arr[i] = (num%10) + 48;
			i++;
			num = num/10;
		}
		s8 k;
		for(k=i-1; k>=0; k--)
		{
			LCD_WRITE_CHAR(arr[k]);
		}
	}
}
void LCD_GOTO(u8 x, u8 y)
{
	if(y == 1)
	{
		//line 1
		LCD_WRITE_COMAND(0x80 + x);
	}
	else if( y == 2)
	{
		//line 2
		LCD_WRITE_COMAND(0xc0 +  x );
	}
	
}