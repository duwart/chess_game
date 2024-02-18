#pragma once

#include <memory>

#include "../include/Rook.hpp"
#include "../include/Bishop.hpp"
#include "Piece.hpp"

class Queen final : public Piece
{
private:
    std::shared_ptr<Rook> move_rook;
    std::shared_ptr<Bishop> move_bishop;

public:
    Queen(PieceColor piece_color, Position piece_position);
    ~Queen();

    bool canMove(Position destination) const override;
};
