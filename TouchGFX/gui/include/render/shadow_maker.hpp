#ifndef __SHADOW_MAKER_HPP__
#define __SHADOW_MAKER_HPP__

#include "board/board.hpp"
#include "render/pos.hpp"
#include "tetromino/tetromino.hpp"

#include <array>
#define SHADOW_SIZE 4

class ShadowMaker
{
  public:
    std::array<Pos, SHADOW_SIZE> get_shadow_pos(const Board& board, const Tetromino& tetromino);
    bool is_shadow(std::array<Pos, SHADOW_SIZE>, Pos);

  private:
    std::array<Pos, SHADOW_SIZE> get_mino_pos(const Tetromino& tetromino);
    bool is_collide(const BoardT& board, const Tetromino& tetromino, Pos);
};

#endif // !__SHADOW_MAKER_HPP__
