#include "model.hpp"

// void Model::doCommand(std::vector<std::string> p, MazeGame&mg)
void Model::doCommand(std::pair<Command *, std::vector<std::string>> p, MazeGame &mg)

{
    p.first->Execute(p.second, mg);

    // CLI* cli;
    // if (v[0] == "display" && v[1] == "solution")
    // {
    //     cli->getcommandmap().find("display solution")->second->Execute(v, mg);
    //     // commandmap.find("display solution")->second->Execute(v, mg);
    // }
    // else if (v[0] == "display")
    // {
    //     // return {commandmap.find("display")->second, v};
    //     cli->getcommandmap().find("display")->second->Execute(v, mg);
    // }
    // else
    // {
    //     // return {commandmap.find(v[0])->second , v};
    //     cli->getcommandmap().find(v[0])->second->Execute(v, mg);
    // }

    // if (v[0] == "display" && v[1] == "solution")
    // {
    //     return {commandmap.find("display solution")->second, v};
    //     // commandmap.find("display solution")->second->Execute(v, mg);
    // }
    // else if (v[0] == "display")
    // {
    //     return {commandmap.find("display")->second, v};
    //     // commandmap.find("display")->second->Execute(v, mg);
    // }
    // else
    // {
    //     return {commandmap.find(v[0])->second , v};
    //     // commandmap.find(v[0])->second->Execute(v, mg);
    // }
}