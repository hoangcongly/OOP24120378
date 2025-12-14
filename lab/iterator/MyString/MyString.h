#pragma once

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>
#include "SLList.h"

class MyString
{
private:
    SLList<char> _data;

public:
    class Iterator;

    MyString();
    MyString(const char *s);
    MyString(const MyString &other);
    MyString &operator=(const MyString &other);
    ~MyString();

    int size() const;
    bool empty() const;

    char &operator[](int index);
    const char &operator[](int index) const;

    char &at(int index);
    const char &at(int index) const;

    char front() const;
    char back() const;

    void push_back(char c);
    void clear();

    MyString &operator+=(const MyString &other);
    MyString &operator+=(char c);
    friend MyString operator+(const MyString &a, const MyString &b);
    friend bool operator==(const MyString &a, const MyString &b);
    friend bool operator!=(const MyString &a, const MyString &b);
    friend bool operator<(const MyString &a, const MyString &b);
    friend bool operator>(const MyString &a, const MyString &b);

    MyString substr(int pos, int len) const;
    int find(const MyString &pattern) const;

    friend std::ostream &operator<<(std::ostream &os, const MyString &s);
    friend std::istream &operator>>(std::istream &is, MyString &s);

    friend bool getline(std::istream &is, MyString &s);
    friend bool readFromFile(const char *filename, MyString &s);
    class Iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = char;
        using difference_type = std::ptrdiff_t;
        using pointer = char *;
        using reference = char &;

    private:
        SLList<char>::Iterator _it;
        friend class MyString;

        Iterator(const SLList<char>::Iterator &it) : _it(it) {}

    public:
        Iterator() {}
        reference operator*() const
        {
            return *_it;
        }
        pointer operator->() const
        {
            return &(*_it);
        }
        Iterator &operator++()
        {
            ++_it;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++_it;
            return temp;
        }

        bool operator==(const Iterator &other) const
        {
            return _it == other._it;
        }
        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }
    };

    Iterator begin()
    {
        return Iterator(_data.begin());
    }
    Iterator end()
    {
        return Iterator(_data.end());
    }
    Iterator begin() const
    {
        return Iterator(_data.begin());
    }
    Iterator end() const
    {
        return Iterator(_data.end());
    }
};
