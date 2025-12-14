#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const char *DEFAULT_MSSV = "xxxxxxx";
const char *DEFAULT_HOTEN = "xxxx";
struct NgayThang
{
    int ngay = 0;
    int thang = 0;
    int nam = 0;
    NgayThang(int d = 0, int m = 0, int y = 0)
    {
        ngay = d;
        thang = m;
        nam = y;
    }
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
    SinhVien(const char *mssv, const char *hoTen, float dlt, float dth);
    SinhVien(const char *mssv, const char *hoTen, float dlt, float dth, int _ng, int _th, int _n);
    SinhVien(const char *mssv, const char *hoTen, float dlt, float dth, NgayThang ngaysinh);
    SinhVien(const SinhVien &other);
    ~SinhVien();

    void Xuat() const;
};

#endif