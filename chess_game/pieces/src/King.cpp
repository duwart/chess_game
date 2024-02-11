#include "../include/King.hpp"

King::King(PieceColor piece_color, Position piece_position) : Piece(piece_color, piece_position, PieceType::KING)
{
    bool in_check_ = false;
}

King::~King() {}

bool King::canMove(Position destination) const
{
    bool in_range = piece_position_.column + 1 == destination.column || piece_position_.column - 1 == destination.column || piece_position_.column == destination.column;

    if (piece_position_.row + 1 == destination.row && in_range)
        return true;

    if (piece_position_.row - 1 == destination.row && in_range)
        return true;

    if (piece_position_.row == destination.row && in_range)
        return true;

    return false;
}

bool King::isInCheck()
{
    return in_check_;
}
void King::setInCheck(bool in_check)
{
    King::in_check_ = in_check;
}
