#include <iostream>
using namespace std;

// Hàm so sánh
bool ascending(int a, int b)
{
    return a > b;
}
bool descending(int a, int b)
{
    return a < b;
}

// Hàm sắp xếp sử dụng con trỏ hàm
void sort_Array(int arr[], int n, bool(*cmp)(int, int))
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (cmp(arr[i], arr[j])) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm in mảng
void print_Array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    { 
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr1[] = {5, 2, 9, 1, 3, 7, 1, 8};
    int arr2[] = {5, 2, 9, 1, 3, 7, 1, 8};
    int n = 8;

    cout << "Sap xep tang dan" << endl;
    sort_Array(arr1, n, ascending);
    print_Array(arr1, n);

    cout << "\nSap xep giam dan" << endl;
    sort_Array(arr2, n, descending);
    print_Array(arr2, n);

    return 0;
}