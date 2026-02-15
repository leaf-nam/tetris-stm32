#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include <gui_generated/game_screen/GameViewBase.hpp>
#include <gui/game_screen/GamePresenter.hpp>
#include <gui/util/BoardWidget.hpp>
#include <render/color.hpp>
#include <render/pos.hpp>

#define UNIT_X 20
#define UNIT_Y 20

class GameView : public GameViewBase
{
public:
    GameView();
    virtual ~GameView() {}
    virtual void updateBoard();
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
private:
};

#endif // GAMEVIEW_HPP
