#include "../include/Pawn.h"

const int FIRST_POSITION_BLACK_PAWN = 1;
const int FIRST_POSITION_WHITE_PAWN = 6;

Pawn::Pawn(PieceColor piece_color, Position piece_position)
{
    Pawn::piece_type_ = PieceType::PAWN;
    Pawn::piece_color_ = piece_color;
    setPosition(piece_position);
}

Pawn::~Pawn()
{
}

bool Pawn::canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{
    int move_direction = piece_color_ == PieceColor::WHITE ? -1 : 1;

    if (!configuration_bool[destination.row][destination.column])
    {
        if (piece_position_.column == destination.column)
        {
            if (piece_position_.row + move_direction == destination.row)
                return true;

            if (piece_position_.row + move_direction * 2 == destination.row && isFirstMove())
                return true;
        }
    }
    else
    {
        if (piece_position_.column + 1 == destination.column || piece_position_.column - 1 == destination.column)
        {
            if (piece_position_.row + move_direction == destination.row)
                return true;
        }
    }
    return false;
}

bool Pawn::isFirstMove() const
{
    if (piece_position_.row == FIRST_POSITION_BLACK_PAWN && piece_color_ == PieceColor::BLACK)
        return true;

    if (piece_position_.row == FIRST_POSITION_WHITE_PAWN && piece_color_ == PieceColor::WHITE)
        return true;

    return false;
}
