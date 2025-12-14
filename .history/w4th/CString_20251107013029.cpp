#include "CString.h"

CString::~CString()
{
    if (_mang != nullptr)
    {
        delete[] _mang;
    }
}

CString::CString()
{
    _mang = nullptr;
}

CString::CString(const char *str)
{
    int len = strlen(str);
    _mang = new char[len + 1];
    strcpy_s(_mang, len + 1, str);
}

CString::CString(const CString &cs) : CString(cs._mang)
{
}
CString &CString::operator=(const CString &cs)
{
    cout << "The operator= was called." << endl;
    if (_mang != nullptr)
    {
        delete[] _mang;
    }
    int len = strlen(cs._mang) + 1;
    _mang = new char[len];
    strcpy_s(_mang, len, cs._mang);
    return *this;
}

ostream &operator<<(ostream &os, const CString &cs)
{
    os << cs._mang;
    return os;
}