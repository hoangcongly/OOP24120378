#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class HinhHocPhang
{
public:
    virtual double dienTich() const = 0;
    virtual double chuVi() const = 0;
    virtual char *loai() const = 0;
};