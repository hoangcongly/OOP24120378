#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    do
    {
        cout << "Nhap a: ";
        cin >> a;
        cout << "Nhap b: ";
        cin >> b;
        cout << "Nhap c: ";
        cin >> c;
        cout << "Nhap d: ";
        cin >> d;

    } while (a <= 0 || a >= 200 || b <= -120 || b >= 0 || c <= 100 || c >= 0 || d <= 0 || d >= 150);
    cout << a << b << c << d << endl;
}