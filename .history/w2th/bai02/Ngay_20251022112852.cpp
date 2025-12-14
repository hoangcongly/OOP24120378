#include "Ngay.h"

Ngay::Ngay()
{
    _ng=_th=_n=1;
}
Ngay:: Ngay(const int&n)
{
    _ng=(n>0)?n:(-n);
    _th=_n=1;
    if(_ng==0)
    {
        _ng=1;
        return;
    }
    int idxN= LaNamNhuan(_n);
    while(_ng>arrNgayCuaThang[idxN][_th])
    {
        _ng-=arrNgayCuaThang[idx][_th];
        _th++;
        if(_th>12)
        {
            _th=1;
            _n++;
            idxN= LaNamNhuan(_n);
        }
    }
}