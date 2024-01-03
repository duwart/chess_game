#ifndef BOARD_H
#define BOARD_H

#include <iostream>  // cin, cout, endl
#include <string>    // getline
#include <windows.h> // bunch of things

#include "../../pieces/include/Bishop.h"
#include "../../pieces/include/King.h"
#include "../../pieces/include/Knight.h"
#include "../../pieces/include/Pawn.h"
#include "../../pieces/include/Piece.h"
#include "../../pieces/include/Queen.h"
#include "../../pieces/include/Rook.h"

class Board
{
public:
    Board();
    ~Board();

    std::shared_ptr<Piece> configuration[BOARD_SIZE][BOARD_SIZE];
    bool configuration_bool[BOARD_SIZE][BOARD_SIZE] = {{false}};

    void setInitalConfiguration();
    void updateBoard(Position actual_position, Position destination_position);
    bool isValidMove(Position actual_position, Position destination_position);
    void promotePawn(std::shared_ptr<Piece> pawn);
    void addPieceToBoard(PieceColor color, PieceType type, Position position_on_board);
    void printBoard();
    void setConsoleColour(WORD *Attributes, DWORD Colour);
    void resetConsoleColour(WORD Attributes);
    std::string typeToString(PieceType type);
};

#endif /* BOARD_H */