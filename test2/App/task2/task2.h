#include "semphr.h"
#include "queue.h"

typedef struct
{
    char ucMessageID;

} Task2Message;


typedef enum task2States
{
	STATE_INIT = 0,
	STATE_RUNNING,
}task2States;


typedef struct Task2Control
{
	task2States state;
	QueueHandle_t xStructQueue;
	UART_HandleTypeDef *huart;
	SemaphoreHandle_t xSemaphore;
}Task2Control;


void vTask2( void * pvParameters );
task2States getVTask2State(void);
QueueHandle_t getVTask2Queue(void);
SemaphoreHandle_t getVTask2Semaphore(void);
