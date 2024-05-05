/*
 * devices.c
 *
 * Created: 4/6/2024 9:04:08 PM
 *  Author: Mohamed
 */ 
#include "STD_DIO.h"
#include "BIT_MATH.h"
#include "DIO_FINCTION.h"
#include "STD_TYPEDEF.h"
#include "TIMER2_FUNCTION.h"
#include "PROJECT_FUNCTION_HEADERS.h"
#include "PROJECT_PINS.h"
#include "ADC_FUNCTION.h"
/************************************************************************/
/*                           HEATER                                     */
/************************************************************************/
void SET_HEATER(u8 PRISINTAGE)
{
	TIMER2_INIT(TIMER2_PHASE_CORRECT_PWM,CLEAN_OC2);
	TIMER2_FREQUANCE(F_TIMER2_244);
	TIMER2_PHASE_CORRECT_PWM_PRISNTAGE(CLEAN_OC2,PRISINTAGE);
}
/************************************************************************/
/*                          HEATER LEAD                                 */
/************************************************************************/
void SET_HEATER_LED(u8 STATE)
{
	if(STATE==ON)
	{
		DIO_SIT_BIT_VALUO(HEATER_LED_PIN,HIGH);
	}
	else if(STATE==OFF)
	{
		DIO_SIT_BIT_VALUO(HEATER_LED_PIN,LOW);
	}
}
/************************************************************************/
/*                          cooler                                      */
/************************************************************************/
void SET_COOLER(u8 STATE)
{
	if(STATE==ON)
	{
		DIO_SIT_BIT_VALUO(COOLER_PIN,HIGH);
	}
	else if(STATE==OFF)
	{
		DIO_SIT_BIT_VALUO(COOLER_PIN,LOW);
	}
}
/************************************************************************/
/*                          cooler LED                                  */
/************************************************************************/
void SET_COOLER_LED(u8 STATE)
{
	if(STATE==ON)
	{
		DIO_SIT_BIT_VALUO(COOLER_LED_PIN,HIGH);
	}
	else if(STATE==OFF)
	{
		DIO_SIT_BIT_VALUO(COOLER_LED_PIN,LOW);
	}
}
/************************************************************************/
/*                         EMERGANCY                                    */
/************************************************************************/
void SET_EMERGANCY(u8 STATE)
{
	if(STATE==ON)
	{
		DIO_SIT_BIT_VALUO(EMERGANCY_PIN,HIGH);
	}
	else if(STATE==OFF)
	{
		DIO_SIT_BIT_VALUO(EMERGANCY_PIN,LOW);
	}
}
/************************************************************************/
/*                       FIRE FIGHTING PUMP                             */
/************************************************************************/
void SET_FIRE_FIGHTING_PUMP(u8 STATE)
{
	if(STATE==ON)
	{
		DIO_SIT_BIT_VALUO(FIRE_FIGHTING_PUMP_PIN,HIGH);
	}
	else if(STATE==OFF)
	{
		DIO_SIT_BIT_VALUO(FIRE_FIGHTING_PUMP_PIN,LOW);
	}
}
/************************************************************************/
/*                             THERMOSTAT                               */
/************************************************************************/
u16 THERMOSTAT_READ(void)
{
	return ADC_ANALOG_PRISANTAGE(ADC_READ(ADCPIN1));
}