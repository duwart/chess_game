#include "../include/Board.hpp"

Board::Board()
{
    setInitalConfiguration();
}

Board::~Board() {}

void Board::setInitalConfiguration()
{
    for (int8_t board_column = 0; board_column < BOARD_SIZE; board_column++)
    {
        addPieceToBoard(PieceColor::WHITE, PieceType::PAWN, Position{6, board_column});
        addPieceToBoard(PieceColor::BLACK, PieceType::PAWN, Position{1, board_column});
    }
    addPieceToBoard(PieceColor::BLACK, PieceType::ROOK, Position{0, 0});
    addPieceToBoard(PieceColor::BLACK, PieceType::ROOK, Position{0, 7});
    addPieceToBoard(PieceColor::BLACK, PieceType::KNIGHT, Position{0, 1});
    addPieceToBoard(PieceColor::BLACK, PieceType::KNIGHT, Position{0, 6});
    addPieceToBoard(PieceColor::BLACK, PieceType::BISHOP, Position{0, 2});
    addPieceToBoard(PieceColor::BLACK, PieceType::BISHOP, Position{0, 5});
    addPieceToBoard(PieceColor::BLACK, PieceType::QUEEN, Position{0, 3});
    addPieceToBoard(PieceColor::BLACK, PieceType::KING, Position{0, 4});

    addPieceToBoard(PieceColor::WHITE, PieceType::ROOK, Position{7, 0});
    addPieceToBoard(PieceColor::WHITE, PieceType::ROOK, Position{7, 7});
    addPieceToBoard(PieceColor::WHITE, PieceType::KNIGHT, Position{7, 1});
    addPieceToBoard(PieceColor::WHITE, PieceType::KNIGHT, Position{7, 6});
    addPieceToBoard(PieceColor::WHITE, PieceType::BISHOP, Position{7, 2});
    addPieceToBoard(PieceColor::WHITE, PieceType::BISHOP, Position{7, 5});
    addPieceToBoard(PieceColor::WHITE, PieceType::QUEEN, Position{7, 3});
    addPieceToBoard(PieceColor::WHITE, PieceType::KING, Position{7, 4});

    // Is this right?
    this->black_king_ = std::shared_ptr<King>((King *)configuration[0][4].get());
    this->white_king_ = std::shared_ptr<King>((King *)configuration[7][4].get());
}

void Board::addPieceToBoard(PieceColor color, PieceType type, Position position_on_board)
{
    switch (type)
    {
    case PieceType::BISHOP:
        configuration[position_on_board.row][position_on_board.column] = std::make_shared<Bishop>(color, position_on_board);
        break;
    case PieceType::KING:
        configuration[position_on_board.row][position_on_board.column] = std::make_shared<King>(color, position_on_board);
        break;
    case PieceType::KNIGHT:
        configuration[position_on_board.row][position_on_board.column] = std::make_shared<Knight>(color, position_on_board);
        break;
    case PieceType::PAWN:
        configuration[position_on_board.row][position_on_board.column] = std::make_shared<Pawn>(color, position_on_board);
        break;
    case PieceType::QUEEN:
        configuration[position_on_board.row][position_on_board.column] = std::make_shared<Queen>(color, position_on_board);
        break;
    case PieceType::ROOK:
        configuration[position_on_board.row][position_on_board.column] = std::make_shared<Rook>(color, position_on_board);
        break;
    default:
        break;
    }
}

