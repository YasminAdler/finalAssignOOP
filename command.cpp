#include "command.hpp"

void Generate::Execute(std::vector<std::string> str, MazeGame &mg)
{
        std::cout << "execute generating " << std::endl;

    SimpleMaze2DGenerator sm2dg;
    sm2dg.generateMaze(mg, str[2]);
}

void Save::Execute(std::vector<std::string> str, MazeGame &mg)
{
    mg.MazeToFile(str[2],str[3]);
}
void Load::Execute(std::vector<std::string> str, MazeGame& mg){};

void MazeSize::Execute(std::vector<std::string> str, MazeGame& mg){};
void FileSize::Execute(std::vector<std::string> str, MazeGame& mg){};
void Solve::Execute(std::vector<std::string> str, MazeGame& mg){};
void DisplaySolution::Execute(std::vector<std::string> str, MazeGame& mg){};
void Exit::Execute(std::vector<std::string> str, MazeGame& mg){};