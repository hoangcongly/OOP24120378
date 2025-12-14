#include "Fraction.h"

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}
Fraction::Fraction(int nume, int deno)
{
    if (deno == 0)
    {
        cout << "Loi: Mau so bang 0! Tu dong gan ve 1.\n";
        deno = 1;
    }
    if (deno < 0)
    {
        nume = -nume;
        deno = -deno;
    }
    numerator = nume;
    denominator = deno;
}
Fraction::Fraction(const Fraction &frac)
{
    
    numerator = frac.numerator;
    denominator = frac.denominator;
}
Fraction::~Fraction() {};
void Fraction::input()
{
    cout << "Nhap tu va mau: ";
    cin >> numerator >> denominator;
}
void Fraction::output()
{
    cout << numerator << "/" << denominator << endl;
}
int Fraction::getNum() const
{
    return numerator;
}
void Fraction::setNum(const int &num)
{
    numerator = num;
}
int Fraction::getDenom() const
{
    return denominator;
}
void Fraction::setDenom(const int &den)
{
    denominator = den;
}

Fraction Fraction::reduce()
{
    int a = abs(numerator);
    int b = abs(denominator);
    while (b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    Fraction res(numerator / a, denominator / a);
    if (res.denominator < 0)
    {
        res.denominator *= -1;
        res.numerator *= -1;
    }
    return res;
}
Fraction Fraction::inverse()
{
    return Fraction(denominator, numerator);
}
Fraction Fraction::add(const Fraction &other)
{
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDen = denominator * other.denominator;
    return Fraction(newNum, newDen).reduce();
}
int Fraction::compare(const Fraction &other)
{
    int left = numerator * other.denominator;
    int right = other.numerator * denominator;
    return left - right;
}