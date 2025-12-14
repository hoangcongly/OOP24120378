#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <cstring>

class Document
{
protected:
    char *title;

public:
    Document(/* args */);
    Document(const char *t);
    Document(const Document &other);
    Document &operator=(const Document &other);
    virtual ~Document();

    virtual void display() const;
};

#endif