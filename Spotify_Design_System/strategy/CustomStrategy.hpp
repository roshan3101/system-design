#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include "../models/Playlist.hpp"
#include "PlayStrategy.hpp"

class CustomStrategy : public PlayStrategy {
private:
    Playlist* currentPlaylist;
    int currentIndex;
    queue<Song*> nextQueue;
    stack<Song*> prevStack;

    Song* nextSequential() {
        if (currentPlaylist->getSize() == 0) {
            throw std::runtime_error("Playlist is empty.");
        }
        currentIndex = currentIndex + 1;
        return currentPlaylist->getSongs()[currentIndex];
    }

    Song* previousSequential() {
        if (currentPlaylist->getSize() == 0) {
            throw std::runtime_error("Playlist is empty.");
        }
        currentIndex = currentIndex - 1;
        return currentPlaylist->getSongs()[currentIndex];
    }

public:
    CustomStrategy() {
        currentPlaylist = nullptr;
        currentIndex = -1;
    }

    void setPlaylist(Playlist* playlist) override {
        currentPlaylist = playlist;
        currentIndex = -1;
        while (!nextQueue.empty()) {
            nextQueue.pop();
        }
        while(!prevStack.empty()) {
            prevStack.pop();
        }
    }

    bool hasNext() override {
        return currentPlaylist && ((currentIndex + 1) < currentPlaylist->getSize());
    }

    Song* next() override {
        if (!currentPlaylist || currentPlaylist->getSize() == 0) {
            throw std::runtime_error("No playlist loaded or playlist is empty.");
        }

        if (!nextQueue.empty()) {
            Song* s = nextQueue.front();
            nextQueue.pop();
            prevStack.push(s);

            // update index to match queued song
            auto& list = currentPlaylist->getSongs();
            for (int i = 0; i < (int)list.size(); ++i) {
                if (list[i] == s) {
                    currentIndex = i;
                    break;
                }
            }
            return s;
        }

        return nextSequential();
    }

    bool hasPrevious() override {
        return currentPlaylist && (currentIndex - 1 >= 0);
    }

    Song* previous() override {
        if (!currentPlaylist || currentPlaylist->getSize() == 0) {
            throw std::runtime_error("No playlist loaded or playlist is empty.");
        }

        if (!prevStack.empty()) {
            Song* s = prevStack.top();
            prevStack.pop();

            auto& list = currentPlaylist->getSongs();
            for (int i = 0; i < (int)list.size(); ++i) {
                if (list[i] == s) {
                    currentIndex = i;
                    break;
                }
            }
            return s;
        }

        return previousSequential();
    }

    void addToNext(Song* song) override {
        if (!song) {
            throw std::runtime_error("Cannot enqueue null song.");
        }
        nextQueue.push(song);
    }
};