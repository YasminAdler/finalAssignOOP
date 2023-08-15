#include "model.hpp"

std::vector<std::string> Model::doCommand(std::pair<Command *, std::vector<std::string>> p, MazeGame &mg)

{
    return p.first->Execute(p.second, mg);

}