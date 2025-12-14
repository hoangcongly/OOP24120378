#include "Array.h"

Array::Array()
{
    data = nullptr;
    size = 0;
}

Array::Array(int s) : Array()
{
    size = (s > 0) ? s : 0;
    if (size != 0)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }
}

Array::~Array()
{
    delete[] data;
    size = 0;
}

Array::Array(const Array &other)
{
    size = (other.size > 0) ? other.size : 0;
    if (size > 0)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    else
        data = nullptr;
}

Array &Array::operator=(const Array &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] data;
    size = other.size;
    if (size > 0)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

int Array::getSize() const
{
    return size;
}

int Array::getValue(int index) const
{
    if (index >= size || index < 0)
    {
        throw std::out_of_range("out of range");
    }
    return data[index];
}

void Array::setValue(int index, int value)
{
    if (index >= size || index < 0)
    {
        throw std::out_of_range("out of range");
    }
    data[index] = value;
}

void Array::display() const
{
    std::cout << "Array data: [";
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << "\t";
    }
    std::cout << "]" << std::endl;
}