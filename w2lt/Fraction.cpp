#include "Fraction.h"

int Fraction:: gcd(int a, int b) const
{
    a= abs(a);
    b= abs(b);
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
void Fraction::normalize()
{
    if(denominator<0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}
Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}
Fraction::Fraction(int nume, int deno)
{
    if (deno == 0)
    {
        cout << "Loi mau so bang 0, tu dong gan bang 1\n";
        numerator=0;
        denominator=1;
    }
    else
    {
        numerator=nume;
        denominator=deno;
    }
    normalize();
}
Fraction::Fraction(const string&fracStr)
{
    int pos=fracStr.find('/');
    if(pos!=string::npos)
    {
        string numStr= fracStr.substr(0, pos);
        string denStr= fracStr.substr(pos+1);
        numerator = stoi(numStr);
        denominator = stoi(denStr);
    }
    else
    {
        numerator = stoi(fracStr);
        denominator=1;
    }
    if(denominator==0)
    {
        cerr << "Loi mau so bang 0, tu dong gan bang 1\n";
        denominator=1;
    }
    normalize();
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
    if(den==0)
    {
        cerr << "Loi mau so khong the bang 0, giu nguyen gia tri\n";
        return;
    }
    denominator = den;
    normalize();
}

Fraction Fraction::reduce()
{
    if(numerator==0)
    {
        return Fraction(0,1);
    }
    int rut_gon= gcd(numerator, denominator);   
    return Fraction(numerator/rut_gon, denominator/rut_gon);
}
Fraction Fraction::inverse() const 
{
    if(numerator==0)
    {
        cerr<< "Loi khong the dao nguoc phan so 0/x\n";
    }
    return Fraction(denominator, numerator);
}
Fraction Fraction::add(const Fraction &other)
{
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDen = denominator * other.denominator;
    return Fraction(newNum, newDen).reduce();
}
int Fraction::compare(const Fraction &other) const
{
    int a = numerator * other.denominator;
    int b = other.numerator * denominator;
    if(a==b) return 0;
    else if(a<b) return -1;
    else return 1;
}