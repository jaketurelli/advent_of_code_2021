///////////////////////////////////////////////
/// @file day_006.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/6
/// @version 0.1
/// @date 2021-12-15
/// 
/// @copyright Copyright (c) 2021
/// 
///////////////////////////////////////////////
#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>

#include "day_006.h"

size_t Solution::part1(size_t number_days)
{
    size_t number_fish = parse_and_fill_fish();
    printf("Initial state: ");
    for (auto i = 0; i < number_fish; i++)
    {
        // intitial
        printf("%i,",m_fish[i]);
    }
    printf("\n");

    for (size_t iday = 1; iday <= number_days; iday++)
    {
        // auto end_this_turn = m_fish.end();
        // printf("       day %2i: ", iday);
        for (auto i = 0; i < number_fish; i++)
        {
            // determine next day 
            if (m_fish[i]==0)
            {
                m_fish[i]=SPAWN_DAYS_DEFAULT;
                m_fish.push_back(SPAWN_DAYS_NEW+1);
                number_fish++;
            }
            else
            {
                m_fish[i]=m_fish[i]-1;
            }

            // process 
            // printf("%i,",m_fish[i]);
            
        }
        // printf("\n");
    }
    return number_fish;
}

size_t Solution::part2(size_t number_days)
{
    size_t number_fish = parse_and_fill_bins();

    // day_bookkeeper
    // new_fish_bookie
    // day 0: 0
    // day 1: 218
    // day 2: 24
    // day 3: 19
    // day 4: 24
    // day 5: 15
    // day 6: 0

    // initialize new_fish_bookie
    for (size_t i = 0; i < SPAWN_DAYS_NEW+1; i++)
    {
        new_fish_bookie.push(0);
    }
    
    
    int spawn_due_index=0;
    for (size_t iday = 1; iday <= number_days; ++iday)
    {
        spawn_due_index = (iday-1)%(SPAWN_DAYS_DEFAULT+1);

        // printf("day %2i: spawn index: %i | %llu | total fish: %llu\n", iday, spawn_due_index, day_bookkeeper[spawn_due_index], number_fish);

        // add front() to current spawn
        day_bookkeeper[spawn_due_index]=day_bookkeeper[spawn_due_index]+new_fish_bookie.front();

        // add current spawn due to bookkie
        new_fish_bookie.push(day_bookkeeper[spawn_due_index]);
        number_fish+=day_bookkeeper[spawn_due_index];

        // remove those fish now that they've been accounted for
        new_fish_bookie.pop(); 
    }
    return number_fish;
}

size_t Solution::parse_and_fill_fish()
{
    // Create a text string, which is used to output the text file
    string line;

    // Read from the text file
    ifstream data_stream(m_data_file);

    size_t line_number = 0;
    size_t count = 0;
    while (getline (data_stream, line)) 
    {
        // Output the text from the file
        
        // parse moves
        
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

                m_fish.push_back(stoi(move_str));
                count++;

            }
            
        }
    }

    for (auto i = m_fish.begin(); i !=m_fish.end(); i++)
    {
        printf("%3i\n",*i);
    }
    return count;
};

size_t Solution::parse_and_fill_bins()
{
    // Create a text string, which is used to output the text file
    string line;

    // Read from the text file
    ifstream data_stream(m_data_file);

    size_t line_number = 0;
    size_t count = 0;


    while (getline (data_stream, line)) 
    {
        // Output the text from the file
        
        // parse moves
        
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
                
                int key = stoi(move_str);
                day_bookkeeper[key] = day_bookkeeper[key]+1;
                count++;

            }
            
        }
    }

    for (auto i = 0; i <SPAWN_DAYS_DEFAULT+1 ; i++)
    {
        printf("day %i: %i\n",i, day_bookkeeper[i]);
    }
    
    return count;
};

int main(int argc, const char** argv) {
    string data_file = "day_006.txt";
    // string data_file = "day_006_example.txt";
    Solution solution(data_file);
    size_t number_days = 80;
    // printf("number fish after %llu days: %llu\n", number_days, solution.part1(number_days));
    
    // part 2
    number_days = 256;
    printf("number fish after %llu days: %llu\n", number_days, solution.part2(number_days));
    
    
    return 0;
}