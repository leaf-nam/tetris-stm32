extern "C" {
#include <stdio.h>
#include "main.h"
#include "cmsis_os2.h"
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
	Timer& timer = Timer::get_instance();
	KeyMapper key_mapper;

	Engine engine(&input, &render, board, &rule, &queue, &timer, key_mapper);

	for(;;) {
		engine.handle_loop();
		osDelay(100);
	}

}
