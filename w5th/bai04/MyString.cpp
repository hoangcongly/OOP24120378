#include "MyString.h"

MyString::MyString()
{
}

MyString::MyString(const char *s)
{
    if (s != nullptr)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            lKT.push_back(s[i]);
        }
    }
}

MyString::MyString(const MyString &mst)
{
    this->lKT = mst.lKT;
}

MyString::~MyString()
{
    lKT.Clear();
}

MyString &MyString::operator=(const MyString &mst)
{
    if (this == &mst)
    {
        return *this;
    }
    lKT.Clear();
    this->lKT = mst.lKT;
    return *this;
}

MyString MyString::operator+(MyString mst) const
{
    MyString newString(*this);
    for (auto it = mst.lKT.begin(); it != mst.lKT.end(); ++it)
    {
        newString.lKT.push_back(*it);
    }
    return newString;
}

int MyString::length() const
{
    return lKT.size();
}

SLList<MyString> MyString::Split(const SLList<char> &delimiters, bool keepEmptyEntries) const
{
    SLList<MyString> resultList;
    MyString current;
    for (auto it = this->lKT.begin(); it != this->lKT.end(); ++it)
    {
        char currentChar = *it;
        if (delimiters.Contains(currentChar))
        {
            if (keepEmptyEntries == false || current.length() > 0)
            {
                resultList.push_back(current);
            }
            current.lKT.Clear();
        }
        else
        {
            current.lKT.push_back(currentChar);
        }
    }
    if (keepEmptyEntries == false || current.length() > 0)
    {
        resultList.push_back(current);
    }
    return resultList;
}

MyString operator+(const char *s, const MyString &ms)
{
    return MyString(s) + ms;
}

ostream &operator<<(ostream &os, const MyString &ms)
{
    for (auto it = ms.lKT.begin(); it != ms.lKT.end(); ++it)
    {
        os << *it;
    }
    return os;
}
