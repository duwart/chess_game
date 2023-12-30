#include "../include/Knight.h"

Knight::Knight(PieceColor piece_color, int16_t pos_row, int16_t pos_column)
{
    Knight::piece_type_ = PieceType::KNIGHT;
    Knight::piece_color_ = piece_color;
    setPosition(pos_row, pos_column);
}

Knight::~Knight()
{
}

bool Knight::canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    if (piece_position_.first + 2 == pos_row || piece_position_.first - 2 == pos_row)
    {
        if (piece_position_.second + 1 == pos_column || piece_position_.second - 1 == pos_column)
            return true;
    }

    if (piece_position_.first + 1 == pos_row || piece_position_.first - 1 == pos_row)
    {
        if (piece_position_.second - 2 == pos_column || piece_position_.second + 2 == pos_column)
            return true;
    }

    return false;
}
