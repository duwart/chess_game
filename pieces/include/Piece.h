#ifndef PIECE_H
#define PIECE_H

#include <memory>
#include <string>
#include <utility>

#define BOARD_SIZE 8

enum class PieceColor
{
    BLACK,
    WHITE
};

enum class PieceType
{
    BISHOP,
    KING,
    KNIGHT,
    PAWN,
    QUEEN,
    ROOK
};

class Piece
{
public:
    virtual ~Piece() = default;

    PieceType piece_type_;
    PieceColor color_;
    std::pair<int16_t, int16_t> position_;

    virtual bool canMove(int16_t pos_h, int16_t pos_w, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const = 0;
    void setPosition(int16_t pos_h, int16_t pos_w)
    {
        position_ = std::make_pair(pos_h, pos_w);
    }
};

#endif