#include "game_rule/rule_zen.hpp"

#include "util/action.hpp"

ZEN::ZEN(Board& board) : GameRule(board), level_game_time(0), current_level(1)
{
    // 120 == 1 minute, when timer is 500ms
    time_for_level_up[0] = 0;
    time_for_level_up[1] = 20;
    time_for_level_up[2] = 18;
    time_for_level_up[3] = 16;
    time_for_level_up[4] = 14;
    time_for_level_up[5] = 12;
    time_for_level_up[6] = 10;
    time_for_level_up[7] = 8;
    time_for_level_up[8] = 7;
    time_for_level_up[9] = 6;
    time_for_level_up[10] = 5;
}

int ZEN::update_score()
{
    int score = 0;
    int base_score = 100;
    int r = 21;
    while (r >= 2) {
        if (board.is_line_full(r)) {
            board.delete_line(r);
            score += base_score;
        }
        else {
            --r;
        }
    }
    return score;
}

bool ZEN::is_game_clear() { return false; }

bool ZEN::is_game_over()
{
    const BoardT& game_board = board.get_board();
    for (int r = 0; r < 2; ++r) {
        if (game_board[r] != 0) return true;
    }

    return false;
}

bool ZEN::time_and_level_update()
{
    level_game_time++;
    if ((current_level < 10) && (time_for_level_up[current_level + 1] <= level_game_time)) {
        level_game_time = 0;
        current_level++;
        return true;
    }
    return false;
}

int ZEN::get_level() { return current_level; }
