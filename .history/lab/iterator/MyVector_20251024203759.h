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
    void ensureCapacity()
    {
        if (m_size == m_capacity)
        {
            unsigned long newCap = (m_capacity == 0) ? 0 : m_capacity * 2;
            reallocate(newCap);
        }
    }

public:
    class Iterator
    {
    private:
        Iterator(T *ptr) : m_ptr(ptr) {}
        T *m_ptr; // giu vi tri hien tai cua iterator dang tro den

    public:
        friend class MyVector;
        T &operator*() const { return *m_ptr; }
    };

    Iterator::Iterator(/* args */)
    {
    }

    Iterator::~Iterator()
    {
    }
};

#endif