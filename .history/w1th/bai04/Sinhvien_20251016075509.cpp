#include "SinhVien.h"

SinhVien::SinhVien()
{
    const char *default_mssv = "xxxxxxx";
    MSSV = new char[strlen(default_mssv) + 1];
    strcpy(MSSV, default_mssv);
    const char *default_hoTen = "xxxx";
    HoTen = new char[strlen(default_hoTen) + 1];
    strcpy(HoTen, default_hoTen);
    NgaySinh = NgayThang(1, 1, 2000);
    DTH = 10.0f;
    DLT = 10.0f;
}

SinhVien::SinhVien()