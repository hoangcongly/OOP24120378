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
#endif