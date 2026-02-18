#include <gui/util/NextWidget.hpp>
#include <gui/util/BoardWidget.hpp>
#include <tetromino/tetromino.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <touchgfx/Color.hpp>
#include <render/color.hpp>

void NextWidget::draw(const touchgfx::Rect& invalidatedArea) const {

    touchgfx::LCD& lcd = touchgfx::HAL::lcd();
    touchgfx::Rect absolute = getAbsoluteRect();

    int nextType;
    for (int i = 0; i < 3; ++i) {
    	nextType = next[i];
    	if (nextType < 0 || nextType > 7) continue;

    	const Mino& minoShape = TETROMINO[nextType][0];

		for (int y = 0; y < RENDER_TASK_MINO_SIZE; y++) {
			for (int x = 0; x < RENDER_TASK_MINO_SIZE; x++) {
				int drawX = absolute.x + x * BOARD_BLOCK_SIZE;
				int drawY = absolute.y + y * BOARD_BLOCK_SIZE
						+ ((BOARD_BLOCK_SIZE - 3) * RENDER_TASK_MINO_SIZE) * i;

				RGB rgb = (minoShape[y][x] == 0)?
					Colors::getColor(8) :
					Colors::getColor(nextType);

				touchgfx::colortype color =
					touchgfx::Color::getColorFromRGB(
						rgb.r, rgb.g, rgb.b);

				lcd.fillRect(touchgfx::Rect(drawX, drawY, BOARD_BLOCK_SIZE, BOARD_BLOCK_SIZE), color);
			}
		}
    }
}

touchgfx::Rect NextWidget::getSolidRect() const
{
    return touchgfx::Rect(0, 0, getWidth(), getHeight());
}

