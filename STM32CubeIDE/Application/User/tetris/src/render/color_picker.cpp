#include "render/color_picker.hpp"

#include <random>
#include <string>

using namespace std;

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<int> dist(static_cast<int>(Color::CYAN),
                                               static_cast<int>(Color::YELLOW));
string ColorPicker::get_block_color(int type) { return get_color(get_color_key(type)).c_str(); }

string ColorPicker::get_block_color(const Tetromino& tetromino)
{
    return get_color(get_color_key(tetromino));
}

Color ColorPicker::get_color_key(const Tetromino& tetromino)
{
    return get_color_key(tetromino.get_mino_type());
}

Color ColorPicker::get_color_key(int type)
{
    switch (type) {
    case 0:
        return Color::CYAN;
    case 1: // O �̳� (Yellow - �����)
        return Color::ORANGE;
    case 2: // Z �̳� (Red - ������)
        return Color::RED;
    case 3: // S �̳� (Green - �ʷϻ�)
        return Color::GREEN;
    case 4: // J �̳� (Blue - �Ķ���)
        return Color::PINK;
    case 5: // L �̳� (Orange -> �͹̳��� ���� ��� or ���� ������� ��ü)
        return Color::YELLOW;
    case 6: // T �̳� (Purple - �����)
        return Color::PURPLE;
    case 7: // ���� ��� (Gray - ȸ��)
        return Color::COMMENT;
    default: // ���� (Reset)
        return Color::BACKGROUND;
    }
}

Color ColorPicker::get_random_color() { return static_cast<Color>(dist(gen)); }
