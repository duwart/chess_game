#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
    King(PieceColor piece_color, Position piece_position);
    ~King();

    bool in_check_ = false;

    bool isInCheck()
    {
        return in_check_;
    }
    void setInCheck(bool in_check)
    {
        in_check_ = in_check;
    }
    bool canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const override;
};

#endif /* KING_H */