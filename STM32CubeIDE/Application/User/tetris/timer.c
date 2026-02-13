#include "timer.h"
#include "engine_task.h"

TimerHandle_t xTimer;

void Timer_500ms_callback( TimerHandle_t xTimer ) {

	uint32_t ulCount;

	ulCount = ( uint32_t ) pvTimerGetTimerID( xTimer );
	ulCount++;

	EngineTaskMessage message;
	message.messageID = ENGINE_TASK_TICK;
	xQueueSendToFront( engine_task_queue, &message, pdMS_TO_TICKS(100) );

	vTimerSetTimerID( xTimer, ( void * ) ulCount );
}
