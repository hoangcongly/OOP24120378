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
};

#endif