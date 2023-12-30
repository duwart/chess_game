#include "../include/Pawn.h"

Pawn::Pawn(PieceColor piece_color, int16_t pos_row, int16_t pos_column)
{
    Pawn::piece_type_ = PieceType::PAWN;
    Pawn::piece_color_ = piece_color;
    setPosition(pos_row, pos_column);
}

Pawn::~Pawn()
{
}

bool Pawn::canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    // change variable name
    int aux = piece_color_ == PieceColor::WHITE ? -1 : 1;

    if (!configuration_bool[pos_row][pos_column])
    {
        if (piece_position_.second == pos_column)
        {
            if (piece_position_.first + aux == pos_row)
            {
                return true;
            }
            if (piece_position_.first + aux * 2 == pos_row && isFirstMove())
            {
                return true;
            }
        }
    }
    else
    {
        if (piece_position_.second + 1 == pos_column || piece_position_.second - 1 == pos_column)
        {
            if (piece_position_.first + aux == pos_row)
            {
                return true;
            }
        }
    }
    return false;
}

bool Pawn::isFirstMove() const
{
    if (piece_position_.first == 1 && piece_color_ == PieceColor::BLACK)
    {
        return true;
    }
    if (piece_position_.first == 6 && piece_color_ == PieceColor::WHITE)
    {
        return true;
    }
    return false;
}
