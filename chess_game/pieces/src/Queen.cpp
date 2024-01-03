#include "../include/Queen.h"
#include "../include/Rook.h"
#include "../include/Bishop.h"

#include <memory> // make_shared

Queen::Queen(PieceColor piece_color, Position piece_position)
{
    Queen::piece_type_ = PieceType::QUEEN;
    Queen::piece_color_ = piece_color;
    setPosition(piece_position);
}

Queen::~Queen()
{
}

bool Queen::canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    auto move_rook = std::make_shared<Rook>(piece_color_, piece_position_);
    auto move_bishop = std::make_shared<Bishop>(piece_color_, piece_position_);
    return move_rook->canMove(destination, configuration_bool) || move_bishop->canMove(destination, configuration_bool);
}
