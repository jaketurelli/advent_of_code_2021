#ifndef DA7_006_H_
#define DA7_006_H_

#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution
{
private:
    static constexpr size_t SPAWN_DAYS_DEFAULT = 6;
    static constexpr size_t SPAWN_DAYS_NEW = 8;
    string m_data_file;
    vector<uint8_t> m_fish;
    size_t parse_and_fill_fish();
    size_t parse_and_fill_bins();
    size_t day_bookkeeper[SPAWN_DAYS_DEFAULT+1]={0};
    queue<size_t> new_fish_bookie;

public:
    Solution(string input_file)
        : m_data_file(input_file){};
    ~Solution(){};

    size_t part1(size_t number_days);
    size_t part2(size_t number_days);
};

#endif // DA7_006_H_