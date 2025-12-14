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
MyStack<T>::MyStack() : m_Top(nullptr), m_size(0) {}

template <typename T>
MyStack<T>::~MyStack()
{
    clear();
}

template <typename T>
MyStack<T>::MyStack(const MyStack &other) : m_Top(nullptr), m_size(0)
{
    MyStack<T> tempStack;
    Node *current = other.m_Top;
    while (current != nullptr)
    {
        tempStack.push(current);
        current = current->next;
    }
    while (!empty(tempStack))
    {
        this->push(tempStack.top());
        tempStack.pop();
    }
}

template <typename T>
MyStack<T> &MyStack::operator=(const MyStack &other)
{
    if(this== &other)
    {
        return *this;
    }
    clear();
    MyStack<T> tempStack;
    Node *current = other.m_Top;
    while (current != nullptr)
    {
        tempStack.push(current);
        current = current->next;
    }
    while (!empty(tempStack))
    {
        this->push(tempStack.top());
        tempStack.pop();
    }
    return *this;
}