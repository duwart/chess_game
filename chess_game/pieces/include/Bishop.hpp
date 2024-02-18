#pragma once

#include "Piece.hpp"

class Bishop final : public Piece
{
public:
    Bishop(PieceColor piece_color, Position piece_position);
    ~Bishop();

    bool canMove(Position destination) const override;
};
