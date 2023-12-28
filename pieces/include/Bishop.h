#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(PieceColor piece_color, int16_t pos_row, int16_t pos_column);
    ~Bishop();

    bool canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* BISHOP_H */