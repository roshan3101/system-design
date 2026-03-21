#pragma once

#include <string>
#include "IAudioDevice.hpp"
#include "../externals/BluetoothAPI.hpp"

class BluetoothAdapter : public IAudioDevice {
    private:
        BluetoothAPI* api;

    public:
        BluetoothAdapter(BluetoothAPI* api){
            this->api = api;
        }

        ~BluetoothAdapter(){
            delete api;
        }

        void playAudio(Song* song) override{
            std::string payload = song->getName() + " - " + song->getArtist();
            api->playByBluetooth(payload);
        }
};