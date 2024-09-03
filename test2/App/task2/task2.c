#include "FreeRTOS.h"
#include "task.h"
#include "stm32f0xx_hal.h"

#include "m_functinos.h"

#include "task2.h"


Task2Control Task2Ctrl;
Task2Message RxMessage;
/**
  * @brief  Function implementing the vTask1 thread.
  * @param  argument: Not used
  * @retval None
  */
void vTask2( void * pvParameters )
{

	Task2Ctrl.huart =(UART_HandleTypeDef*)pvParameters;


	for(;;)
	{
		switch (Task2Ctrl.state)
		{
			case STATE_INIT:
			{
				Task2Ctrl.xStructQueue = xQueueCreate(5, sizeof( Task2Message ));
				//vPrintString(huart, (unsigned char *)"task 2: STATE_INIT\n\r");
				if(Task2Ctrl.xStructQueue != NULL)
				{
				  Task2Ctrl.state = STATE_RUNNING;
				}
				break;
			}
			case STATE_RUNNING:
			{

				 if( xQueueReceive( Task2Ctrl.xStructQueue,&RxMessage,(TickType_t)10 ) == pdPASS )
				 {
					 char buffer[15];
					 sprintf(buffer,"Msg rx ID %d\n\r", RxMessage.ucMessageID);
					 vPrintString(Task2Ctrl.huart, (unsigned char *)buffer);
				 }
				//vPrintString(huart, (unsigned char *)"task 2: STATE_RUNNING\n\r");

				break;
			}
		}
		vTaskDelay(2000/ portTICK_PERIOD_MS); // Wait 2000 ms

	}

}


task2States getVTask2State(void)
{
	return Task2Ctrl.state;
}
QueueHandle_t getVTask2Queue(void)
{
	return Task2Ctrl.xStructQueue;
}

