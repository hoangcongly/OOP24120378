#include <MyStack.h>

template <typename T>
void MyStack::clear()
{
    while (!empty())
    {
        pop();
    }
}

template <typename T>
MyStack<T>::MyStack() : m_top(nullptr), m_size(0) {}