bool Board::updateBoard(Position actual_position, Position destination_position, PieceColor current_player)
{
    if (hasPieceInPosition(actual_position))
    {
        if (current_player != configuration[actual_position.row][actual_position.column]->getPieceColor())
        {
            return false;
        }
    }

    if (isValidMove(actual_position, destination_position))
    {
        {
            configuration[destination_position.row][destination_position.column] = std::move(configuration[actual_position.row][actual_position.column]);
            configuration[actual_position.row][actual_position.column] = nullptr;
            configuration[destination_position.row][destination_position.column]->setPosition(destination_position);
            Piece::printConfigurationBoard();
        }

        Position king_position = current_player == PieceColor::WHITE ? white_king_->getPiecePosition() : black_king_->getPiecePosition();
        if (this->isKingInCheck(king_position, current_player))
        {
            {
                configuration[actual_position.row][actual_position.column] = std::move(configuration[destination_position.row][destination_position.column]);
                configuration[destination_position.row][destination_position.column] = nullptr;
                configuration[actual_position.row][actual_position.column]->setPosition(actual_position);
                Piece::printConfigurationBoard();
            }
            return false;
        }

        if (hasPieceInPosition(destination_position))
        {

            PieceType current_piece_type = configuration[destination_position.row][destination_position.column]->getPieceType();
            if (current_piece_type == PieceType::PAWN)
            {
                this->promotePawn(configuration[destination_position.row][destination_position.column]);
            }
        }
        return true;
    }

    return false;
}

bool Board::isValidMove(Position actual_position, Position destination_position) const
{

    if (!hasPieceInPosition(actual_position))
        return false;

    auto color_piece = configuration[actual_position.row][actual_position.column]->getPieceColor();
    bool ret = true;

    ret = ret && canMoveToPosition(actual_position, destination_position);
    if (hasPieceInPosition(destination_position))
        ret = ret && configuration[destination_position.row][destination_position.column]->getPieceColor() != configuration[actual_position.row][actual_position.column]->getPieceColor();
    return ret;
}

bool Board::canMoveToPosition(Position actual_position, Position destination_position) const
{
    return configuration[actual_position.row][actual_position.column]->canMove(destination_position);
}

bool Board::isKingInCheck(Position destination_position, PieceColor king_color) const
{

    Position _pos;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            _pos.row = i;
            _pos.column = j;
            if (hasPieceInPosition(_pos))
            {
                if (configuration[i][j]->getPieceColor() != king_color)
                {
                    if (canMoveToPosition(_pos, destination_position))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Board::hasPieceInPosition(Position position) const
{
    if (configuration[position.row][position.column] == nullptr)
        return false;
    return true;
}

void Board::promotePawn(std::shared_ptr<Piece> pawn)
{

    if ((pawn->getPieceColor() == PieceColor::BLACK && pawn->getPiecePosition().row == 7) || (pawn->getPieceColor() == PieceColor::WHITE && pawn->getPiecePosition().row == 0))
    {
        std::string var = "";
        std::cout << "Promotion! Choose a type (B N Q R): ";
        std::getline(std::cin, var);

        if (var == "B")
        {
            configuration[pawn->getPiecePosition().row][pawn->getPiecePosition().column] = std::make_shared<Bishop>(pawn->getPieceColor(), pawn->getPiecePosition());
            return;
        }

        if (var == "N")
        {
            configuration[pawn->getPiecePosition().row][pawn->getPiecePosition().column] = std::make_shared<Knight>(pawn->getPieceColor(), pawn->getPiecePosition());
            return;
        }

        if (var == "R")
        {
            configuration[pawn->getPiecePosition().row][pawn->getPiecePosition().column] = std::make_shared<Rook>(pawn->getPieceColor(), pawn->getPiecePosition());
            return;
        }

        if (var == "Q")
        {
            configuration[pawn->getPiecePosition().row][pawn->getPiecePosition().column] = std::make_shared<Queen>(pawn->getPieceColor(), pawn->getPiecePosition());
            return;
        }
    }
}

bool Board::isCheckMate(PieceColor current) const
{
    Position pos = current == PieceColor::WHITE ? white_king_->getPiecePosition() : black_king_->getPiecePosition();

    bool ret = true;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (((pos.row + i > 0) && (pos.row + i < BOARD_SIZE)) && ((pos.column + j > 0) && (pos.column + j < BOARD_SIZE)))
            {
                ret = ret && isKingInCheck({int8_t(pos.row + i), int8_t(pos.column + j)}, current);
            }
        }
    }

    return ret;
}