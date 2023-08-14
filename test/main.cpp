// #include <cstdlib>
// #include <vector>
// #include <iostream>
// #include <ctime>
// #include <windows.h>
// enum ORIENTATION
// {
//     HORIZONTAL,
//     VERTICAL,
// };

// enum DIRECTION
// {
//     SOUTH,
//     EAST,
// };

// ORIENTATION choose_orientation(int width, int height)
// {
//     srand(time(NULL));
//     if (width < height)
//         return HORIZONTAL;
//     else if (height < width)
//         return VERTICAL;
//     else
//         return (rand() % 2 == 0 ? HORIZONTAL : VERTICAL);
// }

// void displaymaze(std::vector<std::vector<int>> grid)
// {
//     for (int i = 0; i < grid.size(); i++)
//     {
//         for (int j = 0; j < grid[0].size(); j++)
//         {
//             std::cout << (grid[i][j] ? '#' : ' ');
//         }
//         std::cout << std::endl;
//     }
//     std::cout << std::endl;
//     std::cout << std::endl;
//     std::cout << std::endl;
// }

// void divide(std::vector<std::vector<int>> &grid, int x, int y, int width, int height, ORIENTATION orientation)
// {
//     srand(time(NULL));
//     if (width < 3 || height < 3)
//         return;
//     int horizontal = orientation == HORIZONTAL;

//     int wallx = x + (horizontal ? 0 : rand() % (width - 2));
//     int wally = y + (horizontal ? rand() % (height - 2) : 0);
//     srand(time(NULL));

//     int passagex = wallx + (horizontal ? rand() % width : 0);
//     int passagey = wally + (horizontal ? 0 : rand() % height);
//     // std::cout << wallx << " " << wally << "\n";

//     int directionx = horizontal ? 1 : 0;
//     int directiony = horizontal ? 0 : 1;

//     int walllength = horizontal ? width : height;
//     int perpendicular = horizontal ? SOUTH : EAST;

//     for (int i = 0; i < walllength; i++)
//     {
//         if (wallx != passagex || wally != passagey)
//             grid[wally][wallx] = 1;
//         wallx += directionx;
//         wally += directiony;
//     }

//     int newx, newy, newwidth, newheight;

//     if (horizontal)
//     {
//         newx = x;
//         newy = y;
//         newwidth = width;
//         newheight = wally - y + 1;
//     }
//     else
//     {
//         newx = x;
//         newy = y;
//         newwidth = wallx - x + 1;
//         newheight = height;
//     }

//     divide(grid, newx, newy, newwidth, newheight, choose_orientation(newwidth, newheight));

//     if (horizontal)
//     {
//         newx = x;
//         newy = wally + 1;
//         newwidth = width;
//         newheight = y + height - wally - 2;
//     }
//     else
//     {
//         newx = wallx + 1;
//         newy = y;
//         newwidth = x + width - wallx - 2;
//         newheight = height;
//     }
//     divide(grid, newx, newy, newwidth, newheight, choose_orientation(newwidth, newheight));
// };

// std::vector<std::vector<int>> generateMaze(int width, int height)
// {
//     std::vector<std::vector<int>> grid(height);
//     for (int i = 0; i < height; i++)
//     {
//         int col = width;
//         grid[i] = std::vector<int>(col);
//         for (int j = 0; j < col; j++)
//         {
//             grid[i][j] = 0;
//         }
//     }

//     divide(grid, 0, 0, width, height, choose_orientation(width, height));
//     return grid;
// };

// int main()
// {
//     std::vector<std::vector<int>> maze = generateMaze(40, 20);
//     displaymaze(maze);
// }

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define constants for maze dimensions
const int WIDTH = 10;
const int HEIGHT = 10;

// Define cell structure
struct Cell {
    bool visited;
    bool topWall;
    bool rightWall;
    bool bottomWall;
    bool leftWall;

    Cell() : visited(false), topWall(true), rightWall(true), bottomWall(true), leftWall(true) {}
};

// Function to get unvisited neighbors
vector<pair<int, int>> getUnvisitedNeighbors(int x, int y, const vector<vector<Cell>>& maze) {
    vector<pair<int, int>> neighbors;
    
    if (x > 0 && !maze[x - 1][y].visited)
        neighbors.push_back(make_pair(x - 1, y));
    if (x < WIDTH - 1 && !maze[x + 1][y].visited)
        neighbors.push_back(make_pair(x + 1, y));
    if (y > 0 && !maze[x][y - 1].visited)
        neighbors.push_back(make_pair(x, y - 1));
    if (y < HEIGHT - 1 && !maze[x][y + 1].visited)
        neighbors.push_back(make_pair(x, y + 1));
    
    return neighbors;
}

// DFS maze generation algorithm
void generateMazeDFS(vector<vector<Cell>>& maze) {
    stack<pair<int, int>> cellStack;
    cellStack.push(make_pair(0, 0));  // Start from top-left corner
    maze[0][0].visited = true;

    while (!cellStack.empty()) {
        int x = cellStack.top().first;
        int y = cellStack.top().second;
        vector<pair<int, int>> unvisitedNeighbors = getUnvisitedNeighbors(x, y, maze);

        if (!unvisitedNeighbors.empty()) {
            int randomIndex = rand() % unvisitedNeighbors.size();
            int nx = unvisitedNeighbors[randomIndex].first;
            int ny = unvisitedNeighbors[randomIndex].second;

            // Remove wall between current cell and chosen neighbor
            if (nx == x - 1) {
                maze[x][y].topWall = false;
                maze[nx][ny].bottomWall = false;
            } else if (nx == x + 1) {
                maze[x][y].bottomWall = false;
                maze[nx][ny].topWall = false;
            } else if (ny == y - 1) {
                maze[x][y].leftWall = false;
                maze[nx][ny].rightWall = false;
            } else if (ny == y + 1) {
                maze[x][y].rightWall = false;
                maze[nx][ny].leftWall = false;
            }

            maze[nx][ny].visited = true;
            cellStack.push(make_pair(nx, ny));
        } else {
            cellStack.pop();
        }
    }
}

// Function to print the maze
void printMaze(const vector<vector<Cell>>& maze) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            cout << (maze[x][y].topWall ? "###" : "# #");
        }
        cout << "#" << endl;
        for (int x = 0; x < WIDTH; ++x) {
            cout << (maze[x][y].leftWall ? "#" : " ");
            cout << " " << (x == WIDTH - 1 ? "#" : "");
        }
        cout << endl;
    }
    for (int x = 0; x < WIDTH; ++x) {
        cout << "###";
    }
    cout << "#" << endl;
}

int main() {
    // Initialize random seed
    srand(static_cast<unsigned>(time(nullptr)));
    
    // Create maze grid
    vector<vector<Cell>> maze(WIDTH, vector<Cell>(HEIGHT));

    // Generate the maze
    generateMazeDFS(maze);

    // Print the maze
    printMaze(maze);

    return 0;
}
