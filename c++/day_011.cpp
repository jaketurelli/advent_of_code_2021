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
    for (size_t irow = 0; irow < m_ROWS; irow++)
    {
        for (size_t icol = 0; icol < m_COLS; icol++)
        {
            printf("%2i", m_data[irow][icol]);
        }
        printf("\n");
    }
    printf("\n******\n");
}

void Solution::increase_by_1()
{
    for (size_t irow = 0; irow < m_ROWS; irow++)
    {
        for (size_t icol = 0; icol < m_COLS; icol++)
        {
            m_data[irow][icol]++;
        }
    }
}

bool Solution::resolve_flashes(int row, int col, bool adjacent_flash)
{
    int current_value = m_data[row][col]; //debug only
    if (adjacent_flash && m_data[row][col] != 0xff)
        m_data[row][col] = m_data[row][col] + 1;

    bool flashes_occurred = false;
    if (m_data[row][col] < 10)
        return flashes_occurred;
    else if (m_data[row][col] == 0xff)
    {
        return flashes_occurred;
    }
    else if (m_data[row][col] > 9)
    {
        m_total_flashes++;
        m_data[row][col] = 0xff;
        flashes_occurred = true;

        if (col != m_COLS - 1)
        {
            resolve_flashes(row, col + 1, true);

            if (row != 0)
                resolve_flashes(row - 1, col + 1, true);

            if (row != m_ROWS - 1)
                resolve_flashes(row + 1, col + 1, true);
        }
        if (col != 0)
        {
            resolve_flashes(row, col - 1, true);
            if (row != 0)
                resolve_flashes(row - 1, col - 1, true);

            if (row != m_ROWS - 1)
                resolve_flashes(row + 1, col - 1, true);
        }
        if (row != 0)
            resolve_flashes(row - 1, col, true);

        if (row != m_ROWS - 1)
            resolve_flashes(row + 1, col, true);
    }
}

void Solution::run_flashes()
{
    bool flashes_occurred = false;
    for (size_t irow = 0; irow < m_ROWS; irow++)
        for (size_t icol = 0; icol < m_COLS; icol++)
            resolve_flashes(irow, icol);
}

void Solution::reset_flashes()
{
    for (size_t irow = 0; irow < m_ROWS; irow++)
    {
        for (size_t icol = 0; icol < m_COLS; icol++)
        {
            if (m_data[irow][icol] > 9)
                m_data[irow][icol] = 0;
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
    bool not_done = true;
    size_t step_number = 0;
    while (not_done)
    {
        printf("after step %llu:\n", ++step_number);
        increase_by_1();

        // display_matrix(); //testing

        run_flashes();

        reset_flashes();

        if (step_number == 100)
        {
            display_matrix();
            not_done = false;
            m_answer.part1 = m_total_flashes;
        }
    }
    return m_answer;
}

int main(int argc, char const *argv[])
{
    string file_path = "day_011.txt";
    // string file_path = "day_011_example.txt";
    // string file_path = "day_011_example2.txt";

    Solution solution(file_path);
    printf("part 1: %llu\n", solution.get_answer().part1);
    // printf("part 2: %llu\n", solution.get_answer().part2);
    return 0;
}
