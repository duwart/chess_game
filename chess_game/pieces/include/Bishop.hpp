#pragma once
#include "Piece.hpp"

class Bishop : public Piece
{
public:
    Bishop(PieceColor piece_color, Position piece_position);
    ~Bishop();

    bool canMove(Position destination) const override;
};
