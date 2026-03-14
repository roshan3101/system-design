#pragma once

#include <string>
#include <iostream>

class BluetoothAPI {
    public:
        void playByBluetooth (const std::string& data){
            std::cout << "[Bluetooth Speaker]: Playing " << data << " by Bluetooth" << std::endl;
        }
};