#pragma once
#include <string>
#include <vector>
#include <iostream>
// enum
// {
//     EMPTY,
//     TOPLEFTCORNER,
//     TOPRIGHTCORNER,
//     BOTTOMRIGHTCORNER,
//     BOTTOMLEFTCORNER,
//     VERTICALWALL,
//     VERTICALLEFT,
//     VERTICALRIGHT,
//     VERTICALBOTH,
//     HORIZONTALWALL,
//     HORIZONTALTOP,
//     HORIZONTALBOTTOM,
//     HORIZONTALBOTH,
//     AGENT,
//     GOAL
// };

enum
{
    EMPTY,
    VERTICALWALL,
    HORIZONTAL,
    AGENT,
    GOAL
};
class Maze2D
{
private:
    std::vector<std::vector<int>> mazeMap;
    std::string name;
    std::pair<int, int> startPoint;
    std::pair<int, int> endPoint;

public:
    Maze2D(std::string name_) : name(name_) {}
    Maze2D(std::vector<std::string> mazeData_, std::string name_);
    std::vector<std::string> getData();
    int getRows() { return mazeMap.size(); };
    int getColumns() { return mazeMap[0].size(); };
    std::pair<int, int> getStartPoint() { return startPoint; };
    std::pair<int, int> getEndPoint() { return endPoint; };
    std::vector<std::vector<int>>& getMap() { return mazeMap; };
    void setMap(std::vector<std::vector<int>> mazeMap_) { mazeMap = mazeMap_; };
    std::string getName() { return name; };
    void setName(std::string name_) {name = name_;};
    void setStart(std::pair<int,int> start_) {startPoint = start_;};
    void setEnd(std::pair<int,int> end_) {endPoint = end_;};
    void printMaze();
    // virtual void solveMaze();
};