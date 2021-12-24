///////////////////////////////////////////////
/// @file day_010.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/10
/// @version 0.1
/// @date 2021-12-23
///
/// @copyright Copyright (c) 2021
///
///////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include "day_010.h"

int Solution::part1()
{
    string line;
    ifstream data_stream(m_data_file);

    while (getline(data_stream, line))
    {
        for (size_t i = 0; i < line.length(); i++)
        {
            char cur_char = line[i];
            char cur_char_pair = pairs[cur_char];
            if (cur_char == '(' || cur_char == '[' || cur_char == '{' || cur_char == '<')

            {
                openers[cur_char]++;
                printf("openers[%c]: %i\n", cur_char, openers[cur_char]);
            }
            else
            {
                closers[cur_char]++;
                printf("closers[%c]: %i\n", cur_char, closers[cur_char]);
                if (closers[cur_char] > openers[cur_char_pair])
                {
                    cout << cur_char << '\n';
                }
            }
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    string data_file = "day_010_example.txt";
    Solution solution(data_file);

    solution.part1();
    return 0;
}
