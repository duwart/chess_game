#include "../include/Rook.h"

Rook::Rook(PieceColor piece_color, int16_t pos_row, int16_t pos_column)
{
    Rook::piece_type_ = PieceType::ROOK;
    Rook::piece_color_ = piece_color;
    setPosition(pos_row, pos_column);
}

Rook::~Rook()
{
}

// Refactore this function
bool Rook::canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    bool ret = true;

    if (pos_column > piece_position_.second && pos_row == piece_position_.first)
    {
        for (int column = piece_position_.second + 1; column < pos_column; column++)
        {
            ret = ret && !configuration_bool[pos_row][column];
        }
        return ret;
    }
    if (pos_column < piece_position_.second && pos_row == piece_position_.first)
    {
        for (int column = piece_position_.second - 1; column > pos_column; column--)
        {
            ret = ret && !configuration_bool[pos_row][column];
        }
        return ret;
    }

    if (pos_row > piece_position_.first && pos_column == piece_position_.second)
    {
        for (int row = piece_position_.first + 1; row < pos_row; row++)
        {
            ret = ret && !configuration_bool[row][pos_column];
        }
        return ret;
    }
    if (pos_row < piece_position_.first && pos_column == piece_position_.second)
    {
        for (int row = piece_position_.first - 1; row > pos_row; row--)
        {
            ret = ret && !configuration_bool[row][pos_column];
        }
        return ret;
    }
    return false;
}
