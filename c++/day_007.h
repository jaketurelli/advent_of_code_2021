#ifndef DAY_007_
#define DAY_007_
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
     enum Part
    {
        ONE,
        TWO
    };
private:
    static constexpr int MAX_VALUE = 2001;
    string m_data_file;
    size_t parse_and_anaylize(Part part);
    // vector<int> deltas;
    int deltas[MAX_VALUE]={0};

public:
    Solution(string data_file):
        m_data_file(data_file){};
    ~Solution(){};

    size_t part1_2(Part part);
};

#endif // DAY_007_