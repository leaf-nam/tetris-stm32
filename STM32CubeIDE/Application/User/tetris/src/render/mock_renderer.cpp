#include "render/mock_renderer.hpp"

#include "render/theme.hpp"

#include <iostream>

using namespace std;

void MockRenderer::render_background(){}

void MockRenderer::render_board(const Board& board, const Tetromino& tetromino)
{
	printf("render board called\n");
	for (int i = 2; i < 22; ++i) {
		for (int j = 0; j < 10; ++j) {
			printf("[%d] ", board.at(i,j));
		}
		printf("\n");
	}
	printf("type : %d\n", tetromino.get_mino_type());

}

void MockRenderer::render_timer(int sec)
{
	printf("render timer called : %d\n", sec);
}

void MockRenderer::render_next_block(const int* tetrominoArray)
{
}

void MockRenderer::render_hold(const Tetromino& tetromino){}

void MockRenderer::render_score(int score){}

void MockRenderer::render_game_over(){}

void MockRenderer::render_win(){}

void MockRenderer::render_level(int level){}

void MockRenderer::render_clear(){}
