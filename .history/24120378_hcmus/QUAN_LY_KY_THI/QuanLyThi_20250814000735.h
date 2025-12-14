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

#endif // QUANLYTHI_H