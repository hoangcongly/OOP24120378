#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <cstring>
class Author
{
private:
    char *name;

public:
    Author(/* args */);
    Author(const char *n);
    Author(const Author &other);
    Author &operator=(const Author &other);
    ~Author();

    void display() const;
};

#endif