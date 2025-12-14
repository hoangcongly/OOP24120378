#include "MyStack.h"

template <typename T>
void MyStack<T>::clear()
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
MyStack<T> & MyStack<T>::operator=(const MyStack &other)
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

template<typename T>
void MyStack<T>:: push(const T& value)
{
    Node*newNode= new Node(value,m_Top);
    m_Top= newNode;
    m_size++;
}

template<typename T>
void MyStack<T>:: pop()
{
    if(empty()) return;
    Node*nodeDel= m_Top;
    m_Top=m_Top->next;
    delete nodeDel;
    m_size--;
}

template<typename T>
T& MyStack<T>::top()
{
    if(empty())
    {
        cerr << "Error: Calling top from empty Stack!!!!";
        exit(EXIT_FAILURE);
    }
    return m_Top->data;
}

template<typename T>
const T&MyStack<T>::top() const
{
    if(empty())
    {
        cerr << "Error: Calling top from empty Stack!!!!";
        exit(EXIT_FAILURE);
    }
    return m_Top->data;
}

template<typename T>
typename MyStack<T>:: Iterator MyStack<T>:: begin()
{
    return Iterator(m_Top);
}

template<typename T>
typename MyStack<T>::Iterator MyStack<T>:: end()
{
    return Iterator(nullptr);
}

template<typename T>
bool MyStack<T>:: empty() const
{
    return m_Top==nullptr;
}

template<typename T>
unsigned long MyStack<T>::size() const
{
    return m_size;
}

template class MyStack<int>;
template class MyStack<double>;
template class MyStack<const char*>;