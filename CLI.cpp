#include "CLI.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

void CLI::start(MazeGame& mg)
{
    Command * cmd;
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

        commandmap.find(v[0])->second->Execute(v, mg);
        std::cout << "generate " << std::endl;

        // print the vector
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << std::endl;
        }
    } while (v[v.size() - 1] != "exit");
}