#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(PieceColor piece_color, Position piece_position);
    ~Rook();

    bool isInHorizontalRange(int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const;
    bool isInVerticalRange(int16_t pos_row, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const;
    bool canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* ROOK_H */