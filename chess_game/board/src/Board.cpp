#include "../include/Board.h"

Board::Board()
{
    setInitalConfiguration();
}

Board::~Board() {}

void Board::setInitalConfiguration()
{
    for (int board_row = 0; board_row < BOARD_SIZE; board_row++)
    {
        for (int board_column = 0; board_column < BOARD_SIZE; board_column++)
        {
            if (board_row == 0)
            {
                if (board_column == 0 || board_column == 7)
                {
                    configuration[board_row][board_column] = std::make_shared<Rook>(PieceColor::BLACK, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }

                if (board_column == 1 || board_column == 6)
                {
                    configuration[board_row][board_column] = std::make_shared<Knight>(PieceColor::BLACK, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }

                if (board_column == 2 || board_column == 5)
                {
                    configuration[board_row][board_column] = std::make_shared<Bishop>(PieceColor::BLACK, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }

                if (board_column == 3)
                {
                    configuration[board_row][board_column] = std::make_shared<Queen>(PieceColor::BLACK, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }
                if (board_column == 4)
                {
                    configuration[board_row][board_column] = std::make_shared<King>(PieceColor::BLACK, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }
            }
            if (board_row == 1)
            {
                configuration[board_row][board_column] = std::make_shared<Pawn>(PieceColor::BLACK, board_row, board_column);
                configuration_bool[board_row][board_column] = true;
            }

            if (board_row == 7)
            {
                if (board_column == 0 || board_column == 7)
                {
                    configuration[board_row][board_column] = std::make_shared<Rook>(PieceColor::WHITE, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }

                if (board_column == 1 || board_column == 6)
                {
                    configuration[board_row][board_column] = std::make_shared<Knight>(PieceColor::WHITE, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }
                if (board_column == 2 || board_column == 5)
                {
                    configuration[board_row][board_column] = std::make_shared<Bishop>(PieceColor::WHITE, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }

                if (board_column == 3)
                {
                    configuration[board_row][board_column] = std::make_shared<Queen>(PieceColor::WHITE, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }

                if (board_column == 4)
                {
                    configuration[board_row][board_column] = std::make_shared<King>(PieceColor::WHITE, board_row, board_column);
                    configuration_bool[board_row][board_column] = true;
                }
            }
            if (board_row == 6)
            {
                configuration[board_row][board_column] = std::make_shared<Pawn>(PieceColor::WHITE, board_row, board_column);
                configuration_bool[board_row][board_column] = true;
            }
        }
    }
}

bool Board::isValidMove(std::pair<int16_t, int16_t> actual_position, std::pair<int16_t, int16_t> destination_position)
{
    bool ret = true;
    if (configuration_bool[actual_position.first][actual_position.second])
    {
        ret = ret && configuration[actual_position.first][actual_position.second]->canMove(destination_position.first, destination_position.second, configuration_bool);
    }

    if (configuration_bool[destination_position.first][destination_position.second])
    {
        ret = ret && configuration[destination_position.first][destination_position.second]->piece_color_ != configuration[actual_position.first][actual_position.second]->piece_color_;
    }

    return ret;
}

void Board::promotePawn(std::shared_ptr<Piece> pawn)
{

    if ((pawn->piece_color_ == PieceColor::BLACK && pawn->piece_position_.first == 7) || (pawn->piece_color_ == PieceColor::WHITE && pawn->piece_position_.first == 0))
    {
        std::string var = "";
        std::cout << "Promotion! Choose a type (B N Q R): ";
        std::getline(std::cin, var);

        if (var == "B")
        {
            configuration[pawn->piece_position_.first][pawn->piece_position_.second] = std::make_shared<Bishop>(pawn->piece_color_, pawn->piece_position_.first, pawn->piece_position_.second);
        }
        else if (var == "N")
        {
            configuration[pawn->piece_position_.first][pawn->piece_position_.second] = std::make_shared<Knight>(pawn->piece_color_, pawn->piece_position_.first, pawn->piece_position_.second);
        }
        else if (var == "R")
        {
            configuration[pawn->piece_position_.first][pawn->piece_position_.second] = std::make_shared<Rook>(pawn->piece_color_, pawn->piece_position_.first, pawn->piece_position_.second);
        }
        else
        {
            configuration[pawn->piece_position_.first][pawn->piece_position_.second] = std::make_shared<Queen>(pawn->piece_color_, pawn->piece_position_.first, pawn->piece_position_.second);
        }
    }
}

void Board::updateBoard(std::pair<int16_t, int16_t> actual_position, std::pair<int16_t, int16_t> destination_position)
{
    if (isValidMove(actual_position, destination_position))
    {

        configuration[destination_position.first][destination_position.second] = configuration[actual_position.first][actual_position.second];
        configuration[actual_position.first][actual_position.second] = nullptr;
        configuration[destination_position.first][destination_position.second]->setPosition(destination_position.first, destination_position.second);
        configuration_bool[destination_position.first][destination_position.second] = true;
        configuration_bool[actual_position.first][actual_position.second] = false;

        if (configuration_bool[destination_position.first][destination_position.second])
        {
            if (configuration[destination_position.first][destination_position.second]->piece_type_ == PieceType::PAWN)
            {
                this->promotePawn(configuration[destination_position.first][destination_position.second]);
            }
        }
    }
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
                if (configuration[row][column]->piece_color_ == PieceColor::BLACK)
                {
                    setConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
                    std::cout << " " << typeToString(configuration[row][column]->piece_type_) << " ";
                    resetConsoleColour(Attributes);
                }
                else
                {
                    std::cout << " " << typeToString(configuration[row][column]->piece_type_) << " ";
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
