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
    outfile.open(fileName);
    for (int i = 0; i < getloadedMazes().size(); i++)
    {
        if (getloadedMazes()[i].getName() == mazeName)
        {
            index = i;
            break;
        }
    }

    for (auto element : getloadedMazes()[index].getData())
    {
        outfile << element;
    }

    outfile.close();
}