#include "ThoiGian.h"

void ThoiGian::ChuanHoa()
{
    _gio=abs(_gio);
    _phut=abs(_phut);
    _giay=abs(_giay);
    int phutDu= (_giay-1)/60;
    _giay=(_giay-1)%60+1;
    _phut+=phutDu;
    int gioDu= (_phut-1)/60;
    _phut=(_phut-1)%60+1;
    _gio+=gioDu;
}
ThoiGian:: ThoiGian()
{
    _gio=_phut=_giay=0;
}
ThoiGian:: ThoiGian(const int& h, const int& m, const int& s)
{
    _gio=h;
    _phut=m;
    _giay=s;
    ChuanHoa();
}
ThoiGian:: ThoiGian(const int&m, const int&s)
{
    _gio=0;
    _phut=abs(m);
    _giay=abs(s);
    ChuanHoa();
}
ThoiGian:: ThoiGian(const int& s)
{
    _gio=_phut=0;
    _giay=abs(s);
    ChuanHoa();
}
ThoiGian:: ~ThoiGian() {};
void ThoiGian:: Xuat()
{
    
}