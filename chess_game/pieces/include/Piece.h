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

struct Position
{
    int16_t row;
    int16_t column;
};

class Piece
{
public:
    virtual ~Piece() = default;

    PieceType piece_type_;
    PieceColor piece_color_;
    Position piece_position_;

    virtual bool canMove(Position destination, bool configuration_bool[BOARD_SIZE][BOARD_SIZE]) const = 0;

    void setPosition(Position position)
    {
        piece_position_ = position;
    }
};

#endif /* PIECE_H */