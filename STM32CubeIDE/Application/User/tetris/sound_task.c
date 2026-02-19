#include "sound_task.h"
#include "main.h"

QueueHandle_t sound_task_queue;

enum notes {
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

void Sound_Task(void *argument)
{
	enum notes BGM1_note[] = {
			  E5, B4, C5, D5, C5, B4, A4, A4, C5, E5, D5, C5, B4, B4, C5, D5, E5, C5, A4, A4,
			  D5, F5, A5, G5, F5, E5, C5, E5, D5, C5, B4, B4, C5, D5, E5, C5, A4, A4};

	int BGM1_beat[] = {
			  10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 10, 10, 10, 20,
			  10, 5, 10, 5, 5, 15, 5, 10, 5, 5, 10, 5, 5, 10, 10, 10, 10, 10
	};

	uint32_t timer_clk = 1000000;

	for(;;) {
	for (int i = 0 ; i < sizeof(BGM1_note)/sizeof(enum notes) ; i++) {

		uint32_t arr = timer_clk / BGM1_note[i];

		__HAL_TIM_SET_AUTORELOAD(&htim2, arr - 1);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, arr / 2);

		vTaskDelay(pdMS_TO_TICKS(BGM1_beat[i] * 35));

		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
		vTaskDelay(pdMS_TO_TICKS(10));
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	  }

	  HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	  vTaskDelay(pdMS_TO_TICKS(2000));
	  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	}
}
