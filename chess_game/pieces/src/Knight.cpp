#include "../include/Knight.h"

Knight::Knight(PieceColor piece_color, Position piece_position)
{
    Knight::piece_type_ = PieceType::KNIGHT;
    Knight::piece_color_ = piece_color;
    setPosition(piece_position);
}

Knight::~Knight()
{
}

bool Knight::canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
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
