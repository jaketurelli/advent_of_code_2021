#ifndef DAY_005_H_
#define DAY_005_H_



// #include <cstdint>
#include <string>
#include <vector>
// #include <map>
using namespace std;

class Solution
{
private:
    static constexpr int MAX_VAL = 1000;
    string m_data_file;
    // vector<vector<int>> m_grid;
    // uint16_t m_grid1[MAX_VAL][MAX_VAL]={0};
    uint16_t m_grid[MAX_VAL][MAX_VAL]={0};

public:
    Solution(string data_file):
        m_data_file(data_file){
        };
    ~Solution(){};

    int part1();
    int part2();
};

#endif // DAY_005_H_