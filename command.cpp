#include "command.hpp"

std::string Dir::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    DIR *dr;
    struct dirent *en;
    dr = opendir(str[1].c_str()); // open all directory
    if (dr)
    {
        while ((en = readdir(dr)) != NULL)
        {
            std::cout <<" \n"
                      << en->d_name; // print all directory name
        }
        std::cout << std::endl;
        closedir(dr); // close all directory
    }
}
std::string Generate::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::cout << "execute generating " << std::endl;

    // SimpleMaze2DGenerator sm2dg;
    // sm2dg.generateMaze(mg, str[2]);
    SimpleMaze2DGenerator sm2dg;
    sm2dg.generateMaze(mg, str[2]);
    std::cout << "Maze " << str[2] << " is ready" << std::endl;
}

std::string Save::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    mg.MazeToFile(str[2], str[3]);
}
std::string Load::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    mg.FileToMaze(str[2], str[3]);
};

std::string MazeSize::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    for (int i = 0; i < mg.getloadedMazes().size(); i++)
    {
        if (mg.getloadedMazes()[i].getName() == str[2])
        {
            std::cout << "The maze size is " << mg.getloadedMazes()[i].getData().size() << " bits" << std::endl;
            return;
        }
    }
    std::cout << "Maze not found" << std::endl;
};
std::string FileSize::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::ifstream infile;
    int index = 0;
    infile.open(str[2], std::ios::in);
    if (infile)
    {
        std::string buffer, str;
        std::getline(infile, buffer, '\n');
        std::cout << "The file size is " << buffer.size() << " bits" << std::endl;
        infile.close();
        return;
    }
    else
        std::cout << "Maze not found" << std::endl;
};

std::string Solve::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    for (int i = 0; i < mg.getloadedMazes().size(); i++)
    {
        if (mg.getloadedMazes()[i].getName() == str[1])
        {
            Maze2D *maze = &mg.getloadedMazes()[i];
            if (isSolvable(maze->getMap(), maze->getStartPoint(), maze->getEndPoint()))
            {
                if (str[2] == "BFS")
                {
                    SearchableMaze *smaze = new SearchableMaze(*maze);
                    BFS bfs;
                    std::vector<std::pair<int, int>> solution = bfs.solveMaze(*smaze);
                    mg.getSolutions()[str[1]] = solution;
                    delete smaze;
                }
                else if (str[2] == "A*")
                {
                    SearchableMaze *smaze = new SearchableMaze(*maze);
                    Astar astar;
                    std::vector<std::pair<int, int>> solution = astar.solveMaze(*smaze);
                    mg.getSolutions()[str[1]] = solution;
                    delete smaze;
                }
                else
                {
                    std::cout << "Unknown algorithm specified." << std::endl;
                }
                return;
            }
            else
            {
                std::cout << "Maze " << maze->getName() << " is unsolvable" << std::endl;
                return;
            }
        }
    }
    std::cout << "Maze not found" << std::endl;
}

std::string DisplaySolution::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    for (int i = 0; i < mg.getloadedMazes().size(); i++)
    {
        if (mg.getloadedMazes()[i].getName() == str[2])
        {

            std::vector<std::pair<int, int>> solution = mg.getSolutions()[mg.getloadedMazes()[i].getName()];
            for (int j = 0; j < solution.size(); j++)
            {
                std::cout << solution[j].first << solution[j].second << " ";
            }
        }
    }
    std::cout << "Maze unsolvable" << std::endl;
    return;
};

std::string DisplayMaze::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    for (int i = 0; i < mg.getloadedMazes().size(); i++)
    {
        if (mg.getloadedMazes()[i].getName() == str[1])
        {
            mg.getloadedMazes()[i].printMaze();
            return;
        }
    }
    std::cout << "Maze not found" << std::endl;
};

std::string Exit::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    if (str[0] == "exit")
        exit(0);
};
