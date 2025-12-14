#include "Fraction.h"
#include <iostream>
using namespace std;

int main()
{
    Fraction a, b;
    cout << "Nhap phan so a:\n";
    cin >> a;
    cout << "Nhap phan so b:\n";
    cin >> b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    cout << "++a = " << ++a << endl;
    cout << "b++ = " << b++ << endl;
    cout << "b sau khi ++ = " << b << endl;

    return 0;
}
