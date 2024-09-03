#include "FreeRTOS.h"
#include "task.h"
#include "stm32f0xx_hal.h"

#include "m_functinos.h"


/**
  * @brief  Function implementing the vTask1 thread.
  * @param  argument: Not used
  * @retval None
  */
void vTask3( void * pvParameters )
{

	UART_HandleTypeDef *huart =(UART_HandleTypeDef*)pvParameters;
//	TickType_t xLastWakeTime;

	//const TickType_t xFrequency = 2000; //ms if configTICK_RATE_HZ=1000

    //xLastWakeTime = xTaskGetTickCount();

	for(;;)
	{
		vPrintString(huart, (unsigned char *)"I'm task 3\n\r");
		vTaskDelay(1500/ portTICK_PERIOD_MS); // Wait 1500 ms
		//vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}

}
