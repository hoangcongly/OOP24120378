#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>

using namespace std;

class FileNotFoundException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "File not found";
    }
};

class NullReferenceException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Null reference";
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

class IndexOutOfRangeException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Index out of range";
    }
};

class Son
{
protected:
    string ten;

public:
    Son(string ten = "") : ten(ten) {}
    virtual ~Son() = default;

    string getTen() const { return ten; }
    virtual double theTich() const = 0;
    virtual double hamLuongMau() const = 0;
    virtual double hamLuongDungMoi() const = 0;
    virtual int demLuongSon() const = 0;

    virtual void nhap(istream &is) = 0;
    virtual void xuat(ostream &os) const = 0;
};

ostream &operator<<(ostream &os, const Son &s)
{
    s.xuat(os);
    return os;
}

class SonDon : public Son
{
private:
    double vt;
    double mau;
    double dungMoi;

public:
    SonDon() : vt(0), mau(0), dungMoi(0) {}
    double theTich() const override { return vt; }
    double hamLuongMau() const override { return mau; }
    double hamLuongDungMoi() const override { return dungMoi; }
    int demLuongSon() const override { return 1; }
    void nhap(istream &is) override
    {
        is >> ten >> vt >> mau >> dungMoi;
        if (is.fail())
            throw InvalidDataException();
    }
    void xuat(ostream &os) const override
    {
        os << "Son don: " << ten
           << " | VT=" << vt
           << " | Mau=" << mau
           << " | Dung moi=" << dungMoi << endl;
    }
};

class SonHonHop : public Son
{
protected:
    vector<Son *> dsCon;

public:
    SonHonHop(string ten = "") : Son(ten) {}
    virtual ~SonHonHop()
    {
        for (auto p : dsCon)
        {
            delete p;
        }
    }
    void themSon(Son *s)
    {
        if (!s)
        {
            throw NullReferenceException();
        }
        dsCon.push_back(s);
    }
    int demLuongSon() const override
    {
        int sum = 0;
        for (auto p : dsCon)
        {
            sum += p->demLuongSon();
        }
        return sum;
    }
};

class SonHonHopDac : public SonHonHop
{
public:
    SonHonHopDac(string ten = "") : SonHonHop(ten) {}
    double theTich() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->theTich();
        }
        return s;
    }
    double hamLuongMau() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->hamLuongMau();
        }
        return 0.5 * s;
    }
    double hamLuongDungMoi() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->hamLuongDungMoi();
        }
        return 0.5 * s;
    }

    void nhap(istream &is) override;
    void xuat(ostream &os) const override;
};

class SonHonHopLong : public SonHonHop
{
public:
    SonHonHopLong(string ten = "") : SonHonHop(ten) {}
    double theTich() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->theTich();
        }
        return 1.2 * s;
    }
    double hamLuongMau() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->hamLuongMau();
        }
        return s;
    }
    double hamLuongDungMoi() const override
    {
        double s = 0;
        for (auto p : dsCon)
        {
            s += p->hamLuongDungMoi();
        }
        return s;
    }
    void nhap(istream &is) override;
    void xuat(ostream &os) const override;
};

Son *taoSonTheoLoai(const string &type)
{
    if (type == "DON")
        return new SonDon();
    if (type == "DAC")
        return new SonHonHopDac();
    if (type == "LONG")
        return new SonHonHopLong();
    throw InvalidDataException();
}

void SonHonHopDac::nhap(istream &is)
{
    int n;
    is >> ten >> n;
    if (n < 0)
        throw InvalidDataException();
    for (int i = 0; i < n; i++)
    {
        string type;
        is >> type;
        Son *s = taoSonTheoLoai(type);
        s->nhap(is);
        themSon(s);
    }
}

void SonHonHopDac::xuat(ostream &os) const
{
    os << "Son hon hop dac: " << ten << endl;
    for (auto p : dsCon)
        os << *p;
    os << "-> VT=" << theTich()
       << ", Mau=" << hamLuongMau()
       << ", Dung moi=" << hamLuongDungMoi() << endl;
}

void SonHonHopLong::nhap(istream &is)
{
    int n;
    is >> ten >> n;
    if (n < 0)
        throw InvalidDataException();
    for (int i = 0; i < n; i++)
    {
        string type;
        is >> type;
        Son *s = taoSonTheoLoai(type);
        s->nhap(is);
        themSon(s);
    }
}

void SonHonHopLong::xuat(ostream &os) const
{
    os << "Son hon hop long: " << ten << endl;
    for (auto p : dsCon)
        os << *p;
    os << "-> VT=" << theTich()
       << ", Mau=" << hamLuongMau()
       << ", Dung moi=" << hamLuongDungMoi() << endl;
}

class ThungSon
{
private:
    string ten;
    vector<Son *> ds;

public:
    ~ThungSon()
    {
        for (auto p : ds)
        {
            delete p;
        }
    }
    void docFile(const string &filename)
    {
        ifstream fin(filename);
        if (!fin)
            throw FileNotFoundException();
        fin >> ten;
        int n;
        fin >> n;
        for (int i = 0; i < n; i++)
        {
            string type;
            fin >> type;
            Son *s = taoSonTheoLoai(type);
            s->nhap(fin);
            ds.push_back(s);
        }
    }
    void xuat() const
    {
        cout << "THUNG SON: " << ten << endl;
        for (auto p : ds)
            cout << *p;
    }

    void SonHonHopNhieuDonNhat() const
    {
        SonHonHop *best = nullptr;
        int mx = 0;
        for (auto p : ds)
        {
            auto hh = dynamic_cast<SonHonHop *>(p);
            if (hh)
            {
                int cnt = hh->demLuongSon();
                if (cnt > mx)
                {
                    mx = cnt;
                    best = hh;
                }
            }
        }
        if (best)
        {
            cout << "Son hon hop chua nhieu son don nhat: "
                 << best->getTen() << " (" << mx << ")" << endl;
        }
    }
};

int main()
{
    try
    {
        ThungSon t;
        t.docFile("input.txt");
        t.xuat();
        t.SonHonHopNhieuDonNhat();
    }
    catch (exception &e)
    {
        cout << "ERROR: " << e.what() << endl;
    }
    return 0;
}
