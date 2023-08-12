#include "maze2Dgenerator.hpp"


bool SimpleMaze2DGenerator::generateMaze(MazeGame& mg, std::string name_)
{
    Maze2D *newMaze = new Maze2D(name_);
    do
    {
        srand(time(NULL));
        std::vector<std::vector<int>> newMap = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

        };
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                if (i == 0 || i == 19) // first and last rows and columns are walls => #
                    newMap[i][j] = 2;
                else if (j == 0 || j == 39) // first and last rows and columns are walls => #
                    newMap[i][j] = 1;
                else
                {
                    int spot = rand() % 3;
                    newMap[i][j] = spot;
                }
                if (i == 18 && j == 39)
                    newMap[i][j] = 4;
                if (i == 1 && j == 0)
                    newMap[i][j] = 3;
            }
        }
    } while (!recursiveDFS({0, 1}, {-2, -2}, {18, 39}, *newMaze));
    newMaze->setName(name_);
    newMaze->setStart({0,1});
    newMaze->setEnd({18,38});
    mg.addMaze(*newMaze);   
    return true; 
}
bool recursiveDFS(std::pair<int, int> node, std::pair<int, int> prev, std::pair<int, int> goal, Maze2D &maze)
{
    if (node == goal)
    {
        return true;
    }
    std::pair<int, int> next;
    if (node.first - 1 != prev.first && node.first - 1 >= 0 && (maze.getMap()[node.first - 1][node.second] != 1 && maze.getMap()[node.first - 1][node.second] != 2)) // check if you can move up
    {
        next.first = node.first - 1;
        next.second = node.second;
        recursiveDFS(next, node, goal, maze);
    }
    if (node.second + 1 != prev.second && node.second + 1 < maze.getColumns() - 1 && (maze.getMap()[node.first][node.second + 1] != 1 && maze.getMap()[node.first][node.second + 1] != 2)) // check if you can move right
    {
        next.first = node.first;
        next.second = node.second + 1;
        recursiveDFS(next, node, goal, maze);
    }
    if (node.first + 1 != prev.first && node.first + 1 < maze.getRows() - 1 && (maze.getMap()[node.first + 1][node.second] != 1 && maze.getMap()[node.first + 1][node.second] != 2)) // check if you can move down
    {
        next.first = node.first + 1;
        next.second = node.second;
        recursiveDFS(next, node, goal, maze);
    }
    if (node.second - 1 != prev.second && node.second - 1 >= 0 && (maze.getMap()[node.first][node.second - 1] != 1 && maze.getMap()[node.first][node.second - 1] != 2)) // check if you can move left
    {
        next.first = node.first;
        next.second = node.second - 1;
        recursiveDFS(next, node, goal, maze);
    }
    return false;
}

// bool Maze2Dgenerator::testGeneratedMaze(Maze2D &maze)
// {
//     std::pair<int, int> basePrev(-1, -1);
//     recursiveDFS(maze.getStartPoint(), basePrev, maze.getEndPoint(), maze);
//     return true;
// }
