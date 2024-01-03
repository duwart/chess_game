#include "../include/Bishop.h"

Bishop::Bishop(PieceColor piece_color, Position piece_position)
{
    Bishop::piece_type_ = PieceType::BISHOP;
    Bishop::piece_color_ = piece_color;
    setPosition(piece_position);
}

Bishop::~Bishop()
{
}

bool Bishop::canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const
{

    int rowDirection = (destination.row > piece_position_.row) ? 1 : -1;
    int columnDirection = (destination.column > piece_position_.column) ? 1 : -1;

    for (int i = 1; i < BOARD_SIZE; ++i)
    {
        int checkRow = piece_position_.row + i * rowDirection;
        int checkColumn = piece_position_.column + i * columnDirection;

        if (checkRow == destination.row && checkColumn == destination.column)
        {
            return true;
        }
        if (configuration_bool[checkRow][checkColumn])
        {
            return false;
        }
    }

    return false;
}
