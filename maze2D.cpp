#include "maze2D.hpp"
Maze2D::Maze2D(std::vector<std::string> mazeData_, std::string name_)
{
    startPoint.first = atoi(mazeData_[0].c_str());
    startPoint.second = atoi(mazeData_[1].c_str());
    endPoint.first = atoi(mazeData_[2].c_str());
    endPoint.second = atoi(mazeData_[3].c_str());

    int q = 0;
    for (int i = 0; i < atoi(mazeData_[4].c_str()); i++)
    {
        std::vector<int> row;
        for (int j = 0; j < atoi(mazeData_[5].c_str()); j++)
            if (q < mazeData_[6].size())
                row.push_back(mazeData_[6].c_str()[q++] - '0');
        mazeMap.push_back(row);
    }
    name = name_;
}

std::vector<std::string> Maze2D::getData()
{
    std::vector<std::string> dataArray; // four cells for two points(start and end point), two cells for maze dimensions(rows and columns), size*size cells for map data
    char str[1024];
    itoa(startPoint.first, str, 10);
    dataArray.push_back(str);
    dataArray.push_back(" ");

    itoa(startPoint.second, str, 10);
    dataArray.push_back(str);
    dataArray.push_back(" ");

    itoa(endPoint.first, str, 10);
    dataArray.push_back(str);
    dataArray.push_back(" ");

    itoa(endPoint.second, str, 10);
    dataArray.push_back(str);
    dataArray.push_back(" ");

    itoa(mazeMap.size(), str, 10);
    dataArray.push_back(str);
    dataArray.push_back(" ");

    itoa(mazeMap[0].size(), str, 10);
    dataArray.push_back(str);
    dataArray.push_back(" ");

    int q = 6;

    for (int i = 0; i < mazeMap.size(); i++) // for each element in dataArray start from index = 6 we enter the maze point
        for (int j = 0; j < mazeMap[0].size(); j++)
        {
            itoa(mazeMap[i][j], str, 10);
            dataArray.push_back(str);
        }
    return dataArray;
}

void Maze2D::printMaze()
{
    for (int i = 0; i < mazeMap.size(); i++)
    {
        for (int j = 0; j < mazeMap[0].size(); j++)
        {
            switch (mazeMap[i][j])
            {
            case 0:
                std::cout << " ";
                break;

            case 1:
                std::cout << "#";
                break;

            case 2:
                std::cout << "O";
                break;

            case 3:
                std::cout << "X";
                break;

            default:
                break;
            }
        }
        std::cout << std::endl;
    }
}
