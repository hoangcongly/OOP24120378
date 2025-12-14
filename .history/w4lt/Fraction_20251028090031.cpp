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

Fraction:: ~Fraction();

Fraction:: operator+(const Fraction& frac) 
{
    return Fraction(num+frac.num, denom+ frac.denom);
}