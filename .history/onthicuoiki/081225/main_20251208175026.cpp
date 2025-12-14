#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>

using namespace std;

class NguyenLieu
{
protected:
    string ten;

public:
    NguyenLieu(const string &t = " ") : ten(t) {}
    virtual ~NguyenLieu() = default;

    string getTen() const { return ten; }
    virtual double khoiLuong() const = 0;
    virtual double hamLuongBeo() const = 0;
    virtual double hamLuongDuong() const = 0;
    virtual int demNguyenLieuDon() const = 0;
    virtual void xuat(ostream &os) const
    {
        os << ten;
    }
};

ostream &operator<<(ostream &os, const NguyenLieu &nl)
{
    nl.xuat();
    return os;
}

class NguyenLieuDon : public NguyenLieu
{
    double kl, beo, duong;
};