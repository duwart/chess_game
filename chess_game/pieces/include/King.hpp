#pragma once
#include "Piece.hpp"

class King : public Piece
{
private:
    bool in_check_;

public:
    King(PieceColor piece_color, Position piece_position);
    ~King();

    bool isInCheck();
    void setInCheck(bool in_check);
    bool canMove(Position destination) const override;
};
