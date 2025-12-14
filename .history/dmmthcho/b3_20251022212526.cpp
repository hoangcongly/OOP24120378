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
    int giaithua = 1;
    int tu = 0;
    for (int i = 1; i < n; i++)
    {
        giaithua *= i;
        if (i % 2 == 0)
            tu -= i;
        else
            tu += i;
    }
    cout << "ket qua: " << n << endl;
}