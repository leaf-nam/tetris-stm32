#include "sound_task.h"
#include "main.h"

QueueHandle_t sound_task_queue;

enum notes {
	BREAK = 0,

    AB3 = 208,
    A3  = 220,
    B3  = 247,

    C4  = 262,
    D4  = 294,
    E4  = 330,
    F4  = 349,
    FS4  = 370,
    G4  = 392,
    AB4 = 415,
    A4  = 440,

    B4  = 494,
    C5  = 523,
    D5  = 587,
    E5  = 659,
    F5  = 698,
    G5  = 784,
    A5  = 880
};

extern TIM_HandleTypeDef htim2;

#define BGM_SPEED 35

enum notes BGM1_note[] = {
		BREAK,

		// 1절
		E5, B4, C5, D5, C5, B4, A4, A4, C5, E5, D5, C5, B4, B4, C5, D5, E5, C5, A4, A4,
		D5, F5, A5, G5, F5, E5, C5, E5, D5, C5, B4, B4, C5, D5, E5, C5, A4, A4,

		// 2절
		E4, C4, D4, B3, C4, A3, AB3, B3, E4, C4, D4, B3, C4, E4, A4, A4, AB4
};

int BGM1_beat[] = {
		20,

		10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 10, 10, 10, 20,
		10, 5, 10, 5, 5, 15, 5, 10, 5, 5, 10, 5, 5, 10, 10, 10, 10, 20,

		20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 10, 10, 10, 10, 20
};

int BGM1_count = sizeof(BGM1_note) / sizeof(enum notes);

enum notes BGM2_note[] = {
		BREAK,

		// 1절
		B4, B4, C5, B4, A4, C5, B4, A4, G4, A4, G4, G4, A4, G4, FS4, G4, E4, BREAK,
		B4, B4, C5, B4, A4, C5, B4, A4, G4, A4, G4, G4, A4, G4, FS4, G4, E4, BREAK,
		B4, B4, C5, B4, A4, C5, A4, A4, B4, A4, G4, B4, G4, G4, A4, G4, FS4, G4, FS4, FS4, G4, A4,
		B4, B4, C5, B4, A4, C5, B4, A4, G4, A4, G4, G4, A4, G4, FS4, G4, E4, BREAK,

		// 2절
		B4, B4, C5, D5, E5, D5, C5, B4, A4, A4, B4, A4, G4, G4, A4, B4,
		B4, B4, C5, D5, E5, D5, C5, B4, A4, A4, B4, A4, G4, BREAK,
		B4, B4, C5, D5, E5, D5, C5, B4, A4, A4, B4, A4, G4, G4, A4, B4,
		B4, B4, C5, D5, E5, D5, C5, B4, A4, A4, G4, FS4, E4,
};

int BGM2_beat[] = {
		20,

		5, 5, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2, 5, 10,
		5, 5, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2, 5, 10,
		5, 5, 2, 2, 2, 2, 5, 5, 2, 2, 2, 2, 5, 5, 2, 2, 2, 2, 5, 5, 5, 5,
		5, 5, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2, 5, 10,

		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
};

int BGM2_count = sizeof(BGM2_note) / sizeof(enum notes);

uint32_t timer_clk = 1000000;

void Sound_Task(void *argument)
{
	int sound_loop = 1;
	SoundTaskMessage message;

	enum notes* note = BGM1_note;
	int* beat = BGM1_beat;
	int count = BGM1_count;

	for(;;) {

		for (int i = 0; i < count; ++i) {

			if (xQueueReceive(sound_task_queue, &message, pdMS_TO_TICKS(10)) == pdPASS) {
				switch(message.messageID) {
				case SOUND_TASK_BGM_1_START:
					sound_loop = 1;
					note = BGM1_note;
					beat = BGM1_beat;
					count = BGM1_count;
					break;
				case SOUND_TASK_BGM_2_START:
					sound_loop = 1;
					note = BGM2_note;
					beat = BGM2_beat;
					count = BGM2_count;
					break;
				case SOUND_TASK_BGM_STOP:
					sound_loop = 0;
					break;
				}
			}

			if (!sound_loop) break;

			if (note[i] == BREAK) {
				HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
			}

			else {
				uint32_t arr = timer_clk / note[i];

				__HAL_TIM_SET_AUTORELOAD(&htim2, arr - 1);
				__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, arr / 2);

				HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
			}

			vTaskDelay(pdMS_TO_TICKS(beat[i] * BGM_SPEED));

			HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
		}

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
