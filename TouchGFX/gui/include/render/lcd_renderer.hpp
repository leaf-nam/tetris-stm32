#ifndef APPLICATION_USER_TETRIS_SRC_RENDER_LCD_RENDERER_HPP_
#define APPLICATION_USER_TETRIS_SRC_RENDER_LCD_RENDERER_HPP_

extern "C" {
#include <render_task.h>
}

#include "board/board.hpp"
#include "tetromino/tetromino.hpp"
#include "i_renderer.hpp"

class LcdRenderer : public IRenderer {
public:
	LcdRenderer();

	void render_background();

	void render_board(const Board& board, const Tetromino& tetromino);

	void render_timer(int sec);

	void render_next_block(const int* tetrominoArray);

	void render_hold(const Tetromino& tetromino);

	void render_score(int score);

	void render_game_over();

	void render_win();

	void render_level(int level);

	void render_clear();

	virtual ~LcdRenderer();

};

#endif /* APPLICATION_USER_TETRIS_SRC_RENDER_LCD_RENDERER_HPP_ */
