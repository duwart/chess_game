#pragma once

#include <iostream>
#include <string>
#include <windows.h>

#include "../../pieces/include/Bishop.hpp"
#include "../../pieces/include/King.hpp"
#include "../../pieces/include/Knight.hpp"
#include "../../pieces/include/Pawn.hpp"
#include "../../pieces/include/Piece.hpp"
#include "../../pieces/include/Queen.hpp"
#include "../../pieces/include/Rook.hpp"

class Board final
{
private:
    std::shared_ptr<King> black_king_;
    std::shared_ptr<King> white_king_;
    void setInitalConfiguration();
    bool hasPieceInPosition(Position position) const;
    bool isValidMove(Position actual_position, Position destination_position) const;
    bool canMoveToPosition(Position actual_position, Position destination_position) const;
    bool isKingInCheck(Position destination_position, PieceColor king_color) const;
    void promotePawn(std::shared_ptr<Piece> pawn);
    void addPieceToBoard(PieceColor color, PieceType type, Position position_on_board);

public:
    Board();
    ~Board();

    bool isCheckMate(PieceColor current) const;
    bool updateBoard(Position actual_position, Position destination_position, PieceColor current_player);
    std::shared_ptr<Piece> configuration[BOARD_SIZE][BOARD_SIZE];
};
