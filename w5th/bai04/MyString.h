#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include "SLList.h"
using namespace std;

class MyString
{
private:
    SLList<char> lKT;

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &mst);
    ~MyString();
    MyString &operator=(const MyString &mst);
    MyString operator+(MyString mst) const;
    int length() const;
    SLList<MyString> Split(const SLList<char> &delimiters, bool keepEmptyEntries) const;

    friend MyString operator+(const char *s, const MyString &ms);
    friend ostream &operator<<(ostream &os, const MyString &ms);
};

#endif