#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(PieceColor color, int16_t pos_h, int16_t pos_w);
    ~Rook();

    bool canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif