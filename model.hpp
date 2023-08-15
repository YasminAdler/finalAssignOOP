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

    // Model(MazeGame &mg_) : mg(&mg_){};
    // void modelGenerateMaze(std::string str)
    // {
    //     SimpleMaze2DGenerator sm2dg;
    //     sm2dg.generateMaze(*mg, str);
    // }
    void doCommand(std::pair<Command* , std::vector<std::string>> p, MazeGame& mg);

};
