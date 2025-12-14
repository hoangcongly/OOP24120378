#ifndf MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

template <typename T>
class MyVector
{
private:
    T *m_data;
    unsigned long m_size;
    unsigned long m_capacity;

    // cap bo nho moi cho vector
    void reallocate(unsigned long newCapacity)
    {
        T *newdata = new T[newCapacity];
        for (unsigned long i = 0; i < m_size; i++)
        {
            newdata[i] = static_cast<T &&>(m_data[i]);
        }
        delete[] m_data;
        m_data = newdata;
        m_capacity = newCapacity;
    }
    // kiem tra mang co day khong, neu co thi tang capa *2

public:
    MyVector(/* args */);
    ~MyVector();
};

MyVector::MyVector(/* args */)
{
}

MyVector::~MyVector()
{
}

#endif