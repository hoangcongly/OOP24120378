#pragma once

#include <iostream>
#include <stdexcept>
#include "SLList.h"

template <class T>
class MyVector
{
private:
    SLList<T> _data;

public:
    class Iterator;

    MyVector() {}
    MyVector(const MyVector &other) : _data(other._data) {}
    MyVector(const T *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            _data.push_back(arr[i]);
        }
    }
    MyVector<T> &operator=(const MyVector &other)
    {
        if (this != &other)
        {
            _data = other._data;
        }
        return *this;
    }
    ~MyVector() {}

    int size() const
    {
        return _data.size();
    }
    bool empty() const
    {
        return _data.empty();
    }

    T &operator[](int index)
    {
        return _data[index];
    }

    const T &operator[](int index) const
    {
        return _data[index];
    }

    T &at(int index)
    {
        if (index < 0 || index >= _data.size())
            throw std::out_of_range("MyVector::at index out of range");
        return _data[index];
    }

    const T &at(int index) const
    {
        if (index < 0 || index >= _data.size())
            throw std::out_of_range("MyVector::at index out of range");
        return _data[index];
    }

    T &front()
    {
        if (empty())
            throw std::out_of_range("front() on empty vector");
        return _data.front();
    }

    const T &front() const
    {
        if (empty())
            throw std::out_of_range("front() on empty vector");
        return _data.front();
    }

    T &back()
    {
        if (empty())
            throw std::out_of_range("back() on empty vector");
        return _data.back();
    }

    const T &back() const
    {
        if (empty())
            throw std::out_of_range("back() on empty vector");
        return _data.back();
    }

    void push_back(const T &value)
    {
        _data.push_back(value);
    }

    void pop_back()
    {
        if (empty())
            throw std::out_of_range("pop_back on empty vector");
        _data.RemoveTail();
    }

    void insert(Iterator pos, const T &value)
    {
        _data.insert(pos._it, value);
    }
    void erase(Iterator pos)
    {
        int n = _data.size();
        int idx = -1;
        int i = 0;
        for (auto it = _data.begin(); it != _data.end(); ++it, ++i)
        {
            if (it == pos._it)
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return;
        for (int j = idx + 1; j < n; ++j)
        {
            _data[j - 1] = _data[j];
        }
        _data.RemoveTail();
    }

    void Clear()
    {
        _data.Clear();
    }

    bool operator==(const MyVector &other) const
    {
        if (size() != other.size())
        {
            return false;
        }
        for (int i = 0; i < size(); ++i)
        {
            if (_data[i] != other._data[i])
                return false;
        }
        return true;
    }

    bool operator!=(const MyVector &other) const
    {
        return !(*this == other);
    }

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
        friend class MyVector<T>;
        Iterator(const typename SLList<T>::Iterator &it) : _it(it) {}

    public:
        Iterator() : _it() {}
        reference operator*() const { return *_it; }
        pointer operator->() const { return &(*_it); }
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