#ifndef __SOUND_TASK_H__
#define __SOUND_TASK_H__

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

extern QueueHandle_t sound_task_queue;

typedef struct SoundTaskMessage_ {
	char messageID;
} SoundTaskMessage;

#define SOUND_TASK_QUEUE_LENGTH 3
#define SOUND_TASK_QUEUE_SIZE sizeof(SoundTaskMessage)

#define SOUND_TASK_BGM_INIT 1
#define SOUND_TASK_BGM_STOP 2
#define SOUND_TASK_BREAK_LINE 3
#define SOUND_TASK_GAME_OVER 4


void Sound_Task(void *argument);

#endif //__SOUND_TASK_H__
