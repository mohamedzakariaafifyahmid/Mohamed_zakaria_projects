/*
 * KEYPAD_FUNCTION.c
 *
 * Created: 2/13/2024 2:32:14 PM
 *  Author: Mohamed
 */ 
#include "KEYPAD_FUNCTION.h"
#include "IO_ADDRESSES1.h"
void KEYPAD_INIT(void)
{
	DIO_SIT_BIT_DIRICTION(KEYPAD_ROW1,INPUT);
	DIO_SIT_BIT_DIRICTION(KEYPAD_ROW2,INPUT);
	DIO_SIT_BIT_DIRICTION(KEYPAD_ROW3,INPUT);
	DIO_SIT_BIT_DIRICTION(KEYPAD_ROW4,INPUT);
	
 	DIO_ACTIVE_PULL_UP(KEYPAD_ROW1);
 	DIO_ACTIVE_PULL_UP(KEYPAD_ROW2);
 	DIO_ACTIVE_PULL_UP(KEYPAD_ROW3);
 	DIO_ACTIVE_PULL_UP(KEYPAD_ROW4);
	
	DIO_SIT_BIT_DIRICTION(KEYPAD_COLOUM1,OUTPUT);
	DIO_SIT_BIT_DIRICTION(KEYPAD_COLOUM2,OUTPUT);
	DIO_SIT_BIT_DIRICTION(KEYPAD_COLOUM3,OUTPUT);
	DIO_SIT_BIT_DIRICTION(KEYPAD_COLOUM4,OUTPUT);
}
u8 KEYPAD_READ(void)
{
	//CASE1
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM1,LOW);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM2,HIGH);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM3,HIGH);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM4,HIGH);
	
	if (DIO_INPUT(KEYPAD_ROW1)==0)
	{
		return KEYPAD_ROW1_COLOUM1;
	}
	else if (DIO_INPUT(KEYPAD_ROW2)==0)
	{
		return KEYPAD_ROW2_COLOUM1;
	}
	else if (DIO_INPUT(KEYPAD_ROW3)==0)
	{
		return KEYPAD_ROW3_COLOUM1;
	}
	else if (DIO_INPUT(KEYPAD_ROW4)==0)
	{
		return KEYPAD_ROW4_COLOUM1;
	}
	else if (DIO_INPUT(KEYPAD_ROW1)==0)
	{
		return KEYPAD_ROW1_COLOUM1;
	}
	
	//CASE2
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM1,HIGH);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM2,LOW);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM3,HIGH);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM4,HIGH);
	
	if (DIO_INPUT(KEYPAD_ROW1)==0)
	{
		return KEYPAD_ROW1_COLOUM2;
	}
	else if (DIO_INPUT(KEYPAD_ROW2)==0)
	{
		return KEYPAD_ROW2_COLOUM2;
	}
	else if (DIO_INPUT(KEYPAD_ROW3)==0)
	{
		return KEYPAD_ROW3_COLOUM2;
	}
	else if (DIO_INPUT(KEYPAD_ROW4)==0)
	{
		return KEYPAD_ROW4_COLOUM2;
	}
	
	//CASE3
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM1,HIGH);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM2,HIGH);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM3,LOW);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM4,HIGH);
	
	if (DIO_INPUT(KEYPAD_ROW1)==0)
	{
		return KEYPAD_ROW1_COLOUM3;
	}
	else if (DIO_INPUT(KEYPAD_ROW2)==0)
	{
		return KEYPAD_ROW2_COLOUM3;
	}
	else if (DIO_INPUT(KEYPAD_ROW3)==0)
	{
		return KEYPAD_ROW3_COLOUM3;
	}
	else if (DIO_INPUT(KEYPAD_ROW4)==0)
	{
		return KEYPAD_ROW4_COLOUM3;
	}
	
	//CASE4
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM1,HIGH);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM2,HIGH);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM3,HIGH);
	DIO_SIT_BIT_VALUO(KEYPAD_COLOUM4,LOW);
	
	if (DIO_INPUT(KEYPAD_ROW1)==0)
	{
		return KEYPAD_ROW1_COLOUM4;
	}
	else if (DIO_INPUT(KEYPAD_ROW2)==0)
	{
		return KEYPAD_ROW2_COLOUM4;
	}
	else if (DIO_INPUT(KEYPAD_ROW3)==0)
	{
		return KEYPAD_ROW3_COLOUM4;
	}
	else if (DIO_INPUT(KEYPAD_ROW4)==0)
	{
		return KEYPAD_ROW4_COLOUM4;
	}
	return KEYPAD_UNPRISD;
}