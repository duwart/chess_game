#pragma once

#include <iostream>
#include <utility>

#include "PieceColor.hpp"
#include "PieceType.hpp"
#include "Position.hpp"

const int BOARD_SIZE = 8;

class Piece
{
protected:
    PieceType piece_type_;
    PieceColor piece_color_;
    Position piece_position_;
    static bool configuration_board[BOARD_SIZE][BOARD_SIZE];

    void setColor(PieceColor piece_color);

public:
    static void printConfigurationBoard(); // for debug purpose
    Piece(PieceColor piece_color, Position piece_position, PieceType piece_type);
    virtual ~Piece();
    void setPosition(Position position);
    virtual bool canMove(Position destination) const = 0;
    PieceType getPieceType() const;
    PieceColor getPieceColor() const;
    Position getPiecePosition() const;
    friend std::ostream &operator<<(std::ostream &cout, const Piece &piece);
};
