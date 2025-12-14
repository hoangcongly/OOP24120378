#include "Fraction.h"

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

void Fraction::rutgon()
{
    int ucln = gcd(num, denom);
    num /= ucln;
    denom /= ucln;
    if (denom < 0)
    {
        num = -num;
        denom = -denom;
    }
}

Fraction Fraction::operator+(const Fraction &frac)
{
    int new_num = num * frac.denom + frac.num * denom;
    int new_denom = denom * frac.denom;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator+(const int &a)
{
    return *this + Fraction(a);
}

Fraction Fraction::operator-(const Fraction &frac)
{
    int new_num = num * frac.denom - frac.num * denom;
    int new_denom = denom * frac.denom;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator-(const int &a)
{
    return *this - Fraction(a);
}

Fraction Fraction::operator*(const Fraction &frac)
{
    int new_num = num * frac.num;
    int new_denom = denom * frac.denom;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator*(const int &a)
{
    return *this * Fraction(a);
}

Fraction Fraction::operator/(const Fraction &frac)
{
    if (frac.num == 0)
    {
        cerr << "Loi: Chia cho phan so co tu = 0. Tra ve 0/1." << endl;
        return Fraction(0, 1);
    }
    int new_num = num * frac.denom;
    int new_denom = denom * frac.num;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator/(const int &a)
{
    return *this / Fraction(a);
}

bool Fraction::operator==(const Fraction &frac)
{
    return num * frac.denom == frac.num * denom;
}

bool Fraction::operator==(const int &a)
{
    return *this == Fraction(a);
}

bool Fraction::operator!=(const Fraction &frac)
{
    return !(*this == frac);
}

bool Fraction::operator!=(const int &a)
{
    return !(*this == a);
}

bool Fraction::operator>(const Fraction &frac)
{
    return num * frac.denom > frac.num * denom;
}

bool Fraction::operator>(const int &a)
{
    return *this > Fraction(a);
}

bool Fraction::operator<(const Fraction &frac)
{
    return num * frac.denom < frac.num * denom;
}

bool Fraction::operator<(const int &a)
{
    return *this < Fraction(a);
}

bool Fraction::operator>=(const Fraction &frac)
{
    return !(*this < frac);
}

bool Fraction::operator>=(const int &a)
{
    return !(*this < a);
}

bool Fraction::operator<=(const Fraction &frac)
{
    return !(*this > frac);
}

bool Fraction::operator<=(const int &a)
{
    return !(*this > a);
}

Fraction &Fraction::operator++()
{
    num += denom;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    ++(*this);
    return temp;
}

Fraction &Fraction::operator--()
{
    num -= denom;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(*this);
    --(*this);
    return temp;
}

Fraction &Fraction::operator=(const Fraction &frac)
{
    if (this != &frac)
    {
        num = frac.num;
        denom = frac.denom;
    }
    return *this;
}

Fraction &Fraction::operator+=(const Fraction &frac)
{
    *this = *this + frac;
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &frac)
{
    *this = *this * frac;
    return *this;
}

Fraction::operator int() const
{
    return num / denom;
}

Fraction::operator float() const
{
    return (float)num / (float)denom;
}

istream &operator>>(istream &in, Fraction &frac)
{
    cout << "Nhap tu so: ";
    in >> frac.num;
    cout << "Nhap mau so: ";
    in >> frac.denom;
    if (frac.denom == 0)
    {
        cerr << "Loi: Mau so khong duoc bang 0. Dat lai thanh 1." << endl;
        frac.denom = 1;
    }
    frac.rutgon();
    return in;
}

ostream &operator<<(ostream &out, const Fraction &frac)
{
    if (frac.denom == 1)
        out << frac.num;
    else
        out << frac.num << "/" << frac.denom;
    return out;
}
