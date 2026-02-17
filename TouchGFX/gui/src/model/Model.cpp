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
	for (int i = 0; i < RENDER_TASK_BOARD_ROW; ++i) {
		for (int j = 0; j < RENDER_TASK_BOARD_COL; ++j) {
			board[i][j] = msg.board[i][j];
		}
	}

    if (modelListener != nullptr) {
        modelListener->notifyBoardChanged();
    }
}
