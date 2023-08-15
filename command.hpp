#pragma once
#include "maze2Dgenerator.hpp"
#include "searchable.hpp"
#include "mazeGame.hpp"
#include <dirent.h>
#include "algorithms.hpp"
#include <sys/types.h>

class Command
{
private:
   MazeGame *mazeGame_;

public:
   virtual ~Command()
   {
   }
   virtual std::string Execute(std::vector<std::string> str, MazeGame &mg) const = 0;
};

class Dir : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame &mg) const override;
};
class Generate : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame &mg) const override ;
};

class DisplayMaze : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame& mg) const override; 
};

class Save : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame &mg) const override;
};

class Load : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame& mg) const override;
};

class MazeSize : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame& mg) const override;
};

class FileSize : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame& mg) const override;
};

class Solve : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame& mg) const override;
};

class DisplaySolution : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame& mg)const override;
};

class Exit : public Command
{
   std::string Execute(std::vector<std::string> str, MazeGame& mg)const override;
   
};
