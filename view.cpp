//Dean Shalev 209707470
//Yasmin Adler 208462184

#include "view.hpp"

std::pair<Command*, std::vector<std::string>> View::viewStart(MazeGame &mg)
{
    return cli->start();
}