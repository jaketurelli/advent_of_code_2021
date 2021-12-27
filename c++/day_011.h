#ifndef DAY_011_H_
#define DAY_011_H_
#include <string>
using namespace std;

class Solution
{
private:
    string m_data_file;

public:
    Solution(string file_path)
        : m_data_file(file_path){};
    ~Solution(){};

    struct Answer
    {
        size_t part1{0};
        size_t part2{0};
    };

private:
    Answer m_answer;

public:
    Answer get_answer();
};

#endif // DAY_011_H_