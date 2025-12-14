#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int nume, int deno);
    Fraction(const Fraction &frac);
    ~Fraction();
    void input();
    void output();
    int getNum() const;
    void setNum(const int &num);
    int getDenom() const;
    void setDenom(const int &den);
    Fraction reduce();
    Fraction inverse();
    Fraction add(const Fraction &other);
    int compare(const Fraction &other);
};
#endif