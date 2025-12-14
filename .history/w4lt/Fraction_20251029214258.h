#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <numeric> // Dùng cho std::abs, hoặc std::gcd nếu dùng C++17

using namespace std;

template <typename T>
T gcd(T a, T b)
{
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0)
    {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

template <typename T>
class Fraction
{
private:
    T num;
    T denom;
    void rutgon();

public:
    Fraction();
    Fraction(const Fraction<T> &other);
    Fraction(const T &t, const T &m);
    Fraction(const T &n);

    ~Fraction();

    Fraction<T> operator+(const Fraction<T> &frac);
    Fraction<T> operator+(const T &a);
    Fraction<T> operator-(const Fraction<T> &frac);
    Fraction<T> operator-(const T &a);
    Fraction<T> operator*(const Fraction<T> &frac);
    Fraction<T> operator*(const T &a);
    Fraction<T> operator/(const Fraction<T> &frac);
    Fraction<T> operator/(const T &a);

    bool operator==(const Fraction<T> &frac);
    bool operator==(const T &a);
    bool operator!=(const Fraction<T> &frac);
    bool operator!=(const T &a);
    bool operator>(const Fraction<T> &frac);
    bool operator>(const T &a);
    bool operator<(const Fraction<T> &frac);
    bool operator<(const T &a);
    bool operator>=(const Fraction<T> &frac);
    bool operator>=(const T &a);
    bool operator<=(const Fraction<T> &frac);
    bool operator<=(const T &a);

    Fraction<T> &operator++();
    Fraction<T> operator++(int);
    Fraction<T> &operator--();
    Fraction<T> operator--(int);

    Fraction<T> &operator=(const Fraction<T> &frac);
    Fraction<T> &operator+=(const Fraction<T> &frac);
    Fraction<T> &operator*=(const Fraction<T> &frac);

    template <typename U>
    friend istream &operator>>(istream &in, Fraction<U> &frac);
    template <typename U>
    friend ostream &operator<<(ostream &out, const Fraction<U> &frac);
};

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

template <typename T>
Fraction<T>::Fraction(const T &n)
{
    num = n;
    denom = 1;
}
template <typename T>
Fraction<T>::~Fraction() {}

template <typename T>
Fraction<T> Fraction<T>::operator+(const Fraction<T> &frac)
{
    T new_num = num * frac.denom + frac.num * denom;
    T new_denom = denom * frac.denom;
    return Fraction(new_num, new_denom);
}

template <typename T>
Fraction<T> Fraction<T>::operator-(const Fraction<T> &frac)
{
    T new_num = num * frac.denom - frac.num * denom;
    T new_denom = denom * frac.denom;
    return Fraction(new_num, new_denom);
}

template <typename T>
Fraction<T> Fraction<T>::operator*(const Fraction<T> &frac)
{
    T new_num = num * frac.num;
    T new_denom = denom * frac.denom;
    return Fraction(new_num, new_denom);
}

template <typename T>
Fraction<T> Fraction<T>::operator/(const Fraction<T> &frac)
{
    if (frac.num == 0)
    {
        cerr << "Loi: Chia cho 0. Dat mac dinh 0/1" << endl;
        return Fraction(0, 1);
    }
    T new_num = num * frac.denom;
    T new_denom = denom * frac.num;
    return Fraction(new_num, new_denom);
}

template <typename T>
Fraction<T> Fraction<T>::operator+(const T &a)
{
    return *this + Fraction(a);
}

template <typename T>
Fraction<T> Fraction<T>::operator-(const T &a)
{
    return *this - Fraction(a);
}

template <typename T>
Fraction<T> Fraction<T>::operator*(const T &a)
{
    return (*this) * Fraction(a);
}

template <typename T>
Fraction<T> Fraction<T>::operator/(const T &a)
{
    return (*this) / Fraction(a);
}

template <typename T>
bool Fraction<T>::operator==(const Fraction<T> &frac)
{
    return (num == frac.num) && (denom == frac.denom);
}

template <typename T>
bool Fraction<T>::operator==(const T &a)
{
    return (*this == Fraction(a));
}

template <typename T>
bool Fraction<T>::operator!=(const Fraction<T> &frac)
{
    return !(*this == frac);
}

template <typename T>
bool Fraction<T>::operator!=(const T &a)
{
    return !(*this == Fraction(a));
}

template <typename T>
bool Fraction<T>::operator>(const Fraction<T> &frac)
{
    return (this->num * frac.denom) > (frac.num * this->denom);
}

template <typename T>
bool Fraction<T>::operator>(const T &a)
{
    return *this > Fraction(a);
}

template <typename T>
bool Fraction<T>::operator<(const Fraction<T> &frac)
{
    return (this->num * frac.denom) < (frac.num * this->denom);
}

template <typename T>
bool Fraction<T>::operator<(const T &a)
{
    return *this < Fraction(a);
}

template <typename T>
bool Fraction<T>::operator>=(const Fraction<T> &frac)
{
    return (*this > frac) || (*this == frac);
}

template <typename T>
bool Fraction<T>::operator>=(const T &a)
{
    return *this >= Fraction(a);
}

template <typename T>
bool Fraction<T>::operator<=(const Fraction<T> &frac)
{
    return !(*this > frac);
}

template <typename T>
bool Fraction<T>::operator<=(const T &a)
{
    return *this <= Fraction(a);
}

template <typename T>
Fraction<T> &Fraction<T>::operator++()
{
    num += denom;
    return *this;
}

template <typename T>
Fraction<T> Fraction<T>::operator++(int)
{
    Fraction<T> tmp = *this;
    num += denom;
    return tmp;
}

template <typename T>
Fraction<T> &Fraction<T>::operator--()
{
    num -= denom;
    return *this;
}

template <typename T>
Fraction<T> Fraction<T>::operator--(int)
{
    Fraction<T> tmp = *this;
    num -= denom;
    return tmp;
}

template <typename T>
Fraction<T> &Fraction<T>::operator=(const Fraction<T> &frac)
{
    if (this != &frac)
    {
        this->num = frac.num;
        this->denom = frac.denom;
    }
    return *this;
}

template <typename T>
Fraction<T> &Fraction<T>::operator+=(const Fraction<T> &frac)
{
    this->num = this->num * frac.denom + this->denom * frac.num;
    this->denom *= frac.denom;
    this->rutgon();
    return *this;
}

template <typename T>
Fraction<T> &Fraction<T>::operator*=(const Fraction<T> &frac)
{
    this->num *= frac.num;
    this->denom *= frac.denom;
    this->rutgon();
    return *this;
}

template <typename T>
istream &operator>>(istream &in, Fraction<T> &frac)
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

template <typename T>
ostream &operator<<(ostream &out, const Fraction<T> &frac)
{
    if (frac.denom == 1)
    {
        out << frac.num;
    }
    else
        out << frac.num << "/" << frac.denom;
    return out;
}

template <typename T>
void Fraction<T>::rutgon()
{
    if (denom < 0)
    {
        num = -num;
        denom = -denom;
    }
    if (num == 0)
    {
        denom = 1;
        return;
    }
    T ucln = gcd(num, denom);
    if (ucln > 1)
    {
        num /= ucln;
        denom /= ucln;
    }
}

#endif