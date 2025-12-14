#ifndef SONGUYENLON_H
#define SONGUYENLON_H

#include <iostream>
#include "SLList.h"

using namespace std;

class SoNguyenLon
{
private:
    SLList<unsigned char> lCS;
    void Pow10(const int &n);

public:
    SoNguyenLon(void);
    SoNguyenLon(const int &cs, const int &scs);
    SoNguyenLon(const unsigned long &n);
    SoNguyenLon(const SoNguyenLon &snl);
    SoNguyenLon(const char *s);
    ~SoNguyenLon();

    int SoCS() const;
    SoNguyenLon operator+(SoNguyenLon snl) const;
    SoNguyenLon operator-(SoNguyenLon snl) const;
    SoNguyenLon operator*(SoNguyenLon snl) const;
    bool operator>(const SoNguyenLon &snl) const;
    const SoNguyenLon &operator=(const SoNguyenLon &snl);
    SoNguyenLon &operator+=(SoNguyenLon snl);
    friend SoNguyenLon operator+(const unsigned int &n, const SoNguyenLon &snl);
    friend SoNguyenLon operator-(const unsigned int &n, const SoNguyenLon &snl);
    friend ostream &operator<<(ostream &os, const SoNguyenLon &snl);
};
#endif