///////////////////////////////////////////////
/// @file day_007.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/7
/// @version 0.1
/// @date 2021-12-16
/// 
/// @copyright Copyright (c) 2021
/// 
///////////////////////////////////////////////

#include "day_007.h"
#include <iostream>
#include <fstream>
#include <vector>

size_t Solution::parse_and_anaylize()
{
    // Create a text string, which is used to output the text file
    string line;

    // Read from the text file
    ifstream data_stream(m_data_file);

    size_t line_number = 0;
    size_t count = 0;
    int min_value = MAX_VALUE;
    int max_value = 0;

    while (getline (data_stream, line)) 
    {
        // Output the text from the file
        
        // parse
        size_t count=0;
        if (line_number==0)
        {
            string delimiter = ",";
            
            size_t position_next = 0;
            size_t position_current = 0;
            while(position_next!=-1)
            {
                position_next = line.find(delimiter, position_current+1);
                string move_str = line.substr(position_current, position_next-position_current);
                position_current=position_next+1;
                cout << move_str << ',';
                int cur_value = stoi(move_str);
                // day_bookkeeper[key] = day_bookkeeper[key]+1;
                if (cur_value<MAX_VALUE)
                {
                    deltas[cur_value]= deltas[cur_value] + 1;
                    if( cur_value < min_value)
                        min_value = cur_value;
                    if( cur_value > max_value)
                        max_value = cur_value;
                }
                else
                {
                    printf("too large!\n");
                }
                count++;

            }
            
        }
    }
    printf("\n");

    printf("min: %i\n", min_value);
    printf("max: %i\n", max_value);

    
    for (size_t i = min_value; i <= max_value; i++)
    {
        if(deltas[i]!=0)
            printf("number %2i values: %3i\n", i, deltas[i]);
    }
    

    return count;
};

size_t Solution::part1()
{
    return parse_and_anaylize();
}

int main(int argc, char const *argv[])
{
    string data_file = "day_007_example.txt";
    // string data_file = "day_007.txt";

    Solution solution(data_file);

    solution.part1();

    return 0;
}
