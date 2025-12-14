#include "Report.h"

Report::Report() : Document()
{
    const char *defContent = "Empty Content";
    content = new char[strlen(defContent) + 1];
    strcpy_s(content, strlen(defContent) + 1, defContent);
}

Report::Report(const char*title, const char*authorName, const char*cont): Document(title)
{
    content= new char[strlen(cont)+1];
    strcpy_s(content, strlen(cont)+1 ,cont);
    reportAuthor(authorName);
}