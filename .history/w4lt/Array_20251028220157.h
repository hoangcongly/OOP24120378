#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array
{
private:
    int *m_data;
    int m_size;

public:
    Array();
    Array(int size);
    Array(const Array &other);
    ~Array();

    Array &operator=(const Array &other);
    Array &operator+=(const Array&other);
    int& operator[] (int index);
    const int& operator[] (int index) const;
    operator int*();

    friend istream& operator>> (istream&is, Array&arr);
    friend ostream& operator<< (ostream&os, const Array&arr);

    friend Array operator+(const Array&a1, const Array& a2);
};

#endif