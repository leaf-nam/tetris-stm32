#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <cstdint>

enum class Color : uint8_t
{
    BACKGROUND = 0,
    PANEL,
    FOREGROUND,
    COMMENT,

    CYAN,
    GREEN,
    ORANGE,
    PINK,
    PURPLE,
    RED,
    YELLOW
};

struct RGB
{
    uint8_t r, g, b;
};

class Colors {
public:
	static RGB getColor(int);
};

#endif
