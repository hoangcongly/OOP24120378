#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

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
    HinhChuNhat(double d = 0, double r = 0) : dai(d), rong(r) {}
    double dienTich() const override
    {
        return dai * rong;
    }
    double chuVi() const override
    {
        return 2 * (dai + rong);
    }
    char *loai() const override
    {
        return (char *)"HCN";
    }
    void xuat(ostream &os) const override
    {
        os << "Hinh chu nhat (d=" << dai << ", r=" << rong
           << ")  S=" << dienTich()
           << "  P=" << chuVi();
    }
    void nhap(istream &is)
    {
        is >> dai >> rong;
    }
};

istream &operator>>(istream &is, HinhChuNhat &h)
{
    h.nhap(is);
    return is;
}

class HinhTron : public HinhHocPhang
{
private:
    double r;

public:
    HinhTron(double rr = 0) : r(rr) {}
    double dienTich() const override
    {
        return M_PI
    }
};