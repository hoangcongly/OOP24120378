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
private:
    double kl, beo, duong;

public:
    NguyenLieuDon(const string &t = "", double k = 0, double b = 0, double d = 0) : NguyenLieu(t), kl(k), beo(b), duong(d) {}
    double khoiLuong() const override { return kl; }
    double hamLuongBeo() const override { return beo; }
    double hamLuongDuong() const override { return duong; }
    int demNguyenLieuDon() const { return 1; }
    void xuat(ostream &os) const override
    {
        os << ten << " (Đơn) | KL=" << kl
           << ", Béo=" << beo << ", Đường=" << duong;
    }
};

class NguyenLieuHonHop : public NguyenLieu
{
private:
    vector<NguyenLieu *> ds;

public:
    NguyenLieuHonHop(const string &t = "") : NguyenLieu(t) {}
    virtual NguyenLieuHonHop()
    {
        for (size_t i = 0; i < ds.size(); i++)
        {
            if (ds[i] != nullptr)
                delete ds[i];
        }
        ds.clear();
    }

    void them(NguyenLieu *p)
    {
        if (!p)
            throw invalid_argument("Null pointer exception");
        ds.push_back(p);
    }
}