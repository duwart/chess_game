#pragma once
#include "Piece.hpp"

class Pawn : public Piece
{
private:
    bool isFirstMove() const;

public:
    Pawn(PieceColor piece_color, Position piece_position);
    ~Pawn();

    bool canMove(Position destination) const override;
};
