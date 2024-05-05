/*
 * DIO_FINCTION.c
 *
 * Created: 2/3/2024 12:57:54 PM
 *  Author: Mohamed
 */ 

#include "IO_ADDRESSES1.h"
#include "BIT_MATH.h"
#include "DIO_FINCTION.h"
#include "STD_TYPEDEF.h"
#include "BIT_MATH.h"
#include "STD_DIO.h"
//TO OUTPUT PIN
void DIO_SIT_BIT_VALUO (u8 PIN_NUMBER,u8 STATE)
{
	//OUTOUT PORTA
	if (PIN_NUMBER>=0 && PIN_NUMBER<=7)
	{
		if (STATE ==HIGH)
		{ SET_BIT(PORTA,PIN_NUMBER);}
		else if(STATE==LOW)
		{ RESET_BIT(PORTA,PIN_NUMBER);}
	}
	//OUTPUT PORTB
	if (PIN_NUMBER>=8 && PIN_NUMBER<=15)
	{
		if (STATE ==HIGH)
		{ SET_BIT(PORTB,(PIN_NUMBER-8));}
		else if(STATE==LOW)
		{ RESET_BIT(PORTB,(PIN_NUMBER-8));}
	}
	//OUTPUT PORTC
	if (PIN_NUMBER>=16 && PIN_NUMBER<=23)
	{
		if (STATE ==HIGH)
		{ SET_BIT(PORTC,(PIN_NUMBER-16));}
		else if(STATE==LOW)
		{ RESET_BIT(PORTC,(PIN_NUMBER-16));}
	}
	if (PIN_NUMBER>=24 && PIN_NUMBER<=31)
	{
		if (STATE ==HIGH)
		{ SET_BIT(PORTD,(PIN_NUMBER-24));}
		else if(STATE==LOW)
		{ RESET_BIT(PORTD,(PIN_NUMBER-24));}
	}
}

void DIO_SIT_BYTE_VALUO(u8 PORTNUMBER,u8 STATE)
{
	if (STATE==HIGH)
	{
		SIT_BYTE(PORTNUMBER);
	}
	else
	{
		RESET_BYTE(PORTNUMBER);
	}
}
void DIO_SIT_BYTE_DIRICTION(u8 PORT_NUMBER,u8 STATE)
{
	if (STATE==OUTPUT)
	{
		WRITE_BYTE(PORT_NUMBER);
	}
	else if (STATE==INPUT)
	{
		READ_BYTE(PORT_NUMBER);
	}
}
void DIO_SIT_BIT_DIRICTION(u8 PIN_NUMBER,u8 STATE )
{
	//OUTOUT PORTA
	if (PIN_NUMBER>=0 && PIN_NUMBER<=7)
	{
		if (STATE ==OUTPUT)
		{ WRITE_BIT(DDRA,PIN_NUMBER);}
		else
		{ READ_BITE(DDRA,PIN_NUMBER);}
	}
	//OUTPUT PORTB
	if (PIN_NUMBER>=8 && PIN_NUMBER<=15)
	{
		if (STATE ==OUTPUT)
		{ WRITE_BIT(DDRB,(PIN_NUMBER-8));}
		else
		{ READ_BITE(DDRB,(PIN_NUMBER-8));}
	}
	//OUTPUT PORTC
	if (PIN_NUMBER>=16 && PIN_NUMBER<=23)
	{
		if (STATE ==OUTPUT)
		{ WRITE_BIT(DDRC,(PIN_NUMBER-16));}
		else
		{ READ_BITE(DDRC,(PIN_NUMBER-16));}
	}
	if (PIN_NUMBER>=24 && PIN_NUMBER<=31)
	{
		if (STATE ==OUTPUT)
		{ WRITE_BIT(DDRD,(PIN_NUMBER-24));}
		else
		{ READ_BITE(DDRD,(PIN_NUMBER-24));}
	}
}
u8 DIO_INPUT(u8 PIN_NUMBER)
{
	if (PIN_NUMBER>=0 && PIN_NUMBER<=7)
	{
		return (GET_BIT(PINA,PIN_NUMBER));
	}
	else if (PIN_NUMBER>=8 && PIN_NUMBER<=15)
	{
		return (GET_BIT(PINB,(PIN_NUMBER-8)));
	}
	else if (PIN_NUMBER>=16 && PIN_NUMBER<=23)
	{
		return (GET_BIT(PINC,(PIN_NUMBER-16)));
	}
	else if (PIN_NUMBER>=24 && PIN_NUMBER<=31)
	{
		return (GET_BIT(PIND,(PIN_NUMBER-24)));
	}
}
void DIO_TOGGEL_BIT(u8 PIN_NUMBER)
{
	if (PIN_NUMBER>=0 && PIN_NUMBER<=7)
	{
		TOGGEL_BIT(PORTA,PIN_NUMBER);
	} 
	else if (PIN_NUMBER>=8 && PIN_NUMBER<=15)
	{
		TOGGEL_BIT(PORTB,(PIN_NUMBER-8));
	}
	else if (PIN_NUMBER>=16 && PIN_NUMBER<=23)
	{
		TOGGEL_BIT(PORTC,(PIN_NUMBER-16));
	}
	else if (PIN_NUMBER>=24 && PIN_NUMBER<=31)
	{
		TOGGEL_BIT(PORTD,(PIN_NUMBER-24));
	}
}

void DIO_ACTIVE_PULL_UP (u8 PIN_NUMBER)
{
	DIO_SIT_BIT_VALUO(PIN_NUMBER,HIGH);
}