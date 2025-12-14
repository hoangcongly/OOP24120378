#define NGAY_H
#ifndef NGAY_H

#include <iostream>
using namespace std;

class Ngay
{
private:
    int _ng, _th, _n;
    static int arrNgayCuaThang[][13];
    static bool LaNamNhuan(const int &n);

public:
    Ngay(/* args */);
    ~Ngay();
};

Ngay::Ngay(/* args */)
{
}

Ngay::~Ngay()
{
}

#endif