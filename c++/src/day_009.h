#ifndef DAY_009_H_
#define DAY_009_H_

#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    enum FromDirection
    {
        FromLow,
        FromHigh,
        FromRight,
        FromLeft,
        StartPoint
    };

    struct BasinPoint
    {

        uint8_t row;
        uint8_t col;
        uint8_t val;
        BasinPoint(uint8_t _row, uint8_t _col, uint8_t _val) : row(_row),
                                                               col(_col),
                                                               val(_val){};
    };
    struct LowPoint
    {

        uint8_t row;
        uint8_t col;
        uint8_t val;
        vector<BasinPoint> basin_points;
        LowPoint(uint8_t _row, uint8_t _col, uint8_t _val) : row(_row),
                                                             col(_col),
                                                             val(_val){};
    };
    string m_data_file;
    static const size_t m_n_cols = 100; // 10
    static const size_t m_n_rows = 100; // 5
    uint8_t m_data_matrix[m_n_rows][m_n_cols];
    vector<LowPoint> m_low_points;
    void fill_array(string &line, uint8_t array[], size_t size_of_array);
    void add_low_point(uint8_t value, int row, int col);
    size_t get_basin_points(LowPoint &low_point, uint8_t row, uint8_t col, uint8_t val, FromDirection from_dir);
    void parse_and_fill_matrix();
    size_t parse_and_analyze();

public:
    Solution(string data_file) : m_data_file(data_file){};
    ~Solution(){};

    size_t solve();
};

#endif // DAY_009_H_