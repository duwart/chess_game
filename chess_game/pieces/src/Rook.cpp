#include "../include/Rook.hpp"

Rook::Rook(PieceColor piece_color, Position piece_position) : Piece(piece_color, piece_position, PieceType::ROOK) {}

Rook::~Rook() {}

bool Rook::canMove(Position destination) const
{
    if (destination.row == piece_position_.row)
        return isInHorizontalRange(destination.column);

    if (destination.column == piece_position_.column)
        return isInVerticalRange(destination.row);

    return false;
}

bool Rook::isInHorizontalRange(int16_t pos_column) const
{
    auto step_direction = (pos_column > piece_position_.column) ? 1 : -1;

    for (int column = piece_position_.column + step_direction; column < pos_column; column += step_direction)
    {
        if (configuration_board[piece_position_.row][column])
            return false;
    }
    return true;
}

bool Rook::isInVerticalRange(int16_t pos_row) const
{
    auto step_direction = (pos_row > piece_position_.row) ? 1 : -1;

    for (int row = piece_position_.row + step_direction; row < pos_row; row += step_direction)
    {
        if (configuration_board[row][piece_position_.column])
            return false;
    }

    return true;
}
