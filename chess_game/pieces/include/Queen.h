#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(PieceColor piece_color, int16_t pos_row, int16_t pos_column);
    ~Queen();

    bool canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* QUEEN_H */