#include "maze2Dgenerator.hpp"

bool SimpleMaze2DGenerator::generateMaze(MazeGame &mg, std::string name_)
{
    Maze2D *newMaze = new Maze2D(name_);

    srand(time(NULL));
    std::vector<std::vector<int>>
        newMap = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

        };
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            if (i == 0 || i == 19) // first and last rows and columns are walls => #
                newMap[i][j] = 1;
            else if (j == 0 || j == 39) // first and last rows and columns are walls => #
                newMap[i][j] = 1;
            else
            {
                int spot = rand() % 2;
                newMap[i][j] = spot;
            }
            if (i == 18 && j == 39)
                newMap[i][j] = 3;
            if (i == 1 && j == 0)
                newMap[i][j] = 2;
        }
    }
  

    newMaze->setMap(newMap);
    newMaze->setName(name_);
    newMaze->setStart({0, 1});
    newMaze->setEnd({18, 38});
    mg.addMaze(*newMaze);
    mg.getloadedMazes()[mg.getloadedMazes().size() - 1].printMaze();
    return true;
}
bool recursiveDFS(std::pair<int, int> node, std::pair<int, int> prev, std::pair<int, int> goal, Maze2D &maze)
{
    if (node == goal)
    {
        return true;
    }
    std::pair<int, int> next;
    if (node.first > 1)
        if (node.first - 1 != prev.first && (maze.getMap()[node.first - 1][node.second] != 1 && maze.getMap()[node.first - 1][node.second] != 1)) // check if you can move up
        {
            next.first = node.first - 1;
            next.second = node.second;
            recursiveDFS(next, node, goal, maze);
        }
    if (node.second < maze.getColumns() - 1)
        if (node.second + 1 != prev.second && (maze.getMap()[node.first][node.second + 1] != 1 && maze.getMap()[node.first][node.second + 1] != 1)) // check if you can move right
        {
            next.first = node.first;
            next.second = node.second + 1;
            recursiveDFS(next, node, goal, maze);
        }
    if (node.first < maze.getRows() - 1)
        if (node.first + 1 != prev.first && (maze.getMap()[node.first + 1][node.second] != 1 && maze.getMap()[node.first + 1][node.second] != 1)) // check if you can move down
        {
            next.first = node.first + 1;
            next.second = node.second;
            recursiveDFS(next, node, goal, maze);
        }
    if (node.second > 1)
        if (node.second - 1 != prev.second && (maze.getMap()[node.first][node.second - 1] != 1 && maze.getMap()[node.first][node.second - 1] != 1)) // check if you can move left
        {
            next.first = node.first;
            next.second = node.second - 1;
            recursiveDFS(next, node, goal, maze);
        }
    return false;
}


bool isSolvable(const std::vector<std::vector<int>> &mazeMap, const std::pair<int, int> &startPoint, const std::pair<int, int> &endPoint)
{
    int rows = mazeMap.size();
    int cols = mazeMap[0].size();

    // Check if start or end point is blocked
    if (mazeMap[startPoint.first][startPoint.second] == 1 || mazeMap[endPoint.first][endPoint.second] == 1)
        return false;

    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::queue<std::pair<int, int>> queue;

    // Create and initialize the visited matrix
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    queue.push(startPoint);
    visited[startPoint.first][startPoint.second] = true;

    while (!queue.empty()) {
        std::pair<int, int> current = queue.front();
        queue.pop();

        if (current == endPoint)
            return true;

        for (const auto &dir : directions) {
            int newRow = current.first + dir.first;
            int newCol = current.second + dir.second;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                mazeMap[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                queue.push({newRow, newCol});
                visited[newRow][newCol] = true;
            }
        }
    }

    return false;
}
