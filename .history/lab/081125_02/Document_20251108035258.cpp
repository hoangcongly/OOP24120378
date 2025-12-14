#include "Document.h"

Document::Document()
{
    const char *defaultTitle = "Untitled";
    title = new char[strlen(defaultTitle) + 1];
    strcpy_s(title, strlen(defaultTitle) + 1, defaultTitle);
}

Document::Document(const char *t)
{
    title = new char[strlen(t) + 1];
    strcpy_s(title, strlen(t) + 1, t);
}

Document::Document(const Document &other)
{
    title = new char[strlen(other.title) + 1];
    strcpy_s(title, strlen(other.title) + 1, other.title);
}