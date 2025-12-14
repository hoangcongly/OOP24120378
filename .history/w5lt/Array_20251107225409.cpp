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
}

Array& Array::operator=(const Array&other)
{
    if(*this==other)
    {
        return*this;
    }

    delete[] data;
    size=other.size;
    data= new int[size];
    for(int i=0; i<size; i++)
    {
        data[i]=other.data[i];
    }
    return*this;
}