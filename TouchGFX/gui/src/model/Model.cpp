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
        default: break;
        }
    }
}

void Model::updateBoard(RenderTaskMessage& msg) {
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
