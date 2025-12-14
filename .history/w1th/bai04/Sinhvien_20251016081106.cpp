#include "SinhVien.h"

SinhVien::SinhVien()
{
    DTH = 10.0f;
    DLT = 10.0f;
    NgaySinh.ngay = 0;
    NgaySinh.thang = 0;
    NgaySinh.nam = 0;
    MSSV = new char[strlen(DEFAULT_MSSV) + 1];
    strcpy(MSSV, DEFAULT_MSSV);
    HoTen = new char[strlen(DEFAULT_HOTEN) + 1];
    strcpy(HoTen, DEFAULT_HOTEN);
}

SinhVien::SinhVien(const char *mssv)
{
    DLT = 10.0f;
    DTH = 10.0f;
    NgaySinh = NgayThang();
    const char *mssv_ptr = (mssv != nullptr && strlen(mssv) > 0) ? mssv : DEFAULT_MSSV;
    MSSV = new char[strlen(mssv_ptr) + 1];
    strcpy(MSSV, mssv_ptr);
    HoTen = new char[strlen(DEFAULT_HOTEN) + 1];
    strcpy(HoTen, DEFAULT_HOTEN);
}

Sinhvien