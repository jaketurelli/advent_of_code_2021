#ifndef DAY_007_
#define DAY_007_
#include <string>

using namespace std;

class Solution
{
private:
    string m_file_path;

public:
    Solution(string data_file):
        m_file_path(data_file){};
    ~Solution(){};

    size_t part1();
    size_t part2();
};

#endif // DAY_007_