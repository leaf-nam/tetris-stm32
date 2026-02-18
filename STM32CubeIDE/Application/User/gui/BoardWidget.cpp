#include <gui/util/BoardWidget.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <touchgfx/Color.hpp>
#include <render/color.hpp>

void BoardWidget::draw(const touchgfx::Rect& invalidatedArea) const {

	if (board == nullptr) return;

    touchgfx::LCD& lcd = touchgfx::HAL::lcd();
    touchgfx::Rect absolute = getAbsoluteRect();

    for (int y = 0; y < RENDER_TASK_BOARD_ROW; y++) {
        for (int x = 0; x < RENDER_TASK_BOARD_COL; x++) {
			int drawX = absolute.x + x * BOARD_BLOCK_SIZE;
			int drawY = absolute.y + y * BOARD_BLOCK_SIZE;
			RGB rgb = Colors::getColor((*board)[y][x]);

			touchgfx::colortype color =
				touchgfx::Color::getColorFromRGB(
					rgb.r, rgb.g, rgb.b);

			lcd.fillRect(touchgfx::Rect(drawX, drawY, BOARD_BLOCK_SIZE, BOARD_BLOCK_SIZE), color);
        }
    }
}

touchgfx::Rect BoardWidget::getSolidRect() const
{
	return touchgfx::Rect(0, 0, 0, 0);
}

