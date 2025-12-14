#ifndef HOCSINH_H
#define HOCSINH_H

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_HS 100

class HocSinh
{
private:
    char *hoTen;
    float d1, d2, d3;
    int maSo;
    static int SL_HocSinh;
    static HocSinh *DS_HocSinh[MAX_HS];
    static int NextMS;

public:
    HocSinh();
    HocSinh(const char *&ten, const float &n1, const float &n2, const float &n3);
    void DatHoTen(char *name);
    void GanDiem(const float &n1, const float &n2, const float &n3);
    void In();
    float DiemTB();
    static HocSinh HSDiemTBCaoNhat();
    ~HocSinh();
};

#endif