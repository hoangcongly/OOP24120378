#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d;
    do
    {
        cout << "Nhap a: ";
        cin >> a;
    } while (a <= 0 || a >= 200);

    do
    {
        cout << "Nhap b: ";
        cin >> b;
    } while (b <= -120 || b >= 0);

    do
    {
        cout << "Nhap c: ";
        cin >> c;
    } while (c <= -100 || c >= 0);

    do
    {
        cout << "Nhap d: ";
        cin >> d;
    } while (d <= 0 || d >= 150);

    double val = a + b + c * d;
    cout << "a + b + c * d = " << val << endl;

    double ptp1 = a - int(a);
    double ptp2 = b - int(b);
    double ptp3 = c - int(c);
    double ptp4 = d - int(d);

    double minptp = ptp1;
    if (ptp2 < minptp)
        minptp = ptp2;
    if (ptp3 < minptp)
        minptp = ptp3;
    if (ptp4 < minptp)
        minptp = ptp4;

    cout << "Phan tri thap phan nho nhat trong 4 so la: " << minptp << endl;
}
