#include "Report.h"

Report::Report() : Document(), reportAuthor()
{
    const char *defContent = "Empty Content";
    content = new char[strlen(defContent) + 1];
    strcpy_s(content, strlen(defContent) + 1, defContent);
}

Report::Report(const char *title, const char *authorName, const char *cont) : Document(title), reportAuthor(authorName)
{
    content = new char[strlen(cont) + 1];
    strcpy_s(content, strlen(cont) + 1, cont);
}

Report::~Report()
{
    delete[] content;
}

Report::Report(const Report &other) : Document(other), reportAuthor(other.reportAuthor)
{
    content = new char[strlen(other.content) + 1];
    strcpy_s(content, strlen(other.content) + 1, other.content);
}

Report &Report::operator=(const Report &other)
{
    if (this == &other)
    {
        return *this;
    }
    reportAuthor = other.reportAuthor;
    delete[] content;
    content = new char[strlen(other.content) + 1];
    strcpy_s(content, strlen(other.content) + 1, other.content);
    return *this;
}