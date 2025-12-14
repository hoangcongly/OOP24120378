#include "Array.h"
#include <iostream>
using namespace std;

int main()
{
    Array a, b, c;
    cout << "Nhap mang a:\n";
    cin >> a;
    cout << "Nhap mang b:\n";
    cin >> b;

    cout << "Mang a = " << a << endl;
    cout << "Mang b = " << b << endl;

    cout << "\ntoan tu +:\n";
    c = a + b;
    cout << "a + b = " << c << endl;

    cout << "\ntoan tu +=:\n";
    a += b;
    cout << "a sau khi a += b: " << a << endl;

    cout << "\ntoan tu = (gan bang):\n";
    Array d;
    d = c;
    cout << "d = c = " << d << endl;

    cout << "\nt toan tu [] (truy cap phan tu):\n";
    if (a.operator int *() != nullptr && a[0] >= 0)
    {
        cout << "a[0] = " << a[0] << endl;
        cout << "Nhap gia tri moi cho a[0]: ";
        cin >> a[0];
        cout << "a sau khi sua: " << a << endl;
    }

    cout << "\nchuyen kieu operator int*():\n";
    int *p = a;
    if (p != nullptr)
        cout << "Dia chi mang a (int*): " << p << endl;

    cout << "\nsao chep (copy constructor):\n";
    Array e = b;
    cout << "Mang e (copy tu b): " << e << endl;

    return 0;
}
