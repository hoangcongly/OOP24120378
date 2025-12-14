#include "Array.h"
#include <algorithm> 


Array::Array() : data(nullptr), size(0) {}

Array::Array(int length) : size(length) 
{
    if (size > 0) 
    {
        data = new int[size];
        for (int i = 0; i < size; ++i) 
        {
            data[i] = 0;
        }
    }
    else 
    {
        data = nullptr;
        size = 0;
    }
}

Array::Array(int arr[], int length) : size(length) 
{
    if (size > 0) 
    {
        data = new int[size];
        for (int i = 0; i < size; ++i) 
        {
            data[i] = arr[i];
        }
    }
    else 
    {
        data = nullptr;
        size = 0;
    }
}

Array::Array(const Array& other) : size(other.size) 
{
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }
    }
    else 
    {
        data = nullptr;
    }
}

Array::~Array() 
{
    delete[] data;
    data = nullptr; 
    size = 0;
}

void Array::input() {
    cout << "Nhap kich thuoc mang: ";
    int newSize;
    cin >> newSize;

    if (newSize < 0) newSize = 0;
    if (data != nullptr) 
    {
        delete[] data;
    }
    
    size = newSize;
    if (size > 0) 
    {
        data = new int[size];
        cout << "Nhap " << size << " phan tu: ";
        for (int i = 0; i < size; ++i) 
        {
            cin >> data[i];
        }
    } 
    else 
    {
        data = nullptr;
    }
}

void Array::output() const 
{
    if (size == 0) 
    {
        cout << "[] (Mang rong)" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < size; ++i) 
    {
        cout << data[i] << (i == size - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int Array::getSize() const 
{
    return size;
}

void Array::setSize(int newSize) 
{
    if (newSize < 0) newSize = 0;
    if (newSize == size) return;
    int* newData = nullptr;
    if (newSize > 0) 
    {
        newData = new int[newSize];
        int copySize = (newSize < size) ? newSize : size;
        for (int i = 0; i < copySize; ++i) 
        {
            newData[i] = data[i];
        }
        for (int i = copySize; i < newSize; ++i) 
        {
            newData[i] = 0;
        }
    }
    delete[] data;
    data = newData;
    size = newSize;
}

int Array::getElement(int index) const 
{
    if (index >= 0 && index < size) 
    {
        return data[index];
    }
    cerr << "Loi index nam ngoai pham vi tra ve 0." << endl;
    return 0;
}

void Array::setElement(int index, int value) 
{
    if (index >= 0 && index < size) 
    {
        data[index] = value;
    } 
    else 
    {
        cerr << "Loi index nam ngoai pham vi khong the set element" << endl;
    }
}

int Array::find(int value) const 
{
    for (int i = 0; i < size; ++i) 
    {
        if (data[i] == value) 
        {
            return i;
        }
    }
    return -1; 
}

void Array::sort(bool ascending) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            bool swapCondition;
            if (ascending) 
            {
                swapCondition = (data[j] > data[j + 1]);
            } 
            else 
            {
                swapCondition = (data[j] < data[j + 1]);
            }
            if (swapCondition) 
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
}