//Dean Shalev 209707470
//Yasmin Adler 208462184

#include "command.hpp"

std::vector<std::string> Dir::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    DIR *dr;
    struct dirent *en;
    dr = opendir(str[1].c_str()); // open all directory
    std::vector<std::string> dirList;
    if (dr)
    {
        while ((en = readdir(dr)) != NULL)
        {
            dirList.push_back(" \n");

            dirList.push_back(en->d_name); // print all directory name
        }
        std::cout << std::endl;
        closedir(dr); // close all directory
    }
    return dirList;
}
std::vector<std::string> Generate::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::vector<std::string> mazeIsready;
    SimpleMaze2DGenerator sm2dg;
    sm2dg.generateMaze(mg, str[2]);
    mazeIsready.push_back("Maze ");
    mazeIsready.push_back(str[2]);
    mazeIsready.push_back(" is ready\n");
    return mazeIsready;
}

std::vector<std::string> Save::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::vector<std::string> nothing;
    mg.MazeToFile(str[2], str[3]);
    return nothing;
}
std::vector<std::string> Load::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::vector<std::string> nothing;
    mg.FileToMaze(str[2], str[3]);
    return nothing;
};

std::vector<std::string> MazeSize::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::vector<std::string> mazeSize;
    for (int i = 0; i < mg.getloadedMazes().size(); i++)
    {
        if (mg.getloadedMazes()[i].getName() == str[2])
        {
            mazeSize.push_back("The maze size is ");
            std::string str = std::to_string(mg.getloadedMazes()[i].getData().size());
            mazeSize.push_back(str);
            mazeSize.push_back(" bits\n");
            return mazeSize;
        }
    }
    mazeSize.push_back("Maze not found\n");
    return mazeSize;
};
std::vector<std::string> FileSize::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::vector<std::string> FileSize;
    std::ifstream infile;
    int index = 0;
    infile.open(str[2], std::ios::in);
    if (infile)
    {
        std::string buffer;
        std::getline(infile, buffer, '\n');
        FileSize.push_back("The file size is ");
        std::string st = std::to_string(buffer.size());
        FileSize.push_back(st);
        FileSize.push_back(" bits\n");
        infile.close();
        return FileSize;
    }
    else
    {
        FileSize.push_back("Maze not found\n");
        return FileSize;
    }
};

std::vector<std::string> Solve::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::vector<std::string> solveStr;

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
                    solveStr.push_back("Unknown algorithm specified.\n");
                }
                return solveStr;
            }
            else
            {
                solveStr.push_back("Maze ");
                solveStr.push_back(maze->getName());
                solveStr.push_back(" is unsolvable\n");
                return solveStr;
            }
        }
    }
    solveStr.push_back("Maze not found\n");
    return solveStr;
}

std::vector<std::string> DisplaySolution::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::vector<std::string> disSol;
    std::string first;
    std::string second;

    for (int i = 0; i < mg.getloadedMazes().size(); i++)
    {
        if (mg.getloadedMazes()[i].getName() == str[2])
        {

            std::vector<std::pair<int, int>> solution = mg.getSolutions()[mg.getloadedMazes()[i].getName()];
            for (int j = 0; j < solution.size(); j++)
            {
                first = std::to_string(solution[j].first);
                disSol.push_back(first);
                second = std::to_string(solution[j].second);
                disSol.push_back(second);
                disSol.push_back(" ");
            }
        }
    }
    disSol.push_back("Maze unsolvable\n");
    return disSol;
};

std::vector<std::string> DisplayMaze::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::vector<std::string> disMaz;
    for (int i = 0; i < mg.getloadedMazes().size(); i++)
    {
        if (mg.getloadedMazes()[i].getName() == str[1])
        {
            mg.getloadedMazes()[i].printMaze();
            return disMaz;
        }
    }
    disMaz.push_back("Maze not found\n");
    return disMaz;
};

std::vector<std::string> Exit::Execute(std::vector<std::string> str, MazeGame &mg) const
{
    std::vector<std::string> st;
    if (str[0] == "exit")
        exit(0);
    return st;
};
