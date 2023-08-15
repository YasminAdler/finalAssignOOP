#include "maze2Dgenerator.hpp"
#include "CLI.hpp"
#include <iostream>
#include "controller.hpp"
#include <bits/stdc++.h>
#include <string>

int main()
{
    std::istream *in;
    std::ostream *out;
    MazeGame *mg = new MazeGame();
    CLI *cli = new CLI(std::cin, std::cout);
    View *view = new View(*cli);
    Model *model = new Model();
    Controller *controller = new Controller(*model, *view, *mg);
    controller->startGame();

    // CLI cli(std::cin, std::cout);
    // cli.start(mg);
}