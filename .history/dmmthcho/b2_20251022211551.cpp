#include <iostream>
#include "algorithm"
using namespace std;

int main()
{
    double a, b, c, d;
    do
    {
        cout << "Nhap a:";
        cin >> a;
    } while (a <= 0 || a >= 200);
    do
    {
        cout << "Nhap b:";
        cin >> b;
    } while (b <= -120 || b >= 0);
    do
    {
        cout << "Nhap c:";
        cin >> c;
    } while (c <= -100 || c >= 0);
    do
    {
        cout << "Nhap d:";
        cin >> d;
    } while (d <= 0 || d >= 150);
    double val = a + b + c * d;
    cout << "a+b+c*d=" << val << endl;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    double n1 = int(a);
    double n2 = int(b);
    double n3 = int(c);
    double n4 = int(d);
    // double n1, n2, n3, n4;
    while (count1 < n1)
    {
        count1++;
    }
    while (count2 < n2)
    {
        count2++;
    }
    while (count3 < n3)
    {
        count3++;
    }
    while (count4 < n4)
    {
        count4++;
    }
    double ptp1 = n1 - count1, ptp2 = n2 - count2, ptp3 = n3 - count3, ptp4 = n4 - count4;
    double minptp = -1;
    if (ptp2 < ptp3 && ptp2 < ptp1 && ptp2 < ptp4)
        minptp = ptp2;
    else if (ptp1 < ptp2 && ptp1 < ptp3 && ptp1 < ptp4)
        minptp = ptp1;
    else if (ptp3 < ptp1 && ptp3 < ptp2 && ptp3 < ptp4)
        minptp = ptp3;
    else
        minptp = ptp4;
    cout << "Phan tri thap phan nho nhat trong 4 so la: " << minptp << endl;
}