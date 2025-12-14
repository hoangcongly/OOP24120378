#include "lib.h"

template <class T>
LinkedList<T>::LinkedList()
{
    _pHead = _pTail = nullptr;
    _n = 0;
}