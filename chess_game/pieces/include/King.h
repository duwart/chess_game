#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
    King(PieceColor piece_color, Position piece_position);
    ~King();

    bool canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* KING_H */