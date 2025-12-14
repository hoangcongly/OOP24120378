#include <iostream>
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
    } while (b <= 0 || b >= 200);
    do
    {
        cout << "Nhap c:";
        cin >> c;
    } while (c <= 0 || c >= 200);
    do
    {
        cout << "Nhap d:";
        cin >> d;
    } while (d <= 0 || d >= 200);
}