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

	for (int i = BOARD_UPPER; i < BOARD_ROW + BOARD_UPPER; ++i) {
		for (int j = 0; j < BOARD_COL; ++j) {
			msg.board[i - BOARD_UPPER][j] = board.at(i, j);
		}
	}

	msg.mino.type = tetromino.get_mino_type();
	msg.mino.pos[0] = tetromino.get_pos().first - 2;
	msg.mino.pos[1] = tetromino.get_pos().second;
	auto mino = tetromino.get_shape();
	for (int i = 0; i < MINO_SIZE; ++i) {
		for (int j = 0; j < MINO_SIZE; ++j) {
			msg.mino.shape[i][j] = mino[i][j];
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
	printf("render next called\n");

	RenderTaskMessage msg;

	msg.messageID = RENDER_TASK_NEXT_BLOCK;
	for (int i = 0; i < 3; ++i) {
		msg.nextType[i] = tetrominoArray[i];
	}

	xQueueSendToFront(render_task_queue, &msg, pdMS_TO_TICKS(20));
}

void LcdRenderer::render_hold(const Tetromino& tetromino){
	printf("render hold called\n");

	RenderTaskMessage msg;

	msg.messageID = RENDER_TASK_HOLD;
	msg.holdType = tetromino.get_mino_type();

	xQueueSendToFront(render_task_queue, &msg, pdMS_TO_TICKS(20));
}

void LcdRenderer::render_score(int score){}

void LcdRenderer::render_game_over(){}

void LcdRenderer::render_win(){}

void LcdRenderer::render_level(int level){}

void LcdRenderer::render_clear(){}
