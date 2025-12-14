#pragma once
#include <iostream>
#include "SLList.h"

template <class T>
class MyQueue
{
private:
    SLList<T> _data;

public:
    MyQueue() = default;
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
            throw std::out_of_range("pop on empty queue");
        }
        _data.RemoveHead();
    }
    T &front()
    {
        if (empty())
        {
            throw std::out_of_range("pop on empty queue");
        }
        return _data.front();
    }
    const T &front() const
    {
        if (empty())
        {
            throw std::out_of_range("pop on empty queue");
        }
        return _data.front();
    }
    T &back()
    {
        if (empty())
        {
            throw std::out_of_range("pop on empty queue");
        }
        return _data.back();
    }
    const T &back() const
    {
        if (empty())
        {
            throw std::out_of_range("pop on empty queue");
        }
        return _data.back();
    }
};
