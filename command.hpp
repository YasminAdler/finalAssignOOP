#pragma once
#include "maze2Dgenerator.hpp"
#include "searchable.hpp"
#include "mazeGame.hpp"

class Command
{
private:
   MazeGame *mazeGame_;

public:
   virtual ~Command()
   {
   }
   virtual void Execute(std::vector<std::string> str, MazeGame& mg) const = 0;
};

class Dir : public Command
{
   void Execute(std::vector<std::string> str){};
};
class Generate : public Command
{

   void Execute(std::vector<std::string> str, MazeGame &mg);
};

class DisplayMaze : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg);
};

class Save : public Command
{
   void Execute(std::vector<std::string> str, MazeGame &mg);
};

class Load : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg);
};

class MazeSize : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg);
};

class FileSize : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg);
};

class Solve : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg);
};

class DisplaySolution : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg);
};

class Exit : public Command
{
   void Execute(std::vector<std::string> str, MazeGame& mg);
   
};
