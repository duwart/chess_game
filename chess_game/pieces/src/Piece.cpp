#include "../include/Piece.hpp"
#include <algorithm>
#include <iostream>

bool Piece::configuration_board[BOARD_SIZE][BOARD_SIZE] = {{false}};

Piece::Piece(PieceColor piece_color, Position piece_position, PieceType piece_type) : piece_color_(piece_color), piece_position_(piece_position), piece_type_(piece_type)
{
    configuration_board[piece_position.row][piece_position.column] = true;
}

void Piece::setPosition(Position position)
{
    configuration_board[piece_position_.row][piece_position_.column] = false;
    configuration_board[position.row][position.column] = true;

    piece_position_ = position;
}

PieceType Piece::getPieceType()
{
    return piece_type_;
}

PieceColor Piece::getPieceColor()
{
    return piece_color_;
}

Position Piece::getPiecePosition()
{
    return piece_position_;
}

void Piece::setColor(PieceColor piece_color)
{
    piece_color_ = piece_color;
}
