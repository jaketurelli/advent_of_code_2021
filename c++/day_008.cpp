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
#include <map>

int Solution::get_mask_delta(string a, string b)
{
    //returns number of segments a has more than b

    int delta=0;
    for(size_t i=0; i<a.length(); ++i)
        if(a.find(b[i])==string::npos)
            delta++;
    return delta;
}

bool Solution::fully_masked(string a, string b)
{
    //returns true if a is fully masked by b
    for(size_t i=0; i<a.length(); ++i)
        if(b.find(a[i])==string::npos)
            return false;
    return true;
}

size_t Solution::parse_and_anaylize(Part part)
{
    string line;
    ifstream data_stream(m_data_file);
    string delim_space = " ";
    string delim_pipe  = "|";

    vector<string> unique_output_values;

    int total_sum=0;
    
    while(getline(data_stream, line))
    {
        
        // 
        string string_solution[10] = {};
        map<string,int> map_solution;

        bool output_values_reached = false;
        int position_next = 0;
        int position_current = 0;

        vector<string> input_values;
        vector<string> all_values;
        int output_values_start_index = 0;
        while(position_next!=-1)
        {
            

            position_next = line.find(delim_space, position_current+1);
            string curr_string = line.substr(position_current, position_next-position_current);
            position_current=position_next+1;


            if (curr_string.compare(delim_pipe)==0)
            {
                output_values_reached = true;
                output_values_start_index = all_values.size()-1;
            }
            else
            {
                all_values.push_back(curr_string);
                int string_length = curr_string.length();
                if (string_length == SEGS_PER_DIGIT[1] )
                {
                    map_solution[curr_string] = 1;
                    string_solution[1]= curr_string;
                }
                else if(string_length == SEGS_PER_DIGIT[4] )
                {
                    map_solution[curr_string] = 4;
                    string_solution[4] = curr_string;
                }
                else if(string_length == SEGS_PER_DIGIT[7] )
                {
                    map_solution[curr_string] = 7;
                    string_solution[7] = curr_string;
                }
                else if( string_length == SEGS_PER_DIGIT[8])
                {
                    map_solution[curr_string] = 8;
                    string_solution[8] = curr_string;
                }
            }

            if(output_values_reached)
            {
                if(part==Part::TWO)
                {
                    // printf("input values: ");
                    // for (size_t i = 0; i < input_values.size(); i++)
                    // {
                    //     cout << input_values[i] << ' ';
                    // }
                    // printf("\n");
                    
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


        if( part==Part::TWO)
        {
            // 0 -> 6 x
            // 1 -> 2 *
            // 2 -> 5
            // 3 -> 5 x
            // 4 -> 4 *
            // 5 -> 5
            // 6 -> 6 x
            // 7 -> 3 * 
            // 8 -> 7 *
            // 9 -> 6 x

            // todo: logic for distinguishing segments

            // what about bitwise solution? treat the segs as a mask!
            // = 6 = 0 9 6
            // (value & 7) && (value & 4) must be 9
            // !(value & 1) must be 6
            // (value & 7) & !(value & 4) must be 0
            for (size_t i = 0; i < all_values.size(); i++)
            {
                string cur_string = all_values[i];
                int cur_length = cur_string.length();
                if(cur_length==6)
                {
                    // 9s
                    if(fully_masked(string_solution[7], cur_string ) && fully_masked(string_solution[4], cur_string))
                    {
                        string_solution[9]=cur_string;
                        map_solution[cur_string] = 9;
                    }
                    // 6s
                    if(!fully_masked(string_solution[1], cur_string))
                    {
                        string_solution[6]=cur_string;
                        map_solution[cur_string] = 6;
                    }
                    // 0s
                    if(fully_masked(string_solution[7], cur_string)&&!fully_masked(string_solution[4], cur_string))
                    {
                        string_solution[0]=cur_string;
                        map_solution[cur_string] = 0;
                    }
                    

                }
                

            }

            for (size_t i = 0; i < all_values.size(); i++)
            {
                string cur_string = all_values[i];
                int cur_length = cur_string.length();
                if(cur_length==5)
                {
                    // 3s
                    if(fully_masked(string_solution[7], cur_string))
                    {
                        string_solution[3]=cur_string;
                        map_solution[cur_string] = 3;
                    }
                    else if(get_mask_delta(string_solution[9],cur_string)==1)
                    {
                        string_solution[5]=cur_string;
                        map_solution[cur_string] = 5;
                    }
                    else
                    {
                        string_solution[2]=cur_string;
                        map_solution[cur_string] = 2;
                    }
                }
            }

            int multiplier=1000;
            int cur_sum = 0;
            for (size_t i = 0; i < all_values.size(); i++)
            {
                string cur_string = all_values[i];
                int cur_length = cur_string.length();
                if(map_solution.find(cur_string)!=map_solution.end())
                {
                    if(i>output_values_start_index)
                    {
                        cur_sum += multiplier*map_solution[cur_string];
                        printf("%i ", map_solution[cur_string]);
                        multiplier/=10;
                    }
                }
                else
                    cout << cur_string << ' ';

            }
            total_sum+=cur_sum;
            printf(" (%i) \n", cur_sum);
        }




        // // printf("\n");
        // for (size_t i = 0; i < all_values.size(); i++)
        // {
        //     cout << all_values[i] << ' ';
        //     if (i==output_values_start_index)
        //         printf(" output: ");
        // }
        // printf("\n");
    }

    // print unique_output_values
    // for (size_t i = 0; i < unique_output_values.size(); i++)
    // {
    //     cout << unique_output_values[i] << '\n';
    // }

    
    
    if (part==Part::ONE)
        return unique_output_values.size();
    else
        return total_sum; //todo
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
