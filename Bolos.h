/*
 * Bolos.h
 *
 * Created: 10/05/2022 9:27:04
 *  Author: adria
 */ 


#ifndef BOLOS_H_
#define BOLOS_H_

#include <avr/io.h>
#include <avr/common.h>
#include <stdio.h>

#define BOLOS_PORT PORTD
#define BOLOS_DDR  DDRD
#define BOLOS_PIN  PIND

void detectarBolos(void (*func)(), uint8_t* );

void configBolos();

void setFlagsToOne(uint8_t* );

void setFlagsToZero(uint8_t* );


#endif /* BOLOS_H_ */