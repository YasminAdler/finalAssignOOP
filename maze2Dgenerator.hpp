//Dean Shalev 209707470
//Yasmin Adler 208462184

#pragma once
#include <memory>
#include "maze2D.hpp"
#include <random>
#include <cstdlib>
#include "mazeGame.hpp"
#include <vector>
#include <queue>

class Maze2Dgenerator
{

public:
    virtual bool generateMaze(MazeGame &mg, std::string str);
private:
};

class Context
{
    std::unique_ptr<Maze2Dgenerator> strategy_;

public:
    explicit Context(std::unique_ptr<Maze2Dgenerator> &&strategy = {}) : strategy_(std::move(strategy)) {}
};

class SimpleMaze2DGenerator : public Maze2Dgenerator
{
public:
    bool generateMaze(MazeGame &mg, std::string name_);
};

class MyMaze2DGenerator : public Maze2Dgenerator
{
    bool generateMaze(std::string name_);
};

bool recursiveDFS(std::pair<int, int> node, std::pair<int, int> prev, std::pair<int, int> goal, Maze2D &maze);
bool isSolvable(const std::vector<std::vector<int>> &mazeMap, const std::pair<int, int> &startPoint, const std::pair<int, int> &endPoint);
