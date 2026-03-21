#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include "models/Song.hpp"
#include "managers/PlaylistManager.hpp"
#include "MusicPlayerFacade.hpp"

class MusicPlayerApplication {
private:
    static MusicPlayerApplication* instance;
    std::vector<Song*> songLibrary;
    MusicPlayerApplication() {}

public:
    static MusicPlayerApplication* getInstance() {
        if (!instance) {
            instance = new MusicPlayerApplication();
        }
        return instance;
    }

    void createSongInLibrary(const std::string& title, const std::string& artist,
                                const std::string& path) {
        Song* newSong = new Song(title, artist, path);
        songLibrary.push_back(newSong);
    }

    Song* findSongByTitle(const std::string& title) {
        for (Song* s : songLibrary) {
            if (s->getName() == title) {
                return s;
            }
        }
        return nullptr;
    }

    void createPlaylist(const std::string& playlistName) {
        PlaylistManager::getInstance()->createPlaylist(playlistName);
    }

    void addSongToPlaylist(const std::string& playlistName,
                            const std::string& songTitle) {
        Song* song = findSongByTitle(songTitle);
        if (!song) {
            throw std::runtime_error("Song \"" + songTitle + "\" not found in library.");
        }
        PlaylistManager::getInstance()
            ->addSongToPlaylist(playlistName, song);
    }

    void connectAudioDevice(DeviceType deviceType) {
        MusicPlayerFacade::getInstance()->connectDevice(deviceType);
    }

    void selectPlayStrategy(StrategyType strategyType) {
        MusicPlayerFacade::getInstance()->setPlayStrategy(strategyType);
    }

    void loadPlaylist(const std::string& playlistName) {
        MusicPlayerFacade::getInstance()->loadPlaylist(playlistName);
    }

    void playSingleSong(const std::string& songTitle) {
        Song* song = findSongByTitle(songTitle);
        if (!song) {
            throw std::runtime_error("Song \"" + songTitle + "\" not found.");
        }
        MusicPlayerFacade::getInstance()->playSong(song);
    }

    void pauseCurrentSong(const std::string& songTitle) {
        Song* song = findSongByTitle(songTitle);
        if (!song) {
            throw std::runtime_error("Song \"" + songTitle + "\" not found.");
        }
        MusicPlayerFacade::getInstance()->pauseSong(song);
    }

    void playAllTracksInPlaylist() {
        MusicPlayerFacade::getInstance()->playAllTracks();
    }

    void playPreviousTrackInPlaylist() {
        MusicPlayerFacade::getInstance()->playPreviousTrack();
    }

    void queueSongNext(const string& songTitle) {
        Song* song = findSongByTitle(songTitle);
        if (!song) {
            throw std::runtime_error("Song \"" + songTitle + "\" not found.");
        }
        MusicPlayerFacade::getInstance()->enqueueNext(song);
    }
};

MusicPlayerApplication* MusicPlayerApplication::instance = nullptr;