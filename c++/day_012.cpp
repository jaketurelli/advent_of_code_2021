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
        bool is_big;
        vector<Node *> neighbors;
        Node(string _name, bool _is_big)
            : name(_name),
              is_big(_is_big)
        {
        }
    };
    map<string, Node *> m_node_map;

    bool is_big(string node_name);

    // map<string, vector<string>> m_node_names;
    uint32_t get_number_paths(string start_node);
    // vector<string> m_node_names;

public:
    uint32_t
    getNumberPaths();
    Solution(string data_file) : m_data_file(data_file){};
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
    uint32_t number_paths = get_number_paths("start");

    return 0;
}

uint32_t Solution::get_number_paths(string start_node)
{
    uint32_t number_paths = 0;
    cout << "checking paths for " << start_node << '\n';

    auto neighbors = m_node_map[start_node]->neighbors;

    if (neighbors.empty())
    {
        printf("empty!\n");
        return 0;
    }

    int count = 0;
    for (auto i = neighbors.begin(); i != neighbors.end(); i++)
    {
        if (!(*i)->is_big)
        {
            neighbors.erase(neighbors.begin() + count);
        }
        else
        {
        }
        number_paths++;
        count++;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    string data_file = "day_012.txt";
    Solution solution(data_file);
    uint32_t part1 = solution.getNumberPaths();
    printf("part1: %lu\n", part1);
    return 0;
}
