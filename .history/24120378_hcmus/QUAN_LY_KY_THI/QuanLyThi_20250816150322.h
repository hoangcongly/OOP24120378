#ifndef QUANLYTHI_H
#define QUANLYTHI_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GiangVien{
private: 
    string maGV;
    string tenGV;
    string boMon;
    string sdtGV;
    string emailGV;
    string diaChiGV;
public:
    GiangVien();
    GiangVien(string maGV, string tenGV, string boMon, string sdtGV, string emailGV, string diaChiGV);

    string getMaGV() const;
    string getTenGV() const;
    void setHoTen(const string& ten);
    void setMaGV(const string& maGV);

    void HienThi() const;
};

class CanBoCoiThi{
private: 
    string maCB;
    string tenCB;
    string boMon;
    string sdtCB;
    string emailCB;
    string diaChiCB;
public:
    CanBoCoiThi();
    CanBoCoiThi(string maCB, string tenCB, string boMon, string sdtCB, string emailCB, string diaChiCB);

    string getMaCB() const;
    void hienThi() const;
};

class LichThi{
private:
    string maLop;
    string monHoc;
    string ngayThi;
    string gioThi;
    string phongThi;
    int soLuongSV;
    bool daThi;
    GiangVien giangVien;
    vector<CanBoCoiThi> dsCanBo;
public:
    LichThi();
    LichThi(string maLop, string monHoc, string ngayThi, string gioThi, string phongThi, int soLuongSV, bool daThi, GiangVien giangVien, vector<CanBoCoiThi> dsCanBo);
    
    void ganGiangVien(const GiangVien&gv);
    void themCanBo(const CanBoCoiThi& cb);
    bool kiemTraTrungLich(const LichThi&lt) const;
    void hienThi() const;
};

class KyThi{
private:
    string maKyThi;
    string hocKi;
    int namHoc;
    vector<LichThi> dsLichThi;
    bool daKetThuc;
public:
    KyThi();
    KyThi(string maKyThi, string hocKi, int namHoc, vector<LichThi> dsLichThi, bool daKetThuc);

    void themLichThi(const LichThi& lich);
    void xoaLichThi(const string& maLop);
    void KhoaLichThi(const string& maLop);
    void hienThi() const;
    bool kiemTraLichThi(const LichThi& lich) const;
    void ketThucKyThi();
};

class KinhPhi{
private:
    string maLop;
    double donGia;
    int soSv;
    double chiPhiInAn;
    double chiPhiCoiThi;
    bool daThanhToan;

public:
    KinhPhi();
    KinhPhi(string maLop, double donGia, int soSv, double chiPhiInAn, double chiPhiCoiThi, bool daThanhToan);

    double tinhTongChiPhi() const;
    void hienThi() const;
};

class PhanCongCoiThi{
private:
    vector<CanBoCoiThi> dsCanBo;
public:
    PhanCongCoiThi();
    void themCanBo(const CanBoCoiThi& cb);
    void xoaCanBo(const string& maCB);
    static bool KiemTraTrungLich(const CanBoCoiThi& cb, const LichThi& lt);
    static void phanCong(LichThi& lt, const vector<CanBoCoiThi>& dsCanBo);
    void hienThi() const;
};
#endif // QUANLYTHI_H