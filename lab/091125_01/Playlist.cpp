#include "Playlist.h"

Playlist::Playlist() : name("default Name"), songCount(0), capacity(10)
{
    SongList= new Song*[capacity];
}

Playlist:: Playlist(const std:: string& name, int capaciy): name(name), songCount(0), capacity(capacity)
{
    SongList= new Song*[capacity];
}

Playlist::  ~Playlist()
{
    for(int i=0; i<songCount; i++)
    {
        delete SongList[i];
    }
    delete[] SongList;
}

Playlist:: Playlist(const Playlist&other)
{
    name= other.name;
    songCount= other.songCount;
    capacity= other.capacity;
    SongList= new Song*[capacity];
    for(int i=0; i<songCount; i++)
    {
        SongList[i]= other.SongList[i];
    }
}

Playlist& Playlist:: operator=(const Playlist&other)
{
    if(this==&other)
    {
        return*this;
    }
    for(int i=0; i<songCount; i++)
    {
        delete SongList[i];
    }
    delete[] SongList;

    name= other.name;
    songCount= other.songCount;
    capacity= other.capacity;

    SongList= new Song*[capacity];
    for(int i=0; i<songCount; i++)
    {
        SongList[i]= other.SongList[i];
    }
    return*this;
}

void Playlist:: addSong(Song*song)
{
    if(songCount<capacity)
    {
        Playlist[songCount]= song;
        songCount++;
    }
    else
    {
        std::cout << "Playlist is full. Deleting song." << std::endl;
        delete song;
    }
}

void Playlist:: playAll() const
{
    for( int i=0; i<songCount; i++)
    {
        SongList[i]->play();
    }
}

void Playlist::displayInfo() const
{
    std::cout << "Playlist: " << name << " (" << songCount << "/" << capacity << ")" << std::endl;
    for (int i = 0; i < songCount; ++i) {
        std::cout << "  " << (i + 1) << ". " << songList[i]->getTitle() << std::endl;
    }
}