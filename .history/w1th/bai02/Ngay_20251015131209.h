#ifndef NGAY_H
#define NGAY_H

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Ngay
{
private: 
    int _ng, _th, _n;
    void ChuanHoa();
public:
    Ngay();
    Ngay(const int&);
    Ngay(const int&, const int&, const int&);
    Ngay(const char*s);
    ~Ngay();
    void Xuat();
};
#endif //NGAY_H