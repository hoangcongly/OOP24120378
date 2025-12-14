#ifndef SONGUYENLON_H
#define SONGUYENLON_H

#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pNext;
};

class SoNguyenLon
{
private:
    Node *pHead, *pTail;
    int _n;
    static Node *CreateNode(const int &value);

public:
    SoNguyenLon();
    SoNguyenLon(const unsigned long long &num);
    SoNguyenLon(const int &n1, const int &n2);
    SoNguyenLon(const SoNguyenLon &other);
    Node *AddHead(const int &value);
    Node *AddTail(const int &value);
    ~SoNguyenLon();

    Node *reveser();
    SoNguyenLon operator+(const SoNguyenLon &snl);
    SoNguyenLon operator-(const SoNguyenLon &snl);
    SoNguyenLon operator*(const SoNguyenLon &snl);
    friend SoNguyenLon operator-(int num, const SoNguyenLon &snl);
    friend ostream &operator<<(ostream &os, const SoNguyenLon &snl);
};
#endif