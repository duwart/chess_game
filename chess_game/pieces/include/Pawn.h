#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(PieceColor piece_color, Position piece_position);
    ~Pawn();

    bool canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;

private:
    bool isFirstMove() const;
};

#endif /* PAWN_H */