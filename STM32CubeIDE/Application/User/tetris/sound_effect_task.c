#include "sound_effect_task.h"
#include "sound_task.h"
#include "main.h"

QueueHandle_t sound_effect_task_queue;

extern TIM_HandleTypeDef htim3;

enum notes {
    BREAK = 0,
	HARD_DROP = 150,
    A5  = 880,
    C6  = 1046,
    E6  = 1318,
    A6  = 1760
};

#define EFFECT_SPEED 15

enum notes DOWN_note[] = { HARD_DROP };
int DOWN_beat[] = { 3 };
int DOWN_count = sizeof(DOWN_note) / sizeof(enum notes);


enum notes BREAK_note[] = { A6, E6 };
int BREAK_beat[] = { 2, 2 };
int BREAK_count = sizeof(BREAK_note) / sizeof(enum notes);


enum notes GAME_OVER_note[] = { BREAK, E6, C6, A5 };
int GAME_OVER_beat[] = { 5, 30, 30, 30 };
int GAME_OVER_count = sizeof(GAME_OVER_note) / sizeof(enum notes);


extern uint32_t timer_clk;

void Sound_Effect_Task(void *argument)
{
	int sound_loop = 0;
	SoundEffectTaskMessage message;

	enum notes* note = BREAK_note;
	int* beat = BREAK_beat;
	int count = BREAK_count;

	for(;;) {

		if (xQueueReceive(sound_effect_task_queue, &message, pdMS_TO_TICKS(10)) == pdPASS) {
			switch(message.messageID) {
			case SOUND_EFFECT_TASK_DOWN:
				sound_loop = 1;
				note = DOWN_note;
				beat = DOWN_beat;
				count = DOWN_count;
				break;
			case SOUND_EFFECT_TASK_BREAK:
				sound_loop = 1;
				note = BREAK_note;
				beat = BREAK_beat;
				count = BREAK_count;
				break;
			case SOUND_EFFECT_TASK_GAME_OVER:
				sound_loop = 1;
				note = GAME_OVER_note;
				beat = GAME_OVER_beat;
				count = GAME_OVER_count;
				break;
			}
		}

		if (!sound_loop) continue;

		for (int i = 0; i < count; ++i) {

			if (note[i] == BREAK) {
				HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
			}

			else {
				uint32_t arr = timer_clk / note[i];

				__HAL_TIM_SET_AUTORELOAD(&htim3, arr - 1);
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, arr / 2);

				HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
			}

			vTaskDelay(pdMS_TO_TICKS(beat[i] * EFFECT_SPEED));

			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
		}

		sound_loop = 0;
	}
}
