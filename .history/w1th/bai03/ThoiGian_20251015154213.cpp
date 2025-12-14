#include "ThoiGian.h"

void ThoiGian::ChuanHoa()
{
    if(_gio<0) _gio=0;
    if(_phut<0) _phut=0;
    if(_giay<0) _giay=0;
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
    _phut=m;
    _giay=s;
    ChuanHoa();
}
ThoiGian:: ThoiGian(const int& s)
{
    _gio=_phut=0;
    _giay=s;
    ChuanHoa();
}
ThoiGian:: ~ThoiGian() {};
void ThoiGian:: Xuat()
{
    if(_gio<10) cout << "0" << _gio << ":";
    else cout << _gio << ":";
    if(_phut<10) cout << "0"<< _phut<< ":";
    else cout << _phut << ":";
    if(_giay<10) cout << "0" << _giay << ":";
    else cout << _giay << endl;
}