#ifndef SONGUYENLON_H
#define SONGUYENLON_H

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LENGTH 100
#define MAX_SNL 100
class SoNguyenLon
{
private:
    char digit[MAX_LENGTH];
    int length;
    static SoNguyenLon *DS_SNL[MAX_SNL];
    static int DS_size;
    void init_zero();
    void trimLeadingZeros();

public:
    SoNguyenLon();
    SoNguyenLon(const char *str);
    SoNguyenLon(int num1, int num2);
    ~SoNguyenLon();
    int compare(const SoNguyenLon &other);
    SoNguyenLon Cong(const SoNguyenLon &other);
    SoNguyenLon Tru(const SoNguyenLon &other);
    static SoNguyenLon HieuVoiHangSo(const long long &dig, const SoNguyenLon &other);
    static SoNguyenLon SNLMAX(const SoNguyenLon *DS_SNL[], int size);
};

#endif