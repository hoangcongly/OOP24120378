#include "So_Phuc.h"

SoPhuc:: SoPhuc()
{
    thuc=0;
    ao=0;
}
SoPhuc:: SoPhuc(double t, double a)
{
    thuc=t;
    ao=a;
}
SoPhuc SoPhuc::operator+(const SoPhuc&src) const
{
    return SoPhuc(thuc+src.thuc, ao+src.ao);
}
SoPhuc SoPhuc:: operator-(const SoPhuc&src) const
{
    return SoPhuc(thuc-src.thuc,ao-src.ao);
}
SoPhuc SoPhuc:: operator*(const SoPhuc&src) const
{
    return SoPhuc(thuc*src.thuc- ao*src.ao, thuc*src.ao+ ao*src.thuc);
}
SoPhuc SoPhuc:: operator/(const SoPhuc&src) const
{
    double mau= src.thuc*src.thuc+src.ao*src.ao;
    return SoPhuc((thuc*src.thuc+ao*src.ao)/mau, (-thuc*src.ao+ao*src.thuc)/mau);
}
bool SoPhuc:: operator==(const SoPhuc&src) const
{
    return (thuc==src.thuc&& ao== src.ao);
}
bool SoPhuc:: operator!=(const SoPhuc&src) const
{
    return !(*this==src);
}
ostream& operator<<(ostream&out, const SoPhuc&sp)
{
    out << sp.thuc;
    if(sp.ao>=0) out << "+";
    out << sp.ao << "i";
    return out;
}
istream& operator>> (istream&in, SoPhuc&sp)
{
    cout << "Nhap phan thuc: ";
    in >> sp.thuc;
    cout << "Nhap phan ao: ";
    in >> sp.ao;
    return in;
}