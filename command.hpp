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
   virtual void Execute(std::vector<std::string> str, MazeGame &mg) const = 0;
};

class Dir : public Command
{
   void Execute(std::vector<std::string> str, MazeGame &mg) const override;
};
class Generate : public Command
{
   void Execute(std::vector<std::string> str, MazeGame &mg) const override ;
};

class DisplayMaze : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg) const override; 
};

class Save : public Command
{
   void Execute(std::vector<std::string> str, MazeGame &mg) const override;
};

class Load : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg) const override;
};

class MazeSize : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg) const override;
};

class FileSize : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg) const override;
};

class Solve : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg) const override;
};

class DisplaySolution : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg)const override;
};

class Exit : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg)const override;
   
};
