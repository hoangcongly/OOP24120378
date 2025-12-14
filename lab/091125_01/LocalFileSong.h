#ifndef LOCALFILESONG_H
#define LOCALFILESONG_H

#include <iostream>
#include "song.h"

class LocalFileSong: public Song
{
private:
    std:: string filePath;
public:
    LocalFileSong();
    LocalFileSong(const std:: string&title, const std:: string& filePath);
    virtual void play() const override;
    virtual Song* clone() const override;
};

#endif