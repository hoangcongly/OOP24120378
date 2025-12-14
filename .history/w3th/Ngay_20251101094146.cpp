#include "ngay.h"

Ngay::Ngay()
{
    _ng = _th = _n = 1;
}

Ngay::Ngay(const int &n)
{
    _ng = (n > 0) ? n : (-n);
    _th = _n = 1;
    if (_ng == 0)
    {
        _ng = 1;
        return;
    }
    ChuanHoaNgay();
}

Ngay::Ngay(const int &ng, const int &th, const int &n)
{
    _ng = ng;
    _th = th;
    _n = n;
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
    ChuanHoaNgay();
}

Ngay::~Ngay() {};

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

bool Ngay::LaNamNhuan(const int &n)
{
    return (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0));
}

int Ngay::arrNgayCuaThang[][13] = {{-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

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
    Ngay rs;
    rs._ng = _ng + d._ng;
    rs._th = _th + d._th;
    rs._n = _n + d._n;
    while (rs._th > 12)
    {
        rs._th -= 12;
        rs._n++;
    }
    while (rs._th <= 0)
    {
        rs._th += 12;
        rs._n--;
    }
    rs.ChuanHoaNgay();
    return rs;
}

Ngay Ngay::operator+(const int &num) const
{
    return *this + Ngay(num);
}

Ngay Ngay::operator-(const Ngay &d) const
{
    int num1 = this->demSoNgay();
    int num2 = d.demSoNgay();
    int hieu = num1 - num2;
    Ngay rs(1, 1, 1);
    rs = rs + hieu;
    rs.ChuanHoaNgay();
    return rs;
}

bool Ngay::operator>(const Ngay &d) const
{
    if (_n != d._n)
        return _n > d._n;
    if (_th != d._th)
        return _th > d._th;
    return _ng > d._ng;
}

Ngay operator+(const int &num, const Ngay &d)
{
    Ngay rs(d);
    rs._n += num;
    rs.ChuanHoaNgay();
    return rs;
}

Ngay operator-(const int &num, const Ngay &d)
{
    Ngay rs(num);
    return rs - d;
}

ostream &operator<<(ostream &os, const Ngay &d)
{
    os << d._ng << "/" << d._th << "/" << d._n;
    return os;
}