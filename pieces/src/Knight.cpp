#include "../include/Knight.h"

Knight::Knight(PieceColor color, int16_t pos_h, int16_t pos_w)
{
    Knight::piece_type_ = PieceType::KNIGHT;
    Knight::color_ = color;
    setPosition(pos_h, pos_w);
}

Knight::~Knight()
{
}

bool Knight::canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    if (position_.first + 2 == pos_h)
    {
        if (position_.second + 1 == pos_w || position_.second - 1 == pos_w)
            return true;
    }

    if (position_.first - 2 == pos_h)
    {
        if (position_.second + 1 == pos_w || position_.second - 1 == pos_w)
            return true;
    }

    if (position_.first + 1 == pos_h)
    {
        if (position_.second - 2 == pos_w || position_.second + 2 == pos_w)
            return true;
    }

    if (position_.first - 1 == pos_h)
    {
        if (position_.second + 2 == pos_w || position_.second - 2 == pos_w)
            return true;
    }

    return false;
}
