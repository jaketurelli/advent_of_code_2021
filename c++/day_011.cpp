///////////////////////////////////////////////
/// @file day_011.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/11
/// @version 0.1
/// @date 2021-12-26
///
/// @copyright Copyright (c) 2021
///
///////////////////////////////////////////////

#include "day_011.h"

Solution::Answer Solution::get_answer()
{
    return m_answer;
}

int main(int argc, char const *argv[])
{
    // string file_path = "day_011.txt";
    string file_path = "day_011_example.txt";
    Solution solution(file_path);
    printf("part 1: %llu\n", solution.get_answer().part1);
    printf("part 2: %llu\n", solution.get_answer().part2);
    return 0;
}
