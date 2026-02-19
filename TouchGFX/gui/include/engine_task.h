#ifndef __ENGINE_TASK_H__
#define __ENGINE_TASK_H__

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

extern QueueHandle_t engine_task_queue;

typedef struct EngineTaskMessage_ {
	char messageID;
	int input;
} EngineTaskMessage;

#define ENGINE_TASK_QUEUE_LENGTH 10
#define ENGINE_TASK_QUEUE_SIZE sizeof(EngineTaskMessage)

#define ENGINE_TASK_INIT 1
#define ENGINE_TASK_STOP 2
#define ENGINE_TASK_FINISH 3
#define ENGINE_TASK_TICK 4
#define ENGINE_TASK_INPUT 5

void Engine_Task(void *argument);

#endif //__ENGINE_TASK_H__
