/*
 * EEPROM_INIT.h
 *
 * Created: 5/3/2024 1:17:58 AM
 *  Author: Mohamed
 */ 


#ifndef EEPROM_INIT_H_
#define EEPROM_INIT_H_
#include "STD_TYPEDEF.h"
#define EEAR *(volatile u16*)0x3E
#define EEDR *(volatile u8*)0x3D
#define EECR *(volatile u8*)0x3C
#define EERE  0
#define EEWE  1
#define EEMWE 2
#define EERIE 3

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
u8 EEPROM_read(unsigned int uiAddress);


#endif /* EEPROM_INIT_H_ */