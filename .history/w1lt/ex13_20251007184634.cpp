#include <iostream>
using namespace std;

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

template <typename T>
bool ascending(T a, T b) { return a > b; }

template <typename T>
bool descending(T a, T b) { return a < b; }

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

    sortArray(arr_Int, 5, ascending<int>);     // Sắp xếp tăng dần
    sortArray(arr_Float, 4, descending<float>); // Sắp xếp giảm dần
    sortArray(arr_Char, 4, ascending<char>);   // Sắp xếp tăng dần

    printArray(arr_Int, 5);
    printArray(arr_Float, 4);
    printArray(arr_Char, 4);

    return 0;
}
