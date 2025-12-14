#ifndef STREAMEDSONG_H
#define STREAMEDSONG_H

#include <iostream>
#include "song.h"

class StreamedSong
{
private:
    std:: string url;
public:
    StreamedSong();
    StreamedSong(const std:: string& title, const std:: string&url);
    ~virtual StreamedSong();
    virtual void play() const override;
    virtual Song* clone() const override;
};

#endif