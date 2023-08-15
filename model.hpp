//Dean Shalev 209707470
//Yasmin Adler 208462184

#pragma once
#include "mazeGame.hpp"
#include "maze2Dgenerator.hpp"
#include "command.hpp"
#include "CLI.hpp"

class Model
{
private:
    Command* cmd;

public:
    
    std::vector<std::string> doCommand(std::pair<Command* , std::vector<std::string>> p, MazeGame& mg);

};
