#pragma once

#include <iostream>
#include <stdexcept>
#include "../devices/IAudioDevice.hpp"
#include "../enums/DeviceType.hpp"
#include "../factory/DeviceFactory.hpp"

class DeviceManager {
    private:
        static DeviceManager* instance;
        IAudioDevice* currentDevice;
        DeviceManager() {
            currentDevice = nullptr;
        }

    public:
        static DeviceManager* getInstance() {
            if(instance == nullptr) {
                instance = new DeviceManager();
            }
            return instance;
        }

        void connect (DeviceType deviceType) {
            if(currentDevice) {
                delete currentDevice;
                currentDevice = nullptr;
            }

            currentDevice = DeviceFactory::createDevice(deviceType);

            switch(deviceType) {
                case DeviceType::BLUETOOTH:
                    std::cout << "Connected to Bluetooth device" << std::endl;
                    break;
                case DeviceType::WIRED:
                    std::cout << "Connected to Wired device" << std::endl;
                    break;
                case DeviceType::HEADPHONES:
                    std::cout << "Connected to Headphones device" << std::endl;
                    break;
                default:
                    throw std::runtime_error("Invalid device type");
            }
        }

        IAudioDevice* getCurrentDevice() const {
            if(!currentDevice) {
                throw std::runtime_error("No device is connected");
            }
            return currentDevice;
        }

        bool hasOutputDevice() {
            return currentDevice != nullptr;
        }

        void disconnect() {
            if(currentDevice) {
                delete currentDevice;
                currentDevice = nullptr;
                std::cout << "Disconnected from device" << std::endl;
            }
        }

        ~DeviceManager() {
            disconnect();
            instance = nullptr;
        }
};

DeviceManager* DeviceManager::instance = nullptr;