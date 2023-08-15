#include "view.hpp"

// Command* View::viewStart(MazeGame &mg)
// std::vector<std::string> View::viewStart(MazeGame &mg)
std::pair<Command*, std::vector<std::string>> View::viewStart(MazeGame &mg)
{
    return cli->start();
}