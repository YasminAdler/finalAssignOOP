#include "mazeGame.hpp"
#include "CLI.hpp"

class View
{
private:
    CLI *cli;

public:
    View(CLI &cli_) : cli(&cli_){};
    // Command* viewStart(MazeGame& mg);
    // std::vector<std::string> viewStart(MazeGame &mg);
    std::pair<Command*, std::vector<std::string>> viewStart(MazeGame &mg);
    // std::map<std::string, Command *> &getCommandMapFromView()
};
