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
