#pragma once

#include "Piece.hpp"

class King final : public Piece
{
public:
    King(PieceColor piece_color, Position piece_position);
    ~King();

    bool canMove(Position destination) const override;
};
