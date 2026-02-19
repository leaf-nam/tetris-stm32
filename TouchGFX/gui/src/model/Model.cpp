#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	RenderTaskMessage msg;

    while (xQueueReceive(render_task_queue, &msg, 0) == pdTRUE)
    {
        switch(msg.messageID) {
        case RENDER_TASK_BOARD: updateBoard(msg); break;
        case RENDER_TASK_HOLD: updateHold(msg); break;
        case RENDER_TASK_NEXT_BLOCK: updateNext(msg); break;
        case RENDER_TASK_TIMER: updateTimer(msg); break;
        case RENDER_TASK_GAME_OVER: updateGameOver(); break;
        default: break;
        }
    }
}

void Model::updateBoard(RenderTaskMessage& msg) {
	if (gameOver) {
		gameOver = false;
		return;
	}

	auto pos = msg.mino.pos;
	for (int r = 0; r < RENDER_TASK_BOARD_ROW; ++r) {
		for (int c = 0; c < RENDER_TASK_BOARD_COL; ++c) {
			bool inside = (r >= pos[0] && r < pos[0] + 4) && (c >= pos[1] && c < pos[1] + 4);

			if (inside && msg.mino.shape[r - pos[0]][c - pos[1]] != 0)
				board[r][c] = msg.mino.type;

			else if (msg.board[r][c] < 8 && msg.board[r][c] > -1)
				board[r][c] = msg.board[r][c];

			else
				board[r][c] = 8;
		}
	}

    if (modelListener != nullptr) {
        modelListener->notifyBoardChanged();
    }
}

void Model::updateHold(RenderTaskMessage& msg) {
	if (gameOver) return;

	hold = msg.holdType;

	if (modelListener != nullptr) {
		modelListener->notifyHoldChanged();
	}
}

void Model::updateNext(RenderTaskMessage& msg) {
	if (gameOver) return;

    for (int i = 0; i < RENDER_TASK_NEXT_BLOCK_SIZE; ++i) {
        next[i] = msg.nextType[i];
    }

	if (modelListener != nullptr) {
		modelListener->notifyNextChanged();
	}
}

void Model::updateTimer(RenderTaskMessage& msg) {
	if (gameOver) return;

	if (modelListener != nullptr) {
		modelListener->notifyTimerChanged(msg.sec);
	}
}

void Model::updateGameOver() {
	for (int r = 0; r < RENDER_TASK_BOARD_ROW; ++r) {
		for (int c = 0; c < RENDER_TASK_BOARD_COL; ++c) {
			if (board[r][c] < 7 && board[r][c] > -1)
				board[r][c] = 7;

			else
				board[r][c] = 8;
		}
	}

	gameOver = true;

	if (modelListener != nullptr) {
		modelListener->notifyGameOverChanged();
	}
}
