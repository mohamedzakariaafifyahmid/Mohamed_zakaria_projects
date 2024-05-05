/*
 * ADC_FUNCTION.h
 *
 * Created: 2/23/2024 3:14:41 PM
 *  Author: Mohamed
 */ 


#ifndef ADC_FUNCTION_H_
#define ADC_FUNCTION_H_

#include "STD_TYPEDEF.h"
// MDMUX 
//REFRANCE VOLTAGE
#define ADC_REFRANCE_VOLTAGE_AREF 0
#define ADC_REFRANCE_VOLTAGE_AVCC 1
#define ADC_REFRANCE_VOLTAGE_Reserved 2
#define ADC_REFRANCE_VOLTAGE_Internal 3
//bits
#define REFS1 7
#define REFS0 6
void ADC_REFRANCE_VOLTAGE(u8 state);
// ADLAR: ADC Left Adjust Result
#define ADLAR 5
#define ADC_LEFT_ADJUST_ENABLE   SET_BIT(MDMUX,ADLAR)
#define ADC_LEFT_ADJUST_DESABLE  RESET_BIT(MDMUX,ADLAR)
// Analog Channel and Gain Selection Bits
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0
//?? GAIN ????
#define ADCPIN0 0
#define ADCPIN1 1
#define ADCPIN2 2
#define ADCPIN3 3
#define ADCPIN4 4
#define ADCPIN5 5
#define ADCPIN6 6
#define ADCPIN7 7
u16 ADC_RESD(u8);
// ADCSRA
// Prescaler Select Bits
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
void ADC_PRESCALER_SELECT_BITS(void);
// ADC WITH INTERRABT
#define ADC_ETERRAPT_ENABLE SET_BIT(ADCSRA,3)
#define ADC_ETERRAPT_DESABLE RESET_BIT(ADCSRA,3)
//ADC ITERRAPT FLAGE
u8 ADC_ITERRAPT_FLAGE(void);
//ADC Auto Trigger Enable
#define ADC_AUTO_TRIGGER_ENABLE SET_BIT(ADCSRA,5)
#define ADC_AUTO_TRIGGER_DESABLE RESET_BIT(ADCSRA,5)
//ADC Start Conversion
#define ADC_START_CONVERSION SET_BIT(ADCSRA,6)
//ADC ENABLE 
#define ADEN 7
#define ADC_ENABLE SET_BIT(ADCSRA,ADEN)
void ADC_INIT(void);
float ADC_convertAnalog(u16 digitalValue);
u16 ADC_READ(u8 x);
u16 ADC_ANALOG_PRISANTAGE(u16 DIGITALVALUE);

#endif /* ADC_FUNCTION_H_ */