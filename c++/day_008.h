#ifndef DAY_008_H_
#define DAY_008_H_
#include <string>
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

public:
    Solution(string data_file):
        m_data_file(data_file){};
    ~Solution(){};

    size_t part1_2(Part part);
};


#endif // DAY_008_H_