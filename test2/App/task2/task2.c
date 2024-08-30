#include "FreeRTOS.h"
#include "task.h"
#include "stm32f0xx_hal.h"

#include "m_functinos.h"


/**
  * @brief  Function implementing the vTask1 thread.
  * @param  argument: Not used
  * @retval None
  */
void vTask2( void * pvParameters )
{

	UART_HandleTypeDef *huart =(UART_HandleTypeDef*)pvParameters;
//	TickType_t xLastWakeTime;

	//const TickType_t xFrequency = 2000; //ms if configTICK_RATE_HZ=1000

    //xLastWakeTime = xTaskGetTickCount();

	for(;;)
	{
		vPrintString(huart, (unsigned char *)"I'm task 2\n\r");
		vTaskDelay(2000/ portTICK_PERIOD_MS); // Wait 2000 ms
		//vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}

}
