#pragma once
#include <string>
#include <vector>

enum
{
    EMPTY,
    UPPERWALL,
    BOTTOMWALL,
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
    Maze2D(std::vector<int> mazeData_,std::string name_);
    std::vector<int> getData();
    int getRows() {return mazeMap.size();};
    int getColumns() {return mazeMap[0].size();};
    std::pair<int,int> getStartPoint() {return startPoint;};
    std::pair<int,int> getEndPoint() {return endPoint;};
    std::vector<std::vector<int>> getMap() { return mazeMap;};
    void setMap(std::vector<std::vector<int>> mazeMap_) { mazeMap = mazeMap_;};
    // virtual void solveMaze();
};