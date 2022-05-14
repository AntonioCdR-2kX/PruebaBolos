/*
 * Config.h
 *
 * Created: 10/05/2022 12:17:20
 *  Author: adria
 */ 

#ifndef CONFIG_H_
#define CONFIG_H_

typedef enum estados_4532
{
	S_INIT,
	S_TEST,
	S_PREPARANDO_BOLA,
	/*
	
	Vamos poniendo aqui los posibles estados
	
	
	*/
	S_BOLA_DISPARADA,
	S_BOLA_FINAL_PISTA

	} estados;

#endif /* CONFIG_H_ */