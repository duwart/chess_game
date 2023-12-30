#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
    King(PieceColor piece_color, int16_t pos_row, int16_t pos_column);
    ~King();

    bool canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* KING_H */