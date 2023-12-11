#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(PieceColor color, int16_t pos_h, int16_t pos_w);
    ~Queen();

    bool canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif