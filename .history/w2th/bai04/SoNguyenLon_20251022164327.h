#ifndef SONGUYENLON_H
#define SONGUYENLON_H

#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    int digit;
    Node *prev;
    Node *next;

    Node(int d) : digit(d), prev(nullptr), next(nullptr) {};
};
class SoNguyenLon
{
private:
public:
};

#endif