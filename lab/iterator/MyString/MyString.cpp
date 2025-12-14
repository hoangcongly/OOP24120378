#include "MyString.h"

MyString::MyString() {}
MyString::MyString(const char *s)
{
    if (s != nullptr)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            _data.push_back(s[i]);
        }
    }
}
MyString::MyString(const MyString &other)
{
    _data = other._data;
}
MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        _data = other._data;
    }
    return *this;
}
MyString::~MyString()
{
    _data.Clear();
}
int MyString::size() const
{
    return _data.size();
}
bool MyString::empty() const
{
    return _data.empty();
}
char &MyString::operator[](int index)
{
    return _data[index];
}
const char &MyString::operator[](int index) const
{
    return _data[index];
}
char &MyString::at(int index)
{
    if (index < 0 || index >= size())
    {
        throw std::out_of_range("MyString::at index out of range");
    }
    return _data[index];
}
const char &MyString::at(int index) const
{
    if (index < 0 || index >= size())
    {
        throw std::out_of_range("MyString::at index out of range");
    }
    return _data[index];
}
char MyString::front() const
{
    if (empty())
        throw std::out_of_range("MyString::front on empty string");
    return _data.front();
}
char MyString::back() const
{
    if (empty())
        throw std::out_of_range("MyString::back on empty string");
    return _data.back();
}
void MyString::push_back(char c)
{
    _data.push_back(c);
}
void MyString::clear()
{
    _data.Clear();
}
MyString &MyString::operator+=(const MyString &other)
{
    for (int i = 0; i < other._data.size(); i++)
    {
        _data.push_back(other._data[i]);
    }
    return *this;
}
MyString &MyString::operator+=(char c)
{
    _data.push_back(c);
    return *this;
}
MyString operator+(const MyString &a, const MyString &b)
{
    MyString res = a;
    res = res + b;
    return res;
}
bool operator==(const MyString &a, const MyString &b)
{
    if (a._data.size() != b._data.size())
        return false;
    for (int i = 0; i < a._data.size(); i++)
    {
        if (a._data[i] != b._data[i])
            return false;
    }
    return true;
}
bool operator!=(const MyString &a, const MyString &b)
{
    return !(a == b);
}
bool operator<(const MyString &a, const MyString &b)
{
    if (a._data.size() > b._data.size())
        return false;
    else if (a._data.size() < b._data.size())
        return true;
    else
    {
        for (int i = 0; i < a._data.size(); ++i)
        {
            if (a._data[i] > b._data[i])
                return false;
        }
    }
    return true;
}
bool operator>(const MyString &a, const MyString &b)
{
    return b < a;
}

MyString MyString::substr(int pos, int len) const
{
    MyString sub;
    int n = size();
    if (pos < 0 || len < 0 || pos > n || pos + len > n)
    {
        throw std::out_of_range("MyString::substr out of range");
    }
    for (int i = pos; i < pos + len; i++)
    {
        sub.push_back(_data[i]);
    }
    return sub;
}

int MyString::find(const MyString &pattern) const
{
    int n = size();
    int m = pattern.size();
    if (m == 0)
        return 0;
    if (m > n)
        return -1;
    for (int i = 0; i < n - m; i++)
    {
        bool ok = true;
        for (int j = 0; j < m; j++)
        {
            if (_data[i + j] != pattern._data[j])
            {
                ok = false;
                break;
            }
        }
        // abcdasdkj// ptt= asd, i duyet tu 0 den 6
        if (ok == true)
        {
            return i;
        }
    }
    return -1;
}

std::ostream &operator<<(std::ostream &os, const MyString &s)
{
    if (s != nullptr)
    {
        for (int i = 0; i < s.size(); i++)
        {
            os << s._data[i];
        }
    }
    return os;
}

std::istream &operator>>(std::istream &is, MyString &s)
{
    s.clear();
    char c;
    while (is.get(c))
    {
        if (!isspace(c))
        {
            s.push_back(c);
            break;
        }
    }
    while (is.get(c))
    {
        if (isspace(c))
            break;
        s.push_back(c);
    }
    return is;
}

bool getline(std::istream &is, MyString &s)
{
    s.clear();
    char c;

    if (!is.get(c))
        return false; // EOF

    while (c != '\n' && !is.eof())
    {
        s.push_back(c);
        if (!is.get(c))
            break;
    }

    return true;
}

#include <fstream>

bool readFromFile(const char *filename, MyString &s)
{
    std::ifstream fi(filename);
    if (!fi.is_open())
        return false;

    s.clear();
    char c;

    while (fi.get(c))
    {
        s.push_back(c);
    }

    fi.close();
    return true;
}
