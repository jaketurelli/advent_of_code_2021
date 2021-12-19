///////////////////////////////////////////////
/// @file day_009.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/9
/// @version 0.1
/// @date 2021-12-17
/// 
/// @copyright Copyright (c) 2021
/// 
///////////////////////////////////////////////
#include "day_009.h"
#include <fstream>
#include <iostream>


void Solution::fill_array(string& line, uint8_t array[], size_t size_of_array)
{
    for (size_t i = 0; i < size_of_array; i++)
    {
        array[i] = line[i] - '0';
    }
}

void Solution::add_low_point(uint8_t value, int row, int col)
{
    m_low_points.push_back(value);
    printf("low point: %1i (%3i,%3i)\n", value, row, col);
}

size_t Solution::parse_and_analyze()
{
    string line_previous;
    string line_current;
    string line_next;
    ifstream data_stream(m_data_file);
    int line_number = 0;
    

    // determine number of digits per line
    
    getline(data_stream, line_previous);
    const int N_DATA = line_previous.length();

    uint8_t data_previous[N_DATA] = {0};
    uint8_t data_current[N_DATA] = {0};
    uint8_t data_next[N_DATA] = {0};

    uint8_t* data_previous_p[N_DATA] = {0};
    uint8_t* data_current_p[N_DATA] = {0};
    uint8_t* data_next_p[N_DATA] = {0};

    fill_array(line_previous,data_previous,N_DATA);
    fill_array(line_current, data_current,N_DATA);

    int current_line_number = 0;

    // somethign different for first line
    for (size_t i = 0; i < N_DATA; i++)
    {
        if( i==0 && 
            data_previous[i] < data_previous[i+1] &&
            data_previous[i] < data_current[i] )
        {
            add_low_point(data_previous[i], current_line_number, i);
        }

        else if( i==(N_DATA-1) && 
                    data_previous[i] < data_previous[i-1] &&
                    data_previous[i] < data_current[i])
        {
            add_low_point(data_previous[i], current_line_number, i);
        }

        else if( data_previous[i] < data_previous[i+1] && 
                 data_previous[i] < data_previous[i-1] && 
                 data_previous[i] < data_current[i])
        {
            add_low_point(data_previous[i], current_line_number, i);
        }

        
    }
    
    while(getline(data_stream, line_next))
    {
        current_line_number++;
        fill_array(line_next,data_next,N_DATA);

        for (size_t i = 0; i < N_DATA; i++)
        {
            if( i==0 && 
                data_current[i] < data_current[i+1] &&
                data_current[i] < data_next[i] && 
                data_current[i] < data_previous[i])
            {
                add_low_point(data_current[i], current_line_number, i);
            }

            else if( i==(N_DATA-1) && 
                     data_current[i] < data_current[i-1] &&
                     data_current[i] < data_next[i] && 
                     data_current[i] < data_previous[i])
            {
                add_low_point(data_current[i], current_line_number, i);
            }

            else if( data_current[i] < data_current[i+1] && 
                     data_current[i] < data_current[i-1] && 
                     data_current[i] < data_next[i] && 
                     data_current[i] < data_previous[i])
            {
                add_low_point(data_current[i], current_line_number, i);
            }

            
        }
        data_previous_p = data_current_p;
        data_current_p = data_next_p;
    }

    // somethign different for first line
    for (size_t i = 0; i < N_DATA; i++)
    {
        if( i==0 && 
            data_next[i] < data_next[i+1] &&
            data_next[i] < data_current[i] )
        {
            add_low_point(data_next[i], current_line_number, i);
        }

        else if( i==(N_DATA-1) && 
                    data_next[i] < data_next[i-1] &&
                    data_next[i] < data_current[i])
        {
            add_low_point(data_next[i], current_line_number, i);
        }

        else if( data_next[i] < data_next[i+1] && 
                 data_next[i] < data_next[i-1] && 
                 data_next[i] < data_current[i])
        {
            add_low_point(data_next[i], current_line_number, i);
        }

        
    }

    // for (size_t i = 0; i < N_DATA; i++)
    // {
    //     printf("%i",line_0[i]);
    // }
    // printf("\n");
    return 0;
    
}

size_t Solution::solve()
{
    return parse_and_analyze();
}

int main(int argc, char const *argv[])
{
    string data_file = "day_009_example.txt";
    Solution solution(data_file);
    printf("part1: %llu\n", solution.solve());
    return 0;
}
