#pragma once

#include <string>
#include <iostream>

class HeadphonesAPI {
    public:
    void playByHeadphones (const std::string& data){
        std::cout << "[Headphones]: Playing " << data << " by Headphones" << std::endl;
    }
};