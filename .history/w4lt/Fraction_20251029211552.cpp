#include "Fraction.h"
template <typename T>
Fraction<T>::Fraction()
{
    num = 0;
    denom = 1;
}

template <typename T>
Fraction<T>::Fraction(const Fraction<T> &other)
{
    num = other.num;
    denom = other.denom;
    rutgon();
}

template <typename T>
Fraction<T>::Fraction(const T &t, const T &m)
{
    if (m == 0)
    {
        cerr << "Loi: Mau so khong duoc bang 0. Dat mac dinh 0/1" << endl;
        num = 0;
        denom = 1;
    }
    else
    {
        num = t;
        denom = m;
        rutgon();
    }
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
    if (frac.num == 0)
    {
        cerr << "Loi: Mau so khong duoc bang 0. Dat mac dinh 0/1" << endl;
        return Fraction(0, 1);
    }
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

bool Fraction::operator>(const Fraction &frac)
{
    return (this->num * frac.denom) > (frac.num * this->denom);
}

bool Fraction::operator>(const int &a)
{
    return *this > Fraction(a);
}

bool Fraction::operator<(const Fraction &frac)
{
    return (this->num * frac.denom) < (frac.num * this->denom);
}

bool Fraction::operator<(const int &a)
{
    return *this < Fraction(a);
}

bool Fraction::operator>=(const Fraction &frac)
{
    return (*this > frac) || (*this == frac);
}

bool Fraction::operator>=(const int &a)
{
    return *this >= Fraction(a);
}

bool Fraction::operator<=(const Fraction &frac)
{
    return !(*this > frac);
}

bool Fraction::operator<=(const int &a)
{
    return *this <= Fraction(a);
}

Fraction &Fraction::operator++()
{
    num += denom;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction tmp = *this;
    num += denom;
    return tmp;
}

Fraction &Fraction::operator--()
{
    num -= denom;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction tmp = *this;
    num -= denom;
    return tmp;
}

Fraction &Fraction::operator=(const Fraction &frac)
{
    if (this != &frac)
    {
        this->num = frac.num;
        this->denom = frac.denom;
    }
    return *this;
}

Fraction &Fraction::operator+=(const Fraction &frac)
{
    this->num = this->num * frac.denom + this->denom * frac.num;
    this->denom *= frac.denom;
    this->rutgon();
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &frac)
{
    this->num *= frac.num;
    this->denom *= frac.denom;
    this->rutgon();
    return *this;
}

istream &operator>>(istream &in, Fraction &frac)
{
    in >> frac.num;
    if (in.peek() == '/')
    {
        char slash;
        in >> slash;
        in >> frac.denom;
        if (frac.denom == 0)
        {
            cerr << "Loi: Mau so khong duoc bang 0. Dat mac dinh 0/1" << endl;
            frac.num = 0;
            frac.denom = 1;
        }
    }
    else
        frac.denom = 1;
    frac.rutgon();
    return in;
}

ostream &operator<<(ostream &out, const Fraction &frac)
{
    if (frac.denom == 1)
    {
        out << frac.num;
    }
    else
        out << frac.num << "/" << frac.denom;
    return out;
}

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::rutgon()
{
    if (denom < 0)
    {
        num = -num;
        denom = -denom;
    }
    int ucln = gcd(num, denom);
    if (ucln > 1)
    {
        num /= ucln;
        denom /= ucln;
    }
}
