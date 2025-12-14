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
