#pragma once
#include "Piece.hpp"

class Knight : public Piece
{
public:
    Knight(PieceColor piece_color, Position piece_position);
    ~Knight();

    bool canMove(Position destination) const override;
};
