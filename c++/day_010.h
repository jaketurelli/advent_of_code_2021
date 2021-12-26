#ifndef DAY_010_H_
#define DAY_010_H_
#include <string>
#include <map>
using namespace std;
class Solution
{
private:
    /* data */
    string m_data_file;

    map<char, char> m_pairs = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
        {'<', '>'},
        {')', '('},
        {']', '['},
        {'}', '{'},
        {'>', '<'}};

    map<char, int> m_points = {
        {')', 3},
        {']', 57},
        {'}', 1197},
        {'>', 25137}};

public:
    Solution(string data_file) : m_data_file(data_file){};
    ~Solution(){};

    int part1();
    int part2();
};

#endif // DAY_010_H_