#pragma
#include "BenhNhan.h"

class NgoaiTru : public BenhNhan
{
private:
    std::vector<double> m_phiKham;

public:
    NgoaiTru(const std::string &msbn = "", const std::string &hoten = "") : BenhNhan(msbn, hoten) {}
    void ThemLanKham(double phikham)
    {
        m_phiKham.push_back(phikham);
    }
    double TinhVienPhi() const override
    {
        double tong = 0.0;
        for (double f : m_dsPhiKham)
            tong += f;
        return tong;
    }
    void XuatThongTin() const override
    {
        BenhNhan::XuatThongTin();
        std::cout << " - Loai: Ngoai tru"
                  << " - Vien phi: " << TinhVienPhi() << '\n';
    }
};

