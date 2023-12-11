#include "../include/Board.h"

Board::Board()
{
    initalConfiguration();
}

Board::~Board() {}

void Board::initalConfiguration()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            configuration_bool[i][j] = false;
            if (i < 2)
            {
                if (i == 0)
                {
                    if (j == 0 || j == 7)
                    {
                        configuration[i][j] = std::make_shared<Rook>(PieceColor::BLACK, i, j);
                        configuration_bool[i][j] = true;
                    }

                    if (j == 1 || j == 6)
                    {
                        configuration[i][j] = std::make_shared<Knight>(PieceColor::BLACK, i, j);
                        configuration_bool[i][j] = true;
                    }

                    if (j == 2 || j == 5)
                    {
                        configuration[i][j] = std::make_shared<Bishop>(PieceColor::BLACK, i, j);
                        configuration_bool[i][j] = true;
                    }

                    if (j == 3)
                    {
                        configuration[i][j] = std::make_shared<Queen>(PieceColor::BLACK, i, j);
                        configuration_bool[i][j] = true;
                    }
                    if (j == 4)
                    {
                        configuration[i][j] = std::make_shared<King>(PieceColor::BLACK, i, j);
                        configuration_bool[i][j] = true;
                    }
                }
                if (i == 1)
                {
                    configuration[i][j] = std::make_shared<Pawn>(PieceColor::BLACK, i, j);
                    configuration_bool[i][j] = true;
                }
            }
            if (i > 5)
            {
                if (i == 7)
                {
                    if (j == 0 || j == 7)
                    {
                        configuration[i][j] = std::make_shared<Rook>(PieceColor::WHITE, i, j);
                        configuration_bool[i][j] = true;
                    }

                    if (j == 1 || j == 6)
                    {
                        configuration[i][j] = std::make_shared<Knight>(PieceColor::WHITE, i, j);
                        configuration_bool[i][j] = true;
                    }
                    if (j == 2 || j == 5)
                    {
                        configuration[i][j] = std::make_shared<Bishop>(PieceColor::WHITE, i, j);
                        configuration_bool[i][j] = true;
                    }

                    if (j == 3)
                    {
                        configuration[i][j] = std::make_shared<Queen>(PieceColor::WHITE, i, j);
                        configuration_bool[i][j] = true;
                    }

                    if (j == 4)
                    {
                        configuration[i][j] = std::make_shared<King>(PieceColor::WHITE, i, j);
                        configuration_bool[i][j] = true;
                    }
                }
                if (i == 6)
                {
                    configuration[i][j] = std::make_shared<Pawn>(PieceColor::WHITE, i, j);
                    configuration_bool[i][j] = true;
                }
            }
        }
    }
}

void Board::updateBoard(std::pair<int16_t, int16_t> old_, std::pair<int16_t, int16_t> new_)
{
    if (configuration[old_.first][old_.second] && configuration[old_.first][old_.second]->canMove(new_.first, new_.second, configuration_bool))
    {
        if (configuration[new_.first][new_.second])
        {
            if (configuration[new_.first][new_.second]->color_ != configuration[old_.first][old_.second]->color_)
            {
                configuration[new_.first][new_.second] = configuration[old_.first][old_.second];
                configuration[old_.first][old_.second] = nullptr;
                configuration[new_.first][new_.second]->setPosition(new_.first, new_.second);
                configuration_bool[new_.first][new_.second] = true;
                configuration_bool[old_.first][old_.second] = false;
            }
        }
        else
        {
            configuration[new_.first][new_.second] = configuration[old_.first][old_.second];
            configuration[old_.first][old_.second] = nullptr;
            configuration[new_.first][new_.second]->setPosition(new_.first, new_.second);
            configuration_bool[new_.first][new_.second] = true;
            configuration_bool[old_.first][old_.second] = false;
        }
    }
}

void Board::SetConsoleColour(WORD *Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void Board::ResetConsoleColour(WORD Attributes)
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
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        std::cout << (8 - i) << " |";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (configuration[i][j])
            {
                if (configuration[i][j]->color_ == PieceColor::BLACK)
                {
                    SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
                    std::cout << " " << typeToString(configuration[i][j]->piece_type_) << " ";
                    ResetConsoleColour(Attributes);
                }
                else
                {
                    std::cout << " " << typeToString(configuration[i][j]->piece_type_) << " ";
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
