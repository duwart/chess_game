#include "../include/King.h"

King::King(PieceColor piece_color, int16_t pos_row, int16_t pos_column)
{
    King::piece_type_ = PieceType::KING;
    King::piece_color_ = piece_color;
    setPosition(pos_row, pos_column);
}

King::~King()
{
}

bool King::canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    // change variable name
    bool in_range = piece_position_.second + 1 == pos_column || piece_position_.second - 1 == pos_column || piece_position_.second == pos_column;

    if (piece_position_.first + 1 == pos_row && in_range)
    {
        return true;
    }
    if (piece_position_.first - 1 == pos_row && in_range)
    {
        return true;
    }
    if (piece_position_.first == pos_row && in_range)
    {
        return true;
    }

    return false;
}
