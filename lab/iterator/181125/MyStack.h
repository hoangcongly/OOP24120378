#pragma once

#include <iostream>
#include "SLList.h"

template <class T>
class MyStack
{
private:
    SLList<T> _data;

public:
    MyStack() = default;
    bool empty() const
    {
        return _data.empty();
    }
    int size() const
    {
        return _data.size();
    }
    void push(const T &value)
    {
        _data.push_back(value);
    }
    void pop()
    {
        if (empty())
        {
            throw std::out_of_range("pop on empty stack");
        }
        _data.RemoveTail();
    }
    T &front()
    {
        if (empty())
        {
            throw std::out_of_range("pop on empty stack");
        }
        return _data.front();
    }
    const T &front() const
    {
        if (empty())
        {
            throw std::out_of_range("pop on empty stack");
        }
        return _data.front();
    }
    T &back()
    {
        if (empty())
        {
            throw std::out_of_range("pop on empty stack");
        }
        return _data.back();
    }
    const T &back() const
    {
        if (empty())
        {
            throw std::out_of_range("pop on empty stack");
        }
        return _data.back();
    }

    T &top()
    {
        return _data.back();
    }

    const T &top() const
    {
        return _data.back();
    }
};