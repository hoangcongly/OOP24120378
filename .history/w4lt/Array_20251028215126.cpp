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
}