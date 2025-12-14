#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>
#include <cstring>
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
