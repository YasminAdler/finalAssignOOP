#include "algorithms.hpp"

//Dean Shalev 209707470
//Yasmin Adler 208462184

std::vector<std::pair<int, int>> BFS::solveMaze(SearchableMaze &searchableMaze)
{
    std::pair<int, int> startState = searchableMaze.getStartState();
    std::pair<int, int> goalState = searchableMaze.getGoalState();

    std::queue<std::pair<int, int>> stateQueue;
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, PairHash> parentMap;

    stateQueue.push(startState);
    parentMap[startState] = startState;

    while (!stateQueue.empty())
    {
        std::pair<int, int> currentState = stateQueue.front();
        stateQueue.pop();

        if (currentState == goalState)
        {
            // Reconstruct the path
            std::vector<std::pair<int, int>> path;
            std::pair<int, int> current = goalState;
            while (current != startState)
            {
                path.push_back(current);
                current = parentMap[current];
            }
            path.push_back(startState);
            std::reverse(path.begin(), path.end());
            return path;
        }

        std::vector<std::pair<int, int>> successors = searchableMaze.getAllPossibleStates(currentState);
        for (const std::pair<int, int> &successor : successors)
        {
            if (parentMap.find(successor) == parentMap.end())
            {
                stateQueue.push(successor);
                parentMap[successor] = currentState;
            }
        }
    }

    // No solution found
    return {};
}

double heuristic(const std::pair<int, int> &curr, const std::pair<int, int> &goal)
{
    return static_cast<double>(std::abs(goal.first - curr.first) + std::abs(goal.second - curr.second));
}

std::vector<std::pair<int, int>> Astar::solveMaze(SearchableMaze &searchableMaze)
{
    std::pair<int, int> startState = searchableMaze.getStartState();
    std::pair<int, int> goalState = searchableMaze.getGoalState();

    std::priority_queue<std::pair<double, std::pair<int, int>>> stateQueue;
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, PairHash> parentMap;
    std::unordered_map<std::pair<int, int>, double, PairHash> gScore;

    stateQueue.push({0.0, startState});
    gScore[startState] = 0.0;
    parentMap[startState] = startState;

    while (!stateQueue.empty())
    {
        auto currentPair = stateQueue.top();
        stateQueue.pop();
        std::pair<int, int> currentState = currentPair.second;

        if (currentState == goalState)
        {
            // Reconstruct the path
            std::vector<std::pair<int, int>> path;
            std::pair<int, int> current = goalState;
            while (current != startState)
            {
                path.push_back(current);
                current = parentMap[current];
            }
            path.push_back(startState);
            std::reverse(path.begin(), path.end());
            return path; // Return the solution path
        }

        std::vector<std::pair<int, int>> successors = searchableMaze.getAllPossibleStates(currentState);
        for (const std::pair<int, int> &successor : successors)
        {
            double tentativeGScore = gScore[currentState] + 1.0; // Assuming all steps have the same cost
            if (gScore.find(successor) == gScore.end() || tentativeGScore < gScore[successor])
            {
                gScore[successor] = tentativeGScore;
                double fScore = tentativeGScore + heuristic(successor, goalState);
                stateQueue.push({-fScore, successor});
                parentMap[successor] = currentState;
            }
        }
    }

    // No solution found
    return {}; // Return an empty vector to indicate no solution
}
