#ifndef _So_Phuc_h
#define _So_Phuc_h

#include <iostream>
#include <vector>

using namespace std;

class SoPhuc
{
private:
    double thuc;
    double ao;
public:
    SoPhuc();
    SoPhuc(double t, double a);

    SoPhuc operator+(const SoPhuc&) const;
    SoPhuc operator-(const SoPhuc&) const;
    SoPhuc operator*(const SoPhuc&) const;
    SoPhuc operator/(const SoPhuc&) const;

    bool operator==(const SoPhuc&) const;
    bool operator!=(const SoPhuc&) const;

    friend ostream&operator << (ostream&, const SoPhuc&);
    friend istream&operator >> (istream&, SoPhuc&);
};

#endif 