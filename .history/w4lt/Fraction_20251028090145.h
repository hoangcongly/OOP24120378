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
    Fraction(int t, int m);
    Fraction(const int &n);

    ~Fraction();

    Fraction operator+(const Fraction &frac);
    Fraction operator-(const Fraction &frac);
    Fraction operator*(const Fraction &frac);
    Fraction operator/(const Fraction &frac);

    bool operator==(const Fraction &frac);
    // bool operator==(int a);
    bool operator!=(const Fraction &frac);
    bool operator>(const Fraction &frac);
    bool operator<(const Fraction &frac);
    bool operator>=(const Fraction &frac);
    bool operator<=(const Fraction &frac);

    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);

    Fraction &operator=(const Fraction &frac);
    Fraction &operator+=(const Fraction &frac);
    Fraction &operator*=(const Fraction &frac);

    friend istream &operator>>(istream &in, Fraction &frac);
    friend ostream &operator<<(ostream &out, const Fraction &frac);
};

#endif