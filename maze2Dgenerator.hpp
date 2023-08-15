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
    // virtual void measureAlgorithmTime() = 0;
    // virtual bool testGeneratedMaze(Maze2D &maze);

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
    // void measureAlgorithmTime() {};
    // bool testGeneratedMaze(Maze2D &maze) {};
};

class MyMaze2DGenerator : public Maze2Dgenerator
{
    bool generateMaze(std::string name_);
    // void measureAlgorithmTime() {};
    // bool testGeneratedMaze() {};
};

bool recursiveDFS(std::pair<int, int> node, std::pair<int, int> prev, std::pair<int, int> goal, Maze2D &maze);
bool isSolvable(const std::vector<std::vector<int>> &mazeMap, const std::pair<int, int> &startPoint, const std::pair<int, int> &endPoint);
