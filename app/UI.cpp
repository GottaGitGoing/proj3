// ui.cpp
#include "HashMap.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

void startUI()
{
    HashMap hm;
    bool debug_on = false;
    std::vector<std::string> user_history;
    std::string valid_commands = "CREATE LOGIN REMOVE CLEAR DEBUG BUCKET LOAD MAX";
    for (std::string line; std::getline(std::cin,line);)
    {
        std::istringstream in{line};
        std::string command, user, pass;
        if (in >> command)
        {
            if (command == "QUIT") {std::cout << "GOODBYE" << std::endl; break;}
            
            if (valid_commands.find(command) == std::string::npos)
            {
                std::cout << "INVALID" << std::endl;
                continue;
            }   

            in >> user >> pass; 
            
            if (command == "CREATE")
            {
                if (user.length() == 0 || pass.length() == 0) 
                {
                    std::cout << "INVALID" << std::endl;
                    continue;
                }
                if (hm.contains(user) == true) 
                {
                    std::cout << "EXISTS" << std::endl;
                    continue;
                }
                hm.add(user,pass);
                user_history.push_back(user);
                std::cout << "CREATED" << std::endl;
                continue;

            }
            // std::cout << command << user <<pass <<std::endl;
            if (command == "LOGIN")
            {
                if (user == "COUNT") 
                {
                    if (debug_on == false)
                    {
                        std::cout << "INVALID" << std::endl;
                        continue;
                    }
                    // if (pass.length() !=0) {std::cout << "INVALID"; continue;}
                    std::cout << hm.size() << std::endl;
                    continue;
                }
                if (user.length() == 0 || pass.length() ==0) 
                {
                    std::cout << "INVALID" << std::endl;
                    continue;
                }
                if (hm.value(user) != "" && hm.value(user) == pass)
                {
                    std::cout << "SUCCEEDED" << std::endl;
                    continue;
                }
                std::cout << "FAILED" << std::endl;
            }

            if (command == "REMOVE")
            {
                if(hm.remove(user) == true && pass.length() ==0)
                {
                    std::cout << "REMOVED" << std::endl;
                    continue;
                }
                if (pass.length() >0)
                {
                    std::cout << "INVALID" << std::endl;
                    continue;
                }
                std::cout << "NONEXISTENT" << std::endl;
                continue;
                
            }
            
            if (command == "CLEAR")
            {
                if (user.length()==0 && pass.length() ==0)
                {
                    // std::cout << hm.size() <<std::endl;
                    for (std::string i: user_history)
                    {
                        hm.remove(i);
                    }
                    continue;
                } 
            }

            if (command == "DEBUG")
            {
                // if (user != "ON")
                // {
                //     std::cout << "INVALID" << std::endl;
                //     continue;
                // }
                if (user == "ON" && debug_on==false)
                {
                    std::cout << "ON NOW" << std::endl;
                    debug_on = true;
                    continue;
                }
                if (user == "ON" && debug_on==true)
                {
                    std::cout << "ON ALREADY" << std::endl;
                    continue;
                }
                if (user == "OFF" && debug_on==true)
                {
                    std::cout << "OFF NOW" << std::endl;
                    debug_on = false;
                    continue;
                }
                if (user == "OFF" && debug_on==false)
                {
                    std::cout << "OFF ALREADY" << std::endl;
                    continue;
                }
            }

            if (command == "BUCKET")
            {
                if (user == "COUNT" && debug_on== true && pass.length()==0)
                {
                    std::cout << hm.bucketCount() << std::endl;
                    continue;
                }
                std::cout << "INVALID" << std::endl;
                continue;

            }

            if (command == "LOAD")
            {
                if (user == "FACTOR" && debug_on== true && pass.length()==0)
                {
                    std::cout << hm.loadFactor() << std::endl;
                    continue;
                }
                std::cout << "INVALID" << std::endl;
                continue;
            }

            if (command == "MAX")
            {
                if (user == "BUCKET" && debug_on== true && pass =="SIZE")
                {
                    std::cout << hm.maxBucketSize() << std::endl;
                    continue;
                }
                std::cout << "INVALID" << std::endl;
                continue;
            }

            
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
        
    }
}