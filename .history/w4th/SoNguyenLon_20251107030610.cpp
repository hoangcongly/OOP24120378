#include "SoNguyenLon.h"

Node *SoNguyenLon::CreateNode(const int &value)
{
    Node *node = new Node();
    node->info = value;
    node->pNext = nullptr;
    return node;
}

SoNguyenLon::SoNguyenLon()
{
    pHead = pTail = nullptr;
    _n = 0;
    Node *zeroNode = CreateNode(0);
    if (zeroNode != nullptr)
    {
        pHead = pTail = zeroNode;
        _n = 1;
    }
}

Node *SoNguyenLon::AddHead(const int &value)
{
    Node *newNode = CreateNode(value);
    if (newNode == nullptr)
    {
        return nullptr;
    }
    if (pHead == nullptr)
    {
        pHead = pTail = newNode;
    }
    else
    {
        newNode->pNext = pHead;
        pHead = newNode;
    }
    _n++;
    return newNode;
}

Node *SoNguyenLon::AddTail(const int &value)
{
    Node *newNode = CreateNode(value);
    if (newNode == nullptr)
    {
        return nullptr;
    }
    if (pHead == nullptr)
    {
        pHead = pTail = newNode;
    }
    else
    {
        pTail->pNext = newNode;
        pTail = newNode;
    }
    _n++;
    return newNode;
}

SoNguyenLon::SoNguyenLon(const unsigned long long &num)
{
    pHead = pTail = nullptr;
    _n = 0;
    unsigned long long tempnum = num;
    if (tempnum <= 0)
    {
        Node *newNode = CreateNode(0);
        if (newNode != nullptr)
        {
            pHead = pTail = newNode;
            _n = 1;
        }
        return;
    }
    while (tempnum > 0)
    {
        int digit = tempnum % 10;
        Node* newNode= AddHead(digit);
        tempnum /= 10;
    }
}

SoNguyenLon::SoNguyenLon(const int &n1, const int &n2)
{
    pHead = pTail = nullptr;
    _n = 0;
    if (n1 == 0 || n2 == 0)
    {
        Node *newNode = CreateNode(0);
        if (newNode != nullptr)
        {
            pHead = pTail = newNode;
            _n = 1;
        }
        return;
    }
    while (_n < n2)
    {
        Node* newNode= AddHead(n1);
    }
}