#ifndef APPLICATION_USER_GUI_HOLDWIDGET_HPP_
#define APPLICATION_USER_GUI_HOLDWIDGET_HPP_

#include <touchgfx/widgets/Widget.hpp>
#include <render_task.h>

class HoldWidget : public touchgfx::Widget {
public:
	HoldWidget() = default;
	~HoldWidget() {};
    virtual void draw(const touchgfx::Rect& invalidatedArea) const override;
    virtual touchgfx::Rect getSolidRect() const;

    void setHold(int* holdType) { this->holdType = holdType; }
private:
    int* holdType;
};

#endif /* APPLICATION_USER_GUI_HOLDWIDGET_HPP_ */
