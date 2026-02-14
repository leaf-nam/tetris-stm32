extern "C" {
#include <stdio.h>
#include "main.h"
#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "engine_task.h"
}

#include "render/mock_renderer.hpp"
#include "engine/engine.hpp"

extern "C" void engine_wrapper_init();

void engine_wrapper_init(void)
{
	MockRenderer render;
	Board board;
	ZEN rule = ZEN(board);
	TetrominoQueue& queue = TetrominoQueue::get_instance();
	KeyMapper key_mapper;

	Engine engine(&render, board, &rule, queue, key_mapper);

	EngineTaskMessage message;

	for(;;) {
		if (xQueueReceive(engine_task_queue, &message, pdMS_TO_TICKS(20)) == pdPASS) {

			switch(message.messageID) {
			case ENGINE_TASK_TICK: engine.handle_tick(); break;
			case ENGINE_TASK_INPUT: engine.handle_input(message.input); break;
			default: break;
			}

		}

		engine.handle_loop();
	}

}
