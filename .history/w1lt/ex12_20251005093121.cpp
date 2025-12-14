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
    int arr[] = {5, 2, 9, 1, 3};
    int n = 5;
    char choice;

    cout << "Sắp xếp tăng dần hay giảm dần (Chọn a để tăng/ d để giảm)? ";
    cin >> choice;

    if (choice == 'a')
        sort_Array(arr, n, ascending);
    else
        sort_Array(arr, n, descending);

    print_Array(arr, n);
    return 0;
}