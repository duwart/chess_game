#include "../include/Rook.h"
#include <iostream>

Rook::Rook(PieceColor color, int16_t pos_h, int16_t pos_w)
{
    Rook::piece_type_ = PieceType::ROOK;
    Rook::color_ = color;
    setPosition(pos_h, pos_w);
}

Rook::~Rook()
{
}

bool Rook::canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    bool aux = true;

    if (pos_h == position_.first && pos_w == position_.second)
    {
        return false;
    }
    if (pos_h == position_.first)
    {
        if (pos_w > position_.second)
        {
            for (int i = position_.second + 1; i < pos_w; i++)
            {
                aux = aux && !configuration_bool[pos_h][i];
            }
        }
        else
        {
            for (int i = position_.second - 1; i > pos_w; i--)
            {
                aux = aux && !configuration_bool[pos_h][i];
            }
        }
        return aux;
    }
    if (pos_w == position_.second)
    {
        if (pos_h > position_.first)
        {
            for (int i = position_.first + 1; i < pos_h; i++)
            {
                aux = aux && !configuration_bool[i][pos_w];
            }
        }
        else
        {
            for (int i = position_.first - 1; i > pos_h; i--)
            {
                aux = aux && !configuration_bool[i][pos_w];
            }
        }
        return aux;
    }
    return false;
}
