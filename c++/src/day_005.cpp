///////////////////////////////////////////////
/// @file day_005.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/5
/// @version 0.1
/// @date 2021-12-14
///
/// @copyright Copyright (c) 2021
///
///////////////////////////////////////////////
#include "day_005.h"
#include <iostream>
#include <fstream>
int Solution::part1()
{
    int two_line_overlap_locations = 0;
    // Read from the text file
    ifstream data_stream(m_data_file);
    string line;
    while (getline(data_stream, line))
    {
        // Output the text from the file
        // 580,438 -> 580,817
        size_t position_arrow = line.find("->", 0);
        size_t position_comma1 = line.find(",", 0);
        size_t position_comma2 = line.find(",", position_arrow + 1);
        string str_x1 = line.substr(0, position_comma1);
        string str_y1 = line.substr(position_comma1 + 1, position_arrow - (position_comma1 + 1));
        string str_x2 = line.substr(position_arrow + 2, position_comma2 - (position_arrow + 2));
        string str_y2 = line.substr(position_comma2 + 1, line.length() - (position_comma2 + 1));

        // cout << str_x1 << " | " << str_y1 << " | " << str_x2 << " | " << str_y2 << '\n';

        int x1 = stoi(str_x1);
        int y1 = stoi(str_y1);
        int x2 = stoi(str_x2);
        int y2 = stoi(str_y2);

        uint16_t val = 0;
        if (x1 == x2)
        {
            if (y1 < y2)
                for (int i = y1; i <= y2; i++)
                {
                    val = ++m_grid[x1][i];
                    if (val == 2)
                        two_line_overlap_locations++;
                }
            else
                for (int i = y2; i <= y1; i++)
                {
                    val = ++m_grid[x1][i];
                    if (val == 2)
                        two_line_overlap_locations++;
                }
        }
        else if (y1 == y2)
        {
            if (x1 < x2)
                for (int i = x1; i <= x2; i++)
                {
                    val = ++m_grid[i][y1];
                    if (val == 2)
                        two_line_overlap_locations++;
                }
            else
                for (int i = x2; i <= x1; i++)
                {
                    val = ++m_grid[i][y1];
                    if (val == 2)
                        two_line_overlap_locations++;
                }
        }
    }

    return two_line_overlap_locations;
}

int Solution::part2()
{
    int two_line_overlap_locations = 0;
    // Read from the text file
    ifstream data_stream(m_data_file);
    string line;
    while (getline(data_stream, line))
    {
        // Output the text from the file
        // 580,438 -> 580,817
        size_t position_arrow = line.find("->", 0);
        size_t position_comma1 = line.find(",", 0);
        size_t position_comma2 = line.find(",", position_arrow + 1);
        string str_x1 = line.substr(0, position_comma1);
        string str_y1 = line.substr(position_comma1 + 1, position_arrow - (position_comma1 + 1));
        string str_x2 = line.substr(position_arrow + 2, position_comma2 - (position_arrow + 2));
        string str_y2 = line.substr(position_comma2 + 1, line.length() - (position_comma2 + 1));

        // cout << str_x1 << " | " << str_y1 << " | " << str_x2 << " | " << str_y2 << '\n';

        int x1 = stoi(str_x1);
        int y1 = stoi(str_y1);
        int x2 = stoi(str_x2);
        int y2 = stoi(str_y2);
        // printf("%i,%i -> %i,%i\n",x1,y1,x2,y2);

        if (x1 == x2)
        {
            if (y1 < y2)
                for (int i = y1; i <= y2; i++)
                {

                    m_grid[x1][i]++;
                    // printf("          (%i,%i) | %i\n",x1,i, m_grid[x1][i]);
                    if (m_grid[x1][i] == 2)
                    {
                        two_line_overlap_locations++;
                        // printf("(%3i,%3i) (%6i)\n",x1,i,two_line_overlap_locations);
                    }
                }
            else
                for (int i = y2; i <= y1; i++)
                {

                    m_grid[x1][i]++;
                    // printf("          (%i,%i) | %i\n",x1,i, m_grid[x1][i]);
                    if (m_grid[x1][i] == 2)
                    {
                        two_line_overlap_locations++;
                        // printf("(%3i,%3i) (%6i)\n",x1,i,two_line_overlap_locations);
                    }
                }
        }
        else if (y1 == y2)
        {
            if (x1 < x2)
                for (int i = x1; i <= x2; i++)
                {

                    m_grid[i][y1]++;
                    // printf("          (%i,%i) | %i\n",i,y1,m_grid[i][y1] );
                    if (m_grid[i][y1] == 2)
                    {
                        two_line_overlap_locations++;
                        // printf("(%3i,%3i) (%6i)\n",i,y1,two_line_overlap_locations);
                    }
                }
            else
                for (int i = x2; i <= x1; i++)
                {

                    m_grid[i][y1]++;
                    // printf("          (%i,%i) | %i\n",i,y1,m_grid[i][y1]);
                    if (m_grid[i][y1] == 2)
                    {
                        two_line_overlap_locations++;
                        // printf("(%3i,%3i) (%6i)\n",i,y1,two_line_overlap_locations);
                    }
                }
        }
        else
        {
            // continue;
            int delta_x = -1;
            if (x1 < x2)
                delta_x = 1;
            int delta_y = -1;
            if (y1 < y2)
                delta_y = 1;

            int cur_x = x1;
            int cur_y = y1;
            while (cur_x != (x2 + delta_x))
            {
                m_grid[cur_x][cur_y]++;
                // printf("          (%i,%i) | %i\n",cur_x,cur_y, m_grid[cur_x][cur_y]);
                if (m_grid[cur_x][cur_y] == 2)
                {

                    two_line_overlap_locations++;
                    // printf("(%3i,%3i) (%6i)\n",cur_x,cur_y,two_line_overlap_locations);
                }
                cur_x += delta_x;
                cur_y += delta_y;
            }
        }
    }
    // for (size_t i = 0; i < 10; i++)
    // {
    //     for (size_t j = 0; j < 10; j++)
    //     {
    //         if(m_grid[j][i]==0)
    //             printf(".");
    //         else
    //             printf("%i", m_grid[j][i]);
    //     }
    //     printf("\n");

    // }

    return two_line_overlap_locations;
}

int main(int argc, const char **argv)
{
    string file_path = "../../data/day_005.txt";
    // string file_path = "day_005_example.txt";
    Solution solution(file_path);
    // int two_line_overlap_locations = solution.part1();
    // printf("two_line_overlap_locations: %i\n",two_line_overlap_locations);
    int two_line_overlap_locations_diagonals = solution.part2();
    printf("two_line_overlap_locations_diagonals: %i\n", two_line_overlap_locations_diagonals);
    return 0;
}