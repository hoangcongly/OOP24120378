#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>
using namespace std;

class CString
{
private:
    char *_mang;

public:
    CString();
    CString(const char *);
    CString(const CString &);
    ~CString();

    char &operator[](const int &);
    CString &operator=(const CString &);
    friend ostream &operator<<(ostream &os, const CString &);
};
#endif
