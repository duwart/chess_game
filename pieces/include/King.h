#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
    King(PieceColor color, int16_t pos_h, int16_t pos_w);
    ~King();

    bool canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif