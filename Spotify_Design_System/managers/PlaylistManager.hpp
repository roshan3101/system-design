#pragma once

#include <string>
#include <map>
#include <iostream>
#include <stdexcept>

#include "../models/Playlist.hpp"
#include "../models/Song.hpp"

class PlaylistManager {
    private:
        static PlaylistManager* instance;
        std::map<std::string, Playlist*> playlists;
        PlaylistManager() = default;

    public:
        static PlaylistManager* getInstance() {
            if(instance == nullptr) {
                instance = new PlaylistManager();
            }
            return instance;
        }

        void createPlaylist(const std::string& name) {
            if(playlists.find(name) != playlists.end()) {
                throw std::runtime_error("Playlist with this name already exists");
            }

            playlists[name] = new Playlist(name);
            std::cout << "Playlist " << name << " created" << std::endl;
        }

        void addSongToPlaylist(const std::string& playlistName, Song* song) {
            if(playlists.find(playlistName) == playlists.end()) {
                throw std::runtime_error("Playlist with this name does not exist");
            }

            playlists[playlistName]->addSongToPlaylist(song);
            std::cout << "Song " << song->getName() << " added to playlist " << playlistName << std::endl;
        }

        Playlist* getPlaylist(const std::string& playlistName) {
            if(!playlists.count(playlistName)) {
                throw std::runtime_error("Playlist with this name does not exist");
            }
            return playlists[playlistName];
        }

        ~PlaylistManager() {
            for(auto& kv : playlists) {
                auto* playlist = kv.second;
                delete playlist;
            }
            playlists.clear();
            instance = nullptr;
        }
};

PlaylistManager* PlaylistManager::instance = nullptr;