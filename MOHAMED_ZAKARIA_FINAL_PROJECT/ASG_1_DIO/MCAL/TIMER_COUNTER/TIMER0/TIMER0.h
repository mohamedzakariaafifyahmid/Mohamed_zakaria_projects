/*
 * TIMER0.h
 *
 * Created: 3/1/2024 5:39:08 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "TIMER_COUNTER_ADDRESES.h"
#include "STD_TYPEDEF.h"
//TCCR0 REGESTERS
#define FOC0		7
#define WGM00		6  //TIMER MOOD
#define COM01		5  //CTC OC 
#define COM00		4  //CTC 0C
#define WGM01		3  //TIMER MOOD
#define CS02		2
#define CS01		1
#define CS00		0
//************************************************************************************************************************
//TO INIT TIMR0
//IF IT WORK AS NORMAL PWM CTC FAST PWM
void TIMER0_INIT(u8,u8);
#define TIMER0_NORMAL            0
#define TIMER0_PHASE_CORRECT_PWM 1
#define TIMER0_CTC               2
#define TIMER0_FAST_PWM          3
//************************************************************************************************************************
//THE OUTPUT TYPE
#define  OC0_DISCONNECTED 0
#define  TOGGEL_OC0       1
#define  CLEAN_OC0        2
#define  SET_OC0          3
//************************************************************************************************************************
//THE PRESCALER
void TIMER0_START(u8);
#define TIMER0_CLK_DIV_1			0
#define TIMER0_CLK_DIV_8			1
#define TIMER0_CLK_DIV_64			2
#define TIMER0_CLK_DIV_256			3
#define TIMER0_CLK_DIV_1024			4
#define TIMER0_CLK_EXTERNAL_FALLING	5
#define TIMER0_CLK_EXTERNAL_RISING	6
//************************************************************************************************************************
void TIMER0_STOP(void);
void TIMER0_setPreload(u8 ticks);
u8 TIMER0_READ_TIMER(void);
void TIMER_CTC0_WRITE(u8);
//*****************************************************************************************************************
// TIMSK
#define OCIE0		1
#define TOIE0		0
void TIMER_CTC0_WRITE(u8);
void TIMER0_setCallbackCTC( void (*APP_func)() );
//*****************************************************************************************************************
//PWM
#define TOP0 255
void TIMER0_PHASE_CORRECT_PWM_PRISNTAGE(u8 STATE,u8 DUTEY);
void TIMER0_FREQUANCE(u8);
#define F_62500 0
#define F_7812  1
#define F_976   2
#define F_244   3
#define F_61    4
#endif /* TIMER0_H_ */