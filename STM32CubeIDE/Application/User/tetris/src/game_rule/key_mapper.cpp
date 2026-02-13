#include "game_rule/key_mapper.hpp"

Action KeyMapper::map_key(int key)
{
    switch(key)
    {
        case Arrow::KEY_LEFT:
        case 'a':
            return Action::LEFT;

        case Arrow::KEY_RIGHT:
        case 'd':
            return Action::RIGHT;

        case Arrow::KEY_DOWN:
        case 's':
            return Action::DROP;

        case 'z':
        case 'q':
            return Action::ROTATE_CCW;

        case 'x':
        case Arrow::KEY_UP:
        case 'e':
            return Action::ROTATE_CW;

        case ' ':
        case 'f':
            return Action::HARD_DROP;

        case 'w':
        case 'c':
            return Action::SWAP;

        default:
            return Action::INVALID;
    }
}
