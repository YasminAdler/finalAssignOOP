#include "CLI.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

void CLI::start(MazeGame &mg)
{
    Command *cmd;
    std::string buffer, str;
    std::vector<std::string> v;
    do
    {
        v.clear();
        std::getline(std::cin, buffer, '\n');
        std::istringstream s(buffer);
        while (std::getline(s, str, ' '))
        {
            v.push_back(str);
            if (v[v.size() - 1] == "exit")
                break;
        }
        if (v[0] == "display" && v[1] == "solution")
        {
            commandmap.find("display solution")->second->Execute(v, mg);
        }
        else if (v[0] == "display")
        {
            commandmap.find("display")->second->Execute(v, mg);
        }
        else
        {
            commandmap.find(v[0])->second->Execute(v, mg);
        }

    } while (v[v.size() - 1] != "exit");
}

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
