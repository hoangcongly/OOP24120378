#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class HinhHocPhang
{
public:
    virtual double dienTich() const = 0;
    virtual double chuVi() const = 0;
    virtual char *loai() const = 0;
    virtual void xuat(ostream &os) const = 0;
    virtual ~HinhHocPhang() = default;
};

ostream &operator<<(ostream &os, const HinhHocPhang &h)
{
    h.xuat(os);
    return os;
}

class HinhChuNhat : public HinhHocPhang
{
private:
    double dai, rong;

public:
}