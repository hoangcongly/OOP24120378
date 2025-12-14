#ifndef HOCSINH_H
#define HOCSINH_H

#include <iostream>
#include <cstring>
using namespace std;

class HocSinh
{
private:
    char *hoTen;
    float d1, d2, d3;
    int size_ds;
    HocSinh *DS_HocSinh;
    static int NextMS;

public:
    HocSinh();
    HocSinh(const char *ten, const float &n1, const float &n2, const float &n3);
    void DatHoTen(const char *name);
    void GanDiem(const float &n1, const float &n2, const float &n3);
    void In();
    static HocSinh HSDiemTBCaoNhat();
};

#endif