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

SinhVien::SinhVien(const char *mssv, const char *hoTen, float dlt, float dth)
{
    DLT = dlt;
    DTH = dth;
    NgaySinh = NgayThang();
    const char *mssv_ptr = (mssv != nullptr && strlen(mssv) > 0) ? mssv : DEFAULT_MSSV;
    MSSV = new char[strlen(mssv_ptr) + 1];
    strcpy(MSSV, mssv_ptr);
    const char *hoTen_ptr = (hoTen != nullptr && strlen(hoTen) > 0) ? hoTen : DEFAULT_HOTEN;
    hoTen = new char[strlen(hoTen_ptr) + 1];
    strcpy(HoTen, hoTen_ptr);
}

SinhVien::SinhVien(const char *mssv, const char *hoTen, float dlt, float dth, int _ng, int _th, int _n)
{
    DLT = dlt;
    DTH = dth;
    NgaySinh = NgayThang(_ng, _th, _n);
    const char *mssv_ptr = (mssv != nullptr && strlen(mssv) > 0) ? mssv : DEFAULT_MSSV;
    MSSV = new char[strlen(mssv_ptr) + 1];
    strcpy(MSSV, mssv_ptr);
    const char *hoTen_ptr = (hoTen != nullptr && strlen(hoTen) > 0) ? hoTen : DEFAULT_HOTEN;
    hoTen = new char[strlen(hoTen_ptr) + 1];
    strcpy(HoTen, hoTen_ptr);
}

SinhVien::SinhVien(const char *mssv, const char *hoTen, float dlt, float dth, NgayThang ns)
{
    DLT = dlt;
    DTH = dth;
    NgaySinh = ns;
    const char *mssv_ptr = (mssv != nullptr && strlen(mssv) > 0) ? mssv : DEFAULT_MSSV;
    MSSV = new char[strlen(mssv_ptr) + 1];
    strcpy(MSSV, mssv_ptr);
    const char *hoTen_ptr = (hoTen != nullptr && strlen(hoTen) > 0) ? hoTen : DEFAULT_HOTEN;
    hoTen = new char[strlen(hoTen_ptr) + 1];
    strcpy(HoTen, hoTen_ptr);
}

SinhVien::SinhVien(const SinhVien &other)
{
    this->MSSV = new char[strlen(other.MSSV) + 1];
    strcpy(this->MSSV, other.MSSV);
    this->HoTen = new char[strlen(other.HoTen) + 1];
    strcpy(this->HoTen, other.HoTen);
    this->NgaySinh = other.NgaySinh;
    this->DTH = other.DTH;
    this->DLT = other.DLT;
}

SinhVien::~SinhVien()
{
    delete[] MSSV;
    delete[] HoTen;
}
