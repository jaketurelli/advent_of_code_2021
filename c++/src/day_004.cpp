///////////////////////////////////////////////
/// @file day_004.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief
/// @version 0.1
/// @date 2021-12-12
///
/// @copyright Copyright (c) 2021
///
///////////////////////////////////////////////
#include "day_004.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool Solution::parse_data_file(string data_file_path)
{
    int final_best_turn = 9999;
    int final_best_score = 0;
    int final_worst_turn = 0;
    int final_worst_score = 0;

    // Create a text string, which is used to output the text file
    string line;

    // Read from the text file
    ifstream data_stream(m_data_file);

    int line_number = 0;
    int board_number = 0;
    while (getline(data_stream, line))
    {
        // Output the text from the file

        // parse moves
        if (line_number == 0)
        {
            string delimiter = ",";
            int count = 0;
            size_t position_next = 0;
            size_t position_current = 0;
            while (position_next != -1)
            {
                position_next = line.find(delimiter, position_current + 1);
                string move_str = line.substr(position_current, position_next - position_current);
                // cout << move_str << '\n';
                m_moves.insert(pair<int, int>(stoi(move_str), count++));
                position_current = position_next + 1;
            }

            for (auto i = m_moves.begin(); i != m_moves.end(); i++)
            {
                printf("key: %i | value: %i\n", i->first, i->second);
            }
        }
        else if (line_number > 1 && line.length() > 0)
        {
            string delimiter = " ";
            size_t position_current = 0;
            while (position_current < 14)
            {
                string bingo_str = line.substr(position_current, 2);
                int bingo_val = stoi(bingo_str);
                // if (m_moves.find(bingo_val) != m_moves.end())
                //     printf("%3i ",m_moves[bingo_val]);
                // else
                //     printf("XX ");

                m_board.board_numbers[m_board.ind_row][m_board.ind_column] = bingo_val;
                m_board.board_turns[m_board.ind_row][m_board.ind_column] = m_moves[bingo_val];
                position_current = position_current + 3;
                m_board.ind_column++;
                m_board.count++;
            }
            m_board.ind_row++;
            m_board.ind_column = 0;
            // printf("\n");

            if (m_board.count == BOARD_MAX_COUNT)
            {
                int current_best_turn = 0;
                int current_final_score = 0;
                process_board(m_board, current_best_turn, current_final_score);
                printf("=====\n");
                print_board(m_board);
                if (current_best_turn < final_best_turn)
                {
                    final_best_turn = current_best_turn;
                    final_best_score = current_final_score;
                    printf("better turn found: %i (score: %i)\n=====\n\n", final_best_turn, final_best_score);
                }
                if (current_best_turn > final_worst_turn)
                {
                    final_worst_turn = current_best_turn;
                    final_worst_score = current_final_score;
                    printf("worse turn found: %i (score: %i)\n=====\n\n", final_worst_turn, final_worst_score);
                }

                m_board.reset();
            }
        }
        line_number++;
    }
    printf("*************\n");
    printf("best  turn: %3i (score: %6i)\n=====\n\n", final_best_turn, final_best_score);
    printf("worse turn: %3i (score: %6i)\n=====\n\n", final_worst_turn, final_worst_score);
    printf("*************\n");
    return false;
}

