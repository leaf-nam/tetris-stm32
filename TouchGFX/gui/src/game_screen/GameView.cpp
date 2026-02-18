#include <gui/game_screen/GameView.hpp>
#include <touchgfx/Color.hpp>

GameView::GameView()
{

}

void GameView::setupScreen()
{
    GameViewBase::setupScreen();

    touchgfx::LCD& lcd = touchgfx::HAL::lcd();
    lcd.fillRect(
        touchgfx::Rect(0, 0, HAL::DISPLAY_WIDTH, HAL::DISPLAY_HEIGHT),
        touchgfx::Color::getColorFromRGB(0, 0, 0)
    );

    Model* model = presenter->getModel();

    boardWidget.setXY(10, 10);
    boardWidget.setWidth(RENDER_TASK_BOARD_ROW * BOARD_BLOCK_SIZE);
    boardWidget.setHeight(RENDER_TASK_BOARD_COL * BOARD_BLOCK_SIZE);
    boardWidget.setBoard(&model->board);
    boardWidget.setVisible(true);

    holdWidget.setXY(170, 60);
    holdWidget.setWidth(60);
    holdWidget.setHeight(60);
    holdWidget.setHold(&model->hold);
    holdWidget.setVisible(true);

    nextWidget.setXY(170, 130);
    nextWidget.setWidth(60);
    nextWidget.setHeight(180);
    nextWidget.setNext(model->next);
    nextWidget.setVisible(true);

	add(boardWidget);
	add(holdWidget);
	add(nextWidget);

    boardWidget.invalidate();
    holdWidget.invalidate();
    nextWidget.invalidate();
}

void GameView::tearDownScreen()
{
    GameViewBase::tearDownScreen();
    remove(boardWidget);
    remove(holdWidget);
    remove(nextWidget);
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
