#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "maze2D.hpp"

class MazeGame
{
private:
    std::vector<Maze2D> loadedMazes;

public:
    void addMaze(Maze2D &maze_) { loadedMazes.push_back(maze_); };
    bool checkName(std::string name_);
    std::vector<Maze2D> getloadedMazes() { return loadedMazes; };
    void MazeToFile(std::string mazeName, std::string fileName);
};