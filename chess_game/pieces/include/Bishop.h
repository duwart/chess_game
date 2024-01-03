#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:
    Bishop(PieceColor piece_color, Position piece_position);
    ~Bishop();

    bool canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* BISHOP_H */