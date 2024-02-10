#include "../include/King.h"

King::King(PieceColor piece_color, Position piece_position)
{
    King::piece_type_ = PieceType::KING;
    King::piece_color_ = piece_color;
    setPosition(piece_position);
}

King::~King()
{
}

bool King::canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
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
