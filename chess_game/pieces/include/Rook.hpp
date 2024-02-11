#pragma once
#include "Piece.hpp"

class Rook : public Piece
{
public:
    Rook(PieceColor piece_color, Position piece_position);
    ~Rook();

    bool canMove(Position destination) const override;

private:
    bool isInHorizontalRange(int16_t pos_column) const;
    bool isInVerticalRange(int16_t pos_row) const;
};
