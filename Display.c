/*
 * Display.c
 *
 * Created: 12/05/2022 12:22:15
 *  Author: adria
 */ 

#include "Display.h"

volatile uint8_t digits[2];
volatile uint8_t curr_digit = 0xFF;
enum state_display modo = S_DISPLAY_MODO_NORMAL;
int contador = 0;

// Bit:    7     6 5 4 3 2 1 0
//		selector g f e d c b a
//               
uint8_t display_d2s(int par)
{
	switch(par)
	{
		case 0:
			return 0b00111111;
		case 1:
			return 0b00000110; //
		case 2:
			return 0b01011011;
		case 3:
			return 0b01001111;
		case 4:
			return 0b01100110;//
		case 5:
			return 0b01101101;//
		case 6:
			return 0b01111101;//xd
		case 7:
			return 0b00000111; // xd
		case 8:
			return 0b01111111; //xd
		case 9:
			return 0b01101111; // xd
		default:
			return 0b00000001;			
	}
}

void display_setNumber(int par)
{
	digits[UNIDADES] = display_d2s( par % 10);
	digits[DECENAS] = display_d2s( par / 10);
}

void display_update()
{
	static uint8_t selector = 0;
	
	if(selector == 0)
	{
		DISPLAY_PORT = 0b00000000 | digits[0];
		selector = 1;
		return;
	}
	else
	{
		DISPLAY_PORT = 0b10000000 | digits[1];
		selector = 0;
		return;
	}
}

void display_setup()
{
	cli();
	// Configuracion ISR cada 1ms
	//		Timer 4, modo ctc, preescaler 1/256, max count 3125
	
	TCCR4A = 0x00;
	TCCR4B = 0x0C;
	TIMSK4 = 0x04;
	
	
	DISPLAY_PORT = 0x00;
	DISPLAY_DDR = 0xFF;
	OCR4A = 312;
	
	sei();
}

void display_setOn()
{
	modo = S_DISPLAY_MODO_NORMAL;
}

void display_setOFF()
{
	modo = S_APAGADO;
}

void display_p()
{
	modo = S_DISPLAY_MODO_PARPADEANDO;
}

ISR(TIMER4_COMPB_vect)
{
	switch(modo)
	{
		case S_APAGADO:
			DISPLAY_PORT = 0x00;
			break;
			
		case  S_DISPLAY_MODO_NORMAL:
			display_update();
			break;
			
		case S_DISPLAY_MODO_PARPADEANDO:
			
			contador++;
			
			if((contador >= 90))
			{
				DISPLAY_PORT = 0x00;
				
			}
			else
			{
				display_update();
			}
			
			if(contador == 100)
			{
				contador = 0;
			
			}
			
			break;
	}
	
	
	//display_update();

}







