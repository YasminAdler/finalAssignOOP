
//Dean Shalev 209707470
//Yasmin Adler 208462184

#include "searchable.hpp"

SearchableMaze::SearchableMaze(Maze2D &maze_)
{
    maze = &maze_;
}

std::vector<std::pair<int, int>> SearchableMaze::getAllPossibleStates(std::pair<int, int> curr)
{
    std::vector<std::pair<int, int>> states;
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (const auto &dir : directions)
    {
        int newRow = curr.first + dir.first;
        int newCol = curr.second + dir.second;

        if (newRow >= 1 && newRow <= 18 && newCol >= 0 && newCol < 38)
        {
            if (maze->getMap()[newRow][newCol] == 0)
            {
                states.push_back({newRow, newCol});
            }
        }
    }

    return states;
}

// std::vector<std::pair<int, int>> SearchableMaze::getAllPossibleStates(std::pair<int,int> curr)
// {
//     std::vector<std::pair<int, int>> states;
//     int q = 0;
//     for (int i = 0; i < 4; i++)
//     {
//         if(!curr.first - 1 < 1)
//         {
//             if(!maze->getMap()[curr.first - 1][curr.second])
//                 states.push_back({curr.first - 1, curr.second});
//         }
//         else if(!curr.first + 1 > 18)
//         {
//             if(!maze->getMap()[curr.first + 1][curr.second])
//                 states.push_back({curr.first + 1, curr.second});
//         }
//         else if(!curr.second - 1 < 0)
//         {
//             if(!maze->getMap()[curr.first][curr.second - 1])
//                 states.push_back({curr.first, curr.second - 1});
//         }
//         else if(!curr.second + 1 < 38)
//         {
//             if(!maze->getMap()[curr.first][curr.second + 1])
//                 states.push_back({curr.first, curr.second + 1});
//         }
//     }
//     return states;
// }
