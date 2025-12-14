#pragma
#include "BenhNhan.h"

class NoiTru : public BenhNhan
{
private:
    int m_ngayNhap = 0;
    int m_ngayXuat = 0;
    double m_phiMoiNgay = 0.0;
    char loaiPhong = 'C';

    double DonGiaPhong() const
    {
        switch (m_loaiPhong)
        {
        case 'A':
            return 1400000;
        case 'B':
            return 900000;
        case 'C':
            return 600000;
        default:
            std::cerr << "Loi: Loai phong khong hop le '" << m_loaiPhong
                      << "' cho MSBN " << m_msbn << endl;
            return 0.0;
        }
    }

public:
    NoiTru(const std::string &msbn, const std::string &hoTen) : BenhNhan(msbn, hoTen) {}
    void NhapVien(int day, double phimoingay, char loaiphong)
    {
        m_ngayNhap = day;
        m_ngayXuat = 0;
        m_phiMoiNgay = phimoingay;
        loaiPhong = loaiphong;
    }
    void XuatVien(int day)
    {
        m_ngayXuat = day;
    }
    double TinhVienPhi() const override
    {
        if (m_ngayNhap == 0 || m_ngayXuat == 0 || m_ngayXuat <= m_ngayNhap)
            return 0.0;

        int soNgay = m_ngayXuat - m_ngayNhap;
        double donGia = m_phiMoiNgay + DonGiaPhong(m_loaiPhong);
        return soNgay * donGia;
    }
    void XuatThongTin() const override
    {
        BenhNhan::XuatThongTin();
        std::cout << " - Loai: Noi tru"
                  << " - Vien phi: " << TinhVienPhi() << '\n';
    }
};
