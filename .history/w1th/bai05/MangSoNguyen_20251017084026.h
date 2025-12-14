#ifndef MANGSONGUYEN_H
#define MANGSONGUYEN_H

#include <iostream>
using namespace std;

class MangSoNguyen
{
private:
    int *arr;
    int Size;

public:
    MangSoNguyen();
    MangSoNguyen(int size);
    MangSoNguyen(int *arr, int size);
    MangSoNguyen(const MangSoNguyen &other);

    ~MangSoNguyen();
    void Xuat();
};

#endif