#include <render/color.hpp>

RGB Colors::getColor(int type) {
    switch (type) {
    case 0:
        return {120, 220, 255};
    case 1: // O 미노 (Yellow)
        return {255, 180, 90};
    case 2: // Z 미노 (Red)
        return {255, 90, 90};
    case 3: // S 미노 (Green)
        return {80, 255, 150};
    case 4: // J 미노 (Blue)
        return {255, 110, 200};
    case 5: // L 미노 (Orange)
        return {255, 240, 120};
    case 6: // T 미노 (Purple)
        return {200, 160, 255};
    case 7: // 방해 블록 (Gray)
        return {140, 150, 200};
    default: // 예외 (Reset)
        return {30, 32, 45};
    }
}
