#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <memory>

using namespace std;

const double PI = 3.141592653589793;
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
    static int dem;

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
int HinhChuNhat::dem = 0;

class HinhTron : public HinhHocPhang
{
private:
    double r;
    static int dem;

public:
    HinhTron(double rr = 0) : r(rr) {}
    double dienTich() const override
    {
        return PI * r * r;
    }
    double chuVi() const override
    {
        return 2 * PI * r;
    }
    char *loai() const override
    {
        return (char *)"HTR";
    }
    void xuat(ostream &os) const override
    {
        os << "Hinh tron (r=" << r
           << ")  S=" << dienTich()
           << "  P=" << chuVi();
    }
    void nhap(istream &is)
    {
        is >> r;
    }
};

istream &operator>>(istream &is, HinhTron &h)
{
    h.nhap(is);
    return is;
}

int HinhTron::dem = 0;

class HinhTamGiac : public HinhHocPhang
{
private:
    double a, b, c;
    static int dem;

public:
    HinhTamGiac(double aa = 0, double bb = 0, double cc = 0) : a(aa), b(bb), c(cc) {}
    double chuVi() const override
    {
        return a + b + c;
    }
    double dienTich() const override
    {
        double p = chuVi() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    char *loai() const override
    {
        return (char *)"HTG";
    }
    void xuat(ostream &os) const override
    {
        os << "Hinh tam giac (a=" << a << ", b=" << b << ", c=" << c
           << ")  S=" << dienTich()
           << "  P=" << chuVi();
    }

    void nhap(istream &is)
    {
        is >> a >> b >> c;
    }
};

istream &operator>>(istream &is, HinhTamGiac &h)
{
    h.nhap(is);
    return is;
}

int HinhTamGiac::dem = 0;

class HinhThangVuong : public HinhHocPhang
{
private:
    double dayLon, dayBe, cao;

public:
    HinhThangVuong(double dl = 0, double db = 0, double h = 0)
        : dayLon(dl), dayBe(db), cao(h) {}
    double dienTich() const override
    {
        return (dayLon + dayBe) * cao / 2.0;
    }
    double chuVi() const override
    {
        double canhBen = fabs(dayLon - dayBe); // cạnh ngang còn lại
        double canhCheo = sqrt(canhBen * canhBen + cao * cao);
        return dayLon + dayBe + cao + canhCheo;
    }
    char *loai() const override
    {
        return (char *)"HTV";
    }
    void xuat(ostream &os) const override
    {
        os << "Hinh thang vuong (day lon=" << dayLon
           << ", day be=" << dayBe
           << ", cao=" << cao
           << ")  S=" << dienTich()
           << "  P=" << chuVi();
    }

    void nhap(istream &is)
    {
        is >> dayLon >> dayBe >> cao;
    }
};
istream &operator>>(istream &is, HinhThangVuong &h)
{
    h.nhap(is);
    return is;
}

class QuanLyHinhHocPhang
{
private:
}