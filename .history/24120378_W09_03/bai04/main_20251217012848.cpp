#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ChiTietMay
{
protected:
    string _maSo;
public:
    ChiTietMay(const string&ms)
    {
        _maSo= ms;
    }
    virtual ~ChiTietMay()= default;
    virtual double TrongLuong() const;
    virtual double GiaThanh() const;
};

class ChiTietDon: public ChiTietMay
{
private:
    double tl;
    double gt;
public:

};
int main()
{
    /// tao moi co may
    CoMay* pcm = new CoMay();

    /// them chi tiet
    pcm->ThemChiTietMay(new ChiTietDon("CTD001", 120, 350000));

    /// tao Chi tiet phuc
    ChiTietMay* pctm = new ChiTietPhuc("CTP001");
    ((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD002", 50, 1280000));
    ((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD003", 20, 10000));

    ChiTietMay* pctm1 = new ChiTietPhuc("CTP002");
    ((ChiTietPhuc*)pctm1)->ThemChiTiet(new ChiTietDon("CTD004", 80, 170000));
    ((ChiTietPhuc*)pctm)->ThemChiTiet(pctm1);

    pcm->ThemChiTietMay(pctm);
    pcm->ThemChiTietMay(new ChiTietDon("CTD005", 210, 2350000));
    pcm->ThemChiTietMay(new ChiTietDon("CTD006", 40, 50000));

    /// xuat thong tin co may
    /// xuat danh sach cac chi tiet con
    cout << "Thong tin co may: " << endl << *pcm << endl;

    /// xuat trong luong co may
    cout << "Trong luong: " << pcm->TrongLuong() << endl;

    /// xuat gia thanh co may
    cout << "Gia thanh: " << pcm->GiaThanh() << endl;

    cout << endl << endl;
    system("pause");
    return 0;
}
