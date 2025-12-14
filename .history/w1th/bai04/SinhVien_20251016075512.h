#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <cstring>
using namespace std;

struct NgayThang
{
    int ngay, thang, nam;
};
class SinhVien
{
private:
    char *MSSV;
    char *HoTen;
    NgayThang NgaySinh;
    float DLT;
    float DTH;

public:
    SinhVien();
    SinhVien(const char *mssv);
    SinhVien(const char *mssv, const char *hoTen, float drl, float dth);
    SinhVien(const char *mssv, const char *hoTen, float drl, float dth, int _n, int _th, int _n);
    SinhVien(const char *mssv, const char *hoTen, float drl, float dth, NgayThang ngaysinh);
    SinhVien(const SinhVien &other);
    ~SinhVien();

    void Xuat() const;
};

#endif