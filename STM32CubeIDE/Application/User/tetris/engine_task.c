#include "engine_task.h"

QueueHandle_t engine_task_queue;

void Engine_Task(void *argument)
{
	// c++에서 실행
	engine_wrapper_init();
}
