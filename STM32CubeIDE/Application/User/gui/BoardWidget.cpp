#include <gui/util/BoardWidget.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <touchgfx/Color.hpp>

void BoardWidget::draw(const touchgfx::Rect& invalidatedArea) const {

	if (board == nullptr) return;

    touchgfx::LCD& lcd = touchgfx::HAL::lcd();
    touchgfx::Rect absolute = getAbsoluteRect();

    for (int y = 0; y < BOARD_ROW - 2; y++) {
        for (int x = 0; x < BOARD_COL; x++) {
            auto block = board[y * BOARD_COL + x];

			int drawX = absolute.x + x * BOARD_BLOCK_SIZE;
			int drawY = absolute.y + y * BOARD_BLOCK_SIZE;

			touchgfx::colortype color =
				touchgfx::Color::getColorFromRGB(
					100, x * 10, y * 10);

			lcd.fillRect(touchgfx::Rect(drawX, drawY, BOARD_BLOCK_SIZE, BOARD_BLOCK_SIZE), color);
        }
    }
}

touchgfx::Rect BoardWidget::getSolidRect() const
{
    return touchgfx::Rect(0, 0, getWidth(), getHeight());
}

