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

Solution::Answer Solution::get_answer()
{
    string line;
    ifstream data_stream(m_data_file);
    int score = 0;

    while (getline(data_stream, line))
    {
        size_t incomplete_score = 0; // part 2;

        stack<char> m_part1_stack;
        bool line_is_corrupt = false;

        for (size_t i = 0; i < line.length(); i++)
        {
            char cur_char = line[i];
            char cur_char_pair = m_pairs[cur_char];
            if (cur_char == '(' || cur_char == '[' || cur_char == '{' || cur_char == '<')

            {
                m_part1_stack.push(cur_char);
                // printf("adding %c\n", cur_char);
            }
            else
            {
                if (m_part1_stack.top() == cur_char_pair)
                {
                    // printf("popping %c\n", cur_char_pair);
                    m_part1_stack.pop();
                }
                else
                {
                    // cout << line << " | ";
                    // printf("syntax error found! (%c expected, found %c)\n", m_pairs[m_part1_stack.top()], cur_char);
                    score += m_points[cur_char];
                    line_is_corrupt = true;
                    break;
                }
            }
        }

        // handle non-corrupt lines for part 2
        if (!line_is_corrupt)
        {
            if (m_part1_stack.size() > 0)
            {
                // printf("characters left: %i\n", m_part1_stack.size());

                for (size_t i = 0; i < m_part1_stack.size();)
                {
                    printf("%c", m_pairs[m_part1_stack.top()]);
                    incomplete_score = 5 * incomplete_score + m_incomplete_points[m_pairs[m_part1_stack.top()]];
                    // printf("%c", m_part1_stack.top());
                    m_part1_stack.pop();
                }

                m_incomplete_scores.push(incomplete_score);
                printf(" | %llu\n", incomplete_score);
            }
            else
            {
                printf("this line is not incomplete\n");
            }
        }
    }
    m_answer.part1 = score;

    size_t number_incomplete = m_incomplete_scores.size();
    size_t index = (number_incomplete / 2) + 1;
    for (size_t i = 0; i < number_incomplete; i++)
    {
        if (i == index - 1)
        {
            m_answer.part2 = m_incomplete_scores.top();
            return m_answer;
        }
        else
            m_incomplete_scores.pop();
    }
    return m_answer;
}

int main(int argc, char const *argv[])
{
    // string data_file = "day_010_example.txt";
    string data_file = "day_010.txt";
    Solution solution(data_file);

    Solution::Answer answer = solution.get_answer();
    printf("points: %i\n", answer.part1);
    printf("score : %llu\n", answer.part2);

    return 0;
}
