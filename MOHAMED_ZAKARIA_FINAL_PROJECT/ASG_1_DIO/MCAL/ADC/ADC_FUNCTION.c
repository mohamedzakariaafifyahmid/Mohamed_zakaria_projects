/*
 * ADC_FUNCTION.c
 *
 * Created: 2/23/2024 5:15:57 PM
 *  Author: Mohamed
 */ 
#define F_CPU 16000000
#include "util/delay.h"
#include "ADC_ADDRESSES.h"
#include "ADC_FUNCTION.h"
#include "BIT_MATH.h"
#include "STD_TYPEDEF.h"
#include "DIO_FINCTION.h"
#include "DIO_FINCTION.h"
#include "IO_ADDRESSES1.h"
void ADC_REFRANCE_VOLTAGE(u8 state)
{
	if (state==ADC_REFRANCE_VOLTAGE_AREF)
	{
		RESET_BIT(MDMUX,REFS0);
		RESET_BIT(MDMUX,REFS1);
	}
	else if (state==ADC_REFRANCE_VOLTAGE_AVCC)
	{
		SET_BIT(MDMUX,REFS0);
		RESET_BIT(MDMUX,REFS1);
	}
	else if (state==ADC_REFRANCE_VOLTAGE_Reserved)
	{
		RESET_BIT(MDMUX,REFS0);
		SET_BIT(MDMUX,REFS1);
	}
	else if (state==ADC_REFRANCE_VOLTAGE_Internal)
	{
		SET_BIT(MDMUX,REFS0);
		SET_BIT(MDMUX,REFS1);
	}
} 
u16 ADC_READ(u8 x)
{
	SET_BIT(ADCSRA,6);
	if (x==ADCPIN0)
	{
		RESET_BIT(MDMUX,MUX0);
		RESET_BIT(MDMUX,MUX1);
		RESET_BIT(MDMUX,MUX2);
		RESET_BIT(MDMUX,MUX3);
		RESET_BIT(MDMUX,MUX4);
	}
	else if (x==ADCPIN1)
	{
		SET_BIT(MDMUX,MUX0);
		RESET_BIT(MDMUX,MUX1);
		RESET_BIT(MDMUX,MUX2);
		RESET_BIT(MDMUX,MUX3);
		RESET_BIT(MDMUX,MUX4);
	}
	else if (x==ADCPIN2)
	{
		RESET_BIT(MDMUX,MUX0);
		SET_BIT(MDMUX,MUX1);
		RESET_BIT(MDMUX,MUX2);
		RESET_BIT(MDMUX,MUX3);
		RESET_BIT(MDMUX,MUX4);
	}
	else if (x==ADCPIN3)
	{
		SET_BIT(MDMUX,MUX0);
		SET_BIT(MDMUX,MUX1);
		RESET_BIT(MDMUX,MUX2);
		RESET_BIT(MDMUX,MUX3);
		RESET_BIT(MDMUX,MUX4);
	}
	else if (x==ADCPIN4)
	{
		RESET_BIT(MDMUX,MUX0);
		RESET_BIT(MDMUX,MUX1);
		SET_BIT(MDMUX,MUX2);
		RESET_BIT(MDMUX,MUX3);
		RESET_BIT(MDMUX,MUX4);
	}
	else if (x==ADCPIN5)
	{
		SET_BIT(MDMUX,MUX0);
		RESET_BIT(MDMUX,MUX1);
		SET_BIT(MDMUX,MUX2);
		RESET_BIT(MDMUX,MUX3);
		RESET_BIT(MDMUX,MUX4);
	}
	else if (x==ADCPIN6)
	{
		RESET_BIT(MDMUX,MUX0);
		SET_BIT(MDMUX,MUX1);
		SET_BIT(MDMUX,MUX2);
		RESET_BIT(MDMUX,MUX3);
		RESET_BIT(MDMUX,MUX4);
	}
	else if (x==ADCPIN7)
	{
		SET_BIT(MDMUX,MUX0);
		SET_BIT(MDMUX,MUX1);
		SET_BIT(MDMUX,MUX2);
		RESET_BIT(MDMUX,MUX3);
		RESET_BIT(MDMUX,MUX4);
	}
	/*ADC_START_CONVERSION;*/
	while(GET_BIT(ADCSRA,6)==1);
	//ADCLH=ADCLH & 0B0000001111111111;
	return ADCLH;
}
void ADC_PRESCALER_SELECT_BITS(void)
{
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}
u8 ADC_ITERRAPT_FLAGE(void)
{
	return GET_BIT(ADCSRA,4);
} 
void ADC_INIT(void)
{
	SET_BIT(ADCSRA,ADEN);
	ADC_REFRANCE_VOLTAGE(ADC_REFRANCE_VOLTAGE_AVCC);
	ADC_PRESCALER_SELECT_BITS(); 
}
float ADC_convertAnalog(u16 digitalValue)
{
	return (digitalValue * (5.0 / 1023 ));
}
u16 ADC_ANALOG_PRISANTAGE(u16 DIGITALVALUE)
{
	return ((ADC_convertAnalog(DIGITALVALUE)/5)*100);
}