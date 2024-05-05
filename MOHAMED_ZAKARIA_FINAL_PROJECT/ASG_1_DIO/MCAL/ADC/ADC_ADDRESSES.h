/*
 * ADC_ADDRESSES.h
 *
 * Created: 2/23/2024 3:01:25 PM
 *  Author: Mohamed
 */ 


#ifndef ADC_ADDRESSES_H_
#define ADC_ADDRESSES_H_
//BIN7&6 REFRANCE
//Bit 5 Left Adjust Result
//Bits 4:0  Analog Channel and Gain Selection Bits
#define MDMUX *(volatile u8*)0x27
// Bit 7 – ADEN: ADC Enable
// Bit 6 – ADSC: ADC Start Conversion
// Bit 5 – ADATE: ADC Auto Trigger Enable
// Bit 4 – ADIF: ADC Interrupt Flag
// Bit 3 – ADIE: ADC Interrupt Enable
// Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
#define ADCSRA *(volatile u8*)0x26
//ADC HIGH
#define ADCH *(volatile u8*)0x25
//ADC LOW
#define ADCL *(volatile u8*)0x24
//THE 10 BITE
#define ADCLH  *(volatile u16*)0x24

#endif /* ADC_ADDRESSES_H_ */