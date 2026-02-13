#ifndef __MOCK_RENDERER_HPP__
#define __MOCK_RENDERER_HPP__

#include "board/board.hpp"
#include "tetromino/tetromino.hpp"
#include "i_renderer.hpp"

class MockRenderer: public IRenderer
{
public:
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

};

#endif //!__MOCK_RENDERER_HPP__
