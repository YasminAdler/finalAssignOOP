#pragma once
#include "maze2D.hpp"
#include "searchable.hpp" // Assuming you have this header with the Searchable interface definition
#include "maze2D.hpp"
#include <vector>
#include <utility>

class SearchableMaze
{
	Maze2D *maze;

public:
	SearchableMaze(Maze2D &maze_);
	std::pair<int, int> getStartState() { return maze->getStartPoint(); };
	std::pair<int, int> getGoalState() { return maze->getEndPoint(); };
	std::vector<std::pair<int, int>> getAllPossibleStates(std::pair<int, int> curr); // returns neighbouring states
};

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};