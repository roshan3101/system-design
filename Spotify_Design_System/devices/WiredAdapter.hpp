#pragma once

#include <string>
#include "IAudioDevice.hpp"
#include "../externals/WiredAPI.hpp"

class WiredAdapter : public IAudioDevice {
    private:
        WiredAPI* api;

    public:
        WiredAdapter(WiredAPI* api){
            this->api = api;
        }

        ~WiredAdapter(){
            delete api;
        }

        void playAudio(Song* song) override{
            std::string payload = song->getName() + " - " + song->getArtist();
            api->playByWired(payload);
        }
};