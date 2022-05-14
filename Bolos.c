/*
 * Bolos.c
 *
 * Created: 10/05/2022 9:26:52
 *  Author: adria
 */ 
#include "Bolos.h"
#define NUM_BOLOS 6;

void configBolos()
{
	BOLOS_DDR = 0x00;
}
void detectarBolos(void (*func)(), uint8_t* banderas)
{
	uint8_t i = 0;
	uint8_t shift = 0b00000001;
	if(func != NULL && banderas != NULL)
	{			
				/*
				if((BOLOS_PIN & (shift)) == shift )
				{
					if(banderas[i] == 0)
						{
							func();
							banderas[i] = 1;
						}
					
					shift << 1;
				}
				*/
				
				{
					
				// Bolo 1
				if(((BOLOS_PIN &  0b10000000) == 0x00) && banderas[0] == 0)
				{
					func();
					banderas[0] = 1;
				}
				
				// Bolo 2
				if((BOLOS_PIN &  0b01000000) == 0x00 && banderas[1] == 0)
				{
					func();
					banderas[1] = 1;
				}
				
				// Bolo 3
				if((BOLOS_PIN &  0b00100000) == 0x00 && banderas[2] == 0)
				{
					func();
					banderas[2] = 1;
				}
				
				// Bolo 4
				if((BOLOS_PIN &  0b00010000) == 0x00 && banderas[3] == 0)
				{
					func();
					banderas[3] = 1;
				}
				
				// Bolo 5
				if((BOLOS_PIN &  0b00001000) == 0x00 && banderas[4] == 0)
				{
					func();
					banderas[4] = 1;
				}
				
				// Bolo 6
				if((BOLOS_PIN &  0b00000100) == 0x00 && banderas[5] == 0)
				{
					func();
					banderas[5] = 1;
				}
				
				
			}
				
			
	}
}

void setFlagsToOne(uint8_t* flags)
{
	if(flags != NULL)
	{
		for(uint8_t i = 0; i < 6; i++)
		{
			flags[i] = 1;
		}
	}
}

void setFlagsToZero(uint8_t* flags)
{
	if(flags != NULL)
	{
		for(uint8_t i = 0; i < 6; i++)
		{
			flags[i] = 0;
		}
	}
}