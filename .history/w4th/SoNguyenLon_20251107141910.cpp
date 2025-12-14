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
        Node *newNode = AddHead(digit);
        tempnum /= 10;
    }
}

SoNguyenLon::SoNguyenLon(const int &n1, const int &n2)
{
    pHead = pTail = nullptr;
    _n = 0;
    if (n1 == 0 || n2 <= 0)
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
        Node *newNode = AddHead(n1);
    }
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon &other)
{
    this->pHead = this->pTail = nullptr;
    this->_n = 0;
    Node *cur = other.pHead;
    while (cur != nullptr)
    {
        this->AddTail(cur->info);
        cur = cur->pNext;
    }
}

SoNguyenLon::~SoNguyenLon()
{
    _n = 0;
    Node *node = pHead;
    while (pHead != nullptr)
    {
        pHead = pHead->pNext;
        delete node;
        node = pHead;
    }
}
Node *SoNguyenLon::reveser()
{
    if (pHead == nullptr || pHead == pTail)
    {
        return pHead;
    }
    Node *prev = nullptr;
    Node *current = pHead;
    Node *next = nullptr;
    Node *oldHead = pHead;
    while (current != nullptr)
    {
        next = current->pNext;
        current->pNext = prev;
        prev = current;
        current = next;
    }
    pHead = prev;
    pTail = oldHead;
    return pHead;
}

SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon &snl)
{
    SoNguyenLon snl1_copy(*this);
    SoNguyenLon snl2_copy(snl);
    snl1_copy.reveser();
    snl2_copy.reveser();
    SoNguyenLon result;
    delete result.pHead;
    result.pHead = result.pTail = nullptr;
    result._n = 0;
    Node *cur1 = snl1_copy.pHead;
    Node *cur2 = snl2_copy.pHead;
    int carry = 0;
    while (cur1 != nullptr || cur2 != nullptr || carry != 0)
    {
        int digit1 = (cur1 != nullptr) ? cur1->info : 0;
        int digit2 = (cur2 != nullptr) ? cur2->info : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digresult = sum % 10;
        result.AddTail(digresult);
        if (cur1 != nullptr)
            cur1 = cur1->pNext;
        if (cur2 != nullptr)
            cur2 = cur2->pNext;
    }
    if (result.pHead == nullptr)
    {
        result.AddTail(0);
    }
    result.reveser();
    return result;
}

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon &snl)
{
    SoNguyenLon s1copy(*this);
    SoNguyenLon s2copy(snl);
    s1copy.reveser();
    s2copy.reveser();
    SoNguyenLon result;
    delete result.pHead;
    result.pHead = result.pTail = nullptr;
    result._n = 0;
    Node *cur1 = s1copy.pHead;
    Node *cur2 = s2copy.pHead;
    int borrow = 0;
    while (cur1 = nullptr)
    {
        int digit1 = cur1->info;
        int digit2 = (cur2 != nullptr) ? cur2->info : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result.AddTail(diff);
        cur1 = cur1->pNext;
        if (cur2 != nullptr)
            cur2 = cur2->pNext;
    }
    result.reveser();
    return result;
}

SoNguyenLon SoNguyenLon::operator*(const SoNguyenLon &snl)
{
    SoNguyenLon s1cop(*this);
    SoNguyenLon s2cop(snl);
}