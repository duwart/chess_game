#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

#include "../../board/include/Board.hpp"

class Game final
{
private:
    short int turn;
    PieceColor current_player_;

    void setConsoleColour(WORD *Attributes, DWORD Colour) const;
    void resetConsoleColour(WORD Attributes) const;
    std::string typeToString(PieceType type) const;

public:
    Game();
    void initGame();
    std::pair<int16_t, int16_t> cast_to_pair(std::string str) const;
    bool validate_var(std::string str) const;
    std::pair<int8_t, int8_t> getInputFromPlayer() const;
    void changeCurrentPlayer();
    void printBoard(const std::shared_ptr<Piece> (&configuration)[BOARD_SIZE][BOARD_SIZE]) const;
};