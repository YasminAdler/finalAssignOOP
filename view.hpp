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
    std::pair<Command *, std::vector<std::string>> viewStart(MazeGame &mg);
    void outputRespons(std::vector<std::string> strOut)
    {
        for (int i = 0; i < strOut.size(); i++)
        {
            std::cout << strOut[i];
        }
            std::cout << std::endl;
    }
    // std::map<std::string, Command *> &getCommandMapFromView()
};
