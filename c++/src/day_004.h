#ifndef DAY_004_H_
#define DAY_004_H_

#include <cstdint>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    static const int BOARD_MAX_COUNT = 25;
    static const int BOARD_ROW_COUNT = 5;
    static const int BOARD_COL_COUNT = 5;
    struct BoardBookie
    {
        int ind_column{0};
        int ind_row{0};
        int count{0};
        int board_numbers[BOARD_ROW_COUNT][BOARD_COL_COUNT]{0};
        int board_turns[BOARD_ROW_COUNT][BOARD_COL_COUNT]{0};
        
        void reset()
        {
            ind_column = 0;
            ind_row = 0;
            count = 0;
        }
    };
    BoardBookie m_board;
    
    string m_data_file;
    map<int,int> m_moves;


    bool parse_data_file( string data_file_path);
    int get_best_row_value(int matrix[BOARD_ROW_COUNT][BOARD_COL_COUNT], int& best_row_value, int& best_row_index, int& best_col_index);
    int get_best_col_value(int matrix[BOARD_ROW_COUNT][BOARD_COL_COUNT], int& best_col_value, int& best_row_index, int& best_col_index);
    void process_board(BoardBookie& board, int& best_score, int& final_score);
    void print_board(BoardBookie& board);
public:
    Solution(string data_file):
        m_data_file(data_file){
            parse_data_file(m_data_file);
        };
    ~Solution(){};

    uint32_t part1();
    uint32_t part2();
};

#endif // DAY_004_H_