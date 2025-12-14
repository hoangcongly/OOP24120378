#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

class Song
{
protected:
    std:: string title;

public:
    Song();
    Song(const std::string& tit);
    virtual ~Song();
    std:: string getTitle() const;
    virtual void play() const=0;
    virtual Song* clone() const=0;
};

#endif