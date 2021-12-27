#ifndef DAY_010_H_
#define DAY_010_H_
#include <string>
#include <map>
#include <queue>
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

    map<char, int> m_incomplete_points = {
        {')', 1},
        {']', 2},
        {'}', 3},
        {'>', 4}};

    priority_queue<size_t> m_incomplete_scores;

public:
    Solution(string data_file) : m_data_file(data_file){};
    ~Solution(){};

    struct Answer
    {
        int part1{0};
        int part2{0};
    };

private:
    Answer m_answer;

public:
    Answer get_answer();
    int part2();
};

#endif // DAY_010_H_