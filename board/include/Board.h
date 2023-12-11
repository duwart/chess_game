#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <windows.h>

#include "../../pieces/include/Bishop.h"
#include "../../pieces/include/King.h"
#include "../../pieces/include/Knight.h"
#include "../../pieces/include/Pawn.h"
#include "../../pieces/include/Piece.h"
#include "../../pieces/include/Queen.h"
#include "../../pieces/include/Rook.h"

#define BOARD_SIZE 8

class Board
{
public:
    Board();
    ~Board();

    std::shared_ptr<Piece> configuration[BOARD_SIZE][BOARD_SIZE];
    bool configuration_bool[BOARD_SIZE][BOARD_SIZE];

    void initalConfiguration();
    void updateBoard(std::pair<int16_t, int16_t> old_, std::pair<int16_t, int16_t> new_);
    void printBoard();
    void SetConsoleColour(WORD *Attributes, DWORD Colour);
    void ResetConsoleColour(WORD Attributes);
    std::string typeToString(PieceType type);
};

#endif