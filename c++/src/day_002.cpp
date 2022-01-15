///////////////////////////////////////////////
/// @file day_002.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/2
/// @version 0.1
/// @date 2021-12-10
/// 
/// @copyright Copyright (c) 2021
/// 
///////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char** argv) {
    string line;
    ifstream myfile ("day_002.txt");
    string delimiter = " ";
    int lateral=0;
    int depth = 0;
    int aim = 0;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            string move_type = line.substr(0, line.find(delimiter));
            string move_val = line.substr(line.find(delimiter)+1, line.find(delimiter));
            int move_val_int = stoi(move_val);
            
            if (move_type == "forward")
            {
                // lateral+=move_val_int; // part 1
                
                lateral+=move_val_int; // part 2
                depth+=aim*move_val_int; // part 2
                
            }
            else if(move_type == "up")
            {
                // depth-=move_val_int; // part 1
                aim-=move_val_int; // part 2
            }
            else if(move_type == "down")
            {
                // depth+=move_val_int;// part 1
                aim+=move_val_int; // part 2
            }
            else
            {
                printf("ERROR\n");
            }

        }
        myfile.close();
    }
    printf("depth        : %i\n", depth);
    printf("lateral      : %i\n", lateral);
    printf("aim          : %i\n", aim);
    printf("depth*lateral: %i\n", depth*lateral);

}