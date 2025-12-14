#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

class NguyenLieu;
class NguyenLieuHonHop;
class HonHopLong;
class HonHopDac;
NguyenLieu *taoNguyenLieuTheoLoai(const string &type);
ostream &operator<<(ostream &, const NguyenLieu &);

class NullReferenceException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Null reference";
    }
};

class IndexOutOfRangeException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Index out of range";
    }
};

class InvalidDataException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid data format";
    }
};

class NguyenLieu
{
protected:
    string ten;

public:
    NguyenLieu(string ten = "") : ten(ten) {}
    virtual ~NguyenLieu() = default;

    string getTen() const { return ten; }
    virtual double khoiluong() const = 0;
    virtual double hamLuongBeo() const = 0;
    virtual double hamLuongDuong() const = 0;
    virtual int demNguyenLieuDon() const = 0;
    virtual void nhap(istream &is) = 0;
    virtual void xuat(ostream &os) const = 0;
};

class NguyenLieuDon : public NguyenLieu
{
private:
    double kl;
    double beo;
    double duong;

public:
    NguyenLieuDon() : kl(0), beo(0), duong(0) {}
    double khoiluong() const override { return kl; }
    double hamLuongBeo() const override { return beo; }
    double hamLuongDuong() const override { return duong; }
    int demNguyenLieuDon() const override { return 1; }
    void nhap(istream &is) override
    {
        is >> ten >> kl >> beo >> duong;
        if (is.fail())
            throw InvalidDataException();
    }

    void xuat(ostream &os) const override
    {
        os << "Nguyen lieu don: " << ten
           << " | KL=" << kl
           << " | Beo=" << beo
           << " | Duong=" << duong << endl;
    }
};

class NguyenLieuHonHop : public NguyenLieu
{
protected:
    vector<NguyenLieu *> dsCon;

public:
    NguyenLieuHonHop(string ten = "") : NguyenLieu(ten) {}
    ~NguyenLieuHonHop()
    {
        for (auto p : dsCon)
            delete p;
    }
    void themNguyenLieu(NguyenLieu *nl)
    {
        if (!nl)
            throw NullReferenceException();
        dsCon.push_back(nl);
    }
    int demNguyenLieuDon() const override
    {
        int sum = 0;
        for (auto p : dsCon)
            sum += p->demNguyenLieuDon();
        return sum;
    }
};

class HonHopLong : public NguyenLieuHonHop
{
public:
    HonHopLong(string ten = "") : NguyenLieuHonHop(ten) {}
    double khoiluong() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->khoiluong();
        }
        return s;
    }
    double hamLuongBeo() const override
    {
        double s = 0;
        for (auto p : dsCon)
            s += p->hamLuongBeo();
        return s;
    }

    double hamLuongDuong() const override
    {
        double s = 0;
        for (auto p : dsCon)
            s += p->hamLuongDuong();
        return s;
    }

    void nhap(istream &is) override
    {
        int n;
        is >> ten >> n;
        if (n < 0)
            throw InvalidDataException();

        for (int i = 0; i < n; ++i)
        {
            string type;
            is >> type;

            NguyenLieu *nl = taoNguyenLieuTheoLoai(type);
            nl->nhap(is);
            themNguyenLieu(nl);
        }
    }

    void xuat(ostream &os) const override
    {
        os << "Hon hop long: " << ten << endl;
        for (auto p : dsCon)
            os << *p;
        os << "-> Tong KL=" << khoiluong()
           << ", Beo=" << hamLuongBeo()
           << ", Duong=" << hamLuongDuong() << endl;
    }
};

class HonHopDac : public NguyenLieuHonHop
{
public:
    HonHopDac(string ten = "") : NguyenLieuHonHop(ten) {}
    double khoiluong() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->khoiluong();
        }
        return s;
    }
    double hamLuongBeo() const override
    {
        double s = 0;
        for (auto p : dsCon)
            s += p->hamLuongBeo();
        return 0.4 * s;
    }

    double hamLuongDuong() const override
    {
        double s = 0;
        for (auto p : dsCon)
            s += p->hamLuongDuong();
        return 0.4 * s;
    }

    void nhap(istream &is) override
    {
        int n;
        is >> ten >> n;
        if (n < 0)
            throw InvalidDataException();

        for (int i = 0; i < n; ++i)
        {
            string type;
            is >> type;

            NguyenLieu *nl = taoNguyenLieuTheoLoai(type);
            nl->nhap(is);
            themNguyenLieu(nl);
        }
    }

    void xuat(ostream &os) const override
    {
        os << "Hon hop dac: " << ten << endl;
        for (auto p : dsCon)
            os << *p;
        os << "-> Tong KL=" << khoiluong()
           << ", Beo=" << hamLuongBeo()
           << ", Duong=" << hamLuongDuong() << endl;
    }
};

class FileNotFoundException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "File not found";
    }
};

class Banh
{
private:
    string ten;
    vector<NguyenLieu *> ds;

public:
    ~Banh()
    {
        for (auto p : ds)
            delete p;
    }

    void docFile(const string &filename)
    {
        ifstream fin(filename);
        if (!fin)
            throw FileNotFoundException();

        fin >> ten;
        int n;
        fin >> n;

        for (int i = 0; i < n; ++i)
        {
            string type;
            fin >> type;
            NguyenLieu *nl = nullptr;

            if (type == "DON")
                nl = new NguyenLieuDon();
            else if (type == "DAC")
                nl = new HonHopDac();
            else if (type == "LONG")
                nl = new HonHopLong();
            else
                throw InvalidDataException();

            nl->nhap(fin);
            ds.push_back(nl);
        }
    }

    void xuat() const
    {
        cout << "BANH: " << ten << endl;
        for (auto p : ds)
            cout << *p;
    }

    void honHopNhieuDonNhat() const
    {
        NguyenLieuHonHop *best = nullptr;
        int mx = 0;

        for (auto p : ds)
        {
            auto hh = dynamic_cast<NguyenLieuHonHop *>(p);
            if (hh)
            {
                int cnt = hh->demNguyenLieuDon();
                if (cnt > mx)
                {
                    mx = cnt;
                    best = hh;
                }
            }
        }

        if (best)
            cout << "Hon hop chua nhieu NL don nhat: "
                 << best->getTen() << " (" << mx << " NL don)" << endl;
    }
};

ostream &operator<<(ostream &os, const NguyenLieu &nl)
{
    nl.xuat(os);
    return os;
}

NguyenLieu *taoNguyenLieuTheoLoai(const string &type)
{
    if (type == "DON")
        return new NguyenLieuDon();
    if (type == "DAC")
        return new HonHopDac();
    if (type == "LONG")
        return new HonHopLong();
    throw InvalidDataException();
}

int main()
{
    try
    {
        Banh b;
        b.docFile("input.txt");
        b.xuat();
        b.honHopNhieuDonNhat();
    }
    catch (exception &e)
    {
        cout << "ERROR: " << e.what() << endl;
    }
    return 0;
}