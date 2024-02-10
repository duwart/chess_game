#include "../include/Rook.h"

Rook::Rook(PieceColor piece_color, Position piece_position)
{
    Rook::piece_type_ = PieceType::ROOK;
    Rook::piece_color_ = piece_color;
    setPosition(piece_position);
}

Rook::~Rook()
{
}

bool Rook::canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    if (destination.row == piece_position_.row)
        return isInHorizontalRange(destination.column, configuration_bool);

    if (destination.column == piece_position_.column)
        return isInVerticalRange(destination.row, configuration_bool);

    return false;
}

bool Rook::isInHorizontalRange(int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    auto step_direction = (pos_column > piece_position_.column) ? 1 : -1;

    for (int column = piece_position_.column + step_direction; column < pos_column; column += step_direction)
    {
        if (configuration_bool[piece_position_.row][column])
            return false;
    }
    return true;
}

bool Rook::isInVerticalRange(int16_t pos_row, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    auto step_direction = (pos_row > piece_position_.row) ? 1 : -1;

    for (int row = piece_position_.row + step_direction; row < pos_row; row += step_direction)
    {
        if (configuration_bool[row][piece_position_.column])
            return false;
    }

    return true;
}
