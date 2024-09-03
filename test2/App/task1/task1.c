#include "FreeRTOS.h"
#include "task.h"

#include "stm32f0xx_hal.h"
#include "m_functinos.h"


#include "App/task2/task2.h"

uint16_t dataCount = 0;
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
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
		vTaskDelay(1000/ portTICK_PERIOD_MS); // Wait 1000 ms
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	    vTaskDelay(1000/ portTICK_PERIOD_MS); // Wait 1000 ms


	    Task2Message newData;
	    newData.ucMessageID = dataCount;

	    task2States task2State = getVTask2State();
	    QueueHandle_t task2Queue = getVTask2Queue();

	    if((task2State == STATE_RUNNING)&&(task2Queue != NULL))
	    {
	    	 BaseType_t returnSend = xQueueSend( task2Queue,(void *) &newData,(TickType_t)0 );

	    	 if(returnSend !=pdTRUE )
	    	 {
	    		 vPrintString(huart, (unsigned char *)"Error sending data to task2\n\r");
	    	 }
	    }


	    dataCount++;
	}

}
