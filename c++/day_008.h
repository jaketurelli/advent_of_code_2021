#ifndef DAY_008_H_
#define DAY_008_H_
#include <string>
#include <map>
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
    string m_data_file;
    size_t parse_and_anaylize(Part part);

    static constexpr int SEGS_PER_DIGIT[10]={
        6,  // 0
        2,  // 1
        5,  // 2
        5,  // 3
        4,  // 4
        5,  // 5
        6,  // 6
        3,  // 7
        7,  // 8
        6}; // 9

public:
    Solution(string data_file):
        m_data_file(data_file){};
    ~Solution(){};

    size_t part1_2(Part part);
};


#endif // DAY_008_H_