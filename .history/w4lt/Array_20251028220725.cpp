#include "Array.h"

Array::Array() : m_data(nullptr), m_size(0) {}

Array::Array(int size)
{
    if (size < 0)
        size = 0;
    m_size = size;
    m_data = (m_size == 0) ? nullptr : new int[m_size]();
}

Array::Array(const Array &other)
{
    m_size = other.m_size;
    m_data = new int[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = other.m_data[i];
    }
}

Array::~Array()
{
    delete[] m_data;
}
Array &Array::operator=(const Array &other)
{
    if (this == &other)
        return *this;
    delete[] m_data;
    m_size = other.m_size;
    m_data = new int[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = other.m_data[i];
    }
    return *this;
}

Array &Array::operator+=(const Array &other)
{
    int new_size = m_size + other.m_size;
    if (new_size == 0)
        return *this;
    int *newData = new int[new_size];
    for (int i = 0; i < m_size; i++)
    {
        newData[i] = m_data[i];
    }
    for (int i = 0; i < other.m_size; i++)
    {
        newData[m_size + i] = other.m_data[i];
    }
    delete[] m_data;
    m_data = newData;
    m_size = new_size;

    return *this;
}

int &Array::operator[](int index)
{
    if (index < 0 || index >= m_size)
    {
        throw out_of_range("Chi so truy cap nam ngoai pham vi mang!\n");
    }
    return m_data[index];
}

Array::operator int *()
{
    return m_data;
}

istream &operator>>(istream &is, Array &arr)
{
    cout << "Nhap so luong phan tu cua mang: ";
    is >> arr.m_size;
    if (arr.m_size < 0)
        arr.m_size = 0;
    delete[] arr;
    arr.m_data = (arr.m_size == 0) ? nullptr : new int[arr.m_size];
    if (arr.m_size > 0)
    {
        for (int i = 0; i < arr.m_size; i++)
        {
            is >> arr.m_data[i];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Array &arr)
{
    cout << "{";
    for (int i = 0; i < arr.m_size; i++)
    {
        os << arr.m_data[i];
        if (i < arr.m_size - 1)
            os << ",";
    }
    os << "}";
    return os;
}