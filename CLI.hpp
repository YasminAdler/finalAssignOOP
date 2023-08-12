#pragma once
#include <iostream>
#include <map>
#include "command.hpp"

class CLI
{
private:
    std::istream &in;
    std::ostream &out;
    std::map<std::string, Command*> commandmap;

public:
    CLI(std::istream &is, std::ostream &os) : in(is), out(os) {
            Dir* dir;
            DisplayMaze* dm;
            Save* save;
            Load* load;
            MazeSize* ms;
            FileSize* fs;
            Solve* solve;
            DisplaySolution * ds;
            Exit * exit;
            commandmap = {
                {"dir",,
                {"Display Maze", dm},
                {"Save", save},
                {"Load", load},
                {"Maze Size", ms},
                {"File Size", fs},
                {"Solve", solve},
                {"Display Solution", ds},
                {"Exit", exit},
            };

    }
    void start(MazeGame& mg);
};