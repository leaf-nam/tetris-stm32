#include "render/shadow_maker.hpp"
#include "render/pos.hpp"

using namespace std;

bool ShadowMaker::is_shadow(array<Pos, SHADOW_SIZE> shadows, Pos pos)
{
    for (auto shadow : shadows) {
        if (shadow.y == pos.y && shadow.x == pos.x) {
            return true;
        }
    }
    return false;
}

array<Pos, SHADOW_SIZE> ShadowMaker::get_shadow_pos(const Board& board, const Tetromino& tetromino)
{
	array<Pos, SHADOW_SIZE> shadow_pos;
    int r = tetromino.get_pos().first;
    int c = tetromino.get_pos().second;

    const BoardT& board2D = board.get_board();
    auto mino = tetromino.get_mino_type();

    while (!is_collide(board2D, tetromino, {c, ++r}));

    int delta = r - tetromino.get_pos().first - 1;
    array<Pos, SHADOW_SIZE> base_position = get_mino_pos(tetromino);
    int idx = 0;
    for (auto& p : base_position) {
        shadow_pos[idx++] = {p.x, p.y + delta};
    }

    return shadow_pos;
}

array<Pos, SHADOW_SIZE> ShadowMaker::get_mino_pos(const Tetromino& tetromino)
{
	array<Pos, SHADOW_SIZE> ret;

	int idx = 0;
    for (int i = 0; i < MINO_SIZE; ++i) {
        for (int j = 0; j < MINO_SIZE; ++j) {
            if (tetromino.get_shape()[i][j] != 0) {
                ret[idx++] = {tetromino.get_pos().second + j, tetromino.get_pos().first + i};
            }
        }
    }

    return ret;
}

bool ShadowMaker::is_collide(const BoardT& board, const Tetromino& tetromino, Pos pos)
{
    for (int i = 0; i < MINO_SIZE; ++i) {
        for (int j = 0; j < MINO_SIZE; ++j) {
            if (tetromino.get_shape()[i][j] != 0) {
                int board_r = pos.y + i;
                int board_c = pos.x + j;

                if (board_r < 0 || board_r >= BOARD_ROW || board_c < 0 || board_c >= BOARD_COL) {
                    return true;
                }

                if (board[board_r][board_c] != 8) {
                    return true;
                }
            }
        }
    }

    return false;
}
