#ifndef DAY_009_H_
#define DAY_009_H_

#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    string m_data_file;
    vector<uint8_t> m_low_points;
    void fill_array(string& line, uint8_t array[], size_t size_of_array);
    void add_low_point(uint8_t value, int row, int col);
    size_t parse_and_analyze();
public:
    Solution(string data_file):
        m_data_file(data_file){};
    ~Solution(){};

    size_t solve();
};


#endif // DAY_009_H_