#include "../include/King.h"

King::King(PieceColor color, int16_t pos_h, int16_t pos_w)
{
    King::piece_type_ = PieceType::KING;
    King::color_ = color;
    setPosition(pos_h, pos_w);
}

King::~King()
{
}

bool King::canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    bool aux = true;
    if (position_.first + 1 == pos_h && position_.second + 1 == pos_w)
    {
        return aux;
    }
    if (position_.first + 1 == pos_h && position_.second - 1 == pos_w)
    {
        return aux;
    }
    if (position_.first - 1 == pos_h && position_.second + 1 == pos_w)
    {
        return aux;
    }
    if (position_.first - 1 == pos_h && position_.second - 1 == pos_w)
    {
        return aux;
    }
    if (position_.first == pos_h && position_.second + 1 == pos_w)
    {
        return aux;
    }
    if (position_.first == pos_h && position_.second - 1 == pos_w)
    {
        return aux;
    }
    if (position_.first + 1 == pos_h && position_.second == pos_w)
    {
        return aux;
    }
    if (position_.first - 1 == pos_h && position_.second == pos_w)
    {
        return aux;
    }
    return false;
}
