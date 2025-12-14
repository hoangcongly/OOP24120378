#include <iostream>
using namespace std;

int main()
{
    int n;
    do
    {
        cout << "Nhap so: ";
        cin >> n;
    } while (n >= 14);
    double giaithua = 1.0;
    double tu = 0.0;
    double result = 0;
    for (int i = 1; i < n; i++)
    {
        giaithua *= i;
        if (i % 2 == 0)
            tu -= i;
        else
            tu += i;
        result += double(tu / result);
    }
    cout << "ket qua: " < < < < endl;
}