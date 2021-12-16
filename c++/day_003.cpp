///////////////////////////////////////////////
/// @file day_003.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/3
/// @version 0.1
/// @date 2021-12-11
/// 
/// @copyright Copyright (c) 2021
/// 
///////////////////////////////////////////////
#include "day_003.h"
#include <cstdio>


void print_values(uint32_t value)
{
    printf("value: %8i, [ ", value);
    
    for (size_t i = 0; i < NUMBER_BITS; i++)
    {
        printf("%1i ",(value & (1U<<(NUMBER_BITS-i-1)))!=0);
    }
    printf("]\n");

}

void Submarine::print_list(std::list<uint32_t>& list)
{
    for (auto i = list.begin(); i != list.end(); i++)
    {
        print_values(*i);
    }
}

uint32_t Submarine::get_sums(std::list<uint32_t>& list)
{
    buffer_array_number_high_bits[NUMBER_BITS] = {0};
    uint32_t count =0;
    for (auto i = list.begin(); i != list.end(); i++)
    {
        count++;
        for (size_t j = 0; j < NUMBER_BITS; j++)
        {
            // zero out buffer
            if(i==list.begin())
            {
                buffer_array_number_high_bits[j]=0;
            }
            buffer_array_number_high_bits[j] +=(*i & (1U << (NUMBER_BITS-j-1)))==0?0:1;
        }
    }
    printf("Sums set: [ ");
    for (size_t i = 0; i < NUMBER_BITS; i++)
    {
        printf("%3i, ",buffer_array_number_high_bits[i]);
    }
    printf("]\n");

    return count;
}

bool Submarine::add_nodes(std::list<uint32_t>& from, std::list<uint32_t>& to, int bit, bool high)
{
    for (auto i = from.begin(); i != from.end(); i++)
    {
        if( is_bit_high(*i, bit) )
        {
            if(high)
            {
                to.push_back(*i);
                print_values(*i);
            }
        }
        else
        {
            if(!high)
            {
                to.push_back(*i);
                print_values(*i);
            }
        }
    }
    return true;
    
}

bool Submarine::prune_nodes(std::list<uint32_t>& list_to_prune, int bit, bool keep_if_high)
{
    for (auto i = list_to_prune.begin(); i != list_to_prune.end(); i++)
    {
        if( ( is_bit_high(*i, bit) && !keep_if_high) || (!is_bit_high(*i, bit) && keep_if_high))
        {
            // printf("removing: ");
            // print_values(*i);
            list_to_prune.erase(i);
        }
    }
    return true;
    
}




uint32_t get_oxygen_rating(std::list<uint32_t>& start_list)
{
    Submarine sub;
    // std::list<uint32_t> start_list = VALUES;
    
    
    // oxygen generator rating
    // find most common bit for each bit, only keep those. 
    // if bits are equal, keep the 1s
    uint32_t remaining_values = 0;
    uint32_t number_highs = 0;
    for (size_t i = 0; i < NUMBER_BITS; i++)
    {
        remaining_values = sub.get_sums(start_list);
        printf("for bit %i, observing %i numbers.\n", i, remaining_values);
        sub.print_list(start_list);
        
        if (remaining_values != 0)
        {
            number_highs = sub.get_bit_array_value(i);
            if(number_highs*2 >= remaining_values)
            {
                printf("keeping 1s\n");
                sub.prune_nodes(start_list,i,true);
            }
            else
            {
                printf("keeping 0s\n");
                sub.prune_nodes(start_list,i,false);
            }
        }
        else
        {
            // do something if zero returned
            printf("ERROR: 0 numbers (todo)\n");
        }
        remaining_values = sub.get_sums(start_list);
        if( remaining_values ==1 )
        {
            printf("Number found! %i  | ", start_list.front());
            print_values(start_list.front());
            return start_list.front();
        }
    }

    
}


uint32_t get_co2_rating(std::list<uint32_t>& start_list)
{
    Submarine sub;
    // std::list<uint32_t> start_list = VALUES;
//     std::list<uint32_t> start_list ={
// 0b00100,
// 0b11110,
// 0b10110,
// 0b10111,
// 0b10101,
// 0b01111,
// 0b00111,
// 0b11100,
// 0b10000,
// 0b11001,
// 0b00010,
// 0b01010};
    
    // oxygen generator rating
    // find most common bit for each bit, only keep those. 
    // if bits are equal, keep the 1s
    uint32_t remaining_values = 0;
    uint32_t number_highs = 0;
    for (size_t i = 0; i < NUMBER_BITS; i++)
    {
        remaining_values = sub.get_sums(start_list);
        printf("for bit %i, observing %i numbers.\n", i, remaining_values);
        sub.print_list(start_list);
        
        if (remaining_values != 0)
        {
            number_highs = sub.get_bit_array_value(i);
            if(number_highs*2 < remaining_values)
            {
                printf("keeping 1s\n");
                sub.prune_nodes(start_list,i,true);
            }
            else
            {
                printf("keeping 0s\n");
                sub.prune_nodes(start_list,i,false);
            }
        }
        else
        {
            // do something if zero returned
            printf("ERROR: 0 numbers (todo)\n");
        }
        remaining_values = sub.get_sums(start_list);
        if( remaining_values ==1 )
        {
            printf("Number found! %i  | ", start_list.front());
            print_values(start_list.front());
            return start_list.front();
        }
    }

    
}

int main(int argc, const char** argv) {
    // part_1();
    std::list<uint32_t> start_list ={
0b00100,
0b11110,
0b10110,
0b10111,
0b10101,
0b01111,
0b00111,
0b11100,
0b10000,
0b11001,
0b00010,
0b01010};

    std::list<uint32_t> start_list1 = VALUES;
    uint32_t oxygen_rating = get_oxygen_rating(start_list1);

    std::list<uint32_t> start_list2 = VALUES;
    uint32_t co2_rating = get_co2_rating(start_list2);

    uint32_t life_support_rating = oxygen_rating*co2_rating;
    printf("oxygen_rating      : %i\n",oxygen_rating);
    printf("co2_rating         : %i\n",co2_rating);
    printf("life_support_rating: %i\n",life_support_rating);

}