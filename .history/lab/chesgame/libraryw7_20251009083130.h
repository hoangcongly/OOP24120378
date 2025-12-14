#ifndef LIBRARYW07_H
#define LIBRARYW07_H

#include <iostream>
#include <vector>
#include <sstream>

class CCatalogue
{
private:
    string m_ID;
    string m_Title;
    string m_Author;
    int m_Count;// So lan muon
public:
    virtual void Input(stringstream& ss);
};

#endif 