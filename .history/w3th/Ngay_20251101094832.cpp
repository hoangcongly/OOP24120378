#include "ngay.h"
#include <iostream>
using namespace std;

int Ngay::arrNgayCuaThang[][13] = {
    {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool Ngay::LaNamNhuan(const int &n)
{
    return (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0));
}

Ngay::Ngay()
{
    _ng = _th = _n = 1;
}

// ✅ SỬA LẠI HÀM KHỞI TẠO TỪ SỐ NGÀY
Ngay::Ngay(const int &n)
{
    int ngay = (n > 0) ? n : -n;
    _n = _th = _ng = 1;

    while (ngay > (LaNamNhuan(_n) ? 366 : 365))
    {
        ngay -= (LaNamNhuan(_n) ? 366 : 365);
        _n++;
    }

    int idx = LaNamNhuan(_n);
    while (ngay > arrNgayCuaThang[idx][_th])
    {
        ngay -= arrNgayCuaThang[idx][_th];
        _th++;
    }

    _ng = ngay;
}

Ngay::Ngay(const int &ng, const int &th, const int &n)
{
    _ng = ng;
    _th = th;
    _n = n;
    ChuanHoaNgay();
}

Ngay::~Ngay() {}

int Ngay::demSoNgay() const
{
    int result = _ng;
    int th = _th - 1, n = _n - 1;
    while (th > 0)
    {
        result += arrNgayCuaThang[LaNamNhuan(n)][th];
        th--;
    }
    while (n > 0)
    {
        result += LaNamNhuan(n) ? 366 : 365;
        n--;
    }
    return result;
}

void Ngay::ChuanHoaNgay()
{
    if (_ng < 0)
        _ng = -_ng;

    while (_th > 12)
    {
        _th -= 12;
        _n++;
    }
    while (_th <= 0)
    {
        _th += 12;
        _n--;
    }

    int idx = LaNamNhuan(_n);
    while (_ng > arrNgayCuaThang[idx][_th])
    {
        _ng -= arrNgayCuaThang[idx][_th];
        _th++;
        if (_th > 12)
        {
            _th = 1;
            _n++;
        }
        idx = LaNamNhuan(_n);
    }
}

Ngay Ngay::operator+(const Ngay &d) const
{
    int num1 = this->demSoNgay();
    int num2 = d.demSoNgay();
    return Ngay(num1 + num2);
}

Ngay Ngay::operator+(const int &num) const
{
    return Ngay(this->demSoNgay() + num);
}

Ngay Ngay::operator-(const Ngay &d) const
{
    int hieu = this->demSoNgay() - d.demSoNgay();
    return Ngay(hieu);
}

bool Ngay::operator>(const Ngay &d) const
{
    if (_n != d._n)
        return _n > d._n;
    if (_th != d._th)
        return _th > d._th;
    return _ng > d._ng;
}

ostream &operator<<(ostream &os, const Ngay &d)
{
    os << d._ng << "/" << d._th << "/" << d._n;
    return os;
}
