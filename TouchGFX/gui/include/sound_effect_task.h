#ifndef __SOUND_EFFECT_TASK_H__
#define __SOUND_EFFECT_TASK_H__

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

extern QueueHandle_t sound_effect_task_queue;

typedef struct SoundEffectTaskMessage_ {
	char messageID;
} SoundEffectTaskMessage;

#define SOUND_EFFECT_TASK_QUEUE_LENGTH 3
#define SOUND_EFFECT_TASK_QUEUE_SIZE sizeof(SoundEffectTaskMessage)

#define SOUND_EFFECT_TASK_DOWN 1
#define SOUND_EFFECT_TASK_BREAK 2
#define SOUND_EFFECT_TASK_GAME_OVER 3

void Sound_Effect_Task(void *argument);

#endif //__SOUND_EFFECT_TASK_H__
