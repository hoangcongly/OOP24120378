#include "LocalFileSong.h"

LocalFileSong:: LocalFileSong(): Song()
{
    filePath= "Unknown File Path";
}

LocalFileSong::LocalFileSong(const std::string& tit, const std::string& fp): Song(tit)
{
    filePath= fp;
}

LocalFileSong:: ~LocalFileSong(){}

void LocalFileSong::play() const
{
    std:: cout << "Playing: " << title << " from file " << filePath << std::endl;
}

Song* LocalFileSong::clone() const
{
    return new LocalFileSong(*this);
}