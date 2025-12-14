#ifndef SLLIST_H
#define SLLIST_H

#include <iostream>
#include <stdexcept>
#include <iterator>
#include <cstddef>

template <class T>
class SLList
{
private:
    struct Node
    {
        T _info;
        Node *_pNext;

        Node(const T &value, Node *next = nullptr)
            : _info(value), _pNext(next) {}
    };

    Node *_pHead;
    Node *_pTail;
    int _n;

    static Node *CreateNode(const T &value)
    {
        return new Node(value);
    }

public:
    class Iterator;

    SLList();
    SLList(const SLList &other);
    SLList &operator=(const SLList &other);
    ~SLList();

    void AddHead(const T &value);
    void push_back(const T &value);
    void insert(Iterator it, const T &value);
    void RemoveHead();
    void RemoveTail();
    void Clear();

    int size() const;
    bool empty() const;

    T &operator[](int index);
    const T &operator[](int index) const;

    T &front();
    const T &front() const;

    T &back();
    const T &back() const;

    Iterator begin() { return Iterator(_pHead); }
    Iterator end() { return Iterator(nullptr); }

    Iterator begin() const { return Iterator(_pHead); }
    Iterator end() const { return Iterator(nullptr); }

    // template <class U>
    // friend std::ostream &operator<<(std::ostream &os, const SLList<U> &ll)
    // {
    //     typename SLList<U>::Node *node = ll._pHead;
    //     while (node != nullptr)
    //     {
    //         os << node->_info;
    //         node = node->_pNext;
    //         if (node != nullptr)
    //             os << ", ";
    //     }
    //     return os;
    // }

    class Iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;

    private:
        Node *current_node;
        Iterator(Node *node) : current_node(node) {}
        friend class SLList<T>;

    public:
        Iterator() : current_node(nullptr) {}

        reference operator*() const
        {
            if (!current_node)
            {
                throw std::out_of_range("Dereferencing end() or null iterator");
            }
            return current_node->_info;
        }

        pointer operator->() const
        {
            if (!current_node)
            {
                throw std::out_of_range("Accessing member via end() or null iterator");
            }
            return &(current_node->_info);
        }

        Iterator &operator++()
        {
            if (!current_node)
            {
                throw std::out_of_range("Incrementing end() or null iterator");
            }
            current_node = current_node->_pNext;
            return *this;
        }

        Iterator operator++(int)
        {
            if (!current_node)
            {
                throw std::out_of_range("Incrementing end() or null iterator");
            }
            Iterator temp = *this;
            current_node = current_node->_pNext;
            return temp;
        }

        bool operator==(const Iterator &other) const
        {
            return current_node == other.current_node;
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }
    };
};

// ================== IMPLEMENTATION ==================

template <class T>
SLList<T>::SLList()
    : _pHead(nullptr), _pTail(nullptr), _n(0)
{
}

template <class T>
SLList<T>::SLList(const SLList<T> &other)
    : _pHead(nullptr), _pTail(nullptr), _n(0)
{
    Node *cur = other._pHead;
    while (cur != nullptr)
    {
        this->push_back(cur->_info);
        cur = cur->_pNext;
    }
}

template <class T>
SLList<T> &SLList<T>::operator=(const SLList<T> &other)
{
    if (this == &other)
        return *this;

    Clear();
    Node *cur = other._pHead;
    while (cur != nullptr)
    {
        this->push_back(cur->_info);
        cur = cur->_pNext;
    }
    return *this;
}

template <class T>
SLList<T>::~SLList()
{
    Clear();
}

template <class T>
void SLList<T>::Clear()
{
    while (_pHead != nullptr)
    {
        Node *cur = _pHead;
        _pHead = _pHead->_pNext;
        delete cur;
    }
    _pTail = nullptr;
    _n = 0;
}

template <class T>
int SLList<T>::size() const
{
    return _n;
}

template <class T>
bool SLList<T>::empty() const
{
    return _n == 0;
}

template <class T>
void SLList<T>::AddHead(const T &value)
{
    Node *node = CreateNode(value);
    node->_pNext = _pHead;
    _pHead = node;
    if (_pTail == nullptr)
    {
        _pTail = node;
    }
    ++_n;
}

template <class T>
void SLList<T>::push_back(const T &value)
{
    Node *node = CreateNode(value);
    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
    }
    else
    {
        _pTail->_pNext = node;
        _pTail = node;
    }
    ++_n;
}

template <class T>
void SLList<T>::insert(Iterator it, const T &value)
{
    Node *node = it.current_node;

    // chèn vào đầu
    if (node == _pHead)
    {
        AddHead(value);
        return;
    }

    // tìm node trước đó
    Node *prev_node = _pHead;
    while (prev_node != nullptr && prev_node->_pNext != node)
    {
        prev_node = prev_node->_pNext;
    }
    if (prev_node == nullptr)
    {
        // không tìm được vị trí (it không thuộc list này) -> bỏ qua
        return;
    }

    Node *newNode = CreateNode(value);
    newNode->_pNext = prev_node->_pNext;
    prev_node->_pNext = newNode;

    if (node == nullptr) // chèn trước end() => newNode là node cuối
    {
        _pTail = newNode;
    }

    ++_n;
}

template <class T>
void SLList<T>::RemoveHead()
{
    if (_pHead == nullptr)
        return;

    Node *temp = _pHead;
    _pHead = _pHead->_pNext;
    delete temp;
    --_n;

    if (_pHead == nullptr)
        _pTail = nullptr;
}

template <class T>
void SLList<T>::RemoveTail()
{
    if (_pHead == nullptr)
        return;

    if (_pHead->_pNext == nullptr)
    {
        delete _pHead;
        _pHead = _pTail = nullptr;
        _n = 0;
        return;
    }

    Node *cur = _pHead;
    while (cur->_pNext != nullptr && cur->_pNext->_pNext != nullptr)
    {
        cur = cur->_pNext;
    }

    Node *temp = cur->_pNext;
    cur->_pNext = nullptr;
    delete temp;
    _pTail = cur;
    --_n;
}

template <class T>
T &SLList<T>::operator[](int index)
{
    if (index < 0 || index >= _n)
    {
        throw std::out_of_range("Index out of range");
    }
    Node *cur = _pHead;
    for (int i = 0; i < index; ++i)
    {
        cur = cur->_pNext;
    }
    return cur->_info;
}

template <class T>
const T &SLList<T>::operator[](int index) const
{
    if (index < 0 || index >= _n)
    {
        throw std::out_of_range("Index out of range");
    }
    Node *cur = _pHead;
    for (int i = 0; i < index; ++i)
    {
        cur = cur->_pNext;
    }
    return cur->_info;
}

template <class T>
T &SLList<T>::front()
{
    if (_pHead == nullptr)
        throw std::out_of_range("Accessing front() on empty list");
    return _pHead->_info;
}

template <class T>
const T &SLList<T>::front() const
{
    if (_pHead == nullptr)
        throw std::out_of_range("Accessing front() on empty list");
    return _pHead->_info;
}

template <class T>
T &SLList<T>::back()
{
    if (_pTail == nullptr)
        throw std::out_of_range("Accessing back() on empty list");
    return _pTail->_info;
}

template <class T>
const T &SLList<T>::back() const
{
    if (_pTail == nullptr)
        throw std::out_of_range("Accessing back() on empty list");
    return _pTail->_info;
}

#endif // SLLIST_H
