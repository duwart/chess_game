#include "../include/Knight.hpp"

Knight::Knight(PieceColor piece_color, Position piece_position) : Piece(piece_color, piece_position, PieceType::KNIGHT) {}

Knight::~Knight() {}

bool Knight::canMove(Position destination) const
{
    if (piece_position_.row + 2 == destination.row || piece_position_.row - 2 == destination.row)
    {
        if (piece_position_.column + 1 == destination.column || piece_position_.column - 1 == destination.column)
            return true;
    }

    if (piece_position_.row + 1 == destination.row || piece_position_.row - 1 == destination.row)
    {
        if (piece_position_.column - 2 == destination.column || piece_position_.column + 2 == destination.column)
            return true;
    }

    return false;
}
