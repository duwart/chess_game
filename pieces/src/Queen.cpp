#include "../include/Queen.h"
#include "../include/Rook.h"
#include "../include/Bishop.h"

#include <memory> // make_shared

Queen::Queen(PieceColor piece_color, int16_t pos_row, int16_t pos_column)
{
    Queen::piece_type_ = PieceType::QUEEN;
    Queen::piece_color_ = piece_color;
    setPosition(pos_row, pos_column);
}

Queen::~Queen()
{
}

bool Queen::canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    auto move_1 = std::make_shared<Rook>(piece_color_, piece_position_.first, piece_position_.second);
    auto move_2 = std::make_shared<Bishop>(piece_color_, piece_position_.first, piece_position_.second);
    return move_1->canMove(pos_row, pos_column, configuration_bool) || move_2->canMove(pos_row, pos_column, configuration_bool);
}
