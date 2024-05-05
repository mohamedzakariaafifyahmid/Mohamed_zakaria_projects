/*
 * TIMER1FUNCTION.h
 *
 * Created: 3/15/2024 11:47:26 AM
 *  Author: Mohamed
 */ 


#ifndef TIMER1FUNCTION_H_
#define TIMER1FUNCTION_H_
/************************************************************************/
/*                            TCCR1A                                    */
/************************************************************************/
#define WGM10	0  //Waveform Generation Mode
#define WGM11	1  //Waveform Generation Mode
#define FOC1A	2  //FOC1b
#define FOC1B	3  //FOC1A
#define COM1B0	4  //Compare Output Mode for Channel B
#define COM1B1	5  //Compare Output Mode for Channel B
#define COM1A0	6  //Compare Output Mode for Channel B
#define COM1A1	7  //Compare Output Mode for Channel A
/************************************************************************/
/*                            TCCR1B                                    */
/************************************************************************/
#define CS10	0  //Input Capture Noise Canceler
#define CS11	1  //Input Capture Edge Select
#define CS12	2  //Reserved Bit
#define WGM12	3  //Waveform Generation Mode
#define WGM13	4  //Waveform Generation Mode
#define ICES1	6  //Clock Select
#define ICNC1	7  //Clock Select
/************************************************************************/
/*                          TIMSK                                       */
/************************************************************************/
#define  TOIE1   2
#define  OCIE1B  3
#define  OCIE1A  4
#define  TICIE1  5

/************************************************************************/
/*                         FUNCTION                                     */
/************************************************************************/
void TIMER1_INIT(void);
//PIN
#define  A 0
#define  B 1
//MOOD
#define TIMER1_NORMAL       0
#define TIMER1_CTC          1
#define TIMER1_FASTPWM      2
#define TIMER1_PHASECORRECT 3
//*********************************************************************
void TIMER1_setFrequency(u16 pwm_frequency);
void TIMER1_Duty(u8 duty);
#define TIMER1_PWM_NON_INVERTING 0
#define TIMER1_PWM_INVERTING     1
#endif /* TIMER1FUNCTION_H_ */