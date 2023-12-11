#include "../include/Bishop.h"
#include <iostream>

Bishop::Bishop(PieceColor color, int16_t pos_h, int16_t pos_w)
{
    Bishop::piece_type_ = PieceType::BISHOP;
    Bishop::color_ = color;
    setPosition(pos_h, pos_w);
}

Bishop::~Bishop()
{
}

bool Bishop::canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    bool aux0, aux1, aux2, aux3;
    aux0 = aux1 = aux2 = aux3 = true;

    for (int i = 1; i < BOARD_SIZE; i++)
    {
        if (position_.first + i == pos_h && position_.second + i == pos_w)
        {
            return aux0;
        }
        else
        {
            if (position_.first + i <= BOARD_SIZE && position_.second + i <= BOARD_SIZE)
            {
                aux0 = aux0 && !configuration_bool[position_.first + i][position_.second + i];
            }
        }
        if (position_.first - i == pos_h && position_.second - i == pos_w)
        {
            return aux1;
        }
        else
        {
            if (position_.first - i >= 0 && position_.second - i >= 0)
            {
                aux1 = aux1 && !configuration_bool[position_.first - i][position_.second - i];
            }
        }
        if (position_.first + i == pos_h && position_.second - i == pos_w)
        {
            return aux2;
        }
        else
        {
            if (position_.first + i <= BOARD_SIZE && position_.second - i >= 0)
            {
                aux2 = aux2 && !configuration_bool[position_.first + i][position_.second - i];
            }
        }
        if (position_.first - i == pos_h && position_.second + i == pos_w)
        {
            return aux3;
        }
        else
        {
            if (position_.first - i >= 0 && position_.second + i <= BOARD_SIZE)
            {
                aux3 = aux3 && !configuration_bool[position_.first - i][position_.second + i];
            }
        }
    }

    return false;
}
