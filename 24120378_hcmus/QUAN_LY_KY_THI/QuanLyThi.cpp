#include "QuanLyThi.h"

GiangVien:: GiangVien() {};
GiangVien:: GiangVien(string maGV, string tenGV, string boMon, string sdtGV, string emailGV, string diaChiGV) 
{
    this->maGV = maGV;
    this->tenGV = tenGV;
    this->boMon = boMon;
    this->sdtGV = sdtGV;
    this->emailGV = emailGV;
    this->diaChiGV = diaChiGV;
}
string GiangVien::getMaGV() const
{
    return maGV;
}
string GiangVien::getTenGV() const
{
    return tenGV;
}
void GiangVien::setHoTen(const string& ten)
{
    tenGV = ten;
}
void GiangVien::hienThi() const
{
    cout << "Ma GV: " << maGV << endl;
    cout << "Ten GV: " << tenGV << endl;
    cout << "Bo Mon: " << boMon << endl;
    cout << "SDT: " << sdtGV << endl;
    cout << "Email: " << emailGV << endl;
    cout << "Dia Chi: " << diaChiGV << endl;
}

CanBoCoiThi::CanBoCoiThi() {};
CanBoCoiThi::CanBoCoiThi(string ma, string ten, string bm,string sdt, string email, string diaChi)
{
    maCB= ma;
    tenCB= ten;
    sdtCB= sdt;
    emailCB= email;
    diaChiCB= diaChi;
    boMon= bm;
}
string CanBoCoiThi::getMaCB() const
{
    return maCB;
}
void CanBoCoiThi::hienThi() const
{
    cout << "Ma CB: " << maCB << endl;
    cout << "Ten CB: " << tenCB << endl;
    cout << "Bo Mon: " << boMon << endl;
    cout << "SDT: " << sdtCB << endl;
    cout << "Email: " << emailCB << endl;
    cout << "Dia Chi: " << diaChiCB << endl;
}
LichThi::LichThi() : soLuongSV(0), daThi(false) {}
LichThi::LichThi(string maLop, string monHoc, string ngayThi, string gioThi, string phongThi, int soLuongSV, bool daThi, GiangVien giangVien, vector<CanBoCoiThi> dsCanBo)
    : maLop(maLop), monHoc(monHoc), ngayThi(ngayThi), gioThi(gioThi), phongThi(phongThi), soLuongSV(soLuongSV), daThi(daThi), giangVien(giangVien), dsCanBo(dsCanBo) {}
void LichThi::ganGiangVien(const GiangVien& gv)
{
    giangVien = gv;
}
void LichThi::themCanBo(const CanBoCoiThi& cb)
{
    dsCanBo.push_back(cb);
}
bool LichThi::kiemTraTrungLich(const LichThi& lich) const
{
    if(ngayThi==lich.ngayThi && gioThi==lich.gioThi && phongThi==lich.phongThi)
    {
        return true;
    }
    return false;
}
void LichThi::hienThi() const
{
    cout << "Lop: " << maLop << " - " << monHoc << " - " << ngayThi
         << " " << gioThi << " - Phong: " << phongThi
         << " - SV: " << soLuongSV << " - Da thi: " << (daThi ? "Yes" : "No") << endl;
    cout << "Giang vien: ";
    giangVien.hienThi();
    cout << "Cac can bo coi thi: " << endl;
    for (auto &cb : dsCanBo) {
        cb.hienThi();
    }
}
KyThi::KyThi() : maKyThi(""), hocKi(""), namHoc(0), daKetThuc(false) {}
KyThi::KyThi(string maKyThi, string hocKi, int namHoc, vector<LichThi> dsLichThi, bool daKetThuc)
    : maKyThi(maKyThi), hocKi(hocKi), namHoc(namHoc), dsLichThi(dsLichThi), daKetThuc(daKetThuc) {}
void KyThi:: themLichThi(const LichThi& lich)
{
    dsLichThi.push_back(lich);
}
void KyThi:: KhoaLichThi(const string& maLop)
{
    daKetThuc=true;
}
void KyThi:: hienThi() const
{
    cout << "Ky thi: " << maKyThi << " - Hoc ky: " << hocKi << " - Nam: " << namHoc
         << " - Da ket thuc: " << (daKetThuc ? "Yes" : "No") << endl;
    for (auto &lt : dsLichThi) 
    {
        lt.hienThi();
    }
}
bool KyThi:: kiemTraLichThi(const LichThi&lich) const
{
    for (const auto& lt : dsLichThi) {
        if (lt.kiemTraTrungLich(lich)) {
            return true;
        }
    }
    return false;
}
KinhPhi:: KinhPhi()
{
    maLop = "";
    donGia = 0.0;
    soSv = 0;
    chiPhiInAn = 0.0;
    chiPhiCoiThi = 0.0;
    daThanhToan = false;
}
KinhPhi:: KinhPhi(string maLop, double donGia, int soSv, double chiPhiInAn, double chiPhiCoiThi, bool daThanhToan)
{
    maLop = maLop;
    donGia = donGia;
    soSv = soSv;
    chiPhiInAn = chiPhiInAn;
    chiPhiCoiThi = chiPhiCoiThi;
    daThanhToan = daThanhToan;
}
double KinhPhi:: tinhTongChiPhi() const
{
    return (soSv * donGia) + chiPhiInAn + chiPhiCoiThi;
}
void KinhPhi::hienThi() const 
{
    cout << "Kinh phi lop " << maLop << ": " << tinhTongChiPhi()
         << " - Da thanh toan: " << (daThanhToan ? "Yes" : "No") << endl;
}
PhanCongCoiThi:: PhanCongCoiThi() {};
void PhanCongCoiThi::themCanBo(const CanBoCoiThi& cb)
{
    dsCanBo.push_back(cb);
}
void PhanCongCoiThi::hienThi() const
{
    cout << "Danh sach can bo coi thi: " << endl;
    for (const auto& cb : dsCanBo) {
        cb.hienThi();
    }
}
void PhanCongCoiThi:: phanCong(LichThi& lt, const vector<CanBoCoiThi>& dsCanBo)
{
    for (const auto& cb : dsCanBo) {
        if (KiemTraTrungLich(cb, lt)) {
            lt.themCanBo(cb);
        }
    }
}
bool PhanCongCoiThi:: KiemTraTrungLich(const CanBoCoiThi&cb, const LichThi& lt)
{ 
    return false;
}