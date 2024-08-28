/*
 * m_functinos.h
 *
 *  Created on: Mar 17, 2017
 *      Author: ark4579
 */

#ifndef M_FUNCTINOS_H_
#define M_FUNCTINOS_H_

/* Include's*/
//#include "stm32f1xx_hal.h"	//<--dont forget to change if u are using a board other than stm32f1
#include "main.h"
//#include "usart.h"

/* Prototypes */
extern void vPrintString(UART_HandleTypeDef *huart, unsigned char * message);
void vPrintStringandNumber(UART_HandleTypeDef *huart, unsigned char * message, int number);

#endif /* M_FUNCTINOS_H_ */
