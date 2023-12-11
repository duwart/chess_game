#include "../include/Pawn.h"

Pawn::Pawn(PieceColor color, int16_t pos_h, int16_t pos_w)
{
    Pawn::piece_type_ = PieceType::PAWN;
    Pawn::color_ = color;
    setPosition(pos_h, pos_w);
}

Pawn::~Pawn()
{
}

bool Pawn::canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    int aux = color_ == PieceColor::WHITE ? -1 : 1;

    if (position_.second == pos_w)
    {
        if (position_.first + aux == pos_h)
        {
            if (configuration_bool[pos_h][pos_w])
            {
                return false;
            }
            return true;
        }
        if (position_.first + aux * 2 == pos_h && isFirstMove())
        {
            if (configuration_bool[pos_h][pos_w])
            {
                return false;
            }
            return true;
        }
    }
    if (position_.second + 1 == pos_w || position_.second - 1 == pos_w)
    {
        if (position_.first + aux == pos_h)
        {
            if (configuration_bool[pos_h][pos_w])
            {
                return true;
            }
            return false;
        }
    }
    return false;
}

bool Pawn::isFirstMove() const
{
    if (position_.first == 1 && color_ == PieceColor::BLACK)
    {
        return true;
    }
    if (position_.first == 6 && color_ == PieceColor::WHITE)
    {
        return true;
    }
    return false;
}
