///////////////////////////////////////////////
/// @file day_008.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/8
/// @version 0.1
/// @date 2021-12-16
/// 
/// @copyright Copyright (c) 2021
/// 
///////////////////////////////////////////////
#include "day_008.h"
#include <fstream>
#include <iostream>
#include <vector>

size_t Solution::parse_and_anaylize(Part part)
{
    string line;
    ifstream data_stream(m_data_file);
    string delim_space = " ";
    string delim_pipe  = "|";

    vector<string> unique_output_values;
    
    while(getline(data_stream, line))
    {
        // 0 -> 6
        // 1 -> 2 *
        // 2 -> 5
        // 3 -> 5
        // 4 -> 4 *
        // 5 -> 5
        // 6 -> 6
        // 7 -> 3 * 
        // 8 -> 7 *
        // 9 -> 6

        // todo: logic for distinguishing segments
        // if you know 7 and 1, you can get 'a'
        // 


        bool output_values_reached = false;
        int position_next = 0;
        int position_current = 0;
        vector<string> input_values;
        while(position_next!=-1)
        {
            

            position_next = line.find(delim_space, position_current+1);
            string curr_string = line.substr(position_current, position_next-position_current);
            position_current=position_next+1;


            if (curr_string.compare(delim_pipe)==0)
                output_values_reached = true;
            
            if(output_values_reached)
            {
                if(part==Part::TWO)
                {
                    printf("input values: ");
                    for (size_t i = 0; i < input_values.size(); i++)
                    {
                        cout << input_values[i] << ' ';
                    }
                    printf("\n");
                    
                }
                else
                {
                    int curr_string_length = curr_string.length();
                    if( curr_string_length == SEGS_PER_DIGIT[1] ||
                        curr_string_length == SEGS_PER_DIGIT[4] ||
                        curr_string_length == SEGS_PER_DIGIT[7] ||
                        curr_string_length == SEGS_PER_DIGIT[8])
                    {
                        unique_output_values.push_back(curr_string);
                        // cout << curr_string << ' ';
                    }
                }

            }
            else
            {
                // printf("adding: ");
                // cout << curr_string << ' ';
                input_values.push_back(curr_string);

            }

        }
        // printf("\n");
    }

    // print unique_output_values
    // for (size_t i = 0; i < unique_output_values.size(); i++)
    // {
    //     cout << unique_output_values[i] << '\n';
    // }
    
    return unique_output_values.size();
}

size_t Solution::part1_2(Part part)
{
    return parse_and_anaylize(part);
}
int main(int argc, char const *argv[])
{
    
    string data_file = "day_008_example.txt";
    // string data_file = "day_008.txt";

    Solution solution(data_file);
    // printf("times the digits 1, 4, 7, or 8 appear: %i\n", solution.part1_2(Solution::Part::ONE));
    printf("What you get if you add up all of the output values: %i\n", solution.part1_2(Solution::Part::TWO));

    return 0;
}
