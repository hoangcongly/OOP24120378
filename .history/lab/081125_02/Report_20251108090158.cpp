#include "Report.h"

Report::Report() : Document()
{
    const char *defContent = "Empty Content";
    content = new char[strlen(defContent) + 1];
    strcpy_s(content, strlen(defContent) + 1, defContent);
}