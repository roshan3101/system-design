#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "../models/Song.hpp"
#include "../devices/IAudioDevice.hpp"

class AudioEngine {
    private:
        Song* currentSong;
        bool songIsPaused;

    public:
        AudioEngine(){
            currentSong = nullptr;
            songIsPaused = false;
        }

        ~AudioEngine() = default;

        std::string getCurrentSongName() const {
            return currentSong ? currentSong->getName() : std::string{};
        }

        bool isSongPaused() const {
            return songIsPaused;
        }

        void play(IAudioDevice* device, Song* song) {
            if(!device) {
                throw std::runtime_error("No audio device provided");
            }
            if(!song) {
                throw std::runtime_error("Cannot play a null song");
            }

            if(songIsPaused && song == currentSong) {
                songIsPaused = false;
                std::cout << "Resuming playback of " << song->getName() << std::endl;
                device->playAudio(song);
                return;
            }

            currentSong = song;
            songIsPaused = false;
            std::cout << "Playing " << song->getName() << std::endl;
            device->playAudio(song);
        }


        void pause() {
            if(currentSong == nullptr) {
                throw std::runtime_error("No song is currently playing");
            }

            if(songIsPaused) {
                std::cout << "Song is already paused" << std::endl;
                return;
            }

            songIsPaused = true;
            std::cout << "Paused " << currentSong->getName() << std::endl;
        }
};