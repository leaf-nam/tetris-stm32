#include "timer.h"
#include "engine_task.h"
#include "main.h"
#include "cmsis_os.h"

extern uint16_t adc_values[2];

TimerHandle_t x500msTimer;
TimerHandle_t xInputTimer;

TickType_t x500msWait = pdMS_TO_TICKS(500);
TickType_t xInputWait = pdMS_TO_TICKS(30);
TickType_t xInputHold = pdMS_TO_TICKS(300);

void Timer_500ms_callback( TimerHandle_t xTimer ) {

	uint32_t ulCount;

	ulCount = ( uint32_t ) pvTimerGetTimerID( xTimer );
	ulCount++;

	EngineTaskMessage message;
	message.messageID = ENGINE_TASK_TICK;
	xQueueSendToFront( engine_task_queue, &message, x500msWait );

	vTimerSetTimerID( xTimer, ( void * ) ulCount );
}

static int holdKey = -1;
static TickType_t pressTime = 0;
void Timer_input_callback( TimerHandle_t xTimer ) {

	uint32_t ulCount;

	ulCount = ( uint32_t ) pvTimerGetTimerID( xTimer );
	ulCount++;

	EngineTaskMessage message;
	message.messageID = ENGINE_TASK_INPUT;

	// 조이스틱 입력 처리
	message.input = Timer_get_input(adc_values[0], adc_values[1]);

	{ // 버튼 입력 처리   * 조이스틱 입력 무시
		if (HAL_GPIO_ReadPin(HOLD_GPIO_Port, HOLD_Pin) == GPIO_PIN_RESET)
			message.input = 'w';

		if (HAL_GPIO_ReadPin(HARD_DROP_GPIO_Port, HARD_DROP_Pin) == GPIO_PIN_RESET)
			message.input = ' ';

		if (HAL_GPIO_ReadPin(JOY_P_GPIO_Port, JOY_P_Pin) == GPIO_PIN_RESET)
			message.input = ' ';
	}

	if (message.input != -1)
	{
		// 입력한 키 변경되었을때 즉시 전송
	    if (holdKey != message.input)
	    {
	        holdKey = message.input;
	        pressTime = xTaskGetTickCount();
	        xQueueSendToFront( engine_task_queue, &message, xInputWait );
	    }

	    // 변경되지 않았을 경우 대기(xInputHold) 후 전송
	    else
	    {
	        TickType_t now = xTaskGetTickCount();

	        if (now - pressTime > xInputHold)
	        	xQueueSendToFront( engine_task_queue, &message, xInputWait );
	    }
	}
	else holdKey = -1;

	vTimerSetTimerID( xTimer, ( void * ) ulCount );
}

#define ARROW_LEFT 1002
#define ARROW_RIGHT 1003
#define ARROW_DOWN 1001
#define ARROW_UP 1000
int Timer_get_input(int x, int y) {
	int dx = x > 3000? 1 : x < 1000? -1 : 0;
	int dy = y > 3000? 1 : y < 1000? -1 : 0;

	if (dx == 1 && dy == 0) return ARROW_DOWN;
	if (dx == -1 && dy == 0) return ARROW_UP;
	if (dx == 0 && dy == 1) return ARROW_LEFT;
	if (dx == 0 && dy == -1) return ARROW_RIGHT;
	return -1;
}
