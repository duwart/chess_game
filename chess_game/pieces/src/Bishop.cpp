#include "../include/Bishop.hpp"

Bishop::Bishop(PieceColor piece_color, Position piece_position) : Piece(piece_color, piece_position, PieceType::BISHOP) {}

Bishop::~Bishop() {}

bool Bishop::canMove(Position destination) const
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
        if (configuration_board[checkRow][checkColumn])
        {
            return false;
        }
    }

    return false;
}
