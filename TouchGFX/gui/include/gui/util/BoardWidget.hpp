#ifndef APPLICATION_USER_GUI_BOARDWIDGET_HPP_
#define APPLICATION_USER_GUI_BOARDWIDGET_HPP_

#include <touchgfx/widgets/Widget.hpp>
#include <board/board.hpp>

#define BOARD_BLOCK_SIZE 15

class BoardWidget : public touchgfx::Widget {
public:
	BoardWidget() = default;
	~BoardWidget() {};
    virtual void draw(const touchgfx::Rect& invalidatedArea) const override;
    virtual touchgfx::Rect getSolidRect() const;

    void setBoard(BoardT* board) { this->board = board; }
private:
    const BoardT* board;
};

#endif /* APPLICATION_USER_GUI_BOARDWIDGET_HPP_ */
