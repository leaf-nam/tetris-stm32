#include <gui/util/HoldWidget.hpp>
#include <gui/util/BoardWidget.hpp>
#include <tetromino/tetromino.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <touchgfx/Color.hpp>
#include <render/color.hpp>

void HoldWidget::draw(const touchgfx::Rect& invalidatedArea) const {

	if (*holdType < 0 || *holdType > 7) return;

	const Mino& minoShape = TETROMINO[*holdType][0];

    touchgfx::LCD& lcd = touchgfx::HAL::lcd();
    touchgfx::Rect absolute = getAbsoluteRect();

    for (int y = 0; y < RENDER_TASK_MINO_SIZE; y++) {
        for (int x = 0; x < RENDER_TASK_MINO_SIZE; x++) {
        	int drawX = absolute.x + x * BOARD_BLOCK_SIZE;
			int drawY = absolute.y + y * BOARD_BLOCK_SIZE;

			RGB rgb = (minoShape[y][x] == 0)?
				Colors::getColor(8) :
				Colors::getColor(*holdType);

			touchgfx::colortype color =
				touchgfx::Color::getColorFromRGB(
					rgb.r, rgb.g, rgb.b);

			lcd.fillRect(touchgfx::Rect(drawX, drawY, BOARD_BLOCK_SIZE, BOARD_BLOCK_SIZE), color);
        }
    }
}

touchgfx::Rect HoldWidget::getSolidRect() const
{
    return touchgfx::Rect(0, 0, getWidth(), getHeight());
}

