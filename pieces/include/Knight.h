#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(PieceColor color, int16_t pos_h, int16_t pos_w);
    ~Knight();

    bool canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif