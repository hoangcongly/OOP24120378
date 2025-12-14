#include "Author.h"

Author::Author()
{
    const char *defaultName = "Unknow";
    name = new char[strlen(defaultName) + 1];
    strcpy_s(name, strlen(defaultName) + 1, defaultName);
}

Author::Author(const char *n)
{
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
}

Author::~Author()
{
    delete[] name;
}

Author::Author(const Author &other)
{
    name = new char[strlen(other.name) + 1];
    strcpy_s(name, strlen(other.name) + 1, other.name);
}

Author &Author::operator=(const Author &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] name;
    name = new char[strlen(other.name) + 1];
    strcpy_s(name, strlen(other.name) + 1, other.name);
    return *this;
}

void Author::display() const
{
    std::cout << "Name: " << name << std::endl;
}