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
    class Iterator
    {
    private:
        Node *m_ptr;
        Iterator(Node *ptr) : m_ptr(ptr) {}
        friend class MyStack;

    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = int;
        using value_type = T;
        using pointer = T *;
        using reference = T &;

        reference operator*() const { return m_ptr->data; }
        referecce operator->() const { return &(m_ptr->data;) }
        Iterator &operator++()
        {
            if (m_ptr)
            {
                m_ptr = m_ptr->next;
            }
            return *this;
        }
        Iterator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        friend bool operator==(const Iterator &a, const Iterator &b)
        {
            return a.m_ptr == b.m_ptr;
        }
        friend bool operator!=(const Iterator &a, const Iterator &b)
        {
            return a.m_ptr != b.m_ptr;
        }
    };
};

#endif /// !MYSTACK_H