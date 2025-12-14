#ifndef LIB_H
#define LIB_H

#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T info;
    Node *pNext;
};

template <class T>
class LinkedList
{
private:
    Node<T> *_pHead, *_pTail;
    int _n;
    static Node<T> *CreateNode(const T &);

public:
    LinkedList();
    ~LinkedList();

    Node<T> *AddHead(const T &);
    Node<T> *AddTail(const T &);
    Node<T> *RemoveHead();
    Node<T> *RemoveTail();

    T &operator[](const int &);

    template <class T>
    friend ostream &operator<<(ostream &os, const LinkedList<T> &);
};

#endif