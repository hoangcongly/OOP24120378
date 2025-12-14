#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include "Document.h"
#include "Author.h"
#include <cstring>  

class Report : Document
{
private:
    Author reportAuthor;
    char *content;

public:
    Report();
    Report(const char *title, const char *authorName, const char *cont);
    ~Report();
    Report(const Report &other);
    Report &operator=(const Report &other);

    void setContent(const char *newContent);
    virtual void display() const override;
};

#endif