///////////////////////////////////////////////
/// @file day_011.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/11
/// @version 0.1
/// @date 2021-12-26
///
/// @copyright Copyright (c) 2021
///
///////////////////////////////////////////////

#include "day_011.h"
#include <fstream>
#include <iostream>

void Solution::display_matrix()
{
    printf("after step %i:\n", m_step);
    for (size_t irow = 0; irow < m_ROWS; irow++)
    {
        for (size_t icol = 0; icol < m_COLS; icol++)
        {
            printf("%i", m_data[irow][icol]);
        }
        printf("\n");
    }
    printf("\n******\n");
}

bool Solution::increase_by_1()
{
    for (size_t irow = 0; irow < m_ROWS; irow++)
    {
        for (size_t icol = 0; icol < m_COLS; icol++)
        {
            m_data[irow][icol]++;
        }
    }
    return true;
}

bool Solution::increment_and_check_adjacents(int row, int col, bool increment_first)
{
    bool flash_occurred = false;
    if (increment_first)
        m_data[row][col]++;

    if (m_data[row][col] == 10)
    {
        flash_occurred = true;

        if (col != m_COLS)
        {
            flash_occurred |= increment_and_check_adjacents(row, col + 1, true);

            if (row != 0)
                flash_occurred |= increment_and_check_adjacents(row - 1, col + 1, true);

            if (row != m_ROWS)
                flash_occurred |= increment_and_check_adjacents(row + 1, col + 1, true);
        }
        if (col != 0)
        {
            flash_occurred |= increment_and_check_adjacents(row, col - 1, true);
            if (row != 0)
                flash_occurred |= increment_and_check_adjacents(row - 1, col - 1, true);

            if (row != m_ROWS)
                flash_occurred |= increment_and_check_adjacents(row + 1, col - 1, true);
        }
        if (row != 0)
            flash_occurred |= increment_and_check_adjacents(row - 1, col, true);

        if (row != m_ROWS)
            flash_occurred |= increment_and_check_adjacents(row + 1, col, true);
    }
    // display_matrix(); // testing
    return flash_occurred;
}

void Solution::check_flashes()
{
    bool flash_occurred = true;

    while (flash_occurred)
    {
        flash_occurred = false;
        for (size_t irow = 0; irow < m_ROWS; irow++)
        {
            for (size_t icol = 0; icol < m_COLS; icol++)
            {
                flash_occurred = increment_and_check_adjacents(irow, icol, false);
            }
        }
    }

    // reset to 0 if a flash occurred
    for (size_t irow = 0; irow < m_ROWS; irow++)
    {
        for (size_t icol = 0; icol < m_COLS; icol++)
        {
            if (m_data[irow][icol] > 9)
            {
                m_data[irow][icol] = 0;
            }
        }
    }
}

Solution::Answer Solution::get_answer()
{
    string line;
    ifstream data_stream(m_data_file);
    int current_line_number = 0;
    while (getline(data_stream, line))
    {
        for (size_t i = 0; i < m_COLS; i++)
        {
            m_data[current_line_number][i] = line[i] - '0';
        }
        current_line_number++;
    }
    display_matrix();

    while (true)
    {
        m_step++;
        increase_by_1();

        check_flashes();

        display_matrix();

        getchar();
    }
    return m_answer;
}

int main(int argc, char const *argv[])
{
    // string file_path = "day_011.txt";
    string file_path = "day_011_example.txt";
    Solution solution(file_path);
    printf("part 1: %llu\n", solution.get_answer().part1);
    // printf("part 2: %llu\n", solution.get_answer().part2);
    return 0;
}
