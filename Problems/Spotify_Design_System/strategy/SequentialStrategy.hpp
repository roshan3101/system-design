#pragma once

#include <stdexcept>
#include "PlayStrategy.hpp"
#include "../models/Playlist.hpp"

class SequentialStrategy : public PlayStrategy {
    private:
        Playlist* currentPlaylist;
        int currentIndex;

    public:
        SequentialStrategy() {
            currentPlaylist = nullptr;
            currentIndex = -1;
        }

        void setPlaylist (Playlist* playlist) override {
            currentPlaylist = playlist;
            currentIndex = -1;
        }

        bool hasNext() override {
            return currentPlaylist && ((currentIndex + 1) < currentPlaylist->getSize());
        }

        Song* next() override {
            if(!currentPlaylist || currentPlaylist->getSize() == 0) {
                throw std::runtime_error("No playlist loaded or playlist is empty");
            }

            currentIndex = currentIndex + 1;
            return currentPlaylist -> getSongs()[currentIndex];
        }

        bool hasPrevious() override {
            return currentPlaylist && (currentIndex - 1 >= 0);
        }

        Song* previous() override {
            if(!currentPlaylist || currentPlaylist->getSize() == 0){
                throw std::runtime_error("No playlist loaded or playlist is empty");
            }

            if(hasPrevious()) {
                currentIndex = currentIndex - 1;
                return currentPlaylist -> getSongs()[currentIndex];
            }

            throw std::runtime_error("No previous songs found.");
        }

        ~SequentialStrategy() {
            // does not own playlist
            currentPlaylist = nullptr;
        }
};