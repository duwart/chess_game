#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(PieceColor color, int16_t pos_h, int16_t pos_w);
    ~Pawn();

    bool canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;

private:
    bool isFirstMove() const;
};

#endif