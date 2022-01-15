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

size_t Solution::parse_and_anaylize(Part part)
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
                // cout << move_str << ',';
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

    // calculate incremental costs for part 2
    vector<int> incremental_costs(max_value-min_value);
    int current_cost = 0;
    for (size_t i =0; i <= max_value-min_value; i++)
    {
        current_cost+=i;
        incremental_costs[i]=current_cost;
        printf("incremental_cost[%4i]=%7i\n",i, current_cost);
    }

    printf("min: %i\n", min_value);
    printf("max: %i\n", max_value);


    int best_position = 0;
    int best_cost = 0;
    for (int ipos = min_value; ipos <= max_value; ipos++)
    {
        int current_cost = 0;
        // loop through each group of locations and determine distance cost
        for (int iloc = min_value; iloc <= max_value; iloc++)
        {
            if(deltas[iloc]!=0)
            {
                if (part==Part::ONE)
                    current_cost += abs(iloc-ipos)*deltas[iloc];
                else if(part==Part::TWO)
                    current_cost += incremental_costs[abs(iloc-ipos)]*deltas[iloc];
            }
        }
        printf("position (%4i) with cost (%8i)\n",ipos,current_cost);
        if(ipos==min_value)
        {
            best_position = ipos;
            best_cost = current_cost;
        }
        else
        {
            if(current_cost < best_cost)
            {
                best_position = ipos;
                best_cost = current_cost;
                printf("better position (%4i) with cost (%8i)\n",ipos,current_cost);
            }
        }
        // printf("cost of position %3i: %i\n",ipos,current_cost);
    }

    return best_cost;
};

size_t Solution::part1_2(Part part)
{
    return parse_and_anaylize( part);
}

int main(int argc, char const *argv[])
{
    // string data_file = "day_007_example.txt";
    string data_file = "day_007.txt";

    Solution solution(data_file);

    // printf("best position fuel cost: %i\n", solution.part1_2(Solution::Part::ONE));
    printf("best position fuel cost: %i\n", solution.part1_2(Solution::Part::TWO));

    return 0;
}
