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
    Node *pHead, *PTail;
    int _n;
    static Node *CreateNode(const int &value);

public:
    SoNguyenLon();
    SoNguyenLon(const long long &num);
    SoNguyenLon(const int &n1, const int &n2);
    ~SoNguyenLon();

    SoNguyenLon operator+(const SoNguyenLon &snl);
    SoNguyenLon operator-(const SoNguyenLon &snl);
};
#endif