#include "UI.hpp"
#include <iostream>
#include <string>
#include <sstream>
int main()
{

    // startUI(); 
    std::string valid_commands = "CREATE LOGIN REMOVE CLEAR DEBUG BUCKET LOAD MAX";
    for (std::string line; std::getline(std::cin,line);)
    {
        std::istringstream in{line};
        std::string command, user, pass;
        if (in >> command)
        {
            if (command == "QUIT") {break;}
            else if (valid_commands.find(command) == std::string::npos)
            {
                std::cout << "INVALID" << std::endl;
                continue;
            }   
            in >> user >> pass; 
            std::cout << command << user <<pass <<std::endl;
            
            
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
        
    }
    return 0;
}

