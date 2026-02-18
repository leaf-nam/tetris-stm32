#ifndef APPLICATION_USER_GUI_NEXTWIDGET_HPP_
#define APPLICATION_USER_GUI_NEXTWIDGET_HPP_

#include <touchgfx/widgets/Widget.hpp>
#include <render_task.h>

class NextWidget : public touchgfx::Widget {
public:
	NextWidget() = default;
	~NextWidget() {};
    virtual void draw(const touchgfx::Rect& invalidatedArea) const override;
    virtual touchgfx::Rect getSolidRect() const;

    void setNext(int* next) { this->next = next; }
private:
    const int* next;
};

#endif /* APPLICATION_USER_GUI_NEXTWIDGET_HPP_ */
