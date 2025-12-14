#include "Array.h"

Array::Array() : m_data(nullptr), m_size(0) {}

Array::Array(int size)
{
    if (size < 0)
        size = 0;
    m_size = size;
    m_data = (m_size == 0) ? nullptr : new int[m_size]();
}