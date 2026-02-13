extern "C" {
#include <stdio.h>
#include "main.h"
#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "engine_task.h"
}

#include "input/mock_input.hpp"
#include "render/mock_renderer.hpp"
#include "engine/engine.hpp"

extern "C" void engine_wrapper_init();

void engine_wrapper_init(void)
{
	MockInput input;
	MockRenderer render;
	Board board;
	ZEN rule = ZEN(board);
	TetrominoQueue& queue = TetrominoQueue::get_instance();
	KeyMapper key_mapper;

	Engine engine(&input, &render, board, &rule, queue, key_mapper);

	EngineTaskMessage message;

	for(;;) {
		if (xQueueReceive(engine_task_queue, &message, pdMS_TO_TICKS(20)) == pdPASS) {
			engine.handle_tick();
		}

		engine.handle_loop();
	}

}
