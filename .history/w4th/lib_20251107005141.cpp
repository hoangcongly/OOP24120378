#include "lib.h"

template <class T>
LinkedList<T>::LinkedList()
{
    _pHead = _pTail = nullptr;
    _n = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    _n = 0;
    Node<T> *node = _pHead;
    while (_pHead != nullptr)
    {
        _pHead = _pHead->pNext;
        delete node;
        node = _pHead;
    }
}

template <class T>
Node<T> *LinkedList<T>::CreateNode(const T &value)
{
    Node<T> *node = new Node<T>{value, nullptr};
    return node;
}
template <class T>
Node<T> *LinkedList<T>::AddHead(const T &value)
{
    Node<T> *node = CreateNode(value);
    if (node == nullptr)
    {
        return nullptr;
    }
    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
        _n++;
        return node;
    }
    node->pNext = _pHead;
    _pHead = node;
    _n++;
    return node;
}

template <class T>
Node<T> *LinkedList<T>::AddTail(const T &value)
{
    Node<T> *node = CreateNode(value);
    if (node == nullptr)
    {
        return nullptr;
    }
    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
        _n++;
        return node;
    }
    _pTail->pNext = node;
    _pTail = node;
    _n++;
    return node;
}

template <class T>
Node<T> *LinkedList<T>::RemoveHead()
{
    if (_pHead == nullptr)
    {
        return nullptr;
    }
    Node<T> *node = _pHead;
    _pHead = _pHead->pNext;
    _n--;
    if (_pHead == nullptr)
    {
        _pTail = nullptr;
    }
    return node;
}

template <class T>
Node<T> *LinkedList<T>::RemoveTail()
{
    if (_pHead == nullptr)
    {
        return nullptr;
    }
    Node<T> *node;
    _n--;
    if (_pHead == _pTail)
    {
        node = _pHead;
        _pHead = _pTail = nullptr;
        return node;
    }
    Node<T> *current = _pHead;
    while (current->pNext != _pTail)
    {
        current = current->pNext;
    }
    node = _pTail;
    _pTail = current;
    _pTail->pNext = nullptr;
    return node;
}

template <class T>
T &LinkedList<T>::operator[](const int &i)
{
    if (i < 0 || i >= _n)
    {
        throw exception("out of range");
    }
    Node<T> *current = _pHead;
    int count = i;
    while (count > 0)
    {
        current = current->pNext;
        count--;
    }
    return current->info;
}