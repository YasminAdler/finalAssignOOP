#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>
#include "maze2D.hpp"

class MazeGame
{
private:
    // Model myModel;
    // Controller myController;
    // View myView;

    std::vector<Maze2D> loadedMazes;
    std::unordered_map<std::string, std::vector<std::pair<int, int>>> solutions;

public:
    void addMaze(Maze2D &maze_) { loadedMazes.push_back(maze_); };
    bool checkName(std::string name_);
    std::vector<Maze2D> &getloadedMazes() { return loadedMazes; };
    std::unordered_map<std::string, std::vector<std::pair<int, int>>> &getSolutions() { return solutions; };
    void MazeToFile(std::string mazeName, std::string fileName);
    void FileToMaze(std::string mazeName, std::string fileName);
};
