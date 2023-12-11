#include "../include/Queen.h"
#include "../include/Rook.h"
#include "../include/Bishop.h"

Queen::Queen(PieceColor color, int16_t pos_h, int16_t pos_w)
{
    Queen::piece_type_ = PieceType::QUEEN;
    Queen::color_ = color;
    setPosition(pos_h, pos_w);
}

Queen::~Queen()
{
}

bool Queen::canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    auto move_1 = std::make_shared<Rook>(color_, position_.first, position_.second);
    auto move_2 = std::make_shared<Bishop>(color_, position_.first, position_.second);
    return move_1->canMove(pos_h, pos_w, configuration_bool) || move_2->canMove(pos_h, pos_w, configuration_bool);
}
