#ifndef DAY_009_H_
#define DAY_009_H_

#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    struct LowPoint
    {
        uint8_t val;
        uint8_t row;
        uint8_t col;
        LowPoint(uint8_t _val, uint8_t _row, uint8_t _col):
            val(_val),
            row(_row),
            col(_col){};
    };
    string m_data_file;
    size_t m_n_cols;
    size_t m_n_rows;
    vector<LowPoint> m_low_points;
    void fill_array(string& line, uint8_t array[], size_t size_of_array);
    void add_low_point(uint8_t value, int row, int col);
    void parse_and_fill_matrix();
    size_t parse_and_analyze();
public:
    Solution(string data_file):
        m_data_file(data_file),m_n_rows(0){};
    ~Solution(){};

    size_t solve();
};


#endif // DAY_009_H_