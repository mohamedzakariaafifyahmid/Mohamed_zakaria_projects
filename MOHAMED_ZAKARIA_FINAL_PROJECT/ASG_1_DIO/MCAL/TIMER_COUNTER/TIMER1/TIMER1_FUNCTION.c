/*
 * TIMER1_FUNCTION.c
 *
 * Created: 3/15/2024 11:36:22 AM
 *  Author: Mohamed
 */ 
#include "TIMER_COUNTER_ADDRESES.h"
#include "TIMER1FUNCTION.h"
#include "GENERAL_INTERRAPT.h"
#include "STD_TYPEDEF.h"
#include "BIT_MATH.h"
#include "DIO_FINCTION.h"
void TIMER1_INIT()
{
	DIO_SIT_BIT_DIRICTION(DIO_PIND5,OUTPUT);
	RESET_BIT(TCCR1A, FOC1A);
	RESET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	RESET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
}
void TIMER1_Duty(u8 duty)
{
	OCR1A = (duty*ICR1/100) -1;
}
void TIMER1_setFrequency(u16 pwm_frequency)
{
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	RESET_BIT(TCCR1B,CS12);
	ICR1 = (16000000/(64.0*pwm_frequency))-1;
}
