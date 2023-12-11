#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(PieceColor color, int16_t pos_h, int16_t pos_w);
    ~Bishop();

    bool canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif