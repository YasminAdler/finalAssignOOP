
#include "searchable.hpp"


SearchableMaze::SearchableMaze(Maze2D &maze_)
{
    maze = &maze_;
}

std::vector<std::pair<int, int>> SearchableMaze::getAllPossibleStates(std::pair<int,int> curr)
{
    std::vector<std::pair<int, int>> states;
    int q = 0;
    for (int i = 0; i < 4; i++)
    {
        if(!curr.first - 1 < 1)
        {
            if(!maze->getMap()[curr.first - 1][curr.second])
                states.push_back({curr.first - 1, curr.second});
        }
        else if(!curr.first + 1 > 18)
        {
            if(!maze->getMap()[curr.first + 1][curr.second])
                states.push_back({curr.first + 1, curr.second});
        }
        else if(!curr.second - 1 < 0)
        {
            if(!maze->getMap()[curr.first][curr.second - 1])
                states[i] = {curr.first, curr.second - 1};
        }
        else if(!curr.second + 1 < 38)
        {
            if(!maze->getMap()[curr.first][curr.second + 1])
                states[i] = {curr.first, curr.second + 1};
        }
    }
    return states;
}