#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(PieceColor piece_color, int16_t pos_row, int16_t pos_column);
    ~Pawn();

    bool canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;

private:
    bool isFirstMove() const;
};

#endif /* PAWN_H */