#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ChiTietMay
{
protected:
    string _maSo;

public:
    ChiTietMay(const string &ms = "")
    {
        _maSo = ms;
    }
    virtual ~ChiTietMay() = default;
    virtual double TrongLuong() const = 0;
    virtual double GiaThanh() const = 0;
};

class ChiTietDon : public ChiTietMay
{
private:
    double tl;
    double gt;

public:
    ChiTietDon(const string &ms = "", const double &trongluong = 0, const double &giathanh = 0) : ChiTietMay(ms)
    {
        tl = trongluong;
        gt = giathanh;
    }
    double TrongLuong() const override
    {
        return tl;
    }
    double GiaThanh() const override 
    {
        return gt;
    }
};

class ChiTietPhuc: public ChiTietMay
{
protected:
    vector<ChiTietMay*> children;
public:

};
int main()
{
    /// tao moi co may
    CoMay *pcm = new CoMay();

    /// them chi tiet
    pcm->ThemChiTietMay(new ChiTietDon("CTD001", 120, 350000));

    /// tao Chi tiet phuc
    ChiTietMay *pctm = new ChiTietPhuc("CTP001");
    ((ChiTietPhuc *)pctm)->ThemChiTiet(new ChiTietDon("CTD002", 50, 1280000));
    ((ChiTietPhuc *)pctm)->ThemChiTiet(new ChiTietDon("CTD003", 20, 10000));

    ChiTietMay *pctm1 = new ChiTietPhuc("CTP002");
    ((ChiTietPhuc *)pctm1)->ThemChiTiet(new ChiTietDon("CTD004", 80, 170000));
    ((ChiTietPhuc *)pctm)->ThemChiTiet(pctm1);

    pcm->ThemChiTietMay(pctm);
    pcm->ThemChiTietMay(new ChiTietDon("CTD005", 210, 2350000));
    pcm->ThemChiTietMay(new ChiTietDon("CTD006", 40, 50000));

    /// xuat thong tin co may
    /// xuat danh sach cac chi tiet con
    cout << "Thong tin co may: " << endl
         << *pcm << endl;

    /// xuat trong luong co may
    cout << "Trong luong: " << pcm->TrongLuong() << endl;

    /// xuat gia thanh co may
    cout << "Gia thanh: " << pcm->GiaThanh() << endl;

    cout << endl
         << endl;
    system("pause");
    return 0;
}
