#pragma once

#include <iostream>
#include <stdexcept>
#include "SLList.h"

template <class T>
class MySet
{
private:
    SLList<T> _data;

public:
    class Iterator;
    MySet();
    MySet(const MySet<T> &other);
    MySet(const T *arr, int n);
    MySet &operator=(const MySet<T> &other);
    ~MySet();

    int size() const;
    bool empty() const;

    bool insert(const T &value);
    bool erase(const T &value);
    void erase(Iterator pos);
    void clear();

    bool contains(const T &value) const;
    Iterator find(const T &value) const;

    bool operator==(const MySet<T> &other) const;
    bool operator!=(const MySet<T> &other) const;
    bool operator<(const MySet<T> &other) const;
    bool operator>(const MySet<T> &other) const;

    class Iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;

    private:
        typename SLList<T>::Iterator _it;
        friend class MySet<T>;

        Iterator(const typename SLList<T>::Iterator &it) : _it(it) {}

    public:
        Iterator() : _it() {}
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
    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const MySet<U> &s);
};

template <class T>
MySet<T>::MySet() {}

template <class T>
MySet<T>::MySet(const MySet<T> &other)
{
    _data = other._data;
}

template <class T>
MySet<T>::MySet(const T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        insert(arr[i]);
    }
}

template <class T>
MySet<T> &MySet<T>::operator=(const MySet<T> &other)
{
    if (this != &other)
    {
        _data = other._data;
    }
    return *this;
}
template <class T>
MySet<T>::~MySet()
{
    clear();
}

template <class T>
int MySet<T>::size() const
{
    return _data.size();
}

template <class T>
bool MySet<T>::empty() const
{
    return _data.empty();
}
template <class T>
bool MySet<T>::insert(const T &value)
{
    if (_data.empty())
    {
        _data.push_back(value);
        return true;
    }
    auto it = _data.begin();
    auto itend = _data.end();
    for (; it != itend; ++it)
    {
        if (*it == value)
        {
            return false;
        }
        if (*it > value)
        {
            _data.insert(it, value);
            return true;
        }
    }
    _data.push_back(value);
    return true;
}

template <class T>
bool MySet<T>::erase(const T &value)
{
    Iterator it = find(value);
    if (it == end())
    {
        return false;
    }
    erase(it);
    return true;
}

template <class T>
void MySet<T>::erase(Iterator pos)
{
    int n = _data.size();
    if (n == 0)
        return;
    int idx = -1;
    int i = 0;
    for (auto it = begin(); it != end(); ++it, ++i)
    {
        if (it == pos)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        return;
    }
    for (int j = idx + 1; j < n; ++j)
    {
        _data[j - 1] = _data[j];
    }
    _data.RemoveTail();
}

template <class T>
void MySet<T>::clear()
{
    _data.Clear();
}

template <class T>
bool MySet<T>::contains(const T &value) const
{
    for (auto it = _data.begin(); it != _data.end(); ++it)
    {
        if (*it == value)
            return true;
    }
    return false;
}

template <class T>
typename MySet<T>::Iterator MySet<T>::find(const T &value) const
{
    for (auto it = _data.begin(); it != _data.end(); ++it)
    {
        if (*it == value)
            return Iterator(it);
    }
    return end();
}

template <class T>
bool MySet<T>::operator==(const MySet<T> &other) const
{
    if (_data.size() != other._data.size())
        return false;
    auto itA = _data.begin();
    auto itB = other._data.begin();
    auto endA = _data.end();
    while (itA != endA)
    {
        if (*itA != *itB)
            return false;
        ++itA;
        ++itB;
    }
    return true;
}

template <class T>
bool MySet<T>::operator!=(const MySet<T> &other) const
{
    return !(*this == other);
}

template <class T>
bool MySet<T>::operator<(const MySet<T> &other) const
{
    auto itA = _data.begin();
    auto itB = other._data.begin();
    auto endA = _data.end();
    auto endB = other._data.end();
    while (itA != endA && itB != endB)
    {
        if (*itA < *itB)
            return true;
        if (*itB < *itA)
            return false;
        ++itA;
        ++itB;
    }
    if (itA == endA && itB != endB)
        return true;
    return false;
}

template <class T>
bool MySet<T>::operator>(const MySet<T> &other) const
{
    return other < *this;
}
template <class U>
std::ostream &operator<<(std::ostream &os, const MySet<U> &s)
{
    typename MySet<U>::Iterator it = s.begin();
    typename MySet<U>::Iterator itEnd = s.end();

    os << "{ ";
    for (; it != itEnd; ++it)
    {
        os << *it;
        typename MySet<U>::Iterator next = it;
        ++next;
        if (next != itEnd)
            os << ", ";
    }
    os << " }";
    return os;
}
