#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include <gui_generated/game_screen/GameViewBase.hpp>
#include <gui/game_screen/GamePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>

class GameView : public GameViewBase
{
public:
    GameView();
    virtual ~GameView() {}
    virtual void render();
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
private:
    touchgfx::Box box;
};

#endif // GAMEVIEW_HPP
