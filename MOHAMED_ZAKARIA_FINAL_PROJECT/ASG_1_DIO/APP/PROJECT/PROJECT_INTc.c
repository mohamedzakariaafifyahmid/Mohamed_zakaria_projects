/*
 * PROJECT_INTc.c
 *
 * Created: 4/6/2024 1:32:39 AM
 *  Author: Mohamed
 */ 
#include "STD_DIO.h"
#include "BIT_MATH.h"
#include "DIO_FINCTION.h"
#include "SEVEN_SEGMENT.h"
#include "ADC_FUNCTION.h"
#include "PROJECT_PINS.h"
#include "GENERAL_INTERRAPT.h"
#include "EXTERNAL_ENTERRAPT_FUNCTIONS.h"
#include "TIMER0.h"
void PROJECT_INIT(void)
{
	/************************************************************************/
	/*                             D/O                                      */
	/************************************************************************/
	DIO_SIT_BIT_DIRICTION(HEATER_LED_PIN,OUTPUT);
	DIO_SIT_BIT_DIRICTION(COOLER_PIN,OUTPUT);
	DIO_SIT_BIT_DIRICTION(COOLER_LED_PIN,OUTPUT);
	DIO_SIT_BIT_DIRICTION(EMERGANCY_PIN,OUTPUT);
	DIO_SIT_BIT_DIRICTION(FIRE_FIGHTING_PUMP_PIN,OUTPUT);
	/************************************************************************/
	/*                              seven segmant                           */
	/************************************************************************/
	SEVEN_SEGMENT_INIT();
	/************************************************************************/
	/*                            interrapt                                 */
	/************************************************************************/
	GENERAL_INTERRAPT_ENABLE;
	EXTERNAL_ETERRAPT_ENABLE(EXTERNAL_INTERRAPT0,EXTERNAL_INTERRAPTINPUT_ANY_lOGESTIC_CHANGE);
	EXTERNAL_ETERRAPT_ENABLE(EXTERNAL_INTERRAPT1,EXTERNAL_INTERRAPTINPUT_RISING_EDGE);
	EXTERNAL_ETERRAPT_ENABLE(EXTERNAL_INTERRAPT2,EXTERNAL_INTERRAPTINPUT_RISING_EDGE);
	/************************************************************************/
	/*                            adc                                       */
	/************************************************************************/
	ADC_INIT();
	/************************************************************************/
	/*                            timer0                                    */
	/************************************************************************/
 	TIMER0_INIT(TIMER0_NORMAL,6);
 	TIMER0_START(TIMER0_CLK_DIV_1024);	
	LCD_INIT();
}
