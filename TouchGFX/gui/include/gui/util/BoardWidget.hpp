#ifndef APPLICATION_USER_GUI_BOARDWIDGET_HPP_
#define APPLICATION_USER_GUI_BOARDWIDGET_HPP_

#include <touchgfx/widgets/Widget.hpp>
#include <render_task.h>

#define BOARD_BLOCK_SIZE 15

class BoardWidget : public touchgfx::Widget {
public:
	BoardWidget() = default;
	~BoardWidget() {};
    virtual void draw(const touchgfx::Rect& invalidatedArea) const override;
    virtual touchgfx::Rect getSolidRect() const;

    void setBoard(Render_Board* board) { this->board = board; }
private:
    const Render_Board* board;
};

#endif /* APPLICATION_USER_GUI_BOARDWIDGET_HPP_ */
