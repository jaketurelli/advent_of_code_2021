///////////////////////////////////////////////
/// @file day_012.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://adventofcode.com/2021/day/12
/// @version 0.1
/// @date 2022-01-02
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
private:
    string m_data_file;

    struct Node
    {
        string name;
        const bool is_big;
        vector<Node *> neighbors;
        bool is_open;
        uint8_t number_of_visits;
        Node(string _name, bool _is_big)
            : name(_name),
              is_big(_is_big),
              is_open(true),
              number_of_visits(0)
        {
        }
    };
    map<string, Node *> m_node_map;

    uint32_t m_number_paths;

    bool is_big(string node_name);

    // map<string, vector<string>> m_node_names;
    uint32_t get_number_paths(string start_node);
    // vector<string> m_node_names;

public:
    uint32_t
    getNumberPaths();
    Solution(string data_file)
        : m_data_file(data_file),
          m_number_paths(0){};
    ~Solution(){};
};

bool Solution::is_big(string node_name)
{
    return node_name[0] == toupper(node_name[0]);
}
uint32_t Solution::getNumberPaths()
{
    string line;
    ifstream data_stream(m_data_file);
    while (getline(data_stream, line))
    {
        int dash_position = line.find("-");
        string first = line.substr(0, dash_position);
        string second = line.substr(dash_position + 1);

        try
        {
            m_node_map.at(first);
        }
        catch (const std::out_of_range &oor)
        {
            Node *node = new Node(first, is_big(first));
            m_node_map[first] = node;
            cout << "adding " << first << '\n';
        }

        try
        {
            m_node_map.at(second);
        }
        catch (const std::out_of_range &oor)
        {
            Node *node = new Node(second, is_big(second));
            m_node_map[second] = node;
            cout << "adding " << second << '\n';
        }

        m_node_map[first]->neighbors.push_back(m_node_map[second]);
        m_node_map[second]->neighbors.push_back(m_node_map[first]);
    }

    for (auto i = m_node_map.begin(); i != m_node_map.end(); i++)
    {
        cout << i->first << ": ";
        for (auto j = i->second->neighbors.begin(); j != i->second->neighbors.end(); j++)
        {
            cout << (*j)->name;
            printf("(%c) | ", (*j)->is_big ? 'B' : 's');
        }
        cout << "\n";
    }

    bool all_paths_found = false;
    (m_node_map["start"])->is_open = false;
    (m_node_map["start"])->number_of_visits = 1;
    uint32_t number_paths = get_number_paths("start");

    return m_number_paths;
}

uint32_t Solution::get_number_paths(string node_name)
{
    // cout << "checking paths for " << node_name << '\n';
    cout << node_name;

    if (node_name == "end")
    {
        m_number_paths++;
        printf("\n");
        return 0;
    }
    Node *curr_node_p = m_node_map[node_name];

    curr_node_p->number_of_visits++;

    // we're here, so close the door on small ones
    if (curr_node_p->number_of_visits > 1 && !curr_node_p->is_big)
        curr_node_p->is_open = false;

    auto neighbors = curr_node_p->neighbors;

    if (neighbors.empty())
    {
        printf("empty!\n");
        return 0;
    }

    int count = 0;
    bool dead_node = true;
    for (auto i = neighbors.begin(); i != neighbors.end(); i++)
    {
        Node *next_node_p = *i;
        if (next_node_p->is_open)
        {
            // cout << "node [ " << next_node_p->name << " ] is open!\n";
            cout << ", ";
            dead_node = false;
            get_number_paths(next_node_p->name);
        }
        else
        {
            // cout << "node [ " << next_node_p->name << " ] is closed!\n";
        }
    }
    if (dead_node)
        printf("dead!\n");
    curr_node_p->is_open = true;
    curr_node_p->number_of_visits = 0;
    // cout << '\n';

    return m_number_paths;
}

int main(int argc, char const *argv[])
{
    string data_file = "day_012_example.txt";
    // string data_file = "day_012_example1.txt";
    // string data_file = "day_012_example2.txt";
    // string data_file = "day_012_example3.txt";
    // string data_file = "day_012.txt";

    Solution solution(data_file);
    uint32_t part1 = solution.getNumberPaths();
    printf("part1: %lu\n", part1);
    return 0;
}
