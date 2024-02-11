#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include "board/include/Board.hpp"
#include <sstream>

std::pair<int16_t, int16_t> cast_to_pair(std::string str)
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

bool validate_var(std::string str)
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

int main()
{
    Board board;

    bool flag = true;
    std::string var = "";

    while (flag)
    {
        // system("cls");
        board.printBoard();
        std::cout << "Choose a piece (/q to quit):  ";
        std::getline(std::cin, var);
        std::cout << var << std::endl;

        if (var == "/q")
        {
            return 1;
        }

        while (!validate_var(var))
        {
            std::cout << "Wrong input, try again...  " << std::endl;
            std::cout << "Choose a piece (/q to quit):  ";
            std::getline(std::cin, var);
            std::cout << var << std::endl;
            if (var == "/q")
            {
                return 1;
            }
        }

        auto old_pos = cast_to_pair(var);

        std::cout << "Move to:  ";
        std::getline(std::cin, var);
        std::cout << var << std::endl;

        while (!validate_var(var))
        {
            std::cout << "Wrong input, try again...  " << std::endl;
            std::cout << "Move to:  ";
            std::getline(std::cin, var);
            std::cout << var << std::endl;
            if (var == "/q")
            {
                return 1;
            }
        }

        auto new_pos = cast_to_pair(var);
        Position pos_old = Position{old_pos.first, old_pos.second};
        Position pos_new = Position{new_pos.first, new_pos.second};
        board.updateBoard(pos_old, pos_new);
    }

    return 0;
}