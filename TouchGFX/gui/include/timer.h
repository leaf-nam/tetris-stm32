#ifndef __TIMER_H__
#define __TIMER_H__

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

extern TimerHandle_t xTimer;

void Timer_500ms_callback(TimerHandler_t);

#endif //__TIMER_H__
