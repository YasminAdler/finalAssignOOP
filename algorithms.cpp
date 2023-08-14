#include "algorithms.hpp"
// #include "algorithms.hpp"
// std::vector<std::pair<int, int>> Algorithm<T>::solveMaze(SearchableMaze &smaze)
// {
// }

// int hueristicFunction(std::pair<int, int> curr, std::pair<int, int> goal)
// {

//     int val = (goal.first - curr.first) + (goal.second - curr.second);
//     return val;
// }

// std::vector<std::pair<int, int>> BFS::solveMaze(SearchableMaze &smaze)
// {
//     std::queue<std::pair<int, int>> Q;
//     Q.push(smaze.getStartState());
//     std::vector<std::pair<int, int>> vis;
//     int goalindex;
//     while (!Q.empty())
//     {
//         std::pair<int, int> curr = Q.front();
//         vis.push_back(curr);
//         if (curr.first == smaze.getGoalState().first && curr.second == smaze.getGoalState().second)
//         {
//             goalindex = vis.size()-1;
//             break;
//         }
//         Q.pop();
//         std::pair<std::vector<std::pair<int,int>>, std::pair<int,int>*> neighbors = {smaze.getAllPossibleStates(curr), &vis[vis.size() - 1]};
//         for (int i = 0; i < neighbors.first.size(); i++)
//             Q.push(neighbors.first[i]);
//     }
//     std::vector<std::pair<int,int>> result;
//     std::pair<int,int>* curr = &vis[goalindex];
//     do{

//         result.push_back(*curr);
//         curr = second;

//     }while(!(curr.first == smaze.getStartState().first && curr.second == smaze.getStartState().second))

// }

// std::vector<std::pair<int, int>> Astar::solveMaze(SearchableMaze &smaze)
// {
//     std::list<std::pair<std::pair<int, int>, int>> openlist;
//     std::list<std::pair<std::pair<int, int>, int>> closedlist;
//     int f = hueristicFunction(smaze.getStartState(), smaze.getGoalState());
//     openlist.insert(openlist.end(), {smaze.getStartState(), f});
//     while (!openlist.empty())
//     {
//         std::list<std::pair<std::pair<int, int>, int>>::iterator it;
//         std::list<std::pair<std::pair<int, int>, int>>::iterator min = openlist.begin();

//         for (it = openlist.begin(); it != openlist.end(); ++it)
//         {
//             if(min->second > it->second)
//                 min = it;
//         }
//         std::pair<std::pair<int, int>, int> curr = {min->first, min->second};
//         openlist.erase(min);
//     }

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
