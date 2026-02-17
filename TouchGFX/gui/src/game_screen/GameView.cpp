#include <gui/game_screen/GameView.hpp>
#include <touchgfx/Color.hpp>

BoardWidget boardWidget;

GameView::GameView()
{

}

void GameView::setupScreen()
{
    GameViewBase::setupScreen();

    Model* model = presenter->getModel();
    boardWidget.setXY(10, 10);
    boardWidget.setWidth(BOARD_COL * BOARD_BLOCK_SIZE);
    boardWidget.setHeight(BOARD_ROW * BOARD_BLOCK_SIZE);
    boardWidget.setBoard(&model->board);
    boardWidget.setVisible(true);

	add(boardWidget);

    boardWidget.invalidate();
}

void GameView::tearDownScreen()
{
    GameViewBase::tearDownScreen();
    remove(boardWidget);
}

void GameView::updateBoard()
{
	boardWidget.invalidate();
}
