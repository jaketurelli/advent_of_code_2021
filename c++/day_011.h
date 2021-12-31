#ifndef DAY_011_H_
#define DAY_011_H_
#include <string>
using namespace std;

class Solution
{
private:
    string m_data_file;
    static constexpr int m_ROWS = 10;
    static constexpr int m_COLS = 10;
    uint32_t m_total_flashes;
    uint8_t m_data[m_ROWS][m_COLS] = {0};

public:
    Solution(string file_path)
        : m_data_file(file_path), m_total_flashes(0){};
    ~Solution(){};

    struct Answer
    {
        size_t part1{0};
        size_t part2{0};
    };

private:
    Answer m_answer;
    void display_matrix();
    void increase_by_1();
    void run_flashes();
    void reset_flashes();
    bool resolve_flashes(int row, int col, bool adjacent_flash = false);

public:
    Answer get_answer();
};

#endif // DAY_011_H_