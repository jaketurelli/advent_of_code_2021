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

    map<char, char> pairs = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
        {'<', '>'},
        {')', '('},
        {']', '['},
        {'}', '{'},
        {'>', '<'}};

    map<char, int> openers = {
        {'(', 0},
        {'[', 0},
        {'{', 0},
        {'<', 0}};
    map<char, int> closers = {
        {')', 0},
        {']', 0},
        {'}', 0},
        {'>', 0}};

public:
    Solution(string data_file) : m_data_file(data_file){};
    ~Solution(){};

    int part1();
    int part2();
};

#endif // DAY_010_H_