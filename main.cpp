#include <cstdlib>
#include <vector>
#include <time.h>
#include <iostream>
#include "maze2D.hpp"
#include <bits/stdc++.h>
#include "mazeGame.hpp"
#include <string>
#include "CLI.hpp"

#define MAZEWIDTH 40
#define MAZELENGTH 20

// Maze2D &generateMaze()
// {
//     srand(time(NULL));
//     std::pair<int, int> startPoint = {rand() % 18 + 1, 0};
//     std::pair<int, int> endPoint = {rand() % 18 + 1, 39};
//     std::vector<std::vector<int>> newMap;
//     newMap[0][0] = TOPLEFTCORNER;
//     newMap[0][39] = TOPRIGHTCORNER;
//     newMap[19][0] = BOTTOMLEFTCORNER;
//     newMap[19][39] = BOTTOMRIGHTCORNER;
//     newMap[startPoint.first][startPoint.second] = AGENT;
//     newMap[endPoint.first][endPoint.second] = GOAL;
//     for (int i = 0; i < 20; i++)
//     {
//         for (int j = 0; j < 40; j++)
//         {
//             if ((i == startPoint.first && j != startPoint.second) || (i == endPoint.first && j == endPoint.second) || (i == 0 && j == 0) || (i == 0 && j == 19) || (i == 19 && j == 39) || (i == 19 && j == 0)) // to not overwrite out start/end points
//             {
//             }
//             else
//             {
//                 if (i == 0) // top border
//                 {
//                     int topwall = rand() % 1;
//                     if (topwall)
//                         newMap[i][j] = HORIZONTALWALL;
//                     else
//                         newMap[i][j] = HORIZONTALBOTTOM;
//                 }
//                 else if (i == 19)
//                 {
//                     int bottomwall = rand() % 1;
//                     if (bottomwall)
//                         newMap[i][j] = HORIZONTALWALL;
//                     else
//                         newMap[i][j] = HORIZONTALTOP;
//                 }

//                 if(j == 0)
//                 {
//                     int leftwall = rand() % 1;
//                     if (leftwall)
//                         newMap[i][j] = VERTICALWALL;
//                     else
//                         newMap[i][j] = VERTICALRIGHT;
//                 }
//                 else if(j == 39)
//                 {
//                     int rightwall = rand() % 1;
//                     if (rightwall)
//                         newMap[i][j] = VERTICALWALL;
//                     else
//                         newMap[i][j] = VERTICALLEFT;
//                 }
//                 else {
//                     if(newMap[i-1][j] != VERTICALLEFT)
//                     {
//                         int wall = rand() % 4;
//                         switch (wall)
//                         {
//                         case 0:
//                             newMap[i][j] = HORIZONTALWALL;
//                             break;
//                         case 1:
//                             newMap[i][j] = HORIZONTALBOTH;
//                             break;
//                         case 2:
//                             newMap[i][j] = HORIZONTALWALL;
//                             break;
//                         case 3:
//                             newMap[i][j] = HORIZONTALWALL;
//                             break;

//                         default:
//                             break;
//                         }

//                     }
//                 }
//             }
//         }
//     }
// }

// Maze2D &generateMaze()
// {
//     srand(time(NULL));
//     // Maze2D newmaze("mazer");
//     Maze2D *newmaze = new Maze2D("mazer");
//     std::vector<std::vector<int>> newMap = {
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

//     };
//     for (int i = 0; i < 20; i++)
//     {
//         for (int j = 0; j < 40; j++)
//         {
//             if (i == 0 || i == 19) // first and last rows and columns are walls => #
//                 newMap[i][j] = 2;
//             else if (j == 0 || j == 39) // first and last rows and columns are walls => #
//                 newMap[i][j] = 1;
//             else
//             {
//                 int spot = rand() % 3;
//                 newMap[i][j] = spot;
//             }
//             if (i == 18 && j == 39)
//                 newMap[i][j] = 4;
//             if (i == 1 && j == 0)
//                 newMap[i][j] = 3;
//         }
//     }
//     for (int i = 0; i < 20; i++)
//     {
//         for (int j = 0; j < 40; j++)
//         {
//             std::cout << (newMap[i][j] == 0 ? ' ' : (newMap[i][j] == 1 ? '|' : (newMap[i][j] == 2 ? '_' : ((newMap[i][j] == 3 ? 'O' : 'X')))));
//         }

//         std::cout << std::endl;
//     }
//     newmaze->setMap(newMap);
//     return *newmaze;
// }

// bool recursiveDFS(std::pair<int, int> node, std::pair<int, int> prev, std::pair<int, int> goal, Maze2D &maze)
// {
//     if (node == goal)
//     {
//         std::cout << "Solved!";
//         return true;
//     }
//     std::pair<int, int> next;
//     if (node.first - 1 != prev.first && node.first - 1 >= 0 && (maze.getMap()[node.first - 1][node.second] != 1 && maze.getMap()[node.first - 1][node.second] != 2)) // check if you can move up
//     {
//         next.first = node.first - 1;
//         next.second = node.second;
//         recursiveDFS(next, node, goal, maze);
//     }
//     if (node.second + 1 != prev.second && node.second + 1 < maze.getColumns() - 1 && (maze.getMap()[node.first][node.second + 1] != 1 && maze.getMap()[node.first][node.second + 1] != 2)) // check if you can move right
//     {
//         next.first = node.first;
//         next.second = node.second + 1;
//         recursiveDFS(next, node, goal, maze);
//     }
//     if (node.first + 1 != prev.first && node.first + 1 < maze.getRows() - 1 && (maze.getMap()[node.first + 1][node.second] != 1 && maze.getMap()[node.first + 1][node.second] != 2)) // check if you can move down
//     {
//         next.first = node.first + 1;
//         next.second = node.second;
//         recursiveDFS(next, node, goal, maze);
//     }
//     if (node.second - 1 != prev.second && node.second - 1 >= 0 && (maze.getMap()[node.first][node.second - 1] != 1 && maze.getMap()[node.first][node.second - 1] != 2)) // check if you can move left
//     {
//         next.first = node.first;
//         next.second = node.second - 1;
//         recursiveDFS(next, node, goal, maze);
//     }
//     std::cout << "Unsolveable!";
//     return false;
// }

int main()
{
    // Maze2D maze = generateMaze();
    // std::cout << "\n"
    //           << recursiveDFS({1, 0}, {-2, -2}, {19, 39}, maze);

    // std::string buffer, str;

    // std::vector<std::string> v;
    //     do
    //     {
    //         std::getline(std::cin, buffer, '\n');
    //         std::istringstream s(buffer);
    //         while (std::getline(s, str, ' '))
    //         {
    //             v.push_back(str);
    //             if (v[v.size() - 1] == "exit")
    //                 break;
    //         }

    //         // print the vector
    //         for (int i = 0; i < v.size(); i++)
    //         {
    //             std::cout << v[i] << std::endl;
    //         }
    //     } while (v[v.size()-1]!= "exit");
    // }

    MazeGame mg;
    CLI cli(std::cin, std::cout);
    cli.start(mg);
    return 0;
}
