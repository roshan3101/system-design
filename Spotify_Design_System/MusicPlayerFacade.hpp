#pragma once

#include "core/AudioEngine.hpp"
#include "models/Playlist.hpp"
#include "models/Song.hpp"
#include "strategy/PlayStrategy.hpp"
#include "enums/DeviceType.hpp"
#include "enums/StrategyType.hpp"
#include "managers/DeviceManager.hpp"
#include "managers/PlaylistManager.hpp"
#include "managers/StrategyManager.hpp"

using namespace std;

class MusicPlayerFacade {
private:
    static MusicPlayerFacade* instance;
    AudioEngine* audioEngine;
    Playlist* loadedPlaylist;
    PlayStrategy* playStrategy;

    MusicPlayerFacade() {
        loadedPlaylist = nullptr;
        playStrategy   = nullptr;
        audioEngine = new AudioEngine();
    }

    ~MusicPlayerFacade() {
        delete audioEngine;
        loadedPlaylist = nullptr;
        playStrategy = nullptr;
    }

public:
    static MusicPlayerFacade* getInstance() {
        if (!instance) {
            instance = new MusicPlayerFacade();
        }
        return instance;
    }

    void connectDevice(DeviceType deviceType) {
        DeviceManager::getInstance()->connect(deviceType);
    }

    void setPlayStrategy(StrategyType strategyType) {
        playStrategy = StrategyManager::getInstance()->getStrategy(strategyType);
    }

    void loadPlaylist(const std::string& name) {
        loadedPlaylist = PlaylistManager::getInstance()->getPlaylist(name);
        if (!playStrategy) {
            throw std::runtime_error("Play strategy not set before loading.");
        }
        playStrategy->setPlaylist(loadedPlaylist);
    }
    
    void playSong(Song* song) {
        if (!DeviceManager::getInstance()->hasOutputDevice()) {
            throw std::runtime_error("No audio device connected.");
        }
        IAudioDevice* device = DeviceManager::getInstance()->getCurrentDevice();
        audioEngine->play(device, song);
    }

    void pauseSong(Song* song) {
        if (audioEngine->getCurrentSongName() != song->getName()) {
            throw std::runtime_error("Cannot pause \"" + song->getName() + "\"; not currently playing.");
        }
        audioEngine->pause();
    }

    void playAllTracks() {
        if (!loadedPlaylist) {
            throw std::runtime_error("No playlist loaded.");
        }
        while (playStrategy->hasNext()) {
            Song* nextSong = playStrategy->next();
            IAudioDevice* device = DeviceManager::getInstance()->getCurrentDevice();
            audioEngine->play(device, nextSong);
        }
        std::cout << "Completed playlist: " << loadedPlaylist->getPlaylistName() << "\n";
    }

    void playNextTrack() {
        if (!loadedPlaylist) {
            throw std::runtime_error("No playlist loaded.");
        }
        if(playStrategy->hasNext()) {
            Song* nextSong = playStrategy->next();
            IAudioDevice* device = DeviceManager::getInstance()->getCurrentDevice();
            audioEngine->play(device, nextSong);
        }
        else {
            std::cout << "Completed playlist: " << loadedPlaylist->getPlaylistName() << "\n";
        }
    }

    void playPreviousTrack() {
        if (!loadedPlaylist) {
            throw std::runtime_error("No playlist loaded.");
        }
        if(playStrategy->hasPrevious()) {
            Song* prevSong = playStrategy->previous();
            IAudioDevice* device = DeviceManager::getInstance()->getCurrentDevice();
            audioEngine->play(device, prevSong);
        }
        else {
            std::cout << "Completed playlist: " << loadedPlaylist->getPlaylistName() << "\n";
        }
    }

    void enqueueNext(Song* song) {
        playStrategy->addToNext(song);
    }
};

MusicPlayerFacade* MusicPlayerFacade::instance = nullptr;
    