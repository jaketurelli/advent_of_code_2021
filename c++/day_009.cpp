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


void Solution::fill_array(string& line, uint8_t* array, size_t size_of_array)
{
    for (size_t i = 0; i < size_of_array; i++)
    {
        array[i] = line[i] - '0';
    }
}

void Solution::add_low_point(uint8_t value, int row, int col)
{
    m_low_points.push_back(value);
    // printf("low point: %1i (%3i,%3i)\n", value, row, col);
}

size_t Solution::parse_and_analyze()
{
    string line_previous;
    string line_current;
    string line_next;
    ifstream data_stream(m_data_file);
    int line_number = 0;
    

    // determine number of digits per line
    
    getline(data_stream, line_current);
    const int N_DATA = line_current.length();
    // printf("N_DATA: %i\n", N_DATA);

    uint8_t data_0[N_DATA] = {0};
    uint8_t data_1[N_DATA] = {0};
    uint8_t data_2[N_DATA] = {0};

    uint8_t* const pointer_bookie[3] = { &data_0[0],
                                         &data_1[0],
                                         &data_2[0]};

    uint8_t* data_previous_p = nullptr;
    uint8_t* data_current_p  = pointer_bookie[0];
    uint8_t* data_next_p =     pointer_bookie[1];

    fill_array(line_current, data_current_p,N_DATA);
    getline(data_stream, line_next);
    fill_array(line_next, data_next_p,N_DATA);

    int current_line_number = 0;

    // somethign different for first line
    for (size_t i = 0; i < N_DATA; i++)
    {
        // printf("%i ", data_current_p[i]);
        if( i==0 && 
            data_current_p[i] < data_current_p[i+1] &&
            data_current_p[i] < data_next_p[i] )
        {
            add_low_point(data_current_p[i], current_line_number, i);
        }

        else if( i==(N_DATA-1) && 
                    data_current_p[i] < data_current_p[i-1] &&
                    data_current_p[i] < data_next_p[i])
        {
            add_low_point(data_current_p[i], current_line_number, i);
        }

        else if( data_current_p[i] < data_current_p[i+1] && 
                 data_current_p[i] < data_current_p[i-1] && 
                 data_current_p[i] < data_next_p[i])
        {
            add_low_point(data_current_p[i], current_line_number, i);
        }

        
    }
    // printf("\n");

    current_line_number++;
    while(getline(data_stream, line_next))
    {
        
        data_previous_p = pointer_bookie[(current_line_number-1)%3];
        data_current_p  = pointer_bookie[current_line_number%3];
        data_next_p     = pointer_bookie[(current_line_number+1)%3];


        fill_array(line_next,data_next_p,N_DATA);
        

        for (size_t i = 0; i < N_DATA; i++)
        {
            // printf("%i ", data_current_p[i]);
            if( i==0 )
            {
                // printf("%i vs (%i, %i, %i) ", data_current_p[i], data_current_p[i+1], data_next_p[i], data_previous_p[i]);
                if( data_current_p[i] < data_current_p[i+1] &&
                    data_current_p[i] < data_next_p[i] && 
                    data_current_p[i] < data_previous_p[i])
                {
                    add_low_point(data_current_p[i], current_line_number, i);
                }
            }
            else if( i==(N_DATA-1))
            {
                // printf("%i vs (%i, %i, %i) ", data_current_p[i], data_current_p[i-1], data_next_p[i], data_previous_p[i]);
                if(  data_current_p[i] < data_current_p[i-1] &&
                     data_current_p[i] < data_next_p[i] && 
                     data_current_p[i] < data_previous_p[i])
                {

                    add_low_point(data_current_p[i], current_line_number, i);
                }
            }

            else 
            {
                // printf("%i ", data_current_p[i]);
                // printf("%i vs (%i, %i, %i, %i) ", data_current_p[i], data_current_p[i+1], data_current_p[i-1], data_next_p[i], data_previous_p[i]);
                if( data_current_p[i] < data_current_p[i+1] && 
                     data_current_p[i] < data_current_p[i-1] && 
                     data_current_p[i] < data_next_p[i] && 
                     data_current_p[i] < data_previous_p[i])
                {
                    add_low_point(data_current_p[i], current_line_number, i);
                }
            }
            
        }
        
        current_line_number++;
        // printf("\n");
    }

    data_previous_p = pointer_bookie[(current_line_number-1)%3];
    data_current_p  = pointer_bookie[current_line_number%3];

    // somethign different for first line
    for (size_t i = 0; i < N_DATA; i++)
    {
        // printf("%i ", data_current_p[i]);
        if( i==0 && 
            data_current_p[i] < data_current_p[i+1] &&
            data_current_p[i] < data_previous_p[i] )
        {
            add_low_point(data_current_p[i], current_line_number, i);
        }

        else if( i==(N_DATA-1) && 
                    data_current_p[i] < data_current_p[i-1] &&
                    data_current_p[i] < data_previous_p[i])
        {
            add_low_point(data_current_p[i], current_line_number, i);
        }

        else if( data_current_p[i] < data_current_p[i+1] && 
                 data_current_p[i] < data_current_p[i-1] && 
                 data_current_p[i] < data_previous_p[i])
        {
            add_low_point(data_current_p[i], current_line_number, i);
        }

        
    }
    // printf("\n");

    printf("Low points: \n");
    int risk_level_total = 0;
    for (auto i = m_low_points.begin(); i != m_low_points.end(); i++)
    {
        risk_level_total += *i+1;
        printf("%i ",*i);
    }
    printf("\n");
    return risk_level_total;
    
}

size_t Solution::solve()
{
    return parse_and_analyze();
}

int main(int argc, char const *argv[])
{
    // string data_file = "day_009_example.txt";
    string data_file = "day_009.txt";
    Solution solution(data_file);
    printf("part1: %llu\n", solution.solve());
    return 0;
}
