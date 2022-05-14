/*
 * PruebasMicros.cpp
 *
 * Created: 10/05/2022 9:25:20
 * Author : adria
 */ 

#include <avr/io.h>
#include <avr/common.h>
#include "Bolos.h"
#include "Display.h"
#include "Config.h"
#include <avr/interrupt.h>


// ########################## Variables globales #################################

//Variable global que marca en que estado esta la maqueta
estados Estado_global = S_INIT;

// Variable global para almacenar la puntuacion
int puntuacion = 0;

// ########################## Definicion de funciones ############################

// Se llama cada vez que se tira un bolo y suma puntuacion a una variable global
void sumarPuntuacion()
{	
	(puntuacion) += 5;
	display_setNumber(puntuacion);
}

// ################################ Programa principal ##########################
int main(void)
{
	// Bandera que indica si un bolo esta disponible para tirar
	// o ya ha sido tirado 
	uint8_t banderas[6];
	
	// Ponemos a 0 las banderas
	setFlagsToZero(banderas);
	
	// Configuracion de los pines para los bolos
	configBolos();
	
	// Configuracion del display
	display_setup();
	display_setNumber(puntuacion);
	display_p();
	
	
    while (1) 
    {
		//display_update();
		detectarBolos(sumarPuntuacion, banderas);	
		
		
    }
}

