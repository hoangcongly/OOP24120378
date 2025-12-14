#include "Fraction.h"

Fraction::Fraction()
{
    num = 0;
    denom = 1;
}

Fraction::Fraction(const Fraction &other)
{
    num = other.num;
    denom = other.denom;
    rutgon();
}

Fraction::Fraction(const int &t, const int &m)
{
    num = t;
    denom = m;
    rutgon();
}

Fraction::Fraction(const int &n)
{
    num = n;
    denom = 1;
}

Fraction::~Fraction() {}

Fraction Fraction::operator+(const Fraction &frac)
{
    Fraction result;
    result.num = num * frac.denom + frac.num * denom;
    result.denom = denom * frac.denom;
    rutgon();
    return result;
}

Fraction Fraction::operator-(const Fraction &frac)
{
    Fraction result;
    result.num = num * frac.denom - frac.num * denom;
    result.denom = denom * frac.denom;
    rutgon();
    return result;
}

Fraction Fraction::operator*(const Fraction &frac)
{
    Fraction result;
    result.num = num * frac.num;
    result.denom = denom * frac.denom;
    Fraction::rutgon();
    return result;
}

Fraction Fraction::operator/(const Fraction &frac)
{
    Fraction result;
    result.num = num * frac.denom;
    result.denom = denom * frac.num;
    rutgon();
    return result;
}

bool Fraction::operator==(const Fraction &frac)
{
    
}