#include <cstdlib>
#include <vector>
#include <time.h>
#include <iostream>
#include "maze2D.hpp"

Maze2D &generateMaze()
{
    srand(time(NULL));
    // Maze2D newmaze("mazer");
    Maze2D *newmaze = new Maze2D("mazer");
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
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            std::cout << (newMap[i][j] == 0 ? ' ' : (newMap[i][j] == 1 ? '|' : (newMap[i][j] == 2 ? '_' : ((newMap[i][j] == 3 ? 'O' : 'X')))));
        }
        std::cout << std::endl;
    }
    newmaze->setMap(newMap);
    return newmaze;
}

bool recursiveDFS(std::pair<int, int> node, std::pair<int, int> prev, std::pair<int, int> goal, Maze2D &maze)
{
    std::cout << "seemk";
    if (node == goal)
        return true;
    std::pair<int, int> next;
    if (node.first - 1 != prev.first && node.first - 1 > 0 && (maze.getMap()[node.first - 1][node.second] != 1 && maze.getMap()[node.first - 1][node.second] != 2)) // check if you can move up
    {
        next.first = node.first - 1;
        next.second = node.second;
        recursiveDFS(next, node, goal, maze);
        std::cout << "up";
    }
    if (node.second + 1 != prev.second && node.second + 1 < maze.getColumns() - 1 && (maze.getMap()[node.first][node.second + 1] != 1 && maze.getMap()[node.first][node.second + 1] != 2)) // check if you can move right
    {
        next.first = node.first;
        next.second = node.second + 1;
        recursiveDFS(next, node, goal, maze);
        std::cout << "right";
    }
    if (node.first + 1 != prev.first && node.first + 1 < maze.getRows() - 1 && (maze.getMap()[node.first + 1][node.second] != 1 && maze.getMap()[node.first + 1][node.second] != 2)) // check if you can move down
    {
        next.first = node.first + 1;
        next.second = node.second;
        recursiveDFS(next, node, goal, maze);
        std::cout << "down";
    }
    if (node.second - 1 != prev.second && node.second - 1 > 0 && (maze.getMap()[node.first][node.second - 1] != 1 && maze.getMap()[node.first][node.second - 1] != 2)) // check if you can move left
    {
        next.first = node.first;
        next.second = node.second - 1;
        recursiveDFS(next, node, goal, maze);
        std::cout << "left";
    }
    return false;
}

int main()
{
    Maze2D maze = generateMaze();
    std::cout << "\n"
              << recursiveDFS({1, 0}, {-2, -2}, {19, 39}, maze);
    std::cout << "done";
}