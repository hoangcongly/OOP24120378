#include <iostream>
using namespace std;

// Hàm sắp xếp sử dụng con trỏ hàm để chọn loại sắp xếp và sử dụng template để sắp xếp kiểu dữ liệu bất kì
template <typename T>
void sortArray(T arr[], int n, bool (*cmp)(T,T)) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (cmp(arr[i], arr[j])) 
            {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm so sánh 
template <typename T>
bool ascending(T a, T b) { return a > b; }

template <typename T>
bool descending(T a, T b) { return a < b; }

//Hàm in mảng
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr_Int[] = {5, 2, 9, 1, 3};
    float arr_Float[] = {3.1, 1.2, 4.5, 2.2};
    char arr_Char[] = {'d', 'a', 'c', 'b'};
    char choice;

    cout << "Sort ascending or descending (a/d)? ";
    cin >> choice;

    if (choice == 'a') 
    {
        sortArray(arr_Int, 5, ascending<int>);
        sortArray(arr_Float, 4, ascending<float>);
        sortArray(arr_Char, 4, ascending<char>);
    } 
    else 
    {
        sortArray(arr_Int, 5, descending<int>);
        sortArray(arr_Float, 4, descending<float>);
        sortArray(arr_Char, 4, descending<char>);
    }

    printArray(arr_Int, 5);
    printArray(arr_Float, 4);
    printArray(arr_Char, 4);

    return 0;
}

