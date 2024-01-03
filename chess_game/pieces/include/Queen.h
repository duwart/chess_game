#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(PieceColor piece_color, Position piece_position);
    ~Queen();

    bool canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* QUEEN_H */