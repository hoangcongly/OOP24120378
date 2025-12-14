#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include "song.h"

class Playlist
{
private:
    std:: string name;
    Song** SongList;
    int songCount;
    int capacity;

public:
    Playlist(const std:: string& name, int capacity=10);
    virtual ~Playlist();
    Playlist(const Playlist&other);
    void addSong(Song*song);
    void playAll() const;   
    void displayInfo() const;    
};

#endif