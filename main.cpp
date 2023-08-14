#include "maze2Dgenerator.hpp"
#include "CLI.hpp"
#include <iostream>
int main ()
{
    MazeGame mg;
    CLI cli(std::cin, std::cout);
    cli.start(mg);    
}