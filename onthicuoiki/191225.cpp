#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class ChungCu
{
protected:
    string ten;
    int soTang;
    double dienTich;
    string tenQL;
    string soHuu;

public:
    ChungCu(const string &_ten, const int &_soTang, const double &_dienTich, const string &_tenQL, const string &_soHuu)
    {
        ten = _ten;
        soTang = _soTang;
        dienTich = _dienTich;
        tenQL = _tenQL;
        soHuu = _soHuu;
    }
    virtual ~ChungCu() = default;
    virtual void guiThongBao() const
    {
        cout << tenQL << " - " << ten << " - " << soHuu << endl;
    }
    virtual string getTenSoHuu() const = 0;
    double getDienTich() const
    {
        return dienTich;
    }
    virtual double tienThuePhong() const = 0;
};

class CCVinhome : public ChungCu
{
public:
    CCVinhome(const string &ten, const int &soTang, const double &dienTich, const string &tenQL, const string &soHuu = "Vinhomes")
        : ChungCu(ten, soTang, dienTich, tenQL, soHuu) {}
    string getTenSoHuu() const
    {
        return "Vinhomes";
    }
    double tienThuePhong() const override
    {
        double res = 0;
        if (dienTich > 600)
        {
            res = (10 + rand() % (15 - 10 + 1)) * soTang * 6;
        }
        else
        {
            res = (6 + rand() % (10 - 6 + 1)) * soTang * 6;
        }
        return res;
    }
};

class CCBcons : public ChungCu
{
public:
    CCBcons(const string &ten, const int &soTang, const double &dienTich, const string &tenQL, const string &soHuu = "Bcons")
        : ChungCu(ten, soTang, dienTich, tenQL, soHuu) {}
    string getTenSoHuu() const
    {
        return "Bcons";
    }
    double tienThuePhong() const override
    {
        double res = 0;
        if (dienTich > 600)
        {
            res = (8 + rand() % (12 - 8 + 1)) * soTang * 6;
        }
        else
        {
            res = (5 + rand() % (8 - 5 + 1)) * soTang * 6;
        }
        return res;
    }
};

class QuanLyCC
{
private:
    vector<ChungCu *> dscc;

public:
    void ThongBaoALL() const
    {
        cout << "THONG BAO TAT CA\n";
        for (auto cc : dscc)
        {
            cc->guiThongBao();
        }
    }
    double tongtienthu() const
    {
        double res = 0;
        for (auto cc : dscc)
        {
            res += cc->tienThuePhong();
        }
        return res;
    }
    void themcc(ChungCu *cc)
    {
        dscc.push_back(cc);
    }
    ~QuanLyCC()
    {
        for (auto cc : dscc)
        {
            delete cc;
        }
    }
};

int main()
{
    srand(time(nullptr));

    QuanLyCC ql;

    ql.themcc(new CCVinhome("Chung cu UITer", 12, 700, "Nguyen Van A"));
    ql.themcc(new CCBcons("Chung cu USSHer", 10, 550, "Nguyen Van B"));

    ql.ThongBaoALL();

    cout << "Tong tien thu moi thang: "
         << ql.tongtienthu() << " trieu VND\n";
}
