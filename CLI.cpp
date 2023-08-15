//Dean Shalev 209707470
//Yasmin Adler 208462184

#include "CLI.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

std::pair<Command *, std::vector<std::string>> CLI::start()
{
    Command *cmd;
    std::string buffer, str;
    std::vector<std::string> v;

    v.clear();
    std::cout << "Commands: " << std::endl;
    std::cout << "dir <path> (example: dir ./savedmazes)" << std::endl;
    std::cout << "generate maze <name> (example: generate maze newmaze)" << std::endl;
    std::cout << "display <name> (example: display newmaze)" << std::endl;
    std::cout << "save maze <name> <filename> (example: save maze newmaze newmaze.txt)" << std::endl;
    std::cout << "load maze <filename> <name> (example: load maze newmaze.txt newmaze)" << std::endl;
    std::cout << "maze size <name> (example: maze size newmaze)" << std::endl;
    std::cout << "file size <filename> (example: file size newmaze.txt)" << std::endl;
    std::cout << "solve <name> <algorithm> (example: solve newmaze Astar)" << std::endl;
    std::cout << "display solution <name> (example: display solution newmaze)" << std::endl;
    std::cout << "exit\n"
              << std::endl;

    std::getline(in, buffer, '\n');
    std::istringstream s(buffer);
    while (std::getline(s, str, ' '))
    {
        v.push_back(str);
        // if (v[v.size() - 1] == "exit")
        // break;
    }
    // return v;
    // return {commandmap.find(v[0])->second, v};

    if (v[0] == "display" && v[1] == "solution")
    {
        return {commandmap.find("display solution")->second, v};
        // commandmap.find("display solution")->second->Execute(v, mg);
    }
    else if (v[0] == "display")
    {
        return {commandmap.find("display")->second, v};
        // commandmap.find("display")->second->Execute(v, mg);
    }
    else
    {
        return {commandmap.find(v[0])->second, v};
        // commandmap.find(v[0])->second->Execute(v, mg);
    }
}

// if (v[0] == "display" && v[1] == "solution")
// {
//     return {commandmap.find("display solution")->second, v};
//     // commandmap.find("display solution")->second->Execute(v, mg);
// }
// else if (v[0] == "display")
// {
//     return {commandmap.find("display")->second, v};
//     // commandmap.find("display")->second->Execute(v, mg);
// }
// else
// {
//     return {commandmap.find(v[0])->second , v};
//     // commandmap.find(v[0])->second->Execute(v, mg);
// }

// } while (v[v.size() - 1] != "exit");
// }

// void CLI::start(MazeGame& mg)
// {
//     std::string buffer;
//     do
//     {
//         out << "Enter command: ";
//         std::getline(std::cin, buffer);
//         std::istringstream s(buffer);
//         std::string command;
//         std::vector<std::string> v;

//         s >> command; // Read the first word
//         if (command == "display")
//         {
//             std::string nextWord;
//             s >> nextWord;
//             if (nextWord == "solution")
//             {
//                 command += " solution";
//             }
//         }

//         // Read the remaining words, if any
//         std::string arg;
//         while (s >> arg)
//         {
//             v.push_back(arg);
//         }

//         auto it = commandmap.find(command);
//         if (it != commandmap.end())
//         {
//             it->second->Execute(v, mg);
//         }
//         else
//         {
//             out << "Unknown command: " << command << std::endl;
//         }
//     } while (buffer != "exit");
// }
