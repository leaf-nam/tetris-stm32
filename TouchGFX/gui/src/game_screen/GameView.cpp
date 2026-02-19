#include <gui/game_screen/GameView.hpp>
#include <touchgfx/Color.hpp>
#include <gui_generated/game_screen/GameViewBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>
#include <engine_task.h>
#include <sound_task.h>
#include <timer.h>

GameView::GameView()
{

}

void GameView::setupScreen()
{
    GameViewBase::setupScreen();

	EngineTaskMessage message;
	message.messageID = ENGINE_TASK_INIT;
    xQueueSendToFront( engine_task_queue, &message, xInputWait );

    Model* model = presenter->getModel();

    boardWidget.setXY(10, 10);
    boardWidget.setWidth(RENDER_TASK_BOARD_ROW * BOARD_BLOCK_SIZE);
    boardWidget.setHeight(RENDER_TASK_BOARD_COL * BOARD_BLOCK_SIZE);
    boardWidget.setBoard(&model->board);
    boardWidget.setTouchable(false);
    boardWidget.setVisible(true);

    holdWidget.setXY(170, 75);
    holdWidget.setWidth(60);
    holdWidget.setHeight(45);
    holdWidget.setHold(&model->hold);
    holdWidget.setVisible(true);

    nextWidget.setXY(170, 145);
    nextWidget.setWidth(60);
    nextWidget.setHeight(165);
    nextWidget.setNext(model->next);
    nextWidget.setVisible(true);

    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%02d:%02d", 0, 0);

    remove(container1);
	add(holdWidget);
	add(nextWidget);
	add(boardWidget);

	container1.setVisible(false);
	add(container1);
}

void GameView::tearDownScreen()
{
    GameViewBase::tearDownScreen();
    remove(holdWidget);
    remove(nextWidget);
    remove(boardWidget);

	EngineTaskMessage engineMessage;
	engineMessage.messageID = ENGINE_TASK_FINISH;
    xQueueSendToFront( engine_task_queue, &engineMessage, xInputWait );

    SoundTaskMessage soundMessage;
    soundMessage.messageID = SOUND_TASK_BGM_1_START;
	xQueueSendToFront( sound_task_queue, &soundMessage, pdMS_TO_TICKS(20) );
}

void GameView::updateBoard()
{
	boardWidget.invalidate();
}

void GameView::updateHold() {
	holdWidget.invalidate();
}

void GameView::updateNext() {
	nextWidget.invalidate();
}

void GameView::updateTimer(int sec) {
    int m = sec / 60;
    int s = sec % 60;

    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%02d:%02d", m, s);
    textArea2.resizeToCurrentText();
    textArea2.invalidate();
}

void GameView::updateGameOver() {
    container1.setVisible(true);
    container1.invalidate();
	boardWidget.invalidate();
}
