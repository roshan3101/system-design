#pragma once

#include <string>
#include "../models/Song.hpp"
using namespace std;

class IAudioDevice {
    public:
        virtual ~IAudioDevice() {}
        virtual void playAudio(Song* song) = 0;
};