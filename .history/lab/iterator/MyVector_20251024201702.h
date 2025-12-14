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

    void reallocate(unsigned long newCapacity)
    {
    }

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