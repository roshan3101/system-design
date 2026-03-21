#pragma once

#include <string>
using namespace std;

class Song {
private:
    string name;
    string artist;
    string path;

public:
    Song(string name, string artist, string path){
        this->name = name;
        this->artist = artist;
        this->path = path;
    }

    string getName() const{
        return name;
    }
    
    string getArtist() const{
        return artist;
    }

    string getPath() const{
        return path;
    }

    void setName(string name){
        this->name = name;
    }

    void setArtist(string artist){
        this->artist = artist;
    }

    void setPath(string path){
        this->path = path;
    }
};