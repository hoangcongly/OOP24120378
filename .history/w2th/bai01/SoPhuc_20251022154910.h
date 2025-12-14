#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc
{
private:
    int thuc, ao;
    int sl;
    static int ssl;

public:
    SoPhuc();
    SoPhuc(const int &th, const int &a);
    SoPhuc(const SoPhuc &sp);
    ~SoPhuc();

    SoPhuc Cong(const SoPhuc &sp);
    int SoLuongSP();
    static int SSoLuongSP();
};

#endif