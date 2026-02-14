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

Engine::Engine(IRenderer* renderer, Board& board, GameRule* rule, TetrominoQueue& tetromino_queue, KeyMapper& key_mapper)
    : renderer(renderer), board(board), rule(rule), tetromino_queue(tetromino_queue), key_mapper(key_mapper)
{
	update_all();
}

/**
 * @brief 타이머 틱 실행
 */
void Engine::handle_tick(){
	tick++;
	rule->process(Action::DROP);
	update_all();
	is_level_up = rule->time_and_level_update();
}

/**
 * @brief 입력 인터럽트 실행
 */
// TODO 키 인터럽트(handle_input)로 분리
void Engine::handle_input(int key){
	Action action = key_mapper.map_key(key);
	if (action != Action::INVALID) {
		rule->process(action);
		renderer->render_board(board, board.get_active_mino());
		renderer->render_next_block(tetromino_queue.get_tetrominos());
		renderer->render_hold(board.get_saved_mino());
	}
}

void Engine::handle_loop()
{
	// 블록 생성
	if (!board.has_active_mino()) {
		if (!board.spawn_mino(tetromino_queue.get_new_tetromino())) return;
		renderer->render_next_block(tetromino_queue.get_tetrominos());
	}

	// 게임 이벤트 처리
	new_score = rule->update_score();

	// 레벨업 이벤트(3줄 증가) 처리
	if (is_level_up && !board.insert_line(3)) {
		renderer->render_board(board, board.get_active_mino());
		renderer->render_hold(board.get_saved_mino());
		return;
	}

	// 한줄 삭제(=점수 추가)
	if (new_score != 0 || is_level_up) {
		score += new_score;
		update_all();
		is_level_up = false;
	}

}

void Engine::stop() {}

int Engine::finish() { return 0; }

void Engine::update_all() {
	renderer->render_board(board, board.get_active_mino());
	renderer->render_hold(board.get_saved_mino());
	renderer->render_score(score);
	renderer->render_level(rule->get_level());
	renderer->render_timer(ENGINE_TICK_TO_SEC(tick));
}

Engine::~Engine() {}
