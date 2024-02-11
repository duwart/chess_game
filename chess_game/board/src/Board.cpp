#include "../include/Board.hpp"

Board::Board()
{
    setInitalConfiguration();
}

Board::~Board() {}

void Board::setInitalConfiguration()
{
    for (int16_t board_column = 0; board_column < BOARD_SIZE; board_column++)
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
    }
}

void Board::updateBoard(Position actual_position, Position destination_position)
{
    if (isValidMove(actual_position, destination_position))
    {
        configuration[destination_position.row][destination_position.column] = configuration[actual_position.row][actual_position.column];
        configuration[actual_position.row][actual_position.column] = nullptr;
        configuration[destination_position.row][destination_position.column]->setPosition(destination_position);

        if (hasPieceInPosition(destination_position))
        {
            PieceType current_piece_type = configuration[destination_position.row][destination_position.column]->getPieceType();
            PieceColor current_piece_color = configuration[destination_position.row][destination_position.column]->getPieceColor();
            if (current_piece_type == PieceType::PAWN)
            {
                this->promotePawn(configuration[destination_position.row][destination_position.column]);
            }
            if (current_piece_type == PieceType::KING)
            {
                if (current_piece_color == PieceColor::WHITE)
                {
                    white_king_->setInCheck(false);
                }
                else
                {
                    black_king_->setInCheck(false);
                }
            }
            if (current_piece_color == PieceColor::BLACK)
            {
                if (canMoveToPosition(destination_position, white_king_->getPiecePosition()))
                {
                    white_king_->setInCheck(true);
                    std::cout << "WHITE KING IS IN CHECK!" << std::endl;
                }
            }
            else
            {
                if (canMoveToPosition(destination_position, black_king_->getPiecePosition()))
                {
                    black_king_->setInCheck(true);
                    std::cout << "BLACK KING IS IN CHECK!" << std::endl;
                }
            }
        }
    }
}

bool Board::isValidMove(Position actual_position, Position destination_position)
{
    if (!hasPieceInPosition(actual_position))
        return false;

    auto color_piece = configuration[actual_position.row][actual_position.column]->getPieceColor();
    bool ret = true;

    ret = ret && canMoveToPosition(actual_position, destination_position);

    if (hasPieceInPosition(destination_position))
        ret = ret && configuration[destination_position.row][destination_position.column]->getPieceColor() != configuration[actual_position.row][actual_position.column]->getPieceColor();

    if (configuration[actual_position.row][actual_position.column]->getPieceType() == PieceType::KING)
        ret = ret && this->isKingInCheck(destination_position, color_piece);

    if (white_king_->isInCheck() && !white_king_->getPiecePosition().isEqual(actual_position))
    {
        if (!this->isKingInCheck(destination_position, PieceColor::WHITE))
            return false;
    }

    if (black_king_->isInCheck() == true && !black_king_->getPiecePosition().isEqual(actual_position))
    {
        if (!this->isKingInCheck(destination_position, PieceColor::BLACK))
            return false;
    }
    return ret;
}

bool Board::canMoveToPosition(Position actual_position, Position destination_position)
{
    if (!configuration[actual_position.row][actual_position.column]->canMove(destination_position))
    {
        return false;
    }

    // BUG IN THIS CODE
    // int x = actual_position.row > destination_position.row ? -1 : 1;
    // int y = actual_position.column > destination_position.column ? -1 : 1;
    // short actual_row = actual_position.row;
    // short actual_column = actual_position.column;
    // auto actual_color = configuration[actual_position.row][actual_position.column]->getPieceColor();
    // while (actual_row != destination_position.row)
    // {
    //     while (actual_column != destination_position.column)
    //     {
    //         if (hasPieceInPosition(Position{actual_row, actual_column}))
    //         {
    //             if (configuration[actual_row][actual_column]->getPieceColor() != actual_color)
    //                 return true;
    //             return false;
    //         }
    //         actual_column = actual_column + y;
    //     }
    //     actual_row = actual_row + x;
    // }

    return true;
}

bool Board::isKingInCheck(Position destination_position, PieceColor king_color)
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
                        std::cout << "CHECK!" << std::endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool Board::hasPieceInPosition(Position position)
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
        }
        else if (var == "N")
        {
            configuration[pawn->getPiecePosition().row][pawn->getPiecePosition().column] = std::make_shared<Knight>(pawn->getPieceColor(), pawn->getPiecePosition());
        }
        else if (var == "R")
        {
            configuration[pawn->getPiecePosition().row][pawn->getPiecePosition().column] = std::make_shared<Rook>(pawn->getPieceColor(), pawn->getPiecePosition());
        }
        else
        {
            configuration[pawn->getPiecePosition().row][pawn->getPiecePosition().column] = std::make_shared<Queen>(pawn->getPieceColor(), pawn->getPiecePosition());
        }
    }
}

void Board::printBoard()
{
    WORD Attributes = 0;
    std::cout << std::endl;
    std::cout << "    a  b  c  d  e  f  g  h " << std::endl;
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        std::cout << (8 - row) << " |";
        for (int column = 0; column < BOARD_SIZE; column++)
        {
            if (configuration[row][column])
            {
                if (configuration[row][column]->getPieceColor() == PieceColor::BLACK)
                {
                    setConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
                    std::cout << " " << typeToString(configuration[row][column]->getPieceType()) << " ";
                    resetConsoleColour(Attributes);
                }
                else
                {
                    std::cout << " " << typeToString(configuration[row][column]->getPieceType()) << " ";
                }
            }
            else
            {
                std::cout << " _ ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}

void Board::setConsoleColour(WORD *Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void Board::resetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

std::string Board::typeToString(PieceType type)
{
    switch (type)
    {
    case PieceType::BISHOP:
        return "B";
    case PieceType::KING:
        return "K";
    case PieceType::KNIGHT:
        return "N";
    case PieceType::PAWN:
        return "P";
    case PieceType::QUEEN:
        return "Q";
    case PieceType::ROOK:
        return "R";

    default:
        return "_";
    }
}
