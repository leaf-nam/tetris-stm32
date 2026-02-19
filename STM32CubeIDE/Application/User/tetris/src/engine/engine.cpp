#include "engine/engine.hpp"

#include "board/board.hpp"
#include "game_rule/key_mapper.hpp"
#include "game_rule/rule_zen.hpp"
#include "tetromino/tetromino_queue.hpp"
#include "util/action.hpp"

#include "sound_effect_task.h"
#include "cmsis_os2.h"


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
	if (game_over) return;

	tick++;
	rule->process(Action::DROP);
	renderer->render_board(board, board.get_active_mino());
	renderer->render_timer(ENGINE_TICK_TO_SEC(tick));
	renderer->render_next_block(tetromino_queue.get_tetrominos());
	is_level_up = rule->time_and_level_update();
}

/**
 * @brief 입력 인터럽트 실행
 */
void Engine::handle_input(int key){
	if (game_over) return;

	Action action = key_mapper.map_key(key);
	if (action != Action::INVALID) {
		rule->process(action);
		renderer->render_board(board, board.get_active_mino());
		renderer->render_next_block(tetromino_queue.get_tetrominos());
		renderer->render_hold(board.get_saved_mino());
	}

	if (action == Action::HARD_DROP) down_sound();
}

void Engine::handle_loop()
{
	if (game_over) return;

	// 블록 생성 + 게임종료 검사
	if (!board.has_active_mino()) {
		if (!board.spawn_mino(tetromino_queue.get_new_tetromino())) {
			game_over = true;
			renderer->render_game_over();
			return;
		}
	}

	// 게임 이벤트 처리
	new_score = rule->update_score();

	// 레벨업 이벤트(3줄 증가) 처리 + 게임종료 검사
	if (is_level_up && !board.insert_line(3)) {
		game_over = true;
		renderer->render_game_over();
		return;
	}

	// 한줄 삭제(=점수 추가)
	if (new_score != 0 || is_level_up) {
		break_sound();
		score += new_score;
		update_all();
		is_level_up = false;
	}

}

void Engine::stop() {}

int Engine::finish() {
	board.reset();

	game_over = false;
	is_level_up = false;
	game_over = false;
	score = 0;
	tick = 0;

	return 0;
}

void Engine::update_all() {
	renderer->render_board(board, board.get_active_mino());
	renderer->render_hold(board.get_saved_mino());
	renderer->render_score(score);
	renderer->render_next_block(tetromino_queue.get_tetrominos());
	renderer->render_level(rule->get_level());
	renderer->render_timer(ENGINE_TICK_TO_SEC(tick));
}

void Engine::break_sound() {
	SoundEffectTaskMessage effect_msg;
	effect_msg.messageID = SOUND_EFFECT_TASK_BREAK;
	xQueueSendToFront(sound_effect_task_queue, &effect_msg, pdMS_TO_TICKS(20));
}

void Engine::down_sound() {
	SoundEffectTaskMessage effect_msg;
	effect_msg.messageID = SOUND_EFFECT_TASK_DOWN;
	xQueueSendToFront(sound_effect_task_queue, &effect_msg, pdMS_TO_TICKS(20));
}

Engine::~Engine() {}
