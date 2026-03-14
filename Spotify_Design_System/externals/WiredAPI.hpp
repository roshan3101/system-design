#pragma once

#include <string>
#include <iostream>

class WiredAPI {
    public:
    void playByWired (const std::string& data){
        std::cout << "[Wired Speaker]: Playing " << data << " by Wired" << std::endl;
    }
};