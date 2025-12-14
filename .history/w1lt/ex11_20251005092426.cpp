#include <iostream>
using namespace std;

template<typename T>
void sort_Ascending(T arr[], int n)
{
    for( int i = 0; i < n - 1; i++)
    {
        for( int j = i +1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<typename T>
void print_Array(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    { 
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr_Int[] = {3, 6, 4, 5, 9, 7, 1, 8, 5};
    float arr_Float[] = {7.2, 8.5, 3.4, 5.6, 1.3, 0.7};
    char arr_Char[] = {'m', 'd', 'r', 'h', 'g', 'a', 'f', 'i', 'z', 'p'};

    sort_Ascending(arr_Int, 9);
    sort_Ascending(arr_Float, 6);
    sort_Ascending(arr_Char, 10);

    print_Array(arr_Int, 9);
    print_Array(arr_Float, 6);
    print_Array(arr_Char, 10);

    return 0;
}