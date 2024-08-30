#include "FreeRTOS.h"
#include "task.h"

#include "stm32f0xx_hal.h"
#include "m_functinos.h"


/**
  * @brief  Function implementing the vTask1 thread.
  * @param  argument: Not used
  * @retval None
  */
void vTask1( void * pvParameters )
{

	UART_HandleTypeDef *huart =(UART_HandleTypeDef*)pvParameters;

	for(;;)
	{
		vPrintString(huart, (unsigned char *)"I'm task 1\n\r");
		vTaskDelay(1000/ portTICK_PERIOD_MS); // Wait 1000 ms
	}

}
