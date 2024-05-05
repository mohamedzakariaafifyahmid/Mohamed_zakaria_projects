/*
 * TIMER_COUNTER_ADDRESES.h
 *
 * Created: 3/1/2024 5:29:27 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER_COUNTER_ADDRESES_H_
#define TIMER_COUNTER_ADDRESES_H_
#include "STD_TYPEDEF.h"
//TIMER0
//THE TIMER0 COUNTER
#define TCCR0 	*((volatile u8*)0x53)
#define TCNT0 	*((volatile u8*)0x52)
//TIMER CONTROL
#define OCR0 	*((volatile u8*)0x5C)
//INTERRAPT TIMER ENABLE
#define TIMSK 	*((volatile u8*)0x59)
//***************************************************************************************************************************
//TIMER1
#define TCCR1A	*((volatile u8*)0x4F)
#define TCCR1B	*((volatile u8*)0x4E)
#define TCNT1	*((volatile u16*)0x4C)
#define OCR1A	*((volatile u16*)0x4A)
#define OCR1B	*((volatile u16*)0x48)
#define ICR1	*((volatile u16*)0x46)
#define TIFR	*((volatile u8*)0x58)
//*************************************************************************************************************************
//TIMER2
//TIMER2 CONTROL  
#define TCCR2 	*((volatile u8*)0x45)
//TIMER2 COINTER
#define TCNT2 	*((volatile u8*)0x44)
//TIMER2 COMBAR MATCH REGESTER
#define OCR2 	*((volatile u8*)0x43)
#endif /* TIMER_COUNTER_ADDRESES_H_ */