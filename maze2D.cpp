#include "maze2D.hpp"
Maze2D::Maze2D(std::vector<int> mazeData_, std::string name_)
{
    startPoint.first = mazeData_[0];
    startPoint.second = mazeData_[1];
    endPoint.first = mazeData_[2];
    endPoint.second = mazeData_[3];
    int q = 6;
    for (int i = 0; i < mazeData_[4]; i++)
        for (int j = 0; j < mazeData_[5]; j++)
            if (q < mazeData_.size() - 6)
                mazeMap[i][j] = mazeData_[q++];
}

std::vector<int> Maze2D::getData()
{
    std::vector<int> dataArray(mazeMap.size() * mazeMap[0].size() + 6); // four cells for two points(start and end point), two cells for maze dimensions(rows and columns), size*size cells for map data
    dataArray[0] = startPoint.first;
    dataArray[1] = startPoint.second;
    dataArray[2] = endPoint.first;
    dataArray[3] = endPoint.second;
    dataArray[4] = mazeMap.size();
    dataArray[5] = mazeMap[0].size();
    int q = 6;

    for (int i = 0; i < mazeMap.size(); i++) // for each element in dataArray start from index = 6 we enter the maze point
        for (int j = 0; j < mazeMap[0].size(); j++)
            if (q < mazeMap.size() * mazeMap[0].size())
                dataArray[q++] = mazeMap[i][j];
    return dataArray;
}

