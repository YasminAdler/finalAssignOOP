#include "mazeGame.hpp"

bool MazeGame::checkName(std::string name_)
{
    for (int i = 0; i < loadedMazes.size(); i++)
    {
        if (loadedMazes[i].getName() == name_)
        {
            return false;
        }
    }
    return true;
}

void MazeGame::MazeToFile(std::string mazeName, std::string fileName)
{

    std::ofstream outfile;
    int index = 0;
    outfile.open("./savedMazes/" +fileName);
    for (int i = 0; i < loadedMazes.size(); i++)
    {
        if (loadedMazes[i].getName() == mazeName)
        {
            index = i;
            break;
        }
    }

    for (auto element : loadedMazes[index].getData())
    {
        outfile << element;
    }
    outfile.close();

    loadedMazes.erase(loadedMazes.begin() + index);
}

void MazeGame::FileToMaze(std::string fileName, std::string mazeName)
{
    std::ifstream infile;
    int index = 0;
    infile.open("./savedMazes/" + fileName);
    std::string buffer, str;
    std::getline(infile, buffer, '\n');
    std::vector<std::string> mazedata;
    std::istringstream s(buffer);
    while (std::getline(s, str, ' '))
    {
        mazedata.push_back((str.c_str()));
    }
    Maze2D *maze = new Maze2D(mazedata, mazeName);
    loadedMazes.push_back(*maze);
}
