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
#include "day_010.h"

#include <fstream>
#include <iostream>
#include <stack>

//todo: need to do more of a push/pop child/parent solution

int Solution::part1()
{
    string line;
    ifstream data_stream(m_data_file);
    int score = 0;

    while (getline(data_stream, line))
    {
        stack<char> m_part1_stack;

        for (size_t i = 0; i < line.length(); i++)
        {
            char cur_char = line[i];
            char cur_char_pair = m_pairs[cur_char];
            if (cur_char == '(' || cur_char == '[' || cur_char == '{' || cur_char == '<')

            {
                // openers[cur_char]++;
                m_part1_stack.push(cur_char);
                // printf("openers[%c]: %i\n", cur_char, openers[cur_char]);
            }
            else
            {
                // closers[cur_char]++;
                if (m_part1_stack.top() == cur_char_pair)
                    m_part1_stack.pop();
                else
                {
                    cout << line << " | ";
                    printf("syntax error found! (%c expected, found %c)\n", m_pairs[m_part1_stack.top()], cur_char);
                    score += m_points[cur_char];
                    break;
                }
            }
        }
    }

    return score;
}

int main(int argc, char const *argv[])
{
    string data_file = "day_010_example.txt";
    Solution solution(data_file);

    int points = solution.part1();
    printf("points: %i\n", points);
    return 0;
}
