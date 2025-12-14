#include "MangSoNguyen.h"

MangSoNguyen::MangSoNguyen()
{
    Size = 0;
    arr = nullptr;
}
MangSoNguyen::MangSoNguyen(const int &size)
{
    Size = (size > 0) ? size : 0;
    if (Size > 0)
    {
        arr = new int[Size];
        for (int i = 0; i < Size; i++)
        {
            arr[i] = 0;
        }
    }
    else
        arr = nullptr;
}
MangSoNguyen::MangSoNguyen(const int *arr_other, const int &size)
{
    if (Size != 0)
    {
        Size = 0;
        arr = nullptr;
    }
    MangSoNguyen(size);
    for (int i = 0; i < Size; i++)
    {
        arr[i] = arr_other[i];
    }
}
MangSoNguyen::MangSoNguyen(const MangSoNguyen &other)
{
    MangSoNguyen(other.arr, other.Size);
}
MangSoNguyen::~MangSoNguyen()
{
    Size = 0;
    delete[] arr;
}
void MangSoNguyen::Xuat()
{
    for (int i = 0; i < Size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
