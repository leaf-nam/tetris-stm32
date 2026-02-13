#include <gui/game_screen/GameView.hpp>
#include <touchgfx/Color.hpp>

GameView::GameView()
{

}

void GameView::setupScreen()
{
    GameViewBase::setupScreen();

    box.setPosition(20, 20, 50, 50);
    box.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    add(box);
}

void GameView::render()
{
}

void GameView::tearDownScreen()
{
    GameViewBase::tearDownScreen();
}
