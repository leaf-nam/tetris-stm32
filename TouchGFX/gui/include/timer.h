#ifndef __TIMER_H__
#define __TIMER_H__

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

extern TimerHandle_t x500msTimer;
extern TimerHandle_t xInputTimer;
extern TickType_t x500ms;
extern TickType_t xInput;

void Timer_500ms_callback( TimerHandle_t );
void Timer_input_callback( TimerHandle_t );
int Timer_get_input(int x, int y);

#endif //__TIMER_H__
