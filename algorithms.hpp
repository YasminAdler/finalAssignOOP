//Dean Shalev 209707470
//Yasmin Adler 208462184

#pragma once
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
#include "maze2D.hpp"
#include "searchable.hpp"
#include <functional>
#include "maze2D.hpp"

class Algorithm
{
private:
    std::string algoName;

protected:
    void setAlgoName(const std::string &name)
    {
        algoName = name;
    }

public:
    virtual std::vector<std::pair<int, int>> solveMaze(SearchableMaze &smaze) = 0;
};

class BFS : public Algorithm
{

public:
    BFS()
    {
        setAlgoName("BFS"); // Set the algoName to "BFS"
    }
    std::vector<std::pair<int, int>> solveMaze(SearchableMaze &smaze);
};

class Astar : public Algorithm
{
public:
    Astar()
    {
        setAlgoName("A*"); // Set the algoName to "A*"
    }
    std::vector<std::pair<int, int>> solveMaze(SearchableMaze &smaze);
};