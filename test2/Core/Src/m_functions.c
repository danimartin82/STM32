#include "m_functinos.h"

#include <string.h>

void vPrintString(UART_HandleTypeDef *huart, unsigned char * message)
{
//	vTaskSuspendAll();
	HAL_UART_Transmit(huart, message, strlen((char*)message), 10);
//	xTaskResumeAll();
}

void vPrintStringandNumber(UART_HandleTypeDef *huart, unsigned char * message, int number)
{
static unsigned char *cBuffer[ 256 ];

	vTaskSuspendAll();
	sprintf(cBuffer,"%s%d\r\n", message, number);
	HAL_UART_Transmit(huart, cBuffer, 256, 10);
	xTaskResumeAll();
}
