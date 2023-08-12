#pragma once
#include "maze2D.hpp"

class SearchableMaze
{
	Maze2D* maze;
public:
	SearchableMaze(Maze2D &maze_);
	std::pair<int, int> getStartState(){return maze->getStartPoint();};
	std::pair<int, int> getGoalState(){return maze->getEndPoint();};
	std::vector<std::pair<int, int>> getAllPossibleStates(std::pair<int,int> curr); // returns neighbouring states 
};
