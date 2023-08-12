#pragma once
#include <string>
#include <vector>
#include <queue>
#include <list>
#include "searchable.hpp"
class Algorithm
{
private:
    std::string algoName;

public:
    virtual std::vector<std::pair<int, int>> solveMaze(SearchableMaze &smaze) = 0;
};

class BFS : public Algorithm
{

public:
    std::vector<std::pair<int, int>> solveMaze(SearchableMaze &smaze);
};

class Astar : public Algorithm
{
public:
    std::vector<std::pair<int, int>> solveMaze(SearchableMaze &smaze);
};