#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(PieceColor piece_color, int16_t pos_row, int16_t pos_column);
    ~Rook();

    bool canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* ROOK_H */