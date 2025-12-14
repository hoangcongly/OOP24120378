#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
    int gcd(int a, int b) const;
    void normalize();

public:
    Fraction();
    Fraction(int nume, int deno);
    Fraction(const Fraction &frac);
    Fraction(int val);
    Fraction(const string&fracStr);
    ~Fraction();

    void input();
    void output();
    int getNum() const;
    void setNum(const int &num);
    int getDenom() const;
    void setDenom(const int &den);
    Fraction reduce();
    Fraction inverse() const;
    Fraction add(const Fraction &other);
    int compare(const Fraction &other);
};
#endif