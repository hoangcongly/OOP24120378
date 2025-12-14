#include "MangSoNguyen.h"

int main()
{
    MangSoNguyen msn1;
    msn1.Xuat();
    MangSoNguyen msn2(5);
    msn2.Xuat();
    int arr[10];
    for (int i = 0; i < 8; i++)
    {
        arr[i] = i * i;
    }
    MangSoNguyen msn3(arr, 8);
    msn3.Xuat();
    MangSoNguyen msn4(msn3);
    msn4.Xuat();
}