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
    char* MSSV;
    char* HoTen;
    NgayThang NgaySinh;
    float DLT;
    float DTH;
public:
    SinhVien();
    SinhVien(const char*&MSSV);
    
};

#endif 