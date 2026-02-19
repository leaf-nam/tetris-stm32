#include <gui/game_screen/GameView.hpp>
#include <gui/game_screen/GamePresenter.hpp>

GamePresenter::GamePresenter(GameView& v)
    : view(v)
{

}

void GamePresenter::activate()
{

}

void GamePresenter::deactivate()
{

}

void GamePresenter::notifyBoardChanged()
{
    view.updateBoard();
}

void GamePresenter::notifyHoldChanged()
{
	view.updateHold();
}

void GamePresenter::notifyNextChanged()
{
	view.updateNext();
}

void GamePresenter::notifyTimerChanged(int sec)
{
	view.updateTimer(sec);
}

void GamePresenter::notifyGameOverChanged()
{
	view.updateGameOver();
}
