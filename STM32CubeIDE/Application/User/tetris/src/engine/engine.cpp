#include "engine/engine.hpp"

#include "board/board.hpp"
#include "game_rule/key_mapper.hpp"
#include "game_rule/rule_zen.hpp"
#include "tetromino/tetromino_queue.hpp"
#include "util/action.hpp"

extern "C" {
#include "cmsis_os2.h"
}

#define ENGINE_TICK_TO_SEC(t) ((t)/2)

using namespace std;

Engine::Engine(IInputHandler* input_handler, IRenderer* renderer, Board& board, GameRule* rule, TetrominoQueue& tetromino_queue, KeyMapper& key_mapper)
    : input_handler(input_handler), renderer(renderer), board(board), rule(rule), tetromino_queue(tetromino_queue), key_mapper(key_mapper)
{
    renderer->render_background();
    renderer->render_board(board, board.get_active_mino());
    renderer->render_hold(board.get_saved_mino());
    renderer->render_score(score);
    renderer->render_level(rule->get_level());
    renderer->render_timer(ENGINE_TICK_TO_SEC(tick));
}

/**
 * @brief 타이머 틱 실행
 */
// TODO 타이머 인터럽트(handle_tick)로 분리
void Engine::handle_tick(){
	tick++;
	rule->process(Action::DROP);
	renderer->render_board(board, board.get_active_mino());
	renderer->render_hold(board.get_saved_mino());
	renderer->render_score(score);
	renderer->render_level(rule->get_level());
	renderer->render_timer(ENGINE_TICK_TO_SEC(tick));
	is_level_up = rule->time_and_level_update();
}

/**
 * @brief 입력 인터럽트 실행
 */
void Engine::handle_input(int){}

void Engine::handle_loop()
{

	if (!board.has_active_mino()) {
		if (!board.spawn_mino(tetromino_queue.get_new_tetromino())) return;
		renderer->render_next_block(tetromino_queue.get_tetrominos());
	}

	// TODO 키 인터럽트(handle_input)로 분리
	{
		key = input_handler->scan();
		action = key_mapper.map_key(key);
		if (action != -1) {
			rule->process(action);
			renderer->render_next_block(tetromino_queue.get_tetrominos());
			renderer->render_board(board, board.get_active_mino());
			renderer->render_hold(board.get_saved_mino());
		}
	}

	new_score = rule->update_score();
	if (is_level_up && !board.insert_line(3)) {
		renderer->render_board(board, board.get_active_mino());
		renderer->render_hold(board.get_saved_mino());
		return;
	}


	if (new_score != 0 || is_level_up) {
		score += new_score;
		renderer->render_board(board, board.get_active_mino());
		renderer->render_hold(board.get_saved_mino());
		renderer->render_score(score);
		renderer->render_level(rule->get_level());
		renderer->render_timer(ENGINE_TICK_TO_SEC(tick));
		is_level_up = false;
	}

}

void Engine::stop() {}

int Engine::finish() { return 0; }

Engine::~Engine() {}
