#include "HocSinh.h"

int HocSinh::SL_HocSinh = 0;
HocSinh *HocSinh::DS_HocSinh[MAX_HS];
int HocSinh::NextMS = 2312000;

HocSinh::HocSinh()
{
    hoTen = nullptr;
    d1=d2=d3=0;
    maSo=NextMS++;
    if(SL_HocSinh<MAX_HS)
    {
        DS_HocSinh[SL_HocSinh]= this;
        SL_HocSinh++;
    }
}
HocSinh::HocSinh(char*ten, const float&n1, const float&n2, const float& n3)
{
    hoTen=ten;
    d1=n1;
    d2=n2;
    d3=n3;
    maSo=NextMS++;
    if(SL_HocSinh<MAX_HS)
    {
        DS_HocSinh[SL_HocSinh]= this;
        SL_HocSinh++;
    }
}
void HocSinh:: DatHoTen(char*name)
{
    this->hoTen= name;
}
void HocSinh:: GanDiem(const float&n1, const float& n2, const float&n3)
{
    d1=n1;
    d2=n2;
    d3=n3;
}
void HocSinh::In()
{
    cout << "HS: " << hoTen << ", MS: " << maSo << ", DTB: " << DiemTB();
} 
float HocSinh::DiemTB()
{
    return (d1+d2+d3)/3;
}

