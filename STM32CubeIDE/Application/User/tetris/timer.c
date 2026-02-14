#include "timer.h"
#include "engine_task.h"
#include "main.h"
#include "cmsis_os.h"

extern ADC_HandleTypeDef hadc1;

TimerHandle_t x500msTimer;
TimerHandle_t xInputTimer;

TickType_t x500ms = pdMS_TO_TICKS(100);
TickType_t xInput = pdMS_TO_TICKS(50);

void Timer_500ms_callback( TimerHandle_t xTimer ) {

	uint32_t ulCount;

	ulCount = ( uint32_t ) pvTimerGetTimerID( xTimer );
	ulCount++;

	EngineTaskMessage message;
	message.messageID = ENGINE_TASK_TICK;
	xQueueSendToFront( engine_task_queue, &message, x500ms );

	vTimerSetTimerID( xTimer, ( void * ) ulCount );
}

void Timer_input_callback( TimerHandle_t xTimer ) {

	uint32_t ulCount;

	ulCount = ( uint32_t ) pvTimerGetTimerID( xTimer );
	ulCount++;

	EngineTaskMessage message;

	{ // 조이스틱 입력 처리
		uint32_t adcX, adcY;

		HAL_ADC_Start(&hadc1);

		HAL_ADC_PollForConversion(&hadc1, 100);
		adcX = HAL_ADC_GetValue(&hadc1);

		HAL_ADC_PollForConversion(&hadc1, 100);
		adcY = HAL_ADC_GetValue(&hadc1);


		message.messageID = ENGINE_TASK_INPUT;
		message.input = Timer_get_input(adcX, adcY);
	}

	{ // 버튼 입력 처리   * 조이스틱 입력 무시
		if (HAL_GPIO_ReadPin(HOLD_GPIO_Port, HOLD_Pin) == GPIO_PIN_RESET)
			message.input = 'w';

		if (HAL_GPIO_ReadPin(HARD_DROP_GPIO_Port, HARD_DROP_Pin) == GPIO_PIN_RESET)
			message.input = ' ';

		if (HAL_GPIO_ReadPin(JOY_P_GPIO_Port, JOY_P_Pin) == GPIO_PIN_RESET)
			message.input = ' ';
	}


	xQueueSendToFront( engine_task_queue, &message, xInput );

	vTimerSetTimerID( xTimer, ( void * ) ulCount );
}

#define ARROW_LEFT 1002
#define ARROW_RIGHT 1003
#define ARROW_DOWN 1001
#define ARROW_UP 1000
int Timer_get_input(int x, int y) {
	int dx = x > 3000? 1 : x < 1000? -1 : 0;
	int dy = y > 3000? 1 : y < 1000? -1 : 0;

	if (dx == 1 && dy == 0) return ARROW_LEFT;
	if (dx == -1 && dy == 0) return ARROW_RIGHT;
	if (dx == 0 && dy == 1) return ARROW_UP;
	if (dx == 0 && dy == -1) return ARROW_DOWN;
	return -1;
}
