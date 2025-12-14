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
    MangSoNguyen(const int &size);
    MangSoNguyen(const int *arr_other, const int &size);
    MangSoNguyen(const MangSoNguyen &other);

    ~MangSoNguyen();
    int getSize() const;
    void Xuat();
};

#endif