#include "../include/Queen.hpp"

Queen::Queen(PieceColor piece_color, Position piece_position) : Piece(piece_color, piece_position, PieceType::QUEEN)
{
    move_rook = std::make_shared<Rook>(piece_color_, piece_position_);
    move_bishop = std::make_shared<Bishop>(piece_color_, piece_position_);
}

Queen::~Queen() {}

bool Queen::canMove(Position destination) const
{
    move_rook->setPosition(piece_position_);
    move_bishop->setPosition(piece_position_);
    return move_rook->canMove(destination) || move_bishop->canMove(destination);
}
