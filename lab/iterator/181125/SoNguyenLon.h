#ifndef SONGUYENLON_H
#define SONGUYENLON_H

#include <iostream>
#include "SLList.h"
#include <cstring>
#include <cstdlib>

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

void SoNguyenLon::Pow10(const int &n)
{
    for (int i = 0; i < n; ++i)
    {
        lCS.insert(lCS.begin(), 0);
    }
}

SoNguyenLon::SoNguyenLon(void)
{
    lCS.push_back(0);
}

SoNguyenLon::SoNguyenLon(const int &cs, const int &scs)
{
    int csR = cs;
    if (csR < 1)
    {
        csR = 1;
    }
    if (csR > 9)
    {
        csR = 9;
    }
    int soCS = abs(scs);
    if (soCS < 1)
    {
        soCS = 1;
    }
    for (int i = 0; i < soCS; ++i)
    {
        lCS.push_back(csR);
    }
}

SoNguyenLon::SoNguyenLon(const unsigned long &n)
{
    unsigned long temp = n;
    if (temp == 0)
    {
        lCS.push_back(0);
        return;
    }
    while (temp > 0)
    {
        lCS.push_back(temp % 10);
        temp /= 10;
    }
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon &snl)
{
    lCS = snl.lCS;
}

SoNguyenLon::SoNguyenLon(const char *s)
{
    if (s == nullptr || s[0] == '\0')
    {
        lCS.push_back(0);
        return;
    }
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            unsigned char digit = s[i] - '0';
            lCS.AddHead(digit);
        }
    }
}

SoNguyenLon::~SoNguyenLon() {}

int SoNguyenLon::SoCS() const
{
    return lCS.size();
}
bool SoNguyenLon::operator>(const SoNguyenLon &snl) const
{
    if (lCS.size() > snl.lCS.size())
    {
        return true;
    }
    if (lCS.size() < snl.lCS.size())
    {
        return false;
    }
    for (int i = lCS.size() - 1; i >= 0; --i)
    {
        if (lCS[i] == snl.lCS[i])
        {
            continue;
        }
        if (lCS[i] > snl.lCS[i])
        {
            return true;
        }
        return false;
    }
    return false;
}

const SoNguyenLon &SoNguyenLon::operator=(const SoNguyenLon &snl)
{
    lCS = snl.lCS;
    return *this;
}

SoNguyenLon &SoNguyenLon::operator+=(SoNguyenLon snl)
{
    auto it1 = this->lCS.begin();
    auto it2 = snl.lCS.begin();
    int nho = 0, temp = 0;
    while (it1 != lCS.end() || it2 != lCS.end())
    {
        int val1 = (it1 != lCS.end()) ? *it1 : 0;
        int val2 = (it2 != lCS.end()) ? *it2 : 0;
        temp = val1 + val2 + nho;
        nho = temp / 10;
        if (it1 != lCS.end())
        {
            *it1 = temp % 10;
            ++it1;
        }
        else
        {
            lCS.push_back(temp % 10);
            it1 = lCS.end();
        }
        if (it2 != snl.lCS.end())
        {
            ++it2;
        }
    }
    if (nho > 0)
    {
        lCS.push_back(nho);
    }
    return *this;
}

SoNguyenLon SoNguyenLon::operator+(SoNguyenLon snl) const
{
    SoNguyenLon snlKQ;
    snlKQ.lCS.Clear();
    const SoNguyenLon *snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
    const SoNguyenLon *snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;

    int nho = 0, temp;
    for (int i = 0; i < snlSCSMin->SoCS(); i++)
    {
        temp = lCS[i] + snl.lCS[i] + nho;
        snlKQ.lCS.push_back(temp % 10);
        nho = temp / 10;
    }
    for (int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); ++i)
    {
        temp = snlSCSMax->lCS[i] + nho;
        snlKQ.lCS.push_back(temp % 10);
        nho = temp / 10;
    }
    if (nho > 0)
    {
        snlKQ.lCS.push_back(1);
    }
    return snlKQ;
}

SoNguyenLon SoNguyenLon::operator-(SoNguyenLon snl) const
{
    if (snl > *this)
    {
        return SoNguyenLon();
    }
    SoNguyenLon snlKQ;
    snlKQ.lCS.Clear();
    auto it1 = this->lCS.begin();
    auto it2 = snl.lCS.begin();
    int muon = 0, temp = 0;
    while (it1 != this->lCS.end())
    {
        int digit1 = *it1;
        int digit2 = (it2 != snl.lCS.end()) ? *it2 : 0;
        int diff = digit1 - digit2 - muon;
        if (diff < 0)
        {
            diff += 10;
            muon = 1;
        }
        else
        {
            muon = 0;
        }
        snlKQ.lCS.push_back(diff);
        it1++;
        if (it2 != snl.lCS.end())
        {
            it2++;
        }
    }
    while (snlKQ.lCS.size() > 1 && snlKQ.lCS.back() == 0)
    {
        snlKQ.lCS.RemoveTail();
    }
    return snlKQ;
}

SoNguyenLon SoNguyenLon::operator*(SoNguyenLon snl) const
{
    SoNguyenLon snlKQ, *psnlTemp;
    const SoNguyenLon *snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
    const SoNguyenLon *snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
    int nho = 0, temp;
    for (int i = 0; i < snlSCSMin->SoCS(); ++i)
    {
        psnlTemp = new SoNguyenLon;
        psnlTemp->lCS.Clear();
        nho = 0;
        for (int j = 0; j < snlSCSMax->SoCS(); ++j)
        {
            temp = snlSCSMin->lCS[i] * snlSCSMax->lCS[j] + nho;
            psnlTemp->lCS.push_back(temp % 10);
            nho = temp / 10;
        }
        if (nho > 0)
        {
            psnlTemp->lCS.push_back(nho);
        }
        psnlTemp->Pow10(i);
        snlKQ += *psnlTemp;
        delete psnlTemp;
    }
    return snlKQ;
}

SoNguyenLon operator+(const unsigned int &n, const SoNguyenLon &snl)
{
    return snl + SoNguyenLon(n);
}

SoNguyenLon operator-(const unsigned int &n, const SoNguyenLon &snl)
{
    return SoNguyenLon(n) - snl;
}

ostream &operator<<(ostream &os, const SoNguyenLon &snl)
{
    for (int i = snl.lCS.size() - 1; i >= 0; i--)
    {
        os << (int)snl.lCS[i];
    }
    return os;
}
#endif