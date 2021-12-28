#ifndef DAY_011_H_
#define DAY_011_H_
#include <string>
using namespace std;

class Solution
{
private:
    string m_data_file;
    static constexpr int m_ROWS = 10; // 100
    static constexpr int m_COLS = 10; // 100
    uint8_t m_data[m_ROWS][m_COLS] = {0};
    int m_step = 0;

public:
    Solution(string file_path)
        : m_data_file(file_path){};
    ~Solution(){};

    struct Answer
    {
        size_t part1{0};
        size_t part2{0};
    };

private:
    Answer m_answer;
    void display_matrix();
    bool increase_by_1();
    bool increment_and_check_adjacents(int row, int col, bool increment_first);
    void check_flashes();

public:
    Answer get_answer();
};

#endif // DAY_011_H_