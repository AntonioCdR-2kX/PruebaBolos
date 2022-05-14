/*
 * Display.h
 *
 * Created: 12/05/2022 12:22:34
 *  Author: adria
 */ 

#ifndef DISPLAY_H
#define DISPLAY_H

#define DISPLAY_DDR DDRB
#define DISPLAY_PORT PORTB
#define DIAPLAY_PIN PINB

#define UNIDADES 0
#define DECENAS 1

#include <avr/interrupt.h>
#include <avr/io.h>


enum state_display
{
	S_DISPLAY_MODO_NORMAL,
	S_DISPLAY_MODO_PARPADEANDO,
	S_APAGADO
	};
	




// Setea el numero que va a mostrarse
void display_setNumber(int);

void display_update();

void display_updateParpadeando();

void display_setup();

void display_p();

void display_setOn();

void display_setOff();



#endif