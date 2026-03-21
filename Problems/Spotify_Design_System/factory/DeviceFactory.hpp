#pragma once

#include "../devices/IAudioDevice.hpp"
#include "../devices/BluetoothAdapter.hpp"
#include "../devices/WiredAdapter.hpp"
#include "../devices/HeadphoneAdapter.hpp"
#include "../enums/DeviceType.hpp"

class DeviceFactory {
    public:
        static IAudioDevice* createDevice(DeviceType deviceType) {
            switch(deviceType) {
                case DeviceType::BLUETOOTH:
                    return new BluetoothAdapter(new BluetoothAPI());
                case DeviceType::WIRED:
                    return new WiredAdapter(new WiredAPI());
                case DeviceType::HEADPHONES:
                    return new HeadphoneAdapter(new HeadphonesAPI());
                default:
                    throw runtime_error("Invalid device type");
            }
        }
};