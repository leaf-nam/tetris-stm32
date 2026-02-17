#include <render/lcd_renderer.hpp>

extern QueueHandle_t render_task_queue;

using namespace std;

LcdRenderer::LcdRenderer() {
}

LcdRenderer::~LcdRenderer() {

}

void LcdRenderer::render_background(){}

void LcdRenderer::render_board(const Board& board, const Tetromino& tetromino)
{
	printf("render board called\n");

	RenderTaskMessage msg;

	msg.messageID = RENDER_TASK_BOARD;

	for (int i = 2; i < 22; ++i) {
		for (int j = 0; j < 10; ++j) {
			msg.board[i - 2][j] = board.at(i, j);
		}
	}

	xQueueSendToFront(render_task_queue, &msg, pdMS_TO_TICKS(20));
}

void LcdRenderer::render_timer(int sec)
{
	printf("render timer called : %d\n", sec);
}

void LcdRenderer::render_next_block(const int* tetrominoArray)
{
}

void LcdRenderer::render_hold(const Tetromino& tetromino){}

void LcdRenderer::render_score(int score){}

void LcdRenderer::render_game_over(){}

void LcdRenderer::render_win(){}

void LcdRenderer::render_level(int level){}

void LcdRenderer::render_clear(){}
