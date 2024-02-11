#pragma once
#include <iostream>  // cin, cout, endl
#include <string>    // getline
#include <windows.h> // bunch of things

#include "../../pieces/include/Bishop.hpp"
#include "../../pieces/include/King.hpp"
#include "../../pieces/include/Knight.hpp"
#include "../../pieces/include/Pawn.hpp"
#include "../../pieces/include/Piece.hpp"
#include "../../pieces/include/Queen.hpp"
#include "../../pieces/include/Rook.hpp"

class Board
{
private:
    std::shared_ptr<Piece> configuration[BOARD_SIZE][BOARD_SIZE];
    std::shared_ptr<King> black_king_;
    std::shared_ptr<King> white_king_;
    bool is_black_king_in_check_ = false;
    bool is_white_king_in_check_ = false;
    void setInitalConfiguration();
    bool hasPieceInPosition(Position position);
    bool isValidMove(Position actual_position, Position destination_position);
    bool canMoveToPosition(Position actual_position, Position destination_position);
    bool isKingInCheck(Position destination_position, PieceColor king_color);
    void promotePawn(std::shared_ptr<Piece> pawn);
    void addPieceToBoard(PieceColor color, PieceType type, Position position_on_board);
    void setConsoleColour(WORD *Attributes, DWORD Colour);
    void resetConsoleColour(WORD Attributes);
    std::string typeToString(PieceType type);

public:
    Board();
    ~Board();

    void printBoard();
    void updateBoard(Position actual_position, Position destination_position);
};
