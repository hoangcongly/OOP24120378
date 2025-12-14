#include <iostream>
#include "Fraction.h"

using namespace std;

int main() 
{
    Fraction f0;
    cout << "Phan so mac dinh: ";
    f0.output();

    Fraction f1(3, 4);
    cout << "Phan so 3/4: ";
    f1.output();

    f1.setNum(5);
    f1.setDenom(6);
    cout << "Sau setNum(5) va setDenom(6): ";
    f1.output();

    Fraction fStr1("-7/3");
    cout << "Phan so tu chuoi \"-7/3\": ";
    fStr1.output();

    Fraction fCopy = fStr1;
    cout << "Phan so copy cua \"-7/3\": ";
    fCopy.output();

    Fraction fErr(3, 0);
    cout << "Phan so co mau bang 0 (3,0): ";
    fErr.output();

    cout << "Nhap mot phan so (tu va mau): ";
    Fraction fInput;
    fInput.input();
    cout << "Ban vua nhap: ";
    fInput.output();

    Fraction fRed = fInput.reduce();
    cout << "Phan so rut gon: ";
    fRed.output();

    Fraction fInv = fInput.inverse();
    cout << "Phan so dao nguoc: ";
    fInv.output();

    Fraction a(1, 2), b(2, 3);
    cout << "a = "; a.output();
    cout << "b = "; b.output();
    Fraction sum = a.add(b);
    cout << "a + b = ";
    sum.output();

    int cmp = a.compare(b);
    if (cmp == 0)
        cout << "a va b bang nhau\n";
    else if (cmp < 0)
        cout << "a nho hon b\n";
    else
        cout << "a lon hon b\n";

    return 0;
}
