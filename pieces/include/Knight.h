#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(PieceColor piece_color, int16_t pos_row, int16_t pos_column);
    ~Knight();

    bool canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* KNIGHT_H */