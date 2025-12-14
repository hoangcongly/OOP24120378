#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <iostream>
using namespace std;

class ThoiGian
{
private:
    int _gio, _phut, _giay;
    void ChuanHoa();
public:
    ThoiGian();
    ThoiGian(const int& , const int& , const int& );
    ThoiGian(const int&, const int&);
    ThoiGian(const int&);
    ~ThoiGian();
    void Xuat();
};

#endif //THOIGIAN_H