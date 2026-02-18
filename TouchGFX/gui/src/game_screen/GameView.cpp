#include <gui/game_screen/GameView.hpp>
#include <touchgfx/Color.hpp>

GameView::GameView()
{

}

void GameView::setupScreen()
{
    GameViewBase::setupScreen();

    Model* model = presenter->getModel();

    boardWidget.setXY(10, 10);
    boardWidget.setWidth(RENDER_TASK_BOARD_ROW * BOARD_BLOCK_SIZE);
    boardWidget.setHeight(RENDER_TASK_BOARD_COL * BOARD_BLOCK_SIZE);
    boardWidget.setBoard(&model->board);
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

	add(holdWidget);
	add(nextWidget);
	add(boardWidget);
}

void GameView::tearDownScreen()
{
    GameViewBase::tearDownScreen();
    remove(holdWidget);
    remove(nextWidget);
    remove(boardWidget);
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
