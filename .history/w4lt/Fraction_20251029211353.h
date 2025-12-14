#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

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
    Fraction<T> operator++(T);
    Fraction<T> &operator--();
    Fraction<T> operator--(T);

    Fraction<T> &operator=(const Fraction<T> &frac);
    Fraction<T> &operator+=(const Fraction<T> &frac);
    Fraction<T> &operator*=(const Fraction<T> &frac);

    friend istream &operator>>(istream &in, Fraction<T> &frac);
    friend ostream &operator<<(ostream &out, const Fraction<T> &frac);
};

#endif