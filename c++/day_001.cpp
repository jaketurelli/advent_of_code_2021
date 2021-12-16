///////////////////////////////////////////////
/// @file day_001.cpp,
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/1
/// @version 0.1
/// @date 2021-12-10
/// 
/// @copyright Copyright (c) 2021
/// 
///////////////////////////////////////////////
#include "day_001.h"
#include <cstdio>


// How many measurements are larger than the previous measurement?

int part_1(void)
{
    int number_increases = 0;
    for (size_t i = 1; i < NUMBER_INPUT_VALUES; i++)
    {
        number_increases += INPUT_VALUES[i] > INPUT_VALUES[i-1]?1:0;
    }
    return number_increases;
}

int part_2(void)
{
    int number_increases = 0;
    for (size_t i = 3; i < NUMBER_INPUT_VALUES; ++i)
    {
        number_increases += (INPUT_VALUES[i-2] +
                             INPUT_VALUES[i-1] +
                             INPUT_VALUES[i-0] )
                             > 
                            (INPUT_VALUES[i-3] +
                             INPUT_VALUES[i-2] +
                             INPUT_VALUES[i-1])?1:0;
    }
    return number_increases;
}

int main(int argc, char const *argv[])
{
    // part 1
    printf("part 1 number increases: %i\n", part_1());

    // part 2
    printf("part 2 number increases: %i\n", part_2());
    return 0;
}
