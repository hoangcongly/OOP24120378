#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class MyStack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &val, Node *n = nullptr) : data(val), next(n) {};
    };
    Node *m_Top;
    unsigned long m_size;
    void clear();

public:
    MyStack(/* args */);
    ~MyStack();
};

MyStack::MyStack(/* args */)
{
}

MyStack::~MyStack()
{
}

#endif /// !MYSTACK_H