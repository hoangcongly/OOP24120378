#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
using namespace std;

class Fraction
{
private:
    int num;
    int denom;
    void rutgon();

public:
    Fraction();
    Fraction(const Fraction &other);
    Fraction(const int &t, const int &m);

    ~Fraction();

    Fraction operator+(const Fraction &frac);
    Fraction operator-(const Fraction &frac);
    Fraction operator*(const Fraction &frac);
    Fraction operator/(const Fraction &frac);

    bool operator==(const Fraction &frac);
    bool operator!=(const Fraction &frac);
    bool operator>(const Fraction &frac);
    bool operator<(const Fraction &frac);
    bool operator>=(const Fraction &frac);
    bool operator<=(const Fraction &frac);

    Fraction &operator++();
    Fraction &operator--();

    Fraction &operator=(const Fraction &frac);
    Fraction &operator+=(const Fraction &frac);
    Fraction &operator*=(const Fraction &frac);
};

#endif