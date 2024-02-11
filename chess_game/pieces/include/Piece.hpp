#pragma once
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
    bool isEqual(Position pos)
    {
        return (row == pos.row) && (column == pos.column);
    }
};

class Piece
{
protected:
    PieceType piece_type_;
    PieceColor piece_color_;
    Position piece_position_;
    static bool configuration_board[BOARD_SIZE][BOARD_SIZE];

    void setColor(PieceColor piece_color);

public:
    Piece(PieceColor piece_color, Position piece_position, PieceType piece_type);
    virtual ~Piece() = default;

    virtual bool canMove(Position destination) const = 0;
    PieceType getPieceType();
    PieceColor getPieceColor();
    Position getPiecePosition();
    void setPosition(Position position);
};
