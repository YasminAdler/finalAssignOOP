#pragma once
#include <memory>
#include "maze2D.hpp"
#include <random>
#include <cstdlib>
class Maze2Dgenerator
{

public:
    virtual  Maze2D & generateMaze(std::string);
    virtual void measureAlgorithmTime();
    virtual bool testGeneratedMaze(Maze2D& maze);

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
    Maze2D &generateMaze(std::string name_);
    void measureAlgorithmTime();
    bool testGeneratedMaze(Maze2D& maze);
};

class MyMaze2DGenerator : public Maze2Dgenerator
{
    void generateMaze();
    void measureAlgorithmTime();
    bool testGeneratedMaze();
};
