#include "../include/GameUI.hpp"

std::ostream &operator<<(std::ostream &cout, const PieceType &piece_type)
{
    switch (piece_type)
    {
    case PieceType::BISHOP:
        cout << "B";
        break;
    case PieceType::KING:
        cout << "K";
        break;
    case PieceType::KNIGHT:
        cout << "N";
        break;
    case PieceType::PAWN:
        cout << "P";
        break;
    case PieceType::QUEEN:
        cout << "Q";
        break;
    case PieceType::ROOK:
        cout << "R";
        break;
    default:
        cout << "_";
        break;
    }
    return cout;
}

Game::Game()
{
    current_player_ = PieceColor::WHITE;
}

void Game::initGame()
{
    Board board;
    bool flag = true;
    std::string player_color;

    while (!board.isCheckMate(current_player_))
    {
        // system("cls");
        player_color = current_player_ == PieceColor::WHITE ? "WHITE" : "BLACK";
        std::cout << std::endl
                  << "--------------------------------------" << std::endl;
        std::cout << player_color << " TURN" << std::endl;
        std::cout << "--------------------------------------" << std::endl
                  << std::endl;
        printBoard(board.configuration);

        auto old_pos = getInputFromPlayer();

        auto new_pos = getInputFromPlayer();

        Position pos_old = Position{old_pos.first, old_pos.second};
        Position pos_new = Position{new_pos.first, new_pos.second};
        if (board.updateBoard(pos_old, pos_new, current_player_))
        {
            changeCurrentPlayer();
        }
    }
    std::cout << "WINNER: " << player_color << std::endl;
}

void Game::changeCurrentPlayer()
{
    current_player_ = current_player_ == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;
}

std::pair<int16_t, int16_t> Game::cast_to_pair(std::string str) const
{
    std::map<std::string, int16_t> map_str_int{{"a", 0}, {"b", 1}, {"c", 2}, {"d", 3}, {"e", 4}, {"f", 5}, {"g", 6}, {"h", 7}, {"8", 0}, {"7", 1}, {"6", 2}, {"5", 3}, {"4", 4}, {"3", 5}, {"2", 6}, {"1", 7}};

    std::string s;

    std::stringstream ss(str);

    std::vector<std::string> v;

    while (std::getline(ss, s, ' '))
    {
        v.push_back(s);
    }
    return std::make_pair(map_str_int.at(v[1]), map_str_int.at(v[0]));
}

bool Game::validate_var(std::string str) const
{
    std::set<std::string> vec_col{"a", "b", "c", "d", "e", "f", "g", "h"};
    std::set<std::string> vec_lin{"1", "2", "3", "4", "5", "6", "7", "8"};

    std::string s;

    bool ret = false;

    std::stringstream ss(str);

    std::vector<std::string> v;

    while (std::getline(ss, s, ' '))
    {
        v.push_back(s);
    }

    if (v.size() < 2)
    {
        return false;
    }
    std::for_each(vec_col.begin(), vec_col.end(), [v, &ret](auto v_aux)
                  { ret = ret || (v[0] == v_aux); });
    if (!ret)
    {
        return ret;
    }
    ret = false;
    std::for_each(vec_lin.begin(), vec_lin.end(), [v, &ret](auto v_aux)
                  { ret = ret || (v[1] == v_aux); });

    return ret;
}

std::pair<int8_t, int8_t> Game::getInputFromPlayer() const
{
    std::string var = "";

    do
    {
        std::cout << "Choose a piece (/q to quit):  ";
        std::getline(std::cin, var);
        std::cout << var << std::endl;
        if (var == "q")
        {
            exit(0);
        }
    } while (!validate_var(var));

    return cast_to_pair(var);
}

void Game::printBoard(const std::shared_ptr<Piece> (&configuration)[BOARD_SIZE][BOARD_SIZE]) const
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
                    std::cout << " " << configuration[row][column]->getPieceType() << " ";
                    resetConsoleColour(Attributes);
                }
                else
                {
                    std::cout << " " << configuration[row][column]->getPieceType() << " ";
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

void Game::setConsoleColour(WORD *Attributes, DWORD Colour) const
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void Game::resetConsoleColour(WORD Attributes) const
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}
