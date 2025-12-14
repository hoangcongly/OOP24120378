#ifndef NGAY_H
#define NGAY_H

#include <iostream>
using namespace std;
class Ngay
{
private:
    int _ng, _th, _n;
    void ChuanHoaNgay();
    static int arrNgayCuaThang[][13];
    static bool LaNamNhuan(const int &n);
    int demSoNgay() const;

public:
    Ngay();
    Ngay(const int &);
    Ngay(const int &ngay, const int &thang, const int &nam);
    ~Ngay();

    Ngay operator+(const Ngay &d) const;
    Ngay operator+(const int &num) const;
    Ngay operator-(const Ngay &d) const;
    bool operator>(const Ngay &d) const;

    friend Ngay operator+(const int &num, const Ngay &d);
    friend Ngay operator-(const int &num, const Ngay &d);
    friend ostream &operator<<(ostream &os, const Ngay &d);
};
#endif // !NGAY_H