void Solution::print_board(BoardBookie &board)
{
    for (size_t i = 0; i < BOARD_ROW_COUNT; i++)
    {
        for (size_t j = 0; j < BOARD_COL_COUNT; j++)
        {
            printf("%3i ", board.board_numbers[i][j]);
        }
        printf(" | ");
        for (size_t j = 0; j < BOARD_COL_COUNT; j++)
        {
            printf("%3i ", board.board_turns[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Solution::get_best_row_value(int matrix[BOARD_ROW_COUNT][BOARD_COL_COUNT], int &best_row_value, int &best_row_index, int &best_col_index)
{
    int max_row_val = 0;
    int max_row_ind = 0;
    int max_col_ind = 0;

    int best_row_val = 0;
    int best_row_ind = 0;
    int best_col_ind = 0;

    // get max row value and index
    for (size_t i_row = 0; i_row < BOARD_ROW_COUNT; i_row++)
    {
        max_row_val = matrix[i_row][0];
        max_row_ind = 0;

        // check for max row value
        for (size_t i_col = 1; i_col < BOARD_COL_COUNT; i_col++)
        {

            if (matrix[i_row][i_col] > max_row_val)
            {
                // printf("old max: %i | new max: %i\n",
                // max_row_val,
                // matrix[i_row][i_col]);
                max_row_val = matrix[i_row][i_col];
                max_row_ind = i_row;
                max_col_ind = i_col;
            }
        }

        // check if "best" value (min of the max values)
        if (i_row == 0)
        {
            best_row_val = max_row_val;
            best_row_ind = max_row_ind;
            best_col_ind = max_col_ind;
        }
        else if (max_row_val < best_row_val)
        {
            // printf("old best: %i | new best row val: %i\n",
            //     best_row_val, max_row_val);
            best_row_val = max_row_val;
            best_row_ind = max_row_ind;
            best_col_ind = max_col_ind;
        }
    }

    best_row_value = best_row_val;
    best_row_index = best_row_ind;
    best_col_index = best_col_ind;

    return best_row_val;
}

int Solution::get_best_col_value(int matrix[BOARD_ROW_COUNT][BOARD_COL_COUNT], int &best_col_value, int &best_row_index, int &best_col_index)
{
    int max_col_val = 0;
    int max_col_ind = 0;
    int max_row_ind = 0;

    int best_col_val = 0;
    int best_col_ind = 0;
    int best_row_ind = 0;

    // get max col value and index
    for (size_t i_col = 0; i_col < BOARD_COL_COUNT; i_col++)
    {
        max_col_val = matrix[0][i_col];
        max_col_ind = 0;

        // check for max col value
        for (size_t i_row = 1; i_row < BOARD_ROW_COUNT; i_row++)
        {

            if (matrix[i_row][i_col] > max_col_val)
            {
                max_col_val = matrix[i_row][i_col];
                max_col_ind = i_col;
                max_row_ind = i_row;
            }
        }

        // check if "best" value (min of the max values)
        if (i_col == 0)
        {
            best_col_val = max_col_val;
            best_col_ind = max_col_ind;
            best_row_ind = max_row_ind;
        }
        else if (max_col_val < best_col_val)
        {
            best_col_val = max_col_val;
            best_col_ind = max_col_ind;
            best_row_ind = max_row_ind;
        }
    }
    // printf("best col val: %i\n", best_col_val);
    // printf("best col ind: %i\n", best_col_ind);
    // printf("best row ind: %i\n", best_row_ind);

    best_col_value = best_col_val;
    best_row_index = best_row_ind;
    best_col_index = best_col_ind;

    return best_col_val;
}

void Solution::process_board(BoardBookie &board, int &best_turn, int &final_score)
{
    int best_row_value = 0;
    int best_row_row_ind = 0;
    int best_row_col_ind = 0;
    int best_col_value = 0;
    int best_col_row_ind = 0;
    int best_col_col_ind = 0;

    // int best_turn;
    int best_turn_row = 0;
    int best_turn_col = 0;

    // print_board(board);

    get_best_row_value(board.board_turns, best_row_value, best_row_row_ind, best_row_col_ind);
    get_best_col_value(board.board_turns, best_col_value, best_col_row_ind, best_col_col_ind);

    if (best_row_value < best_col_value)
    {
        best_turn = best_row_value;
        best_turn_row = best_row_row_ind;
        best_turn_col = best_row_col_ind;
    }
    else
    {
        best_turn = best_col_value;
        best_turn_row = best_col_row_ind;
        best_turn_col = best_col_col_ind;
    }

    int unmarked_sum = 0;
    for (size_t i = 0; i < BOARD_ROW_COUNT; i++)
    {
        for (size_t j = 0; j < BOARD_COL_COUNT; j++)
        {
            if (board.board_turns[i][j] > best_turn)
                unmarked_sum += board.board_numbers[i][j];
        }
    }

    final_score = unmarked_sum * board.board_numbers[best_turn_row][best_turn_col];
    // printf("best turn: %3i | final number: %3i | unmarked_sum: %5i | final score: %5i\n",
    //         board.board_turns[best_turn_row][best_turn_col],
    //         board.board_numbers[best_turn_row][best_turn_col],
    //         unmarked_sum,
    //         final_score  );
}

uint32_t Solution::part1()
{
    printf("todo: part 1\n");
    return 0;
}
uint32_t Solution::part2()
{
    printf("todo: part 2\n");
    return 0;
}

int main(int argc, const char **argv)
{
    string data_file = "../../data/day_004.txt";
    Solution solution(data_file);
    uint32_t part_1 = solution.part1();
    uint32_t part_2 = solution.part2();
    printf("part1: %lu\n", part_1);
    printf("part2: %lu\n", part_2);
}