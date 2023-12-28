#ifndef PIECE_H
#define PIECE_H

#include <utility> // make_pair, pair

const int BOARD_SIZE = 8;

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
    PieceColor piece_color_;
    std::pair<int16_t, int16_t> piece_position_;

    virtual bool canMove(int16_t pos_row, int16_t pos_column, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const = 0;
    void setPosition(int16_t pos_row, int16_t pos_column)
    {
        piece_position_ = std::make_pair(pos_row, pos_column);
    }
};

#endif /* PIECE_H */