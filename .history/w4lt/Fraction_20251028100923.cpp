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
    int new_num = num * frac.denom + frac.num * denom;
    int new_denom = denom * frac.denom;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator-(const Fraction &frac)
{
    int new_num = num * frac.denom - frac.num * denom;
    int new_denom = denom * frac.denom;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator*(const Fraction &frac)
{
    int new_num = num * frac.num;
    int new_denom = denom * frac.denom;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator/(const Fraction &frac)
{
    int new_num = num * frac.denom;
    int new_denom = denom * frac.num;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator+(const int &a)
{
    return *this + Fraction(a);
}

Fraction Fraction::operator-(const int &a)
{
    return *this - Fraction(a);
}

Fraction Fraction::operator*(const int &a)
{
    return (*this) * Fraction(a);
}
Fraction Fraction::operator/(const int &a)
{
    return (*this) / Fraction(a);
}

bool Fraction::operator==(const Fraction &frac)
{
    return (num == frac.num) && (denom == frac.denom);
}

bool Fraction::operator==(const int &a)
{
    return (*this == Fraction(a));
}

bool Fraction::operator!=(const Fraction &frac)
{
    return !(*this == frac);
}

bool Fraction::operator!=(const int &a)
{
    return !(*this == Fraction(a));
}
