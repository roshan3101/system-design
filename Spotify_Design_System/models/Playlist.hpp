#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Song.hpp"
using namespace std;

class Playlist {
    private:
        string name;
        vector<Song*> songs;

    public:
        Playlist(string name){
            this->name = name;
        }

        const string& getPlaylistName() const{
            return name;
        }
    
        void addSongToPlaylist(Song* song){
            songs.push_back(song);
        }

        void removeSongFromPlaylist(Song* song){
            songs.erase(remove(songs.begin(), songs.end(), song), songs.end());
        }

        const vector<Song*>& getSongs() const{
            return songs;
        }

        int getSongCount() const{
            return static_cast<int>(songs.size());
        }

        int getSize() const{
            return getSongCount();
        }
};