//Dean Shalev 209707470
//Yasmin Adler 208462184

#pragma once
#include <iostream>
#include <map>
#include "command.hpp"

class CLI
{
private:
    std::istream &in;
    std::ostream &out;
    std::map<std::string, Command *> commandmap;

public:
    CLI(std::istream &is, std::ostream &os) : in(is), out(os)
    {
        commandmap["dir"] = new Dir();
        commandmap["save"] = new Save();
        commandmap["load"] = new Load();
        commandmap["maze"] = new MazeSize();
        commandmap["file"] = new FileSize();
        commandmap["solve"] = new Solve();
        commandmap["exit"] = new Exit();
        commandmap["generate"] = new Generate();
        commandmap["display"] = new DisplayMaze();
        commandmap["display solution"] = new DisplaySolution();
    }

    std::pair<Command*, std::vector<std::string>> start();

};