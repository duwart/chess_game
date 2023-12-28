#include "../include/Bishop.h"

Bishop::Bishop(PieceColor piece_color, int16_t pos_row, int16_t pos_column)
{
    Bishop::piece_type_ = PieceType::BISHOP;
    Bishop::piece_color_ = piece_color;
    setPosition(pos_row, pos_column);
}

Bishop::~Bishop()
{
}

bool Bishop::canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    bool aux0, aux1, aux2, aux3;
    aux0 = aux1 = aux2 = aux3 = true;

    for (int i = 1; i < BOARD_SIZE; i++)
    {
        if (piece_position_.first + i == pos_row && piece_position_.second + i == pos_column)
        {
            return aux0;
        }
        if (piece_position_.first - i == pos_row && piece_position_.second - i == pos_column)
        {
            return aux1;
        }
        if (piece_position_.first + i == pos_row && piece_position_.second - i == pos_column)
        {
            return aux2;
        }
        if (piece_position_.first - i == pos_row && piece_position_.second + i == pos_column)
        {
            return aux3;
        }
        if (piece_position_.first + i <= BOARD_SIZE && (piece_position_.second + i <= BOARD_SIZE || piece_position_.second - i >= 0))
        {
            aux0 = aux0 && !configuration_bool[piece_position_.first + i][piece_position_.second + i];
            aux2 = aux2 && !configuration_bool[piece_position_.first + i][piece_position_.second - i];
        }
        if (piece_position_.first - i >= 0 && (piece_position_.second - i >= 0 || piece_position_.second + i <= BOARD_SIZE))
        {
            aux1 = aux1 && !configuration_bool[piece_position_.first - i][piece_position_.second - i];
            aux3 = aux3 && !configuration_bool[piece_position_.first - i][piece_position_.second + i];
        }
    }

    return false;
}
