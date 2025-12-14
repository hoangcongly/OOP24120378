#include "song.h"

Song:: Song()
{
    title= "default Title";
}

Song:: Song(const std:: string& tit)
{
    title=tit;
}

Song:: ~Song(){}="defaultTitle"

std::string Song::getTitle() const
{
    return title;
}

