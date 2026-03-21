#pragma once

#include <string>
#include "IAudioDevice.hpp"
#include "../externals/HeadphonesAPI.hpp"

class HeadphoneAdapter : public IAudioDevice {
    private:
        HeadphonesAPI* api;

    public:
        HeadphoneAdapter(HeadphonesAPI* api){
            this->api = api;
        }

        ~HeadphoneAdapter(){
            delete api;
        }

        void playAudio(Song* song) override{
            std::string payload = song->getName() + " - " + song->getArtist();
            api->playByHeadphones(payload);
        }
};